#include <stdio.h>
#include<stdlib.h>
int main()
{
  int i, a, b, middle, n, search,*array; 
 

  printf("Enter the number of elements :");
  scanf("%d", &n);
  array=(int*)malloc(n*sizeof(int));
 

  printf("Enter %d elements  : \n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);

  printf("Enter search value : ");
  scanf("%d", &search);

  a = 0 ;
  b = n - 1;
  middle = (a+b)/2;

  while (a <= b) {
    if (array[middle] < search)
      a = middle + 1;
    else if (array[middle] == search) {
      printf(" given value %d found at index %d !!!!!.\n", search, middle);
      break;
    }
    else
      b = middle - 1;

    middle = (a + b)/2;
  }
  if (a > b)
    printf("Not found! %d not present \n", search);

  return 0;
}
