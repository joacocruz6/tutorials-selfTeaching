# Variables Scopes
The scopes of variables of JavaScript, they are classified in two types:
1. Global Scope Variables
2. Local Scope Variables

## Global Scope Variables
The global scope variable are defined just in the script but outside the functions
that are defined there. For example:
```JavaScript
var number=10;
function calc(){
  return number;
}
console.log(calc()); //it will print 10 that is the value of number
```

## Local Scope Variables
It's the variables defined inside functions and cannot be access outside of it, because
JavaScript recycle them and they are less resources on the browser and computer.
For example:
```JavaScript
function calc(){
  var number=10;
  return number;
}
console.log(number); //it will get error
```
