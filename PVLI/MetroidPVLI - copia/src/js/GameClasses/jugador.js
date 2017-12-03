class Player extends GameSprite{
	constructor(posX, posY, sprite, gravity){
		super(posX, posY, sprite, gravity);

		this._player = this._sprite; //asignacion con el sprite del padre para que el nombre sea mas legible
		game.camera.follow(this._player);
		this._aim = 'left';
		this.define_Keys();
		this._basicBullets = new Bullets('bala', 300, 300, this); //balas añadidas en una clase, que hereda de la clase GroupFather
		this._player.animations.add('normal', [0], 10, true);
		this._player.animations.add('bolita', [1], 10, true);
		this._width = this._player.body.width;
		this._height = this._player.body.height;
		this._potenciadores = new Potenciadores(this);
		this._animacion = 'normal';
		this._jumpTimer = 0;
	}

	mueveIzquierda(){
		this._aim = 'left';
		this._player.body.velocity.x = -150;
	}

	mueveDerecha(){
		this._player.body.velocity.x = 150;
		this._aim = 'right';
	}

	apuntaArriba(){
		this._aim = 'up';
	}	

	update(){ //update del jugador, se reinicia la velocidad, la gravedad y comprueba si choca o no con el suelo, los eventos de teclado
		this.reset();
		this.handle_Events();
		this.Anima();
		this._puedeTrans = true; //si no esta en los overlaps que no le dejan transformarse, se pone a true y le dejan transformarse
		/*if(this._player.body.touching.down){
			this._contSaltos = 0;
		}*/
	}

	morir(){
		this._player.kill(); //destruye el objeto Jugador
	}

	//Aquí hacemos el saltito (por tiempo presionando la tecla)
	saltar(){

		if(this.WKey.isDown && this._player.body.velocity.y === 0 && !this._bola){
			this._jumpTimer = game.time.now + 600;
			this._player.body.velocity.y = -150;
		}
		else if(this.WKey.isDown && this._jumpTimer != 0){
			if(game.time.now > this._jumpTimer){
					this._jumpTimer = 0;
				}
				else{
					this._player.body.velocity.y = -150;
				}
		}
		else{
			this._jumpTimer = 0;
		}
		/*if(this._player.body.velocity.y === 0 && !this._bola){
			this._player.body.velocity.y = -200;
			//this._contSaltos++;
		}*/
	}

	handle_Events(){
		//If del movimiento...
		if(this.AKey.isDown){ //si presiona izquierda
			this.mueveIzquierda();
		}
		else if(this.DKey.isDown){ //si presiona derecha
			this.mueveDerecha();
		}
		else if(this.cursores.up.isDown){
			this.apuntaArriba();
			if(this.normal != undefined){
				this.normal();
			}
		}
		else if(this.cursores.down.isDown && this.transformarse != undefined){
			this.transformarse();
		}

		this.saltar();

		if(this.JKey.isDown && !this._bola){
			this._basicBullets.shoot(this._aim);
		}
	}

	reset(){
		this._player.body.velocity.x = 0;  //reiniciamos variables...
	}

	Anima(){
		this._player.animations.play(this._animacion);
	}

	define_Keys(){
		this.cursores = game.input.keyboard.createCursorKeys(); //"listener" de eventos de teclado, declarando la variable cursores
		this.JKey = game.input.keyboard.addKey(Phaser.Keyboard.J); //definimos la J
		this.WKey = game.input.keyboard.addKey(Phaser.Keyboard.W); //definimos la W
		this.AKey = game.input.keyboard.addKey(Phaser.Keyboard.A); //definimos la A
		this.SKey = game.input.keyboard.addKey(Phaser.Keyboard.S); //definimos la S
		this.DKey = game.input.keyboard.addKey(Phaser.Keyboard.D); //definimos la D
	}

	agregarBola(i, bool){
		this._potenciadores.agregarBola();
	}

	//Unos gets simples para saber las coordenadas del jugador y para devolvernos al propio jugador
	get x(){
		return this._player.x;
	}
	get y(){
		return this._player.y;
	}
	get width(){
		return this._width;
	}
	get height(){
		return this._height;
	}
	get player(){
		return this._player;
	}
}
