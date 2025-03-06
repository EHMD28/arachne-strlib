#ifndef _ARACHNE_STRING_LIB_H_
#define _ARACHNE_STRING_LIB_H_

#include <stddef.h>

typedef struct ArachneString {
    const char* str;
    size_t start;
    size_t len;
    char* buf;
} ArachneString;


/**
 * @brief Creates a new instance of an Arachne String attached to a string. Start and end will be set
 * to zero. 
 */
extern struct ArachneString arachne_new_str(const char* s);

/**
 * @brief Creates a new instance of an Arachne String attached to a string. Uses `start` and `end` parameters
 * to create a range that goes from s[start] up to and including s[end].
 */
extern struct ArachneString arachne_new_range(const char* s, size_t start, size_t end);

/**
 * @brief Attaches an Arachne String to string `s`. Also resets start and end for range to zero. 
 */
extern void arachne_set_str(struct ArachneString* astr, const char* s);

/**
 * @brief Sets the range for an Arachne String using start and end (inclusive).
 */
extern void arachne_set_range(struct ArachneString* astr, size_t start, size_t end);

/**
 * @brief Returns a string containing the characters in a string from the start of an Arachne String's
 * range up to and including the end. WARNING. This does use dynamic memory allocation, so it is important
 * to call arachne_free() once you are done using an ArachneString.
 */
extern const char* arachne_get_range(struct ArachneString* astr);

/**
 * @brief Should be called on every Arachne String once the program no longer references it. It is
 * technically only necessary to call on functions which return the contents of the string in a range.
 */
extern void arachne_free(struct ArachneString* astr);

/**
 * @brief Each call to this function will read once word from the attached string. A "word" in this case
 * refers to a sequence of non-space characters (space characters including '\n' and '\0'). Subsequent
 * calls to this function will read the next word. This function will return null if there are are no more
 * words to read. 
 */
extern const char* arachne_read_word(struct ArachneString* astr);

#endif
