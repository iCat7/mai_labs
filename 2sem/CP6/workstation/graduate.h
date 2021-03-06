#ifndef _GRADUATE_H_
#define _GRADUATE_H_

#ifdef _MSC_VER 
#define _CRT_SECURE_NO_WARNINGS 
#endif

#define STR_SIZE 24

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint32_t Date;

typedef struct {
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    char gender;
  	Date issue;
  	char class_letter;
  	char university[STR_SIZE];
} Graduate;

#endif