I'm On the 13:16
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
    }
};
```