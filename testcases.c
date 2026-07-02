#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <bsd/string.h>
#include <stdarg.h>

#define RANDVAL(min, max) (rand() % ((max) - (min) + 1)) + (min)
#define TSTMSG(_M) (ft_putstrln("Testing function " #_M))
#define TSTFN(_FN_NAME)    \
    void test_##_FN_NAME() \
    {                      \
        TSTMSG(_FN_NAME);
#define TSTFN_END                                \
    ft_putstrln("Function passed successfully"); \
    }

static void ft_putstrln(char *str)
{
    size_t l = 0;
    while (str[l])
        l++;
    write(STDOUT_FILENO, str, l);
    write(STDOUT_FILENO, "\n", 1);
}

static char *string_filled_rnd(int length)
{
    char *str = malloc(length + 1);
    if (!str)
        return 0;
    str[length] = 0;
    for (int i = 0; i < length; i++)
        str[i] = (char)RANDVAL(32, 126);
    return str;
}

int strarrcmp(char **strarr1, char **strarr2)
{
    while (*strarr1 && *strarr2)
    {
        int cr = strcmp(*strarr1, *strarr2);
        if (cr)
            return (cr);
        strarr1++;
        strarr2++;
    }
    if (*strarr1 && !*strarr2)
        return (1);
    if (!*strarr1 && *strarr2)
        return (-1);
    return (0);
}

static char **strarr_from_va(size_t argc, ...)
{
    char **result = ft_calloc(argc + 1, sizeof(char *));
    va_list args;
    va_start(args, argc);

    for (int i = 0; i < argc; i++)
        result[i] = strdup(va_arg(args, const char *));

    va_end(args);
    return (result);
}

TSTFN(ctype_macro)
for (int i = -128; i <= 127; i++)
{
    assert(!!isalpha(i) == !!ft_isalpha(i));
    assert(!!isdigit(i) == !!ft_isdigit(i));
    assert(!!isalnum(i) == !!ft_isalnum(i));
    assert(!!isascii(i) == !!ft_isascii(i));
    assert(!!isprint(i) == !!ft_isprint(i));
}
TSTFN_END

TSTFN(strlen)
for (int i = 0; i < 1024; i++)
{
    char *str = string_filled_rnd(i);
    assert(str);
    assert(strlen(str) == ft_strlen(str));
    free(str);
}
TSTFN_END

TSTFN(memset)
char mset[2048], ft_mset[2048];
int sizetest = 16;
memset(mset, 'a', sizetest);
ft_memset(ft_mset, 'a', sizetest);
assert(!memcmp(mset, ft_mset, sizetest));
sizetest = 0;
memset(mset, 'b', sizetest);
ft_memset(ft_mset, 'b', sizetest);
assert(!memcmp(mset, ft_mset, sizetest));
sizetest = 1024;
memset(mset, 'c', sizetest);
ft_memset(ft_mset, 'c', sizetest);
assert(!memcmp(mset, ft_mset, sizetest));
TSTFN_END

TSTFN(bzero)
char mset[2048], ft_mset[2048];
int sizetest = 16;
bzero(mset, sizetest);
ft_bzero(ft_mset, sizetest);
assert(!memcmp(mset, ft_mset, sizetest));
sizetest = 0;
bzero(mset, sizetest);
ft_bzero(ft_mset, sizetest);
assert(!memcmp(mset, ft_mset, sizetest));
sizetest = 1024;
bzero(mset, sizetest);
ft_bzero(ft_mset, sizetest);
assert(!memcmp(mset, ft_mset, sizetest));
sizetest = 2048;
bzero(mset, sizetest);
ft_bzero(ft_mset, sizetest);
assert(!memcmp(mset, ft_mset, sizetest));
TSTFN_END

TSTFN(memcpy)
for (int i = 0; i < 1024; i++)
{
    char *str = string_filled_rnd(i);
    assert(str);
    char *mem = malloc(i + 1), *ft_mem = malloc(i + 1);
    assert(mem);
    assert(ft_mem);
    memcpy(mem, str, i);
    assert(ft_mem == ft_memcpy(ft_mem, str, i));
    assert(!memcmp(mem, ft_mem, i));
    free(str);
    free(mem);
    free(ft_mem);
}
TSTFN_END

