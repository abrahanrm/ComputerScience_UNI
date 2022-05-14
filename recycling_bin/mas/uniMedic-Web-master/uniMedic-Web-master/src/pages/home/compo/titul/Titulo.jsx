import React from 'react';
import './Titulo.css';

const Titulo=({text}) =>{
    return (
        <div className='titulo-container'>
            <label className='title-texto'> {text}  </label>
            
        </div>
    )
};
export default Titulo;