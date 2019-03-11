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
#include <fstream>
#include <sstream>
#include <algorithm>
using std::setw;
using std::setprecision;
using std::string;
using std::cin;
using std::vector;
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

extern vector<stud> students;
extern vector<stud> mldcstudents;
extern stud test;
extern vector<stud>::iterator up;

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
