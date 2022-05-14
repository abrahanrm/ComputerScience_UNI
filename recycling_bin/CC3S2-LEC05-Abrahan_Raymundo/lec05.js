//-----Pregunta 1------------------

each([1,2,3,4], function(val){
    console.log(val);
})//imprime cada elemento del arreglo

each([1,2,3,4], function(val){
    console.log(val*2);
})//imprime cada elemento del arreglo multiplicado por 2

//each recorre la matriz y ejecuta la funcion de callback en cada elemento
function each(array, f){
    for(var i=0; i<array.length; i++){
        f(array[i]);
    }
}

//-----Pregunta 2------------------


reject([1,2,3,4], function(val){
    return val>2;
})

reject([2,3,4,5], function(val){
    return val % 2 == 0;
});

//reject devuelve un array con todos los valores del array que no retornan verdadero
function reject(array, f){
    var out = [];
    for(var i=0; i<array.length; i++){
        if(f(array[i])==true){
            out.push(array[i]);
        }
    }
    return out;
}; 

//------Pregunta 3--------------
//setTimeout y setInterval 
//---input: funcion callback y tiempo
//---output: identificador de temporizador

//clearTimeout y clearInterval
//---input: identificador de temporizador

let timerId = setInterval(function(){
    console.log("HI!");
},1000);

setTimeout(function(){
    clearTimeout(timerId);
},3000);
