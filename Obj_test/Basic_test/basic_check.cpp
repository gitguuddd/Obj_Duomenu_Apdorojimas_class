#include "gtest/gtest.h"
#include "classes/stud/Stud.h"
#include "../../code/Headers/Mutual.h"
#include "../../code/classes/Humie/Humie.h"
#include "classes/ImportantValues/Important_Values.h"
TEST(check_op, test_eq ){
    Stud studtest1(4.5, 7.8);
    Stud studtest2(7.8, 4.5);
    Important_Values v;
    v.set_pchoice('v');
    EXPECT_EQ(studtest1<studtest2, false);
}

TEST(check_vid, test_eq) {
    Stud student;
    student.set_nd(5);
    student.set_nd(9);
    student.set_nd(8);
    student.set_nd(10);
    student.set_nd(7);
    student.set_ex(8);
    student.set_vid(student.get_ndsize());
    EXPECT_EQ(student.get_vid(),7.92);
}

TEST(check_vid2, test_eq) {
    vector<Stud> studs;
    Important_Values v;
    v.set_pchoice('v');
    Stud student;
    student.set_nd(5);
    student.set_nd(9);
    student.set_nd(8);
    student.set_nd(10);
    student.set_nd(7);
    student.set_ex(8);
    studs.push_back(student);
    Stud student2;
    student2.set_nd(5);
    student2.set_nd(9);
    student2.set_nd(8);
    student2.set_nd(10);
    student2.set_ex(8);
    studs.push_back(student2);
    calc(studs, v.get_pchoice());
    EXPECT_EQ(studs[1].get_vid(),7.36);
}
