#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "player.h"
#include "npc.h"
#include "movePlayer.h"
#include "monsters.h"

typedef struct Game{
    int*** map;
    Player p;
    Npc npc;
}Game;

Game setting();
int*** settingMap();
Player settingPlayer(Npc);
void startGame(Game,char[]);
void quitGame(Game);
void saveGame(Game);


int main(int argc, const char* argv[]){
    // Initialisation de la map, du npc et du joueur
    Game game = setting();

    // Autres initialisations...

    char s[10];
    printf("Tapez 'start' pour commencer le jeu : ");
    scanf("%s", s);
    startGame(game,s);

    // Nettoyage et libération des ressources
    quitGame(game);

    return 0;
}


Game setting(){
    Game g;
    g.map = settingMap();
    g.npc = initNpc();
    g.p = settingPlayer(g.npc);
    sauvegarderHP(&g.p);
    return g;
}

int*** settingMap(){
    char c;
    while(c !='n' && c != 'y'){
        printf("Voulez-vous lancer une nouvelle map (y/n) : ");
        scanf("%c",&c);
        getchar();
    }
    int*** map;
    if(c == 'y'){
        map = initMap();
    }else{
        map = chargeMap();
    }
    return map;
    
}
Player settingPlayer(Npc npc){
    char c;
    while(c!='n' && c!='y'){
        printf("Voulez-vous lancer un nouveau player (y/n) : ");
        scanf("%c",&c);
        getchar();
    }
    Player p;
    if(c == 'y'){
        p = initPlayer();
    }else{
        p = chargePlayer(npc);
    }
    return p;
}
void quitGame(Game g){
    freePlayer(g.p);
    freeNpc(g.npc);
    freeMap(g.map);
}

void startGame(Game g,char s[]){
    if (strcmp(s, "start") == 0) {
        int gameRunning = 1;
        int deplacement = 0;
        char quit;
        drawMap(g.map);
        while (gameRunning && g.p.hp > 0 ) {
            char depl;
            printf("\nDeplacez-vous avec z q s d :\n");
            scanf(" %c", &depl);

            if (depl == 'z' || depl == 's' || depl == 'q' || depl == 'd') {
                movePlayer(g.map, depl, g.p, g.npc);
                chargerHPSauvegarde(&g.p);
                deplacement ++ ;
                if (deplacement == 14){
                    g.map = reloadMap(g.map);
                    deplacement = 0;
                }
            } else if (depl == ';'){
                saveGame(g);
                printf("Vous quitter la partie");
                gameRunning = 0;
            } else {
                printf("Entrée non valide. Veuillez réessayer.\n");
            }
        }
    }
}

void saveGame(Game g){
    saveMap(g.map);
    savePlayer(g.p,g.npc.chest);
}







