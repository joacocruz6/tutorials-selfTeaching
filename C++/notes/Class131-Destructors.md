# Destructor of objects
In C++ language we can destroy objects (free it's memory assigned).
In example, we had the dog class:
```C++
class Dog{
  private:
    string name, type;
  public:
    Dog(string,string);
    ~Dog(); //this is the destructor of the objects
    void showData();
    void play();
};
```
So now we defined the destructor as the method:
```C++
~ClassName()
```
they never receive the parameters.

If we miss putting the destructor of our class, C++ compiler put it for us the one of default.

Now the methods can be:
```C++
Dog::Dog(string aName,string aType){
  name=aName;
  type=aType;
}
Dog::~Dog(){

}
... //some code
```
Notice that the destructor have to remain it's body blank.

### Usage
So to use it we can do it in main:
```C++
int main(){
  Dog dogge= Dog("Firulais","Chihuahua");
  ... //do some actions to it
  dogge.~Dog() //we destroy the object, liberate its resources
  ... //some code
  return 0;
}
```
## Summary
