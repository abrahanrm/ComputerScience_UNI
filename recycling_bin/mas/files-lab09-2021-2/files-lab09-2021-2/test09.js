var axios = require("axios").default;

var options = {
  method: 'POST',
  url: 'https://microsoft-computer-vision3.p.rapidapi.com/analyze',
  params: {
    language: 'en',
    descriptionExclude: 'Celebrities',
    visualFeatures: 'ImageType',
    details: 'Celebrities'
  },
  headers: {
    'content-type': 'application/json',
    'x-rapidapi-host': 'microsoft-computer-vision3.p.rapidapi.com',
    'x-rapidapi-key': 'db4eaab223mshd8e161f39252b38p170044jsn806af366b89e'
  },
  data: {url: 'https://ichef.bbci.co.uk/news/976/cpsprodpb/C26C/production/_111927794_gettyimages-1192169655.jpg'}
};

axios.request(options).then(function (response) {
	console.log(response.data);
}).catch(function (error) {
	console.error(error);
});