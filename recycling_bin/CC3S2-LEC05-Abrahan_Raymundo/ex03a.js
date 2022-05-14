let myPromise = new Promise(function(myResolve, myReject){
    setTimeout(function(){myResolve("Este es el container");},3000);
});

myPromise.then(function(value){
    document.getElementById("container").innerHTML = value;
});