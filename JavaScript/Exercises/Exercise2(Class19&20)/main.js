let toggleNavStatus=false; //the nav bar is not opened

let toggleNav = function(){
  //we want to manipulate the css of the page
  let getSidebar = document.querySelector(".nav-sidebar"); //id=#name and class = .name
  let getSidebarUl=document.querySelector(".nav-sidebar ul"); //querySelector selects equals of css but one element only
  let getSidebarTitle=document.querySelector(".nav-sidebar span");
  let getSidebarLinks=document.querySelectorAll(".nav-sidebar a"); //put all the selected one and put it on an array

  if (!toggleNavStatus) {
    getSidebarUl.style.visibility = "visible"; //style-> get the style css and visibility->get the visibility of the style
    getSidebar.style.width="272px"; //all the style changes are str
    getSidebarTitle.style.opacity="0.5";
    let arrayLength=getSidebarLinks.length;
    for(let i= 0; i<arrayLength;i++){
      getSidebarLinks[i].style.opacity = "1";
    }
    toggleNavStatus = true;
  }
  else{
    getSidebar.style.width = "50px";
    getSidebarTitle.style.opacity = "0";

    let arrayLength = getSidebarLinks.length;

    for(let i = 0; i<arrayLength; i++){
      getSidebarLinks[i].style.opacity = "0";
    }


    getSidebarUl.style.visibility = "hidden";
    toggleNavStatus = false;
  }
}
