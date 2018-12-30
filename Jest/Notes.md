# Jest

## Some Background
So testing is a fundamental in developing, so in JavaScript we need a test Framework to write test in our project, like in Java we have JUnit. In JavaScript we have Jest Framework.

## Setting up Jest
To use Jest, you need npm, so to get it you need to install Node.js

To start using it on a project, first if you want to create one, we grite the command on our bash:
```bash
$ npm init -y
```
This will produce our package.json file.

Now we have to install jest, to do this we put:
```bash
$ npm i -D jest
```
But also we can install it globaly (search it).

Now in our package.json we change the "scripts" when it's says "test": we change it's value to "jest".

## Starting to test
So we can have our script, for example, example.js. To create it's test file we put the name of it .test.js, in this file will be example.test.js
For example:
```JavaScript
const functions = {
  add: function(num1,num2){
    return num1+num2;
  }
}
module.exports = functions; //exports our functions
```
Now in our tests we have to imported, this is:
```JavaScript
const functions = require('./functions');
```
And now we starts writing some tests.

To do it, we type:
```JavaScript
test(/*Description*/,/*function*/);
```
So in this case:
```JavaScript
test('Adds 2 + 2 to equal 4',() => {
  expect(functions.add(2,2)).toBe(4);
});
```
Now what's going on here. expect function receive a function to be executed. Then we put toBe method that is the value that we expect to get when the function returns. The second parameter should be an anonimous function that calls expect and toBeSomething.
## Running the previous test
To run the test in our bash we type:
```bash
$ npm test
```
## Failing some test
If test have passed, it will show us a message that everything is ok and show the messages of the test passed.

If test have not passed we can look what was the failed test and was the real result was and what was the expected value.

## Using not
In testing, we can not assure that functions will mantain it's functionality. Test have to show that the application has bugs and when the test pass it should clear that bug. So in Jest we can preview what the test will not be using the not propertie.

For example, the add function before we can do it know this test:
```JavaScript
test('Adds 2 plus 2 and it will not be 5',()=>{
  expect(functions.add(2,2)).not.toBe(5);
});
```
And this test will pass.

## Testing especial results
So for now we have just tested expected values to be concrete ones, like 4 and 5. But we can test that values can be undefined, null, 0, etc...

The functions that allow you to do this are:
- toBeNull pass only if the argument is null
- toBeUndefined pass only if the argument is undefined
- toBeDefined is the opposite of toBeUndefined
- toBeTruthy pass only if the argument is true or 1.
- toBeFalsy pass only if the argument is false or 0.

We can not pass anything to our toBe function and the test should pass if we tested these functions.
## Comparison tests
Also we can test equality between objects with the method toBeEqual, because to be will compare references to the objects and not it's content. For example the function:
```JavaScript
const functions = {
  add: function(num1,num2){
    return num1+num2;
  }
  createUser: function(name,last){
    let user = {
      firstName: name,
      lastName: last
    }
    return user;
  }
}
```
Can be tested by Jest with the following test:
```JavaScript
test('User should be Joaquin Cruz Object',()=>{
  expected(functions.createUser('Joaquin','Cruz')).toBeEquals({
    firstName: "Joaquin",
    lastName: "Cruz"
  });
});
```
Also we can test less or greater than some things for example
```JavaScript
const load1=1000;
const load2 = 100;
expect(load1+load2).toBeLessThanOrEqual(2000);
```
This is very functional when working with float variables.

### Testing some arrays
To test the arrays, there is the matcher toContain that pass if and only if the array contain the element that Contain

## Working with asynchronous data
So we can test some AJAX with this. to do this we can create in functions a new function:
```JavaScript
fetchUser: () =>
axion
  .get('https://jsonplacyholder.typicode.com/users/1')
  .then(res =>res.data)
  .catch(err => 'error')
```
Then it's test will be:
```JavaScript
test('User fetched name should be Leanne Graham',()=>{
  expected.assertions(1);//promises return the real test
  return functions.fetchUser()
    .then(data => {
      expect(data.name).toEqual('Leanne Graham');
    });
});
```
You must always put the return and the expected assertions(1) because if not it will pass anyway.

But Jest also gave us the following setup to async functions:
```JavaScript
test('User fetched name should be Leanne Graham',async ()=>{
  expected.assertions(1);//promises return the real test
  const data = await functions.fetchUser();
  expect(data.name).toEqual('Leanne Graham');
});
```
And it's the equivalent of the test before.
## Verifying some types
So now the Jest frame work let us verify types of the returns or some data, for example:
```JavaScript
let x ="Hello";
test("Expected an string", ()=>{
  expect(typeof x).toEqual('string');
});
```
It will pass the test.

## Before tests and after test
We can do before tests and after eache test within Jest script.
So to do this:
```JavaScript
beforeEach(()=> functionToBeExecuted(...));
afterEach(...);
```

If we want to do it before and after all, we just execute beforeAll and afterAll instead of beforeEach and afterEach.
## Grouping the test
We can group some test in a very large one with describe. This is that this block will be executed in blocks
For example:
```JavaScript
describe(/*description*/,/*Jest common test and before/after test*/);
```
## Watch of line
We can watch the test passing while coding, this is adding the testwatch line with the value jest --watchAll and as we develop it will run the test.
To execute it we do:
```bash
$ npm run testwatch
```
## Example
Also the dude see an very interesting example at minute 30.

## Documentation
This class should be available at https://github.com/bradtraversy/jest_testing_basics
