//
// Created by Mindaugas K on 5/2/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_HUMIE_H
#define OBJ_DUOMENU_APDOROJIMAS_HUMIE_H
#include <vector>
#include <sstream>
using std::vector;
using std::istringstream;
using std::string;
using std::iostream;
class Humie{
protected:
    string m_name;
    int m_tempnd;
    string m_surname;
    vector<int> m_nd;
    Humie():m_name("Vardas"),m_surname("Pavarde"){m_nd.reserve(200);}
    Humie(string t_name, string t_surname, vector<int> t_nd):m_name(t_name),m_surname(t_surname),m_nd(t_nd){}
    Humie(vector<int> t_nd2,string t_name, string t_surname):m_name(t_name),m_surname(t_surname){
        m_nd=std::move(t_nd2);
    }
public:
    virtual void f() = 0;
    void scan_name(istringstream &t_stream);
    void scan_surname(istringstream &t_stream);
    inline void set_name(string t_name){m_name=move(t_name);}
    inline void set_surname(string t_surname){m_surname=move(t_surname);}
    inline void set_nd(int t_nd){m_nd.push_back(t_nd);}
    inline void push_b(){m_nd.pop_back();}
    inline string get_name() const {return m_name;}
    inline string get_surname() const {return m_surname;}
    inline int get_ndsize() const {return m_nd.size();}

};
#endif //OBJ_DUOMENU_APDOROJIMAS_HUMIE_H
