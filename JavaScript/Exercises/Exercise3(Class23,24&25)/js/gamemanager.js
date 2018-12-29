let GameManager={
  setGameStart: function(classType){
    this.resetPlayer(classType);
    this.setPreFight(classType);
  },
  resetPlayer: function(classType){
    switch (classType) {
      case "Warrior":
        player = new Player(classType,200,0,200,100,50);
        break;
      case "Rogue":
        player = new Player(classType,100,0,100,100,200);
        break;
      case "Mage":
        player = new Player(classType,80,0,50,200,50);
        break;
      case "Hunter":
        player = new Player(classType,200,0,50,200,100);
        break;
      default:
        alert("Error on choosing fields!");
    }
    let getInterface = document.querySelector(".interface");
    let image='<img src="img/player/'+classType.toLowerCase()+'.jpeg" class="img-avatar">';
    let choosenClass='<div><h3>'+classType+'</h3>';
    let health='<p class="health-player">Health: '+player.health+'</p>';
    let mana= '<p>Mana: '+player.mana+'</p>';
    let strength='<p>Strength: '+player.strength+'</p>';
    let agility='<p> Agility: '+player.agility+'</p>';
    let speed= '<p> Speed: '+player.speed+'</p></div>';
    getInterface.innerHTML= image+choosenClass+health+mana+strength+agility+speed;
  },
  setPreFight: function(classType){
    let getHeader = document.querySelector(".header");
    let getActions = document.querySelector(".actions");
    let getArena = document.querySelector(".arena");
    getHeader.innerHTML = '<p> Task: Find an enemy! </p>';
    getActions.innerHTML = '<a href="#" class = "btn-prefight" onclick="GameManager.setFight()">Search for enemy!</a>';
    getArena.style.visibility = "visible";
  },
  setFight: function(){
    let getHeader = document.querySelector(".header");
    let getActions = document.querySelector(".actions");
    let getEnemy = document.querySelector(".enemy");
    //create enemy!
    let enemy00 = new Enemy("Goblin",100,0,50,100,100);
    let enemy01 = new Enemy("Troll",200,0,150,80,150);
    let chooseRandomEnemy = Math.floor(Math.random() * Math.floor(2));
    switch (chooseRandomEnemy) {
      case 0:
        enemy=enemy00;
        break;
      case 1:
        enemy=enemy01;
        break;
      default:
        alert("Something went wrong creating an enemy, try again!");
    }
    getHeader.innerHTML = '<p>Task: Choose your move!</p>';
    getActions.innerHTML = '<a href="#" class = "btn-prefight" onclick="PlayerMoves.calcAttack()">Attack!</a>';
    let enemyImg = '<img src="img/enemies/'+enemy.enemyType.toLowerCase()+'.jpeg" class="img-avatar">';
    let type='<div><h3>'+enemy.enemyType+'</h3>';
    let health='<p class="health-enemy">Health: '+enemy.health+'</p>';
    let mana= '<p>Mana: '+enemy.mana+'</p>';
    let strength='<p>Strength: '+enemy.strength+'</p>';
    let agility='<p> Agility: '+enemy.agility+'</p>';
    let speed= '<p> Speed: '+enemy.speed+'</p></div>';
    getEnemy.innerHTML=enemyImg+type+health+mana+strength+agility+speed;
  }
};
console.log(GameManager);
