'use strict';

//TODO 1.1 Require de las escenas, play_scene, gameover_scene y menu_scene.
var Play_Scene = require('./play_scene.js');
var Game_Over = require('./gameover_scene.js');
var Menu_Scene = require('./menu_scene.js');

//  The Google WebFont Loader will look for this object, so create it before loading the script.




var BootScene = {
  preload: function () {
    // load here assets required for the loading screen
    this.game.load.image('preloader_bar', 'images/preloader_bar.png');
    this.game.load.spritesheet('button', 'images/buttons.png', 168, 70);
    this.game.load.image('logo', 'images/phaser.png');
  },

  create: function () {
    //this.game.state.start('preloader');
      this.game.state.start('menu');
  }
};


var PreloaderScene = {
  preload: function () {
    this.loadingBar = this.game.add.sprite(100,300, 'preloader_bar');
    this.loadingBar.anchor.setTo(0, 0.5); 
    this.game.load.setPreloadSprite(this.loadingBar);
    this.game.stage.backgroundColor = "#000000";
    
    
    
    this.load.onLoadStart.add(this.loadStart, this);
    //TODO 2.1 Cargar el tilemap images/map.json con el nombre de la cache 'tilemap'.
      //la imagen 'images/simples_pimples.png' con el nombre de la cache 'tiles' y
      // el atlasJSONHash con 'images/rush_spritesheet.png' como imagen y 'images/rush_spritesheet.json'
      //como descriptor de la animación.
      this.game.load.image('tiles','images/simples_pimples.png');
      this.game.load.image('tilemap', 'images/map.json');
      this.game.load.image('atlasJSONHash', 'images/rush_spritesheet.png');
      this.game.load.image('spritesheet', 'images/rush_spritesheet.json');

      

      //TODO 2.2a Escuchar el evento onLoadComplete con el método loadComplete que el state 'play'
      if(onLoadComplete()){
      	this.game.state.start('play');
      }

  },

  loadStart: function () {
    //this.game.state.start('play');
    console.log("Game Assets Loading ...");
  },
    
    
     //TODO 2.2b function loadComplete()
 onLoadComplete: function() {
  		this.ready = true;
},
    
    update: function(){
        this._loadingBar
    }
};


var wfconfig = {
 
    active: function() { 
        console.log("font loaded");
        init();
    },
 
    google: {
        families: ['Sniglet']
    }
 
};
 
//TODO 3.2 Cargar Google font cuando la página esté cargada con wfconfig.
//TODO 3.3 La creación del juego y la asignación de los states se hará en el método init().

window.onload = function () {
  var game = new Phaser.Game(800, 600, Phaser.AUTO, 'game');

//TODO 1.2 Añadir los states 'boot' BootScene, 'menu' MenuScene, 'preloader' PreloaderScene, 'play' PlayScene, 'gameOver' GameOver.
game.state.add('boot',BootScene);
game.state.add('menu',MenuScene);
game.state.add('preloader',PreloaderScene);
game.state.add('play',PlayScene);
game.state.add('gameOver',GameOver);

//TODO 1.3 iniciar el state 'boot'. 
this.game.start('BootScene');

    
};
