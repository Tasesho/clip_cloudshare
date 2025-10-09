#include "../include/todo.hpp"
#include <iostream>


using namespace std;


//This function is the main menu for the To Do maneger.

void ToDoManager::manageMenu() {
    int option = 0;

    // This function implements a do-while loop that controls the ToDo menu.
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

}
void ToDoManager::addTask(){

}
void ToDoManager::markTask(){

}
void ToDoManager::deleteTask(){

}
