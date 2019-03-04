class Question
    attr_accessor :prompt,:answer
    def initialize(prompt,answer)
        @prompt = prompt
        @answer = answer
    end
    def check(answer)
        return @answer == answer
    end
end
p1 = "What color are apples?\n(a)red\n(b)purple\n(c)orange"
p2 = "What color are bananas?\n(a)pink\n(b)red\n(c)yellow"
p3 = "What color are pears?\n(a)yellow\n(b)green\n(c)orange"

questions = [
    Question.new(p1,"a"),
    Question.new(p2,"c"),
    Question.new(p3,"b")
]

def run_test(questions)
    answer = ""
    score = 0
    for q in questions
        puts q.prompt
        answer = gets.chomp()
        if q.check(answer)
            score += 1

        end
    end
    puts "You got a #{score} out of #{questions.length()}"
end
run_test(questions)