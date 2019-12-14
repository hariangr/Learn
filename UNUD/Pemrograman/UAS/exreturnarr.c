#include "student.h"

struct StudentsContainer cobak()
{
    struct StudentsContainer s;
    s.number = 2;

    return s;
}

int main(int argc, char const *argv[])
{
    struct StudentsContainer x;
    x = cobak();

    return 0;
}
