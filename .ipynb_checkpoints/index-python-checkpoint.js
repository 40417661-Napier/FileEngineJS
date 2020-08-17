var http = require('http');
var handlebars = require('handlebars');
var findInFiles = require('find-in-files');
var bodyParser = require('body-parser');
const express = require('express');
const cookieparser = require('cookie-parser');
const fs = require('fs');

const { exec }= require("child_process");


const FILEPATH = "./files"

const app = express();
app.use(cookieparser());
server = app.listen(8889);
app.use(bodyParser.urlencoded({
    extended: false
}));
app.use(bodyParser.json());

app.get("/", (req,res) => {
    try { //start landing page compilation
        var src = fs.readFileSync("./html/index.html");
        src = src.toString();
    } catch (error) {
        console.log(error);
    }
    var template = handlebars.compile(src);
    var data = {

    };
    result = template(data);

    res.send(result) //shows the user the login page from the src file location
})

app.post("/filesFind", (req,res) => {
    
    queryRegex = req.body.query
//     FILEPATH is a const
//     python3 main.py -kw {queryRegex} -fd {FILEPATH}
    var queryResult;
    console.log("Starting")
    exec(("python3 ./py/main.py -kw '" + queryRegex + "' -fd " + FILEPATH), (error, stdout, stderr) => {
        if(stdout) {
            console.log(stdout)
            queryResult = JSON.parse(stdout)
//             console.log(Object.keys(queryResult))
            
            var tablePass = "";
            
            for (const key in queryResult) {
              tablePass = tablePass + '<tr><td>' + queryRegex + '</td><td>' + queryResult[key].length + '</td><td><a href=./preview/' + key + '>' + key + '</a></td></tr>'
            }
            
            try { //start landing page compilation
            var src = fs.readFileSync("./html/results.html");
            src = src.toString();
        } catch (error) {
            console.log(error);
        }
        var template = handlebars.compile(src);
        var data = {
            "resultsNum": queryResult.keys,
            "table": tablePass
        };
        result = template(data);

        res.send(result) //shows the user the login page from the src file location 
        }
        else{
            res.send("504 Error")
            console.log(error)
        }
        
         
});
})

app.get('/preview*', function (req, res) {
    //what to do with a url that doesnt exist!

    var url = req.url;
    //console.log(url);
    url = url.split("/preview");
    console.log(url)
    fs.readFile("." + url[1], 'utf8', function (err, filedata) {
        if (err) throw err;
        //console.log(data);
        try { //start landing page compilation
            var src = fs.readFileSync("./html/preview.html");
            src = src.toString();
        } catch (error) {
            console.log(error);
        }

        var template = handlebars.compile(src);
        var data = {
            "preview": filedata,
        };
        result = template(data);

        res.send(result) //shows the user the login page from the src file location
    });
});