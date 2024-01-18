#ifndef __NO_H__
#define __NO_H__

#include "peca.h"
typedef struct No No;
struct No{

    Peca *peca;
    No *proximo;

};

#endif // __NO_H__