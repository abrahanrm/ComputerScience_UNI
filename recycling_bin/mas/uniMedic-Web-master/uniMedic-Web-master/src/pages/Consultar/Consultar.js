import React, {Component} from 'react';
import './Consultar.css'
import FileUpload from './CompoC/FileUpload'
import AwesomeForm from './CompoC/ImageThumb';
const  Consultar=({ image })=> {
  
  
    return (
      <div className='Consultar'>

        <FileUpload className='sub'/>
          <AwesomeForm />
      </div>
      
    );
  }
  
  export default Consultar;