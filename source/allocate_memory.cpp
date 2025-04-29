#include <malloc.h>

// second Comment
// Test Comment
int allocate_memory(int *ptrMemory, int size)
{
  if(ptrMemory == NULL)
    return (-1);

  for(int i=0; i<size; i++)
  {
    ptrMemory[i] = i+1;
  }

  return 0;
}
