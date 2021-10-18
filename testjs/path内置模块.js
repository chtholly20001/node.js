const fs = require("fs");
const path = require("path");
const { log } = require("util");

/*const path = require("path");
console.log(__dirname);
console.log(__filename);
console.log(path.extname(__filename));
fs.readFileSync();//同步
fs.readFile();//异步*/
/*let filepath = path.join(__dirname, "file.txt");
const content = fs.readFileSync(filepath);
console.log(content.toString());*/
let filepath = path.join(__dirname, "file.txt");
/*const content = fs.readFileSync(filepath, "utf-8");
console.log(content)*///同步
/*fs.readFile(filepath, "utf-8", (error, data) => {
    if (error)console.log(error);
    else console.log(data);
})*///异步
fs.writeFile(filepath, "写入的内容","utf-8", (error) => {
    if (error) {
        console.log(error);
        return;
    }
    console.log("传输完成");
})