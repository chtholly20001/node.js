const http = require("http");
const url = require("url");
const fs = require("fs");
const path = require("path");
const port = 8080;
const server = http.createServer((request, response) => {
    //每接受到一次请求，服务器就执行一次这里的代码
    let filePath = path.join(__dirname, "index.html");
    let content = fs.readFileSync(filePath);
    //response.setHeader("Content-type", "text/html;charset=utf-8");
    response.end(content);
  /*  request.on("data", (postData) => {
        console.log(postData.toString());
    })*/
})
server.listen(port, (error) => {
    console.log(error);
    console.log(`WebServer is listening at port ${port}`)
})
