#include <iostream>
#include "MV.h"
#include <vector>
using std::cout;
using std::endl;
int main()
{
    MV<int> container;
    cout << "Inserting"<<endl;
    container.put(5);
    cout << "Getting"<<container.get()<<endl;
    MV<string> containerString;
    cout << "Inserting"<<endl;
    containerString.put("Hello");
    cout << "Getting "<<containerString.get()<<endl;
     vector<string> mystrings;
    int n = 40000; // The number of inserts 
    for(int i = 0; i < n; i++) {
        mystrings.insert(mystrings.begin(),"Hello");
    }
}