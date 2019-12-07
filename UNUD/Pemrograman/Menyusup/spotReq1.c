#include <stdio.h>
#include <string.h>

struct User
{
    int id;
    char name[50];
};

struct User users[5];

void placeholderUsers()
{
    for (int i = 0; i < 5; i++)
    {
        users[i].id = i;
        strcpy(users[i].name, "Apalah");
    }
}

void printAllUsers()
{
    for (int i = 0; i < 5; i++)
    {
        printf("ID %d = %s\n", users[i].id, users[i].name);
    }
}

void removeById(int id)
{
    struct User temp[5];

    int _offset = 0;
    for (int i = 0; i < 5; i++)
    {
        if (users[i].id != id)
        {
            temp[_offset] = users[i];
            _offset++;
        }
    }

    memset(users, NULL, sizeof(users));

    for (int i = 0; i < _offset; i++)
    {
        users[i] = temp[i];
    }
}

int main(int argc, char const *argv[])
{
    placeholderUsers();

    printAllUsers();

    removeById(2);
    printf("___\nHapus id 2\n____\n");

    printAllUsers();

    return 0;
}
