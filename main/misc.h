//Misc.h
//Used for miscellaneous functions
//Please edit with an actual text editor

#ifndef MISC_H
#define MISC_H

#include "track.h"
#include "watch.h"

struct date {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
};

struct date getDate() {
  struct date now = {0, 0, 0, 0, 0, 0};
  now.year = 2015;
  now.month = 10;
  now.day = 13;
  return now;
}

#endif // MISC_H
