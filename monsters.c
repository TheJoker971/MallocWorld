//
// Created by Aymen on 18/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "monsters.h"
int degat;
int weapon;
int skip = 1;
int level = 3;

int initMonster(int id, Player p) {
    int result = 0;

    if (id >= 12 && id < 20) {
        Monster demon;
        demon.name = "Cyclope";
        demon.pv = 100;
        demon.experience = 5;
        printf("LE monstre s'appelle : %s\n", demon.name);
        result = combatMonstre(&demon, &p);
    } else if (id >= 20 && id < 40){
        Monster demon;
        demon.name = "Monstre de feu\n";
        demon.pv = 130;
        demon.experience = 10;
        printf("LE monstre s'appelle : %s\n", demon.name);
        result = combatMonstre(&demon, &p);
    } else if (id >= 40 && id < 60){
        Monster demon;
        demon.name = "Monstre d'eau\n";
        demon.pv = 160;
        demon.experience = 15;
        printf("LE monstre s'appelle : %s\n", demon.name);
        result = combatMonstre(&demon, &p);
    } else if (id >= 60 && id < 99){
        Monster demon;
        demon.name = "Monstre de terre\n";
        demon.pv = 200;
        demon.experience = 20;
        printf("LE monstre s'appelle : %s\n", demon.name);
        result = combatMonstre(&demon, &p);
    }
    return result;
}

int combatMonstre(Monster *monster, Player *p) {
    int result = 0;
    char yesNo;
    int choix;
    skip = 0;

    do {
        printf("Veux-tu commencer le combat ? (oui/non)\n");
        scanf(" %c", &yesNo);

        if (yesNo == 'o' || yesNo == 'O') {
            skip = 1;
            chooseArmeAfter(p);
        } else if (yesNo == 'n' || yesNo == 'N') {
            skip = 0;
        } else {
            printf("Erreur de saisie. Veuillez entrer 'o' pour oui ou 'n' pour non.\n");
        }
    } while (yesNo != 'o' && yesNo != 'O' && yesNo != 'n' && yesNo != 'N');

    if (skip) {
        // Logique de combat ici
        while(monster->pv > 0 && p->hp > 0 && degat > 0 && skip > 0){
            chooseMenu();
            scanf("%d", &choix);
            switch (choix) {
                case 1:
                    attaque(p, monster);
                    break;

                case 2:
                    printf("POTION");
                    break;

                case 3:
                    fuir(p);
                    break;

                default:
                    break;
            }
        }
        if (monster->pv <= 0) {
            printf("Le monstre est vaincu!\n");
            result = 1;
            levelZone();
            levelingHP(p);
        } else if(p->hp <=0){
            printf("Le joueur est vaincu!\n");
            result = 0;
        }
    }
    return result;
}

int chooseArmeAfter(Player *p){
    if(verifyDurability(p) == 1){
        printf("Vous n'avez plus aucune arme, FUIYEZ !\n");
        fuir(p);
        return 1;
    }
    verifyDurability(p);
    showWeaponsInInventory(p);
    //showInventory(*p);

    int isValidInput;
    do {
        printf("Quelle arme veux-tu ? (Entrez un nombre) :\n");
        isValidInput = scanf("%d", &weapon);

        // Vider le buffer d'entrée si l'utilisateur n'a pas entré un nombre
        if (!isValidInput) {
            printf("Erreur de saisie. Veuillez entrer un nombre.\n");
            while (getchar() != '\n'); 
            continue;
        }

        weapon -= 1;

        // Vérifier si l'entrée correspond à une arme valide
        if (weapon < 0 || !isWeapon(p->inventory[weapon].id)) {
            printf("Ce n'est pas une arme valide. Veuillez ressaisir.\n");
            isValidInput = 0; // Réinitialiser la validité de l'entrée
        }
    } while (!isValidInput);

    // Mettre à jour les dégâts et la durabilité de l'arme choisie
    degat = p->inventory[weapon].degats;
    printf("--------------------\n");
    printf("| %d de degats     |\n", degat);
    printf("| %d de durabilité |\n", p->inventory[weapon].durability);
    printf("--------------------\n\n");

    return 0;
}


int chooseArme(Player *p){
    showInventory(*p);
    printf("Quel arme veux-tu :\n");
    scanf("%d", &weapon);
    weapon -= 1;

    idArme(weapon);
    if(isWeapon(p->inventory[weapon].id)){
            degat = p->inventory[weapon].degats;
        }
    printf("--------------------\n");
    printf("| %d de degats     |\n", degat);
    printf("| %d de durabilité |\n", p->inventory->durability);
    printf("--------------------\n\n");
    return 0;
}

