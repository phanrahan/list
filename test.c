#include <stdio.h>
#include "list.h"

int 
compare(i,j)
int *i, *j;
{
  if( *i < *j ) return -1;
  if( *i > *j ) return  1;
  return 0;
}
main()
{
  LIST *l, *list;
  LIST *mist;
  LIST *nist;

  nist = Cons(1,Cons(2,Cons(3,NULL)));
  mist = Cons(2,Cons(4,Cons(3,NULL)));
  /*
  list = nist;
  ForAllElements( l, list )
    printf( "%d \n", Car(l) );
  printf( "Member(2,list) = %c \n", Member(2,list) ? 't' : 'f' );
  printf( "Member(5,list) = %c \n", Member(5,list) ? 't' : 'f' );
  list = Delete(1,list);
  list = Insert(4,list);
  list = Sort(list,compare);
  ForAllElements( l, list )
    printf( "%d ", Car(l) );
  printf( "\n" );
  printf( "Length(list) = %d \n", Length(list) );
  list = Reverse(Copy(list));
  ForAllElements( l, list )
    printf( "%d ", Car(l) );
  printf( "\n" );
  */
  printf( "mist\n" );
  list = mist;
  ForAllElements( l, list )
    printf( "%d ", Car(l) );
  printf( "\n" );
  printf( "nist\n" );
  list = nist;
  ForAllElements( l, list )
    printf( "%d ", Car(l) );
  printf( "\n" );
  printf( "Union\n" );
  list = Union(mist,nist);
  ForAllElements( l, list )
    printf( "%d ", Car(l) );
  printf( "\n" );
  printf( "Intersection\n" );
  list = Intersection(mist,nist);
  ForAllElements( l, list )
    printf( "%d ", Car(l) );
  printf( "\n" );
}
