#include "src/arachne_strlib.h"
#include <stdio.h>
#include <string.h>

void read_chars_example(void) {
    puts("Read Characters Example:");
    const char* str = "The quick brown fox jumps over the lazy dog";
    ArachneString astr = arachne_new_str(str);
    printf("Fist 10 characters: %s\n", arachne_read_chars(&astr, 10));
    arachne_free(&astr);
}

void read_range_example(void) {
    const char* str = "Let's eat, Grandma";
    puts("Read Range Example:");
    printf("String: %s\n", str);
    ArachneString first = arachne_new_range(str, 0, 9);
    ArachneString second = arachne_new_range(str, 10, 18);
    printf("First: \"%s\"\n", arachne_get_range(&first));
    printf("Second: \"%s\"\n", arachne_get_range(&second));
    printf("Whole: %s%s\n", arachne_get_range(&first),
           arachne_get_range(&second));
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

void read_rest_example(void) {
    puts("Read Rest Example:");
    const char* str = "Mr. Jock, TV quiz PhD, bags few lynx";
    ArachneString astr = arachne_new_str(str);
    arachne_read_chars(&astr, 18);
    printf("Rest of String: \"%s\"", arachne_read_rest(&astr));
    arachne_free(&astr);
}

int main(void) {
    puts("");
    read_chars_example();
    puts("");
    read_range_example();
    puts("");
    read_words_example();
    puts("");
    read_word_with_delimeter();
    puts("");
    read_rest_example();
    puts("");
}
