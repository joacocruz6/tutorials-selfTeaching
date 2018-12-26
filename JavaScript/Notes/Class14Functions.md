# Functions in JavaScript

In JavaScript are three different types:
1. Named functions
2. Anonymous functions
3. Inmediatly evaluate expression function
## Named Functions
A named function we will named like
```JavaScript
function testExample(/*parameters*/){
  //instructions
}
```
For example, we can do a simple greetings function:
```JavaScript
function greetings(){
  var greeting="Hi! My name is Joaquin";
  console.log(greeting);
}
```
But now we can return that value:
```JavaScript
function greetings(){
  var greeting="Hi! My name is Joaquin";
  return greeting;
}
```

Now we can pass some name to it:
```JavaScript
function greetings(name){
  var greeting="Hi! My name is "+name;
  return greeting;
}
```
#### Running the function
To run this function we have to call it on other function or in the script, like Python language.
So to use the greetings function of the example we do:
```JavaScript
greetings("Daniel");
//or
var x=greeting("Daniel");
console.log(x); //will print the result of the function
```
## Anonymous Functions
They are functions without a name, they can be attached to a variable.
They look like:
```JavaScript
var x=function(/*arguments*/){
  //instructions
}
```
To use it on our script we do:
```JavaScript
x(/*arguments*/);
```

## Inmediatly invoked function expression
Functions without name that runs inmmediatly the code is loaded.
To use it, we do:
```JavaScript
function(/*parameters*/){
  //instructions
}
```
But this will not run, to make it work we have to make it like:
```JavaScript
(function(/*arguments*/){
  //instructions
}(/*parameters given*/))
```
This will be executed as the content get loaded on the website.
