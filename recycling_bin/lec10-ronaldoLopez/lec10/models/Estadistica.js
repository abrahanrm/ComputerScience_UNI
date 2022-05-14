const { Schema, model } = require('mongoose');

const estadistica = new Schema ({
     UserID: {
         type: String,
         required: true
     },
     TiempoDeServicio: {
         type: Date
     },
     Especialidad: {
         type: String  
     },
     Hospital: {
         type: String,
     },
     PacienteID: {
         type: [String] 
     },
     Estrellas: {
         type: Number
     }
})
module.exports= model('Estadistica', estadistica);