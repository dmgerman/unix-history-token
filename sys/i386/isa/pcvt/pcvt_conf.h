begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000 Hellmuth Michaelis  *  * Copyright (c) 1992, 1995 Hellmuth Michaelis and Joerg Wunsch.  *  * Copyright (c) 1992, 1994 Brian Dunford-Shore.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by  *	Hellmuth Michaelis, Brian Dunford-Shore and Joerg Wunsch.  * 4. The name authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  *	pcvt_conf.h	VT220 driver global configuration file  *	------------------------------------------------------  *  *	Last Edit-Date: [Fri Mar 31 10:20:27 2000]  *  * $FreeBSD$  *  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* ---------------- USER PREFERENCE DRIVER OPTIONS -------------------- */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_NSCREENS
end_if

begin_comment
comment|/* ---------- DEFAULT: 8 -------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_NSCREENS
value|8
end_define

begin_comment
comment|/* this option defines how many virtual	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* screens you want to have in your	*/
end_comment

begin_comment
comment|/* system.				*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_VT220KEYB
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_VT220KEYB
value|0
end_define

begin_comment
comment|/* this compiles a more vt220-like	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_VT220KEYB
operator|!=
literal|0
end_elif

begin_comment
comment|/* keyboardlayout as described in the	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_VT220KEYB
end_undef

begin_comment
comment|/* file Keyboard.VT220.			*/
end_comment

begin_define
define|#
directive|define
name|PCVT_VT220KEYB
value|1
end_define

begin_comment
comment|/* if undefined, a more HP-like         */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* keyboardlayout is compiled		*/
end_comment

begin_comment
comment|/* try to find out what YOU like !	*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_SCREENSAVER
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_SCREENSAVER
value|1
end_define

begin_comment
comment|/* enable screen saver feature - this	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_SCREENSAVER
operator|!=
literal|0
end_elif

begin_comment
comment|/* just blanks the display screen.	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_SCREENSAVER
end_undef

begin_comment
comment|/* see PCVT_PRETTYSCRNS below ...	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_SCREENSAVER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_PRETTYSCRNS
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_PRETTYSCRNS
value|0
end_define

begin_comment
comment|/* for the cost of some microseconds of	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_PRETTYSCRNS
operator|!=
literal|0
end_elif

begin_comment
comment|/* cpu time this adds a more "pretty"	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_PRETTYSCRNS
end_undef

begin_comment
comment|/* version to the screensaver, an "*"	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_PRETTYSCRNS
value|1
end_define

begin_comment
comment|/* in random locations of the display.	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOTE: this should not be defined if	*/
end_comment

begin_comment
comment|/* you have an energy-saving monitor 	*/
end_comment

begin_comment
comment|/* which turns off the display if its	*/
end_comment

begin_comment
comment|/* black !!!!!!				*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_GREENSAVER
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_GREENSAVER
value|0
end_define

begin_comment
comment|/* screensaver mode that enables 	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_GREENSAVER
operator|!=
literal|0
end_elif

begin_comment
comment|/* power-save mode			*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_GREENSAVER
end_undef

begin_define
define|#
directive|define
name|PCVT_GREENSAVER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_CTRL_ALT_DEL
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_CTRL_ALT_DEL
value|0
end_define

begin_comment
comment|/* this enables the execution of a cpu	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_CTRL_ALT_DEL
operator|!=
literal|0
end_elif

begin_comment
comment|/* reset by pressing the CTRL, ALT and	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_CTRL_ALT_DEL
end_undef

begin_comment
comment|/* DEL keys simultanously. Because this	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_CTRL_ALT_DEL
value|1
end_define

begin_comment
comment|/* is a feature of an ancient simple	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bootstrap loader, it does not belong */
end_comment

begin_comment
comment|/* into modern operating systems and 	*/
end_comment

begin_comment
comment|/* was commented out by default ...	*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_USEKBDSEC
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_USEKBDSEC
value|1
end_define

begin_comment
comment|/* do not set the COMMAND_INHOVR bit	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_USEKBDSEC
operator|!=
literal|0
end_elif

begin_comment
comment|/* (1 = override security lock inhibit) */
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_USEKBDSEC
end_undef

begin_comment
comment|/* when initializing the keyboard, so   */
end_comment

begin_define
define|#
directive|define
name|PCVT_USEKBDSEC
value|1
end_define

begin_comment
comment|/* that security locking should work    */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* now. I guess this has to be done also*/
end_comment

begin_comment
comment|/* in the boot code to prevent single   */
end_comment

begin_comment
comment|/* user startup ....                    */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_24LINESDEF
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_24LINESDEF
value|0
end_define

