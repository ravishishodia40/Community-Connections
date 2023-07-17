import java.util.*; 
import java.io.*; 

// Community Connections Program 
public class CommunityConnections 
{ 
   static HashMap<String, User> userDatabase = new HashMap<String, User>(); 
   static ArrayList<Event> eventDatabase = new ArrayList<Event>(); 
   static String currentUserName; 
   static User currentUser; 
    
   public static void main(String[] args) 
   { 
      boolean quitProgram = false; 
        
      while (!quitProgram) 
      { 
         System.out.println("Hello! Welcome to the Community Connections Program!"); 
         System.out.println("Please pick one of the following options:"); 
         System.out.println("1) Create an account"); 
         System.out.println("2) Login"); 
         System.out.println("3) Quit the program"); 
           
         int userChoice = getUserInput(); 
           
         switch (userChoice) 
         { 
            case 1: 
               createAccount(); break; 
            case 2: 
               login(); break; 
            case 3: 
               quitProgram = true; break; 
            default:  
               System.out.println("Please enter a valid option."); 
         } 
      } 
   } 
    
   private static void createAccount() 
   { 
      System.out.println("Please enter your desired username:"); 
      String username = getUserString(); 
        
      while (usernameExists(username)) 
      { 
         System.out.println("That username is taken, please enter a different one:"); 
         username = getUserString(); 
      } 
        
      System.out.println("Please enter your email address:"); 
      String email = getUserString(); 
        
      System.out.println("Please enter a password:"); 
      String password = getUserString(); 
        
      User newUser = new User(username, email, password); 
      userDatabase.put(username, newUser); 
        
      System.out.println("Account successfully created!"); 
   } 
    
   private static boolean usernameExists(String username) 
   { 
      return userDatabase.containsKey(username); 
   } 
    
   private static void login() 
   { 
      System.out.println("Please enter your username:"); 
      String username = getUserString(); 
        
      while (!usernameExists(username)) 
      { 
         System.out.println("That username does not exist, please enter a valid one:"); 
         username = getUserString(); 
      } 
        
      System.out.println("Please enter your password:"); 
      String password = getUserString(); 
        
      User existingUser = userDatabase.get(username); 
        
      if (existingUser.verifyPassword(password)) 
      { 
         System.out.println("Login successful!"); 
         currentUserName = username; 
         currentUser = existingUser; 
         mainMenu(); 
      } 
      else 
      { 
         System.out.println("Incorrect password!"); 
      } 
   } 
    
   private static void mainMenu() 
   { 
      boolean backToMain = false; 
        
      while (!backToMain) 
      { 
         System.out.println("Welcome " + currentUserName + "!"); 
         System.out.println("Please pick one of the following options:"); 
         System.out.println("1) See Events"); 
         System.out.println("2) Create an Event"); 
         System.out.println("3) Logout"); 
           
         int userChoice = getUserInput(); 
           
         switch (userChoice) 
         { 
            case 1: 
               seeEvents(); break; 
            case 2: 
               createEvent(); break; 
            case 3: 
               backToMain = true; break; 
            default:  
               System.out.println("Please enter a valid option."); 
         } 
      } 
   } 
    
   private static void seeEvents() 
   { 
      for (Event event : eventDatabase) 
      { 
         System.out.println(event); 
      } 
   } 
    
   private static void createEvent() 
   { 
      System.out.println("Please enter the title of the event:"); 
      String title = getUserString(); 
        
      System.out.println("Please enter the date of the event (MM/DD/YYYY):"); 
      String date = getUserString(); 
        
      System.out.println("Please enter the time of the event (HH:MM:SS):"); 
      String time = getUserString(); 
        
      Event newEvent = new Event(title, date, time); 
      eventDatabase.add(newEvent); 
        
      System.out.println("Event successfully created!"); 
   } 
    
   private static int getUserInput() 
   { 
      Scanner scanner = new Scanner(System.in); 
      return scanner.nextInt(); 
   } 
    
   private static String getUserString() 
   { 
      Scanner scanner = new Scanner(System.in); 
      return scanner.nextLine(); 
   } 
    
   static class User 
   { 
      String username; 
      String email; 
      String password; 
        
      public User(String username, String email, String password) 
      { 
         this.username = username; 
         this.email = email; 
         this.password = password; 
      } 
        
      public boolean verifyPassword(String inputPassword) 
      { 
         return inputPassword.equals(password); 
      } 
   } 
    
   static class Event 
   { 
      String title; 
      String date; 
      String time; 
        
      public Event(String title, String date, String time) 
      { 
         this.title = title; 
         this.date = date; 
         this.time = time; 
      } 
        
      @Override 
      public String toString() 
      { 
         return this.title + ", " + this.date + ", " + this.time; 
      } 
   } 
}