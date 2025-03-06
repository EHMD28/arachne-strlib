# Arachne String Library
My personal header library for parsing strings in C, because it is a massive
pain in the donkey.

## Examples

### Word Reader Example
```c
#include "src/arachne_strlib.h"
#include <stdio.h>

int main(void) {
    const char* planets = "My Very Educated Mother Just Served Us Noodles";
    const char* current = NULL;
    ArachneString astr = arachne_new_str(planets);
    while ((current = arachne_read_word(&astr)) != NULL) {
        puts(current);
    }
    arachne_free(&astr);
}
```
