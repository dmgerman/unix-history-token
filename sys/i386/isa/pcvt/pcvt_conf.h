begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Hellmuth Michaelis  *  * Copyright (c) 1992, 1995 Hellmuth Michaelis and Joerg Wunsch.  *  * Copyright (c) 1992, 1994 Brian Dunford-Shore.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by  *	Hellmuth Michaelis, Brian Dunford-Shore and Joerg Wunsch.  * 4. The name authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  *	pcvt_conf.h	VT220 driver global configuration file  *	------------------------------------------------------  *  *	Last Edit-Date: [Mon Dec 27 14:09:58 1999]  *  * $FreeBSD$  *  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  * from: Onno van der Linden    c/o   frank@fwi.uva.nl  *  * Here's an idea how to automatically detect the version of NetBSD pcvt is  * being compiled on:  *  * NetBSD 0.8 : NetBSD0_8 defined in<sys/param.h>  * NetBSD 0.9 : NetBSD0_9 defined in<sys/param.h>  * NetBSD 1.0 : NetBSD1_0 defined as 1 in<sys/param.h>  * NetBSD 1.0A: NetBSD1_0 defined as 2 in<sys/param.h>  *  * The NetBSDx_y defines are mutual exclusive.  *  * This leads to something like this in pcvt_hdr.h (#elif is possible too):  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NetBSD0_8
end_ifdef

begin_define
define|#
directive|define
name|PCVT_NETBSD
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NetBSD0_9
end_ifdef

begin_define
define|#
directive|define
name|PCVT_NETBSD
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NetBSD1_0
end_ifdef

begin_if
if|#
directive|if
name|NetBSD1_0
operator|>
literal|1
end_if

begin_define
define|#
directive|define
name|PCVT_NETBSD
value|199
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCVT_NETBSD
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------  * Note that each of the options below should rather be overriden by the  * kernel config file instead of this .h file - this allows for different  * definitions in different kernels compiled at the same machine  *  * The convention is as follows:  *  *	options "PCVT_FOO=1"  - enables the option  * 	options "PCVT_FOO"    - is a synonym for the above  *	options "PCVT_FOO=0"  - disables the option  *  * omitting an option defaults to what is shown below  *  * exceptions from this rule are i.e.:  *  *	options "PCVT_NSCREENS=x"  *	options "PCVT_SCANSET=x"  *	options "PCVT_UPDATEFAST=x"  *	options "PCVT_UPDATESLOW=x"  *	options "PCVT_SYSBEEPF=x"  *  * which are always numeric!  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* -------------------- OPERATING SYSTEM ------------------------------ */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  *  one of the following options must be set in the kernel config file:  *  *======================================================================*  *			N e t B S D					*  *======================================================================*  *  *	options "PCVT_NETBSD=xxx" enables support for NetBSD  *  *	select:  *		PCVT_NETBSD =   9	for NetBSD 0.9  *		PCVT_NETBSD =  99	for PRE-1.0 NetBSD-current  *		PCVT_NETBSD = 100	for NetBSD 1.0  *		PCVT_NETBSD = 199	for PRE-2.0 NetBSD-current  *  *  *======================================================================*  *			F r e e B S D					*  *======================================================================*  *  *	options "PCVT_FREEBSD=xxx" enables support for FreeBSD  *  *	select:  *		PCVT_FREEBSD = 102	for 1.0 release (actually 1.0.2)  *		PCVT_FREEBSD = 110	for FreeBSD 1.1-Release  *		PCVT_FREEBSD = 115	for FreeBSD 1.1.5.1-Release  *		PCVT_FREEBSD = 200	for FreeBSD 2.0-Release  *		PCVT_FREEBSD = 210	for FreeBSD 2.1-Release  *  */
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

begin_comment
comment|/*----------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* NOTE: if FAT_CURSOR is defined, a block cursor is used instead of	*/
end_comment

begin_comment
comment|/*       the cursor shape we got from the BIOS, see pcvt_out.c		*/
end_comment

begin_comment
comment|/*----------------------------------------------------------------------*/
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
comment|/* system. each screen allocates memory,*/
end_comment

begin_comment
comment|/* so you can't have an unlimited num-	*/
end_comment

begin_comment
comment|/* ber...; the value is intented to be	*/
end_comment

begin_comment
comment|/* compile-time overridable by a config	*/
end_comment

begin_comment
comment|/* options "PCVT_NSCREENS=x" line	*/
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
name|PCVT_KBD_FIFO
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_KBD_FIFO
value|1
end_define

begin_comment
comment|/* this enables Keyboad fifo so that we */
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_KBD_FIFO
operator|!=
literal|0
end_elif

begin_comment
comment|/* are not any longer forced to switch  */
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_KBD_FIFO
end_undef

begin_comment
comment|/* off tty interrupts while switching   */
end_comment

begin_define
define|#
directive|define
name|PCVT_KBD_FIFO
value|1
end_define

begin_comment
comment|/* virtual screens - AND loosing chars  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* on the serial lines is gone :-)      */
end_comment

