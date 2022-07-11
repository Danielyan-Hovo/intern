let fs = require('fs');

const jacobi = (n, data, p) => {
	const eps = 0.001;
	let answer = '';
	let mat = Array.from(Array(n), () => new Array(n+1));
	let curr = new Array(n);
	let prev = new Array(n);
	for(let i = 0; i<n; i++){
		curr[i] =0, prev[i] =0;
		for(let j = 0; j<=n; ++j){
			mat[i][j] = Number(data[p]);
			p++;
		}
	}
	let maxi = 0;
	let iter = 0;
	let for_exit = true;
	while(for_exit){
		for(let i =0;i<n;i++){
			curr[i] = mat[i][n];
			for(let j =0; j<n; j++){
				if(j!==i)
					curr[i] -= prev[j] *mat[i][j];
				else
					continue;
			}
			curr[i] /= mat[i][i];
		}
		iter++;
		answer +='Ireation ' + iter + '     ';
		let count = 0;
		for(let i =0; i<n;i++){
			maxi = curr[i] - prev[i];
			if(Math.abs(maxi) <= eps)
				count++;
			if(count >= n){
				for_exit = false;
				console.log(111)
			}
			else if(iter > 30){
				for_exit = false;
				console.log('lucum chuni\n');
			}
				prev[i] = curr[i];
				answer +=Math.round(prev[i]*10000)/10000+'   ';
		}
		answer +='\n';
	}
	fs.appendFile('exit.txt',answer+'\n', () =>{});
}


(function () {
	let input = fs.readFileSync('input.txt','utf-8');
	fs.writeFile('exit.txt', '', ()=>{});
	let data = input.split('\r\n').join(' ').split(' ');
	let i =0;
	let n = Number(data[i]);
	jacobi(n, data, i+1);
	i = n*(n+1);
	n = Number(data[i+1]);
	jacobi(n, data, i+2);
})();


