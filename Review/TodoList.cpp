#include <vector>
#include <iostream>
#include <fstream>
#include "TodoList.h"
#include "TodoListInterface.h"
using namespace std;

TodoList::TodoList() {
    ifstream inToDo;
    
    inToDo.open("ToDoText.txt");
    if (!inToDo.is_open()) {
        return;
    }
    string userDate;
    string userTask;
    while (getline(inToDo, userDate)) {
        getline(inToDo, userTask);
        add(userDate, userTask);
    }
    inToDo.close();
}

TodoList::TodoList(string dueDate, string taskName) {
    dueDates.push_back(dueDate);
    toDoTasks.push_back(taskName);
}

TodoList::~TodoList() {
    ofstream outToDo;
    outToDo.open("ToDoText.txt");
   
    if (!outToDo.is_open()) {
        return;
    }
    
    for (int i = 0; i < dueDates.size(); ++i) {
        outToDo << dueDates.at(i) << endl;
        outToDo << toDoTasks.at(i) << endl;
    }
    
    outToDo.close();
}

void TodoList::add(string _duedate, string _task) {
    dueDates.push_back(_duedate);
    toDoTasks.push_back(_task);
}

int TodoList::remove(string _task) {
    for (int i = 0; i < toDoTasks.size(); ++i) {
        if (toDoTasks.at(i) == _task) {
            toDoTasks.erase(toDoTasks.begin() + i);
            dueDates.erase(dueDates.begin() + i);
            return 1;
        }
    }
    return 0;
}

void TodoList::printTodoList() {
    for (int i = 0; i < dueDates.size(); ++i) {
        cout << dueDates.at(i) << endl;
        cout << toDoTasks.at(i) << endl;
    }
}

void TodoList::printDaysTasks(string _date) {
    vector<int> taskPositions;
    
    for (int i = 0; i < dueDates.size(); ++i) {
        if (dueDates.at(i) == _date) {
            taskPositions.push_back(i);
        }
    }
    
    for (int i = 0; i < taskPositions.size(); ++i) {
        cout << toDoTasks.at(taskPositions.at(i)) << endl;
    }
}
