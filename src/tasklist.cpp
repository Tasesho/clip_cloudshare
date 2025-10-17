/*this file contains method definitions of Task class*/

#include "../include/tasklist.hpp"
#include <iostream>


void TaskList::addTask(const std::string& description){   
    Task newTask(description);
    tasks.push_back(newTask);
}
/*
void TaskList::deleteTask(){

}

const std::vector<Task>& getTasks();{
    return tasks;
}

Task& getTask(size_t index){
    return tasks.at(index);
}
*/
