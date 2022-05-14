import React from 'react';
import Titulo from './compo/titul/Titulo';
import Textos from './compo/labels/Textos';
import Button from "@material-ui/core/Button";
import { makeStyles } from "@material-ui/core/styles";
import './Home.css';
import doctor from './compo/imagen/doctor.png';
const Home=() =>{

    const useStyles = makeStyles({
        root: {
          background: 'linear-gradient(45deg, #FE6B8B 30%, #FF8E53 90%)',
          border: 0,
          borderRadius: 20,
          boxShadow: '0 3px 5px 2px rgba(255, 105, 135, .3)',
          color: 'white',
          height: 48,
          padding: '0 30px',
          position: 'relative',
          top: '1px',
          right: '790px',
        },
      });

      const UStyles = makeStyles({
        root: {
          background: 'linear-gradient(45deg, #FE6B8B 30%, #FF8E53 90%)',
          border: 0,
          borderRadius: 20,
          boxShadow: '0 3px 5px 2px rgba(255, 105, 135, .3)',
          color: 'white',
          height: 48,
          padding: '0 30px',
          position: 'relative',
          top: '1px',
          right: '750px',
        },
      });
      const estilo=useStyles();
      const stile=UStyles();
    return (
        <div className='Home-ini'>
            <Titulo text='Cuida tu salud con uniMedic'/>
            <Textos text='Evita exponerte al coronavirus con nuestro'/>
            <Textos text='asistente virtual médico que te brinda'/>
            <Textos text='diagnóstico en tiempo real.'/>
            <img src={doctor} className='imag'/> 
            <Button className={estilo.root} variant="outlined" color="primary" href="https://google.com"> 
                Descargar
            </Button>
            <Button className={stile.root} variant="outlined" color="primary" href="https://google.com"> 
                Asociate con Nosotros
            </Button>

            
        </div>
    )
};
export default Home;