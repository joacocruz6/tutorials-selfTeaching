# Node.js Course
Video: https://www.youtube.com/watch?v=TlB_eWDSMt4
I'm on the minute: 27:26
## Introduction
Node.js is a runtime environment for executing JavaScript Code. It's not a framework and not a language, is an enviroment to take out JavaScript of the browser and executing it on the machine. It's open source and that is so cool!. We can just run JavaScript on the backend if we want or build an API for JavaScript, and so on... We now have the power of JavaScript on our machine. So using node has many advantages, but mainly we allow us to not change our JavaScript between front end and back end.
## The Node.js Architecture
So let's see how Node works first. So it's a enviroment (or a JS engine) that works outside the web. It's use the v8 engine, which is the same as in Chrome. 
Now what's the difference and the consequences that we have by letting JavaScript work outside the web. Remember that in JavaScript we can manipulate the DOM by the document or window (if you are crazy enough) by their respectives objects. Now we don't have that, which means, we can't do:
```js
var x = document.getElementById('');
```
But now we have other objects, like using the file system, listening to certain port of our machine, etc...

Node is non-blocking asyncronous constructor of applications by default, so be careful!. So this make node ideal for input and output intensive apps, because it doesn't need to throw multiple threads to handle request, is just one being pretty optimised for being ''asynchronous''. This is why is not good for CPU intensive apps.

## Installing Node
So let's install node. Let's open our bash or powershell or terminal. First check if node is already installed, we do this by typing:
```bash
node --version
```
I have the version 10, but the video uses the version 6. If we don't have node or have a early version we can install it by going to [Node Main page](https://nodejs.org/en/), and use the LTS. Then install it like always.

## Creating a first node app
So lets create our app, the node apps are *.js files like the browser's one. So let's create a hello world for example:
```js
function sayHello(name){
     console.log('Hello' + name);
}
sayHello('Joaquin');
```
So what's the difference with regular JavaScript? The answer is how we execute it, to do that we go to the bash and move to that particular directory with the file, let's call it first.js, and type:
```bash
node first.js
```
This is passing our file to the node environment to execute our programs!. But let's see what happen if we use window or document. So on our file we can do:
```js
function sayHello(name){
     console.log('Hello' + name);
}
console.log(window);
```
If we want to run it, it will show:
```bash
node main.js
```
We get a error, because window is not defined in node.

## Node Module System
Now we will see the modules build on node by default and how to create our own modules. The modules predefined are:
- os
- fs
- events
- http

### Global objects
So there are global objects build on node, for example:
```js
console.log();
```
The console object is known on every module of node, so we can access it on every file we create. Also we have for example:
```js
setTimeout(()=> console.log("hello"),1000);
```
So if it's standard JavaScript, we can use it on node. On this are:
```js
console.log();
setTimeout();
clearTimeout();
setInterval();
clearInterval();
```
But in our browser we have the window object which represent everything on JavaScript. For example, the console log method on the browser JS is: 
```js
window.console.log();
```
But in node we don't have the window object, instead we have the global object which replaces window:
```js
global.console.log();
```
But the main difference is that if for example in the vainilla JavaScript we do:
```js
var message = 'Some message';
```
Then the variable is passed to a propertie of the window object. Which means we can do:
```js
console.log(window.message);
```
But in node this do not happen with the global object, it doesn't add the message as a propertie of global:
```js
console.log(global.message);
```
Will be an error.

Now here is the important part, if we declare a function on JavaScript, it is added globally through the window object. Which means that:
```js
var sayHello = function(){
}
```
If we had this, we can do now: 
```js
window.sayHello();
```
But there is a problem with this behaviour, because if split the app within multiple files, then if two files have the same function name, then the one of them will be ignored. So we need to avoid making this to happen, we need modularity! (We need encapsulation of the files). Then every application has defined their module object and it's encapsulated. To make someone to see some functions we need to explicit say to node that it has been exported. Then there is a global object different from global that everyone in node knows which is the module one:
```js
console.log(module);
```
Will print our module object. In summary every file is a module and it's encapsulated within itself.
## Creating Modules
Let's create a module for logger messages, let's calle it logger.js. We want to use that module in another file called main.js. We will use one remote loggin services. So we have a url with requester of loggin in. Now:
```js
var url = 'http://mylogger.io/log';
```
Now we can use a log function to log in:
```js
function log(message){
     //Send an http request to log us in
}
```
We want to make the log function public in our app. So to export it we add:
```js
module.exports.log = log;
```
We just want to export the interface of usage, don't ever export the logic functions and variables!
### Loading modules
To load a module, we use the require function, which receive a route to our js module:
```js
require('./logger');
```
We don't put the js because node assume is a js file! It uses the relative path to it.
If we do now:
```js
let logger = require('./logger');
console.log(logger);
```
And we run it, it will show us that the logger variable is a JavaScript Object.

