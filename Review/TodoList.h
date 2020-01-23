#ifndef TODOLIST_H
#define TODOLIST_H
#include <iostream>
#include <string>
#include <vector>
#include "TodoListInterface.h"
using namespace std;

class TodoList : public TodoListInterface {
    public:
        TodoList();
        ~TodoList();
        TodoList(string dueDate, string taskName);
        void add(string _duedate, string _task);
        int remove(string _task);
        void printTodoList();
        void printDaysTasks(string _date);
    protected:
        vector<string> dueDates;
        vector<string> toDoTasks;
};
        
#endif
