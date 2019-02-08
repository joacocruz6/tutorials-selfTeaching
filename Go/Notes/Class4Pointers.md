# Pointers in Go
So like C, Go have pointers to manage our memory.

Then imagine the next base program:
```Go
package main
import "fmt"
func main(){
  x:=15
  a:=&x
  fmt.Println(a)
}
```
So a is a pointer or reference to the variable x. So we have pointers to variables. So if you want to point to some variable in the memory we use the & operator.
But if we want to get access the data int that pointer we use the * operator.
So if we do now:
```Go
func main(){
  x := 15
  px := &x
  *px= 5
  fmt.Println(x) //will print 5
}
```
So the types of pointer are * (the normal type)  . Also we can create pointer to pointers, this are ** variables.
That's it!
