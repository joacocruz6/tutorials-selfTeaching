# Heritage of Object
So now we are gonna look how to do Heritage in C++.
So in mode of example, we are gonna do Persons and Students.

The naive approach will be write both classes from 0. But this is not a well design, it too much code. But Students are Persons, so we can Heritage the Persons to the Students (Students do what all Persons can do).

```C++
class Person{
  private:
    string name;
    int age;
  public:
    Person(string,int);
    void showPerson();
};
... //define the methods here, see the code in source
```
Now to do the heritage in C++, we just do in it's class:

```C++
class Student : public Person {
  private:
    int studentCode;
    float finalGrades;
  public:
    Student(string,int,int,float); //respect the heritage
    void showStudent();
};
```
And there we go, we used the heritage to define the students. The students objects can have the constructor of it's parent classes (or super classes).

In the subclasses the constructor have to call the super constructors for functioning, this can be made by the following:
```C++
Student::Student(string aName,int myAge,int myCode,float myGrades) : Person(aName,age){

}
```
## Summary
To do heritage in C++, we extends the classes by putting:
```C++
class className : public parentClassName{
  ...
};
```
To do the constructors of the subclass, we need to call the super class constructor.
The constructor receive the parameters like:
```C++
className(par1,par2,par3,...,myPar1,myPar2); /*par1 is the first parameter of the parent class, myPar1 is my parameter number 1 that he super class doesn't have*/
```
This is going to be made by the following:
```C++
className:: className(/*parameters*/) : parentClassName(/*its parameters*/);
```
The super constructor can be anyone if there is more than one.
