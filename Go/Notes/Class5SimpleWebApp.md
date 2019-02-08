# Creating a simple web application
So to create a web application we need to import the net/http package.

#### Example
We will create a simple one, this will be receiving a request of http protocol and handle to a port

```Go
package main
import ("fmt"
        "net/http")
func main(){
  http.HandleFunc("/",index_handler) // (URL to go, function to run)
  http.ListenAndServe(":8000",nil) // (Port,),nil<=>null of go
}
```
So now we have to make the index_handler function, this receive the rewrite and the request
```Go
func index_handler(w http.ResponseWriter,r *http.Request){
  fmt.Fprintf(w,"Whoa, Go is neat!") //fprintf write on where we tell it, (where to write,message)
}
```
So if we want to add another page, we add on the main function:
```Go
http.HandleFunc("/about/",about_handler )
```
And we create the function
```Go
func about_handler(w http.ResponseWriter,r *http.Request){
  fmt.Fprintf(w,"Hello World!")
}
```
