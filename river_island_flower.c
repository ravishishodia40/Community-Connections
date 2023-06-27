#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Global Variables 
int globalCounter = 0;

// User-Defined Structures 
typedef struct{
	char name[50];
	int age;
	char hometown[50];
	char email[50];
} user_t;

// Function Prototypes
void printUser(user_t* user);
void addUser(user_t* user);
int getUserCount();
user_t* findUser(int userID);

// Main Function 
int main(){
	
	// Create User Objects 
	user_t user1;
	strcpy(user1.name, "John Doe");
	user1.age = 35;
	strcpy(user1.hometown, "New York City");
	strcpy(user1.email, "john@example.com");
	
	user_t user2;
	strcpy(user2.name, "Jane Doe");
	user2.age = 25;
	strcpy(user2.hometown, "Chicago");
	strcpy(user2.email, "jane@example.com");
	
	// Add Users to Database
	addUser(&user1);
	addUser(&user2);
	
	// Retrieve User and Print Info
	user_t *foundUser = findUser(1);
	printUser(foundUser);
	
	return 0;
}

// Function Definitions
void printUser(user_t* user){
	printf("Name: %s\n", user->name);
	printf("Age: %d\n", user->age);
	printf("Hometown: %s\n", user->hometown);
	printf("Email: %s\n", user->email);
}

void addUser(user_t* user){
	// Add user to database
	globalCounter++;
	user->id = globalCounter;
}

int getUserCount(){
	return globalCounter;
}

user_t* findUser(int userID){
	user_t* foundUser = malloc(sizeof(user_t));
	if (userID <= globalCounter){
		// Retrieve user from database
		foundUser->id = userID;
		strcpy(foundUser->name, "John Doe");
		foundUser->age = 35;
		strcpy(foundUser->hometown, "New York City");
		strcpy(foundUser->email, "john@example.com");
		return foundUser;
	}
	else{
		return NULL;
	}
}