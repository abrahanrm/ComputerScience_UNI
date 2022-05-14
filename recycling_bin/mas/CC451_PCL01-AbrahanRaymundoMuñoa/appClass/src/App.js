import React from "react";
import "./styles.css";
import Home from "./Home";
import Contact from "./Contact";
import About from "./About";
import { Route, Switch } from "react-router-dom";
import Drawer from "./Drawer";
import { makeStyles } from "@material-ui/core/styles";
import Header from "./Header";
import Content from "./Content";


const useStyles = makeStyles({
  container: {
    display: "flex"
  }
});

const App = () => {
  const classes = useStyles();
  return (
    <div className={classes.container}>
      <Drawer />
      <Switch>
        <Route exact from="/" render={props => <Content {...props} />} />
        <Route exact path="/contact" render={props => <Contact {...props} />} />
        <Route exact path="/about" render={props => <About {...props} />} />
      </Switch>
    </div>
  );
};

export default App;
