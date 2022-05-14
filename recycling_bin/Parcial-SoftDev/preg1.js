
function reloj(){
	var tiempo = new Date();
	var horas = tiempo.getHours();
  if (horas>12) {horas= horas- "12"} ;
  var minutos = tiempo.getMinutes();
  var segundos = tiempo.getSeconds();
  minutos = checkTime(minutos);
  segundos = checkTime(segundos);
  document.getElementById('reloj').innerHTML = horas + ":" + minutos + ":" + segundos;
  var r = parseInt(segundos) * 1;
  var g = parseInt(segundos) * 3;
  var b = parseInt(segundos) * 5;

  document.body.style.backgroundColor = 'rgb(' + r + ',' + g + ',' + b + ')';
  document.getElementById('colorHex').innerHTML = '#'+r.toString()+g.toString()+b.toString();
  var t = setTimeout(reloj, 500);
}

function checkTime(i) {
	if (i < 10) {i = "0" + i};
	return i;
}

reloj();