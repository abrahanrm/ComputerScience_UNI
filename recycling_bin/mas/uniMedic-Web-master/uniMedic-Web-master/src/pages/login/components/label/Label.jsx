import React from 'react';
import './Label.css';

const Label= ({text}) =>{
    return(
        <div className='label-style'>
            <label> {text} </label>
        </div>
    )
};
export default Label;