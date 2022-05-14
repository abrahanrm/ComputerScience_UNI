//no es un componente
//Peguelo en App.js para visualizarlo

import { StatusBar } from 'expo-status-bar';
import React, {Component} from 'react';
import { StyleSheet, Text, Touchable, TouchableOpacity, View } from 'react-native';

class App extends Component {
  constructor(props){
    super(props);
    this.state = {
      counter: 0,
    }
    this.handleUp = this.handleUp.bind(this);
    this.handleDown = this.handleDown.bind(this);
  }

  handleUp(){
    const {counter: ct} = this.state;
    this.setState({counter: ct + 1});
  }
  handleDown(){
    const {counter: ct} = this.state;
    this.setState({counter: ct - 1});
  }

  render(){
    const {counter} = this.state;
  return (
    <View style={styles.container}>
      <View style = {styles.subcontainer}>
          <TouchableOpacity style={styles.btn} onPress={this.handleDown}>
            <Text style={styles.btnTxt}>-</Text>
          </TouchableOpacity>

          <View style={styles.counterContainer}>
            <Text style={styles.counter}>{counter}</Text>
          </View>

          <TouchableOpacity style={styles.btn} onPress={this.handleUp}>
            <Text style={styles.btnTxt}>+</Text>
          </TouchableOpacity>
          
      </View>
      <StatusBar style="auto" />
    </View>
  );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#81ecec',
    alignItems: 'center',
    justifyContent: 'center',
  },
  subcontainer: {
    height: 50,
    width: '100%',
    paddingHorizontal: 10,
    flexDirection: 'row',
  },
  btn:{
    width: 50,
    height: 50,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#ff7675',
  },
  btnTxt: {
    fontSize: 18,
    color: '#2d3436',
    fontWeight: 'bold',
  },
  counterContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  counter:{
    fontSize: 40,
    color: '#FFF',
    fontWeight: 'bold',
  }
});

export default App;

/* export default function App()  */