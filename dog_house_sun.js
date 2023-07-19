// Program to initiate Community Connections //

// Declare global variables 
let userName;
let userCommute;
let userPreferences;
let userZipcode;

// Create function to prompt for user data 
function promptUser() {
	// Prompt user for username
	userName = prompt('Please enter your username:');
	// Prompt user for commute
	userCommute = prompt('Please enter your preferred commute:');
	// Prompt user for preferences
	userPreferences = prompt('Please enter your preferences:');
	// Prompt user for zipcode
	userZipcode = prompt('Please enter your zipcode:');
}

// Create a function to find other users in the same zipcode
function findLocalUsers() {
	let localUsers = [];
	// Iterate through the user database
	for (let i=0; i< usersDatabase.length; i++) {
		// Compare user zipcode to other users in the database
		if (usersDatabase[i].zipcode === userZipcode) {
			// Add matches to localUsers array
			localUsers.push(usersDatabase[i]);
		}
	}
	return localUsers;
}

// Create a function to find potential matches in the same zipcode
function findPotentialMatches() {
	let potentialMatches = [];
	// Iterate through the local users
	for (let i=0; i<localUsers.length; i++) {
		// Compare user commute and preferences to local users
		if (localUsers[i].commute === userCommute && localUsers[i].preferences === userPreferences) {
			// Add matches to potential matches array
			potentialMatches.push(localUsers[i]);
		}
	}
	return potentialMatches;
}

// Create a function to connect users 
function connectUsers() {
	// Iterate through potential matches
	for (let i=0; i<potentialMatches.length; i++) {
		// Check if user is already connected
		if (!userConnections.includes(potentialMatches[i].username)) {
			// Add match as connection 
			userConnections.push(potentialMatches[i].username);
			// Send connection request to potential match
			sendConnectionRequest(potentialMatches[i].username);
		}
	}
}

// Create a function to send connection request
function sendConnectionRequest(username) {
	// Create message
	let message = {
		from: userName,
		content: 'I\'d like to connect!'
	};
	// Send message to specified user
	socket.emit('send message', message, username);
}

// Create a loop to continue running the application
while (true) {
	// Prompt user for data
	promptUser();
	// Find local users 
	let localUsers = findLocalUsers();
	// Find potential matches
	let potentialMatches = findPotentialMatches();
	// Connect users
	connectUsers();
}