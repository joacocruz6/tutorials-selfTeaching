I'm On the 46:00
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

### Constructor property
So every object on JavaScript have a constructor property which is the method that created it. For example if we do on the console:
```js
circle.constructor
```
And it will tell me which function created it.

What if we do it with an empty JavaScript Object:
```js
let x = {};
// This means let x = new Object();
```

So if we do:
```js
x.constructor
```
It will print the constructor to it. This means that everything in JavaScript have a constructor, like:
```js
new String(); //Instance empty '' "" or ``
new Boolean(); //true or false
new Number(); // 1, 2, 3, ...
```

## Functions are Objects
On JavaScript, functions are objects. Which means that have properties and methods. For example for the Circle constructor function, we have:
```js
Circle.name; //An string of the name of the function
Circle.length; //The number of arguments
Circle.constructor; // Which is the Function() constructor
```
The constructor of functions is behaved like:
```js
new Function("string of the parameters", "string of the body");
```
On our case, the circle function can look like the following:
```js
const Circle1 = new Function('radius',`
this.radius = radius;
this.draw = () => console.log('draw');
`);
```
To use it we do the exact same thing as before. Some of it's methods and properties are:
* call(this reference, *args) : Call the function to make it's action and the this reference is passed like an object.
* apply(this reference, array_of_args): Exactly the same, but args are passed on an array

## Value vs Reference Types
So we need to kanow which types are values are which types are references:

The Value Types on JavaScript are:
- Number
- String
- Boolean
- Symbol
- undefined
- null

And the Reference types are:
- Objects
- Functions
- Arrays

So the value types are independants of each other but the references are the same object for example:
```js
let x = 10;
let y = x;
x = 20;
console.log(x===y); //Returns false because they are values
```
But the next code:
```js
let x = {value: 10};
let y = x;
x.value = 20;
console.log(x.value === y.value); //Returns true because they are references to the same object
```

## Adding and removing properties
So we can modify on the fly the objects created. For example we can use  the circle created before:
```js
function Circle(radius){
    this.radius = radius;
    this.draw = () => {console.log('draw');}
}
let circle = new Circle(10);
```
Because we don't have classes we can create new properties and methods between the code itself. For example, we will add the location propertie to our circle object:
```js
circle.location = {x: 1};
// Or bracket circle['location'] = {x: 1};
```
Now to delete properties to an object, we use the delete keyword in this case if we want to delete the location:
```js
delete circle.location;
// Or in bracket notation
```

## For each loop
To iterate on an object, we use the for each loop. This do that a variable took the name of all the properties and methods names.
On our example if we want to:
```js
for (let key in circle){
    console.log(key);
}
```
So if we want it's value, we use the bracket notation. There is another way to get all the keys of an Object which is:
```js
Object.keys(circle); // Returns an array of the keys
```
Finally we can ask if an object have some propertie, for example if we want to ask if the circle have a radius propertie we do:
```js
console.log('radius' in circle); //Print true, can work for if's statements
```
## Abstraction
So sometimes we want to hide some implementation of the objects to the client, for example we can add the following to the circle:
```js
function Circle(radius){
    this.radius = radius;
    this.defaultLocation = {x:0,y:0};
    this.computeOptimumLocation = (factor) => {return;}
    this.draw = ()=>{
        this.computeOptimumLocation();
        console.log('draw');
    };
}
```
So we need to hide the details default location and computeOptimumLocation. To do this, we need to make private methods and properties. 

On JavaScript, we make private variables like declaring it as a variable on the constructor function like this:
```js
function Circle(radius){
    this.radius = radius;
    let defaultLocation = {x:0,y:0}; // This is now a private propertie
    let computeOptimumLocation = (factor=0.1) => {return;} // This is now a private function
    this.draw = ()=>{
        computeOptimumLocation(); //We just call it, because are locals methods and properties
        console.log('draw');
    };
}
```
Now this methods and properties survives because of the scope is within the object and not a single method of it.

## Getters and Setters
So now that we have getters and setters, we do this methods on the constructors. Technally this are not private methods on our object, but we can't access to it,to do this we have two ways. The first and naive way to do it is the following:
```js
function Circle(radius){
    this.radius = radius;
    let defaultLocation = {x:0,y:0}; // This is now a private propertie
    let computeOptimumLocation = (factor=0.1) => {return;} // This is now a private function
    this.getDefaultLocation = () => {return defaultLocation};
    this.draw = ()=>{
        computeOptimumLocation(); //We just call it, because are locals methods and properties
        console.log('draw');
    };
}
```
This is the common way to do it. But another way which we can call like this the method:
```js
circle.defaultLocation;
```
To do it like this, we do:
```js
function Circle(radius){
    this.radius = radius;
    let defaultLocation = {x:0,y:0}; // This is now a private propertie
    let computeOptimumLocation = (factor=0.1) => {return;} // This is now a private function
    this.draw = ()=>{
        computeOptimumLocation(); //We just call it, because are locals methods and properties
        console.log('draw');
    };
    Object.defineProperty(this,'defaultLocation',{
        get: () =>{
            return defaultLocation;
        }
    });
}
```
To do a setter know we do:
```js
function Circle(radius){
    this.radius = radius;
    let defaultLocation = {x:0,y:0}; // This is now a private propertie
    let computeOptimumLocation = (factor=0.1) => {return;} // This is now a private function
    this.draw = ()=>{
        computeOptimumLocation(); //We just call it, because are locals methods and properties
        console.log('draw');
    };
    Object.defineProperty(this,'defaultLocation',{
        get: () =>{
            return defaultLocation;
        }
        set: (value) =>{
            defaultLocation = value;
        }
    });
}
```
