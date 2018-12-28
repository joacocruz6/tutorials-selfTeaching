# Polyformism of C++
The Polyformism is an strong concept in POO.


## Overriding methods
So now we are gonna to do some overrides to the method for not making duplicate coding.
For doing this, the methods of the class we add the keyword virtual when they are gonna be defined.

So we can continue the Student-Persons but now add some Professors to the mix. Show for every class was very bad, because we can do override of this method and save lines of coding.

Now the show method in person class can be:
```C++
class Person{
  private:
    string name;
    int age;
  public:
    Person(string,int);
    virtual void show();
};
```
And now C++ nows that the show method can be override by person subclasses. To override it, we have to declare it on the subclasses, like Student:
```C++
class Student : public Person {
  private:
    int studentCode;
    float finalGrades;
  public:
    Student(string,int,int,float); //respect the heritage
    void show();
};
```
In its definition method, we have to put:
```C++
void Person::show(){
  cout<<"My name is: "<<name<<endl;
  cout<<"My age is: "<<age<<endl;
}
void Student::show(){
  Person::show();
  cout<<"My code is: "<<studentCode<<endl;
}
```
And in that way we can do show for Students overriding the show from person.
## The new keyword
Now we gonna make references to our objects using pointers of C++.
In the main, we can do 3 persons pointers, to our objects:
```C++
int main(){
  Person* group[3];
  group[0]= new Student("Joaquin",21,18.9);
}
```
The new keyword is like the malloc function of C, but this time we don't manage the amount of
memory, C++ does that for us. This bunch of memory is dynamic, this is, we have to tell C++ when to destroy it by using
destructors.

To use the student methods, we use like in C, this is:
```C++
  group[0]->show();
```
And that's it!
## Extra by me: keyword delete
Delete are a generic destructor of objects, this means, its deallocate the memory space of a pointer pointing towards an object. It calls it's destructor!.
Also you can delete an entire array of objects by doing delete[] arrayName;
## Summary
By supporting heritage, C++ supports Polyformism and overriding of objects methods.

To explicit to C++ like, this will be a method capable of override, we put the keyword:
```C++
virtual
```
In it's declaration of the superclass.

Then to override it, we put it on the declaration of the subclass and then we put the subclass name of it's declaration.

Also, C++ manage pointers to objects like we had pointers to structs in C. To create a new pointer to an object we put the word new and then call a constructor. new keyword is like the malloc in C, so we have to explicit when that pointer is going to liberate it's resources. To liberate that pointer to an object, we use delete keyword to it.

If we have an array of pointers we use delete[].
