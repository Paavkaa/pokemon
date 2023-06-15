#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int fire_attack(int choice);
int water_attack(int choice);
int grass_attack(int choice);
int electric_attack(int choice);

int main()
{
    //struktura pokemona
    typedef struct
    {
        char name[20];
        int hp;
        int defense;
        int speed;
        char type[20];
        char attack1[20];
        char attack2[20];
        char attack3[20];
    } Pokemon;

    //volba pokemona
    int choice;
    printf("Vyber si pokemona:\n");
    //vypis pokemonu s jejich typem
    printf("1. Charmander (fire)\n");
    printf("2. Squirtle (water)\n");
    printf("3. Bulbasaur (grass)\n");
    printf("4. Pikachu (electric)\n");

    scanf("%d", &choice);

    //vytvoření pokemona
    //? fire - střední rychlost, vysoký útok, nízká obrana, nízké HP
    //? water - nízká rychlost, střední útok, nízká obrana, vysoké HP
    //? grass - vysoká rychlost, nízký útok, vysoká obrana, nízké HP
    //? electric - rychlý, střední útok a obrana, vysoké HP

    Pokemon Charmander = {"Charmander", 65, 10, 40, "fire", "Scratch", "Ember", "Fire Fang"}; 
    Pokemon Squirtle = {"Squirtle", 100, 12, 20, "water", "Tackle", "Water Gun", "Bubble Beam"};
    Pokemon Bulbasaur = {"Bulbasaur", 70, 35, 80, "grass", "Tackle", "Vine Whip", "Razor Leaf"};
    Pokemon Pikachu = {"Pikachu", 95, 20, 90, "electric", "Quick Attack", "Thunder Shock", "Thunderbolt"};


    return 0;
}

int fire_attack(int choice)
{
    if (choice == 1)
    {
        /* code */
    }
    else if (choice == 2)
    {
        /* code */
    }
    else if (choice == 3)
    {
        /* code */
    }
    else
    {
        /* code */
    }
}

int water_attack(int choice)
{
    if (choice == 1)
    {
        /* code */
    }
    else if (choice == 2)
    {
        /* code */
    }
    else if (choice == 3)
    {
        /* code */
    }
    else
    {
        /* code */
    }
}

int grass_attack(int choice)
{
    if (choice == 1)
    {
        /* code */
    }
    else if (choice == 2)
    {
        /* code */
    }
    else if (choice == 3)
    {
        /* code */
    }
    else
    {
        /* code */
    }
}

int electric_attack(int choice)
{
    if (choice == 1)
    {
        /* code */
    }
    else if (choice == 2)
    {
        /* code */
    }
    else if (choice == 3)
    {
        /* code */
    }
    else
    {
        /* code */
    }
}