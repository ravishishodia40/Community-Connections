package main

import "fmt"

func main() {
	fmt.Println("Welcome to Community Connections!")

	// Initialize Variables
	var name string
	var haveCommunity bool

	// Get User's Name
	fmt.Print("What's your name? ")
	fmt.Scanln(&name)
	fmt.Printf("Nice to meet you, %s.\n", name)

	// Get User's Community Status
	fmt.Print("Do you have a community? (y/n): ")
	fmt.Scanln(&haveCommunity)

	if haveCommunity {
		fmt.Println("Thanks for being part of our community!")
	} else {
		fmt.Println("We'd love for you to join our community!")
	}

	//Present Additional Resources
	fmt.Println("Check out our additional community resources:")
	fmt.Println("1. Join our online forum.")
	fmt.Println("2. Attend a local meetup.")
	fmt.Println("3. See our list of recommended websites.")
	fmt.Println("4. Connect with us on social media.")

	//Introduce Blog
	fmt.Println("We also have a blog where we share helpful tips and stories about our community. Be sure to check it out!")

	//Provide Ways to Connect
	fmt.Println("Thanks for checking us out, %s. Feel free to reach out if you'd like to learn more or get involved in our community.", name)
	fmt.Println("We look forward to hearing from you!")
}