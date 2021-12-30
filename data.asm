.include "hdr.asm"

.section ".rodata1" superfree

snesfont: .incbin "res/font/pvsneslibfont.pic"
snesfont_end:

.ends

.section ".rodata2" superfree

logoTm:
.incbin "res/logo/logoTm.pic"
logoTm_end:

gameLogoSprite:
.incbin "res/logo/logoPart1.pic"
.incbin "res/logo/logoPart2.pic"
.incbin "res/logo/logoPart3.pic"
.incbin "res/logo/logoPart4.pic"
.incbin "res/logo/logoPart5.pic"
.incbin "res/logo/logoPart6.pic"
.incbin "res/logo/logoPart7.pic"
.incbin "res/logo/logoPart8.pic"
.incbin "res/logo/logoDown1.pic"
.incbin "res/logo/logoDown2.pic"
.incbin "res/logo/logoDown3.pic"
.incbin "res/logo/logoDown4.pic"
.incbin "res/logo/logoDown5.pic"
gameLogoSprite_end:

logoPalette:
.incbin "res/logo/logoPart1.pal"
logoPalette_end:

.ends

.section ".rodata3" superfree
.ends

.section ".rodata4" superfree
.ends

.section ".rodata5" superfree
.ends
