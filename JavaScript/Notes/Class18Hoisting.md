# Hoisting in JavaScript
## Preview
When we declared a variable in JavaScript you declared the type of variable (var,let,const).
For example:
```JavaScript
var a;
a="First";
var b="Second";
var c="Third";
console.log(a+" "+b+" "+c);
```
Declaring the variable and assigned the value to it will affect hoisting.
## Hoisting
The hoisting in JavaScript is that when the document or website content is loaded, the browser will ''read'' all the JavaScript and the variables declarations will put it on the top of it. So you can access it in any portion of the code that you want, this can be before of after assigning it's value to the variable.

For example, in the code showed before we do:
```JavaScript
var a;
a="First";
var b="Second";
var c="Third";
console.log(a+" "+b+" "+c);
console.log(d);
var d;
```
It will print on the console undefined, and not an error that we can probably assume. This means that the variable d is hoisted to the top of the code.

But if we do instead:
```JavaScript
var d="Fourth";
```
We still get undefined in the console log because it only takes on top the DECLARATION not ASSIGNING of the value.

This also means that we can do this:
```JavaScript
d="Fourth";
console.log(d);
var d;
```
And is going to print ''Fourth'' because the d assigning of the value it's on top of the console log and it's declaration is hoisted to the top of the code.

## Hoisting in functions
First imagine the example:
```JavaScript
function example(){
  var a=10;
  return a;
}
console.log(example());
```
We will get 10, but if we do now:
```JavaScript
console.log(example());
function example(){
  var a=10;
  return a;
}
```
We do still get 10!, this means that named functions are also hoisted in the top of our JS code.

## Con of Hoisted
The main con of hoisting is that makes JavaScript codes so slow because the browser have to look all the code to make it work on the first place and then run it normally.
So it's not recommended to

## How to avoid hoisting

To avoid variables it's pretty easy but how to avoid functions.

To avoid functions hoisting we use anonymous functions!

For example, the example function before we do:
```JavaScript
var a=function(){
  var a=20;
  return a;
}
console.log(a());
```
Now what is the difference from a normal named function?
If we do now:
```JavaScript
console.log(a());
var a=function(){
  var a=20;
  return a;
}
```
The console will throw an error because just the declaration of a is hoisted but not that it is a function.
