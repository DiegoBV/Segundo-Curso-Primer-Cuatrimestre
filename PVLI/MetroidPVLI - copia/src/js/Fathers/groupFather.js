class GroupFather{
	constructor(){
		this._group = game.add.group();
		this._group.enableBody = true;
	}
	
	get group(){
		return this._group;
	}
}