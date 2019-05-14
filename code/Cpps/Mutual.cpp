//
// Created by Mindaugas K on 2/25/2019.
//

#include "../Headers/Mutual.h"
#include "classes/ImportantValues/Important_Values.h"
vector<Stud> students;
vector<Stud> minksti;
vector<Stud>mldc_students;
vector <Stud> mldc;
vector <Stud> L_laivs;
list<Stud> students_l;
list<Stud> mldc_students_l;
list <Stud> mldc_l;
list <Stud> L_laivsl;
deque<Stud> students_d;
deque<Stud> minksti_d;
deque<Stud> mldc_students_d;
deque <Stud> mldc_d;
deque <Stud> L_laivs_d;
Stud test;
bool non_alpha;
std::ofstream fv;
std::ofstream ft;
Timer t;
long double diff;
void handle_nd(string t_message) {
    if(cin.fail()){
        do {
            cin.clear();
            cin.ignore(256,'\n');
            std::cout << t_message;
            v.set_nd_count();
        } while (cin.fail());}
}
void t_STL_pick(bool t_pap){
    if(t_pap==false){
    printf("Su kuriuo STL konteineriu norite dirbti ? [d]eque/[v]ector/[l]ist\n");
        v.set_STL();
    while(v.get_STL()!='d'&& v.get_STL()!='v'&& v.get_STL()!='l'){
        printf("Netinkama ivestis, bandykite is naujo\n");
        v.set_STL();
    }}
    else if(t_pap==true){
        printf("Su kuriuo STL konteineriu norite dirbti ? [d]eque/[v]ector\n");
        v.set_STL();
        while(v.get_STL()!='d'&& v.get_STL()!='v'){
            printf("Netinkama ivestis, bandykite is naujo\n");
            v.set_STL();
        }
    }
}
void t_strat_pick(){
    printf("Kuria skelimo strategija naudosite noredami perskelti studentus?\n");
    printf(" [a] - sukurti du naujus STL'us ir i juos atrinkti tinkamus studentus\n");
    printf(" [b] - sukurti viena nauja STL'a, sename STL'e istrinti naujame STL'e esancius studentus\n");
    printf(" [c] - isrikiuoti studentus, rasti iteratoriu i (i>=5), naudojant iteratoriu sukurti nauja STL'a\n");
    printf(" [d] - dirbti su papildomos uzduoties siulomais sprendimais\n");
    v.set_strat();
    while(v.get_strat()!='a'&& v.get_strat()!='b'&& v.get_strat()!='c'&& v.get_strat()!='d'){
        printf("Netinkama ivestis, bandykite is naujo - a, b, c arba d\n");
        v.set_strat();
    }
}
bool t_gavo_skola(const Stud t_student1, char t_pchoice){
    if(t_pchoice=='v'){
        if(t_student1.get_vid()< 4.99999999)
            return true;
        else if(t_student1.get_vid()>4.999999999)
            return false;
        else if(t_student1.get_vid()==4.999999999)
            return false;
    }
    else if(t_pchoice=='m'){
        if(t_student1.get_mvid()<4.99999999){
            return true;
        }
        else if(t_student1.get_mvid()>4.9999999){
            return false;
        }
        else if (t_student1.get_mvid()==4.999999)
            return false;
    }
}
vector<Stud> rask_Minkstus(vector<Stud> &t_students, char t_pchoice){
    t.reset();
    vector<Stud> minksti;
    vector<Stud>::size_type i = 0;
    while (i != t_students.size()) {
        if (t_gavo_skola(t_students[i], t_pchoice)) {
            minksti.push_back(t_students[i]);
            t_students.erase(t_students.begin() + i);
        } else
            ++i;
    }
    diff=t.elapsed();
    return minksti;
}
deque<Stud> rask_Minkstus_d(deque<Stud> &t_students_d, char t_pchoice){
    t.reset();
    deque<Stud> minksti;
    deque<Stud>::size_type i = 0;
    while (i != t_students_d.size()) {
        if (t_gavo_skola(t_students_d[i], t_pchoice)) {
            minksti.push_back(t_students_d[i]);
            t_students_d.erase(t_students_d.begin() + i);
        } else
            ++i;
    }
    diff=t.elapsed();
    return minksti;
}
deque<Stud> rask_Kietus_d(deque<Stud> &t_students_d, char t_pchoice){
    t.reset();
    deque<Stud> minksti;
    deque<Stud>::size_type i = 0;
    int dydis= t_students_d.size();

    while (i != t_students_d.size()) {
        if (t_gavo_skola(t_students_d[i], t_pchoice)) {
            minksti.push_back(t_students_d[i]);
            ++i;
        } else if(!t_gavo_skola(t_students_d[i], t_pchoice)){
            t_students_d.insert(t_students_d.begin(),t_students_d[i]);
            i=i+2;
        }
    }
    t_students_d.resize((t_students_d.size()-dydis));
    t_students_d.shrink_to_fit();
    diff=t.elapsed();
    return minksti;
}
vector<Stud> rask_Kietus(vector<Stud> &t_students, char t_pchoice){
    t.reset();
    vector<Stud> minksti;
    vector<Stud>::size_type i = 0;
    int dydis=t_students.size();
 while (i != t_students.size()) {
        if (t_gavo_skola(t_students[i], t_pchoice)) {
            minksti.push_back(t_students[i]);
            ++i;
        } else if(!t_gavo_skola(t_students[i], t_pchoice)){
            t_students.insert(t_students.begin(),t_students[i]);
            i=i+2;
        }
    }
    t_students.resize((t_students.size()-dydis));
    t_students.shrink_to_fit();
    diff=t.elapsed();
    return minksti;
}
