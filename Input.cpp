//
// Created by Mindaugas K on 2/25/2019.
//
#include "Mutual.h"
#include "Input.h"
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<double> dist(1.0, 100000000.0);
std::uniform_real_distribution<double> dist2(1.0, 10.0);
stud Userinput() {
    stud student;
    student.nd.reserve(200);
    int nd = 1;
    printf("Iveskite studento varda\n");
    msg = "Klaida ivedant studento varda, bandykite is naujo";
    cin >> student.name;
    handleinput(student.name, msg);
    printf("Iveskite studento pavarde\n");
    msg = "Klaida ivedant studento pavarde, bandykite is naujo";
    cin >> student.surname;
    handleinput(student.surname, msg);
    printf("Iveskite studento egzamino ivertinima\n");
    msg = "Klaida ivedant studento egzamino ivertinima, bandykite is naujo\n";
    cin >> student.ex;
    handleinput(student.ex, msg);
    if(student.ex<0||student.ex>10){
        printf("Ivestas egzamino pazymys iseina is pazymio ribu, egzamino ivertinimas nulinamas");
        student.ex=0;
    }
    printf("Iveskite studento namu darbu pazymius, skaiciaus -1 ivestis uzbaigia ivesti\n");
    while (nd != -1) {
        msg = "Klaida ivedant studento namu darbu ivertinima, bandykite is naujo (-1 baigia ivesti)";
        cin >> nd;
        handleinput(nd, msg);
        if (nd >= 0 && nd < 11) {
            student.sum += nd;
            try{
            student.nd.push_back(nd);}
            catch(std::exception e){
                printf("Perzengtos %d studento namu darbu vektoriaus ribos",students.size()+1);
            }
        }
        else if (nd > 10 || nd < -1)
            printf("\n Ivesta netinkama reiksme, teskite pildyma ivesdami skaiciu is intervalo [0;10] arba iveskite -1 (baigti) \n");


    }
    return student;
}
stud GenStudent() {
    stud student;
    student.nd.reserve(200);
    msg = "Ivedete ne skaiciu, bandykite is naujo (0 baigia ivesti)";
    int nd = 1;
    int temp;
    int num =dist(mt);
    student.name = "Vardas" + std::to_string(num);
    printf("Studento vardas: %s\n", student.name.c_str());
    student.surname = "Pavarde" + std::to_string(num);
    printf("Studento pavarde: %s\n", student.surname.c_str());
    student.ex = dist2(mt);
    printf("Studento egzamino ivertinimas: %d \n", student.ex);
    printf("Iveskite bet koki  skaiciu, kad sugeneruotumete pazymi,  skaiciaus 0 ivestis uzbaigia ivesti\n");
    while (nd != 0) {
        cin >> nd;
            handleinput(nd, msg);
        temp = nd;
        nd = (double)rand() / RAND_MAX * 11;
        printf("Sugeneruotas pazymys: %d\n", nd);
        student.sum += nd;
        try{
        student.nd.push_back(nd);}
        catch(std::exception e){
            printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",students.size()+1);}
        nd = temp;
    }
    return student;
}
void readfile(bool & isempty, int &readcount) {
    std::ifstream fd("kursiokai.txt");
    int i = students.size();
    int linecount = 1;
    int countnd;
    int tempnd;
    bool fsio;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        fsio = false;
        countnd = 0;
        std::istringstream scan(line);
        try{
        students.push_back(stud());}
        catch(std::exception e){
            printf("Perzengtos studentu vektoriaus ribos\n");
        }
        students[i].nd.reserve(200);
        scan >> students[i].surname;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("kursiokai.txt faile ivyko klaida nuskaitant %d studento pavarde\n", linecount);
        }
        scan >> students[i].name;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("kursiokai.txt faile ivyko klaida nuskaitant %d studento varda\n", linecount);
        }
        while (scan) {
            scan >> tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("kursiokai.txt faile ivyko klaida nuskaitant %d studento %d pazymi\n", linecount,
                           countnd + 1);
                    try{
                    students[i].nd.push_back(0);}
                    catch(std::exception e){
                        printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",linecount);
                    }
                    countnd++;
                    if (scan.peek() != '\n'&&scan.peek() != EOF)
                        scan >> tempnd;
                    else {
                        fsio = true;
                        break;
                    }
                } while (scan.fail());

            }
            if (!fsio) {
                if (tempnd < 0 || tempnd > 10) {
                    tempnd = 0;
                }
                students[i].sum += tempnd;
                try{
                students[i].nd.push_back(tempnd);}
                catch(std::exception e){
                    printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",linecount);
                }
                countnd++;
            }
            if (scan.peek() == '\n' || scan.peek() == EOF)
                break;

        }
        students[i].ex = students[i].nd.back();
        students[i].sum-=students[i].nd.back();
        students[i].nd.pop_back();
        linecount++;
        i++;

    }
    if (linecount == 1)
        isempty = true;
    else
        readcount++;
}
