# How to load data from server
So we need to load the data from the server using now AJAX. So now we want to retrieve data for the server


For example, we have a comment page with a lot of comments. Now we want to show more comments without refreshing the browser. On this time without a backend also.
First we need an html page, a basic one:
```html
<!DOCTYPE html>
<html>
<head>
    <title></title>
    <script
    src="https://code.jquery.com/jquery-3.2.1.min.js"
    integrity="sha256-h2g4gsxgFZhOsEEamdOYGBf13FyQuiTwlAQgxVSNgt4="
    crossorigin="anonymous"></script>
    <script>

    </script>

</head>
<body>
    <div id="test">
        <p> This is the first content!</p>
    </div>
    <button id="btn" >Click to change</button>
</body>
</html>
```
So we want to change the content of that tag with AJAX. We will use it alongside jQuery framework of selection. Now inside the script tags we do:

```JavaScript
$(document).ready(function(){
    $("#btn").click(function(){
        $("#test").load();
    });
});
```
Now what is going here. First we grab the document and then when the document is ready it's execute the function that is inside the parenthesis. The AJAX function is load and it's receive three parameters, the first one is the url where we want to load in, the method that the data will be transfered and last one is a callback function that is going to be execute it when the data will be received. Now the document that is going to be loaded have to exist and need to have some kind of data for example a txt, a html, php, etc... For example we can have a txt file called data.txt that have the following:
```txt
<p>The content have changed! </p>
```
So now on our jQuery javascript content we need to load that data. To do this (for this class) we do:
```JavaScript
$(document).ready(function(){
    $("#btn").click(function(){
        $("#test").load("data.txt");
    });
});
```
## The load function
The load function can have three parameters. The first one is the url, the second one is some data that we want to send to the server if we are working with one and the last one is a callback function. It's form looks like this:
```JavaScript
$(element).load(url,data,callback);
```
The data have to be a object of the form:
```JavaScript
data = {
    data1: SomeData,
    data2: OtherData
};
```
The callback is a function that is going to be run when the data had arrived to the page.