TSTFN(memmove)
for (int i = 1; i <= 1024; i++)
{
    char *str = string_filled_rnd(i);
    assert(str);
    char *mem = malloc(i + 1), *ft_mem = malloc(i + 1);
    assert(mem);
    assert(ft_mem);
    memcpy(mem, str, i);
    memcpy(ft_mem, str, i);

    int rnd = RANDVAL(0, i - 1);
    int len = i - rnd;

    memmove(mem, mem + rnd, len);
    ft_memmove(ft_mem, ft_mem + rnd, len);
    assert(!memcmp(mem, ft_mem, len));
    rnd = RANDVAL(0, i - 1);
    int max_safe_len = i - rnd;
    len = RANDVAL(0, max_safe_len);

    memmove(mem + rnd, mem, len);
    ft_memmove(ft_mem + rnd, ft_mem, len);
    assert(!memcmp(mem, ft_mem, i));

    free(str);
    free(mem);
    free(ft_mem);
}
TSTFN_END
TSTFN(strlcpy)
for (int i = 1; i <= 1024; i++)
{
    int rnd;
    char *str = string_filled_rnd(i);
    char *s1 = malloc(i + 1), *s2 = malloc(i + 1);
    assert(str);
    assert(s1);
    assert(s2);

    assert(strlcpy(s1, str, i + 1) == ft_strlcpy(s2, str, i + 1));
    assert(!memcmp(s1, s2, i + 1));
    assert(strlcpy(s1, str, 0) == ft_strlcpy(s2, str, 0));
    assert(!memcmp(s1, s2, i + 1));
    rnd = RANDVAL(0, i);
    assert(strlcpy(s1, str, rnd) == ft_strlcpy(s2, str, rnd));
    assert(!memcmp(s1, s2, i + 1));
    rnd = RANDVAL(0, i);
    assert(strlcpy(s1, str, rnd) == ft_strlcpy(s2, str, rnd));
    assert(!memcmp(s1, s2, i + 1));
    rnd = RANDVAL(0, i);
    assert(strlcpy(s1, str, rnd) == ft_strlcpy(s2, str, rnd));
    assert(!memcmp(s1, s2, i + 1));

    free(str);
    free(s1);
    free(s2);
}
TSTFN_END
TSTFN(strlcat)
for (int i = 1; i <= 1024; i++)
{
    int rnd = RANDVAL(1, i);
    char *str = string_filled_rnd(rnd);
    char *add = string_filled_rnd(i - rnd);
    char *s1 = malloc(i + 1), *s2 = malloc(i + 1);

    strlcpy(s1, str, i);
    strlcpy(s2, str, i);
    assert(strlcat(s1, add, i + 1) == ft_strlcat(s2, add, i + 1));
    assert(!memcmp(s1, s2, i));

    free(str);
    free(add);
    free(s1);
    free(s2);
}
TSTFN_END
TSTFN(switchcasing)
for (int i = 0; i <= 255; i++)
{
    assert((char)tolower(i) == (char)ft_tolower(i));
    assert((char)toupper(i) == (char)ft_toupper(i));
}
TSTFN_END
TSTFN(strchr)
for (int i = 2; i <= 1024; i++)
{
    int rnd = RANDVAL(1, i);
    char *str = string_filled_rnd(i);
    char c = str[rnd];

    assert(strchr(str, c) == ft_strchr(str, c));
    assert(strchr(str, 0) == ft_strchr(str, 0));
    assert(strchr(str, 1) == ft_strchr(str, 1));
    assert(strchr(str, 314) == ft_strchr(str, 314));
    assert(strchr(str, -1684) == ft_strchr(str, -1684));

    free(str);
}
TSTFN_END

