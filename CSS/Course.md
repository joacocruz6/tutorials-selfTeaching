# CSS course
CSS is a styling "language" for making our HTML look good or better. The course is from freeCodeCamp so they have some exercises that I will be putting here along the course so you can check it!

## In-line Styling
So on our html we can add some styling within the tags. To do this we do:
```html
<h1 style="color: red;">Some text </h1>

```
And there we go!

## Blocks of style
So in HTML we can have blocks of CSS. To initiate it we need to do:
```html
<style>
    /*instructions*/
</style>
```
For example:
```html
<style>
h2{
    color: blue;
}
</style>
```
So now we have all the h2 tags with letters of the color blue.
## CSS classes
So now we need to style classes, to choose a class we add a ''.'' in front of the selector. In general:
```css
.myClass{
    /*styling*/
}
```
For example if some tags are with the class: cell.
So we do:
```css
.cell{
    color: blue;
}
```
And all the html elements that have that class will have the letters of the color blue now!.

## Styling multiple elemets with css classes
We can use classes to use the same css style to more than one element, like paragraphs and tables at the same time!

## Changing font sizes
Another property is font size, to change it we do:
```css
#anElement {
    font-size: 30px; /*Just an example, can be any pixels*/
}
```
Now the font size of the element with that id will be 30 pixels.

## Changing the font family
To change the font of an element, we use the font family propertie. 

For example, to make all the p tags with the monospace font:
```css
p {
    font-family: monospace;
}
```

To import fonts family we can browse it (a common page is google fonts) we can do it in many ways. One for example can be at the html doing it with a link tag like this:
```html
<link href="page to the font" rel="stylesheet" type="text/css">
```
Or doing on the css file:
```css
@import url(the url);
```


### Degrade of the fonts
If the specific font doesnt load, we can make a backup font by putting:
```css 
h2 {
    font-family: primary, secondary;
}
```
You want to get the last one a generic font to make sure that it loads succesfully.

## Sizing images
Css have a property called width that changes the scale of the images. For example:
```css
.larger-image {
    width: 500px;
}
```

## Adding borders to the elements
Css borders have the next properties:
- Style
- Color
- Width

To call it on the css we do border-propertieName. For example to make a thick green border to our h2 tags we do:
```css
h2 {
    border-color: green;
    border-width: 10px;
    border-style: solid;
}
```

## Adding round borders to images
So css have the propertie to make things round, like divs and images. To do so we add them the propertie border-radius with some metric.
For example:
```css
img {
    border-radius: 10px;
}
```
To generate a circle image we specify the border radius in porcentage (we can do this with all the metrics) like this:
```css 
img {
    border-radius: 50%;
}
```

## Giving background color to a div
So to set the background color of an element with the background-color propertie.

## Selectors
So 