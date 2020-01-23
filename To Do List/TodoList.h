#pragma once
#include "TodoListInterface.h"
#include "Task.h"
#include <vector>
#include <fstream>
#include <sstream>

class TodoList: public TodoListInterface {
    protected:
    vector<Task*> tasks;
    public:
	TodoList() {
		//cout << "In To Do List  Constructor "<<endl;
		//read from file into vector
		ifstream infile("TODOList.txt");
		if(infile.is_open())
		{
    	    string dateLine;
    	    string descLine;
    	    
    	    while(getline(infile, dateLine)){
    	        getline(infile, descLine);
    	        Task* curTask = new Task(dateLine, descLine);
    	        tasks.push_back(curTask);
    	    }
    	   infile.close();
		}
	};
	~TodoList() {
	    //cout << "in desctructor" << endl;
	    //write to file from vector
    	ofstream outfile("TODOList.txt");
		if(outfile.is_open())
		{
    	    auto it = tasks.begin();
        	while (it != tasks.end())
        	{
        	    //cout << "in loop: " <<(*it)->getDesc() << endl;
        	    outfile << (*it)->getDate() << endl << (*it)->getDesc() << endl;
                it++;
            }
    	   outfile.close();
		}
	}
    void add(string _duedate, string _task);    
    /*    *   
    Removes an item from the todo list with the specified task name   
    *    *   Returns 1 if it removes an item, 0 otherwise   
    */    
    int remove(string _task);    
    /*    *   
    Prints out the full todo list to the console    
    */    
    void printTodoList();   
    /*    *   
    Prints out all items of a todo list with a particular due date (specified by _duedate)    
    */   
    void printDaysTasks(string _date);

};