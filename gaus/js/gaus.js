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


const gaus = (a) => {
        a.diagonal()
        let n = a.row
	let x = new Array();
	let sum = 0;
	for(let i = n-1; i>=0; i--){
		x[i] = a.get(i,n);
		for(let j=i+1; j<n;j++)
			if(j!==i)
				x[i] = x[i] -a.get(i,j) * x[j];
		x[i] = Math.round(x[i] / a.get(i,i)*1000)/1000;
	}
        return x;
}
module.exports = gaus

function run() {
	fs.writeFile('exit.txt', '', ()=>{});
        let count = 0;
        while(true){
                let arr = new Matrix(5)
                arr.init('input.txt')
                if(arr.matrix !== undefined){
                        fs.appendFileSync('exit.txt', gaus(arr).join('   ')+'\n',()=>{})
                } else{
                        break
                }
        }
}
if(validate_input('input.txt')){
        run()
}


