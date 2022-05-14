import React from 'react';
import './States.css';

class States extends React.Component {
  constructor(props) {
    super(props);

    this.state = {  
      states: window.cc3s2models.statesModel().sort(), 
      searchString: ''
    };

    this.handleSearchBound = event => this.handleSearch(event);
  }

  handleSearch(event) {
    this.setState({ searchString: event.target.value });
  }


  filterStates(searchString) {
    const statesList = [];
    for(let i = 0; i < this.state.states.length; i++) {
      const stateItem = this.state.states[i];
      if(!searchString || stateItem.toLowerCase().search(searchString.toLowerCase()) >= 0) {
        statesList.push( 
          (<div className="states-list-item"> {stateItem} </div>)
        );
      }
    }

 
    if(statesList.length === 0) {
      statesList.push(
        (<div className="states-list-item"> There are no matching states! </div>)
      );
    }

    return statesList;
  }

  render() {
    return (
      <div>
        <p className="states-searchbar">
          <label htmlFor="inputID"> Search US States </label>
          <input 
            id="inputID"
            type="text"
            value={this.state.searchString}
            onChange={this.handleSearchBound}
          />
        </p>

        <div className="states-list-display">
          <p className="states-list-header"> 
            <span> US States </span>
            { this.state.searchString && (
                <span> Containing "{this.state.searchString}" </span>
              )
            }
          </p>

          <div className="states-list">
            {this.filterStates(this.state.searchString)}
          </div>
        </div>
      </div>
    );
  }
}

export default States;