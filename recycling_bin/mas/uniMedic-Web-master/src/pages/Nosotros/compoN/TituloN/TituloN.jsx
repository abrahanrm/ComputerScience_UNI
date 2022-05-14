import React from 'react';
import './TituloN.css';

const TituloN=({text}) =>{
    return (
        <div className='titulN-container'>
            <label className='titleN-label'> {text}  </label>
            
        </div>
    )
};
export default TituloN;