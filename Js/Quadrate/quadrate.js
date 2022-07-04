let fs = require('fs');

const zuygD = (a, b, c) => (b/2)**2-4*a*c;

const kentD = (a, b, c) => b*b-4*a*c;

const oneRoot = (a, b) => `${-b/(2*a)}\n`;

const quadrate = (a, b, c) => {
	let d;
	if( a !==  0 ) {
		if(b % 2 === 0){
			d = zuygD(a, b, c);
			if(d > 0){
				let x1,x2;
				x1 = ((-b/2) + Math.sqrt(d)) / (a);
	                        x2 = ((-b/2) - Math.sqrt(d)) / (a);
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
			x1 = (-b + Math.sqrt(d)) / (2*a);
			x2 = (-b - Math.sqrt(d)) / (2*a);
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
let exit = '';
for(let i=0; i<length; i+=3){
        exit+=`${quadrate(data[i],data[i+1],data[i+2])}\n`;
}
fs.writeFile('exit.txt', exit ,()=>console.log('succes'));


