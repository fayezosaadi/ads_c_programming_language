# Algorithms and Data Structures in C

## Prerequisites

- C compiler (gcc, clang, etc.)
- Make (optional)

## Building and Running

```bash
# Compile
gcc -Wall -Wextra code.c main.c -o main

# Run program
./main
```

## Example Usage

```c
#include "doubly_linked_list.h"

static void print_node_int(const void *value) {
    printf("%d ", *(const int *) value);
}

int main() {
    List *list = list_create(print_node_int);
    
    int a = 10, b = 20, c = 30;
    
    list_append(list, &a);
    list_prepend(list, &b);
    list_insert(list, 1, &c);
    
    printf("List contents: ");
    print_list(list);  // Output: 20 30 10
    
    list_reverse(list);
    
    printf("Reversed: ");
    print_list(list);  // Output: 10 30 20
    
    list_destroy(list);
    return 0;
}
```
