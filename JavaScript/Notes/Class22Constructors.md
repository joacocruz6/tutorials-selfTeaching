# Constructors methods in POO JS
So in the previous class we did have:
```JavaScript
let person ={
  name: "Daniel",
  eyeColor: "Blue",
  age: 27,
  updateAge: function(){
    return ++person.age;
  }
}
```
But if we want another person, we will have to copy everything.
To simplify the creation of objects we create a constructor method, like this:
```JavaScript
function Person(name, eyeColor, age){
  this.name = name;
  this.eyeColor=eyeColor;
  this.age=age;
  this.updateAge=function(){
    return ++this.age;
  }
}
```
This is the constructor of the objects. We have the properties and the methods are anonymous functions.
So to create the person of before, we do:
```JavaScript
let person = new Person("Daniel","Blue",27);
```
And it is more easy to create new persons.
