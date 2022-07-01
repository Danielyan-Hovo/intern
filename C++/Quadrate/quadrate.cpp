#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
//quadrate file


float d_qarrord(float a, float b, float c){
return ((b/2)*(b/2)-4*a*c);
}

float d_sovorakan(float a, float b, float c){
return (b*b-4*a*c);
}

float mekarmat(float a, float b){
return (-b/(2*a));
}

auto qarakusayin(float a, float b, float c){
	float d = d_sovorakan(a, b, c);
        if (d>0){
		float x1, x2;
		x1 = (-b-sqrt(d))/(2*a);
		x2 = (-b+sqrt(d))/(2*a);
	   	return std::vector<float>({x1, x2});
	} else if(d==0){ 
                float x1 = mekarmat(a ,b);
                return std::vector<float>({x1});
        } else return std::vector<float>({0, 0, 0});
}

int main(){
	std::ifstream infile;
	std::ofstream exitfile;
	infile.open("inputQuadrate.txt");
	exitfile.open("exitQuadrate.txt");
	float a,b,c;
	if(!infile){
		exitfile<<"ERROR from inputQuadrate.txt file"<<std::endl;
	}
	else{	
		while(infile>>a>>b>>c){
			auto x = qarakusayin(a,b,c);
			for(auto&i: x){
				exitfile<<i<<"  ";
			}
			exitfile<<std::endl;
		}
	}
	infile.close();
	exitfile.close();
	std::cout<<"quadrate run"<<std::endl;;
return 0;
}
