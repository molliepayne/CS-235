#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#define ECHO(x) #x << ": " << (x)

using namespace std;

int main(int argc, char *argv[]) 
{
    cout << "Hello World!" << endl;
    cout << "argc "<<argc<<" argv[0] "<<argv[0]<<" argv[1]= "<<argv[1]<<endl;
    if(argc != 2) {
        cout << "Usage: "<<argv[0]<<" <filename>"<<endl;
    } else {
        ifstream fileHandle(argv[1]);
        if(!fileHandle.is_open()) {
            cout << "Could not open file"<<endl;
        } else {
            string name;
            int age;
            
            


            vector<string> names;
            while(fileHandle>>name>>age) {
               //cout << "Name "<<name<<" Age "<<age<<endl;
                names.push_back(name);
                cout << ECHO(name) << ECHO(age) << ECHO(age + age) << '\n'; 
cout << ECHO(age) << ECHO(age << 2) << '\n';
            }
            sort(names.begin(), names.end());
            ofstream outHandle("sorted.txt");
            for(int i = 0; i < names.size(); i++){
                cout << names[i] << endl;
                outHandle << names[i] <<endl;
            }
            
        }
    }
}