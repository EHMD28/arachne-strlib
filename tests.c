#include "src/arachne_strlib.h"
#include <stdio.h>

int main(void) {
    const char* planets = "My Very Educated Mother Just Served Us Noodles";
    const char* current = NULL;
    ArachneString astr = arachne_new_str(planets);

    puts("Start");
    while ((current = arachne_read_word(&astr)) != NULL) {
        puts(current);
    }
    puts("End");

    arachne_free(&astr);
}
