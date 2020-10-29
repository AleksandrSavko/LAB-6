#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int  strlen(char*);
void sort_hoara(char*, int, int);



int main()
{
    setlocale(LC_ALL, "RUS");
    char** str;
    char* str_osn;
    int kol_strok, kol_simvolov;
    int dl_stroki;

    int i, j, k;

    str_osn = (char*)malloc((80) * sizeof(char));
    k = 0;
    printf("������� ���������� �����\n");
    scanf_s("%d", &kol_strok);
    printf("������� ���������� �������� � ������\n");
    scanf_s("%d", &kol_simvolov);
    while (getchar() != '\n');

    // �������� ������ ��� ���������� �� ������
    str = (char**)malloc(kol_strok * sizeof(char*));
    // ���� ������, �� ������� �� ���������
    if (!str)
    {
        printf("������: ������ �� ��������.\n");
        return 0;
    }

    // �������� ������ ��� �����
    for (i = 0; i < kol_strok; i++)
    {
        str[i] = (char*)malloc((kol_simvolov + 1) * sizeof(char));
        // ���� ������, �� ����������� ������ � ������� �� ���������
        if (!str[i])
        {
            for (j = 0; j < i; ++j)
                free(str[j]);
            free(str);
            printf("������: ������ �� ��������.\n");
            return 0;
        }
    }

    // ���� �����
    for (i = 0; i < kol_strok; i++)
    {
        printf("������� ������ �%d �� ����� %d ��������\n", i + 1, kol_simvolov);
        fgets(str[i], kol_simvolov+1, stdin);
        while (getchar() != '\n');

    }

    //����� �����
    printf("��������� ���� �����\n");
    for (i = 0; i < kol_strok; i++)
    {
        puts(str[i]);
    }


    // ����� ����������
    for (i = 0; i < kol_strok; i++)
    {
        dl_stroki = strlen(str[i]);
        for (j = 0; j < dl_stroki; )
        {
            if (*(str[i] + j) < 91 && *(str[i] + j) > 64)
            {
                *(str_osn + k) = *(str[i] + j);

                k++;
                j++;
            }
            else j++;

        }
    }
    *(str_osn + k) = '\0';
    printf("������ �� ����������\n");
    puts(str_osn);
    sort_hoara(str_osn, 0, strlen(str_osn));

    // ������������ ������
    for (i = 0; i < kol_strok; i++)
    {
        free(str[i]);
    }
    free(str);
    free(str_osn);

    return 0;


}

// ������� ���������� ����� ������
int strlen(char* mss)
{
    int m = 0;
    while ((*(mss + m) != '\0') && (*(mss + m) != '\n'))
        m++;
    return m;
}

// ���������� ������� �����
void sort_hoara(char* str, int first, int last)
{
    int i = first, j = last-1;
    int  x = (i + j) / 2;
    char tmp;

    do
    {
        while (*(str + i) < *(str + x))
            i++;
        while (*(str + j) > * (str + x))
            j--;

        if ( i <= j)
        {
            if (i < j)
            {
                tmp = *(str + i);
                *(str + i) = *(str + j);
                *(str + j) = tmp;
            }
            i++;
            j--;
        }
    } while ( i <= j);

    if (i < last)
        sort_hoara(str, i, last);
    if (first < j)
        sort_hoara(str, first, j);

    printf("��������������� ������ \n");
    puts(str);
}