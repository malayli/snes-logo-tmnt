ifeq ($(strip $(PVSNESLIB_HOME)),)
$(error "Please create an environment variable PVSNESLIB_HOME with path to its folder and restart application. (you can do it on windows with <setx PVSNESLIB_HOME "/c/snesdev">)")
endif

include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

.PHONY: logo bitmaps all

#---------------------------------------------------------------------------------
# ROMNAME is used in snes_rules file
export ROMNAME := snesdemo

all: logo bitmaps $(ROMNAME).sfc

clean: cleanBuildRes cleanRom cleanGfx cleanAudio
	
#---------------------------------------------------------------------------------
logoTm.pic: res/logo/logoTm.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs8 -pc16 -po16 -n $<

logoPart1.pic: res/logo/logoPart1.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoPart2.pic: res/logo/logoPart2.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoPart3.pic: res/logo/logoPart3.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoPart4.pic: res/logo/logoPart4.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoPart5.pic: res/logo/logoPart5.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoPart6.pic: res/logo/logoPart6.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoPart7.pic: res/logo/logoPart7.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoPart8.pic: res/logo/logoPart8.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoDown1.pic: res/logo/logoDown1.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoDown2.pic: res/logo/logoDown2.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoDown3.pic: res/logo/logoDown3.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoDown4.pic: res/logo/logoDown4.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

logoDown5.pic: res/logo/logoDown5.bmp
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -gs32 -pc16 -po16 -n $<

pvsneslibfont.pic: res/font/pvsneslibfont.bmp
	@echo convert font with no tile reduction ... $(notdir $@)
	$(GFXCONV) -n -gs8 -po2 -pc16 -pe1 -mR! -m! -p! $<

logo : logoTm.pic logoPart1.pic logoPart2.pic logoPart3.pic logoPart4.pic logoPart5.pic logoPart6.pic logoPart7.pic logoPart8.pic logoDown1.pic logoDown2.pic logoDown3.pic logoDown4.pic logoDown5.pic

bitmaps : pvsneslibfont.pic
