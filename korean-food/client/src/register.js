
import React, { Component } from 'react';
import './App.css';
import axios from 'axios';

//https://reactjs.org/docs/forms.html

class register extends Component {

    // setting the initial state of the variables.
    state = {
        username: "",
        password: "",
        registerMessage: ""
    }

    // Update the value of the username variable
    onKeyDownUsername = (event) => {
        // events are passed in by the event
        this.setState({username: event.target.value});
    }

    // Update the value of the password variable
    onKeyDownPassword = (event) => {
        this.setState({password: event.target.value});
    }

    // Click result of the login button.
    onClickLogin = async () => {
        const loginResponse = await axios.post('/register',{
            "username": this.state.username,
            "password": this.state.password,
        });
        this.setState({registerMessage: loginResponse.data})
    }

render() {


    return (
        // can only return one div
        <div className="reg">
            <h1>
                Register!
            </h1>
            <form>
                <label>
                    <p>Username: </p>
                </label>
                <input type="p" value={this.state.username} onChange={this.onKeyDownUsername} />

                <label>
                    <p> Password: </p>
                </label>
                <input type="password" 	value={this.state.password} onChange={this.onKeyDownPassword} />
            </form>

            <button onClick={this.onClickLogin}>
                Register!
            </button>
            <marquee>{this.state.registerMessage}</marquee>
        </div>
    )}
}


export default register;
