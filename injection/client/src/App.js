import React, { Component } from 'react';
import './App.css';
import axios from 'axios';

//https://reactjs.org/docs/forms.html

class App extends Component {


    // setting the initial state of the variables.
    state = {users: [],
            username: "",
            password: ""}

    componentDidMount() {
        fetch('/users')
        .then(res => res.json())
        .then(users => this.setState({ users }));
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

    onClickLogin = async () => {
        console.log("Log!");
        const loginResponse = await axios.post('/login',{
            "username": this.state.username,
            "password": this.state.password,
        });

        console.log(loginResponse);
    }

render() {


    return (
        // can only return one div
        <div className="App">
            <h1>Users</h1>
            {this.state.users.map(user =>
            <div key={user.id}>{user.username}</div>
            )}

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
            <button onClick={this.onClickLogin}> Login! </button>

        </div>
    );
}

}

export default App;
