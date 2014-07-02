#include <pebble.h>
#include "pebble_one_gpath.h"

GPath *hour_path;
GPath *min_path;
GPath *sec_path;

const GPathInfo HOUR_POINTS = {
  6,
  (GPoint []) {
    { 6,-37},
    { 3,-40},
    {-3,-40},
    {-6,-37},
    {-6,  0},
    { 6,  0},
  }
};

const GPathInfo MIN_POINTS = {
  6,
  (GPoint []) {
    { 5,-57},
    { 3,-61},
    {-3,-61},
    {-5,-57},
    {-5,  0},
    { 5,  0},
  }
};

const GPathInfo SEC_POINTS = {
  4,
  (GPoint []) {
    { 2,  0},
    { 2,-61},
    {-2,-61},
    {-2,  0},
  }
};

void init_one_gpathes(){
  hour_path = gpath_create(&HOUR_POINTS);
  min_path = gpath_create(&MIN_POINTS);
  sec_path = gpath_create(&SEC_POINTS);
}
