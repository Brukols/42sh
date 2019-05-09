/*
** EPITECH PROJECT, 2018
** getnextline.h
** File description:
** prototypes of getnextline
*/

#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H

#ifndef READ_SIZE
#define READ_SIZE 50
#endif

char *get_next_line(int fd);
char *mem_line(char *line, char *buffer, int i, int j);

#endif