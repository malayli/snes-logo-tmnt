#include <snes.h>

#define PAL0 0
#define PAL1 1

extern char gameLogoSprite, gameLogoSprite_end;
extern char logoPalette;

int main(void) {
    // Initialize SNES 
	consoleInit();

	// Now Put in 256 color mode
	setMode(BG_MODE3, 0);

	oamInitGfxSet(&gameLogoSprite, (&gameLogoSprite_end-&gameLogoSprite), &logoPalette, 16*2, 0, 0x6000, OBJ_SIZE8_L32);

	// Line 1 Part 1
	oamSet(0, 0, 0, 3, 0, 0, 0, 0);
	oamSetEx(0, OBJ_LARGE, OBJ_SHOW);

	oamSet(4, 32, 0, 3, 0, 0, 4, 0);
	oamSetEx(4, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*2, 32*2, 0, 3, 0, 0, 4*2, 0);
	oamSetEx(4*2, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*3, 32*3, 0, 3, 0, 0, 4*3, 0);
	oamSetEx(4*3, OBJ_LARGE, OBJ_SHOW);

	// Line 1 Part 2
	oamSet(4*4, 32*4, 0, 3, 0, 0, 64, 0);
	oamSetEx(4*4, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*5, 32*5, 0, 3, 0, 0, 64 + 4, 0);
	oamSetEx(4*5, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*6, 32*6, 0, 3, 0, 0, 64 + 4*2, 0);
	oamSetEx(4*6, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*7, 32*7, 0, 3, 0, 0, 64 + 4*3, 0);
	oamSetEx(4*7, OBJ_LARGE, OBJ_SHOW);

	// Line 2 Part 1
	oamSet(4*8, 0, 32, 3, 0, 0, 64*2 + 4*0, 0);
	oamSetEx(4*8, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*9, 32, 32, 3, 0, 0, 64*2 + 4*1, 0);
	oamSetEx(4*9, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*10, 64, 32, 3, 0, 0, 64*2 + 4*2, 0);
	oamSetEx(4*10, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*11, 168, 32, 3, 0, 0, 64*2 + 4*3, 0);
	oamSetEx(4*11, OBJ_LARGE, OBJ_SHOW);

	// Line 2 Part 2
	oamSet(4*12, 200, 32, 3, 0, 0, 64*3 + 4*0, 0);
	oamSetEx(4*12, OBJ_LARGE, OBJ_SHOW);

	setScreenOn();
    
	while(1) {
		WaitForVBlank();
	}
	return 0;
}
