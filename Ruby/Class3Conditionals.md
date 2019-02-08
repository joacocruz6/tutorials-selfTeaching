# Conditionals in Ruby
The conditionals on ruby work like the next sintaxis:
```Ruby
if #condition
  #Instructions
else
  #Instructions
end
```
For example, a page ask if you are 18+ will be like:
```Ruby
yourAge = 19 # the input
if yourAge <= 17
  puts "You are not old enough to enter this page."
else
  puts "You may enter! \n What is your gender?"
end
```
So the else if statement is :
```Ruby
if True
  #instructions 1
elsif True #Condition
  #instructions 2
else
  #instructions 3
end
```
