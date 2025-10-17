/*this file contains method definitions of Task class*/

#include "../include/task.hpp"
#include <iostream>


Task::Task(const std::string& desc): description(desc),completed(false){}


void Task::markCompleted(){
    completed=true;
}

void Task::markIncomplete(){
    completed=false;
}

bool Task::isComplete() const{
    return completed;
}

std::string Task::getdescription() const{
    return description;
}