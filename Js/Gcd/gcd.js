let fs = require('fs');
const gcd = (num1, num2) => {
	if(num2 === 0) return num1;
	return gcd(num2, num1 % num2);
}

//console.log(gcd(24,64))
let input = fs.readFileSync('input.txt','utf-8');
let data = input.split('\n').join(' ').split(' ')
data.pop();
let length = data.length;
var exit1 = '';
for(let i=0; i<length; i+=2){
	exit1+=`${gcd(data[i],data[i+1])}\n`;
}
fs.writeFile('exit.txt',exit1,()=>console.log('succes'));


const test = () => {
	let golden = fs.readFileSync('golden.txt','utf-8').split('\n');
	let exit = exit1.split('\n');
	let str = '';
	console.log(exit)
	let procent = 100;
	let length = golden.length-1;
	for(let i = 0; i<length; i++){
		if(golden[i] === exit[i])
			str += `${golden[i]} = ${exit[i]} test ${i+1} passed \t <3\n`;
		else{
			str += `${golden[i]} != ${exit[i]} test ${i+1} failed \t :(\n` 
			procent -=10}
	}

	str +=`\n\nTesting Result:  ${procent}%`

	let result = fs.writeFile('result.txt', str , ()=>console.log('testing...'));
}

test();
