I'm on the: 00:50:00
# Vue.js Course
## Using Vue.js on our scripts
To use Vue.js on our scripts, we can imported on the link side of our HTML, which are one of these three:
```html
<!-- For learning porpouses, these is the latest version -->
<script src="https://cdn.jsdelivr.net/npm/vue"></script>
<!-- For developing, this is the latest stable-->
<script src="https://cdn.jsdelivr.net/npm/vue@2.6.10/dist/vue.js"></script>
<!-- If using native ES Modules we use: -->
<script type="module">
  import Vue from 'https://cdn.jsdelivr.net/npm/vue@2.6.10/dist/vue.esm.browser.js'
</script>
```
For more info visit: https://vuejs.org/v2/guide/installation.html

Or install the vue cli. The vue cli is for large apps, so it will be more complicated if we want to use a backend framework like rails or Django.
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
So we want not to change the code every time but to mantain it on a static way. To do this we use the v-once directive, and inside the html tags will be parsed and rendered once.

#### Looping
So in Vue.js we can loop within the HTML. The directivo to do this is v-for. For example, we will loop in an array of cats:

And the array is on the Vue object:
```js
app = new Vue({
  el: '#root',
  data: {
    cats: [
      'kitkat',
      'fish',
      'henry',
      'bosco',
      'melanthios'
    ]
  }
});
```
So now we want to display it on a unordered list on our html, to do this we execute the v-for, like a for each, directive:
```html
<div id="root">
  <ul>
    <li v-for="cat in cats">{{ cat }}</li>
  </ul>
</div>
```
And there we go a list of cats. We can do this with objects, and everything that is iterable.
#### Functions
So now we want to do functions on Vue. So now we stick with the example of the list of cats and want to add one more. So we add and input and a button to the html:
```html
<div id="root">
  <input v-model="newCat">
  <button> + ADD</button>
  <ul>
    <li v-for="cat in cats">{{ cat }}</li>
  </ul>
</div>
```
So now we want to add the cat typed on the list of cats. To do this we want to create a function and bind it to the button tag. The directive use to do this is v-on. The form of it is: 'v-on:event="funName"'. On this case:
```html
<div id="root">
  <input v-model="newCat">
  <button v-on:click="addKitty"> + ADD</button>
  <ul>
    <li v-for="cat in cats">{{ cat }}</li>
  </ul>
</div>
```
Now to make the Vue object execute the function, we add a new attribute called methods that is a object of functions with 'name: definition' form. We can access any data variable on this attribute. On the example will be modified like:
```js
app = new Vue({
  el: '#root',
  data: {
    cats: [
      'kitkat',
      'fish',
      'henry',
      'bosco',
      'melanthios'
    ],
    newCat: ''
  },
  methods: {
    addKitty: function(){
      return this.cats.push(this.newCat);
    }
  }
});
```
A shortcut to the v-on is the '@', like on this example another way to write it is:
```html
<div id="root">
  <input v-model="newCat">
  <button @click="addKitty"> + ADD</button>
  <ul>
    <li v-for="cat in cats">{{ cat }}</li>
  </ul>
</div>
```
#### Filters
So we want to change the display of the DOM but no the data on the Vue object by a pipe, to add format to the displayed data. To do this, we have something called filters that make this functions pipes.

For example, now every cat will be on capital letter:

On the html we add:
```html
    <li v-for="cat in cats">{{ cat | capitalize }}</li>
```
The order of execution will be from left to right. And on the Javascript we add:
```js
app = new Vue({
  el: '#root',
  data: {
    cats: [
      'kitkat',
      'fish',
      'henry',
      'bosco',
      'melanthios'
    ],
    newCat: ''
  },
  methods: {
    addKitty: function(){
      return this.cats.push(this.newCat);
    }
  },
  filters: {
    capitalize: function(value){
      return value.toUpperCase();
    }
  }
});
```

#### Components
So we want to create a custom component on the page. To do this, we add to the Vue object but not inside of it, but outside. For example the list of cats can be used like a component:
```js
Vue.component('cat-list',{
  template:
  <ul>
    <li> cat </li>
  </ul>
});
app = new Vue({
  el: '#root',
  component: [
    'cat-list'
  ],
  data: {
    cats: [
      'kitkat',
      'fish',
      'henry',
      'bosco',
      'melanthios'
    ],
    newCat: ''
  },
  methods: {
    addKitty: function(){
      return this.cats.push(this.newCat);
    }
  },
  filters: {
    capitalize: function(value){
      return value.toUpperCase();
    }
  }
});
```
We have to make sure to added to the Vue, like tell it that it has a component available. Now to use it on the html we do:
```html
<cat-list />
```
And there will be our list with cat. But we may want to pass some variables, to do this we pass on a field called props, that is an array of variables names which the Vue object have.
On this example will be on the list of cats:
```js
Vue.component('cat-list',{
  props: ['cats'],
  template:
  <ul>
    <li v-for="cat in cats" > {{ cat }} </li>
  </ul>
});
```
Now the props are variable that the list can receive when added to the html, so to add the cats list to it we do on the html:
```html
<cat-list :cats="cats" />
```
And now the props receive will be the cats array on the vue. Notice that the ':' will add variables from the vue object, but without it will be a string.

