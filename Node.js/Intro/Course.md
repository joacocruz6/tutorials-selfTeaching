# Node.js Course
Video: https://www.youtube.com/watch?v=TlB_eWDSMt4
I'm on the minute: 15:36
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