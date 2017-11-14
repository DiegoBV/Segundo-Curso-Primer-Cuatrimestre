var playState = {

	//IMPORTANTE: Siempre que declares una variable en estas funciones y la uses, siempre poner el THIS.
	create: function(){
		this.cursores = game.input.keyboard.createCursorKeys(); //"listener" de eventos de teclado, declarando la variable cursores
		game.add.sprite(0,0,'sky'); //establecemos el fondo

		this.jugador = new Jugador(); //una clase o_O
		this.jugador.creaCosas();

		//Definimos un grupo de plataformas, esto es importante, al definir el grupo
		//podemos tratar a todas las plataformas como una sola, en vez de ir una por una
		this.plataformas = game.add.group();
		//activamos las fisicas para dicho grupo
		this.plataformas.enableBody = true;

		//Creamos el "suelo"
		this.suelo = this.plataformas.create(0, game.world.height - 64, 'ground'); //en el 0, altura -64, con el sprite ground
		//escalamos el sprite para que concuerde con el juego
		this.suelo.scale.setTo(2,2);

		//esto hace que si lo pisas no se mueva, ya que como le afectan las físicas...
		this.suelo.body.immovable = true;

		//Creamos dos plataformas en el aire (tuto de phaser dice eso)
		this.ledge = this.plataformas.create(400,400, 'ground'); //las creamos a partir del grupo plataformas
		this.ledge.body.immovable = true;
		this.ledge2 = this.plataformas.create(-150,250,'ground');
		this.ledge2.body.immovable = true;
	
		//Manos que te darán puntos
		this.hands = game.add.group();
		this.hands.enableBody = true;

		for(var i = 0; i < 12; i++){ //creamos 12 manos

			//Añadimos una mano al grupo Hands
			var mano = this.hands.create(i*70, 0 ,'star');
			//Fisicas...
			mano.body.gravity.y = 100;
			mano.body.bounce.y = 0.4 + Math.random() *0.2;
			mano.scale.setTo(0.05,0.05);
		}

		//Añadimos un texto, igualándolo al scoretext, en las coordenadas (16,16) con el texto por defecto "score: 0"
		//y le decimnos que tenga un tamaño de 32 px y el color.Ademas creamos la variable score y la inicializamos a 0
		this.score = 0;
		this.scoreText = game.add.text(16,16, 'score: 0', {fontSize: '32px', fill: '#FFF'});
		this.scoreMax = 120; //variable scoreMax para saber si hemos acabado

		this.spikes = game.add.group(); //pinchitos

		this.spikes.enableBody = true;

		for(var i = 1; i < 4; i++){
			var spike = this.spikes.create(i*200 + 70, game.world.height - 500 ,'spike');
			spike.body.gravity.y = 10000;
			spike.scale.setTo(0.25,0.25);
		}

		this.cursores.up.onDown.add(this.jugador.saltar,this.jugador); //le añadimos a la tecla UP la funcion saltar
		this.JKey = game.input.keyboard.addKey(Phaser.Keyboard.J); //definimos la J
		this.JKey.onDown.add(this.jugador.disparo, this.jugador); //le añadimos la funcion "disparo" de la clase jugador
	},

	update: function(){

			//le decimos a las manos y a los pinchos que colisionen con las plataformas
			game.physics.arcade.collide(this.hands, this.plataformas);
			game.physics.arcade.collide(this.spikes, this.plataformas);
			//igual al jugador pero con un metodo de clase
			this.jugador.update(this.plataformas);

			//If del movimiento...
			if(this.cursores.left.isDown){ //si presiona izquierda
				this.jugador.mueveIzquierda();
			}
			else if(this.cursores.right.isDown){ //si presiona derecha
				this.jugador.mueveDerecha();
			}

			//Vamos a comprobar si el jugador hace "overlap" con una mano y llamamos a la funcion collectStar
			game.physics.arcade.overlap(this.jugador.jugador,this.hands, this.collectStar, null, this); //no se que es ni el null ni el this ese
			//lo mismo pero para los pinchos
			game.physics.arcade.overlap(this.jugador.jugador,this.spikes, this.muerte, null, this);

			if(this.score === this.scoreMax){
				game.state.start('win');
			}

		},

	collectStar: function(jugador, hands){
		hands.kill(); //destruye el objeto star
		//Añade y updatea el texto
		this.score += 10;
		this.scoreText.text = 'Score: ' + this.score;
	},
	
	muerte: function(){
	this.jugador.morir();
	this.scoreText.text = 'Moriste wey';
	game.state.start('fail');
	}
}