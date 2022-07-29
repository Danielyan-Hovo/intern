let fs = require('fs');

const zuygD = (a, b, c) => (b/2)**2-4*a*c;

const kentD = (a, b, c) => b*b-4*a*c;

const oneRoot = (a, b) => `${Math.round(-b/(2*a)*100)/100}\n`;

const quadrate = (a, b, c) => {
	let d;
	if( a !==  0 ) {
		if(b % 2 === 0){
			d = zuygD(a, b, c);
			if(d > 0){
				let x1,x2;
				x1 = Math.round(((-b/2) + Math.sqrt(d)) / (a)*100)/100;
	                        x2 = Math.round(((-b/2) - Math.sqrt(d)) / (a)*100)/100;
				let arr = new Array(x1,x2) + '';
				arr.split(',').join(' ');
				return  arr;
			}
			else if(d === 0) return oneRoot(a , b);
			else return NaN;
		}
		d = kentD(a, b, c);
		if(d > 0){
			let x1,x2;
			x1 = Math.round((-b + Math.sqrt(d)) / (2*a)*100)/100;
			x2 = Math.round((-b - Math.sqrt(d)) / (2*a)*100)/100;
			let arr = new Array(x1,x2) + '';
			arr.split(',').join(' ');
			return  arr;
		}
		else if(d === 0) return oneRoot(a , b);
		return NaN;
	} else{
		if (b === 0 && c === 0) return Infinity;
		else if(b ===0) return NaN;
		return -c/b;
	}
}


let input = fs.readFileSync('input.txt','utf-8');
let data = input.split('\n').join(' ').split(' ')
data.pop();
let length = data.length;
let exit1 = '';
for(let i=0; i<length; i+=3){
        exit1+=`${quadrate(data[i],data[i+1],data[i+2])}\n`;
}
fs.writeFile('exit.txt', exit1 ,()=>console.log('succes'));

const test = () => {
        let golden = fs.readFileSync('golden.txt','utf-8').split('\n');
        let exit = exit1.split('\n');
        let str = '';
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

        let result = fs.writeFile('result.txt', str , ()=>{});
}

test();

