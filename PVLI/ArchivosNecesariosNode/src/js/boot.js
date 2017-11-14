var bootState = {
	create: function(){
		//en este estado damos inicio a las fisicas de tipo ARCADE yey
		game.physics.startSystem(Phaser.Physics.ARCADE);

		//llamamos al siguiente estado -> cargar recursos
		game.state.start('load');
	}
};