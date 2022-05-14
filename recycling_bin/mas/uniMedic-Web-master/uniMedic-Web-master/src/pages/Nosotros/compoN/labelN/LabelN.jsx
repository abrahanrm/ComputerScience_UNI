import React from 'react';
import './LabelN.css';

const LabelN= ({text}) =>{
    return(
        <div className='labelN-style'>
            <label> {text} </label>
        </div>
    )
};
export default LabelN;