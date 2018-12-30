# Changing HTML elements
With JavaScript we can change some HTML. So we need to grab some element in our sites. To do this, we do the following example:
```HTML
<h2 class="main-header example test" id="header-h2">Hello World!</h2>
```
Now we will grab that element with JavaScript:
```JavaScript
let header = document.querySelector("#header-h2");
```
Then to change the content inside the tags with:
```JavaScript
header.innerHTML="Hi there!";
```
Now the content of the page have changed!

## The outer HTML
To add elements in an old way (not use it but you have to now it!), we have the outer HTML that changes the elements out of the tag, for example to add a h3 tag we can do:
```JavaScript
header.outerHTML = "<h3 id='new'> Hello there!</h3>";
```

## Changing properties of the HTML tags

Now to change one propertie we have to just call it as a JavaScript propertie.
```JavaScript
header.id = "Daniel";
```
Now the header id is the Daniel string.

But what about the classes in this h2 element because there are a lot in this one.
For this we can get it's name with:
```JavaScript
let classNames = header.className; //we get the class name of the element
let arrayClass = header.classList; //we get an array of the different classes of the HTML element
```
Some of these properties are read only, this means that we can't do explicit modifications to it, but we it have some methods that modify these attributes. For example if we want to add more classes we do the add method to arrayClass.

Some documentation is available at:
https://developer.mozilla.org/en-US/docs/Web/API/Element
