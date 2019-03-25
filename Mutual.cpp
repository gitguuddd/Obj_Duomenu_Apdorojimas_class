//
// Created by Mindaugas K on 2/25/2019.
//

#include "Mutual.h"
vector<stud> students;
vector<stud>mldcstudents;
vector <stud> mldc;
vector <stud> L_laivs;
list<stud> studentsl;
list<stud> mldcstudentsl;
list <stud> mldcl;
list <stud> L_laivsl;
deque<stud> studentsd;
deque<stud> mldcstudentsd;
deque <stud> mldcd;
deque <stud> L_laivsd;
stud test;
string filename;
string subname;
string msg;
std::ofstream fv;
std::ofstream ft;
char pchoice;
int maxname, maxsurname, maxcount;
high_resolution_clock::time_point start;
high_resolution_clock::time_point end;
duration<long double> diff;
void STLpick(char &STL, int & ind){
    printf("Su kuriuo STL konteineriu norite dirbti ? [d]eque/[v]ector/[l]ist\n");
    cin>>STL;
    while(STL!='d'&&STL!='v'&&STL!='l'){
        printf("Netinkama ivestis, bandykite is naujo\n");
        cin>>STL;
    }
    (STL=='v')?ind=6:
    (STL=='d')?ind=6:
            ind=6;
}
void Stratpick(char &strat){
    printf("Kuria skelimo strategija naudosite noredami perskelti studentus?\n");
    printf(" [a] - sukurti du naujus STL'us ir i juos atrinkti tinkamus studentus\n");
    printf(" [b] - sukurti viena nauja STL'a, sename STL'e istrinti naujame STL'e esancius studentus\n");
    printf(" [c] - isrikiuoti studentus, rasti iteratoriu i (i>=5), naudojant iteratoriu sukurti nauja STL'a\n");
    cin>>strat;
    while(strat!='a'&&strat!='b'&&strat!='c'){
        printf("Netinkama ivestis, bandykite is naujo - a, b arba c\n");
        cin>>strat;
    }
}