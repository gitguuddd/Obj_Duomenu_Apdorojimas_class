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
#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::setw;
using std::setprecision;
using std::string;
using std::cin;
using std::vector;
using std::deque;
using std::list;
using namespace std::chrono;
extern char pchoice;
extern string msg;
extern int maxname, maxsurname, maxcount;
extern const double numb;
extern std::ofstream fv;
extern std::ofstream ft;
extern high_resolution_clock::time_point start;
extern high_resolution_clock::time_point end;
extern duration<long double> diff;
struct stud {
    string name;
    string surname;
    vector<int> nd;
    int ex;
    double vid;
    double med;
    double mvid;
    double vid2;
    int sum = 0;
    struct less_than_vid2{
        bool operator()(const  stud & a, const stud & b){
            return a.vid2<b.vid2;

        }
    };
    struct less_than_mvid{
        bool operator()(const  stud & a, const stud & b){
            return a.mvid<b.mvid;
        }
    };
};
extern void STLpick(char &STL, int & ind);
extern vector<stud> students;
extern vector<stud> mldcstudents;
extern vector<stud>::iterator up;
extern list<stud> studentsl;
extern list<stud> mldcstudentsl;
extern list<stud>::iterator upl;
extern deque<stud> studentsd;
extern deque<stud> mldcstudentsd;
extern deque<stud>::iterator upd;
extern stud test;

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

#endif //OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
