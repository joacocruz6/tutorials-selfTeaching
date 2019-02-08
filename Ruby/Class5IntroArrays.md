# Split and a little of arrays
So to split a string in ruby, we do the .split method on that string.
For example, the string:
```Ruby
myName = "Joaquin Cruz"
sp = myName.split
puts sp
```
Now the split will make an array of the space of the split. But we can target a specific character to make the split, for example:
```Ruby
myName.split(" ")
```
Will split
## Something about the slices
There are two methods of slicing in ruby, the first is with two dots, but the second is with 3 dots. For example:
```Ruby
x = "Hello World!"
x[0..12]
x[0...12]
```
in the first method, it will grab the whole string on the variable x. But in the second method it will a slice of 0 to 11, not considerating the 12 character on the string.

## Introduction to arrays
To make an array in ruby, is just like in Python, we do the following:
```Ruby
x = [1,2,3,4,5]
```
And x is now an array of integers
