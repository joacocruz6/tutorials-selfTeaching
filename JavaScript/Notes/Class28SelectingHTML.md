# Selecting HTML for manipulation in JavaScript
To select an element of HTML in our JavaScript, we have the old methods. For example, we can have
```HTML
<div class="divclass" id="divid"></div>
```
Now to select this in our JavaScript code we need to use one of these methods:
```JavaScript
document.getElementById(/*The id of the element*/);
document.getElementByClassName(/*The class of the element*/);
document.getElementByTagName(/*The tag name of the element*/);
```
Now new methods are more easy to use, this are querySelector and querySelectorAll.
For example, if we want the div of above, by class and id respectively, we use:
```JavaScript
document.querySelector(".divclass");
document.querySelector("#divid");
document.querySelector("div");
```
It grabs the first tag of the document.