TSTFN(strrchr)
for (int i = 2; i <= 1024; i++)
{
    int rnd = RANDVAL(1, i);
    char *str = string_filled_rnd(i);
    char c = str[rnd];

    assert(strrchr(str, c) == ft_strrchr(str, c));
    assert(strrchr(str, 0) == ft_strrchr(str, 0));
    assert(strrchr(str, 1) == ft_strrchr(str, 1));
    assert(strrchr(str, 314) == ft_strrchr(str, 314));
    assert(strrchr(str, -1684) == ft_strrchr(str, -1684));

    free(str);
}
TSTFN_END
TSTFN(strncmp)
for (int i = 1; i <= 1024; i++)
{
    char *str1 = string_filled_rnd(i);
    char *str2 = string_filled_rnd(i);

    assert(strncmp(str1, str2, i) == ft_strncmp(str1, str2, i));
    assert(strncmp(str1, str2, 0) == ft_strncmp(str1, str2, 0));
    if (i > 2)
        assert(strncmp(str1, str2, i / 2) == ft_strncmp(str1, str2, i / 2));

    free(str1);
    free(str2);
}
TSTFN_END
TSTFN(memchr)
for (int i = 2; i <= 1024; i++)
{
    int rnd = RANDVAL(1, i);
    char *str = string_filled_rnd(i);
    char c = str[rnd];

    assert(memchr(str, c, i) == ft_memchr(str, c, i));
    assert(memchr(str, 0, i) == ft_memchr(str, 0, i));
    assert(memchr(str, 1, i) == ft_memchr(str, 1, i));
    assert(memchr(str, 314, i) == ft_memchr(str, 314, i));
    assert(memchr(str, -1684, i) == ft_memchr(str, -1684, i));

    rnd = RANDVAL(2, i);

    assert(memchr(str, c, rnd) == ft_memchr(str, c, rnd));
    assert(memchr(str, 0, rnd) == ft_memchr(str, 0, rnd));
    assert(memchr(str, 1, rnd) == ft_memchr(str, 1, rnd));
    assert(memchr(str, 314, rnd) == ft_memchr(str, 314, rnd));
    assert(memchr(str, -1684, rnd) == ft_memchr(str, -1684, rnd));

    free(str);
}
TSTFN_END
TSTFN(memcmp)
for (int i = 1; i <= 1024; i++)
{
    char *str1 = string_filled_rnd(i);
    char *str2 = string_filled_rnd(i);

    assert(memcmp(str1, str2, i) == ft_memcmp(str1, str2, i));
    assert(memcmp(str1, str2, 0) == ft_memcmp(str1, str2, 0));
    if (i > 2)
        assert(memcmp(str1, str2, i / 2) == ft_memcmp(str1, str2, i / 2));

    free(str1);
    free(str2);
}
TSTFN_END
TSTFN(strnstr)
for (int i = 64; i <= 1024; i++)
{
    int rnd = RANDVAL(64, 1024 - 8) - 1;
    char *str = string_filled_rnd(i);
    char *needle = malloc(9);
    needle[8] = 0;
    for (int i = 0; i < 8; i++)
        needle[i] = str[rnd + i];

    assert(strnstr(str, needle, i) == ft_strnstr(str, needle, i));
    assert(strnstr(str, "", i) == ft_strnstr(str, "", i));
    assert(strnstr("", needle, i) == ft_strnstr("", needle, i));
    assert(strnstr(str, needle, 0) == ft_strnstr(str, needle, 0));
    assert(strnstr(str, "\1\1\1", 0) == ft_strnstr(str, "\1\1\1", 0));
    if (i % 2 == 0 && i >= 4)
        assert(strnstr(str, needle, i / 2) == ft_strnstr(str, needle, i / 2));

    free(str);
    free(needle);
}
TSTFN_END
TSTFN(atoi)
char *val = "-1";
assert(atoi(val) == ft_atoi(val));
val = "-2147483648";
assert(atoi(val) == ft_atoi(val));
val = "2147483647";
assert(atoi(val) == ft_atoi(val));
val = "0";
assert(atoi(val) == ft_atoi(val));
val = "+186";
assert(atoi(val) == ft_atoi(val));
val = "-186";
assert(atoi(val) == ft_atoi(val));
val = "--fg";
assert(atoi(val) == ft_atoi(val));
val = "-";
assert(atoi(val) == ft_atoi(val));
TSTFN_END
TSTFN(substr)
char *str = string_filled_rnd(1024);
char *sub;

sub = ft_substr(str, 0, 16);
assert(!strncmp(str, sub, 16));
free(sub);
sub = ft_substr(str, 157, 16);
assert(!strncmp(str + 157, sub, 16));
free(sub);
sub = ft_substr(str, 1023, 16);
assert(!strncmp(str + 1023, sub, 16));
free(sub);
sub = ft_substr(str, 0, 0);
assert(!strncmp("", sub, 16));
free(sub);
sub = ft_substr(str, 0, 1024);
assert(!strncmp(str, sub, 1024));
free(sub);
TSTFN_END
TSTFN(strjoin)
char *s1 = "My ", *s2 = "string";
char *join = ft_strjoin(s1, s2);

