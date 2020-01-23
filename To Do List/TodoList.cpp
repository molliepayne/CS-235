#include "TodoList.h"

void TodoList::add(string _duedate, string _task){
    //cout <<" in add: " << _duedate << "  " << _task << endl;
    Task *myTask = new Task(_duedate, _task);
    tasks.push_back(myTask);
};
    /*    *   
    Removes an item from the todo list with the specified task name   
    *    *   Returns 1 if it removes an item, 0 otherwise   
    */    
int TodoList::remove(string _task){
    //cout << "in remove: " << _task << endl;
    auto it = tasks.begin();
	while (it != tasks.end())
	{
	    
	    if((*it)->getDesc() == _task){
	        //cout << "removing task "<<endl;
	        tasks.erase(it);
	        //printTodoList();
	        return 1;
	    }
        it++;
    }
    return 0;
};
    /*    *   
    Prints out the full todo list to the console    
    */    
void TodoList::printTodoList(){
    //cout << "print list" << endl;
   for (int i=0; i<tasks.size(); i++){
        Task* curTask = tasks.at(i);
        cout << curTask->getDate() << endl;
        cout << curTask->getDesc() << endl;
        //cout << curTask->getDesc() << " " << curTask->getDate() << endl;
    }
  
};
    /*    *   
    Prints out all items of a todo list with a particular due date (specified by _duedate)    
    */   
void TodoList::printDaysTasks(string _date){
    cout << "Tasks for " << _date << ": " << endl;
    bool found = false;
     auto it = tasks.begin();
	while (it != tasks.end())
	{
	   
	    if((*it)->getDate() == _date){
	        found = true;
	        cout << (*it)->getDesc() << endl;
	    }
        it++;
    }
    if (!found){
        cout<<"no tasks for " << _date << " found." << endl;
    }
};
    