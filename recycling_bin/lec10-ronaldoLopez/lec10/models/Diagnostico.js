const { Schema, model } = require('mongoose');

const diagnostico = new Schema ({
     DiagnosticoID: {
         type: String,
         required: true
     },
     Diagnostico: {
         type: String
     },
     FechaDeDiagnostico: {
         type: Date
     }
})
module.exports= model('Diagnostico', diagnostico);