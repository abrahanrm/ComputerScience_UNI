/*
function calcularImpuestos(edad, ingresos){
    if((edad==18||edad>18)&&(ingresos==1000||ingresos>1000)){
        return ingresos*0.4;
    }
    
    else{
        return 0;
    }
}

console.log(calcularImpuestos(18, 1000));
console.log(calcularImpuestos(40, 10000));
console.log(calcularImpuestos(17, 5000));


function asteriscos(str){
    var count = 0;
    for(let i=0; i<str.length; i++){
        if(str.charAt(i)=='*'){
            count++;
        }
    }
    return count;
}

console.log(asteriscos("H*o*l*a"));
console.log(asteriscos("Hola"));
*/


function duplicar(a){
    for(let i=0; i<a.length; i++){
        a[i]=a[i]*2;
        }
    return a;
}
/*
console.log(duplicar([3, 12, 45, 7]));
*/