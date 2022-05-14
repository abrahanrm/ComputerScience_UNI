import React from 'react';
import './Etiqueta.css';

const Etiqueta= ({text}) =>{
    return(
        <div className='etiqueta-style'>
            <label> {text} </label>
        </div>
    )
};
export default Etiqueta;