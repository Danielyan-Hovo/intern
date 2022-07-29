let fs = require('fs');

const linear = (a, b) => {
	if (a == 0 && b == 0) return Infinity;
	else if (a == 0) return NaN;
	else return -b/a;
}

let input = fs.readFileSync('input.txt','utf-8');
let data = input.split('\n').join(' ').split(' ')
data.pop();
let length = data.length;
let exit1 = '';
for(let i=0; i<length; i+=2){
	exit1+= `${linear(data[i],data[i+1])}\n`;
}
fs.writeFile('exit.txt',exit1,()=>console.log('succes'));

const test = () => {
	let golden = fs.readFileSync('golden.txt','utf-8').split('\n');
	let exit = exit1.split('\n');
	let procent = 100;
	let str = '';
	let len = golden.length-1;
	for (let i = 0; i<len; i++){
		if (golden[i] === exit[i]){
			str += `${golden[i]} === ${exit[i]} test ${i+1} passed \t:)\n`;
		}
		else{
			str += `${golden[i]} !=== ${exit[i]} test ${i+1} failed \t:(\n`;
			procent -= 10;
		}
	}
	str += `\n\n Test result   ${procent}%`
	fs.writeFile('result.txt',str,()=>{});
}

test();
