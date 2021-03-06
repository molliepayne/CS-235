#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TodoList.h"



int main(int argc, char *argv[])  {
   
    if(argv[1] != NULL){
        string userChoice = argv[1];
        TodoList* thisList = new TodoList;
    
        if(userChoice == "add"){
            if(argv[2] != NULL && argv[3] != NULL)
            {
                string dueDate = argv[2];
                string desc = argv[3];
                //cout<<desc<<endl;
                thisList->add(dueDate, desc);
            }
            else{
                cout << "incorrect number arguments found, please try again" << endl;
                return 0;
            }
            
            
        }else if(userChoice == "remove"){
            if(argv[2] != NULL){
                string desc = argv[2];
                int isCompleted = thisList->remove(desc);
                if(!isCompleted){
                    cout <<"Error removing " << desc << " from to do list.  Wasn't found." << endl;
                }
            }else{
                cout << "incorrect number arguments found, please try again" << endl;
                return 0;
            }
           
        }else if(userChoice == "printList"){
            if(argv[2]!=NULL){
                string dueDate = argv[2];
                thisList->printDaysTasks(dueDate);
            }else{
                thisList->printTodoList();
            }
        }else if(userChoice == "printDay"){
            if(argv[2]!=NULL){
                string dueDate = argv[2];
                thisList->printDaysTasks(dueDate);
            }else{
                cout << "no arguments found, please try again" << endl;
            }
        }
        delete thisList;
    }
    else{
        cout << "no arguments found, please try again" << endl;
    }
    
	return 0;
}
