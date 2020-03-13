#include <stdio.h>
#include <stdlib.h>
#include <n_core.h>
#include <n_math.h>


int main() {
        int *shape = calloc(2, sizeof(int));
        shape[0] = 2;
        shape[1] = 3;

        NDARR *a = create_ones(2, shape);

        n_add(a, a, a);

        for (int i = 0; i < a->size; i++) printf("%.2f ", a->data[i]);

        printf("Hello dunia");
        return 0;
}
