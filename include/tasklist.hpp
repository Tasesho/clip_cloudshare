#ifndef TASKLIST_HPP
#define TASKLIST_HPP

#include "task.hpp"
#include<vector>


class TaskList{
    private:
        std::vector<Task> tasks;
    public:
    
void addTask(const std::string& description);
void deleteTask(size_t index);

const std::vector<Task>& getTasks() const;  //returns a read-only reference of the value in the original vector

Task& getTask(size_t index); //returns a modifiable reference in the original task object
};


#endif