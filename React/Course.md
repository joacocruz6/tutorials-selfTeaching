I'm on: 0:00
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
Whaaaat, html on our js? Well yes, but this is not pure html, this is the JSX object (a react element) which is how the UI is going to look up. 

