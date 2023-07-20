#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string name;
    string city;
    string description;
    int age;
 
    //Welcome message
    cout << "Welcome to Community Connections!" << endl;
    
    //Gets the user information
    cout << "What's your name? ";
    cin >> name;
    cout << "Where are you from? ";
    cin >> city;
    cout << "How would you describe yourself? ";
    cin >> description;
    cout << "How old are you? ";
    cin >> age;
 
    //Print the user information
    cout << endl << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "City: " << city << endl;
    cout << "Description: " << description << endl << endl;
 
    cout << "Thanks for signing up for Community Connections!" << endl;
 
    return 0;
}