/**
 * npm install express --save
 * npm install express-session --save
 */
 var express = require('express');
 var session = require('express-session');
 var app = express();
 var cookie_secret='Este es un secreto!';

 app.use(session({
    secret: cookie_secret,
    resave: true,
    saveUninitialized: true
}));
 
 app.get('/', function(req, res){
    if(req.session.page_views){
       req.session.page_views++;
       res.send("Usted ha visitado esta página " + req.session.page_views + " veces");
    } else {
       req.session.page_views = 1;
       res.send("Bienvenido a esta pagina! gracias por visitarnos por primera vez!");
    }
 });
 app.listen(3000);
 console.log("Servidor Escuchando en el puerto 3000...");