#include "TodoList.h"
#include "TodoListInterface.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    string command = argv[1]; 
    TodoList myList;
    string taskDate;
    string taskName;
    
    if (command == "add"){
        taskDate = argv[2];
        taskName = argv[3];
        myList.add(taskDate, taskName);
    }
    else if (command == "remove"){
        taskName = argv[2];
        myList.remove(taskName);
    }
    else if (command == "printList"){
        myList.printTodoList();
    }
    else if (command == "printDay"){
        taskDate = argv[2];
        myList.printDaysTasks(taskDate);
    }
    
    return 0;
}