assert(!strcmp(join, "My string"));
free(join);
s1 = "Bull", s2 = "shit";
join = ft_strjoin(s1, s2);
assert(!strcmp(join, "Bullshit"));
free(join);
s1 = "", s2 = "shit";
join = ft_strjoin(s1, s2);
assert(!strcmp(join, "shit"));
free(join);
s1 = "", s2 = "";
join = ft_strjoin(s1, s2);
assert(!strcmp(join, ""));
free(join);
s1 = "", s2 = "";
join = ft_strjoin(s1, s2);
assert(!strcmp(join, ""));
free(join);
s1 = "Love ", s2 = "me";
join = ft_strjoin(s1, s2);
assert(!strcmp(join, "Love me"));
free(join);
TSTFN_END

void cleanup_splitted(char **splitted)
{
	size_t i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

TSTFN(split)
#pragma region split
/* Test 1: Basic case with multiple words and varying delimiter spacing */
char **splitted = ft_split(" Bug Arc    Is N ever true", ' ');
char **expected = strarr_from_va(6, "Bug", "Arc", "Is", "N", "ever", "true");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 2: Empty string returns null-terminated array with just NULL */
splitted = ft_split("", ' ');
expected = strarr_from_va(0);
assert(splitted);
assert(splitted[0] == NULL);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 3: String with only delimiters returns null-terminated array with just NULL */
splitted = ft_split("     ", ' ');
expected = strarr_from_va(0);
assert(splitted);
assert(splitted[0] == NULL);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 4: Single word, no delimiters */
splitted = ft_split("hello", ' ');
expected = strarr_from_va(1, "hello");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 5: String starting with delimiters */
splitted = ft_split("   hello world", ' ');
expected = strarr_from_va(2, "hello", "world");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 6: String ending with delimiters */
splitted = ft_split("hello world   ", ' ');
expected = strarr_from_va(2, "hello", "world");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 7: Single character string */
splitted = ft_split("a", ' ');
expected = strarr_from_va(1, "a");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 8: Single delimiter character returns null-terminated array with just NULL */
splitted = ft_split(" ", ' ');
expected = strarr_from_va(0);
assert(splitted);
assert(splitted[0] == NULL);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 9: Single word surrounded by delimiters */
splitted = ft_split("   hello   ", ' ');
expected = strarr_from_va(1, "hello");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 10: Words separated by single delimiter */
splitted = ft_split("one two three", ' ');
expected = strarr_from_va(3, "one", "two", "three");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 11: Tab as delimiter */
splitted = ft_split("hello\tworld\there", '\t');
expected = strarr_from_va(3, "hello", "world", "here");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 12: Numbers as strings */
splitted = ft_split("123 456 789", ' ');
expected = strarr_from_va(3, "123", "456", "789");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 13: Special characters */
splitted = ft_split("!@# $%^ &*()", ' ');
expected = strarr_from_va(3, "!@#", "$%^", "&*()");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 14: Consecutive delimiters produce no empty strings */
splitted = ft_split("a  b   c", ' ');
expected = strarr_from_va(3, "a", "b", "c");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 15: Delimiters at both start and end */
splitted = ft_split("  a b c  ", ' ');
expected = strarr_from_va(3, "a", "b", "c");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 16: Newline as delimiter */
splitted = ft_split("line1\nline2\nline3", '\n');
expected = strarr_from_va(3, "line1", "line2", "line3");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 17: Comma as delimiter */
splitted = ft_split("red,green,blue", ',');
expected = strarr_from_va(3, "red", "green", "blue");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 18: Empty strings between delimiters should not appear */
splitted = ft_split(",,test,,value,,", ',');
expected = strarr_from_va(2, "test", "value");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 19: Pipe as delimiter */
splitted = ft_split("cmd1|cmd2|cmd3", '|');
expected = strarr_from_va(3, "cmd1", "cmd2", "cmd3");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 20: Colon as delimiter (PATH-like) */
splitted = ft_split("/usr/bin:/usr/local/bin:/home/bin", ':');
expected = strarr_from_va(3, "/usr/bin", "/usr/local/bin", "/home/bin");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);

