#include <snes.h>

#define PAL0 0

extern char gameLogoSprite, gameLogoSprite_end;
extern char gameLogoPalette;

void loadGameLogo(u16 xspr, u16 yspr) {
	oamInit();
	
	oamInitGfxSet(&gameLogoSprite, 
		(&gameLogoSprite_end-&gameLogoSprite), 
		&gameLogoPalette, 
		16*2, 
		PAL0, 
		0x6000, 
		OBJ_SIZE8_L32);

	// Line 1 Part 1
	oamSet(0, xspr, yspr, 3, 0, 0, 0, 0);
	oamSetEx(0, OBJ_LARGE, OBJ_SHOW);

	oamSet(4, xspr + 32, yspr, 3, 0, 0, 4, 0);
	oamSetEx(4, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*2, xspr + 32*2, yspr, 3, 0, 0, 4*2, 0);
	oamSetEx(4*2, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*3, xspr + 32*3, yspr, 3, 0, 0, 4*3, 0);
	oamSetEx(4*3, OBJ_LARGE, OBJ_SHOW);

	// Line 1 Part 2
	oamSet(4*4, xspr + 32*4, yspr, 3, 0, 0, 64, 0);
	oamSetEx(4*4, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*5, xspr + 32*5, yspr, 3, 0, 0, 64 + 4, 0);
	oamSetEx(4*5, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*6, xspr + 32*6, yspr, 3, 0, 0, 64 + 4*2, 0);
	oamSetEx(4*6, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*7, xspr + 32*7, yspr, 3, 0, 0, 64 + 4*3, 0);
	oamSetEx(4*7, OBJ_LARGE, OBJ_SHOW);

	// Line 2 Part 1
	oamSet(4*8, xspr, yspr + 32, 3, 0, 0, 64*2 + 4*0, 0);
	oamSetEx(4*8, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*9, xspr + 32, yspr + 32, 3, 0, 0, 64*2 + 4*1, 0);
	oamSetEx(4*9, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*10, xspr + 64, yspr + 32, 3, 0, 0, 64*2 + 4*2, 0);
	oamSetEx(4*10, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*11, xspr + 168, yspr + 32, 3, 0, 0, 64*2 + 4*3, 0);
	oamSetEx(4*11, OBJ_LARGE, OBJ_SHOW);

	// Line 2 Part 2
	oamSet(4*12, xspr + 200, yspr + 32, 3, 0, 0, 64*3 + 4*0, 0);
	oamSetEx(4*12, OBJ_LARGE, OBJ_SHOW);
}

int main(void) {
    // Initialize SNES 
	consoleInit();

	// Now Put in 256 color mode
	setMode(BG_MODE3, 0);

	loadGameLogo(14, 102);

	setScreenOn();
    
	while(1) {
		WaitForVBlank();
	}
	return 0;
}
