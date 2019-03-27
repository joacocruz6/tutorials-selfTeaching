# Loading data with a backend
So now we have a data that we want to refresh with ajax. For example comments in our website and we want to load more comments. We will make this using jQuery and some php. So the html is just a div with the comments and som button with the tag: Show more comments!. Also the id of the div box is comments. Now we want to use AJAX to load more comments. The html look like this:
```php
<?php
    include 'dbh.php'
?>
... Some jQuery imports and that...
<body>
    <div id="comments">
    </div>
    <button> Show more comments!</button>
</body>
...
```
We have the database in php called ajax and we have some comments stored on. The table is called comments, with an id (which is the pk), an author name and it's comment.

Now we have to create the conection to the database on a different script, this time a php script. The script is on the same folder called dbh.php. The script should look like this:
```php
<?php
$serverName = "localhost";
$username = "root";
$password = "";
$dbname = "ajax";
$conn = mysqli_connect($servername,$username,$password,$dbname);
?>
```
This is going to make the connection for the db with php, but is not required to make the ajax in general. Remember AJAX works with every text or datatype that is on a file and loads it to the website. Now we want to load the data on our website, so on the html we do:
```php
<! On the index.php file (the main one)>
<div id="comments">
<?php
    $sql = "SELECT * FROM comments LIMIT 2";
    $result = $mysqli_query($conn,$sql);
    if(mysqli_num_rows($result)>0){
        while($row = mysqli_fetch_assoc($result)){
            echo "<p>";
            echo $row['author'];
            echo "<br>";
            echo $row['message'];
            echo "</p>";
        }
    }
    else{
        echo "There are no comments!";
    }
?>
</div>
```
Now we have the initial comments, on the script tags we include the AJAX for the page:
```JavaScript
    $(document).ready(function(){
        var commentCount = 2;
        $("button").click(
            function(){
                commentCount = commentCount + 2;
                $("#comments").load("load-comments.php", {
                    commentNewCount: commentCount
                });
            }
        );
    });
```
And now we need to create the load-comments.php file, now we have passed some data on an object by post method, so the code should loaded like this:
```php
<?php
    include 'dbh.php'
    $commentNewCount = $_POST['commentNewCount']
    $sql = "SELECT * FROM comments LIMIT $commentNewCount";
    $result = $mysqli_query($conn,$sql);
    if(mysqli_num_rows($result)>0){
        while($row = mysqli_fetch_assoc($result)){
            echo "<p>";
            echo $row['author'];
            echo "<br>";
            echo $row['message'];
            echo "</p>";
        }
    }
    else{
        echo "There are no comments!";
    }
?>
```
And there we go!