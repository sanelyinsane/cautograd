#include <stdio.h>
#include <stdlib.h>
#include "src/n_core.h"
#include "src/n_math.h"


int main() {
	n_init();

        long shape[2] = {2, 2};
        double data[4] = {1.0, 2.0,
                          3.0, 4.0};

        NDARR *a = create_ones(2, shape);
        NDARR *b = create_ndarr(2, shape, data);
        NDARR *res;

        res = add(a, b);
        res = add(res, b);

        for (int i = 0; i < res->size; i++) {
                printf("%.2f ", res->data[i]);
        }
        printf("\n");
	lnode_traverse(LLIST);

	n_cleanup();

        return 0;
}
