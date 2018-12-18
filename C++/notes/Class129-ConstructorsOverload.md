# Constructors overload

We are going to dig more in the Constructors of C++ objects.
The concept is what to do if we are going to make more than one constructor method for our object.

In example, we can ilustrate dates as the following object:
```C++
class Date{
  private:
    int day,month,year;
  public:
    Date(int,int,int); //First constructor
    void showDate();
};
```
And the methods are defined by:

```C++
Date::Date(int aDay,int aMonth,int aYear){
  day=aDay;
  month=aMonth;
  year=aYear;
}
void Date::showDate(){
  cout<<"Today is"<<day<<"/"<<month<<"/"<<year<<endl;
}
```
And there we go, nothing new right? Yeah but sometimes people defines the date by different order, like date/month/year, but we could define it like yearmonthdate. Not like three integers, but one long variable so we could add that long to our object:

```C++
class Date{
  private:
    int day,month,year;
  public:
    Date(int,int,int); //First constructor
    Date(long);  //second constructor
    void showDate();
};
```
And our second constructor could be:
```C++
Date::Date(long aDate){
  int day=aDate%100;
  int month=(aDate/100)%100;
  int year=aDate/10000;
}
```
And depends of the variable passed we can do the constructor we like.