begin_if
if|#
directive|if
name|PCVT_KBD_FIFO
end_if

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_KBD_FIFO_SZ
end_if

begin_comment
comment|/* ---------- DEFAULT: 256 ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_KBD_FIFO_SZ
value|256
end_define

begin_comment
comment|/* this specifies the size of the above */
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_KBD_FIFO_SZ
operator|<
literal|16
end_elif

begin_comment
comment|/* mentioned keyboard buffer. buffer    */
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_KBD_FIFO_SZ
end_undef

begin_comment
comment|/* overflows are logged via syslog, so  */
end_comment

begin_define
define|#
directive|define
name|PCVT_KBD_FIFO_SZ
value|256
end_define

begin_comment
comment|/* have a look at /var/log/messages     */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_KBD_FIFO */
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
name|PCVT_EMU_MOUSE
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_EMU_MOUSE
value|0
end_define

begin_comment
comment|/* emulate a mouse systems mouse via	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_EMU_MOUSE
operator|!=
literal|0
end_elif

begin_comment
comment|/* the keypad; this is experimental	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_EMU_MOUSE
end_undef

begin_comment
comment|/* code intented to be used on note-	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_EMU_MOUSE
value|1
end_define

begin_comment
comment|/* books in conjunction with XFree86;	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* look at the comments in pcvt_kbd.c	*/
end_comment

begin_comment
comment|/* if you are interested in testing it.	*/
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

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_SW0CNOUTP
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_SW0CNOUTP
value|0
end_define

begin_comment
comment|/* if ON, on console/kernel output the  */
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_SW0CNOUTP
operator|!=
literal|0
end_elif

begin_comment
comment|/* current screen is switched to screen */
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_SW0CNOUTP
end_undef

begin_comment
comment|/* 0 if not already at screen 0.        */
end_comment

begin_define
define|#
directive|define
name|PCVT_SW0CNOUTP
value|1
end_define

begin_comment
comment|/* CAUTION: CURRENTLY THIS CAUSES AN X- */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SESSION TO CLUTTER VIDEO MEMORY !!!! */
end_comment

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
name|PCVT_PORTIO_DELAY
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_PORTIO_DELAY
value|1
end_define

begin_comment
comment|/* Defining PCVT_PORTIO_DELAY lets pcvt */
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_PORTIO_DELAY
operator|!=
literal|0
end_elif

begin_comment
comment|/* use multiple accesses to port 0x84   */
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_PORTIO_DELAY
end_undef

begin_comment
comment|/* to produce a delay of 7 us needed for*/
end_comment

begin_define
define|#
directive|define
name|PCVT_PORTIO_DELAY
value|1
end_define

begin_comment
comment|/* accessing the keyboard controller,   */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* otherwise the system delay functions */
end_comment

begin_comment
comment|/* are used.                            */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_PCBURST
end_if

begin_comment
comment|/* ---------- DEFAULT: 256 ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_PCBURST
value|256
end_define

begin_comment
comment|/* NETBSD and FreeBSD>= 2.0 only: this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* is the number of output characters	*/
end_comment

begin_comment
comment|/* handled together as a burst in 	*/
end_comment

begin_comment
comment|/* routine pcstart(), file pcvt_drv.c	*/
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
name|PCVT_KEYBDID
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_KEYBDID
value|1
end_define

begin_comment
comment|/* check type of keyboard connected. at	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_KEYBDID
operator|!=
literal|0
end_elif

begin_comment
comment|/* least HP-keyboards send an id other	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_KEYBDID
end_undef

begin_comment
comment|/* than the industry standard, so it	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_KEYBDID
value|1
end_define

begin_comment
comment|/* CAN lead to problems. if you have	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* problems with this, TELL ME PLEASE !	*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_SIGWINCH
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_SIGWINCH
value|1
end_define

begin_comment
comment|/* this sends a SIGWINCH signal in case	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_SIGWINCH
operator|!=
literal|0
end_elif

begin_comment
comment|/* the window size is changed. to try,	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_SIGWINCH
end_undef

begin_comment
comment|/* issue "scons -s<size>" while in elvis*/
end_comment

begin_define
define|#
directive|define
name|PCVT_SIGWINCH
value|1
end_define

begin_comment
comment|/* and you'll see the effect.		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i'm not sure, whether this feature	*/
end_comment

begin_comment
comment|/* has to be in the driver or has to    */
end_comment

begin_comment
comment|/* move as an ioctl call to scon ....	*/
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
comment|/* out nulls. take it as experimental	*/
end_comment

begin_comment
comment|/* code, this behaviour will change in	*/
end_comment

begin_comment
comment|/* a future release			*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_BACKUP_FONTS
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_BACKUP_FONTS
value|1
end_define

begin_comment
comment|/* fonts are always kept memory-backed;	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_BACKUP_FONTS
operator|!=
literal|0
end_elif

begin_comment
comment|/* otherwise copies are only made if	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_BACKUP_FONTS
end_undef

begin_comment
comment|/* they are needed.			*/
end_comment

begin_define
define|#
directive|define
name|PCVT_BACKUP_FONTS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|PCVT_PALFLICKER
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_PALFLICKER
value|0
end_define

