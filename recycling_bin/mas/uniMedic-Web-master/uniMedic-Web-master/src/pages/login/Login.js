import React, {useState} from 'react';
import './Login.css';
import Title from './components/title/Title';
import Button from "@material-ui/core/Button";
import { makeStyles } from "@material-ui/core/styles";
import logo from './Imagen/logo.png';
const Login= () =>{

    const Utyles = makeStyles({
        root: {
            background: 'linear-gradient(120deg,transparent,var(--primary-color),trasparent)',
          border: 0,
          borderRadius: 20,
          boxShadow: '0 3px 5px 2px rgba(255, 105, 135, .3)',
          color: 'black',
          height: 48,
          padding: '0 30px',
          position: 'relative',
          top: '50px',
          transition: '0.6s',
          
        
        },
      });
      const stilo=Utyles();
      const [datos,setDatos]=useState({
        usuario: '',
        contraseña: ''
    })

     const handleChange= (event) =>{
        setDatos({
            ...datos,
            [event.target.name]: event.target.value
        })
            
    };
    
    return (
        <div className='login-container'>
            <Title text='Bienvenido'/>
            <img  src={logo}/>
            <div class="form-input-material">
                <input type="email" name="usuario" id="usuario" placeholder="Ingrese Correo" autocomplete="off" className="form-control-material" required  onChange={handleChange}/>
            </div>
            <div class="form-input-material">
                <input type="password" name="contraseña" id="contraseña" placeholder="Ingrese Contraseña" autocomplete="off" className="form-control-material" required  onChange={handleChange}/>
            </div>
            <Button className={stilo.root} variant="outlined" color="primary" href="https://google.com"> 
                Ingresar
            </Button>
        </div>
    )
};
export default Login;