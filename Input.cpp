//
// Created by Mindaugas K on 2/25/2019.
//
#include "Mutual.h"
#include "Input.h"
int ndcount=0;
int namenum;
int num=0;
std::deque<stud>::iterator upd;
std::list<stud>::iterator upl;
std::vector<stud>::iterator up;
string filename;
long long seed=high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
std::uniform_real_distribution<double> dist(1.0, 100000.0);
std::uniform_real_distribution<double> dist2(1.0, 10.0);
bool sortingmvid(const stud student1, const stud student2){
    if(student1.mvid<student2.mvid)
        return true;
    else if(student1.mvid>student2.mvid)
        return false;
    else if(student1.mvid==student2.mvid)
        return false;
}
bool sortingvid(const stud student1, const stud student2){
        if (student1.vid2 < student2.vid2)
            return true;
        else if (student1.vid2 > student2.vid2)
            return false;
        else if(student1.vid2==student2.vid2)
            return false;

}
void split(char pchoice){
    test.vid2=4.999999999;
    test.mvid=4.999999999;
    if(pchoice=='v'){
    up=std::upper_bound(students.begin(),students.end(),test,stud::less_than_vid2());}
    else if (pchoice=='m'){
        up=std::upper_bound(students.begin(),students.end(),test,stud::less_than_mvid());}
}
void splitd(char pchoice){
    test.vid2=4.999999999;
    test.mvid=4.999999999;
    if(pchoice=='v'){
        upd=std::upper_bound(studentsd.begin(),studentsd.end(),test,stud::less_than_vid2());}
    else if (pchoice=='m'){
        upd=std::upper_bound(studentsd.begin(),studentsd.end(),test,stud::less_than_mvid());}
}
void splitl(char pchoice){
    test.vid2=4.999999999;
    test.mvid=4.999999999;
    if(pchoice=='v'){
        upl=std::upper_bound(studentsl.begin(),studentsl.end(),test,stud::less_than_vid2());}
    else if (pchoice=='m'){
        upl=std::upper_bound(studentsl.begin(),studentsl.end(),test,stud::less_than_mvid());}
}
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
        printf("Ivestas egzamino pazymys iseina is pazymio ribu, egzamino ivertinimas nulinamas\n");
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
        nd = dist2(mt);
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
    fd.close();
}
void readfile(string filename) {
    start=high_resolution_clock::now();
    std::ifstream fd((filename+".txt").c_str());
    students.reserve(namenum);
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
            printf("%s faile ivyko klaida nuskaitant %d studento pavarde\n",filename.c_str(), linecount);
        }
        scan >> students[i].name;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento varda\n",filename.c_str(), linecount);
        }
        while (scan) {
            scan >> tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("%s faile ivyko klaida nuskaitant %d studento %d pazymi\n",filename.c_str(), linecount,
                           countnd + 1);
                    try{
                        students[i].nd.push_back(0);}
                    catch(std::exception e){
                        printf("Perzengtos %d studento namu darbu vektoriaus ribos\n", linecount);
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
    fd.close();
    end=high_resolution_clock::now();
    diff=end-start;
}
void readfiled(string filename) {
    start=high_resolution_clock::now();
    std::ifstream fd((filename+".txt").c_str());
    int i = studentsd.size();
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
            studentsd.push_back(stud());}
        catch(std::exception e){
            printf("Perzengtos studentu vektoriaus ribos\n");
        }
        scan >> studentsd[i].surname;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento pavarde\n",filename.c_str(), linecount);
        }
        scan >> studentsd[i].name;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento varda\n",filename.c_str(), linecount);
        }
        while (scan) {
            scan >> tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("%s faile ivyko klaida nuskaitant %d studento %d pazymi\n",filename.c_str(), linecount,
                           countnd + 1);
                    try{
                        studentsd[i].nd.push_back(0);}
                    catch(std::exception e){
                        printf("Perzengtos %d studento namu darbu vektoriaus ribos\n", linecount);
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
                studentsd[i].sum += tempnd;
                try{
                    studentsd[i].nd.push_back(tempnd);}
                catch(std::exception e){
                    printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",linecount);
                }
                countnd++;
            }
            if (scan.peek() == '\n' || scan.peek() == EOF)
                break;

        }
        studentsd[i].ex = studentsd[i].nd.back();
        studentsd[i].sum-=studentsd[i].nd.back();
        studentsd[i].nd.pop_back();
        linecount++;
        i++;

    }
    fd.close();
    end=high_resolution_clock::now();
    diff=end-start;
}
void readfilel(string filename) {
    start=high_resolution_clock::now();
    std::ifstream fd((filename+".txt").c_str());
    int i = students.size();
    int linecount = 1;
    int countnd;
    int tempnd;
    stud temp;
    bool fsio;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        fsio = false;
        countnd = 0;
        std::istringstream scan(line);
        scan >> temp.surname;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento pavarde\n",filename.c_str(), linecount);
        }
        scan >> temp.name;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento varda\n",filename.c_str(), linecount);
        }
        while (scan) {
            scan >> tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("%s faile ivyko klaida nuskaitant %d studento %d pazymi\n",filename.c_str(), linecount,
                           countnd + 1);
                    try{
                        temp.nd.push_back(0);}
                    catch(std::exception e){
                        printf("Perzengtos %d studento namu darbu vektoriaus ribos\n", linecount);
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
                temp.sum += tempnd;
                try{
                    temp.nd.push_back(tempnd);}
                catch(std::exception e){
                    printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",linecount);
                }
                countnd++;
            }
            if (scan.peek() == '\n' || scan.peek() == EOF)
                break;

        }
        temp.ex = temp.nd.back();
        temp.sum-=temp.nd.back();
        temp.nd.pop_back();
        linecount++;
        i++;
        studentsl.push_back(temp);

    }
    fd.close();
    end=high_resolution_clock::now();
    diff=end-start;
}
void Genstudent(int gensize){
    start=high_resolution_clock::now();
    namenum=int(round(pow(10,gensize)));
    filename=std::to_string(namenum)+"studentu";
    fv.open((filename+".txt").c_str());
    if(fv.fail()){
        printf("Failas %s nerastas/neisejo sukurti",filename.c_str());
        fv.clear();}
    else {
        printf("Kiek namu darbu pazymiu generuoti studentu faile %s ?\n", filename.c_str());
        end=high_resolution_clock::now();
        diff=end-start;
        cin >> ndcount;
        ::msg = "Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n";
        while(ndcount<1||ndcount>1000000){
            cin.setstate(std::ios_base::failbit);
            handleinput(ndcount, msg);}
        handleinput(ndcount, msg);
        start=high_resolution_clock::now();
        for (int i = 0; i < namenum+1; i++) {
            num = dist(mt);
            if (i == 0) {
                fv<<"Pavarde"<<setw(27)<<"Vardas"<<setw(27);
                for (int j = 1; j <= ndcount; j++) {
                    fv<<"ND"<<j<<setw(4);
                }
                fv<<" Egzaminas\n";
            } else {
                fv<<"Pavarde"<<num<<setw(22)<<"Vardas"<<num<<setw(21);
                for (int j = 1; j <= ndcount; j++) {
                    fv<<int(dist2(mt))<<setw(5);
                }
                fv<<int(dist2(mt))<<"\n";
            }
        }
        fv.close();
        end=high_resolution_clock::now();
        diff=diff+(end-start);
    }
}
void splitnprint(string filename, char pchoice){
    start=high_resolution_clock::now();
    maxname = 0;
    maxsurname=0;
    maxcount = 0;
    string subname=filename;
    students.shrink_to_fit();
    for (stud& stud : students) {
        stud.nd.shrink_to_fit();
        if (stud.name.length() >= maxname)
            maxname = stud.name.length();
        if (stud.surname.length() >= maxsurname)
            maxsurname = stud.surname.length();
    }
    if (maxsurname <= 7)
        maxsurname = 7;
    if (maxname <= 6)
        maxname = 6;
    if(pchoice=='v'){
        maxcount = 0;
        for (stud& stud : students) {
            if (stud.nd.size() >= maxcount)
                maxcount = stud.nd.size();
        }
        for (stud& stud : students) {
            if (maxcount != 0) {
                try{
                    stud.vid = (double)stud.sum / (double)maxcount;}
                catch(std::exception e){
                    printf("buvo bandyta apskaiciuototi studentu su 0 nd vidurkius :( \n");
                }
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }
            else {
                stud.vid = 0;
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }

        }
        sort(students.begin(),students.end(),sortingvid);
        split(pchoice);
        vector<stud>mldcstudents(up,students.end());
        students.resize((students.size()-mldcstudents.size()));
        filename=subname+"v_mldc.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (vid.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : mldcstudents){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxsurname-4+(maxsurname-stud.surname.length()));
            fv<<stud.vid2<<setprecision(3)<<"\n";
        }
        fv.close();
        filename=subname+"v_L_laivas.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (vid.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : students){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxsurname-4+(maxsurname-stud.surname.length()));
            fv<<stud.vid2<<setprecision(3)<<"\n";
        }
        fv.close();
    }
    else if(pchoice=='m'){
        for (stud& stud : students) {
            sort(stud.nd.begin(), stud.nd.end());
            if (stud.nd.size() % 2 != 0)
                stud.med = stud.nd[round((double)stud.nd.size() / 2)-1 ];
            else
                stud.med = (double)(stud.nd[stud.nd.size() / 2 -1] + stud.nd[(stud.nd.size() / 2) ]) / 2;
            stud.mvid = stud.med*0.4 + stud.ex*0.6;

        }
        sort(students.begin(),students.end(),sortingmvid);
        split(pchoice);
        vector<stud>mldcstudents(up,students.end());
        students.resize((students.size()-mldcstudents.size()));
        filename=subname+"m_mldc.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : mldcstudents){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.mvid<<setprecision(3)<<"\n";
        }
        fv.close();
        filename=subname+"m_L_laivas.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : students){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.mvid<<setprecision(3)<<"\n";
        }
        fv.close();

    }
    end=high_resolution_clock::now();
    diff=end-start;
}
void splitnprintd(string filename, char pchoice){
    start=high_resolution_clock::now();
    maxname = 0;
    maxsurname=0;
    maxcount = 0;
    string subname=filename;
    studentsd.shrink_to_fit();
    for (stud& stud : studentsd) {
        stud.nd.shrink_to_fit();
        if (stud.name.length() >= maxname)
            maxname = stud.name.length();
        if (stud.surname.length() >= maxsurname)
            maxsurname = stud.surname.length();
    }
    if (maxsurname <= 7)
        maxsurname = 7;
    if (maxname <= 6)
        maxname = 6;
    if(pchoice=='v'){
        maxcount = 0;
        for (stud& stud : studentsd) {
            if (stud.nd.size() >= maxcount)
                maxcount = stud.nd.size();
        }
        for (stud& stud : studentsd) {
            if (maxcount != 0) {
                try{
                    stud.vid = (double)stud.sum / (double)maxcount;}
                catch(std::exception e){
                    printf("buvo bandyta apskaiciuototi studentu su 0 nd vidurkius :( \n");
                }
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }
            else {
                stud.vid = 0;
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }

        }
        sort(studentsd.begin(),studentsd.end(),sortingvid);
        splitd(pchoice);
        deque<stud>mldcstudentsd(upd,studentsd.end());
        studentsd.resize((studentsd.size()-mldcstudentsd.size()));
        filename=subname+"v_mldc.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (vid.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : mldcstudentsd){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.vid2<<setprecision(3)<<"\n";
        }
        fv.close();
        filename=subname+"v_L_laivas.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (vid.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : studentsd){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.vid2<<setprecision(3)<<"\n";
        }
        fv.close();
    }
    else if(pchoice=='m'){
        for (stud& stud : studentsd) {
            sort(stud.nd.begin(), stud.nd.end());
            if (stud.nd.size() % 2 != 0)
                stud.med = stud.nd[round((double)stud.nd.size() / 2)-1 ];
            else
                stud.med = (double)(stud.nd[stud.nd.size() / 2 -1] + stud.nd[(stud.nd.size() / 2) ]) / 2;
            stud.mvid = stud.med*0.4 + stud.ex*0.6;

        }
        sort(studentsd.begin(),studentsd.end(),sortingmvid);
        splitd(pchoice);
        deque<stud>mldcstudentsd(upd,studentsd.end());
        studentsd.resize((studentsd.size()-mldcstudentsd.size()));
        filename=subname+"m_mldc.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : mldcstudentsd){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.mvid<<setprecision(3)<<"\n";
        }
        fv.close();
        filename=subname+"m_L_laivas.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : studentsd){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.mvid<<setprecision(3)<<"\n";
        }
        fv.close();

    }
    end=high_resolution_clock::now();
    diff=end-start;
}
void splitnprintl(string filename, char pchoice){
    start=high_resolution_clock::now();
    maxname = 0;
    maxsurname=0;
    maxcount = 0;
    string subname=filename;
    for (stud& stud : studentsl) {
        stud.nd.shrink_to_fit();
        if (stud.name.length() >= maxname)
            maxname = stud.name.length();
        if (stud.surname.length() >= maxsurname)
            maxsurname = stud.surname.length();
    }
    if (maxsurname <= 7)
        maxsurname = 7;
    if (maxname <= 6)
        maxname = 6;
    if(pchoice=='v'){
        maxcount = 0;
        for (stud& stud : studentsl) {
            if (stud.nd.size() >= maxcount)
                maxcount = stud.nd.size();
        }
        for (stud& stud : studentsl) {
            if (maxcount != 0) {
                try{
                    stud.vid = (double)stud.sum / (double)maxcount;}
                catch(std::exception e){
                    printf("buvo bandyta apskaiciuototi studentu su 0 nd vidurkius :( \n");
                }
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }
            else {
                stud.vid = 0;
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }

        }
        studentsl.sort(sortingvid);
        splitl(pchoice);
        list<stud>mldcstudentsl;
        mldcstudentsl.splice(mldcstudentsl.begin(),studentsl,upl,studentsl.end());
        filename=subname+"v_mldc.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (vid.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : mldcstudentsl){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.vid2<<setprecision(3)<<"\n";
        }
        fv.close();
        filename=subname+"v_L_laivas.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+1);
        fv<<"Galutinis (vid.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : studentsl){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.vid2<<setprecision(3)<<"\n";
        }
        fv.close();
    }
    else if(pchoice=='m'){
        for (stud& stud : studentsl) {
            sort(stud.nd.begin(), stud.nd.end());
            if (stud.nd.size() % 2 != 0)
                stud.med = stud.nd[round((double)stud.nd.size() / 2)-1 ];
            else
                stud.med = (double)(stud.nd[stud.nd.size() / 2 -1] + stud.nd[(stud.nd.size() / 2) ]) / 2;
            stud.mvid = stud.med*0.4 + stud.ex*0.6;

        }
        studentsl.sort(sortingmvid);
        splitl(pchoice);
        list<stud>mldcstudentsl;
        mldcstudentsl.splice(mldcstudentsl.begin(),studentsl,upl,studentsl.end());
        filename=subname+"m_mldc.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : mldcstudentsl){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.mvid<<setprecision(3)<<"\n";
        }
        fv.close();
        filename=subname+"m_L_laivas.txt";
        fv.open(filename.c_str());
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
        for(stud& stud : studentsl){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.mvid<<setprecision(3)<<"\n";
        }
        fv.close();

    }
    end=high_resolution_clock::now();
    diff=end-start;
}




