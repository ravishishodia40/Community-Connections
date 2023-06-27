Public Class CommunityConnections
  
    'Declare Variables
    Dim firstName As String
    Dim lastName As String
    Dim age As Integer
    Dim contactNumber As String
    Dim email As String
    
    'Initialise Variables
    firstName = ""
    lastName = ""
    age = 0
    contactNumber = ""
    email = ""
 
    'Method to retrieve user details
    Public Sub getDetails()

        Console.Write("First Name: ")
        firstName = Console.ReadLine
        Console.Write("Last Name: ")
        lastName = Console.ReadLine
        Console.Write("Age: ")
        age = Console.ReadLine
        Console.Write("Contact Number: ")
        contactNumber = Console.ReadLine
        Console.Write("Email: ")
        email = Console.ReadLine

    End Sub
    
    'Method to print stored user details
    Public Sub printDetails()

        Console.WriteLine("First Name: " & firstName)
        Console.WriteLine("Last Name: " & lastName)
        Console.WriteLine("Age: " & age)
        Console.WriteLine("Contact Number: " & contactNumber)
        Console.WriteLine("Email: " & email)

    End Sub
    
    'Method to update user details
    Public Sub updateDetails()

        Console.WriteLine("Which details would you like to update?")
        Console.WriteLine("1. First Name")
        Console.WriteLine("2. Last Name")
        Console.WriteLine("3. Age")
        Console.WriteLine("4. Contact Number")
        Console.WriteLine("5. Email")
 
        Dim choice As Integer = Console.ReadLine
        Select Case choice
            Case 1
                Console.Write("New First Name: ")
                firstName = Console.ReadLine
            Case 2
                Console.Write("New Last Name: ")
                lastName = Console.ReadLine
            Case 3
                Console.Write("New Age: ")
                age = Console.ReadLine
            Case 4
                Console.Write("New Contact Number: ")
                contactNumber = Console.ReadLine
            Case 5
                Console.Write("New Email: ")
                email = Console.ReadLine
            Case Else
                Console.WriteLine("Invalid selection.")
        End Select
 
    End Sub

    'Main Program 
    Sub Main()

        getDetails()
        printDetails()
        Console.Write("Do you wish to update your details? Y/N ")
        Dim answer as String = Console.ReadLine
        If answer = "Y" Or answer = "y" Then
            updateDetails()
            Console.WriteLine("Details Updated!")
            printDetails()
        End If

    End Sub

End Class