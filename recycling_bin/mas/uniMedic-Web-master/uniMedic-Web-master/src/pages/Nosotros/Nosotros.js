import React from 'react';
import './Nosotros.css';
import Caro from './compoN/Carousel/Caro';
import TituloN from './compoN/TituloN/TituloN';
import LabelN from './compoN/labelN/LabelN';
import Carousel from 'react-elastic-carousel';
import image1 from './compoN/Carousel/Imagenes/image1.jpg';
import image2 from './compoN/Carousel/Imagenes/image2.jpg';
import image3 from './compoN/Carousel/Imagenes/image3.jpg';
import image4 from './compoN/Carousel/Imagenes/image4.jpg';
import image5 from './compoN/Carousel/Imagenes/image5.jpg';
import image6 from './compoN/Carousel/Imagenes/image6.jpg';
import Jose from './compoN/Carousel/Imagenes/Jose.png';
import Particles from 'react-particles-js';


const Nosotros=() =>{
    
    return (
        <div id='particles-js' className='Noso'>
           
           <Particles
    params={{
	    "particles": {
	        "number": {
	            "value": 50
	        },
	        "size": {
	            "value": 3
	        }
	    },
	    "interactivity": {
	        "events": {
	            "onhover": {
	                "enable": true,
	                "mode": "repulse"
	            }
	        }
	    }
	}} />
        <br />
            <LabelN text='Somos estudiantes de la Universidad Nacional de Ingeniería '/>
            <LabelN text='Facultad de Ciencias de la carrera de Ciencia de la Computación'/>
            <br />     
            <Carousel className='car'>
                <img src={Jose} width='700px' height='450px'/>
                <img src={image2} width='700px' height='450px'/>
                <img src={image3} width='700px' height='450px'/>
                <img src={image4} width='700px' height='450px'/>
                <img src={image5} width='700px' height='450px'/>
                <img src={image6} width='700px' height='450px'/>
            </Carousel>
            
        </div>
    )
};
export default Nosotros;