#include <iostream> 
#include <string>

using namespace std;

//Class to store data about the people within the community
class Person {
    string name;
    string profession;
    int age;
    string address;
 
public:
    Person(string n, string p, int a, string a2) 
    {
        name = n;
        profession = p;
        age = a;
        address = a2;
    }
 
    string getName()
    {
        return name;
    }
 
    string getProfession()
    {
        return profession;
    }
 
    int getAge()
    {
        return age;
    }
 
    string getAddress()
    {
        return address;
    }
 
    void setName(string n)
    {
        name = n;
    }
 
    void setProfession(string p)
    {
        profession = p;
    }
 
    void setAge(int a)
    {
        age = a;
    }
 
    void setAddress(string a2)
    {
        address = a2;
    }
};

//Function to add a Person to the community
void addPerson (Person person) 
{
    cout << "Name: " << person.getName() << endl;
    cout << "Profession: " << person.getProfession() << endl;
    cout << "Age: " << person.getAge() << endl;
    cout << "Address: " << person.getAddress() << endl << endl;
}

//Function to remove a person from the community
void removePerson (Person person) 
{
    cout << person.getName() << " has been removed from the community." << endl << endl;
}

int main()
{
    //Creating instances of the Person class
    Person person1("John Smith", "Teacher", 35, "123 Main Street");
    Person person2("Jane Doe", "Accountant", 45, "456 Main Street");
    Person person3("Bob Jones", "Doctor", 25, "789 Main Street");

    //Adding people to the community
    addPerson(person1);
    addPerson(person2);
    addPerson(person3);

    //Removing a person from the community
    removePerson(person2);

    return 0;
}