I'm on the: 00:07:53
# Vue.js Course
## Installation
We want to start making apps with Vue.js because screw JS vanilla. To install it you need to have Node.js with the npm. Then we do:
```bash
$ npm install -g @vue/cli
# OR
$ yarn global add @vue/cli
```
To check if everything went ok, we do:
```bash
$ vue --version
```




## Creating a first app
Now, we want to make a new app. So for example we have this html page:
```html
<div id="root">
  <h1>Hello World</h1>
</div>
```
So now we want to apply some view js to it. First of all we want to create a Viu objects and attach it to a tag. Then we will delete the Hello World text and make it a vue js app.
So first of all we want to make the vue object to render things out, to do this we type:
```js
new Vue({
  el: '#root', //is the element that is bind to this vue object
  data: {
    greeting: 'Hello Vue' //data that contains this vue js object in it
  }
});
```
So now we want to tipe the data on the html, to do this we use it like on Django:
```html
<div id="root">
  <h1>{{ greeting }}</h1>
</div>
```
#### Another way to bind data to the Vue Object
Another way to bind data of our html is by adding inside the element that is binded to our Vue object is using the tag v-model.
For example we can change the greeting message with an input by doing:
```html
<div id="root">
  <h1>{{ greeting }}</h1>
  <input v-model="greeting">
</div>
```
And now all that we type on that input will change the data of our Vue object greeting parameter. And it live updates.

This method is called a directive and there are a lot of directives on Vue.js.

Another directive is:
  - v-if: Evaluates an expression giving true or false, and the content inside the tag will be shown when the expression is true.

    For example:
    ```html
    <div id="root">
      <div v-if="count === 1">
        Hey There!
      </div>
    </div>
    ```
    And the next code of the Vue object:
    ```js
    new Vue({
      el: '#root',
      data: {
        count: 0
      }
    });
    ```
    Now the data will not be showed, but if we change count to 1 will be shown.
  - v-else-if: Else if statement of Vue.js, it works the same way as in a normal programming language.
  - v-else: Vue else statement. An observation is that if this directives are false, they are not rendered at all.
  - v-show: It is similar to the v-if but if it is false, then it's still rendered on the html but with css display as none.

#### Some other directives
So now we got the next example:
```html
<div class="root">
  Sign Up
  <br>
  <input v-model="email">
  <br>
  <button onclick="alert('signed up')">Submit</button>
</div>
```
And the vue data:
```js
let app = new Vue({
  el: ".root"
  data: {
    email: ''
  }
});
```
Now we can use a new directive that is the v-bind. What this does is that it display the attribute of the html if and only if a condition is true. For example:
```html
<div class="root">
  Sign Up
  <br>
  <input v-model="email">
  <br>
  <button onclick="alert('signed up')" v-bind:disabled="email.length<2">Submit</button>
</div>
```
So now the button will be disabled if the length of the email text is less than 2. This is so common that Vue.js have a shortcut to it that is:
```html
<div class="root">
  Sign Up
  <br>
  <input v-model="email">
  <br>
  <button onclick="alert('signed up')" :disabled="email.length<2">Submit</button>
</div>
```

A common usage of v-bind is to change the class in a dynamic way. On this example lets have the next css code:
```css
.red {
  border: 2px solid red;
}
.green {
  border: 2px solid green;
}
```

Then we can change the class in a dynamic way by doing the following:
```html
<input v-model="email" :class="{red: email.length<5}">
```
This will toggle the red class if the input data is less than five, otherwise it will not have other data.

But if we want to make it change, we use the next notation:
```html
<input v-model="email" :class="[email.length<5 ? 'red' : 'green']">
```
This is an if else expression.

Another directive that is does the same thing as the {{}} is the v-text. We can added to a html tag to link and change the inner text of it. This will parse it as text, because there is another directive that parse it to html that is v-html. For example:
```html
<p v-text="email"></p>
```

#### Parsing text static
So we want not to change the code every time but to mantain it on a static way. To do this we use the v-once directive, and inside the html tags
