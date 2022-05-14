var express = require('express')
var app = express()
var fs = require('fs');
const port = 3000


app.get('/', (req, res) => {
    res.send('Hello world 2! - desde el ej 2')
});

app.get('/object/:objid', (req, res) => {
    var dbfile = "./server/DB1.json";
    fs.readFile(dbfile, function(err, contents){
        if(err){
            res.status(500).send(err.message);
        } else{
            var obj=JSON.parse(contents); //JSON.parse acepta buffers
            obj.date=new Date();
            console.log(obj);
            res.set('Content-type', 'application/json');
            res.status(200).send(JSON.stringify(obj));
        }
    });
})

//puerto
app.listen(port, () => {
    console.log(`Aplicacion de Ejemplo escuchando en http://localhost:${port}`)
})