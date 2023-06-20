#!/usr/bin/perl

# Community Connections
#
# This program is a simple script that connects partners in the community.
# It uses a database of people and their interests to match community members
# with activities or groups that fit their interests.

use strict;
use warnings;

#use DBI;
use POSIX qw/strftime/;

# Set up connection to the database
my $dbh = DBI->connect("DBI:mysql:database=connections;host=localhost",
					   "user",
					   "password",
					   {'RaiseError' => 1});

# Create main loop
while (1) {
	# Get user input
	print "Please enter a command (list, add, quit): ";
	my $input = <STDIN>;
	chomp $input;
	
	# Start logic branches

	# List existing members
	if ($input eq "list") {
		# Select all users from the database
		my $sth = $dbh->prepare("SELECT * FROM members");
		$sth->execute();
		
		# Print out all users
		while (my @row = $sth->fetchrow_array()) {
			my($name, $email, $interests) = @row;
			print "Name: $name\n";
			print "Email: $email\n";
			print "Interests: $interests\n\n";
		}
	
	# Add new member
	} elsif ($input eq "add") {
		# Get user info
		print "Please enter the name: ";
		my $name = <STDIN>;
		chomp $name;
		
		print "Please enter the email: ";
		my $email = <STDIN>;
		chomp $email;
		
		print "Please enter the interests: ";
		my $interests = <STDIN>;
		chomp $interests;
		
		# Record the time of entry
		my $date = strftime("%Y-%m-%d %H:%M:%S", localtime);
		
		# Insert the new user into the database
		$dbh->do("INSERT INTO members (name, email, interests, date) ".
				 "VALUES ('$name', '$email', '$interests', '$date')");
				 
		print "Thank you for registering with Community Connections!\n\n";
	
	# Quit program
	} elsif ($input eq "quit") {
		last;
		
	# Invalid input
	} else {
		print "That is not a valid command.\n\n";
	}
}

# Disconnect from the database
$dbh->disconnect();