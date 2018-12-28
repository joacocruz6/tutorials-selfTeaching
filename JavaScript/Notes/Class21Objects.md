# POO in JavaScript
To use Objects in JavaScript, we have used before because we do properties and methods, that concepts are from and for Objects.

## How to create Objects in JavaScript
We will create the typical person object that will have three fields of information (properties) that are it's name, eye color and age.
Also will have a method that will update it's age, that will increase one to it.
So in this class we will do one object and no contructors.
## First form of creating objects
So one way to create objects it's the following:

We do:
```JavaScript
let person = new Object();
```
We use new as we use it on Java, this will create a new object referenced in the variable person.

So to set it's parameters we do:
```JavaScript
person.name = "Daniel";
person.eyeColor = "Blue";
person.age = 27;
```
To create it's methods we do:
```JavaScript
person.updateAge = function(){
  return ++person.age;
}
```
Now we have the updateAge method in the object person C:

## Second form to create objects
To create the object person like in the first way we do:
```JavaScript
let person = {
  name: "Daniel",
  eyeColor: "Blue",
  age: 27,
  updateAge: function(){
    return ++person.age;
  }
}
```
This is the same object of the first method.

This

## Some objects predefined in JavaScript
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference
