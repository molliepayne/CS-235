#include <iostream>
#include "MV.h"
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
}