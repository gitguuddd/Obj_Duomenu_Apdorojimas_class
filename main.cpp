#include "Mutual.h"
#include "Input.h"
#include "Output.h"
int main() {
    students.reserve(100);
    int choice = 0;
    bool isempty = false;
    int readcount = 0;
    int printfail=0;
    int specchoice = -1;
    while (choice == 0 || choice == 5 || choice == 4) {
        if (specchoice == -1) {
            printf("Saugomi %d studentu(o) duomenys, pasirinkite ka daryti toliau:\n", students.size());
            printf("1. Ivesti studenta paciam\n");
            printf("2. Generuoti studenta\n");
            printf("3. Skaityti is failo\n");
            printf("4. Atspausdinti (galutinis pagal nd mediana)\n");
            printf("5. Atspausdinti (galutinis pagal nd vidurki)\n");
            cin >> choice;
            if (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5) {
                do {
                    cin.clear();
                    cin.ignore(256,'\n');
                    printf("Ivestas netinkamas pasirinkimas, bandykite is naujo\n");
                    cin >> choice;
                } while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5);

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