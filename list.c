/*
**	Basic list primitives 
**
**	Author: Pat Hanrahan
**  Date: 1982
*/
#include <stdlib.h>
#include "list.h"

LIST *
Member( size_t element, LIST *list )
{
    LIST *l;

    ForAllElements( l, list )
	if( l->car == element )
	    return l;
    return NULL;
}

LIST *
Intersection( LIST *list1, LIST *list2 )
{
    LIST *l;
    LIST *result;

    if( list1 == NULL ) return list2;
    if( list2 == NULL ) return list1;

    result = NULL;
    ForAllElements( l, list1 )
	if( Member( Car(l), list2 ) ) 
	    result = Cons( Car(l), result );
    return result;
}

LIST *
Union( LIST *list1, LIST *list2 )
{
    LIST *l;
    LIST *result;

    if( list1 == NULL ) return list2;
    if( list2 == NULL ) return list1;

    result = Copy(list2);
    ForAllElements( l, list1 )
	result = Insert( Car(l), result );
    return result;
}

LIST *
Concat( LIST *list1, LIST *list2 )
{
    LIST *l;

    if( list1 == NULL ) return list2;
    if( list2 == NULL ) return list1;

    for( l=list1; Cdr(l); l=Cdr(l) ) 
	;
    Cdr(l) = list2;
    return list1;
}

LIST *
Insert( size_t element, LIST *list )
{
    if( !Member( element, list ) )
	list = Cons( element, list );
    return list;
}

LIST *
Delete( size_t element, LIST *list )
{
    LIST *l;

    if( Car(list) == element )
	return Cdr(list);

    if( list )
	for( l=list; Cdr(l); l=Cdr(l) )
	    if( Car(Cdr(l)) == element ) {
		Cdr(l) = Cdr(Cdr(l));
		break;
	    }
    return list;
}

LIST *
Cons( size_t car, LIST *cdr )
{
    LIST *cell;

    cell = (LIST*) malloc( sizeof( LIST ) );

    if( cell ) {
	cell->car = car;
	cell->cdr = cdr;
    }

    return cell;
}

LIST *
Copy( LIST *list )
{
    /* Lazy copy ! */
    if( list )
        list = Cons( Car(list), Copy(Cdr(list)) );
    return list;
}

void
Free( LIST *list, int (*freecar)() )
{
    LIST *l;

    if( freecar ) 
	ForAllElements( l, list )
	    (*freecar)(Car(l));
  
    while( list ) {
	l = Cdr(list);
	free((char*)list);
	list = l;
    }
}

int 
Length( LIST *list )
{
    int n;

    for( n=0; list; list=Cdr(list) )
	n++;
    return n;
}

LIST *
Sort( LIST *list, int (*compare)() )
{
    LIST *l;
    int *a;
    int i;

    if( list ) {
	a = (int*) malloc( (size_t)(Length(list)*sizeof(int)) );
	i = 0;
	ForAllElements( l, list ) 
	    a[i++] = Car(l);
	qsort( (char*)a, i, sizeof(int), compare );
	i = 0;
	ForAllElements( l, list ) 
	    Car(l) = a[i++];
	free((char*)a);
    }
    return list;
}

LIST *
Reverse( LIST *list )
{
    LIST *l, *ln, *lnn;

    l   = NULL;
    ln  = list;
    lnn = Cdr(list);
    while( ln ) {
	Cdr(ln) = l;
	l   = ln;
	ln  = lnn;
	if( lnn )
	    lnn = Cdr(lnn);
    }
    return l;
}
