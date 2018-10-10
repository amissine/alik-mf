/*
 * To compile and run:
 *
 *   gcc ./wrapped_dynarray.c && ./a.out
 */
#include <stdlib.h>
#include <stdio.h>

struct wrapper {
  size_t array_length;
  int array[];
};

int main (int argc, char * argv[]) {
  struct wrapper * w;
  printf("sizeof(struct wrapper): %zu, sizeof(w->array_length): %zu\n",
      sizeof(struct wrapper), sizeof(w->array_length));

  // Let us allocate 100 elements for the array.
  size_t size = 100;
  w = (struct wrapper *)malloc(sizeof(struct wrapper) + sizeof(int) * size);
  w->array_length = size;
  printf("sizeof(struct wrapper): %zu, w->array_length: %zu\n",
      sizeof(struct wrapper), w->array_length);

  // Clean up.
  free(w);
  return EXIT_SUCCESS;
}
