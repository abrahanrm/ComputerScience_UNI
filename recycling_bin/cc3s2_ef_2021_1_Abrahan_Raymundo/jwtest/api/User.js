const express = require("express");
const router = express.Router();
const jwt = require('jsonwebtoken');

// mongodb user model
const User = require("./../models/User");

// Password handler
const bcrypt = require("bcrypt");

// Signup
router.post("/login", (req, res) => {
  let { username, email, password};
  username = username.trim();
  email = email.trim();
  password = password.trim();

  jwt.sign({id: user});
  res.json('Received');

});

// Signin
router.get("/correo", (req, res) => {
    User.find({ email })
      .then((data) => {
        if (data.length) {
          // User exists
          const hashedPassword = data[0].password;
          bcrypt
            .compare(password, hashedPassword)
            .then((result) => {
              if (result) {
                // Password match
                res.json({
                  status: "SUCCESS",
                  message: "Inicio de sesión satisfactorio",
                  data: data,
                });
              } else {
                res.json({
                  status: "FAILED",
                  message: "Contraseña inválida!",
                });
              }
            })
            .catch((err) => {
              res.json({
                status: "FAILED",
                message: "Ocurrió un error mientras se comparaban las contraseñas",
              });
            });
        } else {
          res.json({
            status: "FAILED",
            message: "Credenciales inválidas!",
          });
        }
      })
      .catch((err) => {
        res.json({
          status: "FAILED",
          message: "Se produjo un error al verificar si había un usuario existente.",
        });
      });
  }
});

module.exports = router;
