//
// Created by Mindaugas K on 2/25/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#define OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cin;
using std::vector;
extern string msg;
struct stud {
    string name;
    string surname;
    vector<int> nd;
    int ex;
    double vid;
    double med;
    double mvid;
    double vid2;
    int sum = 0;
};
extern vector<stud> students;
template <typename T1, typename T2>
extern void handleinput( T1 &input, T2 message) {
    if(cin.fail()){
        do {
            cin.clear();
            cin.ignore(256,'\n');
            std::cout << message;
            cin >> input;
        } while (cin.fail());}
}
#endif //OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
