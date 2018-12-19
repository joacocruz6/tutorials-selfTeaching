/**
Exercise 2: Make a class named Time that contains the following attributes:
*Hours
*Minutes
*Seconds
Make the class with two constructors, one that receive three ints and
and other that just receive one int that is the time measured in seconds
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class Time{
  private:
    int hours,minutes,seconds;
  public:
    Time(int,int,int);
    Time(long);
    void showTime();
};
Time::Time(int _hours,int _minutes,int _seconds){
  hours=_hours;
  minutes=_minutes;
  seconds=_seconds;
}
Time::Time(long seconds){
  //some calculus: 60 sec -> 1 min
  //60 min ->1 hour
  //3600 sec ->1 hour
  hours= (int) (seconds/3600)%24; //divided in the day
  minutes= (int) (seconds/3600)%60; //module divide the hours and give us just the minute
  seconds= (int) seconds%60
}
void Time::showTime(){
  cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
}
