# First Program
We will create our first program in C++.
So first we add the std library for input and output of data.
This is:
```C++
#include <iostream>
```

Then we create the main function, so we will start by doing the hello world.
So we do:
```C++
int main(){
  std::cout<<"Hello World!";
  return 0;
}
```
Then for omiting the std:: we simply reduce the program by this line:
```C++
using namespace std;
```
This line is added after the includes.

Then we will add some new lines, this can be made adding the \\n to the string or doing:
```C++
cout<<"Hello World!"<<endl;
```
So that's it!

Our program will do Hello World !.

# Summary
The default library of C++ to in and out is iostream.

Then the function to get data in the default C++ out is cout.

We use the 'using namespace std;' instruction to get rid of typing std:: every time we need to print something out.

Finally, C++ have a main function that will be executed when we run our programs.
