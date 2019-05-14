//
// Created by Mindaugas K on 5/2/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_MAXVALUES_H
#define OBJ_DUOMENU_APDOROJIMAS_MAXVALUES_H
#include <vector>
#include "iostream"
using std::string;
using std::vector;
class Important_Values{
private:
     int m_name_num;
     int m_gen_size;
     int m_num;
     int m_max_name;
     int m_nd_count;
     int m_max_surname;
     int m_max_count;
     char m_kiec;
     char m_issamiai;
     bool m_pap;
     string m_file_name;
     string m_subname;
     char m_pchoice;
     char m_STL;
     char m_sar;
     char m_strat;
     string m_msg;
     long double m_diff;
public:
    //setters
    inline void set_name_num(int t_namenum){
        m_name_num=t_namenum;
    }
    inline void set_gen_size(int t_gensize){
        m_gen_size=t_gensize;
    };
    inline void set_num(int t_num){
        m_num=t_num;
    }
    inline void set_max_name(int t_maxname){
        m_max_name=t_maxname;
    }
    inline void set_max_surname(int t_nd_count){
        m_nd_count=t_nd_count;
    }
    inline void set_nd_count(){
        std::cin>>m_nd_count;
    }
    inline void set_max_count(int t_max_count){
        m_max_count=t_max_count;
    }
    inline void set_kiec(){
        std::cin>>m_kiec;
    }
    inline void set_issamiai(){
        std::cin>>m_issamiai;
    }
    inline void set_pchoice(){
        std::cin>>m_pchoice;
    }
    inline void set_pchoice(char t_choice){
        m_pchoice=t_choice;
    }
    inline void set_sar(char t_sar){
        m_sar=t_sar;
    }
    inline void set_STL(){
        std::cin>>m_STL;
    }
    inline void set_strat(){
        std::cin>>m_strat;
    }
    inline void set_strat2(char t_strat){
        m_strat=t_strat;
    }
    inline void set_pap(bool t_pap){
        m_pap=t_pap;
    }
    inline void set_file_name(string t_file_name){
        m_file_name=t_file_name;
    }
    inline void set_subname(string t_subname){
        m_subname=t_subname;
    }
    inline void set_msg(string t_msg){
        m_msg=t_msg;
    }
    inline void set_diff(long double t_diff){
        m_diff=t_diff;}
    //getters
    inline int get_name_num(){return m_name_num;}
    inline int get_gen_size(){return m_gen_size;}
    inline int get_num(){return m_num;}
    inline int get_max_name(){return m_max_name;}
    inline int get_max_surname(){return m_max_surname;}
    inline int get_nd_count(){
        return m_nd_count;}
    inline int get_max_count(){return m_max_count;}
    inline char get_kiec(){return m_kiec;}
    inline char get_issamiai(){return m_issamiai;}
    inline char get_pchoice(){return m_pchoice;}
    inline char get_STL(){return m_STL;}
    inline bool get_pap(){return m_pap;}
    inline char get_sar(){return m_sar;}
    inline char get_strat(){return m_strat;}
    inline string get_file_name(){return m_file_name;}
    inline string get_subname(){return m_subname;}
    inline string get_msg(){return m_msg;}
    inline long double get_diff(){return m_diff;}
    //for input
    int line_count = 1;
    int count_nd;
    int temp_nd;
    bool fsio;;
};
extern Important_Values v;

#endif //OBJ_DUOMENU_APDOROJIMAS_MAXVALUES_H
