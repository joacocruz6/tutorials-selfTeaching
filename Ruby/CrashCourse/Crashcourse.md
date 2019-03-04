
# Introduction
So Ruby will be similar to python, so to do it more quickly i will see an crash course.

## Hello World
So we will start with a hello world program in ruby.
```Ruby
print "Hello World"
```
But also we can use a puts command, that is print with new line:
```Ruby
puts "Hello World"
```
So print does not use a new line but puts does it

## Drawing a Shape in Ruby
So now we can draw a shape with puts and print, like a triangle:
```Ruby
puts "   /|"
puts "  / |"
puts " /  |"
puts "/___|"
```
And this will draw a triangle in our console C:

## How Ruby execute instructions
So Ruby is an interpreted language, this is an interpreter will look every line and execute it, if it can't, will be an error.

## Variables
So we can use variables in Ruby, this is assign a letter or a space of memory to a piece of information.

In Ruby we use it like this:
```Ruby
variableName = data
```
For example, the variable 'a' stores the number 5, but then we change it to the string hello:
```Ruby
a = 5
puts a
a = "hello"
puts a
```
So the type of a variable is dynamic in Ruby, the interpreter will assign the size of it in memory, not like in C, Go, C++ or Java.
To put a variable value in an string in Ruby, we can use the #{} in the string. Like this:
  ```Ruby
    a = 5
    puts "I have a number of #{a} chocolates"
  ```

#### Better example and converting to string
So we have the next piece of story deployed:
```Ruby
puts "There once was a man named John"
puts "he was 70 years old."
puts "He really liked the name John"
puts "but didn't like being 70."
```
So an easy way to change the text it's to assign variables, in which case the code looks like this:
```Ruby
sex = "man"
name = "John"
age = 70
puts "There once was a #{sex} named #{name}"
puts "he was #{age} years old."
puts "He really liked the name #{name}"
puts "but didn't like being #{age}."
```
So if we want to change the text, we simply change the value of that variables.

#### Data Types
So like in all programming languages we have the usual data types:
- Integers and Longs
- Floats and Doubles
- Strings and Characters
- Booleans
- None
This is an example of them:
```Ruby
name = "Joaquin"
age = 21
gpa = 3.2
ismale = true
istall = true
flaws = nil
```

## Strings Methods
So the strings methods in Ruby are:
- capitalize(): Make the first letter to upper case
- upcase(): Make all the letters to upper case
- downcase(): Make all the letters to lower case
- strip(): Eliminate all the initial in-front and after the string
- length(): Generate the number of characters in the string
- include? aString: True if aString is in the string.
- index(aString): Give us where aString make it's first apparition in the string
We can access to characters like in python, this is, if 'a' is a string then a[0] it's first character.

Also, we can use this methods in string up-front and not necessarily variables.

## Math and Numbers
So there are the next number of operation:
- \+ is the sum
- \- is the subtraction
- \* is the multiplication
- ** is the power
- % is the module

The methods of numbers are:
- to_s : convert the number to a string
- abs(): give us the absolut value of the number
- round(): round up the float number
- ceil(): round up the float
- floor(): round down the float
In math class are the next methods, to use it we put:
```Ruby
a = Math.sqrt(36)
```
So we have to call the Math class to use the square root, there are also log, sin, cos, etc...

Also, the operational rules will get in ruby, this is int and int it's int float and int is float, etc...


## Getting input data from the users

To get input data we use the gets method.
So we will write a script of a input, so to store the input in a variable we can use:
```Ruby
puts "Enter Your Name: "
name = gets
puts "Hello #{name}"
```
So it will enter information.
The problem is that gets also get the newline character from the input. To fix that we use the chomp method:
```Ruby
puts "Enter Your Name: "
name = gets.chomp()
puts "Hello #{name}"
```
And chomp will get rid of the newline character of the enter. Also, it's important that gets.chomp will always get us a string. We need to convert to the type of input.
So to convert variable type there is the to_t where t is the type to be converted.

## Arrays
So to use arrays in ruby, we initialize it like this:
```Ruby
friends = Array["Pancho","Bau","Martin"]
puts friends
```
or like this
```Ruby
friends = ["Pancho","Bau","Martin"]
puts friends[0]
```
To do slices we do:
```Ruby
puts friends[0,2]
```
To initialize the array empty:
```Ruby
friends = Array.new
friends[0] = "Pancho"
friends[1] = "Bau"
friends[2] = "Martin"
```
But we can do a non linear information array, like having the 0 and 5th element of it but

