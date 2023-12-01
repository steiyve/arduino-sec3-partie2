#include <stdio.h>
#include <stdbool.h>

int liste[10];


int input()
{
    int chiffre = 0;
    scanf("%d", &chiffre);
    return chiffre;
}

float running_average()
{
    float moyenne = 0;
    for (int i = 0; i < 10; i++)
    {
        moyenne += liste[i];
    }
    moyenne = moyenne / 10;
    return moyenne;
}


int main()
{
    printf("code qui gener des mooving average\n");
    
    int last_pos = 0;
    while (true)
    {
        printf("entrez un chiffre\n");
        int chiffre = input();
        liste[last_pos] = chiffre;
        printf("la moyenne est de %f\n", running_average());

        printf("la liste est : %d element\n", last_pos);
        if (last_pos == 10)
        {
            last_pos = 0;
        }
        last_pos++;
    }
}