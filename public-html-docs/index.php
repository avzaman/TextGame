<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Unix Project 3</title>
</head>
<body>
    <form action="../cgi-bin/project3" method="post" enctype="multipart/form-data">
        <label for="letters">Select a letter:</label>
        <select id="letters" name="chosen">
            <?php
            // Generate options for letters A-Z
            for ($letter = 'A'; $letter <= 'Z'; $letter++) {
                echo "<option value='$letter'>$letter</option>";
            }
            ?>
        </select>
        <br><br>
        
        <label for="number">Enter a number (1-100):</label>
        <input type="number" id="number" name="count" min="1" max="100">
        <br><br>
      
        <label for="file">Choose a .txt file:</label>
        <input type="file" id="file" name="text" accept=".txt">
        <br><br>
      
        <input type="submit" value="Submit">
      </form>
    
</body>
</html>