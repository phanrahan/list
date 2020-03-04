#ifndef LISTDEF
#define LISTDEF

#include <stddef.h>

#ifndef NULL
#define NULL 0
#endif

typedef struct _list {

  size_t car;
  struct _list *cdr;

} LIST;

#define Cdr(l)    (l)->cdr
#define Cddr(l)   (l)->cdr->cdr
#define Cdddr(l)  (l)->cdr->cdr->cdr
#define Cddddr(l) (l)->cdr->cdr->cdr->cdr

#define Car(l)    (l)->car
#define Cadr(l)    (l)->cdr->car
#define Caddr(l)   (l)->cdr->cdr->car
#define Cadddr(l)  (l)->cdr->cdr->cdr->car
#define Caddddr(l) (l)->cdr->cdr->cdr->cdr->car

#define Null(l)	 ((l)==NULL)

LIST *Cons( size_t car, LIST *cdr );
LIST *Copy( LIST *l );
LIST *Insert( size_t e, LIST *l );
LIST *Delete( size_t e, LIST *l );
LIST *Member( size_t e, LIST *l );
LIST *Intersection( LIST *l1, LIST *l2 );
LIST *Union( LIST *l1, LIST *l2 );
LIST *Concat( LIST *l1, LIST *l2 );
LIST *Sort( LIST *l, int (*compare)() );
LIST *Reverse( LIST *l );
void  Free( LIST *l, int (*freecar)()  );
int   Length( LIST *k );

# define ForAllElements( lp, l ) for( lp=l; lp; lp=(lp)->cdr )

# endif
