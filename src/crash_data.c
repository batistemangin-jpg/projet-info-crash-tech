#include <stdio.h
#include "crash_data.h"
#include "utils.h"

#define FIRST_YEAR 2005
#define LAST_YEAR 2024
#define MAX_COLLISION_ID 99999999L

void run_crash_data(const char *path){
  long choice = 0;
  long year;
  long id;

  (void)path;
  do{
      printf("\n===== MODE CRASH_DATA =====\n");
      printf("1. Rechercher un  accident\n");
      printf("0. Quitter ce mode\n");
      if (!read_long_in_range("Votre choix : ", 0, 1, &choice)){
          
