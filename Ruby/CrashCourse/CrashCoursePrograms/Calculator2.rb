#Improvement of the previous calculator
#Input: two numbers and its operations
def mult(n1,n2)
    return n1 * n2
end
def sum(n1,n2)
    return n1+n2
end
def div(n1,n2)
    return (1.0*n1)/n2
end
def minus(n1,n2)
    return n1-n2
end
puts "Type a number: "
first = gets.chomp
puts "Type a second number: "
second = gets.chomp
puts "Type an operation (+,-,*,/):"
op = gets.chomp
case op
when "+"
    res = sum(first,second)
when "-"
    res = minus(first,second)
when "*"
    res = mult(first,second)
when "/"
    res = div(first,second)
else
    res = "Invalid Operation"
end

puts "The result of the operation is #{res}"