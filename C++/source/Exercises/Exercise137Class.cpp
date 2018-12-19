/*Exercise 4:
Make a C++ program which corresponds the following herarchy:
Animal->Human(Subclass of Animal)->Dog(Subclass of Animal)
and override the eat() method
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
class Animal{
  private:
    string name;
  public:
    Animal(string);
    virtual void eat();
};
Animal::Anime(string _name){
  name=_name;
}
void Animal::eat(){
  cout<<"I'm eating animal food"<<endl;
}
class Human:public Animal{
  private:
    int age;
  public:
    Human(string,int);
    void eat();
};

Human::Human(string _name,int _age) : Animal(_name){
  age=_age;
}
void Human::eat(){
  cout<<"Eating Human Food"<<endl;
}
class Dog : public Animal{
  private:
    string race;
  public:
    Dog(string,string);
    void eat();
};

Dog::Dog(string _name,string _race) : Animal(_race){
  race=_race;
}
void Dog::eat(){
  cout<<"Eating dogge Food\n";
}
