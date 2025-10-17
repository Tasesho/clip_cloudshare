#ifndef TASK_HPP
#define TASK_HPP

#include<iostream>
#include <string>

class Task{
    private:
    std::string description;
    bool completed;

    public:
        Task(const std::string& desc);

    void markCompleted();
    void markIncomplete();
    bool isComplete() const;
    std::string getdescription() const;
};

#endif TASK_HPP