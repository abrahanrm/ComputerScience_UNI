const config = require('./config/config');

// mongodb
require('./config/db');

const app = require('express')();

const UserRouter = require('./api/User');
// 
//const bodyParser = require('express').json;
//app.use(bodyParser());
var bodyParser = require('body-parser');
app.use(bodyParser.json({limit: "50mb"}));
app.use(bodyParser.urlencoded({limit: "50mb", extended: true, parameterLimit:50000}));

app.use('/user', UserRouter);

app.listen(config.portExpress, () => {
    console.log(`Servidor corriendo en el puerto ${config.portExpress}`);
})

// servidor