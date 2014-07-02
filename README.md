# modified Pebble One #
#### Example of adjusting a project and submitting as library to Pebble PoS demo ####
#### by Ron Ravid & Gregoire Sage ####
This branch of One watchface(By Bert Freudenberg) was created to demonstrate how to convert source code, in order to compile it into a library and submit it to the Pebble PoS overlay demo project. (By Ron64 & Gregoire Sage)

The original PebbleOne project is in:

[pebbleOne]:  https://github.com/bertfreudenberg/PebbleONE
ReadMe of The ONE Pebble Watch Face is in the bottom


##Main steps##

* Add pposdemo.h
* modify your code (entry points, colors, settings, disable messages, etc)
* Test it with demo_main.c
* compile it as library
* submit the library and resources

## Detailed Steps ##
### Preparation ###
Test your watch-face for leaks. Use pebble logs and make sure you see Still allocated <0B> when you exit the app.

### Setting preparation ###

* In your code add #include "pposdemo.h"
* Create some enum with your settings. Convert your settings to use AllSet[setOffset+BATTERY_MODE] instead of local parameters.

### Watch face modification steps ###

* Add #include "pposdemo.h"
* Remove references to Window in init() and deinit(). Let the main program create and destroy the main window, use rootLayer to add your layers.
* Provide entrypoints for creating (load_xxx), destroying (unload_xxx),  and redrawing (redraw_xxx) the window content. the last line of load_xxx should call configRedraw();
* Make all the remaining global variables and functions in your app static - to prevent identical named globals from other apps from clashing.
* Change all GColorBlack to backColor and GColorWhite to foreColor
* Change any string array from form of "const char* days[]" to "const char days[][12]" (Two bytes bigger than length of your longest string, more for unicode.) Otherwise compiler makes some pointer table to string start that won't relocate with the code and cause crash.
* Disable all existing settings code that work with msg inbox, tuple, persistent memory, etc. Instead, get setting from the array AllSet[setOffset+BATTERY_MODE]. Code for updating according to settings changes is not needed, as the entire watchface can be reloaded.
* For settings use general settings like date format and language read existing settings like AllSet[SET_DATE], AllSet[SET_LANG]. For your settings use AllSet[setOffset+SECONDS_MODE], AllSet[setOffset+BATTERY_MODE]...
* If you used float and it's not totally necessary, please convert it to integer.
* If you have many static data it is recommended to convert some of them to dynamic loading or load from resources, See BlockSlide example for details. There, moving two static arrays from static data to dynamic loading, changed it from largest part, to one of the smaller. (size of area allocated for all overlaid pieces is determined by largest piece)
* If you use gpath_draw_filled or gpath_draw_outline, move your GPath data and setup function to external file with setup function(see usage of pebble_one_gpath .c & .h ). Otherwise the GPath draw function will crash.

### Adding Info and settings default ###
Every display should include this data to give proper credit, and preferred default settings

* Add info_xxx like the example.
* app_name and dev_name are used to give correct credits to the developer.
* Def_set lists the values for each setting parameter. the index in AllSet, a default value, and an optional value if needed. this can allow to display the watch-face as developer intended, and in an optional configuration as well.
* def_cnt mark how many setting exist in def_set array. if def_opt is zero, the additional optional setting will be ignored.

### Using demo_main for testing ###

* Add your app short name xxx into ENTRYPOINTS(xxx) and ENTRYPOINTROW(xxx), in demomain.c (In here xxx=one)
* let it run your modified code to make sure it works, and that it is displayed correctly.

### Compiling and submitting ###

* wscript/parameter file modifications
* compile your code using our wscript
* Submit the library (two in case of GPath issue), your resources, and relevant h files (?)





The ONE Pebble Watch Face
=========================

This is a highly readable analog watchface for the [Pebble Smartwatch][pebble], intended for every-day use.
Its features are customizable, but I want to keep the overall look simple.

This latest version is built on the [Pebble SDK 2.0][sdk2] and needs the Pebble 2.0 firmware to run.
You can install the app from [My Pebble Faces][download].

Contributions are highly welcome - just send me a [pull request][pullreq].

-- Bert Freudenberg, December 2013

[pebble]:  https://getpebble.com/
[sdk2]:    https://developer.getpebble.com/2/
[pullreq]: https://help.github.com/articles/using-pull-requests
[download]: http://www.mypebblefaces.com/apps/596/637/
