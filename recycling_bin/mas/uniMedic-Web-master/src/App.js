import 'bootstrap/dist/css/bootstrap.min.css';
import {BrowserRouter as Router,Route } from 'react-router-dom';
import './App.css';
import Login from './pages/login/Login.js';
import NavegacionB from './pages/Navegation/NavegacionB';
import Home from './pages/home/Home';
import CreateUser from './pages/createUser/CreateUser';
import Modelos from './pages/Models/Modelos';
import Nosotros from './pages/Nosotros/Nosotros';
import Consultar from './pages/Consultar/Consultar';



function App() {
  
  return (
    <div className='App'>
      <Router>
      <NavegacionB />
      <Route path="/" exact component={Home}/>
      <Route path="/consultar"  component={Consultar}/>
      <Route path="/modelos"  component={Modelos}/>
      <Route path="/nosotros"  component={Nosotros}/>
      
      </Router>
    </div>
    
  );
}

export default App;
