#include <snes.h>

#define PAL0 0
#define PAL1 1

extern char logoTm, logoTm_end;
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

	initForegroundPalette(&logoPalette, PAL0);
	initForegroundPalette(&logoPalette, PAL1);

	oamInit();
	oamInitGfxAttr(0x4000, OBJ_SIZE32_L64);

	dmaCopyVram(&gameLogoSprite, 0x4000, (&gameLogoSprite_end-&gameLogoSprite));

	WaitForVBlank();

	u16 gfxOffset = 32*32/16;
	
	oamSetEx(0, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(0, 0, 0, gfxOffset*0, OAM_ATTR(3, 0, 0, 0, PAL0));

	oamSetEx(4, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(4, 32, 0, gfxOffset*1, OAM_ATTR(3, 0, 0, gfxOffset*1, PAL0));

	oamSetEx(4*2, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(4*2, 64, 0, gfxOffset*2, OAM_ATTR(3, 0, 0, gfxOffset*2, PAL0));

	oamSetEx(4*3, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(4*3, 96, 0, gfxOffset*3, OAM_ATTR(3, 0, 0, gfxOffset*3, PAL0));

	oamSetEx(4*4, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(4*4, 128, 0, gfxOffset*4, OAM_ATTR(3, 0, 0, gfxOffset*4, PAL0));

	oamSetEx(4*5, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(4*5, 160, 0, gfxOffset*5, OAM_ATTR(3, 0, 0, gfxOffset*5, PAL0));

	oamSetEx(4*6, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(4*6, 192, 0, gfxOffset*6, OAM_ATTR(3, 0, 0, gfxOffset*6, PAL0));

	oamSetEx(4*7, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(4*7, 224, 0, gfxOffset*7, OAM_ATTR(3, 0, 0, gfxOffset*7, PAL0));

	// Second line

	// This sprite is not displayed
	oamSetEx(4*8, OBJ_SMALL, OBJ_SHOW);
	oamSetAttr(4*8, 0, 32, gfxOffset*8, OAM_ATTR(3, 0, 0, gfxOffset*8, PAL1));

	setScreenOn();
    
	while(1) {
		WaitForVBlank();
	}
	return 0;
}
