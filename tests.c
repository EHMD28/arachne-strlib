#include "src/arachne_strlib.h"
#include <stdio.h>
#include <string.h>

void read_range_example(void) {
    const char* str = "Let's eat, Grandma";
    puts("Read Range Example:");
    printf("String: %s\n", str);
    struct ArachneString first = arachne_new_range(str, 0, 9);
    struct ArachneString second = arachne_new_range(str, 10, 18);
    printf("First: \"%s\"\n", arachne_get_range(&first));
    printf("Second: \"%s\"\n", arachne_get_range(&second));
    printf("%s%s\n", arachne_get_range(&first), arachne_get_range(&second));
}

void read_words_example(void) {
    const char* planets = "My Very Educated Mother Just Served Us Noodles";
    const char* current = NULL;
    ArachneString astr = arachne_new_str(planets);

    puts("Read Words Example:");
    printf("String: \"%s\"\n", planets);
    while ((current = arachne_read_word(&astr)) != NULL) {
        puts(current);
    }

    arachne_free(&astr);
}

void read_word_with_delimeter(void) {
    const char* foods = "Green Beans,Potatoes,Tomatoes,You Name It";
    const char* current = NULL;
    ArachneString astr = arachne_new_str(foods);

    puts("Read Words With Delimeter Example:");
    printf("String: \"%s\"\n", foods);
    while ((current = arachne_read_word_wd(&astr, ',')) != NULL) {
        puts(current);
    }

    arachne_free(&astr);
}

int main(void) {
    puts("");
    read_range_example();
    puts("");
    read_words_example();
    puts("");
    read_word_with_delimeter();
    puts("");
}
