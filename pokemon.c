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
int fight(Pokemon player, Pokemon enemy);

int main()
{
    srand(time(NULL));
    //volba pokémona
    int choice;
    printf("Vyber si pokemona:\n");

    printf("1. Charmander (fire)\n");
    printf("2. Squirtle (water)\n");
    printf("3. Bulbasaur (grass)\n");
    printf("4. Pikachu (electric)\n");

    scanf("%d", &choice);

    Pokemon player;
    Pokemon enemy;

    if (choice == 1)
    {
        player =  (Pokemon) {"Charmander", 65, 10, 40, "fire", "Scratch", "Ember", "Fire Fang"};
    }
    else if (choice == 2)
    {
        player = (Pokemon) {"Squirtle", 100, 12, 20, "water", "Tackle", "Water Gun", "Bubble Beam"};
    }
    else if (choice == 3)
    {
        player = (Pokemon) {"Bulbasaur", 70, 35, 80, "grass", "Tackle", "Vine Whip", "Razor Leaf"};
    }
    else if (choice == 4)
    {
        player = (Pokemon) {"Pikachu", 95, 20, 90, "electric", "Quick Attack", "Thunder Shock", "Thunderbolt"};
    }
    else
    {
        printf("Neplatná volba\n");
        return 0;
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

    fight(player, enemy);

    return 0;
}

int fire_attack(int choice) //? vysoký útok
{
    int attack;

    if (choice == 1)
    {
        //rozmezí útoku 35-45
        attack = rand() % 11 + 35;
    }
    else if (choice == 2)
    {
        //rozmezí útoku 20-50
        attack = rand() % 21 + 30;
    }
    else if (choice == 3)
    {
        //rozmezí útoku 38-43
        attack = rand() % 4 + 40;
    }
    else
    {
        attack = 0;
    }

    return attack;
}

int water_attack(int choice) //? střední útok
{
    int attack;

    if (choice == 1)
    {
        //rozmezí útoku 25-35
        attack = rand() % 11 + 25;
    }
    else if (choice == 2)
    {
        //rozmezí útoku 20-40
        attack = rand() % 21 + 20;
    }
    else if (choice == 3)
    {
        //rozmezí útoku 32-38
        attack = rand() % 7 + 32;
    }
    else
    {
        attack = 0;
    }

    return attack;
}

int grass_attack(int choice) //? nízký útok
{
    int attack;

    if (choice == 1)
    {
        //rozmezí útoku 15-25
        attack = rand() % 11 + 15;
    }
    else if (choice == 2)
    {
        //rozmezí útoku 10-30
        attack = rand() % 21 + 10;
    }
    else if (choice == 3)
    {
        //rozmezí útoku 27-32
        attack = rand() % 6 + 27;
    }
    else
    {
        attack = 0;
    }

    return attack;
}

int electric_attack(int choice) //? střední útok
{
    int attack;

    if (choice == 1)
    {
        //rozmezí útoku 25-35
        attack = rand() % 11 + 25;
    }
    else if (choice == 2)
    {
        //rozmezí útoku 20-40
        attack = rand() % 21 + 20;
    }
    else if (choice == 3)
    {
        //rozmezí útoku 32-38
        attack = rand() % 7 + 32;
    }
    else
    {
        attack = 0;
    }

    return attack;
}

int damage(int choice, Pokemon on_turn, Pokemon on_defense)
{
    int damage, defense;

    if (strcmp(on_turn.type, "fire") == 0)
    {
        damage = fire_attack(choice);

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
        damage = water_attack(choice);

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
        damage = grass_attack(choice);

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
        damage = electric_attack(choice);

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

    damage = damage * defense - on_defense.defense;
    return damage;
}

int fight(Pokemon player, Pokemon enemy)
{
    int choice, attack, round = 1;
    printf(" %s ( %s) vs %s ( %s)", player.name, player.type, enemy.name, enemy.type);
    if (player.speed >= enemy.speed)
    {
        printf("Zacina hrac");
    }
    else
    {
        printf("Zacina souper");
    }

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
        }

        if(enemy.hp > 0)
        {
            printf("souper je na tahu:\n");
            choice = rand() % 3 + 1;

            attack = damage(choice, enemy, player);
            printf("Zasah: %d\n", attack);
            player.hp -= attack;
        }

        printf("Stav %d kola:\n", round);
        printf("Hrac: %d\n", player.hp);
        printf("Souper: %d\n", enemy.hp);

        round++;
    }
    if (player.hp > 0)
    {
        printf("Vyhral jsi");
        return 1;
    }
    else
    {
        printf("Prohral jsi");
        return 0;
    }
}