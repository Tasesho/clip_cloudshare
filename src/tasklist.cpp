/*this file contains method definitions of Task class*/

#include "../include/tasklist.hpp"
#include <iostream>


void TaskList::addTask(const std::string& description){   
    Task newTask(description);
    tasks.push_back(newTask);
}

void TaskList::deleteTask(size_t index){
    if(index< tasks.size()){
        tasks.erase(tasks.begin() + index);
    }
}

const std::vector<Task>& TaskList::getTasks() const{
    return tasks;
}

Task& TaskList::getTask(size_t index){
    return tasks.at(index);
}

