var axios = require("axios").default;

var options = {
  method: 'POST',
  url: 'https://microsoft-computer-vision3.p.rapidapi.com/areaOfInterest',
  headers: {
    'content-type': 'application/json',
    'x-rapidapi-host': 'microsoft-computer-vision3.p.rapidapi.com',
    'x-rapidapi-key': 'db4eaab223mshd8e161f39252b38p170044jsn806af366b89e'
  },
  data: {url: 'https://cdn.pixabay.com/photo/2021/10/19/12/30/elephant-6723452__340.jpg'}
};

axios.request(options).then(function (response) {
	console.log(response.data);
}).catch(function (error) {
	console.error(error);
});