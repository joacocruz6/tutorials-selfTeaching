# Arrays in ruby

So we saw how to initialize an array. Now we need to see some operations, like in python we can access to certain variable in the array. Make an slice of it and etc...
So to initialize an array we do:

```Ruby
anArray = ["Hello","Joaquin"]
```

So if we a negative selection, it will happen like in python that is all the way around the array. But if we pass the negative we will get an index out of bounds error.

But if now we do a puts of this array, every line will be an element of the array declared.

Also we can add variable to an string inside the quotes marks, to do this we use the #{} operator:
```Ruby
a = "Hello"
puts "#{a} World!"
```
And this will print in the standard exit of ruby, the string Hello World!
