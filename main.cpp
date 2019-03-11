#include "Mutual.h"
#include "Input.h"
#include "Output.h"
int main() {
    int choice=0;
    int specchoice =-1;
    int printfail=0;
    int readcount=0;
    int gencount=0;
    bool isempty=false;
    students.reserve(100);
    while (choice == 0 || choice == 5 || choice == 4) {
        if (specchoice == -1) {
            printf("Saugomi %d studentu(o) duomenys, pasirinkite ka daryti toliau:\n", students.size());
            printf("1. Ivesti studenta paciam\n");
            printf("2. Generuoti studenta\n");
            printf("3. Skaityti is failo\n");
            printf("4. Atspausdinti (galutinis pagal nd mediana)\n");
            printf("5. Atspausdinti (galutinis pagal nd vidurki)\n");
            printf("6. Generuoti studentu faila (v0.4)\n");
            printf("7. Skelti studentus i maladec ir L-laivo sarasus, atspausdinti\n");
            cin >> choice;
            if (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=7) {
                do {
                    cin.clear();
                    cin.ignore(256,'\n');
                    printf("Ivestas netinkamas pasirinkimas, bandykite is naujo\n");
                    cin >> choice;
                } while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=7);

            }
        }
        switch (choice) {
            case 1:
                try{
                students.push_back(Userinput());}
                catch(std::exception e){
                    printf("Perzengtos studentu vektoriaus ribos\n");
                }
                choice = 0;
                break;
            case 2:
                try{
                students.push_back(GenStudent());}
                catch(std::exception e){
                    printf("Perzengtos studentu vektoriaus riblos\n");
                }
                choice = 0;
                break;
            case 3:
                if (readcount == 0) {
                    readfile(isempty, readcount);
                }
                else
                    printfail=3;
                choice = 0;
                if (isempty)
                    printfail=32;
                    specchoice = 0;
                break;
            case 4:
                if (students.empty()) {
                    specchoice = 0;
                    choice = 0;
                    printfail=4;
                    break;
                }
                else {
                    sort(students.begin(), students.end(), sorting);
                    print(students, 'm');
                    choice = -1;
                    break;
                }
            case 5:
                if (students.empty()) {
                    specchoice = 0;
                    printfail=4;
                    choice = 0;
                    break;
                }
                else {
                    sort(students.begin(), students.end(), sorting);
                    print(students, 'v');
                    choice = -1;
                    break;
                }
            case 6:
                if(gencount==0){
                    ft.open("V0.4_laikai.txt");
                    for(int i=1;i<=6;i++){
                        students.clear();
                        mldcstudents.clear();
                        ft<<int(round(pow(10,i)))<<"studentu\n";
                        ft<<"--------------------------------\n";
                    Genstudent(i);
                    ft<<"Studentai sugeneruoti ir isvesti i faila per "<<diff.count()<<" s.\n";
                    readfile(filename);
                    ft<<"Studentai nuskaityti is failo  "<<filename<<" per "<<diff.count()<<" s.\n";
                    printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",filename.c_str());
                    cin>>pchoice;
                    while(pchoice!='v'&&pchoice!='m'){
                        printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                        cin>>pchoice;
                    }
                        printf("Talpa - %d\n",students.capacity());
                    splitnprint(filename,pchoice);
                    ft<<"Studentai perskelti i mldc ir L_laivo sarasus, bei atspausdinti atitinkamuose failuose per "<<diff.count()<<" s.\n";
                    ft<<"--------------------------------\n";
                    }
                    ft.close();
                    mldcstudents.clear();
                    students.clear();
                    gencount++;
                choice=0;
                break;}
                else{
                    specchoice = 0;
                    printfail=5;
                    choice = 0;
                    break;
                }
            case 7:
                if (students.empty()) {
                    specchoice = 0;
                    choice = 0;
                    printfail=4;
                    break;
                }
                else {
                    filename=std::to_string(students.size())+"kursioku";
                    printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",filename.c_str());
                    cin>>pchoice;
                    while(pchoice!='v'&&pchoice!='m'){
                        printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                        cin>>pchoice;
                    }
                    splitnprint(filename,pchoice);
                    choice = -1;
                    break;
                }
            default:
                switch(printfail){
                    case 3:
                        printf("Sis failas jau buvo nuskaitytas\n");
                        break;
                    case 32:
                        printf("Failas tuscias arba neegzistuoja\n");
                        break;
                    case 4:
                        printf("Bandote atspausdinti tuscia sarasa\n");
                        break;
                    
                }
                specchoice = -1;
                choice = 0;
                printfail=0;
        }
    }
    return 0;
}