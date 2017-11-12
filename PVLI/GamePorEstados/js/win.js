var winState ={

	preload: function(){
		
			var text  = game.add.text(80, 80, 'Congratulations!!', {font: '80px Arial', fill: '#123'});
			var textoTecla = game.add.text(80, game.world.height - 80, 'Press "Space" to continue', {font: '25px Arial', fill: '#FFF'});	
	},

	create: function(){
		var spaceKey = game.input.keyboard.addKey(Phaser.Keyboard.SPACEBAR);
		spaceKey.onDown.addOnce(this.continue, this);
	},

	continue: function(){

		game.state.start('menu');
	}

};
