var loadState = {
	//preload es una funcion de phaser que se llama una sola vez y se suele usar para cargar los recursos
	preload: function(){
		
		var loading = game.add.text(80,150,'loading...',{font: '40px Courier', fill: '#FFF'}); //una textito de carga

		game.load.image('dude', 'assets/personaje.png');
		game.load.image('sky', 'assets/cueva.jpg');
		game.load.image('ground', 'assets/platform.png');       //Cargamos tooodos los recursos que vamos a necesitar
    	game.load.image('star', 'assets/hand.png');
    	game.load.image('spike', 'assets/spikes.png');
    	game.load.image('estrellita', 'assets/star.png'); 
    	console.log("Cargando..."); //simple debug
	},

	create: function(){

		//Llamamos al siguiente estado --> menu
		game.state.start('menu');
	}
};

