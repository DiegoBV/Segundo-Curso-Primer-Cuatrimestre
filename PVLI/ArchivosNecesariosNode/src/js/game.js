var game = new Phaser.Game(800, 600, Phaser.AUTO, 'gameDiv'); //Creamos el Juego

//Añadimos los estados

game.state.add('boot', bootState);
game.state.add('load', loadState);
game.state.add('menu', menuState);
game.state.add('play', playState);
game.state.add('win', winState);
game.state.add('fail', failState);

//Tras haber añadido todos los estados correspondientes, iniciamos el primer estado
game.state.start('boot');