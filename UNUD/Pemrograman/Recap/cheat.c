

int tambah(int n)
{
    if (n != 0)
    {
        return tambah(n - 1) + 2;
    }
    else
    {
        return 1;
    }
}
int main()
{

    printf("%d\n", tambah(3));
}