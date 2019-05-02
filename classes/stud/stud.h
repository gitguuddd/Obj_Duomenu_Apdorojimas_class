//
// Created by Mindaugas K on 4/29/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_STUD_H
#define OBJ_DUOMENU_APDOROJIMAS_STUD_H
#include "../../Mutual.h"
using std::string;
using std::vector;

class stud {
private:
    string name_;
    string surname_;
    vector<int> nd_;
    int ex_;
    double mvid_;
    double vid_;
public:
    stud(): name_("vardas"), surname_("pavarde"), ex_(0), mvid_(4.999999999), vid_(4.999999999){nd_.reserve(200);};
    stud(const stud& s);
    stud& operator=(const stud& s);
    stud(stud&& s)noexcept;
    stud& operator=(stud&& s)noexcept;
    inline void setname (string name){name_=move(name);}
    inline void setsurname (string surname){surname_=move(surname);}
    inline void setnd (int nd){nd_.push_back(nd);}
    inline void setex (int ex){ex_=ex;}
    void setex ();
    void setvid (int max);
    void setmvid ();
    inline void pushb (){nd_.pop_back();};
    inline string getname() const {return name_;}
    inline string getsurname() const {return surname_;}
    inline int getex() const {return ex_;}
    inline double getmvid() const {return mvid_;}
    inline double getvid() const {return vid_;}
    inline int getndsize() const {return nd_.size();}
    ~stud(){nd_.clear();}
    bool operator==(const stud& A);
    bool operator<=(const stud& A);
    bool operator>=(const stud& A);
    bool operator!=(const stud& A);
    bool operator>(const stud& A);
    bool operator<(const stud& A);


};
struct less_than_mvid{
    bool operator()(const  stud & a, const stud & b){
        return a.getmvid()<b.getmvid();
    }
};
struct less_than_vid {
    bool operator()(const  stud & a, const stud & b){
        return a.getvid()<b.getvid();
    }
};
#endif //OBJ_DUOMENU_APDOROJIMAS_STUD_H
