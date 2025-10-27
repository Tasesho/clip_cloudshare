#include "../include/todo.hpp"
#include <iostream>
#include <string>



using namespace std;


//This function is the main menu for the To Do maneger.

void ToDoManager::manageMenu() {
    int option = 0;

    // implements a do-while loop that controls the ToDo menu.
    // It displays an interface using 'cout' where the user selects options
    // by entering a number that corresponds to a menu action.
    do {
        cout << "\n========= TO DO MENU =========\n";
        cout << "1. Show all lists\n";
        cout << "2. Create a new list\n";
        cout << "3. View/Manage lists\n";
        cout << "4. Return to Clip\n";
        cout << "==============================\n";
        cout << "Choose an option: ";

        // Input validation section:
        // 'cin >> option' reads an integer input from the user.
        // If extraction fails (non-numeric input), the stream enters an error state.
        // We negate the condition to detect invalid input.
        if (!(cin >> option)) {
            cin.clear();                      // Reset the stream state
            cin.ignore(10000, '\n');          // Discard invalid input
            cout << "Invalid input. Please enter a number.\n";
            continue;                         // Restart the menu loop
        }
        cin.ignore(); // Discard newline character left in the buffer

        // The switch executes an action based on the chosen option.
        switch (option) {
            case 1: showLists(); break;
            case 2: createList(); break;
            case 3: manageListMenu(); break;
            case 4: cout << "Returning to Clip...\n"; break;
            default: cout << "Invalid option. Try again.\n"; break;
        }

    } while (option != 4); // The loop continues until the user chooses 6.
}

//---------------------------------------------------------------------------------


void ToDoManager::showLists(){
    if (lists.empty()){                 //checks if empty
        cout<<"\nNo lists available yet.\n";
        cout<<"Use option 2 in the menu to create a new one.\n";
        return;
    }

    cout<<"\nAvailable lists: \n";      
    cout<<"-------------------\n";
    for(const auto& list : lists)           //iterates in the map searching for a key. list.first -> list's name (key)
        cout <<"- " << list.first << "\n";


    cout<< "--------------\n";
}


void ToDoManager::createList(){
        //in the 'try' code block we'll be trying to create a new list, if fails it will throw an error.
        try{
            string name;
            cout << "\nEnter the name of the new list: ";
            getline(cin, name);

            if (name.empty()) {
            throw invalid_argument( "List name cannot be empty. ");
            } 
            
            if(lists.count(name)) {
                throw runtime_error("A list with this name already exists.");
            }

            lists.emplace(name, TaskList());
            cout<<"List '"<< name << "' created successfully.\n";
    }
    
    catch(const invalid_argument& e){
        cout<< "Input error: " << e.what() << "\n";

    }
    catch(const runtime_error& e){
        cout<<"Creation error: " << e.what() << "\n";
    }
    
    catch(...) {
        cout<<"Unexpected error occurred while creating the list.\n";
    }
}


void ToDoManager::manageListMenu(){
    string listName;
    cout<<"\nEnter the name of the list to manage: ";
    getline (cin, listName);

    if(lists.count(listName)==0){
        cout << "Error: List '" << listName << "' not found.\n";
        return;
    }

    TaskList& list = lists.at(listName);

    const vector<Task>& taskToDisplay = list.getTasks();

    cout<<" \n --- Tasks in '" <<listName <<"' ---\n";
    if(taskToDisplay.empty()){
        cout<< "This list has no task yet.\n";
    }
    else{
        for(size_t i =0; i<taskToDisplay.size(); i++){
            cout<< i << ". "
            <<(taskToDisplay[i].isComplete() ? "[X] " : "[ ] ")
            <<taskToDisplay[i].getdescription() << "\n";
        }
    }

    cout <<"-----------------------------\n";

    cout<<" Manage Tasks: \n";
    cout<<" 1. Add a new task\n";
    cout<<" 2. Mark/Unmark a task\n";
    cout<<" 3. Delete a task\n";
    cout<<" 4. Go back to main menu\n";
    cout<<" choose an option: \n";

    int choice;
    if(!(cin>> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Invalid input.\n";
        return;
    }
    cin.ignore();

    switch(choice){
        case 1: {
            cout<<"Enter the new task description: ";
            string desc;
            getline(cin, desc);
            if(!desc.empty()){
                list.addTask(desc);
                cout<<"Task added!\n";
            }
            else{
                cout<<"Task description cannot be empty. \n";
            } break;
        }
        case 2: {
            if(taskToDisplay.empty()) {
                cout<<" No tasks to mark. /n";
                break;
            }
            else{
                cout<<"Enter the number of the task to Mark/unmark: ";
                size_t index;
                cin>>index;
                cin.ignore();
                if(index < taskToDisplay.size()) {
                    Task& taskToMark = list.getTask(index);
                    if(taskToMark.isComplete()){
                        taskToMark.markIncomplete();
                        cout<<"Task marked as INCOMPLETE.\n";
                    }
                    else{
                        taskToMark.markCompleted();
                        cout<<"Task marked as COMPLETE. \n";
                    }
                }
                else{
                    cout<<" Invalid task number. \n";
                }
                break;
            }
        }
            case 3: {
                if(taskToDisplay.empty()){
                    cout<< "No task to delete.\n";
                    break;
                }
                cout<<"Enter the number of the task to delete: ";
                size_t index;
                cin>>index;
                cin.ignore();
                if(index< taskToDisplay.size()) {
                    string desc = list.getTask(index).getdescription();
                    list.deleteTask(index);
                    cout<<" Task '"<<desc<<"' deleted.\n";
                }
                else {
                    cout<< "Invalid task number.\n";
                }
                break;
            }
            case 4: {
                break;
            }
                default:
                cout<<"Invalid option.\n";
                break;
            }
        }  


/* THE USE OF 'try, throw and catch' its used following this rules:

-for input validation: if n else
-for logic or system-level failures: try n catch*/