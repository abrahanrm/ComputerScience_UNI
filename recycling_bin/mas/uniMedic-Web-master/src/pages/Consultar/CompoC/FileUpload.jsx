import React from 'react';
import axios from 'axios';
import './FileUpload.css';
function FileUpload(){

    // State to store uploaded file
    const [file, setFile] = React.useState("");
  
    // Handles file upload event and updates state
    function handleUpload(event) {
      setFile(event.target.files[0]);
  
      // Add code here to upload file to server
      // ...
    } 
    const onSubmit= async e =>{
      e.preventDefault();
      const res= await axios.post('http://localhost:3000', {file: handleUpload.file});
    }

    const ImageThumb = ({ image }) => {
      return <img src={URL.createObjectURL(image)} alt={image.name} width='350px' height='250px'/>;
    };

    return (
      <div className="upload">
        <section>
        <p id="textimg">Ingrese imagen para consultar:</p>
          {file && <ImageThumb image={file} />}
          <nav className="uploadpr">
            <ul className="table">
              <input type="file" onChange={handleUpload} onSubmit={onSubmit} />
              <br/>
              
            </ul>
          </nav>
        </section>
      </div>
    );
  }
  export default FileUpload;