import React from 'react';
import './Header.css';


 class Header extends React.Component {
    constructor(props) {
        super(props);

  
        this.state = {
            buttonWasClicked: false,
            imageGraphic: './../../modelData/logo.jpg'
        };

   
        this.handleButtonClickBound = event => this.handleButtonClick(event);
    }

    handleButtonClick(event) {
        event.preventDefault();
        
        this.setState({ buttonWasClicked: !this.state.buttonWasClicked });
        this.setState({ 
            imageGraphic: (this.state.buttonWasClicked ? './../../modelData/emergx.jpeg' : './../../modelData/logo.jpg') 
        });
    }

    render() {
        return (
            <div className="header-Container">
                <p className="header-title"> 
                    <input 
                        type="image" 
                        src={this.state.imageGraphic}
                        alt={this.state.buttonWasClicked ? "Wordmark" : "Logo"}
                        width={this.state.buttonWasClicked ? "100vw" : "400vw"} 
                        height={this.state.buttonWasClicked ? "100vw" : "100vw"} 
                    ></input>
                </p>
                <p className="header-title"> Property of Emergent AI </p>
                <span>
                    <button type="button" onClick={event => this.handleButtonClick(event)}>
                        {this.state.buttonWasClicked ? "Wordmark" : "Logo"}
                    </button>
                </span>
            </div>
        );
    }
 }

 export default Header;