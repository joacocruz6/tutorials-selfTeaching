# JavaScript Modules
I want to learn about the Modules uses on the past and now on the current ES6.

## Classic loading of JavaScript
So let's start with the basic and classics way of loading JavaScript files on a page. This is including a JS file on the script tag on the html, for example:
```html
<script src="main.js"></script>
<script src="example.js"></script>
<script>
function helloWord(){
	console.log("Hello World");
}
```
This is really fine if the app is simple of this, but it's not very scalable.
Also this is loaded in order of the script tags. So one way that was being popular it was like this:
```html
<script>
(function(t,d){
	var g = d.createElement(t);
	    s = d.getElementByTagName(t)[0];
	g.src = './example.js';
	s.parentNode.insertBefore(g, s);
}(document,'script'));
</script>
```
So this load the script tag asynchrounosly while the browser is loading the page and the DOM at the same time. Now this can be achieved by putting async on our tag:
```html
<script async src="./example.js"></script>
```
## Require.js
So a few years later, we will start using require.js module for loading our real modules on the project. This made it more scallable than before, which is becoming more obsolete on the past years. It uses de AMD pattern to load the files.
## Common JS
So common js is the way that js modules are being used today. It's very used also in Node.js so if you know Node, you probably know this. For example let's have a main.js file like this:
```js
var speak = require('speak');
speak('zhi',25);
```
And a math.js file:
```js
module.exports.add = function(a,b){
	return a+b;
};
```
Here we are using the export of a function, which is done by putting 'module.exports.<functionName>', now for example on our speak.js:
```js
var add = require('./math').add;
module.exports = function(name,age){
	var ageIn5Years = add(age,5);
	return 'Hello my name is: '+name+' and I am '+ageIn5Years+' old';
```
So to import it we require the module on our same folder and then we grab the function that we want to export. Now if we don't put a name, then we export to the module name.

## ES6 module system
### Default export
Now a days ES6 can make exports, to do the export we make to a function for example in foo.js:
```js
export default function foo(){};
```
So to import for example in index.js the foo function:
```js
import foo from './foo';
```
But because we put the import default, the export is that function (is the main function of the file) so we can call it whatever we want:
```js
import nameDoesntMatter from './foo'
``` 
### Named export
So we can make a named export, we can make multiple exports on the modules. For example, foo now can have:
```js
export function getBreakfast() {};
export function getLunch() {};
export const baz = 'baz';
export const letters = ['a','b','c'];
export default function getDinner() {};
```
Notice that we can export multiple things. So now to import it, like on index.js, we do:
```js
import {getBreakfast} from './foo';
import {letters} from './foo';
// Another way to do it
import {getBreakfast, getLunch} from './foo';
import dinnerTime, {baz,letters} from './foo';
```
The ones on the brackets are the named imports, and they will import that expecific function from the module. But dinnerTime will get the default one.
## Putting aliases to the imports
Now let's puts aliases on the imports because we may have some similars name. To do this, consider the foo.js from before but now the index.js have the following:
```js
import {getBreakfast as MyBreakfast} from './foo';
```
This imports the getBreakfast function from foo.js but we will use it on this module as MyBreakfast.

