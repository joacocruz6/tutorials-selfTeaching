# Introduction
Go is a Google low level language. This means is fast and static typed language, and it's not interpreted.

## Our first Go program

So first of all, the extension of Go programs are .go .

```Go
package main
import "fmt"

func main(){
  fmt.Println("Welcome to Go!")
}
```
To run it we do
```bash
go run filename.go
```
### Explanation
So this a hello world basic instruction. Like in C and others we have a main function, but like in Java we have to be part of a package, and the default one is the main package of our project. The fmt library is the standard input and output of the computer.
