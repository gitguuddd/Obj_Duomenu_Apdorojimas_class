//
// Created by Mindaugas K on 4/29/2019.
#include "../../Headers/Mutual.h"
void Stud::set_ex(){
    m_ex=m_nd.back();
    m_nd.pop_back();
    m_nd.shrink_to_fit();}
    void Stud::set_vid(int t_max){
    if(t_max!=0)
        m_vid=((double)accumulate(m_nd.begin(),m_nd.end(),0)/(double)t_max)*0.4+m_ex*0.6;
    else
        m_vid=m_ex*0.6;
m_nd.clear();}
void Stud::set_mvid(){
    sort(m_nd.begin(), m_nd.end());
    if (m_nd.size() % 2 != 0)
        m_mvid = m_nd[round((double)m_nd.size() / 2)-1 ]*0.4+m_ex*0.6;
    else
        m_mvid = ((double)(m_nd[m_nd.size() / 2 -1] + m_nd[(m_nd.size() / 2) ]) / 2)*0.4+m_ex*0.6;
    m_nd.clear();
}
Stud::Stud(const Stud& s):Humie(s.m_name,s.m_surname,s.m_nd),m_vid{s.m_vid},m_mvid{s.m_mvid},m_ex{s.m_ex}{
}
Stud& Stud::operator=(const Stud& s){
    if(&s==this)return *this;
    m_nd.reserve(s.m_nd.size());
    for(int nd: s.m_nd)
        m_nd.push_back(nd);
    m_name=s.m_name;
    m_surname=s.m_surname;
    m_ex=s.m_ex;
    m_mvid=s.m_mvid;
    m_vid=s.m_vid;
    return *this;
}
Stud::Stud(Stud&& s)noexcept:Humie(s.m_nd,s.m_name,s.m_surname),m_vid{s.m_vid},m_mvid{s.m_mvid},m_ex{s.m_ex}{
    s.m_name.clear();
    s.m_surname.clear();
    s.m_ex=0;
    s.m_mvid=0;
    s.m_vid=0;
    s.m_nd.clear();
}
Stud& Stud::operator=(Stud&& s)noexcept{
    if(&s==this)return *this;
    m_nd=move(s.m_nd);
    m_name=s.m_name;
    s.m_name.clear();
    m_surname=s.m_surname;
    s.m_surname.clear();
    m_ex=s.m_ex;
    s.m_ex=0;
    m_mvid=s.m_mvid;
    s.m_mvid=0;
    m_vid=s.m_vid;
    s.m_vid=0;
    return *this;
}
bool Stud::operator!=(const Stud &A) {
    if(v.get_pchoice()=='v')
        return m_vid!= A.get_vid();
    else
        return m_mvid!= A.get_mvid();
}
bool Stud::operator==(const Stud &A) {
    if(v.get_pchoice()=='v')
        return m_vid== A.get_vid();
    else
        return m_mvid== A.get_mvid();}
bool Stud::operator>=(const Stud &A) {
    if(v.get_pchoice()=='v')
        return m_vid>= A.get_vid();
    else
        return m_mvid>= A.get_mvid();
}
bool Stud::operator<=(const Stud &A) {
    if(v.get_pchoice()=='v')
        return m_vid<= A.get_vid();
    else
        return m_mvid<= A.get_mvid();
}
bool Stud::operator>(const Stud &A) {
    if(v.get_pchoice()=='v')
        return m_vid> A.get_vid();
    else
        return m_mvid> A.get_mvid();
}
bool Stud::operator<(const Stud &A) {
    if(v.get_pchoice()=='v')
        return m_vid< A.get_vid();
    else
        return m_mvid< A.get_mvid();
}

