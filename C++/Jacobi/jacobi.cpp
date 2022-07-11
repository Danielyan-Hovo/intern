#include<iostream>
#include <fstream>
#include <string>
using namespace std;

const double epsilon = 1/(1000);

/* ֆունկցիան input.txt ֆայլից ստանում է ներածվող տվյալները՝ փոփոխականների և
 * իտերացիաների քանակը,, առաջնահերթ ստուգում
 * է արդյոք տվյալ գծային հավասարումների համակարգը հնարավոր է լուծել ըստ		Յակոբի
 * մեթոդի, հետո ամեն իտերացիայից հետո փոփոխականի արժեքները համեմատվում են նախորդ
 * իտերացիայի աչժեքների հետ և ստուգում որ փոքր լինի epsilion հաստատունից, 
 * բոլոր արտածվող տվյալները տպվում են exit.txt ֆայլում։
 */
void jakobs(ifstream &input, ofstream &output){
      int n = 3;
	input >> n;
	int mat[n][n+1];
	float curr[n] = {0}; 
	float prev[n] = {0};
	for (int i = 0;i < n; ++i){
                for (int j = 0;j <= n; ++j){
                        input>>mat[i][j];
			        output << mat[i][j] << ' ';
			}               
                output<<endl;
    }
	output<<endl;
	float maxi = 0;
	int iter = 0;
	bool for_exit = true;

	while (for_exit){
		for (int i = 0; i < n; ++i){
                        curr[i] = mat[i][n];
                        for (int j = 0; j < n; ++j){
                                if (j != i) {
                                        curr[i] -= prev[j]*mat[i][j];
                                }
                                else {
                                        continue;
                                }
                        }
                        curr[i] /= mat[i][i];
                }
		iter++;
		int count = 0;
		for (int i = 0; i < n; ++i)    {
                        maxi = curr[i] - prev [i];
                        if (abs(maxi) <= epsilon){
                                count++;
			}
                        if(count >= n){
                                for_exit = false;
			}
			else if(iter > 30){
				for_exit = false;
				output<<endl<<"Lucum chuni\n";	
			}
                        prev[i] = curr[i];
                        output<<prev[i]<<' ';
                }
		output<<endl;
	}
}	
/*test ֆունկցիան բացում է exit.txt golden.txt result.txt ֆայլերը, որոնցից
 * առաջինում գտնուվում են մեր ստացած արդյունքները, իսկ երկրորդում թեստեր
 * պատասխանները, համեմատվում են արդյունքները և կախված թե ճիշտ են կատարված,
 * համապատասխան արդյունքները լցվում են result.txt ֆայլի մեջ
 */
void test(){
	ifstream exit;
	ifstream golden;
	ofstream result;
	exit.open("exit.txt");
	golden.open("golden.txt");
	result.open("result.txt");
	float e, g;
	bool flag = true;
	while(exit>>e && golden>>g){
		if(e != g){
			result<<"Test Failed !!!"<<endl;
			flag = false;
			break;
		}
	}
	if(flag)
		result<<"Test passed succesfully ..."<<endl;
	exit.close();
	golden.close();
	result.close();
}

/*Ծրագրի սխալ աշխատանքի դեպքում համապատասխան սխալները try catch բլոկի միջոցով
 * ցույց են տրվում կոնսոլում։
 */
int main() try
{
        ifstream input;
        ofstream output;
        input.open("input.txt");
        output.open("exit.txt");
        jakobs(input,output);
        input.close();
        output.close();

        test();
        return 0;
}
catch(const char* ex){
  std::cerr << ex << std::endl;
}
catch(...){
        std::cerr << "exception()" << std::endl;
}
