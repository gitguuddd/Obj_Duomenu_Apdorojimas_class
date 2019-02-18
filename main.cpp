#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <vector>
using std::string;
using std::cin;
using std::vector;
struct stud {
    string name;
    string surname;
    vector<int> nd;
    int ex;
    double vid;
    double med;
    double mvid;
    double vid2;
    int sum=0;
};
stud Userinput(){
    stud student;
    int nd=1;
    printf("Iveskite studento varda\n");
    cin>>student.name;
    printf("Iveskite studento pavarde\n");
    cin>>student.surname;
    printf("Iveskite studento egzamino ivertinima\n");
    cin>>student.ex;
    while(nd!=-1){
        printf("Iveskite studento namu darbu pazymius, skaiciaus -1 ivestis uzbaigia ivesti\n");
        cin>>nd;
        if(nd>=0&&nd<11){
            student.sum+=nd;
            student.nd.push_back(nd);}
        else if(nd>10||nd<-1)
            printf("\n Ivesta netinkama reiksme, teskite pildyma ivesdami skaiciu is intervalo [0;10] arba iveskite -1 (baigti) \n");

    }
    //TODO: exception handling, ALL INPUTS
return student;
}
stud GenStudent(){
    stud student;
    int nd=1;
    int num=(double)rand()/RAND_MAX*1000000;
    student.name="Vardas" + std::to_string(num);
    printf("Studento vardas: %s\n",student.name.c_str());
    student.surname="Pavarde" + std::to_string(num);
    printf("Studento pavarde: %s\n",student.surname.c_str());
    student.ex=(double)rand()/RAND_MAX*11;
    printf("Studento egzamino ivertinimas: %d \n",student.ex);
    while(nd!=0){
        printf("Iveskite bet koki  skaiciu, kad sugeneruotumete pazymi,  skaiciaus 0 ivestis uzbaigia ivesti\n");
        cin>>nd;//TODO: exception handling
        int temp=nd;
        nd=(double)rand()/RAND_MAX*11;
        printf("Sugeneruotas pazymys: %d\n",nd);
        student.sum+=nd;
        student.nd.push_back(nd);
        nd=temp;


    }
    return student;

}
void print(vector<stud>students, char type){
    int maxname=0,maxsurname=0,maxcount=0;
    for(int i=0;i<students.size();i++){
        if (students[i].name.length()>=maxname)
            maxname=students[i].name.length();
        if (students[i].surname.length()>=maxsurname)
            maxsurname=students[i].surname.length();}
    if(maxsurname<=7)
        maxsurname=7;
        if(maxname<=6)
            maxname=6;
if(type=='v'){
    maxcount=0;
    for(int i=0;i<students.size();i++){
        if(students[i].nd.size()>=maxcount)
            maxcount=students[i].nd.size();
    }
    for(int i=0;i<students.size();i++){
        if (maxcount!=0)
            students[i].vid=(double)students[i].sum/(double)maxcount;
        else students[i].vid=0;
        students[i].vid2=students[i].vid*0.4+students[i].ex*0.6;
        }
    }
if(type=='m'){
    for (int i=0;i<students.size();i++){
        if(students[i].nd.size()!=0)
        sort(students[i].nd.begin(),students[i].nd.end());
    if(students[i].nd.size()/2==0)
        students[i].med=students[i].nd[students[i].nd.size()/2];
    else
        students[i].med=(students[i].nd[students[i].nd.size()/2]+students[i].nd[(students[i].nd.size()/2)+1])/2;
    students[i].mvid=students[i].med*0.4+students[i].ex*0.6;

}}
    if (type=='m'){
        printf("Pavarde%*cVardas%*cGalutinis (Med.)\n",maxsurname-6,' ',maxname-5,' ');
        printf("%s\n",(string(29+maxsurname-7+maxname-6,'-')).c_str());
        for(int i=0;i<students.size();i++){
        printf("%s%*c%s%*c%.2lf\n", students[i].surname.c_str(), maxsurname-students[i].surname.length()+1,' ', students[i].name.c_str(),
               maxname-students[i].name.length()+1,' ', students[i].mvid);
    }}
    if(type=='v'){
        printf("Pavarde%*cVardas%*cGalutinis (Vid.)\n", maxsurname-6, ' ', maxname-5, ' ');
        printf("%s\n",(string(29+maxsurname-7+maxname-6,'-')).c_str());
        for(int i=0;i<students.size();i++) {
            printf("%s%*c%s%*c%.2lf\n", students[i].surname.c_str(), maxsurname-students[i].surname.length()+1,' ', students[i].name.c_str(),
                   maxname-students[i].name.length()+1,' ', students[i].vid2);
        }
        }
    }
int main() {
    srand((unsigned int)time(nullptr));
    int choice=0;
    vector<stud> students;
    while(choice==0){
        printf("Saugomi %d studentu(o) duomenys, pasirinkite ka daryti toliau:\n",students.size());
        printf("1. Ivesti studenta paciam\n");
        printf("2. Generuoti studenta\n");
        printf("3. Atspausdinti (galutinis pagal nd mediana)\n");
        printf("4. Atspausdinti (galutinis pagal nd vidurki)\n");
        cin>>choice;
        switch(choice){
            case 1:
                students.push_back(Userinput());
                choice=0;
                break;
            case 2:
                students.push_back(GenStudent());
                choice=0;
                break;
            case 3:
                if(students.size()==0){
                    goto LINEKAPUT;//You found an easter egg xd
                    }
                print(students,'m');
                break;
            case 4:
                if(students.size()==0){
                    goto LINEKAPUT;
                }
                print(students,'v');
                break;
                LINEKAPUT:
            default:
                printf("Pasirinkote neegzistuojanti pasirinkima/bandote atspausdinti tuscia vektoriu :(, bandykite is naujo\n");
                choice=0;
        }

    }
    return 0;}
