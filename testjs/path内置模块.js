const fs = require("fs");
const path = require("path");
const http = require("http");
const url = require("url");
const port = 8080;
const server = http.createServer((request, response) => {
    //每接受到一次请求，服务器就执行一次这里的代码
    let reqUrl = request.url;
    let reqMethod = request.method;//获取方法
    let obj = url.parse(reqUrl, true);
    console.log(obj.query);
    response.write("hello");
    response.end();
})
server.listen(port, (error) => {
    console.log(error);
    console.log(`WebServer is listening at port ${port}`)
})
/*const path = require("path");
console.log(__dirname);
console.log(__filename);
console.log(path.extname(__filename));
fs.readFileSync();//同步
fs.readFile();//异步*/
/*let filepath = path.join(__dirname, "file.txt");
const content = fs.readFileSync(filepath);
console.log(content.toString());*/
//let filepath = path.join(__dirname, "file.txt");
/*const content = fs.readFileSync(filepath, "utf-8");
console.log(content)*///同步
/*fs.readFile(filepath, "utf-8", (error, data) => {
    if (error)console.log(error);
    else console.log(data);
})*///异步
/*fs.writeFile(filepath, "写入的内容","utf-8", (error) => {
    if (error) {
        console.log(error);
        return;
    }
    console.log("传输完成");
})*///写入，会覆盖
