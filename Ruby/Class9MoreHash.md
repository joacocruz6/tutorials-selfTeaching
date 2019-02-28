# More of Hashes in Ruby
So we can now get the input of the user in a hash of ruby. To do this we can do receive an input and store it on a hash.

## Quick Example
A quick example is getting some info from the user
```Ruby
puts "What's your first name?"
first_name = gets.chomp

puts "How old are you?"
your_age = gets.chomp

puts "How many kids do you have?"
kid_amount = gets.chomp

puts "Are you male or female?"
male_female = gets.chomp

puts "You are a #(your_age) year old #(male_female). Your name is #(first_name) and you got #(kid_amount) children."
```
This is too extensive, now we can put it on a hash. This is done by:
```Ruby
puts "What's your first name?"
first_name = gets.chomp

puts "How old are you?"
your_age = gets.chomp

puts "How many kids do you have?"
kid_amount = gets.chomp

puts "Are you male or female?"
male_female = gets.chomp

facebook_knows_all = Hash.new
facebook_knows_all["first_name"] = first_name.capitalize
facebook_knows_all["your_age"] = your_age
facebook_knows_all["kid_amount"] = kid_amount
facebook_knows_all["male_female"] = male_female.capitalize

puts facebook_knows_all
```
