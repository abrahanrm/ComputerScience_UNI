var express = require('express');
var app = express();
var port = 5555;

app.get('/', (req, res) => {
    
    var randomNumber=Math.random().toString();
    randomNumber=randomNumber.substring(2,randomNumber.length);
    console.log('randomnumber=',randomNumber);
    res.cookie('cookieName',randomNumber, { maxAge: 900000, httpOnly: true })
    res.send('Se ha creado las cookies exitosamente!!!');
    console.log('Se han creado las cookies exitosamente!!');
}) 

app.listen(port, () => {
    console.log(`Aplicacion de Ejemplo escuchando en  http://localhost:${port}`)
  })
