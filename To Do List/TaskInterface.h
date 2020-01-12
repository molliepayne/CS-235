#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
*	This class specifies the methods for a task.
*
*	All tasks have the following attributes:
*		Date - The task's due date
*		Desc - The description for the task
*
*	
*/

class TaskInterface
{
public:
	TaskInterface() {}
	~TaskInterface() {}

	/*
	*	getDate()
	*
	*	Returns the date of this task.
	*/
	virtual string getDate() const = 0;
    
	/*
	*	getDesc()
	*
	*	Returns the description of this task.
	*/
	virtual string getDesc() const = 0;
};