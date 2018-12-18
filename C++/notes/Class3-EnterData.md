# Reading or Input data
For input data in C++, the iostream library provide us with the cin command.

First, we gonna ask the user for a number and then we will show that number to him.

So in the main, we do:
```C++
int main(){
  int number;
  cout<<"Digit a number plis: "
  cin>>number;
  cout<<"\n Your number is: "<<number<<endl;
  return 0;
}
```
And there you go.

Notice that another << is included because we can't add strings to ints, the cout command let us put additional << to add to the message some variables.
