<?php 

//Connect to database
$conn = new mysqli('host', 'username', 'password', 'dbname');

//Check for connection errors
if ($conn->connect_error) {
    die('Connection failed: ' . $conn->connect_error);
} 

//Get community data from database
$sql = 'SELECT * FROM community_connections';
$result = $conn->query($sql);

//Set default values for local community variables
$localName = '';
$localDescription = '';
$localImageUrl = '';

//Iterate through communities from query result
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        //Set community variables to their values from the row
        $localName = $row['name'];
        $localDescription = $row['description'];
        $localImageUrl = $row['image_url'];

        //Display community connection HTML
        echo '<div>';
        echo '  <h1>'.$localName.'</h1>';
        echo '  <img src="'.$localImageUrl.'" alt="Image of '.$localName.'" />';
        echo '  <div>'.$localDescription.'</div>';
        echo '</div>';
    }
}

//Close database connection
$conn->close();
?>