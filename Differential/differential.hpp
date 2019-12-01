/*
 Copyright By Sudiro
 at Sudiro@mail.ugm.ac.id

 Homework of Numerical Method Course
 Lecturer: Mrs. Eny Sukani Rahayu., M. Eng
*/

#ifndef DIFFERENTIAL_HPP
#define DIFFERENTIAL_HPP

#include <vector>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

class fungsi{
 public:
  double rteFDD, rteCDD, rteBDD;
  double DEL;

  fungsi(vector<double>function, double x,double del);
  vector<double> f;
  double TurunanAnalitik(); 
  fungsi nilaiFungsiAsli();
  double FDD();
  double CDD();
  double BDD();
  void pFDD();
  void pCDD();
  void pBDD();
  void pTurunanAnalitik();
  void pNilaiFungsiAsli();
  fungsi RTE();
  void pRTE(char metode);
  
 private:
 double nilaiFungsi;
 double nilaiTurunanAnalitik;
 double xx;
 double nilaiFDD;
 double nilaiCDD;
 double nilaiBDD;
 double atas,tengah,bawah;
 
};

	
template <typename T>
class masukan_vector {
public:
  typedef masukan_vector<T> tipe;
  tipe& operator , (const T& nilai) {
    data_.push_back(nilai);
    return *this;
  }
  operator vector<T>() const {
    return data_;
  }
private:
  vector<T> data_;
};
#endif