begin_comment
comment|/* this option turns off the screen 	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_PALFLICKER
operator|!=
literal|0
end_elif

begin_comment
comment|/* during accesses to the VGA DAC	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_PALFLICKER
end_undef

begin_comment
comment|/* registers. why: on one fo the tested	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_PALFLICKER
value|1
end_define

begin_comment
comment|/* pc's (WD-chipset), accesses to the	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vga dac registers caused distortions	*/
end_comment

begin_comment
comment|/* on the screen. Ferraro says, one has	*/
end_comment

begin_comment
comment|/* to blank the screen. the method used	*/
end_comment

begin_comment
comment|/* to accomplish this stopped the noise	*/
end_comment

begin_comment
comment|/* but introduced another flicker, so	*/
end_comment

begin_comment
comment|/* this is for you to experiment .....	*/
end_comment

begin_comment
comment|/* - see also PCVT_WAITRETRACE below --	*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_WAITRETRACE
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_WAITRETRACE
value|0
end_define

begin_comment
comment|/* this option waits for being in a 	*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_WAITRETRACE
operator|!=
literal|0
end_elif

begin_comment
comment|/* retrace window prior to accessing	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_WAITRETRACE
end_undef

begin_comment
comment|/* the VGA DAC registers.		*/
end_comment

begin_define
define|#
directive|define
name|PCVT_WAITRETRACE
value|1
end_define

begin_comment
comment|/* this is the other method Ferraro	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mentioned in his book. this option 	*/
end_comment

begin_comment
comment|/* did eleminate the flicker noticably	*/
end_comment

begin_comment
comment|/* but not completely. besides that, it	*/
end_comment

begin_comment
comment|/* is implemented as a busy-wait loop	*/
end_comment

begin_comment
comment|/* which is a no-no-no in environments	*/
end_comment

begin_comment
comment|/* like this - VERY BAD PRACTICE !!!!!	*/
end_comment

begin_comment
comment|/* the other method implementing it is	*/
end_comment

begin_comment
comment|/* using the vertical retrace irq, but	*/
end_comment

begin_comment
comment|/* we get short of irq-lines on pc's.	*/
end_comment

begin_comment
comment|/* this is for you to experiment .....	*/
end_comment

begin_comment
comment|/* -- see also PCVT_PALFLICKER above -- */
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
name|PCVT_NOFASTSCROLL
end_if

begin_comment
comment|/* ---------- DEFAULT: OFF ------------ */
end_comment

begin_define
define|#
directive|define
name|PCVT_NOFASTSCROLL
value|0
end_define

begin_comment
comment|/* If off, enables code for fast scroll.*/
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_NOFASTSCROLL
operator|!=
literal|0
end_elif

begin_comment
comment|/* This is done by changing the CRTC	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_NOFASTSCROLL
end_undef

begin_comment
comment|/* screen start address for scrolling	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_NOFASTSCROLL
value|1
end_define

begin_comment
comment|/* and using 2 times the screen size as	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* buffer. The fastscroll code works	*/
end_comment

begin_comment
comment|/* ONLY for VGA/EGA/CGA because it uses */
end_comment

begin_comment
comment|/* the crtc for hardware scrolling and	*/
end_comment

begin_comment
comment|/* therefore needs more than the one	*/
end_comment

begin_comment
comment|/* page video memory MDA and most 	*/
end_comment

begin_comment
comment|/* Hercules boards support.		*/
end_comment

begin_comment
comment|/* If you run pcvt ONLY on MDA/Hercules */
end_comment

begin_comment
comment|/* you should disable fastscroll to save*/
end_comment

begin_comment
comment|/* the time to decide which board you	*/
end_comment

begin_comment
comment|/* are running pcvt on at runtime.	*/
end_comment

begin_comment
comment|/*     [see roll_up() and roll_down().]	*/
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

begin_ifdef
ifdef|#
directive|ifdef
name|XSERVER
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
name|PCVT_USL_VT_COMPAT
end_if

begin_comment
comment|/* ---------- DEFAULT: ON ------------- */
end_comment

begin_define
define|#
directive|define
name|PCVT_USL_VT_COMPAT
value|1
end_define

begin_comment
comment|/* this option enables multiple virtual */
end_comment

begin_elif
elif|#
directive|elif
name|PCVT_USL_VT_COMPAT
operator|!=
literal|0
end_elif

begin_comment
comment|/* screen support for XFree86. If set	*/
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_USL_VT_COMPAT
end_undef

begin_comment
comment|/* to off, support for a "classic"	*/
end_comment

begin_define
define|#
directive|define
name|PCVT_USL_VT_COMPAT
value|1
end_define

begin_comment
comment|/* single screen only X server is	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* compiled in. If enabled, most of the	*/
end_comment

begin_comment
comment|/* ioctl's from SYSV/USL are supported	*/
end_comment

begin_comment
comment|/* to run multiple X servers and/or 	*/
end_comment

begin_comment
comment|/* character terminal sessions.		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XSERVER */
end_comment

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

