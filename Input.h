//
// Created by Mindaugas K on 2/18/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_HEADERS_H
#define OBJ_DUOMENU_APDOROJIMAS_HEADERS_H
#include "Mutual.h"
#include <random>
#include <ctime>
extern string filename;
extern int namenum;
extern int gensize;
extern int ndcount;
extern int num;
extern std::vector<stud>::iterator up;
extern long long seed;
extern std::mt19937 mt;
extern std::uniform_real_distribution<double> dist;
extern std::uniform_real_distribution<double> dist2;
stud Userinput();
void Genstudent(int gensize);
stud GenStudent();
void readfile(bool & isempty, int &readcount);
bool sortingvid(const stud student1, const stud student2);
bool sortingmvid(const stud student1, const stud student2);
extern void readfile(string filename);
extern void readfiled(string filename);
extern void readfilel(string filename);
extern void split(char pchoice);
extern void splitd(char pchoice);
extern void splitl(char pchoice);
extern void splitnprint(string filename, char pchoice);
extern void splitnprintd(string filename, char pchoice);
extern void splitnprintl(string filename, char pchoice);



#endif //OBJ_DUOMENU_APDOROJIMAS_Input_H
