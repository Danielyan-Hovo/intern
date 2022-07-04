let fs = require('fs');
const linear = (a, b) => {
	if (a == 0 && b == 0) return Infinity;
	else if (a == 0) return NaN;
	else return -b/a;
}

console.log(linear(0,0));
console.log(linear(0,7));
console.log(linear(34,93));
let input = fs.readFileSync('input.txt','utf-8');
let data = input.split('\n').join(' ').split(' ')
data.pop();
let length = data.length;
let exit = [];
for(let i=0; i<length; i+=2){
	exit.push(linear(data[i],data[i+1]));
}
fs.writeFile('exit.txt',exit,()=>console.log('succes'));
