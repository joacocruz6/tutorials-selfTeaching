# Data types
In JavaScript we also have data types like in the other programming languages.
So the types are:
```JavaScript
var word= "Hello"; //String type of variable
var otherWord='Hello'; //Also a string

var number=1; //integer or long type of variable
var realNumber=2.75; //float or double type of variable
var otherNumber=-2345 //negative integer (also an integer)

var bool1=true;
var bool2=false; //boolean data type

var notDefined; //undefined data type

var nullValue=null; //null data type, this is different of undefined.
```
So now how to figure out what type of



#### Strings inside strings
If we want to get a string inside of a string we need to handle different type
of quotes mark.
For example:
```JavaScript
var name= "My name 'is' Joaquin ";
var otherName='My name "is" Joaquin';
var invalidName= "My name "is"Joaquin"; //invalid, error
```
### Figuring out the type of data

If we want to get the data type of a variable, we use the keyword:

typeof

In example:
```JavaScript
var x=123;
var y=22.34;
var word="Hello";
var bool=true;
var nullValue=null;
```
If we do:
```JavaScript
console.log(typeof x); //->it prints number, but it is an integer
console.log(typeof y); //also prints number
console.log(typeof word); //->it prints string!
console.log(typeof bool); //->it prints boolean
console.log(typeof nullValue); //->it prints object, rememenber this is not a object
```

##Operators
JavaScript have the same operators for number variables as the other languages.
## String operators
So the strings operators are a little different from other languages. Here you
can add a string to a number If you do so, JS will turn the number into a string
with the text of the value of the number and concatenate to the string variable.
For example:
```JavaScript
var x=21;
var myAge="My age is: "+x;
console.log(myAge);
```
It will print My age is: 21, also if we do:
```JavaScript
var myAge="My age is: "+10;
console.log(myAge);
```
It will print My age is: 10, you have to be cautious about this, because if we do:
```JavaScript
var x=4+" "+5;
```
It's a string variable with the value "4 5".
