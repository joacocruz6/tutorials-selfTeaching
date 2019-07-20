Link:
https://www.youtube.com/watch?v=DLX62G4lc44
I'm on the: 1:03:06
- Pass: TODO list second phase
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
    <link rel="stylesheet" href="style.css" />
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

ReactDOM.render(
  <div>
    {" "}
    <h1> Hello World! </h1> <p> This is a paragraph </p>{" "}
  </div>,
  document.querySelector("#root")
);
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

## Moving components to separate files.

So the great thing that react has it's that we can separate our app to different components. But for now this is not usefull because they are all on the same file.

So to move components to multiple files we need to do is create a file with the exact same name of our component. Let's say MyApp.js, and put the function there, so we got now this two files:

```js
//index.js
import React from "react";
import ReactDOM from "react-dom";

ReactDOM.render(<MyApp />, document.querySelector("#root"));
```

```js
//MyApp.js

function MyApp() {
  return (
    <div>
      <h1> Hello World! </h1>
      <p> This is a paragraph </p>
    </div>
  );
}
```

But this will fail because, we don't have the jsx on the MyApp.js file, so we NEED to import react on it:

```js
//MyApp.js
import React from "react";

function MyApp() {
  return (
    <div>
      <h1> Hello World! </h1>
      <p> This is a paragraph </p>
    </div>
  );
}
```

The last thing to do is export the MyApp component to the world. So we do in ES6 modules style:

```js
//MyApp.js
import React from "react";

function MyApp() {
  return (
    <div>
      <h1> Hello World! </h1>
      <p> This is a paragraph </p>
    </div>
  );
}
export default MyApp;
```

Now let's import the component on our application:

```js
//index.js
import React from "react";
import ReactDOM from "react-dom";

import MyInfo from "./MyInfo";

ReactDOM.render(<MyApp />, document.querySelector("#root"));
```

Now we got our content back!

A good practice is to have a folder called components, so we grab the MyApp.js module into it and we fix the import on the index.js file:

```js
//index.js
import React from "react";
import ReactDOM from "react-dom";

import MyInfo from "./components/MyInfo";

ReactDOM.render(<MyApp />, document.querySelector("#root"));
```

## Parent and Child Components

So let's make a little bit more complex our application adding some hierarchy to the components.

So we will start from scratch the application, first let's make a simple file of our html:

```js
import React from "react";
import ReactDOM from "react-dom";

ReactDOM.render(<h1>Hello World! </h1>, document.querySelector("#root"));
```

So very simple for now right?, so now we can make a component that wraps up our entire application let's call it App, and we render it to the DOM:

```js
import React from "react";
import ReactDOM from "react-dom";
import App from "./App";
ReactDOM.render(<App />, document.querySelector("#root"));
```

So let's create it:

```js
import React from "react";

function App() {
  return <h1> Hello again </h1>;
}
export default App;
```

So let's make it like an actual website, so we add a navbar with some elements on it:

```js
function App() {
  return (
    <div>
      <nav>
        <h1> Hello again </h1>
        <ul>
          <li>Thing 1</li>
          <li>Thing 2</li>
          <li>Thing 3</li>
        </ul>
      </nav>
      <main>
        <p> This is where most of my content will go ... </p>
      </main>
    </div>
  );
}
```

So this is getting a little complex, if we want to change something is going to be a mess (this can grow and grow and never stop growing).

But we can make a tree of components, imagine this the App component have another component in it which is the navbar, and the main content. Now this content can have that paragraph on it and the navbar have the title and so for.

So for example if we need a footer now, we can add it to the app component very easy. So let's create the footer one:

```js
//Footer.js

import React from "react";
function Footer() {
  return (
    <footer>
      <h3> This is an awesome footer </h3>
    </footer>
  );
}
export default Footer;
```

So now let's added it to the application:

```js
import Footer from "./Footer";
function App() {
  return (
    <div>
      <nav>
        <h1> Hello again </h1>
        <ul>
          <li>Thing 1</li>
          <li>Thing 2</li>
          <li>Thing 3</li>
        </ul>
      </nav>
      <main>
        <p> This is where most of my content will go ... </p>
      </main>
      <Footer />
    </div>
  );
}
```

