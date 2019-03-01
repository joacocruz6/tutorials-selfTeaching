## Enter two number and sum of it
puts "Enter a number:"
# first = gets.chomp() this get us a string
first = gets.chomp().to_f
puts "Enter another number:"
#second = gets.chomp() this get us a string
second = gets.chomp().to_f
sum = first + second # if we do first +second it will concatenate, we will have to converted
puts "It's sum is #{sum}"
