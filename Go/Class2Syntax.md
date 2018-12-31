# Syntax of Go
So for now we start the program of Go with the package that the file will be part of, this is made with:
```Go
package nameOfThePackage
```
Generally there is a main package, that is the main one of our project.

Then if we want to import some library or packages we do:
```Go
import "NameOfLibrary"
```
But if we want to import multiple libraries we can do:
```Go
import ("lib1"
        "lib2"
        ...)
```
The input and output of data library is the fmt, and the mathematical functions are math.
If we want an specific function of the library math, it is specified with an /:
do:
```Go
import "math/rand"
```
And this will import the rand function of the math package.

So if we want to use or do a function that is going to be exported afterwards, this MUST be starting with a capital letter.
#### Example 1
The next program will write in our bash the square root of 4:
do:
```Go
package main
import ("fmt"
        "math")
func main(){
  fmt.Println("The square root of 4 is",math.Sqrt(4))
}
```

## Functions
So as you can see, we can start a function by:
do:
```Go
func nameOfFunction(/*Parameters*/){
  //Instructions
}
```
#### Example 2
The next program is a function that print a random number from 1 to a 100
do:
```Go
package main
import "fmt"
import "math/rand"
func foo(){
  fmt.Println("A number from 1-100",rand.Intn(100))
}
func main(){
  foo()
}
```
## Knowing more of a package or function
To know more of a package or a function in our bash we do:
do:
```bash
godoc packageName functionName
```
