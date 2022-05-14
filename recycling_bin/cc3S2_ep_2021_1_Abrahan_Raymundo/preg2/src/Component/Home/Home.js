import React from "react";
import React, { Component } from 'react';
/*import ReactDOM from 'react-dom';*/

import CrearEncuesta from './Component/CrearEncuesta/CrearEncuesta';
import ResponderEncuesta from './Component/ResponderEncuesta/ResponderEncuesta';
import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link
} from "react-router-dom";

class Home extends Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
        <Router>
          <div>
            <ul>
              <li>
                <Link to="/CrearEncuesta">Crear Encuesta</Link>
              </li>
              <li>
                <Link to="/ReponderEncuesta">Responder una Encuesta</Link>
              </li>
            </ul>
    
            <Switch>
              <Route exact path="/">
              </Route>
              <Route path="/CrearEncuesta">
                <CrearEncuesta />
              </Route>
              <Route path="/ResponderEncuesta">
                <ResponderEncuesta />
              </Route>
            </Switch>
          </div>
        </Router>
      );
  }
}

export default Home;