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
    p_tree tree;
    t_move *ind_move= getRandomMoves(9);

    char ** lst= list_move(ind_move,9);
    for (int i=0;i<9;i++){
        printf("%d |",ind_move[i]);
    }
    remplissage_arb(map, tree,ind_move,9, position_rover) ;

    t_move *new= suppr( ind_move, ind_move[2], 9);





        return 0;
}
