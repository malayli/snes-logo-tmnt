.include "hdr.asm"

.section ".rodata1" superfree

snesfont: .incbin "res/font/pvsneslibfont.pic"
snesfont_end:

.ends

.section ".rodata2" superfree

gameLogoSprite:
.incbin "res/sprite/sprite.pic"
gameLogoSprite_end:

logoPalette:
.incbin "res/sprite/sprite.pal"
logoPalette_end:

.ends

.section ".rodata3" superfree
.ends

.section ".rodata4" superfree
.ends

.section ".rodata5" superfree
.ends
