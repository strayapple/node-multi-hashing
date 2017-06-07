#ifndef ARGON2D_H
#define ARGON2D_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void Argon2dHash(const char* in, char* out);

#ifdef __cplusplus
}
#endif

#endif
