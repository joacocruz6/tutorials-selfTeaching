#include <iostream>
#include <stdlib.h>

class Person{
  private:
    string name;
    int age;
  public:
    Person(string,int);
    void showPerson();
};

Person::Person(string aName,int aAge){
  name=aName;
  age=aAge;
}
void Person::showPerson(){
  cout<<"My name is: "<<name<<endl;
  cout<<"My age is: "<<age<<endl;
}
class Student : public Person{
  private:
    int studentCode;
    float finalGrades;
  public:
    Student(string,int,int,float);
    void showStudent();
};

Student::Student(string aName,int aAge,int myCode,float myGrades) : Person(aName,aAge){
  studentCode=myCode;
  finalGrades=myGrades;
}
void Student::showStudent(){
  showPerson();
  cout<<"My code is: "<<studentCode<<endl;
}

int main(){
  Student me = Student("Joaquin",21,12345,18.9);
  me.showStudent();
  me.showPerson();
  return 0;
}
