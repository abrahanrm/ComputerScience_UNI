var express = require('express')
var app = express()
const port = 3000

app.use(function(req, res, next){
    //fecha actual
    let ts = Date.now();
    let date_ob = new Date(ts);
    let date = date_ob.getDate();
    let month = date_ob.getMonth() + 1;
    let year = date_ob.getUTCFullYear();

    //imprime la fecha en el formato DD-MM-YYY
    console.log(date + "-" + month + "-" + year);
    next();
})

//middleware
app.get('/', (req, res) => {
    res.send('Hello World! - desde el middleware ')
})

//puerto
app.listen(port, () => {
    console.log(`Aplicacion de ejemplo escuchando en http://localhost:${port}`)
})