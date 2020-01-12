#pragma once
#include "TaskInterface.h"

class Task: public TaskInterface {
   private: 
    string date;
        string desc;
        
    public:
    
    	Task(string _date, string _desc) {
    	    //cout << "in task constructor: " << _date << " " << _desc << endl;
    	    date = _date;
    	    desc = _desc;
    	};
    	~Task() {}
    	string getDate() const;
    	string getDesc() const;
	

       
};