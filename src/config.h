#pragma once

// #include "overlays.h"

// Each added app must include config.h

enum {SET_INV, SET_DATE, SET_LANG, SET_BAT, SET_COMM, SET_BUZZ_DIS, SET_BUZZ_CON, SET_RES1, //General settings
      SET_BIT_RL, SET_BLOCK_LINE, SET_HPDATE, SET_HPBW, SET_HPINV, SET_HPHAND, SET_RES2, SET_RES3, //Specific settings
      SET_MODE, SET_FACE, SET_FXP, SET_FXN, SET_FYP, SET_FYN, SET_FZP, SET_FZN, // selecting Display
      SET_TIME, SET_RES4};  // More faces.
extern int8_t AllSet[48]; //settings for all. use 0 as default value
void configRedraw();
extern InverterLayer *inverter_layer;
extern GColor backColor;
extern GColor foreColor;
extern Layer *rootLayer;
extern int resourceOffset;
extern void do_invert();
extern void swap_face(int8_t face);
void config_swap(bool up);
extern int saveconfig();
extern int loadconfig();
extern void click_config_provider(void *context);

//void in_received_handler(DictionaryIterator *received, void *context);
//void in_dropped_handler(AppMessageResult reason, void *ctx);//extern int dateStyle;
//AppTimer * FirstTap;

#define ENTRYPOINTS(NAME) void redraw_ ## NAME (); void load_ ## NAME (); void unload_ ## NAME ();

	ENTRYPOINTS(fuzzy)
	ENTRYPOINTS(pick)
	ENTRYPOINTS(accu)
	ENTRYPOINTS(retro)
	ENTRYPOINTS(Perspective)
	ENTRYPOINTS(bit)
	ENTRYPOINTS(ill)
	ENTRYPOINTS(toe)
	ENTRYPOINTS(block)
	ENTRYPOINTS(simplicity)
	//ENTRYPOINTS(words) //problematic watchface
	ENTRYPOINTS(retro)
	ENTRYPOINTS(retro)
	ENTRYPOINTS(retro)

// static const int8_t OVL_RESOURCE_IDS[] = { // Change if you have >127 in RESOURCE_ID
// 		//0,0,0,0,0,0,0,0,0,0,0,
// 		FUZZY_TIME_OVL,//RESOURCE_ID_OVL_FUZZY, //better to have one without overlay
// 		HOP_PICKER_OVL, //problematic data of GPath moved to non_overlay file
// 		ACCUINFO_OVL, 
// 		RETROCLOCK_OVL,
// 		PERSPECTIVE_OVL,
// 		JUST_A_BIT_OVL,
// 		ILLUDERE_OVL,
// 		TIC_TOCK_TOE_OVL,
// 		BLOCKSLIDE_OVL,
// 		SIMPLICITY_OVL,
// 		//RESOURCE_ID_OVL_WORDS,
// 		RETROCLOCK_OVL,
// 		RETROCLOCK_OVL,
// 		RETROCLOCK_OVL,//*/
// 	};
// static const int8_t OVL_debug[] = { //debug information for active overlay part
// 		-1,0,1,2,3,4,5,6,7,3,3,3
// 	};

