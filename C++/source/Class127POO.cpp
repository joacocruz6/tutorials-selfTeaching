#include <iostream>
#include <stdlib.h>
using namespace std;

class Person{
  private:
    int age;
    string name;
  public:
    Person(int,string);
    void read();
    void run();
};
Person::Person(int anAge,int aName){
  age=anAge;
  name=aName;
}
void Person::read(){
  cout<<"I'm reading"<<endl;
}
void Person::run(){
  cout<<"I'm running"<<endl;
}
int main(){
  Person myPerson= Person(30,"Alex");
  myPerson.read();
  myPerson.run();
  return 0;
}
