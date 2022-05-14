
const express = require('express');
const router = express.Router();

const jwt = require('jsonwebtoken');


// mongodb user model
const User = require('./../models/User');

// Password handler
const bcrypt = require('bcrypt');

// Signup
router.post('/login', (req, res) => {
	let {
		username,
		email, 
		password
	} = req.body;
	username = username.trim();
	email = email.trim();
	password = password.trim();

	jwt.sign({id: user._id});
	res.json('Received')
});


router.get('/consulta', function(req, res) {
	User.find({ username}, function(err, collection) {
		if (err) {
			console.log(err);
		} else {
			//res.render("page", {collection: collection});
			res.json({
				status: 'SUCCESS',
				message: 'Obtención satisfactoria de usuarios',
				data: collection
			});
		}
	});
});

router.get('/correos', function(req, res) {
	User.findOne({email}, function(err, collection) {
		if (err) {
			console.log(err);
		} else {
			res.json({
				status: 'SUCCESS',
				message: 'Obtención satisfactoria de usuario',
				data: collection
			});
		}
	});
});

module.exports = router;
