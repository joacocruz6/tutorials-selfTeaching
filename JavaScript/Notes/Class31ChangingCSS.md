# Changing CSS of an Element
When we change CSS with JavaScript we do it to a single element and we not change the style shit of our website, just the style attribute of our element that we grab.

Now let's have the next example to show how we do it.

#### Example
We have the next HTML (same as class 30):
```HTML
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <div class="box">
      <h1>This is a Title!</h1>
    </div>
  </body>
</html>
```
We want to change the CSS of the h1 element that says this is a title.
So first we do in JavaScript:

```JavaScript
document.querySelector("h1").style.color = "green";
```
And there we go, the color have changed! Now the the dash css we have to do uppercase, for example to the font-size in css in JavaScript is fontSize propertie.
##### Changing multiple CSS at once
To change multiple styles at once we use the cssText attribute and with a string we write like in css style. For example:
```JavaScript
document.querySelector("h1").style.cssText = "color: red; font-size: 40px;";
```

###### With set attribute
We can use set attribute to change CSS:
```JavaScript
document.querySelector("h1").setAttribute("style","color: red; font-size: 40px;");
```
and the effect from before !.
