import React, { Component } from "react";
import  { Redirect } from 'react-router-dom';
import "./App.css";
import axios from "axios";

//https://reactjs.org/docs/forms.html

class loginScreen extends Component {
  // setting the initial state of the variables.
  state = { users: [], username: "", password: "", loginMessage: "" };

  // Update the value of the username variable
  onKeyDownUsername = event => {
    // events are passed in by the event
    this.setState({ username: event.target.value });
  };

  // Update the value of the password variable
  onKeyDownPassword = event => {
    this.setState({ password: event.target.value });
  };

  // Action for pressing the login button
  onClickLogin = async () => {
    const loginResponse = await axios.post("/login", {
      username: this.state.username,
      password: this.state.password
    });

    console.log(loginResponse);

    // Messsage logic for logging in
    if (loginResponse.data === "") {
      this.setState({ loginMessage: "Bad Login" });
    } else {

      this.setState({ loginMessage: "Success" });
    }
  };

  render() {
    return (
      // can only return one div
      <div className="App">
        <form>
          <label>
            <p>Username: </p>
          </label>
          <input
            type="p"
            value={this.state.username}
            onChange={this.onKeyDownUsername}
          />

          <label>
            <p> Password: </p>
          </label>
          <input
            type="password"
            value={this.state.password}
            onChange={this.onKeyDownPassword}
          />
        </form>

        <button onClick={this.onClickLogin}>Login!</button>

        <div>
          <a href="/register"> Register... </a>
        </div>
        {this.state.loginMessage === 'Success' &&
        <p> <a href="/koreanFood">Korean Food Page!</a></p>
        }
        <marquee>{this.state.loginMessage}</marquee>
      </div>
    );
  }
}

export default loginScreen;
