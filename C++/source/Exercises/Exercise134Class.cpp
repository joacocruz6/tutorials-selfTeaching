/* Exercise 3: Make a C++ program, which resolves the herarchy:
*                     -----------------
*               -----|     Person      |-------
*               |      -----------------      |
                |                             |
                v                             v
        -----------------           -------------------
       |    Employee     |          |     Student      |
        -----------------            ------------------
                                              |
                                              v
                                    --------------------
                                    |   Universitary    |
                                      ------------------
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
//Person class
class Person{
  private:
    string name;
    int age;
  public:
    Person(string,int);
    void showPerson();
    int getAge();
    string getName();
    void setAge(int);
    void setName(string);
};
Person::Person(string _name,int _age){
  name=_name;
  age=_age;
}
void Person::showPerson(){
  cout<<"My name is: "<<name<<endl;
  cout<<"My age is: "<<age<<endl;
}
int Person::getAge(){
  return age;
}
string Person::getName(){
  return name;
}
void Person::setAge(int newAge){
  age=newAge;
}
void Person::setName(string aName){
  name=aName;
}
//Employee class
class Employee : public Person{
  private:
    string company;
    int id;
  public:
    Employee(string,int,string,int);
    void work();
    string getCompany();
    void changeWork(string);
    int getID();
};

Employee::Employee(string _name,int _age,string _company,int _id) : Person(_name,_age){
  company=_company;
  id=_id;
}
void Employee::work(){
  cout<<"I work at: "<<company<<endl;
}
string Employee::getCompany(){
  return company;
}
void Employee::changeWork(string newJob){
  company=newJob;
}
int Employee::getID(){
  return id;
}

//Student class
class Student : public Person{
  private:
    string school;
    double grades;
  public:
    Student(string,int,string,float);
    void study();
    double getGrades();
    string getSchool();
};
Student::Student(string _name,int _age,string _school,float _grades) : Person(_name,_age){
  school=_school;
  grades=_grades;
}
void Student::study(){
  cout<<"I'm studying"<<endl;
}
double Student::getGrades(){
  return grades;
}
string Student::getSchool(){
  return school;
}
//Universitary
class Universitary : public Student{
  private:
    string career;
    string* course;
  public:
    Universitary(string,int,string,float,string,string);
    string getCareer();
    string* getCourse();
};
Universitary:: Universitary(string _name,int _age,string _school,float _grades,string _career,string* _course) : Student(_name,_age,_school,_grades){
  career=_career;
  course=_course;
}
string Universitary:: getCareer(){
  return career;
}
string* Universitary:: getCourse(){
  return course;
}
