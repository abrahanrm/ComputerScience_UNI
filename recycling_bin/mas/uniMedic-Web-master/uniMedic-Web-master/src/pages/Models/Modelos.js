import React from 'react';
import './Modelos.css';
import TituloM from './ComponenM/TituloM/TituloM'
import LabelM from './ComponenM/LabelM/LabelM'
import arqui from './images/arqui.png';
import desenet from './images/desenet.png';
import unetDemo from './images/unetDemo.gif';
import {Link} from 'react-router-dom';

 const Modelos=() =>{

    return (
        <div className='model'>
            <TituloM text='uniMedic-Modelos'/>
            <LabelM text=''/>
            <LabelM text='Los modelos de uniMedic son los módulos de PyTorch 🔥 que se utilizan actualmente en uniMedic-Core,'/>
            <LabelM text='entrenados en conjuntos de datos disponibles públicamente.'/>
            <LabelM text='Cada modelo tiene una breve explicación a continuación y un ejemplo de cómo hacer inferencias sobre el modelo.'/>
            <TituloM text='Visual Question Answering ❓'/>
            <LabelM text=''/>
            <LabelM text='Visual Question Answering es una tarea desafiante para el aprendizaje automático moderno. Requiere un sistema de'/>
            <LabelM text='inteligencia artificial que pueda comprender tanto el texto como el idioma, de modo que pueda responder preguntas'/>
            <LabelM text='basadas en texto dado el contexto visual (una imagen, una tomografía computarizada, una resonancia magnética, etc.).'/>
            <LabelM text='Arquitectura del modelo VQA: '/>
            <img src={arqui} className='image'/>
            <TituloM text='Segmentación Cerebral Médica 🧠'/>
            <LabelM text=''/>
            <LabelM text='La segmentación médica es la tarea de resaltar una región o un conjunto de regiones con una propiedad específica'/>
            <LabelM text='Nuestro modelo usa una arquitectura UNet, una red residual basada en downsampling y upsampling que tiene un'/>
            <LabelM text='buen desempeño en la localización de diferentes características, como se presenta en PyTorch hub, gracias al trabajo'/>
            <LabelM text='de Mateusz Buda.'/>
            <LabelM text='A continuación se muestra una tarea de segmentación cerebral: '/>
            
            <br />
            <img src={unetDemo} width='40%' height='200px' className='image'/>
            <br />
            <TituloM text=''/> 
            <TituloM text='Etiquetado Médico 📝'/>
            <LabelM text=''/>
            <LabelM text='El etiquetado médico es la tarea de elegir qué tipo de imagen el usuario está introduciendo en la aplicación, las'/>
            <LabelM text='posibles etiquetas son cerebro, pecho, mama, ojos, corazón, codo, antebrazo, mano, húmero, hombro, muñeca.'/>
            <LabelM text='Actualmente, nuestro modelo VQA tiene soporte solo para cerebro y pecho (toráx), pero estamos trabajando para'/>
            <LabelM text='agregar soporte a múltiples etiquetas.'/>
            <LabelM text='A continuación se muestra la arquitectura de Densenet121: '/>
            <img src={desenet}  className='image'/>
            <TituloM text=''/> 
            <TituloM text='Filtrado Médico 🚫'/>
            <LabelM text=''/>
            <LabelM text='El filtrado médico es la tarea de etiquetar imágenes en dos conjuntos, médicos y no médicos, ya que queremos filtrar'/>
            <LabelM text='todos los no médicos para que no se incluyan en los otros modelos de aprendizaje automático.'/>
            <LabelM text='Nuestro modelo utiliza la misma arquitectura Densenet121 del módulo torchvision.'/>
            <TituloM text='Datasets ✔️'/>
            <LabelM text='Los conjuntos de datos utilizados en este proyecto son una versión aumentada de:'/>
            <LabelM href="https://www.nature.com/articles/sdata2018251#data-citations" text='-VQA-RAD'/>
            <LabelM href="https://www.kaggle.com/c/tiny-imagenet" text='-Tiny ImageNet'/>
            <LabelM href="http://medicaldecathlon.com/" text='-Medical Decathlon'/>
            <br />
            <br/>
            <p><a href="https://www.dropbox.com/s/5wwskxctvcxiuea/MedNIST.tar.gz">-Mednist</a>'- el conjunto de datos está amablemente disponible por <a href="https://www.mayo.edu/research/labs/radiology-informatics/overview">Dr. Bradley J. Erickson M.D., Ph.D.</a>
            '-(Departamento de Radiología, Clínica Mayo) bajo licencia Creative Commons <a href="https://creativecommons.org/licenses/by-sa/4.0/">CC BY-SA 4.0.</a>
            </p>
            


        </div>
    )
};
export default Modelos;