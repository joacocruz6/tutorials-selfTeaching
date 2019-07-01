// Objectives:
// 1. Set up the basic React code from scratch
// 2. Create a functional component called MyInfo that returns the following UI:
     // a. An h1 with your name
     // b. A paragraph with a little blurb about yourself
     // c. An ordered or unordered list of the top 3 vacation spots you'd like to visit
// 3. Render an instance of that functional component to the browser

import React from 'react';
import ReactDOM from 'react-dom';

function MyInfo(){
     return (
          <div>
          <h1> Joaquin Cruz </h1>
          <p> I'm a bachelors degree persuer of Computer Science, I do this github page for fun </p>
          <ol>
               <li> London </li>
               <li> Berlin </li>
               <li> Barcelona </li>
          </ol>
          </div>
     );
}

ReactDOM.render(<MyInfo />, document.querySelector("#root"));
