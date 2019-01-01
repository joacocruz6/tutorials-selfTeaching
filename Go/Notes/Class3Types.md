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
