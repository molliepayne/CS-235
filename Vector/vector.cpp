#include <iostream>
#include <vector>
#include <list>
#include "MV.h"
#include "MyVector.h"
#include <string>
using namespace std;
int main()
{
  list<string> mystrings;
    int n = 40000000; // The number of inserts
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.end(),"Hello");
    }
}