#include <stdio.h>
#include "map.h"
#include "loc.h"
#include "tree.h"

int main() {
    t_map map = createMapFromFile("..\\maps\\example1.map");
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
    displayMap(map);
    t_localisation position_rover;
    position_rover = loc_init(7, 6, NORTH);
    p_tree tree;
    tree= Create_abr(5);
    printf("val : %d\n",tree->root->value);
    char **liste_moove;
    liste_moove= list_move(5,6); // Liste des 5 mouvement tiré au hasard
    printf("Liste de mouvement tire au hasard :\n");
    for (int i = 0; i < 5; i++){
        printf("%s\t|",liste_moove[i]);
    }

    return 0;
}
