import React from 'react';
import './TituloM.css';

const TituloM=({text}) =>{
    return (
        <div className='titulM-container'>
            <label className='title-label'> {text}  </label>
            
        </div>
    )
};
export default TituloM;