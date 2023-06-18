#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

 //struktura pokémona
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

int fire_attack(int choice);
int water_attack(int choice);
int grass_attack(int choice);
int electric_attack(int choice);

int damage(int choice, Pokemon on_turn, Pokemon on_defense);

int main()
{
    srand(time(NULL));
    //volba pokémona
    int choice, attack, round = 1;

    printf("Vyber si pokemona:\n");

    printf("1. Charmander (fire)\n");
    printf("2. Squirtle (water)\n");
    printf("3. Bulbasaur (grass)\n");
    printf("4. Pikachu (electric)\n");

    scanf("%d", &choice);

    Pokemon player;
    Pokemon enemy;

    if (choice < 1 || choice > 4)
    {
        printf("Neplatná volba, bude pridelen nahodny pokemon\n");
        choice = rand() % 4 + 1;
    }

    if (choice == 1)
    {
        player =  (Pokemon) {"Charmander", 65, 5, 40, "fire", "Scratch", "Ember", "Fire Fang"};
    }
    else if (choice == 2)
    {
        player = (Pokemon) {"Squirtle", 100, 6, 20, "water", "Tackle", "Water Gun", "Bubble Beam"};
    }
    else if (choice == 3)
    {
        player = (Pokemon) {"Bulbasaur", 70, 12, 80, "grass", "Tackle", "Vine Whip", "Razor Leaf"};
    }
    else if (choice == 4)
    {
        player = (Pokemon) {"Pikachu", 95, 10, 90, "electric", "Quick Attack", "Thunder Shock", "Thunderbolt"};
    }


    //volba soupeře
    choice = rand() % 4 + 1;
     if (choice == 1)
    {
        enemy =  (Pokemon) {"Charmander", 65, 5, 40, "fire", "Scratch", "Ember", "Fire Fang"}; //? fire - střední rychlost, vysoký útok, nízká obrana, nízké HP
    }
    else if (choice == 2)
    {
        enemy = (Pokemon) {"Squirtle", 100, 6, 20, "water", "Tackle", "Water Gun", "Bubble Beam"}; //? water - nízká rychlost, střední útok, nízká obrana, vysoké HP
    }
    else if (choice == 3)
    {
        enemy = (Pokemon) {"Bulbasaur", 70, 15, 80, "grass", "Tackle", "Vine Whip", "Razor Leaf"}; //? grass - vysoká rychlost, nízký útok, vysoká obrana, nízké HP
    }
    else if (choice == 4)
    {
        enemy = (Pokemon) {"Pikachu", 95, 10, 90, "electric", "Quick Attack", "Thunder Shock", "Thunderbolt"}; //? electric - rychlý, střední útok a obrana, vysoké HP
    }

    system("cls");

    printf(" %s ( %s) vs %s ( %s)", player.name, player.type, enemy.name, enemy.type);
    if (player.speed >= enemy.speed)
    {
        printf("\nZacina hrac");
    }
    else
    {
        printf("\nZacina souper");
    }

    Sleep(2000);
    system("cls");

    while (player.hp > 0 && enemy.hp > 0)
    {
         if(player.speed >= enemy.speed)
        {
            printf("Hrac je na tahu:\n");
            printf("1. %s\t", player.attack1);
            printf("2. %s\t", player.attack2);
            printf("3. %s\n", player.attack3);

            scanf("%d", &choice);

            attack = damage(choice, player, enemy);
            printf("Zasah: %d\n", attack);
            enemy.hp -= attack;

            printf("souper je na tahu:\n");
            choice = rand() % 3 + 1;

            attack = damage(choice, enemy, player);
            printf("Zasah: %d\n", attack);
            player.hp -= attack;
        }
        else
        {
            printf("souper je na tahu:\n");
            choice = rand() % 3 + 1;

            attack = damage(choice, enemy, player);
            printf("Zasah: %d\n", attack);
            player.hp -= attack;

            printf("Hrac je na tahu:\n");
            printf("1. %s   ", player.attack1);
            printf("2. %s   ", player.attack2);
            printf("3. %s\n", player.attack3);

            scanf("%d", &choice);

            attack = damage(choice, player, enemy);
            printf("Zasah: %d\n", attack);
            enemy.hp -= attack;
        }

        Sleep(2000);
        system("cls");

        printf("Stav %d kola:\n", round);
        printf("Hrac: %d\n", player.hp);
        printf("Souper: %d\n", enemy.hp);

        Sleep(2000);
        system("cls");

        round++;
    }
    if (player.hp > 0)
    {
        printf("Vyhral jsi");
    }
    if (player.hp <= 0 && enemy.hp <= 0)
    {
        printf("Remiza");
    }
}

