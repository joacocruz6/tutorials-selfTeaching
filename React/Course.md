I'm on: 43:22
# Introduction, What is react?
We will build an app with react through the course. React is a JS library of front end. It based on components which are pieces of the UI. They are reausable, and every react app have at least one component which will be called root component, which contains child components therefore the app is a tree of components.

For example, let's think of tweeter, tweeter have a profile, the trends , a navbar and a feed. The feed have the tweets and the like components, then components can be made of more components!.

In terms of implementation, the components are typically a JS class with a state field and a render method. For example the tweets can be:
```js
class Tweet {
state={}
render() {
}
```
The render method tells how the UI looks like and it returns a React Element. Which is not a DOM Element, is a JS object that represents the DOM element on memory. That memory of the DOM elements on react is called * Virtual DOM * . So now that we have this virtual DOM we manipulate that DOM instead of the real one because react will be on charge of the changes on the real DOM. To update the real dom we have to change the state of our component and react will ''react'' to that change and it will change the real DOM.

# Downloading React
So first we need Node.js and npm. Then on our bash do:
```bash
npm i -g create-react-app
```
On the course, we will use this version:
```bash
npm i -g create-react-app@1.5.2
```
On vscode install the following extensions:
- Simple React Snippets
- Prettier - Code formatter

## Creating the first react app
So let's start with react, to create one let's do on our bash:
```bash
create-react-app <name_of_app>
```
This installs react and the following libraries:
- Development Server
- Webpack
- Babel
- etc...

But we don't need to configurate anything. Now let's create a react app called my-react-app:
```bash
create-react-app my-react-app
```
Then move the folder of the app and type:
```bash
npm start
```
Let's peek inside the project folder, there are:
- node_modules -> doesn't matter to much for now.
- public: this have:
	
	* favicon.ico
	* index.html -> have the root of our react app.
	* manifest.json -> metadata attributes 
- src: our project one, we have a app.js component which is the standard component of the project.

Now let's see the app.js file:
```js
import React, { Component } from 'react';
//...
class App extends Component {
	render() {
		return (
			<div className="App">
				<header className="App-header">
					<img src={logo} className="App-logo" alt="logo" />
					<h1 className="App-title"> Welcome to React </h1>
				</header>
				<p className="App-intro">
				To get started, edit <code> src/App.js</code> and save to reload.
				</p>
			</div>
			);
	}
}
```
Whaaaat, html on our js? Well yes, but this is not pure html, this is the JSX object (a react element) which is how the UI is going to look up. This pass through babel, which is a compiler for modern JavaScript to make things that our browser understands. For example if we write:
```js
const element = <h1> Hello World! </h1>;
```
Babel will transform it to:
```js
var element = React.createElement(
	"h1",
	null,
	"Hello World"
);
```
This code is called to the react create element. So it much simpler that just using react.

## Creating a component from scratch
Let's delete all the files on the src folder of our tutorial app. Now let's create a new file called ''index.js''. Now let's import some modules. The modules are:
```js
import React from 'react';
import ReactDOM from 'react-dom';
```
Now let's create a constant to create our app element, we will set it to a jsx expression:
```js
const element = <h1>Hello World!</h1>;
console.log(element);
```
Also react changes the browser view with every save, so if you want to autosave will get the refresh instantly.

Now we want to render this on the actual DOM, because the jsx component just exists on the virtual DOM of react.

To do this now we add the following lines:
```js
const element = <h1>Hellow World!</h1>;
ReactDom.render(element,document.querySelector("#root"));
```
The first argument is the react jsx element and the second one is where on the app is going to be (on which html or DOM object will it be), this time is the root one of the index.html of our project.

Now we will see the h1 tag on our app. In a real app, this element will be much complex, and we will have a tree of components attached to it. But for now is that simple to do it.

## Components on react
So we are ready to start on react, first create another project to get the little app we are going to build.  the app we will build is on the 22:42 of the video, and have many patterns of the react development. Which is a item list, and a navigation bar.

So let's install bootstrap on react, to do it we use it on npm:
```bash
npm i bootstrap@4.1.1
```
And we import it on our index.js file:
```js
import 'bootstrap/dist/css/bootstrap.css';
```
We then save, and now let's create a first component. Let's create a new folder inside the src folder called 'components'. Here let's add the first component which will be a counter. So let's create a file on the components folder called 'counter.jsx'.

