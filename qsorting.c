// #include <stdio.h>
// #include <stdlib.h>
// #include<string.h>

// int comp(const void* a,const void* b) {
//       return strcmp(*(char**)a,*(char**)b);
// }

// int main() {
//     char *arr[5] = {"apple", "chikoo","banana", "guava", "pineapple"};
//       int n = sizeof(arr)/sizeof(arr[0]);
  
//       qsort(arr, n, sizeof(char **), comp);
  
//       for (int i = 0; i < n; i++) {
//           printf("%s ", arr[i]);
//     }
//       return 0;
// }

#include <stdio.h>

enum Days {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

int main() {
    enum Days today = WEDNESDAY;
    
    printf("Today is day number %s of the week.\n", Days[3]); // Output: 3
    return 0;
}
