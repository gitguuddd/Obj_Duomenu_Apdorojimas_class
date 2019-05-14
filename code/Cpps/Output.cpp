//
// Created by Mindaugas K on 2/25/2019.
//
#include "../Headers/Output.h"

bool sorting(const Stud &t_student1, const Stud &t_student2) {
    if (t_student1.get_surname() != t_student2.get_surname())
        return (t_student1.get_surname() < t_student2.get_surname());
    if (t_student1.get_name() != t_student2.get_name())
        return (t_student1.get_name() < t_student2.get_name());

}
void print(vector<Stud>t_students, char t_type) {
    t_students.shrink_to_fit();
    v.set_max_name(0);
    v.set_max_surname(0);
    v.set_max_count(0);
    for (Stud& stud : t_students) {
        if (stud.get_name().length() >= v.get_max_name())
            v.set_max_name(stud.get_name().length());
        if (stud.get_surname().length() >= v.get_max_surname())
            v.set_max_surname(stud.get_surname().length());
    }

    if (v.get_max_surname() <= 7)
        v.set_max_surname(7);
    if (v.get_max_name() <= 6)
        v.set_max_name(6);
    if (t_type == 'v') {
        v.set_max_count(0);
        for (Stud& stud : t_students) {
            if (stud.get_ndsize() >= v.get_max_count())
                v.set_max_count(stud.get_ndsize());
        }
        for (Stud& stud : t_students)
            stud.set_vid(v.get_max_count());

    }
    if (t_type == 'm') {
        for (Stud& stud : t_students)
            stud.set_mvid();
    }
    if (t_type == 'm') {
        printf("Pavarde%*cVardas%*cGalutinis (Med.)\n", v.get_max_surname() - 6, ' ', v.get_max_name() - 5, ' ');
        printf("%s\n", (string(29 + v.get_max_surname() - 7 + v.get_max_name() - 6, '-')).c_str());
        for (Stud& stud : t_students) {
            printf("%s%*c%s%*c%.2lf\n", stud.get_surname().c_str(), v.get_max_surname() - stud.get_surname().length() + 3, ' ',
                   stud.get_name().c_str(),
                   v.get_max_name() - stud.get_name().length() + 1, ' ', stud.get_mvid());
        }
    }
    if (t_type == 'v') {
        printf("Pavarde%*cVardas%*cGalutinis (Vid.)\n", v.get_max_surname() - 6, ' ', v.get_max_name() - 5, ' ');
        printf("%s\n", (string(29 + v.get_max_surname()- 7 + v.get_max_name() - 6, '-')).c_str());
        for (Stud& stud : t_students) {
            printf("%s%*c%s%*c%.2lf\n", stud.get_surname().c_str(), v.get_max_surname() - stud.get_surname().length() + 3, ' ',
                   stud.get_name().c_str(),
                   v.get_max_name() - stud.get_name().length() + 1, ' ', stud.get_vid());
        }
    }
}