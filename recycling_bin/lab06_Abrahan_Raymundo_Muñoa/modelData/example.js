'use strict';

/*
 * Carga el modelo de datos de la Tarea 1 Del Lab06.
 * Cargamos en el DOM la propiedad cc3s2models.exampleModel 
 * una  funcion que retorna un objeto
 * con la siguiente propiedad:
 *    name:  Una cadena con el nombre.
 *
 * vea README.md para información en como acceder a ella.
 */
var cc3s2models;

if (cc3s2models === undefined) {
   cc3s2models = {};
}

cc3s2models.exampleModel = function() {
   return {
      name: 'Abrahan Raymundo Muñoa',
      lema: 'Mi lema es no importa lo lento que vayas mientras no te detengas'
      
   };
};