On this module, we have to import react and it's component library. So the simple react snippets will do it for us (they are really common imports), the shortcut is: imrc + tab. And to create a component class we use cc + tab. 

Let's call the class Counter. This will not have an state, and will return a simple h1 with hello world on it. The code should look like this:
```js
import React, { Component } from 'react';
class Counter extends Component {
	render(){
		return <h1> Hello World </h1>;
	}
}
```

So now let's use this component on the index.js:
```js
import React from 'react';
import ReactDOM from 'react-dom';
import Counter from './components/counter';

ReactDom.render(<Counter />,document.querySelector("#root"));
```

## More than one tag on the jsx.
So let's create a button on the Counter component of our app, which will increment the counter. This will be something like:
```js
class Counter extends Component {
	render(){
		return <h1> Hello World </h1><button> Increment </button>;
	}
}
```
This is not ok, because babel will not know what to do, it's expecting one parent html element, not two like this one. So the solution can be, let's wrap the counter element on a div, this is one element with two inside (Like a tree!). So the Counter element looks like:
```js
class Counter extends Component {
	render(){
		return <div><h1> Hello World </h1><button> Increment </button></div>;
	}
}
```
Now we are cool with babel. Now to not write it on one line, we use parenthesis to do it on multiple lines, this looks much nicer (the formater will do it on every save), so the counter will look like:
```js
class Counter extends Component {
	render(){
		return( 
			<div>
			<h1> Hello World </h1>
			<button> Increment </button>
			</div>
			);
	}
}
```
Which looks way nicer. But we don't want so many div's on our app. This div is going to do anything on our app. To not creating this, we will have to tell react 'Hey we have to html elements on this component', this is done by putting no a div, a react component instead. This component is called ** React.Fragment**:
```js
class Counter extends Component {
	render(){
		return( 
			<React.Fragment>
			<h1> Hello World </h1>
			<button> Increment </button>
			</React.Fragment>
			);
	}
}
```
Not we have the two elements on the real DOM.
## Embedding Expressions
Instead of hardcoding the things on our components, we want them to change in a dinamic way. To do this, we will have a special property which is the ** state ** propertie. This is an object which include any data that the component will need. On this case, a count because it's a counter.
```js
class Counter extends Component {
	state = {
		count: 0,
	};
	render(){
		return( 
			<React.Fragment>
			<h1> Hello World </h1>
			<button> Increment </button>
			</React.Fragment>
			);
	}
}
```
Now to use it, we do it with on the render we use the curly braces:
```js
class Counter extends Component {
	state = {
		count: 0,
	};
	render(){
		return( 
			<React.Fragment>
			<span> {this.state.count} </span>
			<button> Increment </button>
			</React.Fragment>
			);
	}
}
```
The curly braces allow us to add expressions on our component render html. For example we can put 2+2 and it will render 4, or we can call a method of the component and it will do something to it. 

For example let's add a format for the counter, which is a method on our component:
```js
class Counter extends Component {
	state = {
		count: 0,
	};
	render(){
		return( 
			<React.Fragment>
			<span> {this.formatCount()} </span>
			<button> Increment </button>
			</React.Fragment>
			);
	}
	formatCount(){
		const { count } = this.state;
		return count === 0 ? "Zero" : count;
	}
}
```
Notice the pattern matching on the count constant. Also we are allowed to return jsx expressions to it, so it's pretty normal to do so if you want. This means that jsx is almost equall to a js value.
## Attributes on the components
So we want to set some attributes with some components state variables. It's strayforward from the last section:

```js
class Counter extends Component {
	state = {
		count: 0,
		imageUrl: "https://picsum.photos/200",
	};
	render(){
		return( 
			<React.Fragment>
			<img src={this.state.imageUrl} alt="" />
			<span> {this.formatCount()} </span>
			<button> Increment </button>
			</React.Fragment>
			);
	}
	formatCount(){
		const { count } = this.state;
		return count === 0 ? "Zero" : count;
	}
}
```
Now we want to apply a css class to our component, to do it we don't type 'class' to the attribute, it's a keyword on JavaScript so instead we do it by putting className:
```js
class Counter extends Component {
	state = {
		count: 0,
	};
	render(){
		return( 
			<React.Fragment>
			<span className= "badge badge-primary m-2"> {this.formatCount()} </span>
			<button> Increment </button>
			</React.Fragment>
			);
	}
	formatCount(){
		const { count } = this.state;
		return count === 0 ? "Zero" : count;
	}
}
```