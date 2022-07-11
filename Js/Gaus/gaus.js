let fs = require('fs');
//console.log(data);
const input_matrix = (n, a, data) => {
	let p = 0;
	for(let i =0; i<n; i++)
		for(let j = 0; j<=n; j++){
			a[i][j]=Number(data[p]);
			p++;
		}
}



const diagonal = (n, a) => {
	for(let i=0; i<n; i++)
		for(let k =i+1; k<n; k++)
			if(Math.abs(a[i][i]) < Math.abs(a[k][i]))
				for(let j=0;j<=n;j++){
					let temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}
	for(let i = 0; i<n-1; i++)
		for(let k=i+1;k<n;k++){
			let t = a[k][i]/a[i][i];
			for(let j=0; j<=n;j++)
				a[k][j] = a[k][j] - t*a[i][j];
		}
	return a;
}



const gaus = (n, a) => {
	let answer = '';
	let x = new Array();
	x.length = 10;
	let sum = 0;
	for(let i = n-1; i>=0; i--){
		x[i] = a[i][n];
		for(let j=i+1; j<n;j++)
			if(j!==i)
				x[i] = x[i] -a[i][j] * x[j];
		x[i] = x[i] / a[i][i];
	}
	for (let i = 0; i<n; i++)
		answer += `X${i+1} = ${Math.round(x[i]*1000)/1000}\t\t`;
	answer += '\n';
	fs.appendFile('exit.txt',answer, ()=>{})
}	



(function () {
	fs.writeFile('exit.txt', '', ()=>{});
	let input = fs.readFileSync('input.txt','utf-8');
	let data = input.split('\r\n').join(' ').split(' ');
	

	//Test 1
	let n = Number(data[0]);
	let a = Array.from(Array(n), () => new Array(n+1));
	input_matrix(n, a, data.slice(1,7));
	diagonal(n, a);
	gaus(n, a);

	//Test 2
	n = Number(data[7]);
	a = Array.from(Array(n), () => new Array(n+1));
	input_matrix(n,a,data.slice(8,20));
	diagonal(n,a);
	gaus(n, a);

	//Test 3
	n = Number(data[20]);
	a =Array.from(Array(n), () => new Array(n+1));
	input_matrix(n, a, data.slice(21,41));
	diagonal(n,a);
	gaus(n, a);
})()
