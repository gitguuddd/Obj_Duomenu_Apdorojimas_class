
// Created by Mindaugas K on 2/25/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#define OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#include "../../code/classes/Timer/Timer.h"
#include "classes/ImportantValues/Important_Values.h"
#include "classes/stud/Stud.h"
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
extern Timer t;
extern std::ofstream fv;
extern std::ofstream ft;
extern void t_STL_pick(bool t_pap);
extern void t_strat_pick();
extern vector<Stud> students;
extern vector<Stud> minksti;
extern vector<Stud> mldc_students;
extern vector <Stud> mldc;
extern vector <Stud> L_laivs;
extern vector<Stud>::iterator up;
extern list<Stud> students_l;
extern list<Stud> mldc_students_l;
extern list <Stud> mldc_l;
extern list <Stud> L_laivsl;
extern list<Stud>::iterator up_l;
extern deque<Stud> students_d;
extern deque<Stud> minksti_d;
extern deque<Stud> mldc_students_d;
extern deque <Stud> mldc_d;
extern deque <Stud> L_laivsd;
extern deque<Stud>::iterator up_d;
extern Stud test;
extern vector<Stud> rask_Minkstus(vector<Stud> &t_students, char t_pchoice);
extern vector<Stud> rask_Kietus(vector<Stud> &t_students, char t_pchoice);
extern deque<Stud> rask_Minkstus_d(deque<Stud> &t_students_d, char t_pchoice);
extern deque<Stud> rask_Kietus_d(deque<Stud> &t_students_d, char t_pchoice);
extern bool non_alpha;
void Strat_pick(char &t_strat);
extern void handle_nd(string t_message);
template <typename T1, typename T2>
extern void handle_input(T1 &t_input, T2 t_message) {
    if(cin.fail()){
        do {
            cin.clear();
            cin.ignore(256,'\n');
            std::cout << t_message;
            cin>>t_input;
        } while (cin.fail());}
}
template <typename T1>
extern void handle_name(T1 &t_input) {
    if(typeid(t_input).name()==typeid(v.get_msg()).name()){
        non_alpha=std::find_if(t_input.begin(), t_input.end(),
                               [](char c) { return !std::isalpha(c); }) != t_input.end();
        if(non_alpha){
            printf("Aptiktas klaidingas vardas/pavarde, irasomas sablonas\n");
            t_input="BadInput";
        }

    }
}
template<template<class,class> class STL, class type, class Allocator>
        extern void print_to_file(STL<type, Allocator> &t_kontikas, char t_pchoice, char t_sar){
    (t_sar=='m')? v.set_file_name(v.get_subname() + t_pchoice + "_mldc.txt"): v.set_file_name(
            v.get_subname() + t_pchoice + "_L_laivas.txt");
    fv.open(v.get_file_name().c_str());
    fv<<t_kontikas;
    fv.close();
        }
template<template<class,class> class STL, class type, class Allocator>
        extern void calc(STL<type, Allocator> &t_kontikas, char t_pchoice){
            if(t_pchoice=='v'){
                v.set_max_count(0);
                for (Stud& stud : t_kontikas) {
                    if (stud.get_ndsize() >= v.get_max_count())
                        v.set_max_count(stud.get_ndsize());
                }
                for (Stud& stud : t_kontikas)
                    stud.set_vid(v.get_max_count());
        }
    if(t_pchoice=='m'){
        for (Stud& stud : t_kontikas)
            stud.set_mvid();
    }}
template<template<class,class> class STL, class type, class Allocator>
        extern void names(STL<type, Allocator> & t_kontikas){
    v.set_max_name(0);
    v.set_max_surname(0);
    v.set_max_count(0);
    v.set_subname(v.get_file_name());
    for (Stud& stud : t_kontikas) {
        if (stud.get_name().length() >= v.get_max_name())
            v.set_max_name(stud.get_name().length());
        if (stud.get_surname().length() >= v.get_max_surname())
            v.set_max_surname(stud.get_surname().length());
    }
    if (v.get_max_surname() <= 7)
        v.set_max_surname(7);
    if (v.get_max_name() <= 6)
        v.set_max_name(6);
        }
template<template<class,class> class STL, class type, class Allocator>
        extern void read_file(STL<type, Allocator> &t_kontikas, string t_file_name){
    t.reset();
    std::ifstream fd((t_file_name+".txt").c_str());
    v.line_count=0;
    Stud temp;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        v.fsio = false;
        v.count_nd = 0;
        std::istringstream scan(line);
        scan>>temp;
        temp.set_ex();
        v.line_count++;
        t_kontikas.push_back(temp);
        temp={};
    }
    fd.close();
    v.set_diff(t.elapsed());
        };
#endif //OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