#### Vue life
The idea to have components is the reusable code that they provide because they follow a modular architecture. But they have a creation, presentation, then updates and destroy. So to handle this events, we have four fields which are functions on the Vue object that are called
```js
app = new Vue({
  created: function(){
    //instructions to do when created
  },
  mounted: function(){
    //instructions to do when mounted
  },
  updated: function(){
    //instructions to do when the view is updated
  },
  destroyed: function(){
    //instructions to do when destroyed
  }
});
```

So what is destroy? We can destroy the vue object by calling it by it's name and then calling a method to destroy it, which means that it's transformed to static html all the content that it's been attached to it. To destroy one we do:
```js
app.$destroy();
```
## Vue Cli
So we can create a vue app with the Vue cli development, to install it we use the Installation above.

Now to create a new Vue app we do on a folder of a project:
```bash
vue create <app_name>
```

So let's create a quiz for example:
```bash
vue create quiz
```
The output of this should be a set of settings of vue, we can create our own but let's start with the default
```bash
? please pick a preset:
> default (babel, eslint)
  Manually select features
```
This will install the dependencies and create a folder called quiz with the things to do the app inside and the commands to start running it:
```bash
cd quiz
npm run serve
```

So let open the app and let's the view the code source. So there is a lot of things, but the src directory and there is a file called 'main.js' which is here where the Vue object is rendered to the page. The html file which is attached by default is on the public directory called index.html.

## Looking through the code
So if we go to the src folder, there we will find a main.js file. On this we will find the following setup code, which is mainly the same as we watched before, mounting the Vue instance to a html element.
```js
import Vue from 'vue'
import App from './App.vue'
Vue.config.productionTip = false;

new Vue({
  render: h => h(App),
}).$mount('#app');
```
The html that is rendering is at the public directory index.html. Vue auto inyects your script to the html, it create a bundle of all the src files and then it will rendered into the html with no effort. On the package.json file of your application, on the script part is all the things that vue is using to render our app.

So first, vue is importing the App.vue on the src directory. This puts a template tag, a script tag and a style app. This works for every page like this:

For every page we create a *.vue file. This has the html on the template tags of the file, the javascript that is going to interact with that html and the css style of it. So we can define separate components and then join them on the main.js to be rendered to the page.

# Let's build a project
So let's build a a project that is a quiz one. (start at the 40:00 of the video). So to do it first we will be deleting the file on the HelloVue.vue on the component folder, and we will create two components, one named **Header.vue** and the other one **QuestionBox.vue**, the question box will display the question box and the submit button.

So one the question box we **NEED** a template tag of the html. So lets start putting some dummy tags on it:
```html
<!--On the QuestionBox.vue-->
<template>
  <h1>Question Box</h1>
</template>
```
```html
<template>
  <h1>Header</h1>
</template>
```
So now the App.vue keeps importin the HelloWorld vue component. Now we have to change it to:
```html
<script>
import Header from './components/Header.vue'
import QuestionBox from './components/QuestionBox.vue'
</script>
```
And now on the same file we need to export them in the components:
```html
<script>
//...
export default {
  name: 'app',
  components: {
    Header,
    QuestionBox
  }
}
</script>
```
So on the template tag of the App.vue we have to write now:
```html
<template>
  <div id='app'>
    <Header />
    <QuestionBox />
  </div>
</template>
```
We will do now a bootstrap vue on the app, so we will have it install it as a third party component.

So on our main.js we do:
```js
//...
import BootstrapVue from 'bootstrap-vue' //js bootstrap
//Now the css bootstrap
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'
//...
Vue.use(BootstrapVue)
//...
```
Now on the header let's add a nav bar of bootstrap:
```html
<template>
  <div>
    <b-nav tabs>
    <b-nav-item disable> <b>Fancy Quiz App </b> </b-nav-item>
    <b-nav-item disable>Counter: 4/10</b-nav-item>
    </b-nav>
  </div>
</template>
```

For the Question Box we will use the Jumbotron:
```html
<template>
<div class="question-box-container">
  <b-jumbotron header="BootstrapVue" lead="Bootstrap 4 Components for Vue.js 2">

    <template slot="lead">
      Some Questions
    </template>

    <hr class="my-4">

    <p>
      List of Answers
    </p>

    <b-button variant="primary" href="#">Submit</b-button>
    <b-button variant="success" href="#">Next</b-button>
  </b-jumbotron>
</div>
</template>
```
There will be all on the project folder.