/* Test 21: Hyphen as delimiter */
splitted = ft_split("one-two-three", '-');
expected = strarr_from_va(3, "one", "two", "three");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);
splitted = ft_split("a b c d e", ' ');
expected = strarr_from_va(5, "a", "b", "c", "d", "e");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);
splitted = ft_split("hello\t world", ' ');
expected = strarr_from_va(2, "hello\t", "world");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);
splitted = ft_split("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", ' ');
expected = strarr_from_va(1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);
splitted = ft_split("echo hello;echo world;exit", ';');
expected = strarr_from_va(3, "echo hello", "echo world", "exit");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);
splitted = ft_split("     a     ", ' ');
expected = strarr_from_va(1, "a");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);
splitted = ft_split("hello world", 0);
expected = strarr_from_va(1, "hello world");
assert(splitted);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);
splitted = ft_split(",,,", ',');
expected = strarr_from_va(0);
assert(splitted);
assert(splitted[0] == NULL);
assert(!strarrcmp(splitted, expected));
cleanup_splitted(splitted);
cleanup_splitted(expected);
#pragma endregion
TSTFN_END

TSTFN(itoa)
    char *itoad;

    /* Extreme boundaries (from your original code) */
    itoad = ft_itoa(INT_MAX);
    assert(!strcmp(itoad, "2147483647"));
    free(itoad);
    
    itoad = ft_itoa(INT_MIN);
    assert(!strcmp(itoad, "-2147483648"));
    free(itoad);

    /* Zero (often breaks naive implementations) */
    itoad = ft_itoa(0);
    assert(!strcmp(itoad, "0"));
    free(itoad);

    /* Single digits */
    itoad = ft_itoa(7);
    assert(!strcmp(itoad, "7"));
    free(itoad);

    itoad = ft_itoa(-3);
    assert(!strcmp(itoad, "-3"));
    free(itoad);

    /* Multi-digit numbers */
    itoad = ft_itoa(42);
    assert(!strcmp(itoad, "42"));
    free(itoad);

    itoad = ft_itoa(-42);
    assert(!strcmp(itoad, "-42"));
    free(itoad);

    itoad = ft_itoa(123456789);
    assert(!strcmp(itoad, "123456789"));
    free(itoad);

    itoad = ft_itoa(-987654321);
    assert(!strcmp(itoad, "-987654321"));
    free(itoad);
    itoad = ft_itoa(10);
    assert(!strcmp(itoad, "10"));
    free(itoad);

    itoad = ft_itoa(-1000);
    assert(!strcmp(itoad, "-1000"));
    free(itoad);

    itoad = ft_itoa(1000000000);
    assert(!strcmp(itoad, "1000000000"));
    free(itoad);
TSTFN_END

static void caesar_by_ten(unsigned int idx, char* c)
{
    (void)idx; // Suppress unused parameter warning

    if (c == NULL || !ft_isalpha(*c))
        return ;

    if (*c >= 'a' && *c <= 'z')
        *c = 'a' + (*c - 'a' + 10) % 26;
    else if (*c >= 'A' && *c <= 'Z')
        *c = 'A' + (*c - 'A' + 10) % 26;
}

static char caesar_by_ten_m(unsigned int idx, char c)
{
    (void)idx; // Suppress unused parameter warning

    if (!ft_isalpha(c))
        return c;

    if (c >= 'a' && c <= 'z')
        c = 'a' + (c - 'a' + 10) % 26;
    else if (c >= 'A' && c <= 'Z')
        c = 'A' + (c - 'A' + 10) % 26;
    return (c);
}

TSTFN(strmapi)
    char text[] = "This text is about to be ciphered!";
    char exp[] = "Drsc dohd sc klyed dy lo mszrobon!";

    char *new = ft_strmapi(text, caesar_by_ten_m);
    assert(!strcmp(exp, new));
    free(new);
TSTFN_END

TSTFN(striteri)
    char text[] = "This text is about to be ciphered!";
    char exp[] = "Drsc dohd sc klyed dy lo mszrobon!";

    ft_striteri(text, caesar_by_ten);
    assert(!strcmp(exp, text));
TSTFN_END

TSTFN(putchar_fd)
    char buffer[2] = {0};
    
    // 1. Test Random Printable Char
    char c = (char)RANDVAL(32, 126);
    int fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    assert(fd >= 0);
    ft_putchar_fd(c, fd);
    close(fd);

    fd = open("test_putchar.txt", O_RDONLY);
    assert(fd >= 0);
    assert(read(fd, buffer, 1) == 1);
    close(fd);
    assert(buffer[0] == c);

    // 2. Test Edge Characters (Null byte, newline, tab, non-printable)
    char edges[] = {'\0', '\n', '\t', ' ', 127, -128};
    for (size_t i = 0; i < sizeof(edges); i++)
    {
        memset(buffer, 0, sizeof(buffer));
        fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        ft_putchar_fd(edges[i], fd);
        close(fd);

        fd = open("test_putchar.txt", O_RDONLY);
        read(fd, buffer, 1);
        close(fd);
        assert(buffer[0] == edges[i]);
    }

    unlink("test_putchar.txt");
