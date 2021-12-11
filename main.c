#include <stdio.h>
#include <stdlib.h>

/* return the length of sub-string */
char *NextSubString(char *s) {
    char head;

    if (!s)
        return NULL;

    head = *s;
    s++;
    while (*s)
    {
        if (*s == head)
            break;
        s++;
    }

    return s;
}

int lengthOfLongestSubstring(char * s) {
    char *st_longest, *st_cur, *st_next;
    int len_longest, len_cur;

    if (!s || !(*s))
        return 0;

    /* initialization */
    st_longest = s;
    st_cur = NextSubString(s);
    len_longest = st_cur - s;

    while (*st_cur)
    {
        st_next = NextSubString(st_cur);
        len_cur = st_next - st_cur;
        if (len_cur <= len_longest)
        { /* relpace st_cur to next string */
            st_cur = st_next;
        }
        else
        { /* replace the longest string */
            st_longest = st_cur;
            len_longest = len_cur;
        }
    }

    return len_longest;
}

int main() 
{
    char str1[] = "abcabcbb";
    char str2[] = "bbbbb";
    char str3[] = "pwwkew";
    char str4[] = "";
    char str5[] = "test";

    printf("%s => %d\n", str1, lengthOfLongestSubstring(str1));
    printf("%s => %d\n", str2, lengthOfLongestSubstring(str2));
    printf("%s => %d\n", str3, lengthOfLongestSubstring(str3));
    printf("%s => %d\n", str4, lengthOfLongestSubstring(str4));
    printf("%s => %d\n", str5, lengthOfLongestSubstring(str5));

    return 0;
}
