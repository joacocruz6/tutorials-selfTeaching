# Random Numbers in JavaScript
So to create random number we need to do some things before.

First, we have the Math inner object of JavaScript. So, in the exercise number 3 we used it. We used the function:
```JavaScript
Math.floor();
```
This is the mathematical floor function of integers that we all know from school.

There is the random method of math
```JavaScript
let calc = Math.random();
console.log(calc);
```
Creates a random double number between 0 and 1 non inclusive the 1.
So to create between 0 and n-1 we do:
```JavaScript
let n=20;
let calcn = Math.random()*n
```
But never catch the n number, to do this we do numbers between 1 and n:
```JavaScript
let n = 20;

let calcn = Math.random()*n+1;

```
And to transform it to an integer we have to do floor of this number
```JavaScript
let intn=Math.floor(calcn);
```
## Generic random number integer function
To create a random number of integers from m to n inclusive we can make the next function:
```JavaScript
let randomNumberGen=function(start,end){
  let random =Math.floor((Math.random() * end)+start);
  while (random>end) {
    random=Math.floor((Math.random() * end)+start);
  }
  return random;
}
