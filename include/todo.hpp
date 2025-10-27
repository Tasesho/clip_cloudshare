#ifndef TODO_HPP
#define TODO_HPP

#include "../include/tasklist.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class ToDoManager{
// 'lists' stores all to-do lists.
// Key: list name (string)
// Value: vector of tasks, where each task is a pair<string, bool> 
//        - first: task description
//        - second: completion status (true = done, false = not done)

    private:
        map<string, TaskList> lists;  
        void manageListMenu();  //secondary menu for list management

    public:
    
        void manageMenu();     // main menu for todolist
        void showLists();       //show all existing lists
        void createList();      //create a new list

        
};
#endif