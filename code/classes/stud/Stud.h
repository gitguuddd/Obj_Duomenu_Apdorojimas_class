//
// Created by Mindaugas K on 4/29/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_STUD_H
#define OBJ_DUOMENU_APDOROJIMAS_STUD_H

#include <vector>
#include <string>
#include <iomanip>
#include "../Humie/Humie.h"
#include "classes/ImportantValues/Important_Values.h"
using std::string;
using std::vector;
using std::setw;
using std::setprecision;
class Stud:public Humie{
private:
    int m_ex;
    double m_mvid;
    double m_vid;
public:
    void f() override{};
    Stud():m_ex(0), m_mvid(4.999999999), m_vid(4.999999999){};
    Stud(double t_vid, double t_mvid):m_ex(0), m_mvid(t_mvid), m_vid(t_vid){};
    Stud(const Stud& s);
    Stud& operator=(const Stud& s);
    Stud(Stud&& s)noexcept;
    Stud& operator=(Stud&& s)noexcept;
    inline void set_ex(int t_ex){m_ex=t_ex;}
    void set_ex();
    void set_vid(int t_max);
    void set_mvid();
    inline int get_ex() const {return m_ex;}
    inline double get_mvid() const {return m_mvid;}
    inline double get_vid() const {return m_vid;}
    bool operator==(const Stud& A);
    bool operator<=(const Stud& A);
    bool operator>=(const Stud& A);
    bool operator!=(const Stud& A);
    bool operator>(const Stud& A);
    bool operator<(const Stud& A);
    friend istringstream& operator>>(std::istringstream& t_scan, Stud &temp) {
        temp.scan_surname(t_scan);
        if (t_scan.fail()) {
            t_scan.clear();
            t_scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento pavarde\n", v.get_file_name().c_str(), v.line_count);
        }
        temp.scan_name(t_scan);
        if (t_scan.fail()) {
            t_scan.clear();
            t_scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento varda\n", v.get_file_name().c_str(), v.line_count);
        }
        while (t_scan) {
            t_scan >> v.temp_nd;
            if (t_scan.fail()) {
                do {
                    t_scan.clear();
                    t_scan.ignore(4);
                    printf("%s faile ivyko klaida nuskaitant %d studento %d pazymi\n", v.get_file_name().c_str(),
                           v.line_count,
                           v.count_nd + 1);
                    v.count_nd++;
                    temp.set_nd(0);
                    if (t_scan.peek() != '\n' && t_scan.peek() != EOF)
                        t_scan >> v.temp_nd;
                    else {
                        v.fsio = true;
                        break;
                    }
                } while (t_scan.fail());

            }
            if (!v.fsio) {
                if (v.temp_nd < 0 || v.temp_nd > 10) {
                    v.temp_nd = 0;
                }
                temp.set_nd(v.temp_nd);
                v.count_nd++;
            }
            if (t_scan.peek() == '\n' || t_scan.peek() == EOF)
                break;

        }
    }
    template<template<class,class> class STL, class type, class Allocator>
    friend std::ostream& operator<<(std::ostream& t_fv,  STL<type, Allocator>  &t_kontikas){
        if(v.get_pchoice()== 'v'){
            t_fv<<"Vardas"<<setw(v.get_max_name()+2)<<"Pavarde"<<setw(v.get_max_name()+ v.get_max_surname()+14);
            t_fv<<"Galutinis (vid.)\n";
            t_fv<<"-------------------------------------------------------\n";}
        else if(v.get_pchoice()== 'm'){
            t_fv<<"Vardas"<<setw(v.get_max_name()+2)<<"Pavarde"<<setw(v.get_max_name()+ v.get_max_surname()+14);
            t_fv<<"Galutinis (med.)\n";
            t_fv<<"-------------------------------------------------------\n";
        }
        if(v.get_pchoice()== 'v'){
            for(Stud& stud : t_kontikas){
                t_fv<< stud.get_name()<<setw(v.get_max_name()+2)<<std::right<< stud.get_surname()<<setw(
                        v.get_max_name()-4+(v.get_max_name()-stud.get_name().length())+3);
                t_fv<< stud.get_vid()<<setprecision(3)<<"\n";
            }}
        else if(v.get_pchoice() == 'm'){
            for(Stud& stud : t_kontikas){
                t_fv<< stud.get_name()<<setw(v.get_max_name()+2)<<std::right<< stud.get_surname()<<setw(v.get_max_name()-4+(v.get_max_name()-
                                                                                                                 stud.get_name().length())+3);
                t_fv<< stud.get_mvid()<<setprecision(3)<<"\n";
            }
        }
    }

};
struct less_than_mvid{
    bool operator()(const  Stud & a, const Stud & b){
        return a.get_mvid()< b.get_mvid();
    }
};
struct less_than_vid {
    bool operator()(const  Stud & a, const Stud & b){
        return a.get_vid()< b.get_vid();
    }
};
#endif //OBJ_DUOMENU_APDOROJIMAS_STUD_H
