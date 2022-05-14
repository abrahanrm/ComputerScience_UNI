const { Schema, model } = require('mongoose');

const historial = new Schema ({
     UserID: {
         type: String
     },
     DiagnosticoID: {
         type: String,
         unique: true,
         required: true
     }
})
module.exports= model('Historial', historial);