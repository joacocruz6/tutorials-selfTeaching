secret_word = "giraffe" #variable for the game
guess = ""
while guess != secret_word
    puts "Enter guess: "
    guess = gets.chomp()
end
puts "You win!"