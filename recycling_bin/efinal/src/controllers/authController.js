const express = require('express');
const router = express.Router();

router.post('/signin', (req, res) => {
    res.json('signin');
})

router.post('/me', (req, res) => {
    res.json('me');
})

