var menuState = {

	create: function(){
		//Vamos a hacer un menú muy sencillito, donde ponga el menu de juego y 
		//solo tengas que darle a una tecla para continuar
		//establecemos las coordenadas (80,80), el texto que queremos que ponga,
		//la fuente, el tamaño y el color
		var titulo = game.add.text(80,80, 'Al fin sabemos Phaser', {font: '50px Arial', fill: '#FFF'});
		//Lo mismo que arriba, esta vez la "y" se pilla de la altura del juego
		var texto = game.add.text(80, game.world.height - 80, 'Press "Space" to start', {font: '25px Arial', fill: '#FFF'});

		//Aqui definiremos la tecla espacio para poder hacer cositas con ella
		var spaceKey = game.input.keyboard.addKey(Phaser.Keyboard.SPACEBAR);

		//Cuando alguien presione el espacio, llamaremos a la funcion "start"
		spaceKey.onDown.addOnce(this.start, this); //se añade una vez esa funcion, en este estado
	},

	start: function(){
		//llamamos al siguiente estado --> Play
		game.state.start('play');
	},
};