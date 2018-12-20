# Variables
### console log function
We can show in the command console of our browser, with the function:
```JavaScript
console.log(/*some message*/);
```

For example, we can show the sum of 10 plus 20.
```JavaScript
console.log(10+20);
```
And then the console will show the result that is 30.
### Declarating variables
In JavaScript to declarate variables, we use:
```JavaScript
var x= /*some value*/
```
Notice that, not like Java,C,C++, the type is ommited.
Here x will store some data that will be useful in the future.
The important thing to now is that variables stores data.
Also, we can just say that the variable exist not given it an initial value, this
is:
```JavaScript
var y;
```
So now we can rewrite the log made before with variables:
```JavaScript
var a=10;
var b=20;
var sum=a+b;
console.log(sum);
```
We can create variables also with these two methods:
```JavaScript
var a,b,sum;
a=10;
b=20;
sum=a+b;

var a=10,b=20,sum=a+b;
```
But the first method is the most common and the likely use in programmers because is more easy to read
### Declarating strings
Some variables can be text. This type are the strings variables.
The strings starts with " and end with another ". If you don't do this, the file will launch an error.
```JavaScript
var myName="Joaquin";
```
In this example, myName variable holds the text Joaquin.

### Log of unasigned variables
So suppose that now we do:
```JavaScript
var a;
console.log(a);
```
What will the console show us?. It will show us undefined D:
