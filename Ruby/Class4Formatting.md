# String Formatting
In ruby we have some method of string that return the same string with some letter changed or some value associated to the original string.
This are:
- capitalize: Make all first letters of the string uppercase
- uppercase: Make all characters of the string to uppercase
- downcase: Make all characters of the string got undercase
- reverse: Generate the reverse of the string
- length: Give us the length of the original string

For example:
```Ruby
myName = "Joaquin"
puts myName.reverse
```
Will print niuqaoJ.

Also we can access the characters of a string we can do it like in python through arrays. In this case:
```Ruby
puts myName[3]
```
Will print on console the character q.

To make an slice of the string we put:
```Ruby
puts myName[3..6]
```
and will print quin
