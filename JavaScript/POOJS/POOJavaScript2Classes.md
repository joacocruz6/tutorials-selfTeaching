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