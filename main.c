#include <stdio.h>
#include "map.h"
#include "loc.h"
#include "tree.h"

int main() {
    t_map map = createMapFromFile("../maps/example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    t_localisation position_rover;
    position_rover = loc_init(5, 6, NORTH);
    p_tree tree=Create_abr(returne_val_pos(map,position_rover),5);
    int nb_move=5;
    t_move *ind_move= getRandomMoves(nb_move);  // Tire au sort des mouvements
    char ** lst= list_move(ind_move,3);     // liste de ch de char contenant tout les mouvements


    t_move * test=(t_move*)malloc(sizeof(t_move*)*5);
    test[0]=0;test[1]=4;test[2]=5;test[3]=1;test[4]=6;



    remplissage_arb(map, tree->root,ind_move,nb_move, position_rover) ; // Fonction de remplissage d'arbre
    printf("Done");

        return 0;
}
