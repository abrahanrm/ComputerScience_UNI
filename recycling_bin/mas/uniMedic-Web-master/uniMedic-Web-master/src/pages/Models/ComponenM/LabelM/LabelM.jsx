import React from 'react';
import './LabelM.css';

const LabelM= ({text}) =>{
    return(
        <div className='labelM-style'>
            <label> {text} </label>
        </div>
    )
};
export default LabelM;