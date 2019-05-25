var url = 'http://mylogger.io/log'; // example of the module
function log(message){
     // Send a log http request to the url
     console.log(message);
}
module.exports.log = log;