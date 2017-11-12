class Jugador{
	constructor(){
		this._jugador;
		this._contSaltos = 0;
		this._balas;
		this._tiempoBala = 0;	
	}
	creaCosas(){
		this._jugador = game.add.sprite(32, game.world.height - 250, 'dude'); //iniciamos todo lo del jugador
		game.physics.arcade.enable(this._jugador);
		this._jugador.body.bounce.y = 0,2;
		this._jugador.body.gravity.y = 250; //fisicas varias
		this._jugador.body.collideWorldBounds = true;
		this._jugador.scale.setTo(0.25,0.25); //escalamos

		//Balas
		this._balas = game.add.group();//hace el grupo de balas y le activa a todo el grupo sus físicas
		this._balas.enableBody = true;
		this._balas.createMultiple(20, 'estrellita'); //creamos 5 balas, y luego las reutilizamos tooodo el rato
		this._balas.setAll('outOfBoundsKill', true); //hacemos que desaparezcan al chocar con los limites
		this._balas.setAll('checkWorldBounds', true);//comprueba que no se ha chocado con nada
	}

	mueveIzquierda(){
		this._jugador.body.velocity.x = -150; 
	}

	mueveDerecha(){
		this._jugador.body.velocity.x = 150;
	}

	update(plataformas){ //update del jugador, se reinicia la velocidad, la gravedad y comprueba si choca
						//o no con el suelo
		game.physics.arcade.collide(this._jugador, plataformas);
		this._jugador.body.velocity.x = 0;
		this._jugador.body.gravity.y = 250;
		if(this._jugador.body.touching.down){  
			this._contSaltos = 0;
		}
	}

	morir(){
		this._jugador.kill(); //destruye el objeto Jugador
	}

	//Aquí hacemos el saltito
	saltar(){
		if(this._contSaltos < 2){
			this._jugador.body.velocity.y = -250;
			this._contSaltos++;
		}
	}

	disparo(){
	if(game.time.now > this._tiempoBala){
		var bal = this._balas.getFirstExists(false); //cogemos la primera bala
		bal.reset(this._jugador.x + 30, this._jugador.y + 30); //le marcamos su posicion inicial
		bal.body.velocity.x = 300;
		this._tiempoBala = game.time.now + 1000; //temporizador para que no dispare chorrocientas balas de golpe
	}
}

	//Unos gets simples para saber las coordenadas del jugador y para devolvernos al propio jugador
	get x(){
		return this._jugador.x;
	}
	get y(){
		return this._jugador.y;
	}
	get jugador(){
		return this._jugador;
	}
}
