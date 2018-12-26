# Let and Const variables
So, we have used only the keyword 'var' to declare variables until now.
From now on, we will not use more 'var' keyword because it has a flaw and they
fix it by adding 'let' and 'const' to the mix.
## The function and block scopes
In order to understand the 'var' flaw, we need to know the concepts of block and function scopes.
### Function scope
The function scope is the scope that is defined by the curly brackets of the function. Is the same
as the local scope.
### Block scope
Now the curly brackets is the key of the scopes, so if we do:
```JavaScript
var a=10;
{var a;}
```
On the curly brackets, we will create a new scope of variables, so it does not remember the global variable
from before.
In summary, adding curly brackets to a piece of script in JavaScript creates a new scope for variables

### The problem of var
So now if we do:
```JavaScript
if(1==1){
  var a=10;
}
console.log(a);
```
We expect to get an error of scope because it has not been declared, but no
the a it's printed ok!. So the issue is that why some blocks scope variable declaration
can be accessed from outside the block and why sometimes it can't. So to get a unified
scope marks of variables, JavaScript created 'let' and 'const'.

## Let variable
To create a let variable we do:
```JavaScript
let b=10;
```
The let variables respect all the block scopes, for example:
```JavaScript
if(1 == 1){
  let b=10;
}
console.log(b);
```
Then we will have an error message because it doesn't belong to that scope.
## Const variable
So to use constant variables (that cannot be changed,ever).
```JavaScript
const TEST=10;
console.log(TEST);
TEST=20; //we will get an error, we can't change const variables
```
