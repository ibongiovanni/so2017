#include <string.h>

#define BADKEY -1
#define O1 1
#define O2 2
#define O3 3
#define O4 4
#define O5 5
#define O6 6
#define O7 7

typedef struct { char *key; int val; } t_symstruct;

static t_symstruct lookuptable[] = {
    { "|", O1 }, { "<", O2 }, 
    { ">", O3 }, 
    { ">>", O4 }, 
    { ";", O5 }, 
    { "||", O6 }, 
    { "&&", O7 }
};

#define NKEYS (sizeof(lookuptable)/sizeof(t_symstruct))

int keyfromstring(char *key)
{
    int i;
    t_symstruct *sym;
    for (i=0; i < NKEYS; i++) {
        //sym = lookuptable + i*sizeof(t_symstruct); <- This causes segmetation fault
        sym = &lookuptable[i];
       
        //printf("%s\n",sym->key );
        if (strcmp(sym->key, key) == 0)
            return sym->val;
    }
    return BADKEY;
}
