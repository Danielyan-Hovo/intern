let fs = require('fs');
let gaus = require('./gaus.js')
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

function test() {
	fs.writeFile('exit.txt', '', ()=>{});
        fs.writeFile('result.txt','',()=>{});
        let count = 0;
        let golden = fs.readFileSync('golden.txt','utf-8').split('\n');
        while(true){
                let arr = new Matrix(5)
                arr.init('test_input.txt')
                if(arr.matrix !== undefined){
                        fs.appendFileSync('exit.txt', gaus(arr).join('   ')+'\n',()=>{})
                        if(golden[count] === gaus(arr).join('   ')){
                                count++
                                fs.appendFileSync('result.txt','Test '+count+' passed\n',()=>{})
                        } else {
                                count++
                                fs.appendFileSync('result.txt','Test '+count+' failed!\n',()=>{})
                        }
                } else{
                        break
                }
        }
}
if(validate_input('test_input.txt')){
        test()
}
