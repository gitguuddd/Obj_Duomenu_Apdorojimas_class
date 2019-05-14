//
// Created by Mindaugas K on 2/25/2019.
//
#include "../Headers/Mutual.h"
#include "classes/ImportantValues/Important_Values.h"
#include "../Headers/Input.h"
std::deque<Stud>::iterator up_d;
std::list<Stud>::iterator up_l;
std::vector<Stud>::iterator up;
long long seed=high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
std::uniform_real_distribution<double> dist(1.0, 100000.0);
std::uniform_real_distribution<double> dist2(1.0, 10.0);
bool sorting_mvid(const Stud t_student1, const Stud t_student2){
    if(t_student1.get_mvid()< t_student2.get_mvid())
        return true;
    else if(t_student1.get_mvid()> t_student2.get_mvid())
        return false;
    else if(t_student1.get_mvid()== t_student2.get_mvid())
        return false;
}
bool sorting_vid(const Stud t_student1, const Stud t_student2){
        if (t_student1.get_vid()< t_student2.get_vid())
            return true;
        else if (t_student1.get_vid() > t_student2.get_vid())
            return false;
        else if(t_student1.get_vid()== t_student2.get_vid())
            return false;

}
void split(char t_pchoice, char t_strat, std::vector<Stud>::iterator &t_up){
    if (t_strat == 'a'){
        mldc.reserve(v.get_name_num()/2);
        L_laivs.reserve(v.get_name_num()/2);
        if(t_pchoice=='v'){
            if(t_pchoice=='v')
                t_up=stable_partition(students.begin(),students.end(),[](Stud v) {return v.get_vid()< test.get_vid();});}
            else if(t_pchoice=='m')
                t_up=stable_partition(students.begin(),students.end(),[](Stud v) {return v.get_mvid()< test.get_mvid();});
        mldc.shrink_to_fit();
        L_laivs.shrink_to_fit();
    }
    else if(t_strat=='b'){
        if(t_pchoice=='v'){
            if(t_pchoice=='v')
                t_up=stable_partition(students.begin(),students.end(),[](Stud v) {return v.get_vid()< test.get_vid();});}
        else if(t_pchoice=='m')
            t_up=stable_partition(students.begin(),students.end(),[](Stud v) {return v.get_mvid()< test.get_mvid();});}
    else if(t_strat == 'c'){
    if(t_pchoice=='v'){
    t_up=std::upper_bound(students.begin(),students.end(),test,less_than_vid());}
    else if (t_pchoice=='m'){
        t_up=std::upper_bound(students.begin(),students.end(),test,less_than_mvid());}}
    else if(t_strat=='d'){
        if (v.get_issamiai()!='k'){printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
            v.set_kiec();
        while(v.get_kiec()!='k'&& v.get_kiec()!='m'){
            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/ i prieki perkelti [k]ietus\n");
            v.set_kiec();
        }}
        if(v.get_kiec()=='m')
            minksti= rask_Minkstus(students, t_pchoice);
        else if(v.get_kiec()=='k')
            minksti= rask_Kietus(students, t_pchoice);
    }
}
void split_d(char t_pchoice, char t_strat, std::deque<Stud>::iterator &t_up_d){
    if(t_strat=='a'){
        if(t_pchoice=='v')
        t_up_d=stable_partition(students_d.begin(),students_d.end(),[](Stud v) {return v.get_vid()< test.get_vid();});
        else if(t_pchoice=='m')
            t_up_d=stable_partition(students_d.begin(),students_d.end(),[](Stud v) {return v.get_mvid()< test.get_mvid();});}
    else if(t_strat=='b'){
        if(t_pchoice=='v'){
            if(t_pchoice=='v')
                t_up_d=stable_partition(students_d.begin(),students_d.end(),[](Stud v) {return v.get_vid()< test.get_vid();});}
            else if(t_pchoice=='m')
                t_up_d=stable_partition(students_d.begin(),students_d.end(),[](Stud v) {return v.get_mvid()< test.get_mvid();});}
    else if (t_strat=='c'){
    if(t_pchoice=='v'){
        t_up_d=std::upper_bound(students_d.begin(),students_d.end(),test,less_than_vid());}
    else if (t_pchoice=='m'){
        t_up_d=std::upper_bound(students_d.begin(),students_d.end(),test,less_than_mvid());}
    }
    else if(t_strat=='d'){
       if(v.get_issamiai()!='k') {printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
           v.set_kiec();
        while(v.get_kiec()!='k'&& v.get_kiec()!='m'){
            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/ i prieki perkelti [k]ietus\n");
            v.set_kiec();
        }}
        if(v.get_kiec()=='m')
            minksti_d= rask_Minkstus_d(students_d, t_pchoice);
        else if(v.get_kiec()=='k')
                minksti_d= rask_Kietus_d(students_d, t_pchoice);

    }
}
void split_l(char t_pchoice, char t_strat, std::list<Stud>::iterator &t_up_l){
    if (t_strat=='a'){
        if(t_pchoice=='v'){
            if(t_pchoice=='v')
                t_up_l=stable_partition(students_l.begin(),students_l.end(),[](Stud v) {return v.get_vid()< test.get_vid();});}
            else if(t_pchoice=='m')
                t_up_l=stable_partition(students_l.begin(),students_l.end(),[](Stud v) {return v.get_mvid()< test.get_mvid();});}
    else if(t_strat=='b'){
        if(t_pchoice=='v'){
            if(t_pchoice=='v')
                t_up_l=stable_partition(students_l.begin(),students_l.end(),[](Stud v) {return v.get_vid()< test.get_vid();});}
            else if(t_pchoice=='m')
                t_up_l=stable_partition(students_l.begin(),students_l.end(),[](Stud v) {return v.get_mvid()< test.get_mvid();});}
    else if(t_strat=='c'){
    if(t_pchoice=='v'){
        t_up_l=std::upper_bound(students_l.begin(),students_l.end(),test,less_than_vid());}
    else if (t_pchoice=='m'){
        t_up_l=std::upper_bound(students_l.begin(),students_l.end(),test,less_than_mvid());}
    }
}
Stud user_input() {
    Stud student;
    string temp_name;
    string temp_surname;
    int temp_ex;
    int nd = 1;
    printf("Iveskite studento varda\n");
    v.set_msg("Klaida ivedant studento varda, bandykite is naujo");
    cin >> temp_name;
    handle_name(temp_name);
    student.set_name(temp_name);
    printf("Iveskite studento pavarde\n");
    v.set_msg("Klaida ivedant studento pavarde, bandykite is naujo");
    cin >> temp_surname;
    handle_name(temp_surname);
    student.set_surname(temp_surname);
    printf("Iveskite studento egzamino ivertinima\n");
    v.set_msg("Klaida ivedant studento egzamino ivertinima, bandykite is naujo\n");
    cin >> temp_ex;
    handle_input(temp_ex, v.get_msg());
    if(temp_ex<0||temp_ex>10){
        printf("Ivestas egzamino pazymys iseina is pazymio ribu, egzamino ivertinimas nulinamas\n");
        temp_ex=0;
    }
    student.set_ex(temp_ex);
    printf("Iveskite studento namu darbu pazymius, skaiciaus -1 ivestis uzbaigia ivesti\n");
    while (nd != -1) {
        v.set_msg("Klaida ivedant studento namu darbu ivertinima, bandykite is naujo (-1 baigia ivesti)");
        cin >> nd;
        handle_input(nd, v.get_msg());
        if (nd >= 0 && nd < 11)
            student.set_nd(nd);
        else if (nd > 10 || nd < -1)
            printf("\n Ivesta netinkama reiksme, teskite pildyma ivesdami skaiciu is intervalo [0;10] arba iveskite -1 (baigti) \n");


    }
    return student;
}
Stud gen_student() {
    Stud student;
    v.set_msg("Ivedete ne skaiciu, bandykite is naujo (0 baigia ivesti)");
    int nd = 1;
    int temp;
    string tempname;
    string tempsurname;
    int tempex;
    int num =dist(mt);
    tempname = "Vardas" + std::to_string(num);
    student.set_name(tempname);
    printf("Studento vardas: %s\n", tempname.c_str());
    tempsurname = "Pavarde" + std::to_string(num);
    student.set_surname(tempsurname);
    printf("Studento pavarde: %s\n", tempsurname.c_str());
    student.set_ex(dist2(mt));
    printf("Studento egzamino ivertinimas: %d \n", student.get_ex());
    printf("Iveskite bet koki  skaiciu, kad sugeneruotumete pazymi,  skaicius 0 ivestis uzbaigia ivesti\n");
    while (nd != 0) {
        cin >> nd;
        handle_input(nd, v.get_msg());
        temp = nd;
        nd = dist2(mt);
        printf("Sugeneruotas pazymys: %d\n", nd);
        student.set_nd(nd);
        nd = temp;
    }
    if(student.get_ndsize()>1)
        student.push_b();
    return student;
}
void read_file2(bool &t_isempty, int &t_read_count) {
    std::ifstream fd("kursiokai.txt");
    v.line_count=0;
    Stud temp;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        v.fsio = false;
        v.count_nd = 0;
        std::istringstream scan(line);
        scan>>temp;
        temp.set_ex();
        v.line_count++;
        students.push_back(temp);
        temp={};
    }
    if (v.line_count == 1)
        t_isempty = true;
    else
        t_read_count++;
    fd.close();
}
void gen_student(int t_gen_size){
    t.reset();
    v.set_diff(0);
    v.set_name_num(int(round(pow(10, t_gen_size))));
    v.set_file_name(std::to_string(v.get_name_num()) + "studentu");
    fv.open((v.get_file_name()+".txt").c_str());
    if(fv.fail()){
        printf("Failas %s nerastas/neisejo sukurti", v.get_file_name().c_str());
        fv.clear();}
    else {
    if(v.get_issamiai()!='k'){
        v.set_diff(t.elapsed());
        printf("Kiek namu darbu pazymiu generuoti studentu faile %s ?\n", v.get_file_name().c_str());
        v.set_nd_count();
        v.set_msg("Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n");
        while(v.get_nd_count()<1|| v.get_nd_count()>1000000){
            cin.setstate(std::ios_base::failbit);
            handle_nd(v.get_msg());}
        handle_nd(v.get_msg());
        t.reset();}
        for (int i = 0; i < v.get_name_num()+1; i++) {
            v.set_num(dist(mt));
            if (i == 0) {
                fv<<"Pavarde"<<setw(27)<<"Vardas"<<setw(27);
                for (int j = 1; j <= v.get_nd_count(); j++) {
                    fv<<"ND"<<j<<setw(4);
                }
                fv<<" Egzaminas\n";
            } else {
                fv<<"Pavarde"<< v.get_num()<<setw(22)<<"Vardas"<< v.get_num()<<setw(21);
                for (int j = 1; j <= v.get_nd_count(); j++) {
                    fv<<int(dist2(mt))<<setw(5);
                }
                fv<<int(dist2(mt))<<"\n";
            }
        }
        fv.close();
        v.set_diff(v.get_diff() + t.elapsed());
    }
}
void split_n_print(char t_pchoice, char t_strat){
    if(t_strat!='d'){
    t.reset();
    names(students);
    if(t_pchoice=='v'){
        calc(students,t_pchoice);
        if(t_strat=='c')
            sort(students.begin(), students.end(), sorting_vid);
        split(t_pchoice,t_strat, up);
        if(t_strat=='a'){
            v.set_sar('m');
            vector<Stud>mldc(up, students.end());
            print_to_file(mldc, t_pchoice, v.get_sar());
            v.set_sar('v');
            vector<Stud>L_laivs(students.begin(), up);
            print_to_file(L_laivs, t_pchoice, v.get_sar());
            mldc.clear();
            L_laivs.clear();}
        else{
            v.set_sar('m');
            vector<Stud>mldcstudents(up,students.end());
            print_to_file(mldcstudents, t_pchoice, v.get_sar());
            v.set_sar('v');
            students.resize((students.size()-mldcstudents.size()));
            print_to_file(students, t_pchoice, v.get_sar());}
    }
    else if(t_pchoice=='m'){
        calc(students,t_pchoice);
        if(t_strat=='c')
            sort(students.begin(), students.end(), sorting_mvid);
        split(t_pchoice,t_strat, up);
        if(t_strat=='a'){
            v.set_sar('m');
            vector<Stud>mldc(up, students.end());
            print_to_file(mldc, t_pchoice, v.get_sar());
            v.set_sar('v');
            vector<Stud>L_laivs(students.begin(), up);
            print_to_file(L_laivs, t_pchoice, v.get_sar());
            mldc.clear();
            L_laivs.clear();}
        else{
            v.set_sar('m');
        vector<Stud>mldcstudents(up,students.end());
            print_to_file(mldcstudents, t_pchoice, v.get_sar());
            v.set_sar('v');
        students.resize((students.size()-mldcstudents.size()));
            print_to_file(students, t_pchoice, v.get_sar());}

    }
        v.set_diff(t.elapsed());}
    else if (t_strat=='d'){
        names(students);
        calc(students,t_pchoice);
        split(t_pchoice,t_strat, up);
        v.set_sar('m');
        print_to_file(students, t_pchoice, v.get_sar());
        v.set_sar('v');
        print_to_file(minksti, t_pchoice, v.get_sar());
    }
}
void split_n_print_d(char t_pchoice, char t_strat){
    if(t_strat!='d'){
    t.reset();
    names(students_d);
    if(t_pchoice=='v'){
        calc(students_d,t_pchoice);
        if(t_strat=='c')
            sort(students_d.begin(), students_d.end(), sorting_vid);
        split_d(t_pchoice, t_strat, up_d);
        if(t_strat=='a'){
            v.set_sar('m');
            deque<Stud>mldcd(up_d,students_d.end());
            print_to_file(mldcd, t_pchoice, v.get_sar());
            v.set_sar('v');
            deque<Stud>L_laivsd(students_d.begin(), up_d);
            print_to_file(L_laivsd, t_pchoice, v.get_sar());
            mldcd.clear();
            L_laivsd.clear();}
        else{
            v.set_sar('m');
        deque<Stud>mldcstudentsd(up_d,students_d.end());
            print_to_file(mldcstudentsd, t_pchoice, v.get_sar());
            v.set_sar('v');
        students_d.resize((students_d.size()-mldcstudentsd.size()));
            print_to_file(students_d, t_pchoice, v.get_sar());}
    }
    else if(t_pchoice=='m'){
        calc(students_d,t_pchoice);
        if(t_strat=='c')
            sort(students_d.begin(), students_d.end(), sorting_mvid);
        split_d(t_pchoice, t_strat, up_d);
        if(t_strat=='a'){
            v.set_sar('m');
            deque<Stud>mldcd(up_d,students_d.end());
            print_to_file(mldcd, t_pchoice, v.get_sar());
            v.set_sar('v');
            deque<Stud>L_laivsd(students_d.begin(), up_d);
            print_to_file(L_laivsd, t_pchoice, v.get_sar());
            mldcd.clear();
            L_laivsd.clear();}
        else{
            v.set_sar('m');
        deque<Stud>mldcstudentsd(up_d,students_d.end());
            print_to_file(mldcstudentsd, t_pchoice, v.get_sar());
            v.set_sar('v');
        students_d.resize((students_d.size()-mldcstudentsd.size()));
            print_to_file(students_d, t_pchoice, v.get_sar());}

    }
        v.set_diff(t.elapsed());}
    else if (t_strat=='d'){
        names(students_d);
            calc(students_d,t_pchoice);
        split_d(t_pchoice, t_strat, up_d);
        v.set_sar('m');
        print_to_file(students_d, t_pchoice, v.get_sar());
        v.set_sar('v');
        print_to_file(minksti_d, t_pchoice, v.get_sar());
    }
}
void split_n_print_l(char t_pchoice, char t_strat){
   t.reset();
    names(students_l);
    if(t_pchoice=='v'){
        calc(students_l,t_pchoice);
        if(t_strat=='c')
            students_l.sort(sorting_vid);
        split_l(t_pchoice, t_strat, up_l);
        if(t_strat=='a'){
            v.set_sar('m');
            mldc_l.splice(mldc_l.begin(),students_l,up_l,students_l.end());
            print_to_file(mldc_l, t_pchoice, v.get_sar());
            v.set_sar('v');
            list<Stud>L_laivsl(students_l.begin(), students_l.end());
            print_to_file(L_laivsl, t_pchoice, v.get_sar());
            mldc_l.clear();
            L_laivsl.clear();}
        else{
            v.set_sar('m');
        mldc_students_l.splice(mldc_students_l.begin(),students_l,up_l,students_l.end());
            print_to_file(mldc_students_l, t_pchoice, v.get_sar());
            v.set_sar('v');
            print_to_file(students_l, t_pchoice, v.get_sar());}
    }
    else if(t_pchoice=='m'){
        calc(students_l,t_pchoice);
        if(t_strat=='c')
            students_l.sort(sorting_mvid);
        split_l(t_pchoice, t_strat, up_l);
        if(t_strat=='a'){
            v.set_sar('m');
            mldc_l.splice(mldc_l.begin(),students_l,up_l,students_l.end());
            print_to_file(mldc_l, t_pchoice, v.get_sar());
            v.set_sar('v');
            list<Stud>L_laivsl(students_l.begin(), students_l.end());
            print_to_file(L_laivsl, t_pchoice, v.get_sar());
        mldc_l.clear();
        L_laivsl.clear();}
        else{
            v.set_sar('m');
        mldc_students_l.splice(mldc_students_l.begin(),students_l,up_l,students_l.end());
            print_to_file(mldc_students_l, t_pchoice, v.get_sar());
            v.set_sar('v');
            print_to_file(students_l, t_pchoice, v.get_sar());}

    }
    v.set_diff(t.elapsed());


}