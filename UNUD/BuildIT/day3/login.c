#include <stdio.h>
#include <string.h>

struct User
{
    char username[100];
    char password[100];
};

struct User usersets[100];
int total_user = 0;

void readDatasets()
{
    FILE *reader = fopen("userdata.txt", "r");

    while (!feof(reader))
    {
        char _username[100];
        char _password[100];

        fflush(stdin);
        fscanf(reader, "%s %s", &_username[0], &_password[0]);

        struct User _user;
        strcpy(_user.username, _username);
        strcpy(_user.password, _password);

        usersets[total_user] = _user;

        total_user++;
    }
}

int login(char _username[100], char _password[100])
{
    for (int i = 0; i < total_user; i++)
    {
        struct User _user = usersets[i];

        if (strcmp(_user.username, _username) == 0 && strcmp(_user.password, _password) == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    readDatasets();

    char _username[100];
    printf("Masukkan username? ");
    scanf("%s", &_username[0]);

    char _password[100];
    printf("Masukkan password? ");
    scanf("%s", &_password[0]);

    int res = login(_username, _password);

    if (res == -1)
    {
        printf("Login gagal! Ulangi!\n");
        main();
    }
    else
    {
        printf("Login berhasil!\n");
        printf("Selamat datang %s\n", usersets[res].username);
    }
}