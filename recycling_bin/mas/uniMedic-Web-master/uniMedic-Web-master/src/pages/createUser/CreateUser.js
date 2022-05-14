import React, {Fragment, useState} from 'react';
import './CreateUser.css';
import Titu from './compoCreateUser/Titu/Titu';

import Button from "@material-ui/core/Button";
import { makeStyles } from "@material-ui/core/styles";
import Icon from '@material-ui/core/Icon';
const CreateUser=() =>{

    const Utyles = makeStyles({
        root: {
            background: 'linear-gradient(120deg,transparent,var(--primary-color),trasparent)',
          border: 0,
          borderRadius: 20,
          boxShadow: '0 3px 5px 2px rgba(255, 105, 135, .3)',
          color: 'green',
          height: 48,
          padding: '0 30px',
          position: 'relative',
          top: '50px',
          transition: '0.6s',
          
        
        },
      });
      const stilo=Utyles();

    const [datos,setDatos]=useState({
        nombres: '',
        apellidos: '',
        correo: '',
        contraseña: ''

    })

     const handleChange= (event) =>{
        setDatos({
            ...datos,
            [event.target.name]: event.target.value
        })
            
    };

    return (
            <Fragment>
                <form className="row">

                <div className='create-user'>
            <Titu text='Registrate en uniMedic'/>
            <br />
            <div class="form-input-material">
                <input type="text" name="nombres" id="nombres" placeholder="Ingrese Nombres" autocomplete="off" className="form-control-material" required  onChange={handleChange}/>
            </div>
            <br />
            <div class="form-input-material">
                <input type="text" name="apellidos" id="apellidos" placeholder=" Ingrese Apellidos" autocomplete="off" className="form-control-material" required  onChange={handleChange}/>
            </div>
            <br />
            <div class="form-input-material">
                <input type="email" name="correo" id="correo" placeholder=" Ingrese Email" autocomplete="off" className="form-control-material" required  onChange={handleChange}/>
            </div>
            <br />
            <div class="form-input-material">
                <input type="password" name="contraseña" id="contraseña" placeholder=" Contraseña" autocomplete="off" className="form-control-material" required  onChange={handleChange}/>

            </div>
            
            <Button className={stilo.root} variant="outlined" color="primary" href="https://google.com"> 
                Registrarse
            </Button>
        </div>
        <Icon className="icono">
            start
        </Icon>
                </form>

        </Fragment>
        
    )
};
export default CreateUser;