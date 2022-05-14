const { Schema, model } = require('mongoose');

const product = new Schema ({
     Nombre :{
           type: String
     }, 
     Edad: {
           type: Number
     }, 
     Direccion: {
           type: String
     }, 
     UserID: {
           type: String,
           unique: true,
           required: true
     },
     EsMedico: {
           type: Boolean
     } 
})
module.exports= model('usuarios', product);