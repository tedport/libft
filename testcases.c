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

char *string_fill_rnd(int length)
{
    char *str = malloc(length + 1);
    if (!str)
        return 0;
    str[length] = 0;
    for (int i = 0; i < length; i++)
        str[i] = (char)RANDVAL(32, 126);
    return str;
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
    char *str = string_fill_rnd(i);
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
    char *str = string_fill_rnd(i);
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
    char *str = string_fill_rnd(i);
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
    char *str = string_fill_rnd(i);
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
    char *str = string_fill_rnd(rnd);
    char *add = string_fill_rnd(i - rnd);
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
    char *str = string_fill_rnd(i);
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
    char *str = string_fill_rnd(i);
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
    char *str1 = string_fill_rnd(i);
    char *str2 = string_fill_rnd(i);

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
    char *str = string_fill_rnd(i);
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
    char *str1 = string_fill_rnd(i);
    char *str2 = string_fill_rnd(i);

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
    char *str = string_fill_rnd(i);
    char *needle = malloc(9);
    needle [8] = 0;
    for(int i = 0; i < 8; i++)
        needle[i] = str[rnd + i];

    assert(strnstr(str, needle, i) == ft_strnstr(str,needle,i));
    assert(strnstr(str, "", i) == ft_strnstr(str,"",i));
    assert(strnstr("", needle, i) == ft_strnstr("",needle,i));
    assert(strnstr(str, needle, 0) == ft_strnstr(str,needle,0));
    assert(strnstr(str, "\1\1\1", 0) == ft_strnstr(str,"\1\1\1",0));
    if (i % 2 == 0 && i >= 4)
        assert(strnstr(str, needle, i / 2) == ft_strnstr(str,needle,i / 2));

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
    char    *str = string_fill_rnd(1024);
    char    *sub;

    sub = ft_substr(str, 0, 16);
    assert(!strncmp(str, sub, 16));
    free(sub);
    sub = ft_substr(str, 157, 16);
    assert(!strncmp(str+157, sub, 16));
    free(sub);
    sub = ft_substr(str, 1023, 16);
    assert(!strncmp(str+1023, sub, 16));
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
    s1 = "Bull", s2="shit";
    join = ft_strjoin(s1, s2);
    assert(!strcmp(join, "Bullshit"));
    free(join);
    s1 = "", s2="shit";
    join = ft_strjoin(s1, s2);
    assert(!strcmp(join, "shit"));
    free(join);
    s1 = "", s2="";
    join = ft_strjoin(s1, s2);
    assert(!strcmp(join, ""));
    free(join);
    s1 = "", s2="";
    join = ft_strjoin(s1, s2);
    assert(!strcmp(join, ""));
    free(join);
    s1 = "Love ", s2="me";
    join = ft_strjoin(s1, s2);
    assert(!strcmp(join, "Love me"));
    free(join);
TSTFN_END

void	cleanup_splitted(char **splitted)
{
	while (*splitted)
	{
		free(*splitted);
		splitted++;
	}
	free(splitted);
}

TSTFN(split)
    char **splitted = ft_split(" Bug Arc    Is N ever true", ' ');
    assert(splitted);
    cleanup_splitted(splitted);
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

    return (0);
}
