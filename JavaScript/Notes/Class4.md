# Adding JS in our HTML

First we will create a front page, with the name index.html
With these, we create a simple html file:
```HTML
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>

  </body>
</html>
```
All shorcuts are some word and then press tab, for example, html+TAB make all the previous
code.
## Including JS
To include JavaScript we create script tab. We can put it anywhere but there is some differences.
If there is no defined tag when we put the JavaScript code, then it will bring us an error.
So for good practice, all JavaScript will be put on the end of the document

The browser reads the HTML code, line by line, so if there is some code references something below, it will
no do anything. So every time a JavaScript changes some content, the content will need to be above the code.

In summary:
- If we need the JavaScript to loaded before the HTML content, you put it in the head tags
- If we need to be loaded after the HTML content, we put it after the body tag.

Also we can make JavaScript separate from the HTML page, in this case we call it "example.js" to that file.
To included on my HTML, we do:
```HTML
<script src="example.js">

</script>
```
On the src part, we put the relative route of the JavaScript script.