##### Some methods
Some methods that the arrays have are:
- length(): Give us the length of the array
- include? aData : True if aData is in the array
- reverse(): Revert the array elements
- sort(): Sort the order of the array of elements of the same data type.

## Hashes

So we can use Hash like dictionaries on Python, this are key values pair of information.

For example, Hash of some state of the US:
```Ruby
states = {
  "Pennsylvania" => "PA",
  "New York" => "NY",
  "California" => "CA"
}
puts states
```
But all the keys are unique on the hash, it can't be two values with the same key. So now the index can be selected by the key, for example:
```Ruby
puts states["CA"]
```
Also we can specify the keys like:
```Ruby
states = {
  :Pennsylvania => "PA",
  :NewYork => "NY",
  :California => "CA"
}
puts states
```
And are the same hashes.

## Functions
So functions in ruby are with this form:
```Ruby
def name(arguments)
  #Main code here
end
```
For example the next function say hi to the user:
```Ruby
def sayhi
  puts "Hello User"
end
```
If we execute the code, nothing will be printed, we have to call it by doing:
```Ruby
def sayhi
  puts "Hello User"
end
sayhi
```
Also we can do it like:
```Ruby
def sayhi()
  puts "Hello User"
end
sayhi
```
So a more complex hello function can be:
```Ruby
def sayhi(name)
  puts "Hello #{name}"
end
aName = gets.chomp().to_s
sayhi(aName)
```
Also, we can gave parameters to default like in Python:
```Ruby
def sayhi(name,age=10)
  puts "Hello #{name} your age is #{age}"
end
sayhi("Joaquin")
```

#### Return in function
So like in all programming language the keyword return will return the function.
For example, a function that return the cube of a number:
```Ruby
def cube(number)
  return number * number * number
end
puts cube(3)
```
But we can return more values putting a coma in the return statement:
```Ruby
def cube(n)
  return n * n * n,10
end
puts cube(3)
```
We return the cube of 3 and also 10
## Conditionals
So conditionals in ruby look like this:
```Ruby
if conditional
  #instructions
else
  #instructions if conditional is false
end
```
Or just an if statement
```Ruby
if conditional
  #instructions
end
```
Or the else if:
```Ruby
if condition1
  #instructions 1
elsif conditional2
  #instructions 2
else 
  #instructions 3
end
```
And we can operate some values with boolean.
The logic operators are:
- and
- or 
- ! : is the not of python

The boolean operators are:
- ==
- <=
- <
- \>
- \>=

## Case expressions
Are special kind of conditional statement, like the switch of Java.
It's sintax is like the next form:
```Ruby
case variable
when comp1
  #instructions1
when comp2
  #instructions2
...
when compN
  #instructionsN
else
  #default instructions
end
```
For example, we can make a method that convert the abreviation of a day of the week and convert to it's full name.
```Ruby
  def get_day_name(day)
    day_name = ""
    case day
    when "mon"
      day_name = "Monday"
    when "tue"
      day_name = "Tuesday"
    when "wed"
      day_name = "Wednesday"
    when "thu"
      day_name = "Thursday"
    when "fri"
      day_name = "Friday"
    when "sat"
      day_name = "Saturday"
    when "sun"
      day_name = "Sunday"
    else
      day_name = "Invalid data"
    end
    return day_name
  end
```

## While Loops
The while loop in ruby looks like this:
```Ruby
while condition
  #instructions
end
```

## For Loops
The for in ruby is like a for each in a collection.
It's sintax looks like:
```Ruby
for var in collection
  #instructions
end
```
For example, the next program print out a collection of friends:
```Ruby
friends = ["Kevin","Karen","Oscar","Angela","Andy"]

for element in friends
  puts element
end
```
But also, we can make a do statement like a for each one. This is seen like:
```Ruby
collection.each do |var|
  #instructions
end
```
For looping on the index, we do:
```Ruby
for index in 0..n
  #instructions, loops from 0 to n including
end
```
Another sintax sugar, like each-do, for doing this is
```Ruby
n.times do |index|
  #instructions, this loops from 0 to n-1 times
end
```
## Comments
To write comments of one line in ruby, it's done by starting with a # on that line and afterwards, the values written there are ignored by ruby interpreted.

