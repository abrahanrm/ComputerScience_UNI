
import React from 'react';
import axios from 'axios'; 
import './ImageThumb.css';
  class AwesomeForm extends React.Component {
    constructor(props) {
      super(props);
      this.state = {
        consultar: ''
      };
  
      this.handleChange = this.handleChange.bind(this);
    }

    handleChange(event) {
      this.setState({consultar: event.target.value});
    }
    onSubmit = async e => {
      e.preventDefault();
      const res= await axios.post('http://localhost:3000', {consulta: this.state.consulta});
    }

    render() {
      return (
        <form className="formularioconsultar" onSubmit={this.onSubmit}>

    <input type='text' name='respuesta' id='respuesta' placeholder='' disabled className='ho' />
          <input type='text' name='consultar' id='consultar' placeholder='Ingrese Consulta' onChange={this.handleChange}/>
          <input type="submit" value="Enviar"/>

        </form>
      );
    }
  }
  export default AwesomeForm;