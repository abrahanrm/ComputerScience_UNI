const content = `
	<!doctype html>
    <html>
       <head>
            <meta charset="utf-8">
            <title>PDF Result Template</title>
            <style>
                #titulo {
                    padding-top: 10px;
					text-align: center;
					font-family: 'Merriweather', sans-serif;
					font-size: 20px;
                }
				#imgleft {
					text-align: left;
					width: 220px;
					height: 100px;
					padding-top: 10px;
					border: 2px solid red;

				}
            </style>
        </head>
        <body>
			<div id="imgleft">
				<img src="../logo.png">
			</div>
			<div id="titulo">
				<p>DIAGNÓSTICO MÉDICO</p>
			</div>

            <p>Generando un PDF con un HTML sencillo</p>
			<p>Paciente 
        </body>
    </html>
`;
