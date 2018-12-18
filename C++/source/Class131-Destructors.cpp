#include <iostream>
#include <stdlib.h>
using namespace std;
class Dog{
  private:
    string name,type;
  public:
    Dog(string,string);
    ~Dog(); // Object destructor
    void showData();
    void play();
};
Dog::Dog(string aName,string aType){
  name=aName;
  type=aType;
}
Dog::~Dog(){

}
void Dog:: showData(){
  cout<<"The dog name is: "<<name<<endl;
  cout<<"It's type is: "<<type<<endl;
}
void Dog:: play(){
  cout<<"The dog is playing"<<endl;
}
int main(){
  Dog myDog=Dog("Firulais","Chihuahua");
  myDog.showData();
  myDog.play();
  cout<<"Destroying the dog D:"<<endl;
  myDog.~Dog();
  cout<<"RIP dogge"<<endl;
  return 0;
}
