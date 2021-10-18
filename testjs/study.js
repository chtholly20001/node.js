const m1 = require("./m1.js");
let obj = {
    name: "chtholly",
    age: 21,
    email:"383833916@qq.com"
}
console.log(m1.num);
/*es6新增语法 简写方法
let a = [1, 2, 3];
console.log(obj.name);
console.log(obj["name"]);
let { name:myname, email, age } = obj;
console.log(myname, email, age);//对象解构
[, a] = a;
console.log(a);//数组解构 字符串同理
console.log(`${obj.name}年龄为${obj.age}，邮箱为${obj.email}`);
function func1({ name = "Chtholly", age = 10 } = {}) {
    console.log(name, age);
}
func();
//三点运算符：
function func2(a, b, ...rest) {//rest:剩余运算符
    console.log(a, b);
    console.log(rest);
}
func2(1, 2, 3, 4, 5, 6);
let a = [1, 2, 3];
function func3(a, b, c) {//扩展运算符写法
    console.log(a, b ,c);
}
func3(...a);*/
//面向对象 ES6的写法
class Animal {//定义一个类
    constructor(name){
        this.name = name
    console.log("constructor")
}
    //定义一个实例方法
    showName() {
        console.log(`My name is ${this.name}`)
    }
    static eat() {
        console.log("静态方法");
    }
}
Animal.num = 10;
let dog = new Animal("chtholly");
dog.showName();
Animal.eat();
console.log(Animal.num);
//继承的格式：class Cat 子类名 extends 父类名.修改constructor时加上super();
