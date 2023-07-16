#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

// Struct for storing user data
struct userData {
    string userName;
    int age;
    string location;
    string interests;
};

// Function for comparing user data
bool compareUserData(const userData &a, const userData &b) {
    if (a.age == b.age) {
        return a.location < b.location;
    } else {
        return a.age < b.age;
    }
}

// Struct for storing user connections
struct userConnection {
    string userName;
    vector<string> connections;
};

// Map to store user data
map<string, userData> userMap;

// Vector to store user connections
vector<userConnection> userConnections;

// Function to create a new user
void createUser(string userName, int age, string location, string interests) {
    userData newUser;
    newUser.userName = userName;
    newUser.age = age;
    newUser.location = location;
    newUser.interests = interests;
    userMap[userName] = newUser;

    userConnection newConnection;
    newConnection.userName = userName;
    newConnection.connections.push_back("");
    userConnections.push_back(newConnection);

    cout << "User " << userName << " has been created!" << endl;
}

// Function to delete a user
void deleteUser(string userName) {
    userMap.erase(userName);

    for (int i=0; i<userConnections.size(); i++) {
        if (userConnections[i].userName == userName) {
            userConnections.erase(userConnections.begin() + i);
        }
    }

    cout << "User " << userName << " has been deleted!" << endl;
}

// Function to display all users
void displayUsers() {
    for (auto i=userMap.begin(); i!=userMap.end(); i++) {
        cout << "User " << i->first << ":";
        cout << "Age = " << i->second.age << ", Location = " << i->second.location << ", Interests = " << i->second.interests << endl;
    }
}

// Function to add a connection between two users
void addConnection(string userName1, string userName2) {

    // Check if users exist
    if (userMap.find(userName1) == userMap.end()) {
        cout << "User " << userName1 << " does not exist. Connection cannot be made!" << endl;
        return;
    } 
    if (userMap.find(userName2) == userMap.end()) {
        cout << "User " << userName2 << " does not exist. Connection cannot be made!" << endl;
        return;
    }

    // Check if connection already exist
    for (int i=0; i<userConnections.size(); i++) {
        if (userConnections[i].userName == userName1) {
            vector<string>::iterator it; 
            it = find(userConnections[i].connections.begin(), userConnections[i].connections.end(), userName2); 
            if (it != userConnections[i].connections.end()) { 
                cout << "Connection between " << userName1 << " and " << userName2 << " already exists!" << endl;
                return;
            }
        }
    }

    // Add connection
    for (int i=0; i<userConnections.size(); i++) {
        if (userConnections[i].userName == userName1) {
            userConnections[i].connections.push_back(userName2);
        }
    }

    cout << "Connection between " << userName1 << " and " << userName2 << " has been added!" << endl;
}

// Function to remove a connection between two users
void removeConnection(string userName1, string userName2) {

    // Check if users exist
    if (userMap.find(userName1) == userMap.end()) {
        cout << "User " << userName1 << " does not exist. Connection cannot be removed!" << endl;
        return;
    } 
    if (userMap.find(userName2) == userMap.end()) {
        cout << "User " << userName2 << " does not exist. Connection cannot be removed!" << endl;
        return;
    }

    // Check if connection exists
    for (int i=0; i<userConnections.size(); i++) {
        if (userConnections[i].userName == userName1) {
            vector<string>::iterator it; 
            it = find(userConnections[i].connections.begin(), userConnections[i].connections.end(), userName2); 
            if (it == userConnections[i].connections.end()) { 
                cout << "Connection between " << userName1 << " and " << userName2 << " does not exist!" << endl;
                return;
            }
        }
    }

    // Remove the connection
    for (int i=0; i<userConnections.size(); i++) {
        if (userConnections[i].userName == userName1) {
            for (int j=0; j<userConnections[i].connections.size(); j++) {
                if (userConnections[i].connections[j] == userName2) {
                    userConnections[i].connections.erase(userConnections[i].connections.begin() + j);
                }
            }
        }
    }

    cout << "Connection between " << userName1 << " and " << userName2 << " has been removed!" << endl;
}

// Function to display user connections
void displayConnections(string userName) {

    // Check if user exist
    if (userMap.find(userName) == userMap.end()) {
        cout << "User " << userName << " does not exist!" << endl;
        return;
    }

    // Display user connections
    cout << "User " << userName << " is connected with: ";
    for (int i=0; i<userConnections.size(); i++) {
        if (userConnections[i].userName == userName) {
            for (int j=0; j<userConnections[i].connections.size(); j++) {
                if (userConnections[i].connections[j] != "") {
                    cout << userConnections[i].connections[j] << ", ";
                }
            }
        }
    }
    cout << endl;
}

// Function to suggest connections
void suggestConnections(string userName) {

    // Check if user exist
    if (userMap.find(userName) == userMap.end()) {
        cout << "User " << userName << " does not exist!" << endl;
        return;
    }

    // Suggest connections
    int userAge = userMap[userName].age;
    string userLocation = userMap[userName].location;
    string userInterests = userMap[userName].interests;
    vector<string> suggestedConnections;

    for (auto i=userMap.begin(); i!=userMap.end(); i++) {
        if (i->second.userName != userName && i->second.age == userAge && i->second.location == userLocation && i->second.interests == userInterests) {
            suggestedConnections.push_back(i->first);
        }
    }

    cout << "Suggested connections for user " << userName << ": ";
    for (int i=0; i<suggestedConnections.size(); i++) {
        cout << suggestedConnections[i] << ", ";
    }
    cout << endl;
}

int main() {

    // Create users
    createUser("John", 30, "New York", "Movies");
    createUser("Calvin", 30, "New York", "Movies");
    createUser("David", 25, "London", "Football");
    createUser("Bob", 28, "London", "Football");
    createUser("Amy", 28, "London", "Cricket");

    // Add connections
    addConnection("John", "Calvin");
    addConnection("David", "Amy");

    // Display users
    displayUsers();

    // Display connections
    displayConnections("John");
    displayConnections("David");

    // Suggest connections
    suggestConnections("John");
    suggestConnections("David");

    // Remove connections
    removeConnection("John", "Calvin");
    removeConnection("David", "Amy");

    // Delete users
    deleteUser("John");
    deleteUser("Calvin");

    return 0;
}