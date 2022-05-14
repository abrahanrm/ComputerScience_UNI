import React from 'react';
import './Textos.css';

const Textos= ({text}) =>{
    return(
        <div className='texto-style'>
            <label> {text} </label>
        </div>
    )
};
export default Textos;