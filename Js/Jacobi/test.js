let fs = require('fs');
let e = fs.readFileSync('exit.txt','utf-8');
let g = fs.readFileSync('golden.txt','utf-8');

let exit = e.split('\n\n');
let golden = g.split('\n\n');

let length = golden.length;
let result = '';
for(let i = 0; i < length-1; i++){
	if(exit[i] === golden[i])
		result += `Test ${i+1}   passed Succesfully <3\n`;
	else
		result += `Test  ${i+1}  failed !!!\n`;
}
fs.writeFile('result.txt', result,()=> console.log('Testing'));
