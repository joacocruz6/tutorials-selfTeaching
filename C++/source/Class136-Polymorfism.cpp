#include <iostream>
#include <stdlib.h>
using namespace std;

class Person{
  private:
    string name;
    int age;
  public:
    Person(string,int);
    virtual void show();
};
Person::Person(string aName,int aAge){
  name=aName;
  age=aAge;
}
void Person::show(){
  cout<<"My name is: "<<name<<endl;
  cout<<"My age is: "<<age<<endl;
}
class Student : public Person{
  private:
    int studentCode;
    float finalGrades;
  public:
    Student(string,int,int,float);
    void show();
};

Student::Student(string aName,int aAge,int myCode,float myGrades) : Person(aName,aAge){
  studentCode=myCode;
  finalGrades=myGrades;
}
void Student::show(){
  Person::show();
  cout<<"My code is: "<<studentCode<<endl;
}
//example
int main(){
  Person* group[3];
  group[0]=new Student("Joaquin",21,12345,18.9);
  group[1]=new Person("Alex",30);
  group[3]=new Professor("Patrick",50,"CC3001");
  for(int i=0;i<3;i++){
    group[i]->show();
  }
  delete[] group;
  return 0;
}
