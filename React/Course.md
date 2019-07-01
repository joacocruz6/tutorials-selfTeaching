Link:

I'm on the: 24:40


# Introduction to React

### Why React?

So why use the react library. Some people say that is faster than vainilla JavaScript.
This is true, React use something called the Virtual DOM, which manipulation is way faster than the real one.

Another thing to keep in mind is that React uses reausable web components in an application, and make the code nicer and more readable. For example the bootstrap navbar can be used like:
```html
<body>
<MySweetNavbar />
<MainContent />
<MySweetFooter />
</body>
```
This is a really nice, clean and simple code of a navbar.

### React DOM and the JSX
So let's get right to the code, (the guy of the video is on scrimba). So make a index.js and first of all let's import react on it:
```js
import React from "react";
import ReactDOM from "react-dom";
```
Simple so far right?, so now we will tell the DOM of react to render some things on our page:
```js
import React from "react";
import ReactDOM from "react-dom";

ReactDOM.render();
```
So the render method takes two arguments, the first one is what do we want to render and the second one is where is going to be render it. In code this looks like:
```js
import React from "react";
import ReactDOM from "react-dom";

ReactDOM.render(<what to render>, <where to render it>);
```
Now let's do a basic html file with the typical structure of a web page:
```html
<html>
  <head>
    <link rel="stylesheet" href="style.css">
  </head>
  <body>
    <div id="root"></div>
    <script src="index.pack.js" charset="utf-8"></script>
  </body>
</html>
```
The main atention will be on the div of the id "root". This div acts as a container for the entire application, so everything on the application will be on that div. So let's create a Hello World header 1 on the page,
we create this by:
```js
import React from "react";
import ReactDOM from "react-dom";

ReactDOM.render(<h1> Hello World! </h1>, document.querySelector("#root"));
```
What? Html on our JavaScript? Well yes but also no, React have something called jsx, which is a pseudo language to "put" html on the JavaScript, then React transpile it to a react DOM element. It has very similar syntax to Ja html.

Something to be clear about is that JSX doesn't allow us to put multiple html tag in once, we have to put a single tag with multiple inside for example:
```js
import React from "react";
import ReactDOM from "react-dom";

ReactDOM.render(<h1> Hello World! </h1> <p> This is a paragraph </p>, document.querySelector("#root"));
```
This is an error to react but the following:
```js
import React from "react";
import ReactDOM from "react-dom";

ReactDOM.render(<div> <h1> Hello World! </h1> <p> This is a paragraph </p> </div>, document.querySelector("#root"));
```
It's not, this is because div is one element, but an h1 and a p are two elements.

## Functional Components
So imagine what is going to be to put the entire page on the render method, that is not reusable and it's not near a component. So let's create a functional component to the page.

This are called functional because they are created by creating a function.

This have to be by the constructor convension, they return the JSX that we want to render, if there are more than in one line, wrap it on a parenthesis, for example the hello world will be like:
```js
import React from "react";
import ReactDOM from "react-dom";

function MyApp(){
  return (<div>
    <h1> Hello World! </h1>
    <p> This is a paragraph </p>
    </div>);
}
ReactDOM.render( (...), document.querySelector("#root"));
```
So to put it on the render method we simply do it like a self contained tag of html:
```js
ReactDom.render(<MyApp />, document.querySelector("#root"));
```
