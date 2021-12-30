#include <snes.h>

#define PAL0 0
#define PAL1 1

extern char gameLogoSprite, gameLogoSprite_end;
extern char logoPalette;

void initForegroundPalette(u8 *source, u16 tilePaletteNumber) {
	u16 palEntry = 128+(tilePaletteNumber*16);
   	dmaCopyCGram(source, palEntry, 16*2);
}

int main(void) {
    // Initialize SNES 
	consoleInit();

	// Now Put in 256 color mode
	setMode(BG_MODE3, 0);

	oamInitGfxSet(&gameLogoSprite, (&gameLogoSprite_end-&gameLogoSprite), &logoPalette, 16*2, 0, 0x6000, OBJ_SIZE8_L16);

	oamSet(0, 0, 0, 3, 0, 0, 0, 0);
	oamSetEx(0, OBJ_LARGE, OBJ_SHOW);

	oamSet(4, 16, 0, 3, 0, 0, 2, 0);
	oamSetEx(4, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*2, 32, 0, 3, 0, 0, 4, 0);
	oamSetEx(4*2, OBJ_LARGE, OBJ_SHOW);

	oamSet(4*3, 48, 0, 3, 0, 0, 6, 0);
	oamSetEx(4*3, OBJ_LARGE, OBJ_SHOW);

	setScreenOn();
    
	while(1) {
		WaitForVBlank();
	}
	return 0;
}
