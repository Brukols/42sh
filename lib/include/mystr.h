/*
** EPITECH PROJECT, 2018
** mystr.h
** File description:
** prototypes of my_str functions
*/

#ifndef MYSTR_H
#define MYSTR_H

int my_getnbr(char const *str);
char *my_itoa(int number);
char *my_revstr(char *str);
int check_alphanumeric(char c, char sep);
int count_word(char *str, char sep);
char **my_str_to_word_array(char *str, char sep);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);

#endif
