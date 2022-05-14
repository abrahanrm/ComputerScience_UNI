/**
 * npm install express --save
 * npm install express-session --save
 * npm install cookie-parser --save
 */
 var express = require('express');
 var session = require('express-session');
 var cookieParser = require('cookie-parser');

 var app = express();
 app.use(cookieParser());

 var cookie_secret='Este es un secreto!';

 app.use(session({
    secret: cookie_secret,
    resave: true,
    saveUninitialized: true 
}));
 
 app.get('/', function(req, res){
   
   if(!req.session.user){
      req.session.user='no se ha identificado';
      res.cookie('visita', Date(Date.now()), { domain: 'localhost', path: '/', secure: true });
   } else{
      req.session.user='USER1';
   }

    if(req.session.page_views){
       req.session.page_views++;
       console.log("Primera visita: ", req.cookies.visita);
       res.send("Usted ha visitado esta página " + req.session.page_views +  " veces, desde " + req.cookies.visita + " bienvenido " + req.session.user);
    } else {
       req.session.page_views = 1;
       res.send(`Bienvenido a esta pagina!, Usted aun ${req.session.user} gracias por visitarnos por primera vez!`);
    }
 });
 app.listen(5000);
 console.log("Servidor Escuchando en el puerto 5000...");