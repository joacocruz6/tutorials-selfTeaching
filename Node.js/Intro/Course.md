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
And we run it, it will show us that the logger variable is a JavaScript Object. This object have a method called log, and nothing more. Let's call that function on our app:
```js
let logger = require('./logger');
logger.log('My message');
```
Now the best practice is that we define the import as a constant in order to not change the value. So the app will be now:
```js
const logger = require('./logger');
logger.log('My message');
```

One last thing we can export one thing, for example we have only one log function, so let's export that instead of the object:
```js
module.export = log;
```
Now we call it on the app:
```js
const logger = require('./logger');
logger('My message');
```

## The module wrapper function
So underhood what does node use to make the imports and exports?, so let's make a syntax error on the first line of our module:
```js
var x =;
```
So let's execute it with node, it will tell us what we already know but with saying that the error is produced in: 
```js
(function (exports,require,module,__filename,__dirname){var x=; //...
})
```
What is this?, this is the function that make run our code when exporting it and importing it, so know we know this function as the module wrapper function of a JavaScript file in node. Notice that instead of writing:
```js
module.exports.log = log;
```
We can do it by:
```js
exports.log = log;
```
Because the function receive the exports parameter, but we can't redifined it will be a error. We also have __filename and __dirname that is the complete file path and it's file name and the other one is just the directory respectively

## Path module
So there is a module very usefull for pathing, which is the path module. So let's create a file called app.js and use the module. Let's call the import path:
```js
const path = require('path'); // Built-in module, not use . or .. on the initial thing
```
So let's call and plug on the console the current path of our applycation:
```js
let x = path.parse(__filename);
console.log(x);
```
We will see an object, that is better to work with that instead of the full path to that item. 

## OS module
So let's use now the os module of node:
```js
const os = require('os');
```
Let's see the free and total memory of our machine:`
```js
let free = os.freemem();
let total = os.totalmem();
console.log({f: free,t:total});
```

## File System Module
Let's play with the file system module on node. Let's add it:
```js
const fs = require('fs');
```
This has asynchronous and synchronous method, but we will often use the asynchronous ones. Node work in a single thread, because of that the server have one thread to serve the clients, so need to have a callback function to execute when it's ready. So all the asynchronous methods have a function as the last argument to execute afterwards. The callback always receive an error and a result of the succesfull operation. For example let's scan our files on the current directory:
```js
const fs = require('fs');
const file = fs.readdirSyn('./');
console.log(files);
fs.readdir('./',(err,files) => {
     if(err) console.log('Error',err);
     else console.log(files);
});
```
## Events in Node
So node is usually used on the backend, and it has an API to handle events, which is something that is change or a notification to handle certain processes. For example, handle a raw http request on it. So first let load te event module:
```js
const EventEmitter = require('events'); // Class of the event emitter
```
We have the class methods on the emitter. So let's create a instance of the class ( an object).
```js
const emitter = new EventEmitter();
```
This is a emitter of events. Most of the times we use two methods:
* emit(<name of the event>) : Produce a new event 
* on or addListener(<name of the event>,<function to use when event raise>{callback}): Handler of the event.

The event has listener that 'listens' to the event when produce, now let's use it:
```js
emitter.on('Message log',()=> console.log('Listener Called'));
emitter.emit('Message log');
```

The registration of the events order it matters, if we add a listener afterwards, when emmiting the event, nothing would have happened.

### Event arguments
Now when an event is launched, we can pass some arguments to it, for example when making a connection we can pass the id of the connection and the url:
```js
emitter.emit('Connect',1,'https://example.ex');
```
But this is some magic making it, a better practice is to pass one object as the arguments, which will be called event argument object:
```js
emitter.emit('Connect',{id: 1, url: 'https://example.ex'});
```
Now on the call back we can receive the argument of the event as a argument of the function:
```js
emitter.on('Connect',(arg) =>{ //Some people call it e sometimes
     console.log(`Connection with id ${arg.id} and to the url: ${arg.url}`)
});  
```
## Extending the EventEmitter class
