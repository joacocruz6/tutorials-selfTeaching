# Adding HTML to a website

The tree we have to add a node to it. So to do it we do the next steps:

1. We create a new element in a variable
2. We create it's content
3. We merge this to things
4. We put it in our website

The methods allowed to do this are:
- Create element:
```JavaScript
document.createElement(/*Name of the element*/);
```
- Create Text Node:
```JavaScript
document.createTextNode(/*Content of the element*/);
```
- Merge it and put it on our website:
```JavaScript
appendChild(/*The content or element*/);
```

#### Example:
Create an element of the next web which is a box with a header:
```HTML
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <div class="box">
      <h1>This is a Title!</h1>
    </div>
  </body>
</html>
```
To do it we execute:
```JavaScript
let box = document.querySelector(".box");
let newElement = document.createElement("a");
let newContent = document.createTextNode("This is a link!");
newElement.appendChild(newContent);
box.appendChild(newElement);
```
And there we go, to add attributes, we change it like in the previous lesson with set attribute.
Now another way to do it is just adding text and not an element we can do:
```JavaScript
let box = document.querySelector(".box");
let newElement = document.createElement("a");
newElement.append("This is a link!");
box.appendChild(newElement);
```
And
