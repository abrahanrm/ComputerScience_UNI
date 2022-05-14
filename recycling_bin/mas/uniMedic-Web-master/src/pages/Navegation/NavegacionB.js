import React from 'react';
import './NavegacionB.css';
import log from './Image/log.png';
import {Link} from 'react-router-dom';

const NavegacionB = () => {
    return (
        <nav className="navbar navbar-expand-lg navbar-dark bg-dark">
            <div className="container-fluid">
                <img src={log} width='50px' height='50px'/>
                <Link className="navbar-brand" to="/">
                uniMedic
                </Link>
                <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                    <span className="navbar-toggler-icon"></span>
                </button>
                <div className="collapse navbar-collapse" id="navbarNav">
                    <ul className="navbar-nav ml-auto">
                        <li className="nav-item">
                            <Link className="nav-link active" to="/">Inicio</Link>
                            
                        </li>
                        <li className="nav-item">
                        <Link className="nav-link active" to="/consultar">Consultar</Link>
                        </li>
                        <li className="nav-item">
                        <Link className="nav-link active" to="/modelos">Modelos</Link>
                        </li>
                        <li className="nav-item">
                        <Link className="nav-link active" to="/nosotros">Acerca de</Link>
                        </li>
                        
                    </ul>
                </div>
            </div>
        </nav>
    )
};
export default NavegacionB;