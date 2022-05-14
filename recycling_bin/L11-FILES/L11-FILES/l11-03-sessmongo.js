/**
 * npm install express --save
 * npm install express-session --save
 * npm install parseurl --save
 * npm install mongoose --save
 * npm install connect-mongo --save
 */
 var express = require('express');
 var session = require('express-session');
 var parseurl=require('parseurl');
 var app = express();

 var cookie_secret='secretos';
 const DBURL= 'mongodb://127.0.0.1:27017/mySessionStore';
 
/* 
// conexion 1 con la BD
 const mongoose = require('mongoose');
mongoose.connect(DBURL, {useNewUrlParser: true, useUnifiedTopology: true})
    .then(() => console.log('MongoDB Connected...'))
    .catch((err) => console.log(err));
 */

// conexion 2 con la BD
    var MongoStore=require('connect-mongo');

 app.use(session({
    secret: cookie_secret,
    store:  new MongoStore({
      mongoUrl: DBURL,
      autoRemove:'interval',
      autoRemoveInterval:10 //en minutos
   })
}));
 
app.use( function(req,res,next){
   if(!req.session.views){
      req.session.views={}
   }
//Conseguir la ruta de la url
var pathname=parseurl(req).pathname;
//contar las vistas
req.session.views[pathname]= (req.session.views[pathname] || 0)+1;
next(); 
});

app.get('/zapatos',function(req,res,next){
   res.send('Usted vio nuestra coleccion de zapatos ' + req.session.views['/zapatos'] + ' veces');
})

app.get('/bicicletas',function(req,res,next){
   res.send('Usted vio nuestra coleccion de bicicletas ' + req.session.views['/bicicletas'] + ' veces');
})

 app.get('/', function(req, res){
   var htmlcode=`<div>
                  <h3> Bienvenido a esta pagina!, gracias por visitarnos ! </h3>
                  <h3> vea nuestros <a href= http://localhost:5000/zapatos> zapatos </a>  
                        y <a href= http://localhost:5000/bicicletas> bicicletas </a>   
                  </h3>      
                  </div>`;  
   res.send(htmlcode);
  
 });
 app.listen(5000);
 console.log("Servidor Escuchando en el puerto 5000...");