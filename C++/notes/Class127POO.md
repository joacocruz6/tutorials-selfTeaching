# Object Oriented Programming

We will start with a little program of POO. In this part we will create a class, like person class.
To do this we add:

```C++
class Person{
};
```
This is a new empty class, in here we add the attributes of the class and the methods that the class will understand.

In C++, like Java, we had some privacy things. To put what is private and what is public or protected, we put the words:
```C++
class Person{
  private:
};
```
The fields after that we will be private, so is a good practice to put all our attributes private.

The person class with have a name, and it's ages.

```C++
class Person{
  private:
    int age;
    string name;// added in the stdlib.h library
};
```

Then we have defined the attributes that the human can have.

Now let's define some methods that the Person object can understand, like reading and running.
```C++
class Person{
  private:
    int age;
    string name;
  public:
    Person(int,string); //Constructor class method
    void reading();
    void running();
};
```
The first method is the constructor method. It allow us to make new person objects.

Now we have to define the methods declarated there, so now we do:
```C++
Person::Person(int anAge,string aName){
  age=anAge;
  name=aName;
}
```
So there we have our basic constructor method. We create new objects with it. Always is put by className::className(parameters).

Now we can define it's methods, to do this we create outside the methods defined inside the class.
So reading and running will look like:
```C++
void Person::reading(){
  cout<<"I'm reading"<<endl;
}
void Person::running(){
  cout<<"I'm running"<<endl;
}
```

Notice that the method have to start with className::classMethod to indicate C++ that method belongs to that class.

So in the main we can do a simple example:
1. Create a person myPerson.
2. He reads
3. He runs
```C++
int main(){
  Person myPerson=Person(30,"Alex");
  myPerson.reading();
  myPerson.running();
  return 0;
}
```
And that it!
# Summary
To create classes in C++ we use the class keyword and define the privates arguments and the public ones using the keywords of the same name.
For example:
```C++
class nameOfClass{
  private:
    //put private fields here
  public:
    //public fields go here
};
```
Then to define a method in the class, we put the name and return on the public field, and then outside the class we define it's body:
```C++
class nameOfClass{
  private:
    ...
  public:
    nameOfClass(/*type of it's parameters*/); /*The constructor has the name of the class*/
    typeofreturn method1(/*type of it's parameters*/);
    ...
};
nameOfClass::nameOfClass(/*parameters*/){
  //constructor
}
typeofreturn nameOfClass::method1(/*parameters*/){
  //body of the method
}
```
