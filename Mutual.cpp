//
// Created by Mindaugas K on 2/25/2019.
//

#include "Mutual.h"
vector<stud> students;
vector<stud>mldcstudents;
list<stud> studentsl;
list<stud> mldcstudentsl;
deque<stud> studentsd;
deque<stud> mldcstudentsd;
stud test;
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
            ind=4;
}