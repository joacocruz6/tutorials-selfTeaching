#Fetch API on JavaScript
So we know on JavaScript that we can make asynchronous calls to the server via JQuery and the AJAX. Well this is another more actual way to do it by the fetch API provided on the recent years. This is not fully compatible, it's not that realiable but it's also the one that will be the next standard.
So we will be doing a sandbox, a place holde of data, this means getting and sending data in a asynchronous way.

##The fetch function
The fetch API is based on a function called fetch. This receives two parameters, the first and main one is the url where the data will be retrieved asynchronously and the second one....

This fetch function returns a Promise, so for example to retrieve the simple data of the sample.txt file and then do something with the data we write:
```js
fetch('sample.txt')
.then(function(response){
    console.log(response);
});
```
## Getting the text or the json
So to get the text of the file (on in some cases the json data) we call the text method of the response, but this give us headers of the promise:
```js
fetch('sample.txt')
.then(function(response){
    console.log(response.text());
});
```
If we want the actual text of the promise, we can return the promise header text. If we return it, this is a promise header so we need to have another callback function of then. This then function can manipulate the actual data of the text or json file given by the parameters.

```js
fetch('sample.txt')
.then(function(response){
    return response.text();
})
.then(function(data){
    console.log(data);
});
```
Now we show the data on the sample.txt, to put it on the html we create a div element with and id of output (for example), and then we do:
```js
fetch('sample.txt')
.then(function(response){
    return response.text();
})
.then(function(data){
    document.querySelector("#output").innerHTML = data;
});
```
### With JSON
So now we will do the same but with a json. To manipulate the json we do basically the same as we did before but with some little changes. This are the data manipulation and the response returning value of the recall.

So we do mainly the same thing as before:
```js
fetch('users.json')
.then((response)=>response.json())
.then((data) => console.log(data));
```
To manipulate the json data we can loop through it, for example greating:
```js
fetch('users.json')
.then((response)=>response.json())
.then((data) => {
    let output = '<h2> Users </h2>';
    data.forEach((user)=>{
        output += `
        <ul>
            <li>ID ${user.id}</li>
            <li>ID ${user.name}</li>
            <li>ID ${user.email}</li>
        </ul>
        `;
    });
    document.getElementById('output').innerHTML = output;
});
```
## Fetching from a external API
So we want now to grab external data of our aplication. To do this we can also do fetch as the same way we did before but with the next url:
```js
function getPosts(){
            fetch('https://jsonplaceholder.typicode.com/posts')
            .then((res) => res.json())
            .then((data)=>{
                let output = "<h2> Posts </h2>";
                data.forEach((post)=>{
                    output+=`
                        <div>
                            <h3>${post.title}</h3>
                            <p>${post.body}</p>
                        </div>
                    `;
                });
                document.getElementById('output').innerHTML = output;
            });
}
```

## Publishing data with fetch
So we can do form submissions with fetch. To do this we will use the second parameter of the fetch function which an object with the headers and the data send.
For this we do a form and a function called add posts:
```js
function addPost(e){ //because it's associated with a form we pass an event parameter
    e.preventDefault();
    let title = document.getElementById('title').value;
    let body = documnet.getElementById('body').value;
    fetch('https://jsonplaceholder.typicode.com/posts',{
        method: 'POST', //method of the form
        headers: { //headers of the submition
            'Accept': 'application/json, text/plain, */*',
            'Content-type': 'application/json'
        },
        body: JSON.stringify({title:title,body:body}) // the data of the form
    })
    .then((res) => res.json())
    .then((data)=> console.log(data));

}
```
That it is!.