TSTFN_END

TSTFN(putstr_fd)
    char buffer[256] = {0};
    
    // 1. Test Random String (Using new malloc function)
    int len = RANDVAL(10, 255);
    char *src = string_filled_rnd(len);
    assert(src != NULL); // Safety check against malloc failure
    
    int fd = open("test_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    assert(fd >= 0);
    ft_putstr_fd(src, fd);
    close(fd);

    fd = open("test_putstr.txt", O_RDONLY);
    assert(fd >= 0);
    read(fd, buffer, 255);
    close(fd);
    assert(strcmp(buffer, src) == 0);
    free(src); // FREE THE MALLOC'D STRING

    // 2. Test Empty String
    memset(buffer, 0, sizeof(buffer));
    fd = open("test_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putstr_fd("", fd);
    close(fd);

    fd = open("test_putstr.txt", O_RDONLY);
    assert(read(fd, buffer, 255) == 0); 
    close(fd);
    assert(buffer[0] == '\0');

    // 3. Test String with Spaces and Newlines
    char tricky[] = "  Hello\nWorld\t";
    memset(buffer, 0, sizeof(buffer));
    fd = open("test_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putstr_fd(tricky, fd);
    close(fd);

    fd = open("test_putstr.txt", O_RDONLY);
    read(fd, buffer, sizeof(tricky));
    close(fd);
    assert(strcmp(buffer, tricky) == 0);

    unlink("test_putstr.txt");
TSTFN_END

TSTFN(putendl_fd)
    char buffer[258] = {0};
    
    // 1. Test Random String (Using new malloc function)
    int len = RANDVAL(10, 255);
    char *src = string_filled_rnd(len);
    assert(src != NULL);
    
    int fd = open("test_putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    assert(fd >= 0);
    ft_putendl_fd(src, fd);
    close(fd);

    fd = open("test_putendl.txt", O_RDONLY);
    assert(fd >= 0);
    read(fd, buffer, 257);
    close(fd);
    assert(strncmp(buffer, src, strlen(src)) == 0);
    assert(buffer[strlen(src)] == '\n');
    free(src); // FREE THE MALLOC'D STRING

    // 2. Test Empty String
    memset(buffer, 0, sizeof(buffer));
    fd = open("test_putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putendl_fd("", fd);
    close(fd);

    fd = open("test_putendl.txt", O_RDONLY);
    read(fd, buffer, 2);
    close(fd);
    assert(buffer[0] == '\n');
    assert(buffer[1] == '\0');

    unlink("test_putendl.txt");
TSTFN_END

TSTFN(putnbr_fd)
    char buffer[32] = {0};
    
    // 1. Test Random Int
    int sign = RANDVAL(0, 1) ? 1 : -1; 
    int val = RANDVAL(0, INT_MAX - 1) * sign;
    
    int fd = open("test_putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    assert(fd >= 0);
    ft_putnbr_fd(val, fd);
    close(fd);

    fd = open("test_putnbr.txt", O_RDONLY);
    assert(fd >= 0);
    read(fd, buffer, 32);
    close(fd);
    assert(atoi(buffer) == val);

    // 2. THE CRITICAL EDGE CASES
    int edges[] = {0, 1, -1, 10, -10, INT_MAX, INT_MIN};
    
    for (size_t i = 0; i < sizeof(edges) / sizeof(edges[0]); i++)
    {
        memset(buffer, 0, sizeof(buffer));
        fd = open("test_putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        ft_putnbr_fd(edges[i], fd);
        close(fd);

        fd = open("test_putnbr.txt", O_RDONLY);
        read(fd, buffer, 32);
        close(fd);
        
        assert(atoi(buffer) == edges[i]); 
    }

    unlink("test_putnbr.txt");
TSTFN_END

int main()
{
    srand(time(0));
    test_ctype_macro();
    test_strlen();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    test_switchcasing();
    test_strchr();
    test_strrchr();
    test_strncmp();
    test_memchr();
    test_memcmp();
    test_strnstr();
    test_atoi();
    test_substr();
    test_strjoin();
    test_split();
    test_itoa();
    test_strmapi();
    test_striteri();
    test_putchar_fd();
    test_putendl_fd();
    test_putnbr_fd();
    test_putstr_fd();

    return (0);
}
