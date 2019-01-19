var http = require('http');
var handlebars = require('handlebars');
var findInFiles = require('find-in-files');
var bodyParser = require('body-parser');
const express = require('express');
const cookieparser = require('cookie-parser');
const fs = require('fs');



const app = express();
app.use(cookieparser());
server = app.listen(80);
app.use("/files", express.static(__dirname + '/files'));
app.use(bodyParser.urlencoded({
    extended: false
}));
app.use(bodyParser.json());


app.post("/filesFind", (req, res) => {
    var finding = req.body.query;
    var numFound = [];
    var localLocation = [];
    var result;


    findInFiles.find(finding, "./files/", 'n+').then(function (results) {
        for (var result in results) {
            var res = results[result];
            // console.log(
            //     'found "' + res.matches[0] + '" ' + res.count +
            //     ' times in "' + result + '"'
            // );

            numFound.push(res.count);
            //console.log(numFound.length);

            localLocation.push(result);
            //console.log(localLocation.length);

        }
    }).then(function (mainCode) {
        var tablePass = "";
        for (var index = 0; index < numFound.length; index++) {

            tablePass = tablePass + '<tr><td>' + finding + '</td><td>' + numFound[index] + '</td><td><a href=./preview/' + localLocation[index] + '>' + localLocation[index] + '</a></td></tr>'
        };


        try { //start landing page compilation
            var src = fs.readFileSync("./html/results.html");
            src = src.toString();
        } catch (error) {
            console.log(error);
        }
        var template = handlebars.compile(src);
        var data = {
            "resultsNum": 2,
            "table": tablePass
        };
        result = template(data);
        //console.log(tablePass);

        res.send(result) //shows the user the login page from the src file location
    });


});

app.get("/", (req,res) => {
    // https://medium.freecodecamp.org/learn-how-to-handle-authentication-with-node-using-passport-js-4a56ed18e81e
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

app.get("/login", (req, res) => {
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

app.post("/preview", (req, res) => {

    try { //start landing page compilation
        var src = fs.readFileSync("./html/preview.html");
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

app.get('*', function (req, res) {
    //what to do with a url that doesnt exist!
    
    var url = req.url;
    //console.log(url);
    url = url.split("/preview");

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