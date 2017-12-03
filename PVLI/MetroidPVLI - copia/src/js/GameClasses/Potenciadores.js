class Potenciadores{ //clase en la que agregaremos todas las funciones necesarias al player para poder hacer nuevas acciones
	constructor(player){
		this._player = player;
		console.log(this._player);
		var self = this;
	}

	agregarBola(){ //agrega todas las funciones necesarias para que el jugador se transforme en bola
		this._player.bolita = function(){
			this._bola = true;
			this._player.body.setSize(this._width, this._height/2 - 7); //cambia los colliders
			this._animacion = 'bolita';
		}

		this._player.transformarse = function(){
			if(this._player.body.velocity.y === 0){
				this.bolita();
			}
		}

		this._player.normal = function(){ //vuelve a la normalidad
			if(this._bola && this._puedeTrans){
				this._bola = false;
				this._player.body.setSize(this._width, this._height);
				this._player.body.y = this._player.y - 34.25; //este numero hay que cambiarlo pero no se llegar a él... (es AlturaDeAntes - AlturaEnBola)
				this._animacion = 'normal';
			}
		}

		this._player.no_PuedeTransformarse = function(){
			this._puedeTrans = false;
		}
	}
}
