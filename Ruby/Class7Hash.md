# Hash in Ruby

## Introduction
So we start a hash in ruby, like the dictionaries in python with the {} brackets. Let's make an hash brown:
```Ruby
hash_brown = {
  "topping_1" => "Sour Cream",
  "topping_2" => "Butter",
  "topping_3" => "Salt",
  "topping_4" => "Ketchup"
}
puts hash_brown #This will print the whole hash or dictionary
puts hash_brown["topping_2"] # this will print Butter
$end
```

### Hashes
So hashes are ruby python's dictionaries. Then,

#### Another way to create hashes in Ruby
 So to create an empty hash in ruby, we type in our script:

 ```Ruby
 first_hash = Hash.new
 first_hash["first_name"] = "Joaquin"
 first_hash["nickname"] = "Jacob"
 ```
 And everything is well defined in first_hash
