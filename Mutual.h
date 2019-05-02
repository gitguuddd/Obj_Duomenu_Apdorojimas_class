//
// Created by Mindaugas K on 2/25/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#define OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <fstream>
#include <cctype>
#include <typeinfo>
#include <sstream>
#include <algorithm>
#include <numeric>
#include "./classes/stud/stud.h"
#include "./classes/Timer/Timer.h"
using std::setw;
using std::setprecision;
using std::string;
using std::cin;
using std::move;
using std::vector;
using std::deque;
using std::list;
using std::istream;
using std::stable_partition;
using namespace std::chrono;
extern char kiec;
extern Timer t;
extern char issamiai;
extern bool pap;
extern int maxname;
extern int ndcount;
extern int maxsurname;
extern int maxcount;
extern string filename;
extern string subname;
extern char pchoice;
extern char STL;
extern string msg;
extern int maxname, maxsurname, maxcount;
extern const double numb;
extern std::ofstream fv;
extern std::ofstream ft;
extern long double diff;
extern void STLpick(char &STL, bool pap);
extern void Stratpick(char &strat);
extern vector<stud> students;
extern vector<stud> minksti;
extern vector<stud> mldcstudents;
extern vector <stud> mldc;
extern vector <stud> L_laivs;
extern vector<stud>::iterator up;
extern list<stud> studentsl;
extern list<stud> mldcstudentsl;
extern list <stud> mldcl;
extern list <stud> L_laivsl;
extern list<stud>::iterator upl;
extern deque<stud> studentsd;
extern deque<stud> minkstid;
extern deque<stud> mldcstudentsd;
extern deque <stud> mldcd;
extern deque <stud> L_laivsd;
extern deque<stud>::iterator upd;
extern stud test;
extern vector<stud> raskMinkstus(vector<stud> & students, char pchoice);
extern vector<stud> raskKietus(vector<stud> & students, char pchoice);
extern deque<stud> raskMinkstusd(deque<stud> & studentsd, char pchoice);
extern deque<stud> raskKietusd(deque<stud> & studentsd, char pchoice);
extern bool non_alpha;
void Stratpick(char &strat);
template <typename T1, typename T2>
extern void handleinput( T1 &input, T2 message) {
    if(cin.fail()){
        do {
            cin.clear();
            cin.ignore(256,'\n');
            std::cout << message;
            cin >> input;
        } while (cin.fail());}
}
template <typename T1>
extern void handlename( T1 &input) {
    if(typeid(input).name()==typeid(msg).name()){
        non_alpha=std::find_if(input.begin(), input.end(),
                               [](char c) { return !std::isalpha(c); }) != input.end();
        if(non_alpha){
            printf("Aptiktas klaidingas vardas/pavarde, irasomas sablonas\n");
            input="BadInput";
        }

    }
}
template<template<class,class> class STL, class type, class Allocator>
        extern void printtofile (STL<type, Allocator>  & kontikas, char pchoice, char sar){
    (sar=='m')?filename=subname+pchoice+"_mldc.txt":filename=subname+pchoice+"_L_laivas.txt";
    fv.open(filename.c_str());
    if(pchoice == 'v'){
    fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
    fv<<"Galutinis (vid.)\n";
    fv<<"-------------------------------------------------------\n";}
    else if(pchoice == 'm'){
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
    }
    if(pchoice == 'v'){
    for(stud& stud : kontikas){
        fv<<stud.getname()<<setw(maxname+2)<<std::right<<stud.getsurname()<<setw(maxname-4+(maxname-stud.getname().length()));
        fv<<stud.getvid()<<setprecision(3)<<"\n";
    }}
    else if(pchoice == 'm'){
        for(stud& stud : kontikas){
            fv<<stud.getname()<<setw(maxname+2)<<std::right<<stud.getsurname()<<setw(maxname-4+(maxname-stud.getname().length()));
            fv<<stud.getmvid()<<setprecision(3)<<"\n";
        }
    }
    fv.close();
        }
template<template<class,class> class STL, class type, class Allocator>
        extern void calc(STL<type, Allocator> &kontikas, char pchoice){
            if(pchoice=='v'){
                maxcount = 0;
                for (stud& stud : kontikas) {
                    if (stud.getndsize() >= maxcount)
                        maxcount = stud.getndsize();
                }
                for (stud& stud : kontikas)
                    stud.setvid(maxcount);
        }
    if(pchoice=='m'){
        for (stud& stud : kontikas)
            stud.setmvid();
    }}
template<template<class,class> class STL, class type, class Allocator>
        extern void names(STL<type, Allocator> & kontikas){
    maxname = 0;
    maxsurname=0;
    maxcount = 0;
    subname=filename;
    for (stud& stud : kontikas) {
        if (stud.getname().length() >= maxname)
            maxname = stud.getname().length();
        if (stud.getsurname().length() >= maxsurname)
            maxsurname = stud.getsurname().length();
    }
    if (maxsurname <= 7)
        maxsurname = 7;
    if (maxname <= 6)
        maxname = 6;
        }
template<template<class,class> class STL, class type, class Allocator>
        extern void readfile(STL<type, Allocator> & kontikas, string filename){
    t.reset();
    std::ifstream fd((filename+".txt").c_str());
    int linecount = 1;
    int countnd;
    int tempnd;
    string tempname;
    string tempsurname;
    stud temp;
    bool fsio;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        fsio = false;
        countnd = 0;
        std::istringstream scan(line);
        scan >> tempsurname;
        temp.setsurname(tempsurname);
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento pavarde\n",filename.c_str(), linecount);
        }
        scan >> tempname;
        temp.setname(tempname);
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento varda\n",filename.c_str(), linecount);
        }
        while (scan) {
            scan >> tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("%s faile ivyko klaida nuskaitant %d studento %d pazymi\n",filename.c_str(), linecount,
                           countnd + 1);
                        temp.setnd(0);
                    countnd++;
                    if (scan.peek() != '\n'&&scan.peek() != EOF)
                        scan >> tempnd;
                    else {
                        fsio = true;
                        break;
                    }
                } while (scan.fail());

            }
            if (!fsio) {
                if (tempnd < 0 || tempnd > 10) {
                    tempnd = 0;
                }
                    temp.setnd(tempnd);
                countnd++;
            }
            if (scan.peek() == '\n' || scan.peek() == EOF)
                break;

        }
        temp.setex();
        linecount++;
        kontikas.push_back(temp);
        temp={};
    }
    fd.close();
    diff=t.elapsed();
        }
#endif //OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