int fire_attack(int choice) // Vysoký útok
{
    int attack;

    if (choice == 1)
    {
        // Rozmezí útoku 40-50
        attack = rand() % 11 + 40;
    }
    else if (choice == 2)
    {
        // Rozmezí útoku 35-45
        attack = rand() % 11 + 35;
    }
    else if (choice == 3)
    {
        // Rozmezí útoku 45-55
        attack = rand() % 11 + 45;
    }
    else
    {
        attack = 0;
    }

    return attack;
}

int water_attack(int choice) // Střední útok
{
    int attack;

    if (choice == 1)
    {
        // Rozmezí útoku 35-45
        attack = rand() % 11 + 35;
    }
    else if (choice == 2)
    {
        // Rozmezí útoku 30-40
        attack = rand() % 11 + 30;
    }
    else if (choice == 3)
    {
        // Rozmezí útoku 40-50
        attack = rand() % 11 + 40;
    }
    else
    {
        attack = 0;
    }

    return attack;
}

int grass_attack(int choice) // Nízký útok
{
    int attack;

    if (choice == 1)
    {
        // Rozmezí útoku 30-40
        attack = rand() % 11 + 30;
    }
    else if (choice == 2)
    {
        // Rozmezí útoku 25-35
        attack = rand() % 11 + 25;
    }
    else if (choice == 3)
    {
        // Rozmezí útoku 35-45
        attack = rand() % 11 + 35;
    }
    else
    {
        attack = 0;
    }

    return attack;
}

int electric_attack(int choice) // Střední útok
{
    int attack;

    if (choice == 1)
    {
        // Rozmezí útoku 35-45
        attack = rand() % 11 + 35;
    }
    else if (choice == 2)
    {
        // Rozmezí útoku 30-40
        attack = rand() % 11 + 30;
    }
    else if (choice == 3)
    {
        // Rozmezí útoku 40-50
        attack = rand() % 11 + 40;
    }
    else
    {
        attack = 0;
    }

    return attack;
}



int damage(int choice, Pokemon on_turn, Pokemon on_defense)
{
    float attack, defense;

    if (strcmp(on_turn.type, "fire") == 0)
    {
        attack = fire_attack(choice);

        if(strcmp(on_defense.type, "fire") == 0)
        {
            defense = 0.5;
        }
        else if(strcmp(on_defense.type, "water") == 0)
        {
            defense = 0.5;
        }
        else if(strcmp(on_defense.type, "grass") == 0)
        {
            defense = 2;
        }
        else if(strcmp(on_defense.type, "electric") == 0)
        {
            defense = 1;
        }
    }
    else if (strcmp(on_turn.type, "water") == 0)
    {
        attack = water_attack(choice);

        if(strcmp(on_defense.type, "fire") == 0)
        {
            defense = 2;
        }
        else if(strcmp(on_defense.type, "water") == 0)
        {
            defense = 0.5;
        }
        else if(strcmp(on_defense.type, "grass") == 0)
        {
            defense = 0.5;
        }
        else if(strcmp(on_defense.type, "electric") == 0)
        {
            defense = 1;
        }

    }
    else if (strcmp(on_turn.type, "grass") == 0)
    {
        attack = grass_attack(choice);

        if(strcmp(on_defense.type, "fire") == 0)
        {
            defense = 0.5;
        }
        else if(strcmp(on_defense.type, "water") == 0)
        {
            defense = 2;
        }
        else if(strcmp(on_defense.type, "grass") == 0)
        {
            defense = 0.5;
        }
        else if(strcmp(on_defense.type, "electric") == 0)
        {
            defense = 1;
        }
    }
    else if (strcmp(on_turn.type, "electric") == 0)
    {
        attack = electric_attack(choice);

        if(strcmp(on_defense.type, "fire") == 0)
        {
            defense = 1;
        }
        else if(strcmp(on_defense.type, "water") == 0)
        {
            defense = 2;
        }
        else if(strcmp(on_defense.type, "grass") == 0)
        {
            defense = 0.5;
        }
        else if(strcmp(on_defense.type, "electric") == 0)
        {
            defense = 0.5;

        }
    }

    attack = attack * defense - on_defense.defense;
    if (attack < 0)
    {
        attack = 0;
    }
    
    return attack;
}