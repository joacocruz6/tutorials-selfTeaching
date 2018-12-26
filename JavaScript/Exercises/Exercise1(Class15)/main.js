function calc(){
  var value1=parseInt(document.getElementById("val1").value); // also works querySelector(/*especific element by class or id #id or .class*/)
  var value2=parseInt(document.getElementById("val2").value);
  var operator=document.getElementById("operator").value;
  var calculate;
  if(operator == "add"){
    calculate=value1+value2;
  }
  else if(operator == "subs"){
    calculate=value1-value2;
  }
  else if(operator == "mult"){
    calculate=value1*value2;
  }
  else if(operator == "div"){
    calculate=value1/value2;
  }
  document.querySelector("#result").innerHTML=calculate
}