begin_comment
comment|/* use 24 lines in VT 25 lines mode and	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_24LINESDEF
operator|!=
literal|0
end_elif

begin_comment
comment|/* HP 28 lines mode by default to have	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_24LINESDEF
end_undef

begin_comment
comment|/* the the better compatibility to the	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_24LINESDEF
value|1
end_define

begin_comment
comment|/* real VT220 - you can switch between	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the maximum possible screensizes in	*/
end_comment

begin_comment
comment|/* those two modes (25 lines) and true	*/
end_comment

begin_comment
comment|/* compatibility (24 lines) by using	*/
end_comment

begin_comment
comment|/* the scon utility at runtime		*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_META_ESC
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_META_ESC
value|0
end_define

begin_comment
comment|/* if ON, send the sequence "ESC key"	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_META_ESC
operator|!=
literal|0
end_elif

begin_comment
comment|/* for a meta-shifted key; if OFF,	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_META_ESC
end_undef

begin_comment
comment|/* send the normal key code with 0x80	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_META_ESC
value|1
end_define

begin_comment
comment|/* added.				*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* -------------------- DRIVER DEBUGGING ------------------------------ */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_SHOWKEYS
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_SHOWKEYS
value|0
end_define

begin_comment
comment|/* this replaces the system load line	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_SHOWKEYS
operator|!=
literal|0
end_elif

begin_comment
comment|/* on the vt 0 in hp mode with a display*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_SHOWKEYS
end_undef

begin_comment
comment|/* of the most recent keyboard scan-	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_SHOWKEYS
value|1
end_define

begin_comment
comment|/* and status codes received from the	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* keyboard controller chip.		*/
end_comment

begin_comment
comment|/* this is just for some hardcore	*/
end_comment

begin_comment
comment|/* keyboarders ....			*/
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* -------------------- DRIVER OPTIONS -------------------------------- */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*     it is unlikely that anybody wants to change anything below       */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_NO_LED_UPDATE
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_NO_LED_UPDATE
value|0
end_define

begin_comment
comment|/* On some (Notebook?) keyboards it is	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_NO_LED_UPDATE
operator|!=
literal|0
end_elif

begin_comment
comment|/* not possible to update the LED's	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_NO_LED_UPDATE
end_undef

begin_comment
comment|/* without hanging the keyboard after-	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_NO_LED_UPDATE
value|1
end_define

begin_comment
comment|/* wards. If you experience Problems	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* like this, try to enable this option	*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_SCANSET
end_if

begin_comment
comment|/* ---------- DEFAULT: 1 -------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_SCANSET
value|1
end_define

begin_comment
comment|/* define the keyboard scancode set you	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* want to use:				*/
end_comment

begin_comment
comment|/* 1 - code set 1	(supported)	*/
end_comment

begin_comment
comment|/* 2 - code set 2	(supported)	*/
end_comment

begin_comment
comment|/* 3 - code set 3	(UNsupported)	*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_NULLCHARS
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_NULLCHARS
value|1
end_define

begin_comment
comment|/* allow the keyboard to send null	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_NULLCHARS
operator|!=
literal|0
end_elif

begin_comment
comment|/* (0x00) characters to the calling	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_NULLCHARS
end_undef

begin_comment
comment|/* program. this has the side effect	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_NULLCHARS
value|1
end_define

begin_comment
comment|/* that every undefined key also sends	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* out nulls.				*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCVT_UPDATEFAST
end_ifndef

begin_comment
comment|/* this is the rate at which the cursor */
end_comment

begin_define
define|#
directive|define
name|PCVT_UPDATEFAST
value|(hz/10)
end_define

begin_comment
comment|/* gets updated with its new position	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* see: async_update() in pcvt_sup.c	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCVT_UPDATESLOW
end_ifndef

begin_comment
comment|/* this is the rate at which the cursor	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_UPDATESLOW
value|3
end_define

begin_comment
comment|/* position display and the system load	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (or the keyboard scancode display)	*/
end_comment

begin_comment
comment|/* is updated. the relation is:		*/
end_comment

begin_comment
comment|/* PCVT_UPDATEFAST/PCVT_UPDATESLOW	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCVT_SYSBEEPF
end_ifndef

begin_comment
comment|/* timer chip value to be used for the	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_SYSBEEPF
value|1193182
end_define

begin_comment
comment|/* sysbeep frequency value.		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* this should really go somewhere else,*/
end_comment

begin_comment
comment|/* e.g. in isa.h; but it used to be in 	*/
end_comment

begin_comment
comment|/* each driver, sometimes even with	*/
end_comment

begin_comment
comment|/* different values (:-)		*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_SETCOLOR
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_SETCOLOR
value|0
end_define

begin_comment
comment|/* enable making colors settable. this	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_SETCOLOR
operator|!=
literal|0
end_elif

begin_comment
comment|/* introduces a new escape sequence	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_SETCOLOR
end_undef

begin_comment
comment|/*<ESC d> which is (i think) not 	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_SETCOLOR
value|1
end_define

begin_comment
comment|/* standardized, so this is an option	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (Birthday present for Bruce ! :-)    */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_132GENERIC
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_132GENERIC
value|0
end_define

