//
// Created by Mindaugas K on 2/18/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_HEADERS_H
#define OBJ_DUOMENU_APDOROJIMAS_HEADERS_H
#include <random>
#include <ctime>
extern std::vector<Stud>::iterator up;
extern long long seed;
extern std::mt19937 mt;
extern std::uniform_real_distribution<double> dist;
extern std::uniform_real_distribution<double> dist2;
Stud user_input();
void gen_student(int t_gen_size);
Stud gen_student();
void read_file2(bool &t_isempty, int &t_read_count);
bool sorting_vid(const Stud t_student1, const Stud t_student2);
bool sorting_mvid(const Stud t_student1, const Stud t_student2);
extern void split(char t_pchoice, char t_strat, std::vector<Stud>::iterator &t_up);
extern void split_d(char t_pchoice, char t_strat, std::deque<Stud>::iterator &t_up_d);
extern void split_l(char t_pchoice, char t_strat, std::list<Stud>::iterator &t_up_l);
extern void split_n_print(char t_pchoice, char t_strat);
extern void split_n_print_d(char t_pchoice, char t_strat);
extern void split_n_print_l(char t_pchoice, char t_strat);



#endif //OBJ_DUOMENU_APDOROJIMAS_Input_H
