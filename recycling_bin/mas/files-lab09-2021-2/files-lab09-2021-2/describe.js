var axios = require("axios").default;

var options = {
  method: 'POST',
  url: 'https://microsoft-computer-vision3.p.rapidapi.com/describe',
  params: {language: 'en', maxCandidates: '1', descriptionExclude: 'Celebrities'},
  headers: {
    'content-type': 'application/json',
    'x-rapidapi-host': 'microsoft-computer-vision3.p.rapidapi.com',
    'x-rapidapi-key': 'db4eaab223mshd8e161f39252b38p170044jsn806af366b89e'
  },
//   data: {url: 'https://cdn.pixabay.com/photo/2017/08/01/00/44/laptop-2562361_960_720.jpg'}
//   data: {url: 'https://ichef.bbci.co.uk/news/976/cpsprodpb/C26C/production/_111927794_gettyimages-1192169655.jpg'}
 // data: {url: 'https://img.fixthephoto.com/blog/images/gallery/news_preview_mob_image__preview_546.jpg'}

data: {url: 'https://cdn.pixabay.com/photo/2021/10/19/12/30/elephant-6723452__340.jpg'}
};

axios.request(options).then(function (response) {
	console.log(response.data);
}).catch(function (error) {
	console.error(error);
});