So we can refactor all this App content to just components. So we can nest component as much as we need.

## Syling Components with CSS classes

So to start this we will create a new simple application with a header, a main content and the footer. So we have this three files on it:

```js
import React from "react";
import ReactDOM from "react-dom";

import Header from "./components/Header";
import MainContent from "./components/MainContent";
import Footer from "./components/Footer";

function App() {
  return (
    <div>
      <Header />
      <MainContent />
      <Footer />
    </div>
  );
}

export default App;
```

Then that components are:

```js
//Header.js
function Header() {
  return <header>This is a header </header>;
}
export default Header;
```

```js
//MainContent.js
function MainContent() {
  return <main> This is the main content </main>;
}
```

```js
//Footer
function Footer() {
  return <footer> This is the footer </footer>;
}
```

So now let's add some styling to the component, on html we do this by the attribute of the tag called class, but we are not writing a html file anymore, this is a JavaScript file. So the class keyword is a language reserved one to create classes and prototype objects to them. So how we added it? Instead JSX use 'className':

```js
function Header() {
  return <header className="navbar"> This is a header </header>;
}
export default Header;
```

Now on the style.css we can add some styling to the classes:

```css
body {
  margin: 0;
}

.navbar {
  height: 100px;
  background-color: #333;
  color: whitesmoke;
  margin-bottom: 15px;
  text-align: center;
  font-size: 30px;
  display: flex;
  justify-content: center;
  align-items: center;
}
```

You can only applied to them is to JSX elements, is not components. Like regular HTML.

## JSX to JavaScript and Back

So let's understand how JSX and JavaScript make together. First of all let's create a new app component with a hello world inside:

```js
function App() {
  return <h1> Hello World! </h1>;
}
```

So now what if we want to do it with some variables, like taking a name and saying hello to that name:

```js
function App() {
  const firstName = "Bob";
  const lastName = "Ziroll";
  return <h1> Hello firstName + " " + lastName! </h1>;
}
```

This isn't gonna work. So what are we going to do now to make the JavaScript render as used to be. This is done by putting on our JSX some curly braces, like this:

```js
const App = () => {
  const firstName = "Bob";
  const lastName = "Ziroll";
  return <h1> Hello {`${firstName} ${lastName}`}! </h1>;
};
```

Notice that here we do it using ES6 arrow function, but this can be done on the usual way with named functions instead.

Now for example, let's create a hello in the morning and goodnight on the night:

```js
function App() {
  const date = new Date();
  return <h1> It is currently about {date.getHours() % 12} o'clock! </h1>;
}
```

Now the component promised:

```js
function App() {
  const date = new Date();
  const hours = date.getHours();
  let timeOfDay;
  if (hours < 12) {
    timeOfDay = "morning";
  } else if (hours >= 12 && hours < 17) {
    timeOfDay = "afternoon";
  } else {
    timeOfDay = "night";
  }
  return <h1> Good {timeOfDay}! </h1>;
}
```

## Inline Styling with JSX

So the style propertie of a HTML element is no valid on the JSX ones. It expects to be a JavaScript object, so if our html look like this:
```html
<h1 style="color : '#FF8C00'"> Hello World! </h1>
```
In our component, we use should use it like this:
```js
function App(){
  return (
    <h1 style={color: "#FF8C00"}> Hello World! </h1>
  )
}
```
But this doesn't work, because we write JavaScript on the JSX with curly braces, so to write the style we use now double curly braces:
```js
function App(){
  return (
    <h1 style={{color: "#FF8C00"}}> Hello World! </h1>
  )
}
```
To add additional styles, we add another propertie to that object, except with the '-' in the CSS ones, we replaces with the camelcase of the word. For example background-color will be now backgroundColor.
## Props in React
### What are Props
So let's take a first look to an html file:
```html
<html>
  <head></head>
  <body>
    <a> This is a link </a>
    <input />
    <img />
  </body>
</html>
```
So now what is wrong with this html? The thing is that they doesn't have their properties. So 