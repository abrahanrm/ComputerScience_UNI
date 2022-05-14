import React from "react";
import hmacSHA256 from "crypto-js/hmac-sha256";
import Base64 from "crypto-js/enc-base64";
import "./styles.css";

//Example taken from: ...
//header ...
const header = {
    alg: "HS256",
    typ: "JWT"
};

const payload = {
    sub: "1234567890",
    name: "Jhon Doe",
    iat: 1516239022
};

//No utilizar una...
const jwtSecret = "secret123";

const encodingReplacements = {
    "+": "-",
    "/": "_",
    "=": ""
};

const makeUrlSafe = encoded => {
    return encoded.replace(/[+/=]/g, match => encodingReplacements[match]);
};

const encode = obj => {
    const encoded = btoa(JSON.stringify(obj));
    //return encoded;
    //utilizamos mkeUrlSafe para remover el padding "p. ej. ==" del objeto
    return makeUrlSafe(encoded);
};

//funcion para crear la firma, utiliza hmacSHA256 y Base64
const makeSignature = (header, payload, secret) => {
    //make the signature
    const hashed = hmacSHA256(
        `${encode(header)}.${encode(payload)}`, secret
    );
    const stringified = Base64.stringify(hashed);
    return makeUrlSafe(stringified);
};

const getJwt = (header, payload, signature) => {
    //construct the final JWT
    return `${header}.${payload}.${signature}`
};

function App() {
    return (
        <div className="App">
            <p>Header</p>
            <pre>
                <code>{encode(header)}</code>
            </pre>
            <p>Payload</p>
            <pre>
                <code>{encode(payload)}</code>
            </pre>
            <p>Signature</p>
            <pre>
                <code> {makeSignature(header,payload,jwtSecret)}</code>
            </pre>
            <p>Here is your JWT:</p>
            <pre>
                <code> {getJwt(
                    encode(header),
                    encode(payload),
                    makeSignature(header, payload, jwtSecret)
                )}</code>
            </pre>
        </div>
    );
}

export default App;