To write multiple lines of comments, we can do:
```Ruby
=begin
=end
```
With no white spaces before them.

## Reading files in Ruby
To read a file in ruby, we use the File class. This is done by:
```Ruby
File.open("path_to_file","mode") do |variable|
  #instructions
end
```
The modes can be read, write, overwrite. To reference the to the file is the variable. The file is closed in the end

For example, the next program prints out every line on the file:
```Ruby
File.open("myfile.txt","r") do |file|
  puts file.read() #read the whole file in one execution
end
```
The read makes an string output from the line.

This other program read and prints out the first line of the file:
```Ruby
File.open("myfile.txt","r") do |file|
  puts file.readline() #read the first line, and moves the cursor to the next line
end
```
To make the program from before we can do:
```Ruby
File.open("myfile.txt","r") do |file|
  for line in file.readlines() #make a collection of all the lines of the file
    puts line
  end
end
```
To write on a file, we use the method write on the proper mode.

## Exception handling
The exception handling in ruby are called rescues.

To catch an error or an exception the syntax is doing:
```Ruby
begin
  #instructions,it's the normal code
rescue
  #instructions that execute when the exception is thrown
end
```


For example, the next program handles a division by zero:
```Ruby
begin
  num = 10/0
rescue
  puts "Divided by zero"
end
```
But now to specify the exception, the syntax looks like:
```Ruby
begin
  #...
rescue typeofError
  #Instructions that execute when the type of error is thrown
rescue typeofError2
  #...
end
```
To store the exception in a variable, we do:
```Ruby
begin
  #...
rescue typeOfError => var
  #...
end
```
So the type of error will be stored on the variable var.

## Classes and Objects in Ruby

The syntax for making a class in Ruby looks like:
```Ruby
class NameOfClass
  #methods ...
end
```
To specify the attributes of the class, we do:
```Ruby
class Book
  attr_accessor :att1, :att2, :att3 #....
end
```
For example, this is a book class:
```Ruby
class Book
  attr_accessor :title, :author, :pages
end
```
Now to create instances of books, we do:
```Ruby
book1 = Book.new()
book1.title = "Harry Potter"
book1.author = "JK Rowling"
book1.pages = 400
```

#### Object constructor
To have a constructor, the class need have the method initiliazer. The sintax looks like:
```Ruby
class NameOfClass
  attr_accessor att1, att2
  def initialize(att1,att2)
    @att1 = att1 
    @att2 = att2
end
``` 
When we type @att1 it's the att1 of the class and not the parameter att1

To use it, we do:
```Ruby
var = NameOfClass.new(att1,att2)
```
#### Methods of the objects
To create methods on the classes in ruby, we do:
```Ruby
class NameOfClass
  #...
  def nameofmethod(params)
    #instructions
  end
end
```
## Inheritance in Ruby

To use the inheritance of objects in ruby we need a super class and a subclasses. If we got a super class called Super, to make a subclass of this, the sintax is like:
```Ruby
  class AnotherClass < Super
    #instructions
  end
```
Now the AnotherClass is a subclass of the Super class.

Finally, to use the inheritance when are instance variables of the objects, we have to call the super class intialize method. This is done by using a super keyword.
For example:
```Ruby
class SuperClass
  attr_accessor supParam
  def initialize(supParam)
    @supParam = supParam
  end
end
class SubClass < SuperClass
  attr_accessor subParam
  def initialize(supParam,subParam)
    super(supParam)
    @subParam = subParam
  end
end
```
##### Access control
To make the access control of ruby, we have to do:
```Ruby
class A
  def fuu     #this method is public
    #instructions
  end
  protected
    def m2    #this method is protected
      #instructions
    end
  private 
    def m3    #this method is private
      #instructions
    end
end
```
The attr_accessor make the attribute private in usage.
##### Override
Now to override the methods, we do the same sign of that method. (Same name and arguments of the method to be overwriten).
## Modules
To use modules, this is a group of methods or classes. This are like the packages of Java.

To create one, we simple do

```Ruby
#this is on the myModule.rb file
module myModule
  def m1
    puts "This is a method of m1"
  end
  def m2
    puts "This is a method of m2"
  end
end
```
myModule is essentialy storing the methods inside it. To include a module in another script, we do and use a method of it we do it by:
```Ruby
require_relative "myModule.rb"
include myModule
myModule.m1
```
The require_relative is for ''importing'' the other file relative of the current file that is being edited.