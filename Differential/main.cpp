/*
 Copyright By Sudiro
 at Sudiro@mail.ugm.ac.id
  
 Homework of Numerical Method Course
 Lecturer: Mrs. Eny Sukani Rahayu., M. Eng
*/

#include "differential.hpp"

int counterFDD, counterCDD, counterBDD;

int main(){
	double y=2;
	double delta = 0.25;
	vector<double> F=(masukan_vector<double>(),2.0,0.0,0.0,1.0);
	fungsi FF(F, y, delta);
	FF.pNilaiFungsiAsli();
	FF.pTurunanAnalitik();

	FF.pBDD();
	FF.pCDD();
	FF.pFDD();
	counterFDD = counterCDD = counterBDD = 0;
	do{ 
		if(FF.RTE().rteFDD >= 0.01)
			counterFDD ++;
		cout << counterFDD ++ << "\t"; 
		FF.pFDD(); 
		counterFDD ++;
		FF.DEL /= 2.0;
		FF.pRTE('f');
	}while(FF.RTE().rteFDD >= 0.01);

	FF.DEL = 0.25;
	cout << endl << endl << endl;

	do{
		if(FF.RTE().rteCDD >= 0.01)
			counterCDD ++;
		cout<< counterCDD ++ << "\t"; 
		FF.pCDD(); FF.DEL /= 2.0;
		FF.pRTE('c');
	} while(FF.RTE().rteCDD >= 0.01);

	FF.DEL = 0.25; 
	cout << endl << endl << endl;

	do{
		if(FF.RTE().rteBDD >= 0.01)
			counterBDD ++;
		cout << counterBDD ++ << "\t";
		FF.pBDD(); 
		counterBDD ++;
		FF.DEL /= 2.0;
		FF.pRTE('b');
	}while(FF.RTE().rteBDD >= 0.01); 
}