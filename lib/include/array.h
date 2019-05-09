/*
** EPITECH PROJECT, 2018
** array.h
** File description:
** prototypes of my tab function
*/

#ifndef ARRAY_H
#define ARRAY_H

char **free_array(char **array);
int get_size_array(char **array);
char **my_array_cpy(char **array);
int my_show_word_array(char *const *tab);
void my_sort_int_array(int *tab, int size);
void print_array(char **array);
char **create_array(int row, int col);

#endif
