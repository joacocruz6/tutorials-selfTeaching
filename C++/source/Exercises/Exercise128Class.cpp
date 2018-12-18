/*
POO Exercise 1: Make a class named rectangule with height and width attributes
and two methods, one to calculates it's area and the other to calculates it's
perimeter.
*/
//Solution:
#include <iostream.h>
#include <stdlib.h>
using namespace std;

//first we create the class
class Rectangule{
  private:
    int height;
    int width;
  public:
    Rectangle(int,int);
    int area();
    int perimeter();
};
Rectangle::Rectangle(int _height,int _width){
  height=_height;
  width=_width;
}
int Rectangle::area(){
  return height*width;
}
int Rectangle::perimeter(){
  return 2*(height+width);
}
int main(){
  Rectangle myRectangle=Rectangle(10,10);
  cout<<"The area is: "<<myRectangle.area()<<endl;
  cout<<"It's perimeter is: "<<myRectangle.perimeter()<<endl;
  return 0;
}