void firstAttaque(Player *p, Monster *monster){
    if (p->inventory[weapon].durability >= 0){
        chargerHPSauvegarde(p);
        printf("Le joueur attaque !\n");
        monster->pv -= degat;
        printf("Le monstre contre-attaque!\n");
        p->hp = p->hp - monster->experience; // Le monstre inflige 5 points de dégâts au joueur
        p->inventory[weapon].durability -= 1;
        afficherPointAttaque(p, monster);
        sauvegarderHP(p);
    } else if (p->inventory[weapon].durability <= 0){
        printf("\nL'arme est casser\n");
        chooseArme(p);
    }


}
void attaque(Player *p, Monster *monster){
    if (p->inventory[weapon].durability > 0){
        chargerHPSauvegarde(p);
        printf("Tu attaque !\n");
        monster->pv -= degat;
        p->hp = p->hp - 20; // Le monstre inflige 5 points de dégâts au joueur
        p->inventory[weapon].durability -= 1;
        printf("Il contre-attaque !\n");
        afficherPointAttaque(p, monster);
        sauvegarderHP(p);
    } else if (p->inventory[weapon].durability <= 0){
        printf("\nVotre arme est cassé\n");
        chooseArmeAfter(p);
    }
}

void afficherPointAttaque(Player *p, Monster *monster){
    printf("\n-----------------------------\n");
    printf("| Joueur  | %d point de vie |\n", p->hp);
    printf("| Monstre | %d point de vie |\n", monster->pv);
    printf("| Arme    | %d point de vie |\n", p->inventory[weapon].durability);
    printf("-----------------------------\n");
}

void chooseMenu(){
    printf("\n(1) ATTAQUER\n(2) POTION\n(3) FUIRE\nQuel veux-tu faire : ");
}

void idArme(int weapon){
    switch (weapon) {
        case 1:
            printf("Couteau : \n");
            break;

        case 2:
            printf("Hache : \n");
            break;

        case 3:
            printf("Épée en bois : \n");
            break;

        case 4:
            printf("Épée en diamant : \n");
            break;

        default:
            break;
    }
}

int fuir(Player *p){
    srand((unsigned int)time(NULL));

    printf("Le monstre vous as frappé dans le dos !\n");
    int nb = rand() % 10;
    printf("Nombre random: %d\n", nb);
    int nbA = 8;
    int nbB = 1; 
    int nbC = 4;

    if(nb == nbA || nb == nbB || nb == nbC){
        skip = 0;
        printf("Vous avez réussi à fuire !\n");
    } else {
        p->hp = 0;
        printf("Vous n'avez pas réussi à fuire !\n");
    }
    sauvegarderHP(p);
    return skip;
}

void sauvegarderHP(Player *p) {
    FILE *file = fopen("sauvegarde_hp.txt", "w"); // Ouvre le fichier en mode écriture
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return;
    }
    fprintf(file, "%d", p->hp); // Écrit les HP du joueur dans le fichier
    fclose(file); // Ferme le fichier
    printf("Les points de vie ont été sauvegardés.\n");
}

int chargerHPSauvegarde(Player *p) {
    int hp_sauvegarde;
    FILE *file = fopen("sauvegarde_hp.txt", "r"); // Ouvre le fichier en mode lecture
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return -1; // Retourne -1 pour indiquer une erreur
    }
    if (fscanf(file, "%d", &hp_sauvegarde) == 1) {
        p->hp = hp_sauvegarde; // Attribue la valeur lue aux HP du joueur
        printf("Les points de vie ont été chargés : %d\n", p->hp);
    } else {
        printf("Erreur lors de la lecture des points de vie sauvegardés.\n");
        fclose(file);
        return -1; // Retourne -1 pour indiquer une erreur
    }
    fclose(file); // Ferme le fichier
    return 0; // Retourne 0 pour indiquer le succès
}

void levelingHP(Player *p){
    if(level == 2) p->hp = 110;
    if(level == 3) p->hp = 120;
    if(level == 4) p->hp = 130;
    if(level == 5) p->hp = 140;
    if(level >= 6 && level <= 8) p->hp = 150;
    sauvegarderHP(p);
    printf("Tu est passer à %d de point de vie\n", p->hp);
}

int verifyDurability(Player *p){
    for(int i = 0; i<10; i++){
        if(isWeapon(p->inventory[i].id)){
            if(p->inventory[i].durability > 0){
                return 0;
            } 
        }
    }
    return 1;
}

void levelZone(){
    if(level >= 1 && level <= 3){
        level += 1;
    } else if(level >= 4 && level <= 7){
        level += 0.75;
    } else if(level >= 8 && level <= 10){
        level += 0.5;
    }
}

int myLevel(){
    int niveau = level;
    return level;
}
