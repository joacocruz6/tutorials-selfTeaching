# Types of variables
So as we all know for this tutorial there are data types. Go is a compiled language, so you have to tell him what are this variables.
## Example 1
Create an add function that add 2 float of 64 bytes.
To created and use it we do the next program:

```Go
package main
import "fmt"
func add(x float64,y float64) float64 {
  return x+y
}
func main() {
  var num1 float64 = 5.6
  var num2 float64 = 9.5
  fmt.Println(add(num1,num2))
}
```

### Explanation
In Go, we do this in our program to tell what type of variables this are:

```Go
var //this tells go that here will be a variable
var name type //type of the variable
var name type = value //its value
```
And to tell what type of value a function return we can put it:

```Go
func name(/*Function parameters*/) typeOfFunction {
  //Instructions
}
```

## Some syntax sugar
So we can condese the syntax, so to the program we did before, we do now:
```Go
package main
import "fmt"
func add(x,y float64) float64 {
  return x+y
}
func main() {
  var num1,num2 float64 = 5.6,9.5
  fmt.Println(add(num1,num2))
}
```
And it's the same program, but also inside functions we can omit the var and the variable type keywords and Go compiler will put it for us when compile, but the types are static, this means once initialized the variables, their types can't change.
So now we can do the program like:
```Go
package main
import "fmt"
func add(x float64,y float64) float64 {
  return x+y
}
func main() {
  num1,num2 := 5.6,9.5
  fmt.Println(add(num1,num2))
}
```

## Constants
To make constants in Go, you explicit with the const keyword.

## Returning tuples

To make functions that returns two or more variables we put in parentesis every type of returning.
#### Example
```Go
package main
import "fmt"
func multiple(a,b int) (int,int) {
  return a,b
}
func main() {
  n1,n2 := 2,3
  fmt.Println(multiple(n1,n2))
}
```
## Waste of space
If a variable is declared but not used in our programs, Go will not compile and will throw an error. This make developing a little bit harder but makes it more efficient.

## Casting and passing types
You can cast types in Go, we can do:
```Go
var a int = 62
var b float64 = float64(a)
x := a
```
So x will be an int, b is a cast of float64 type of a.
