#ifndef MATH_H
#define MATH_H

#include <stdlib.h>
#include "n_core.h"

/**
 * In-place binary functions. Use whenever possible.
 **/
void n_add(NDARR *a, NDARR *b, NDARR *out);
void n_sub(NDARR *a, NDARR *b, NDARR *out);
void n_mul(NDARR *a, NDARR *b, NDARR *out);

NDARR *add(NDARR *a, NDARR *b);
NDARR *sub(NDARR *a, NDARR *b);
NDARR *mul(NDARR *a, NDARR *b);

#endif
