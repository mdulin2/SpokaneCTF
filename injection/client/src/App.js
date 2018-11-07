import React, { Component } from 'react';
import ReactDOM from 'react-dom'
import { Switch, BrowserRouter, Route } from 'react-router-dom';

import loginScreen from './loginScreen.js';
import register from './register.js';
import './App.css';
//https://reactjs.org/docs/forms.html

const Routes = () => (
    <BrowserRouter>
        <Switch>
          <Route path='/login' component={loginScreen}/>
          <Route path='/register' component={register}/>
        </Switch>
    </BrowserRouter>
);

export default Routes;
