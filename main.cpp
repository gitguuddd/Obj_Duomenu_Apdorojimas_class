#include "./Headers/Mutual.h"
#include "./Headers/Input.h"
#include "./Headers/Output.h"
int main() {
    v.set_pap(false);
    v.set_strat2('c');
    v.set_num(0);
    int choice=0;
    int spec_choice =-1;
    int print_fail=0;
    int read_count=0;
    bool is_empty=false;
    printf("Pasirinkite programos rezima: [i]ssamus, [k]onkretus ?");
    v.set_issamiai();
    while(v.get_issamiai()!='i'&& v.get_issamiai()!='k'){
        printf("Neteisinga ivestis, galimi variantai: [i]ssamus, [k]onkretus\n");
        v.set_issamiai();
    }
    students.reserve(100);
    while (choice == 0 || choice == 5 || choice == 4) {
        if (spec_choice == -1) {
            printf("Saugomi %d studentu(o) duomenys, pasirinkite ka daryti toliau:\n", students.size());
            printf("1. Ivesti studenta paciam\n");
            printf("2. Generuoti studenta\n");
            printf("3. Skaityti is failo\n");
            printf("4. Atspausdinti (galutinis pagal nd mediana)\n");
            printf("5. Atspausdinti (galutinis pagal nd vidurki)\n");
            printf("6. Generuoti studentu faila (v1.5)\n");
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
                students.push_back(user_input());}
                catch(std::exception e){
                    printf("Perzengtos studentu vektoriaus ribos\n");
                }
                choice = 0;
                break;
            case 2:
                try{
                students.push_back(gen_student());}
                catch(std::exception e){
                    printf("Perzengtos studentu vektoriaus ribos\n");
                }
                choice = 0;
                break;
            case 3:
                if (read_count == 0) {
                    read_file2(is_empty, read_count);
                }
                else
                    print_fail=3;
                choice = 0;
                if (is_empty)
                    print_fail=32;
                    spec_choice = 0;
                break;
            case 4:
                if (students.empty()) {
                    spec_choice = 0;
                    choice = 0;
                    print_fail=4;
                    break;
                }
                else {
                    sort(students.begin(), students.end(), sorting_mvid);
                    print(students, 'm');
                    choice = -1;
                    break;
                }
            case 5:
                if (students.empty()) {
                    spec_choice = 0;
                    print_fail=4;
                    choice = 0;
                    break;
                }
                else {
                    sort(students.begin(), students.end(), sorting_vid);
                    print(students, 'v');
                    choice = -1;
                    break;
                }
            case 6:
                t_strat_pick();
                if(v.get_strat()!='d'){
                    t_STL_pick(v.get_pap());
                    ft.open("V2.0_laikai.txt");
                    (v.get_STL()=='v')?ft<<"Pasirinktas konteineris - vektorius\n":
                        (v.get_STL()=='d')?ft<<"Pasirinktas konteineris - dekas\n":
                        ft<<"Pasirinktas konteineris - listas\n";
                    if(v.get_issamiai()=='k'){
                        printf("Kiek namu darbu pazymiu generuoti studentu failuose ?\n");
                        v.set_nd_count();
                        v.set_msg(
                                "Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n");
                        while(v.get_nd_count()<1|| v.get_nd_count()>1000000){
                            cin.setstate(std::ios_base::failbit);
                            handle_nd(v.get_msg());}
                        handle_nd(v.get_msg());

                        printf("Galutini pazymi studentu failuose skaiciuoti pagal [v]idurki/[m]ediana ?\n");
                        v.set_pchoice();
                        while(v.get_pchoice()!='v'&& v.get_pchoice()!='m'){
                            printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                            v.set_pchoice();}
                    }
                    for(int i=1;i<=6;i++){
                        students.clear();
                        students_l.clear();
                        students_d.clear();
                        mldc_students.clear();
                        mldc_students_l.clear();
                        mldc_students_d.clear();
                        ft<<int(round(pow(10,i)))<<"studentu\n";
                        ft<<"--------------------------------\n";
                        gen_student(i);
                    ft<<"Studentai sugeneruoti ir isvesti i faila per "<< v.get_diff()<<" s.\n";
                    if(v.get_STL()=='v')
                        students.reserve(v.get_name_num());
                       (v.get_STL()=='v')? read_file(students, v.get_file_name()):
                        (v.get_STL()=='d')? read_file(students_d, v.get_file_name()):
                        read_file(students_l, v.get_file_name());
                        if(v.get_STL()=='v')
                            students.shrink_to_fit();
                            else if (v.get_STL()=='d')
                                students_d.shrink_to_fit();
                    ft<<"Studentai nuskaityti is failo  "<< v.get_file_name()<<" per "<< v.get_diff()<<" s.\n";
                    if(v.get_issamiai()!='k'){
                    printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n", v.get_file_name().c_str());
                        v.set_pchoice();
                    while(v.get_pchoice()!='v'&& v.get_pchoice()!='m'){
                        printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                        v.set_pchoice();
                    }}(v.get_STL()=='v')? split_n_print(v.get_pchoice(), v.get_strat()):
                        (v.get_STL()=='d')? split_n_print_d(v.get_pchoice(), v.get_strat()):
                        split_n_print_l(v.get_pchoice(), v.get_strat());
                    ft<<"Studentai perskelti i mldc ir L_laivo sarasus, bei atspausdinti atitinkamuose failuose per "<< v.get_diff()<<" s.\n";
                    ft<<"--------------------------------\n";
                        if(v.get_issamiai()=='k')
                        printf("Darbas baigtas su failu %s \n", v.get_subname().c_str());
                    }
                    ft.close();
                    mldc_students.clear();
                    students.clear();
                choice=-1;
                break;}
                else{
                    v.set_pap(true);
                    t_STL_pick(v.get_pap());
                    if(v.get_issamiai()=='k'){
                        printf("Kiek namu darbu pazymiu generuoti studentu failuose ?\n");
                        v.set_nd_count();
                        v.set_msg(
                                "Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n");
                        while(v.get_nd_count()<1|| v.get_nd_count()>1000000){
                            cin.setstate(std::ios_base::failbit);
                            handle_nd(v.get_msg());}
                        handle_nd(v.get_msg());
                        printf("Galutini pazymi studentu failuose skaiciuoti pagal [v]idurki/[m]ediana ?\n");
                        v.set_pchoice();
                        while(v.get_pchoice()!='v'&& v.get_pchoice()!='m'){
                            printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                            v.set_pchoice();}
                        printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
                        v.set_kiec();
                        while(v.get_kiec()!='k'&& v.get_kiec()!='m'){
                            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/perkelti [k]ietus\n");
                            v.set_kiec();
                        }
                    }
                    ft.open("Papildomos_uzduoties_laikai.txt");
                    (v.get_STL()=='v')?ft<<"Pasirinktas konteineris - vektorius\n":ft<<"Pasirinktas konteineris - dekas\n";
                    for(int i=1;i<=5;i++){
                        students.clear();
                        minksti.clear();
                        students_d.clear();
                        minksti_d.clear();
                        ft<<int(round(pow(10,i)))<<"studentu\n";
                        ft<<"--------------------------------\n";
                        gen_student(i);
                        if(v.get_STL()=='v')
                            students.reserve(v.get_name_num());
                        (v.get_STL()=='v')? read_file(students, v.get_file_name()): read_file(students_d,
                                                                                               v.get_file_name());
                        if(v.get_STL()=='v')
                            students.shrink_to_fit();
                        else
                            students_d.shrink_to_fit();
                        if(v.get_issamiai()!='k') {
                            printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",
                                   v.get_file_name().c_str());
                            v.set_pchoice();
                            while (v.get_pchoice() != 'v' && v.get_pchoice() != 'm') {
                                printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                                v.set_pchoice();
                            }
                        }(v.get_STL()=='v')? split_n_print(v.get_pchoice(), v.get_strat()): split_n_print_d(
                                v.get_pchoice(),
                                v.get_strat());
                        if(v.get_issamiai()=='k')
                        printf("Darbas baigtas su  %s \n", v.get_subname().c_str());
                        ft<<"Papildomos uzduoties split'inimo algoritmas uztruko "<< v.get_diff()<<" s.\n";
                        ft<<"--------------------------------\n";}
                    ft.close();
                    choice= -1;
                    break;
                }
            case 7:
                if (students.empty()) {
                    spec_choice = 0;
                    choice = 0;
                    print_fail=4;
                    break;
                }
                else {
                    t_strat_pick();
                    v.set_file_name(std::to_string(students.size()) + "kursioku");
                    printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n", v.get_file_name().c_str());
                    v.set_pchoice();
                    while(v.get_pchoice()!='v'&& v.get_pchoice()!='m'){
                        printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                        v.set_pchoice();
                    }
                   if(v.get_strat()=='d'&& v.get_issamiai()=='k') {printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
                       v.set_kiec();
                    while(v.get_kiec()!='k'&& v.get_kiec()!='m'){
                        printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/perkelti [k]ietus\n");
                        v.set_kiec();
                    }}
                    split_n_print(v.get_pchoice(), v.get_strat());
                    choice = -1;
                    break;
                }

            default:
                switch(print_fail){
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
                spec_choice = -1;
                choice = 0;
                print_fail=0;
        }
    }
    return 0;
}