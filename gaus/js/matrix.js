let fs = require('fs');
let iter = 0;

class Matrix {
	constructor(...size) {
			if (size[0] instanceof Matrix){
                        this.matrix = size[0].matrix
                        this.row = size[0].row
                        this.col = size[0].col
                        } else if (!Array.isArray(size[0])) {
			this.row = size[0];
			this.col = size[1]?size[1]:size[0];
			this.matrix = Array.from(Array(this.row), () => new Array(this.col).fill(2));
			} else if (Array.isArray(size[0])&& !(size[0] instanceof Matrix)){
                        this.matrix = size[0]
                        this.row = this.matrix.length
                        this.col = this.matrix[0].length
                }
	}
	diagonal(){
		let a = this.matrix;
		let n = a.length;
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
		this.matrix =a;
	}

	init(file){
		let data = fs.readFileSync(file,'utf-8');
        	let arr = []
        	data.split('\r\n\r\n').map((el)=>{arr.push(el.split('\r\n').map((it)=>{
        	return it.split(' ')}))})
        	let p = [];
        	for(let i=0; i<arr.length;i++){
                	p.push([])
                	for(let j=0;j<arr[i].length;j++){
                        	p[i].push([])
                        	for(let k=0; k<arr[i][j].length;k++){
                                	p[i][j].push(Number(arr[i][j][k]))
                        	}
                	}
        	}
       		this.matrix = p[iter]
       		if(p[iter]){
       			this.row = p[iter].length
       			this.col = p[iter][0].length
       		}
		iter++
	}

        print() {
                console.log(this.matrix)
        }

        get(i,j){
                return this.matrix[i][j]
        }

        set(i,j,value){
                this.matrix[i][j] = value
        }

}
module.exports = Matrix;