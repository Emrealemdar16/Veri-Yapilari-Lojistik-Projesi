#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CITY_NAME 50
#define MAX_PACKAGE_ID 20

typedef struct {
    char package_id[MAX_PACKAGE_ID];
    char content[100];
    char current_city[MAX_CITY_NAME];
    char destination[MAX_CITY_NAME];
    int status;
} Package;

#endif
