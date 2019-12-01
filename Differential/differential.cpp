/*
 Copyright By Sudiro
 at Sudiro@mail.ugm.ac.id
  
 Homework of Numerical Method Course
 Lecturer: Mrs. Eny Sukani Rahayu., M. Eng
*/

#include "differential.hpp"

fungsi::fungsi(vector<double>function, double x,double del)
	  : xx(x),DEL(del),f(function)
{
 nilaiFungsi = 0.0;
 cout << "xx " << xx << "\tDEL " << DEL << endl << endl;
 cout << "f(x) = ";
 for(int s=function.size()-1;s>=0;s--)
  {
   cout << function.at(function.size()-1-s) <<"*x^"<< s ;
    if(s!=0)
		cout <<" + ";
  }

 cout << "\nf\'(x) = ";
 for(int s=function.size()-1;s>=0;s--)
  {
   cout << function.at(function.size()-1-s)*s <<"*x^"<< s-1 ;
    if(s!=0)
		cout <<" + ";
  }
 cout << endl << endl;
}

double fungsi::TurunanAnalitik()
{
 nilaiTurunanAnalitik = 0.0;
 for(int s=f.size()-1;s>=0;s--)
    nilaiTurunanAnalitik += f.at(f.size()-1-s)*s * pow(xx,s-1);
 return nilaiTurunanAnalitik;
}

void fungsi::pTurunanAnalitik()
{
 cout << "Secara Analitik diperoleh f\'(" << xx << ") = " << this->TurunanAnalitik() << endl;
}
void fungsi::pNilaiFungsiAsli()
{
 cout << "f(" << xx <<") = " << this->nilaiFungsiAsli().tengah << endl
      << "f(" << xx - DEL <<") = " << this->nilaiFungsiAsli().bawah  << endl
      << "f(" << xx + DEL <<") = " << this->nilaiFungsiAsli().atas   << endl;
}
void fungsi::pFDD() {cout<<"FDD ---- f\'(" << xx << ") = ";printf("%.7f",this->FDD()); cout << endl;}
void fungsi::pCDD() {cout<<"CDD ---- f\'(" << xx << ") = ";printf("%.7f",this->CDD()); cout << endl;}
void fungsi::pBDD() {cout<<"BDD ---- f\'(" << xx << ") = ";printf("%.7f",this->BDD()); cout << endl;}

fungsi fungsi::nilaiFungsiAsli()
{
    this->atas = this->tengah = this->bawah = 0.0;
 for(int s=f.size()-1;s>=0;s--){
   this->atas +=     f.at(f.size()-1-s) * pow(xx + DEL,s);
   this->tengah +=   f.at(f.size()-1-s) * pow(xx,s);
   this->bawah +=    f.at(f.size()-1-s) * pow(xx - DEL,s);
    }
 return *this;
}

double fungsi::FDD()
{
 nilaiFDD = 0.0;
 nilaiFDD = (this->nilaiFungsiAsli().atas -     this->nilaiFungsiAsli().tengah)/DEL;
 return nilaiFDD;
}

double fungsi::CDD()
{
 nilaiCDD = 0.0;
 nilaiCDD = ( this->nilaiFungsiAsli().atas - this->nilaiFungsiAsli().bawah) / (2*DEL);
 return nilaiCDD;
}

double fungsi::BDD()
{ 
 nilaiBDD = 0.0;
 nilaiBDD = (this->nilaiFungsiAsli().tengah - this->nilaiFungsiAsli().bawah)/DEL;
 return nilaiBDD;
}


fungsi fungsi::RTE()
{
     this->rteFDD = this->rteCDD = this->rteBDD = 0.0;
this->rteFDD = 1 - this->FDD()/this->TurunanAnalitik();
     this->rteCDD = 1 - this->CDD()/this->TurunanAnalitik();
     this->rteBDD = 1 - this->BDD()/this->TurunanAnalitik();

     if(this->rteFDD >= 0.0)this->rteFDD=this->rteFDD; else this->rteFDD = -this->rteFDD;
     if(this->rteCDD >= 0.0)this->rteCDD=this->rteCDD; else this->rteCDD = -this->rteCDD;
     if(this->rteBDD >= 0.0)this->rteBDD=this->rteBDD; else this->rteBDD = -this->rteBDD;
     
  return *this;
}

void fungsi::pRTE(char metode)
{

 switch(metode){
     case 'f' : printf("FDD ---- RTE = %.7f\n",this->RTE().rteFDD); break;
     case 'c' : printf("CDD ---- RTE = %.7f\n",this->RTE().rteCDD); break;
     case 'b' : printf("BDD ---- RTE = %.7f\n",this->RTE().rteBDD); break;
    }
}