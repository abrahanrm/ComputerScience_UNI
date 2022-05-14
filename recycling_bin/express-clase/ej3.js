var express = require('express')
var app = express()
var fs = require('fs');
const port = 3000

app.use(express.json())

/*const users = [
    {
        'username': 'Faraday', 
        'email': 'cientifico1'
    },
    {
        'username': 'Fermi',
        'email': 'cientifico2'
    },    
    {
        'username': 'Plank',
        'email': 'cientifico3'
    }
]*/
const users = ['Faraday', 'Fermi', 'Plank'];

app.get('/usuario', (req, res) => {
    //var dir = "./data/"
    //res.send('Hello world 2! - desde el ej 2')
    res.json(users);
    //res.send(users.username)
});

app.get('/data', (req, res) => {
    /*
    var infoFa = "./data/faraday/info.txt";
    var proyectosFa = "./data/faraday/proyectos.txt";
    var infoFe = "./data/fermi/info.txt";
    var proyectosFe = "./data/fermi/proyectos.txt";
    var infoP= "./data/plank/info.txt";
    var proyectosP = "./data/plank/proyectos.txt";
*/

    var dirname = "./data";
    fs.readdir(dirname, (err, files) => {
        if(err){
            console.log(err);
        }
        else{
            console.log("Directorio actual");
            files.forEach(file => {
                if(file == req.body.username){
                    var info = "./data/" + file + "/info.txt";
                    var proyectos = "./data/" + file + "/proyectos.txt";
                    //console.log(info);
                    fs.readFile(info, function(err, data){
                        if(err){
                            res.status(500).send(err.message);
                        } else{
                            var obj=JSON.parse(data); //JSON.parse acepta buffers
                            console.log(obj);
                            res.set('Content-type', 'application/json');
                            res.status(200).send(JSON.stringify(obj));
                        }
                    });
                    fs.readFile(proyectos, function(err, data){
                        if(err){
                            res.status(500).send(err.message);
                        } else{
                            var obj=JSON.parse(data); //JSON.parse acepta buffers
                            console.log(obj);
                            res.set('Content-type', 'application/json');
                            res.status(200).send(JSON.stringify(obj));
                        }
                    });
                    //console.log(proyectos);
                }
            })
            //console.log(req.body.username);
        }
    })

    //info: nombre, fecha, lugar
//respuesta: nombre, fnacimiento, lnacimiento, proyectos
   /* res.json(infoFa.filter(data => data.nombre))

    fs.readFile(dbfile, function(err, data){
        if(err){
            res.status(500).send(err.message);
        } else{
            var obj=JSON.parse(data); //JSON.parse acepta buffers
            obj.date=new Date();
            console.log(obj);
            res.set('Content-type', 'application/json');
            res.status(200).send(JSON.stringify(obj));
        }
    });
    */

});

app.get('/object/:objid', (req, res) => {
    var dbfile = "./server/DB1.json";
    fs.readFile(dbfile, function(err, data){
        if(err){
            res.status(500).send(err.message);
        } else{
            var obj=JSON.parse(data); //JSON.parse acepta buffers
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