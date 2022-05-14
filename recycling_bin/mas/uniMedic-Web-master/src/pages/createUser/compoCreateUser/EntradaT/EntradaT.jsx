import React from 'react';
import './EntradaT.css';

const EntradaT = ({attribute,handleChange,param}) =>{
    return (
        <div>
            <input 
            id={attribute.id}
            name={attribute.name}
            placeholder={attribute.placeholder}
            type={attribute.type}
            autoComplete={attribute.autoComplete}
            onChange={handleChange}
            className='entrada-style'
            />
        </div>
    )
};

export default EntradaT;