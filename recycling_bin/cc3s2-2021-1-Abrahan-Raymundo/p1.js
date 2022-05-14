const express = require('express');
const app = express();
const path = require('path');

//requerir underscore para el manejo de arreglo
const _ = require('underscore');

app.use(express.json());

const perros = require('./data/perros/data.json');
const gatos = require('./data/gatos/data.json');

app.get('/', (req, res) => {
    res.sendFile(path.resolve(__dirname, 'index.html'));
});

app.get('/perros', (req, res) => {
    res.header("Content-Type",'application/json');
    res.send(perros);
    
});

app.get('/gatos', (req, res) => {
    res.header("Content-Type",'application/json');
    res.send(gatos);
});


//routes with params id

app.get('/perros/:id', (req, res) => {
    const { id } = req.params;
    _.each(perros, (perro, i) => {
        if(perro.id == id){
            res.send(perro);
        }
    });
    res.send('ID incorrecto');
});

app.get('/gatos/:id', (req, res) => {
    const { id } = req.params;
    _.each(gatos, (gato, i) => {
        if(gato.id == id){
            res.send(gato);
        }
    });
    res.send('ID incorrecto');
});



app.listen(5050, () => {
    console.log('Server on port 5050');
});