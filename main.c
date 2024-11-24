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
 t_localisation position_rover =loc_init(5, 6, NORTH);

int nb_mvt_analyser=9;

    p_tree tree= ARBRE_POSIBILITE(map,position_rover,nb_mvt_analyser); // Remplissage de l'arbre

for (int i=0; i<tree->root->nb_sons;i++){           //affiche les valeurs des premiers mouvement 
    printf("%d ",tree->root->sons[i]->value);
}
        return 0;
}
