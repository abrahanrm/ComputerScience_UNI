var axios = require("axios").default;

var options = {
  method: 'POST',
  url: 'https://microsoft-computer-vision3.p.rapidapi.com/ocr',
  params: {detectOrientation: 'true', language: 'unk'},
  headers: {
    'content-type': 'application/json',
    'x-rapidapi-host': 'microsoft-computer-vision3.p.rapidapi.com',
    'x-rapidapi-key': 'db4eaab223mshd8e161f39252b38p170044jsn806af366b89e'
  },
  // data: {url: 'https://www.thesun.co.uk/wp-content/uploads/2018/12/B7P7AEjpg-JS321646614-e1632207470113.jpg'}
  data: {url: 'https://static.buildasign.com/cmsimages/bas-street-sign-splash.png?v=38527A78656C397A6B4E413D'}
  
};

axios.request(options).then(function (response) {
	console.log(response.data);
}).catch(function (error) {
	console.error(error);
});


