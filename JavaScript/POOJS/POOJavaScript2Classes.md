# Classes on JavaScript ECMA 6
Classes on javascript are the same as prototypes but are a syntactic sugar to it. So following the last part of basic POO, we need to first see a fundamental thing which is inheritance.

## Inheritance prototypes
So imagine the following Book method on javascript:
```js
function Book(title,author,year){
    this.title = title;
    this.author = author;
    this.year = year;
}
Book.prototype.getSummary = () => {
    return `${this.title} was written by ${this.author} in ${this.year}`;
};
```
Now we want to create an Object Magazine that inheritate from the book one, will have a month as a propertie also. To do this we type on 
it's constructor method:
```js
function Magazine(){
    Book.call(this,title,author,year); //It's calling the super constructor  from the Book object
    this.month = month;
}
```
On this way magazine is a sub class of book, but we don't inheritate it's methods,to do that we type:
```js
Magazine.prototype = Object.create(Book.prototype);
```
This is done right below the Magazine constructor. But this changes the constructor!. To do not this because it's a mess we do right below
the methods inheritance:
```js
Magazine.prototype.constructor = Magazine;
```
And there we go.

##Classes on Javascript
So prototype inheritance is a mess, we all know. To do it more cleaner we use classes which are introduced on ECMAScript 6. To create a class we do:
```js
class Book{

}
```
And there we go, an empty class without any constructor. To do a constructor we have the constructor method attached:
```js
class Book{
    constructor(title, author, year){
        this.title = title;
        this.author = author;
        this.year = year;
    }
}
```
Let's add some method to this class:
```js
class Book{
    constructor(title, author, year){
        this.title = title;
        this.author = author;
        this.year = year;
    }
    getSummary(){
        return `${this.title} was written by ${this.author} in ${this.year}`;
    }
}
```
So good right?. To create static methods we type static to one of them, for example:
```js
class Book{
    constructor(title, author, year){
        this.title = title;
        this.author = author;
        this.year = year;
    }
    getSummary(){
        return `${this.title} was written by ${this.author} in ${this.year}`;
    }
    static topBookStore(){
        return 'Barnes & Noble';
    }
}
```
Now we can do:
```js
console.log(Book.topBookStore());
```
Now to generate private variables we can't use the scope trick to do a private variable. But it's a convention that a private variable is done by an underscore name on it like _title or _author is intended to be private but it doesn't.
## Getters and Setters 
So to make setters and getters on the classes we do for example a square object:
```js
class Square {
    constructor(_width){
        this.width = _width;
        this.height = _width;
    }
    get area() {
        return this.width * this.height;
    }
}
let s1= new Square(5);
console.log(s1.area);
```
And to do area changes on the object we got the setters sugar:
```js
class Square {
    constructor(_width){
        this.width = _width;
        this.height = _width;
    }
    get area() {
        return this.width * this.height;
    }
    set area(area){
        this.width = Math.sqrt(area);
        this.height = this.width;
    }
}
console.log(new Square(5).area);
let s1= new Square(5);
console.log(s1.area);
s1.area = 25;

```

## Inheritence
Inheritence on classes is much simpler, the magazine object will look like this now:
```js
class Magazine extends Book{
    constructor(title,author,year,month){
        super(title,author,year);
        this.month = month;
    }
}
```
So we have the super pseudo variable on ES6. 

## Polymorphism on javascript
So let's define an animal class to ilustriate how the overriding of methods work and the polymorphism on JavaScript is done.
```js
class Animal{
    constructor(name){
        this.name = name;
    }
    makeSound(){
        console.log("Generic Animal Sound!!");
    }
}
class Dog extends Animal{
    constructor(name){
        super(name);
    }
    makeSound(){
        console.log("Woof Woof");
    }
}
```
There we are done, we override the make sound method. To use the parent class first for example we can do:
```js
class Animal{
    constructor(name){
        this.name = name;
    }
    makeSound(){
        console.log("Generic Animal Sound!!");
    }
}
class Dog extends Animal{
    constructor(name){
        super(name);
    }
    makeSound(){
        super.makeSound();
        console.log("Woof Woof");
    }
}
```
