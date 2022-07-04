let fs = require('fs');
const gcd = (num1, num2) => {
	if(num2==0) return num1;
	return gcd(num2, num1 % num2);
}

//console.log(gcd(24,64))
let input = fs.readFileSync('input.txt','utf-8');
let data = input.split('\n').join(' ').split(' ')
data.pop();
let length = data.length;
let exit = [];
for(let i=0; i<length; i+=2){
	exit.push(gcd(data[i],data[i+1]));
}
fs.writeFile('exit.txt',exit,()=>console.log('succes'));

