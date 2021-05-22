#ifndef UF_H
#define UF_H

#include <stdbool.h>

typedef struct uf UF;

//intitializes a struct of type UF and returns a pointer to it
//@param size The number of objects in the UF
//@return A pointer to an UF
UF* UF_init(int size);

//creates an union between two objects inside uf
//@param uf The pointer to the UF
//@param p Integer to be connected
//@param q Integer to be connected
void UF_union(UF* uf, int p, int q);

//finds the root of the object p inside uf
//@param uf The pointer to the UF
//@param p Integer to find it's root
//@return The integer root of p
int UF_find(UF* uf, int p);

//tests if two elements p and q are connected inside uf
//@param uf The pointer to the UF
//@param p Integer to test connection
//@param q Integer to test connection
//@return True if p and q are connected, false if not
bool UF_connected(UF* uf, int p, int q);

//Frees the memory allocated by uf
//@param uf The pointer to the UF to be freed
void UF_delete(UF* uf);

#endif