#include "../include/todo.hpp"
#include <iostream>


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
        cout << "3. Add a task to a list\n";
        cout << "4. Mark a task as completed\n";
        cout << "5. Delete a task from a list\n";
        cout << "6. Return to Clip\n";
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
            case 3: addTask(); break;
            case 4: markTask(); break;
            case 5: deleteTask(); break;
            case 6: cout << "Returning to Clip...\n"; break;
            default: cout << "Invalid option. Try again.\n"; break;
        }

    } while (option != 6); // The loop continues until the user chooses 6.
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

            lists[name] = {};
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

void ToDoManager::addTask(){
        string task;
        string listName;

        cout<<"Add a new Task\n";
        cout<<"Enter the name of the list: \n";

        getline(cin, listName);

        //check if list exist

        if(!lists.count(listName)) {
            cout<< "List '" << listName <<"' not found\n";
        return;
        }   
    
    
        cout << "Enter task description: \n";
        getline(cin, task);

        if(task.empty()){ 
            cout<< "Task cannot be empty. \n";
            return;
        }


        //push the task in the vector, by default as false-> not completed.
        lists[listName].push_back({task,false}); 
        cout<< "Task added succesfully to list '" <<listName <<"'. \n";
}


void ToDoManager::markTask(){
    
    string listName;
    cout<<"Enter the name of the List: \n";
    getline(cin, listName);

    if(!lists.count(listName)) {
            cout<< "List '" << listName <<"' not found\n";
            return;
        }  


        //access to vector of task. Declared const to prevent modification and esure safe iteration
        const auto& task = lists[listName];  


        if(task.empty()){
        cout<< "No task found in this list.\n";
        return;
    }

    /*display tasks with their completion status.
    Uses size_t because it's unsigned and matches task.size(), making it
    ideal for loop indexing*/

    for(size_t i=0; i<task.size(); i++){
        cout<< i <<". "
        <<(task[i].second ? "[X] " : "[ ] ")
        <<task[i].first << "\n";
    }

    //uses indexation to search for each task. 
    //Ex: select task: 2.
    //searches for the task in index 2(starts by 0) so:
    //vector task = {task1, task2,task3, task4}
    //in this case index 2= "task3".
    
    cout<< "Enter the index of the task to mark as completed: ";
    int index;
    cin>>index;
    cin.ignore();
    
    //validate that the selected index is withing the valid range.
    //static_cast<int> avoid signed/unsigned comparison issues.
    if(index < 0 or index >=static_cast<int>(task.size())) {
        cout<<"Invalid index.\n";
        return;
    }

    //mark as completed
    lists[listName][index].second =true;

    //display the task name that just was marked
    cout<< "Task '" << lists[listName][index].first <<"' marked as completed.\n";

}
void ToDoManager::deleteTask(){
        string task;
        string listName;

        cout<<"Delete a task\n";
        cout<<"Enter the name of the list: \n";

        getline(cin, listName);

        //check if list exist

        if(!lists.count(listName)) {
            cout<< "List '" << listName <<"' not found\n";
        return;
        }   

        if(task.empty()){ 
            cout<< "Task cannot be empty. \n";
            return;
        }


        //push the task in the vector, by default as false-> not completed.
        lists[listName].pop_back(); 
        cout<< "Task added succesfully to list '" <<listName <<"'. \n";

}


/* THE USE OF 'try, throw and catch' its used following this rules:

-for input validation: if n else
-for logic or system-level failures: try n catch*/