begin_comment
comment|/* if you #define this, you enable	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_132GENERIC
operator|!=
literal|0
end_elif

begin_comment
comment|/*	EXPERIMENTAL (!!!!!!!!!!!!)	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_132GENERIC
end_undef

begin_comment
comment|/* 	USE-AT-YOUR-OWN-RISK, 		*/
end_comment

begin_define
define|#
directive|define
name|PCVT_132GENERIC
value|1
end_define

begin_comment
comment|/*	MAY-DAMAGE-YOUR-MONITOR		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* code to switch generic VGA boards/	*/
end_comment

begin_comment
comment|/* chipsets to 132 column mode. Since	*/
end_comment

begin_comment
comment|/* i could not verify this option, i	*/
end_comment

begin_comment
comment|/* prefer to NOT generally enable this,	*/
end_comment

begin_comment
comment|/* if you want to play, look at the 	*/
end_comment

begin_comment
comment|/* hints and the code in pcvt_sup.c and	*/
end_comment

begin_comment
comment|/* get in contact with Joerg Wunsch, who*/
end_comment

begin_comment
comment|/* submitted this code. Be careful !!!	*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_INHIBIT_NUMLOCK
end_if

begin_comment
comment|/* --------- DEFAULT: OFF ----------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_INHIBIT_NUMLOCK
value|0
end_define

begin_comment
comment|/* A notebook hack: since i am getting	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_INHIBIT_NUMLOCK
operator|!=
literal|0
end_elif

begin_comment
comment|/* tired of the numlock LED always	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_INHIBIT_NUMLOCK
end_undef

begin_comment
comment|/* being turned on - which causes the	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_INHIBIT_NUMLOCK
value|1
end_define

begin_comment
comment|/* right half of my keyboard being	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* interpreted as a numeric keypad and	*/
end_comment

begin_comment
comment|/* thus going unusable - i want to	*/
end_comment

begin_comment
comment|/* have a better control over it. If	*/
end_comment

begin_comment
comment|/* this option is enabled, only the	*/
end_comment

begin_comment
comment|/* numlock key itself and the related	*/
end_comment

begin_comment
comment|/* ioctls will modify the numlock	*/
end_comment

begin_comment
comment|/* LED. (The ioctl is needed for the	*/
end_comment

begin_comment
comment|/* ServerNumLock feature of XFree86.)	*/
end_comment

begin_comment
comment|/* The default state is changed to	*/
end_comment

begin_comment
comment|/* numlock off, and the escape		*/
end_comment

begin_comment
comment|/* sequences to switch between numeric	*/
end_comment

begin_comment
comment|/* and application mode keypad are	*/
end_comment

begin_comment
comment|/* silently ignored.			*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_SLOW_INTERRUPT
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_SLOW_INTERRUPT
value|0
end_define

begin_comment
comment|/* If off, protecting critical regions	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_SLOW_INTERRUPT
operator|!=
literal|0
end_elif

begin_comment
comment|/* in the keyboard fifo code is done by	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_SLOW_INTERRUPT
end_undef

begin_comment
comment|/* disabling the processor irq's, if on */
end_comment

begin_define
define|#
directive|define
name|PCVT_SLOW_INTERRUPT
value|1
end_define

begin_comment
comment|/* this is done by spl()/splx() calls.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Kernel messages attribute definitions  *	These define the foreground and background attributes used to  *	emphasize messages from the kernel on color and mono displays.  *---------------------------------------------------------------------------*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|COLOR_KERNEL_FG
end_if

begin_comment
comment|/* color displays		*/
end_comment

begin_define
define|#
directive|define
name|COLOR_KERNEL_FG
value|FG_LIGHTGREY
end_define

begin_comment
comment|/* kernel messages, foreground	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|COLOR_KERNEL_BG
end_if

begin_define
define|#
directive|define
name|COLOR_KERNEL_BG
value|BG_RED
end_define

begin_comment
comment|/* kernel messages, background	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|MONO_KERNEL_FG
end_if

begin_comment
comment|/* monochrome displays		*/
end_comment

begin_define
define|#
directive|define
name|MONO_KERNEL_FG
value|FG_UNDERLINE
end_define

begin_comment
comment|/* kernel messages, foreground	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|MONO_KERNEL_BG
end_if

begin_define
define|#
directive|define
name|MONO_KERNEL_BG
value|BG_BLACK
end_define

begin_comment
comment|/* kernel messages, background	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------- E O F ----------------------------------*/
end_comment

end_unit

