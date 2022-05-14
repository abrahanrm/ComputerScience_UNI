const express = require('express');
const app = express();
//const morgan = require('morgan');

// Setting
app.set('port', process.env.PORT || 3000);

//middlewares
//app.use(morgan('dev'));
//app.use(express.urlencoded({extended: false}));
app.use(express.json());

//routes
app.use(require('./routes/index'));
app.use('/api/movies',require('./routes/movies'));


app.listen(app.get('port'), () => {
    console.log(`Server on port ${app.get('port')}`);
});