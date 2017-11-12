window.onload = function(){
	var button = document.getElementById('summon');
	button.addEventListener('click', function(){
		//console.log('Summon!');
		var img = new Image();
		img.src = 'https://placekitten.com/g/200/200/';
		document.getElementById('kittens').appendChild(img);
	});
};