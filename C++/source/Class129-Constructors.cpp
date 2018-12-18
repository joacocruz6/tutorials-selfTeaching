#include <iostream>
#include <stdlib.h>
using namespace std;

class Date{
  private:
    int day,month,year;
  public:
    Date(int,int,int); //First Constructor
    Date(long); // Second constructor
    void showDate();
};
Date::Date(int aDay,int aMonth,int aYear){
  day=aDay;
  month=aMonth;
  year=aYear;
}
Date::Date(long aDate){ //type yyyymmdd
  int day=aDate%100;
  int month=(aDate/100)%100;
  int year=aDate/10000;
}
void Date::showDate(){
  cout<<day<<"/"<<month<<"/"<<year<<endl;
}
// example
int main(){
  Date someDate=Date(8,12,2017);
  Date anotherDate=Date(20171109);
  cout<<"Some date show: ";
  someDate.showDate();
  cout<<"Another Date show:";
  anotherDate.showDate();
  return 0;
}
