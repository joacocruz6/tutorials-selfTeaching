
Crash course link: https://www.youtube.com/watch?v=t_ispmWmdjY
I'm on minute:
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
- Capitalize: Make the first letter to upper case
- upcase: Make all the letters to upper case
- downcase: Make all the letters to lower case
- strip: Eliminate all the initial infront and after the string
- length: Generate the number of characters in the string
- include? aString: True if aString is in the string.
