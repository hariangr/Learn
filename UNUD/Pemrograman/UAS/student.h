struct Student
{
    char sex;
    int age;
    int studytime;
    int absence;
    int g1;
    int g2;
    int g3;
};

struct StudentsContainer
{
    int number;
    struct Student students[__INT_MAX__];
};