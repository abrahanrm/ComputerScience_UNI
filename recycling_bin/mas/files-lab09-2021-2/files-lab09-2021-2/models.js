var axios = require("axios").default;

var options = {
  method: 'GET',
  url: 'https://microsoft-computer-vision3.p.rapidapi.com/models',
  headers: {
    'x-rapidapi-host': 'microsoft-computer-vision3.p.rapidapi.com',
    'x-rapidapi-key': 'db4eaab223mshd8e161f39252b38p170044jsn806af366b89e'
  }
};

axios.request(options).then(function (response) {
	console.log(response.data);
}).catch(function (error) {
	console.error(error);
});