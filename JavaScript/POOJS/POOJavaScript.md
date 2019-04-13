I'm On the 13:16
Video: https://www.youtube.com/watch?v=PFmuCDHHpwk
# Object oriented Programming on JavaScript
So this will a course of purely object oriented programming on the languajes.

## Remembering the concepts of POO
So the basic concepts of the POO are:
- Encapsulation
- Abstraction
- Inheritance
- Polymorphism

And an object is made of:
- Properties
- Methods

So in this section we will be doing the following:
- Creating Objects
- Factories and Constructors
- Primitives and Reference Types
- Working with Properties
- Private Properties
- Getters and Setters

### Creating an Object
So to create an object in javascript we can use what is called a object literal sintax, which is:
```js
let circle = {};
```
An object in JS is a collection of key and values pairs, like a dictionary on the other languajes.

The object that we are creating is a circle, so will have a radius and a location (which is another object):
```js
let circle = {
    radius: 1,
    location: {
        x: 1,
        y: 1
    } //This are properties
    draw: () => {
        console.log('draw'); //This is a method
    }
};
```
So to access to it we use the dot notation:
```js
circle.draw(); //we use a method
circle.radius; //we call a propertie
```

### Factories
So to create another circle, we have to do a duplicated code, and as we all know, this is a super bad practice. To do this in JavaScript, we do a factory function. Which in this case could be:
```js
//a factory function that creates more circles!
function createCircle(radius){
    return {
        radius, //this can be used because of a feature on ES6!
        location: {
            x: 1,
            y: 1
        }
    };
}
```
So this is a factory function that creates a circle object. To create one we do:
```js
let aCircle = createCircle(1);
let anotherCircle = createCircle(2);
```

### Constructors
So there is another way to create objectes which are constructors functions. Because that JavaScript doesn't have classes, we do a function of name of that object. An example with circles could be:
```js
function Circle(radius){
    this.radius = radius; //we use the this keyword to indicate that is a constructor of a Circle object
    this.draw = () => console.log('draw');
}
```
Now to create an instance of the Circle we do:
```js
let circleOne = new Circle(1); //the new keyword creates an empty object, like {};.
```
The new keyword makes three things:
- First, create an empty object.
- Then set the this keyword to point to that object
- Finally it will return that object from that constructor.

So if we don't put new, what happen? This is the case of using constructors, the this keyword point to the global object which is window. This make a lot of mess with our code. Don't forget it. So the disadvantage of a constructor is that some people can forget about the new keyword and make it worse, which is not
the case of using factories.


