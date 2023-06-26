//Community Connections
//A Typescript Application 

//imports necessary libraries
import * as React from 'react';
import { BrowserRouter as Router, Route, Link, Switch } from 'react-router-dom';
import { connect } from 'react-redux';
import { bindActionCreators } from 'redux';
import SignInForm from '../SignInForm';
import HomePage from '../HomePage';
import Iframe from 'react-iframe';

//defines the types of properties and methods of the class
interface Props { }

interface State { }

//component class of the application 
class CommunityConnections extends React.Component<Props, State> {
	constructor(props: Props) {
		super(props);
		this.state = { };
	}

	render() {
		return (
			<Router>
				<div className="app-container">
					<div className="header-bar">
						<h1>Community Connections</h1>
					</div>
					<div className="main-container">
						<Switch>
							<Route exact path="/" component={HomePage} />
							<Route path="/signin" component={SignInForm} />
							<Route path="/iframe" component={Iframe} />
						</Switch>
					</div>
				</div>
			</Router>
		);
	}
}

//maps redux state to properties 
function mapStateToProps(state) {
	return {
 		authUser: state.authUser
	};
}

//connects the redux store to the component properties
export default connect(
	mapStateToProps,
	null
)(CommunityConnections);