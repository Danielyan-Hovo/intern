let fs = require('fs');
let Matrix = require('./matrix.js')

const validate_input = (file) => {
        fs.writeFile('exit.txt','',() => {})
        if(!fs.existsSync(file)){
                fs.appendFile('exit.txt',`${file} file doesent exists!`,()=>{})
                return false
        }
        let data = fs.readFileSync(file,'utf-8')
        if(data.length === 0){
                fs.appendFile('exit.txt',`${file} file is empty!`,()=>{})
                return false
        }
        let err = ''
        let bool = true
        let line_count = 0
	data.split(/\r?\n/).forEach(line =>  {
                line_count++
                line.split(' ').forEach((item) => {
                        if (isNaN(+item)) {
                                err =`Error in line ${line_count} ${file}:  `+item+' is not a Number\n'
                                fs.appendFile('exit.txt',err,() => {})
                                bool = false
                        }
                })
	});
        return bool;
}


const jacobi = (arr) => {
	const eps = 0.00001;
	let curr = new Array(arr.row).fill(0);
	let prev = new Array(arr.row).fill(0);
	let maxi = 0;
	let iter = 0;
	let applicable = true;
	let for_exit = true;
	while (for_exit) {
		for (let i =0; i<arr.row; i++) {
			curr[i] = arr.get(i,arr.row);
			for (let j =0; j<arr.row; j++) {
				if (j!==i) {
					curr[i] -= prev[j] * arr.get(i,j);
                                } else {
					continue;
                                }
			}
			curr[i] /= arr.get(i,i);
		}
		iter++;
		let count = 0;
		for (let i =0; i<arr.row; i++) {
			maxi = curr[i] - prev[i];
			if (Math.abs(maxi) <= eps) {
				count++;
                        }
			if (count >= arr.row) {
				for_exit = false;
			}
			else if (iter > 30) {
				for_exit = false;
				applicable = false
			}
			prev[i] = curr[i];
		}
	}
        prev = prev.map((item) => {return Math.round(item*100000)/100000})
        if(applicable){
       	return prev
	   } else {
	   	return "Matrix can't  applicable for Jacobi method!"
	   }
}
module.exports = jacobi



function  run() {
	fs.writeFile('exit.txt', '', ()=>{});
        let count = 0;
        while (true) {
                let arr = new Matrix(5)
                arr.init('input.txt')
                if (arr.matrix !== undefined) {
                        count++
                        if (typeof jacobi(arr) === 'string') {
                                fs.appendFileSync('exit.txt', jacobi(arr)+'\n', ()=>{})
                        } else {
                                fs.appendFileSync('exit.txt', jacobi(arr).join('\t\t')+'\n')
                        }
                } else {
                        break
                }
        }
}

if(validate_input('input.txt')){
        run()
}

