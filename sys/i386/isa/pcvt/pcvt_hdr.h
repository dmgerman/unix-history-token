begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1995 Hellmuth Michaelis and Joerg Wunsch.  *  * Copyright (c) 1992, 1993 Brian Dunford-Shore.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by  *	Hellmuth Michaelis, Brian Dunford-Shore and Joerg Wunsch.  * 4. The name authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * @(#)pcvt_hdr.h, 3.20, Last Edit-Date: [Fri Apr  7 10:16:58 1995]  *  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  *	pcvt_hdr.h	VT220 Driver Global Include File  *	------------------------------------------------  *	-hm	------------ Release 3.00 --------------  *	-hm	integrating NetBSD-current patches  *	-hm	integrating patches from Thomas Gellekum  *	-hm	moving vt_selattr() inline into this file  *	-hm	Michael's keyboard fifo diffs  *	-hm	documenting some #ifdef's ...  *	-hm	Joerg's patches for FreeBSD's ttymalloc  *	-jw	introduced kbd_emulate_pc() if scanset> 1  *	-hm	moved user configurable items to pcvt_conf.h  *	-hm	applying Joerg's patches for FreeBSD 2.0  *	-hm	patch from Onno& Martin for NetBSD-current (post 1.0)  *	-hm	some adjustments for NetBSD 1.0  *	-hm	patch from Joerg fixing FreeBSD 2.0 support  *	-hm	patch from Onno/John for NetBSD-current  *	-hm	applying patch from Joerg fixing Crtat bug  *	-hm	removed PCVT_FAKE_SYSCONS10  *	-hm	added pcstop (patch from Onno)  *	-hm	multiple X server bugfixes from Lon Willett  *	-hm	patch from Joerg for FreeBSD pre-2.1  *	-jw	adding more support for FreeBSD pre-2.1  *  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|PCVT_REL
value|"3.20-b24"
end_define

begin_comment
comment|/* driver attach announcement	*/
end_comment

begin_comment
comment|/* see also: pcvt_ioctl.h	*/
end_comment

begin_include
include|#
directive|include
file|"opt_pcvt.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PCVT_FREEBSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCVT_FREEBSD
value|210
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|>=
literal|200
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|>
literal|210
end_if

begin_include
include|#
directive|include
file|<machine/random.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_FREEBSD> 210 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! PCVT_FREEBSD>= 200 */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"signalvar.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"uio.h"
end_include

begin_include
include|#
directive|include
file|"callout.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"syslog.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_FREEBSD>= 200 */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/pcvt/pcvt_conf.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/kbdio.h>
end_include

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|>
literal|9
end_if

begin_include
include|#
directive|include
file|"device.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|>
literal|9
end_if

begin_include
include|#
directive|include
file|"i386/isa/isavar.h"
end_include

begin_include
include|#
directive|include
file|"i386/cpufunc.h"
end_include

begin_elif
elif|#
directive|elif
name|PCVT_FREEBSD
operator|>=
literal|200
end_elif

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"i386/isa/isa_device.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|>=
literal|200
end_if

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"i386/isa/icu.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|>
literal|100
end_if

begin_include
include|#
directive|include
file|"i386/isa/isareg.h"
end_include

begin_elif
elif|#
directive|elif
name|PCVT_FREEBSD
operator|>=
literal|200
end_elif

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"i386/isa/isa.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|>
literal|9
end_if

begin_include
include|#
directive|include
file|"dev/cons.h"
end_include

begin_elif
elif|#
directive|elif
name|PCVT_FREEBSD
operator|>=
literal|200
end_elif

begin_include
include|#
directive|include
file|<machine/cons.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"i386/i386/cons.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|<=
literal|9
end_if

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|>=
literal|200
end_if

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! PCVT_FREEBSD>= 200 */
end_comment

begin_include
include|#
directive|include
file|"machine/psl.h"
end_include

begin_include
include|#
directive|include
file|"machine/frame.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_FREEBSD>= 200 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_NETBSD<= 9 */
end_comment

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|>
literal|9
end_if

begin_include
include|#
directive|include
file|<i386/isa/pcvt/pcvt_ioctl.h>
end_include

begin_elif
elif|#
directive|elif
name|PCVT_FREEBSD
operator|>=
literal|200
end_elif

begin_include
include|#
directive|include
file|<machine/pcvt_ioctl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"machine/pcvt_ioctl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|>=
literal|200
end_if

begin_include
include|#
directive|include
file|<machine/pc/display.h>
end_include

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|>
literal|200
end_if

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCVT_FREEBSD>= 200 */
end_comment

begin_include
include|#
directive|include
file|"machine/pc/display.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_FREEBSD>= 200 */
end_comment

begin_comment
comment|/* setup irq disable function to use */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|PCVT_SLOW_INTERRUPT
operator|)
operator|&&
operator|(
name|PCVT_NETBSD
operator|>
literal|9
operator|)
end_if

begin_define
define|#
directive|define
name|PCVT_DISABLE_INTR
parameter_list|()
value|disable_intr()
end_define

begin_define
define|#
directive|define
name|PCVT_ENABLE_INTR
parameter_list|()
value|enable_intr()
end_define

begin_undef
undef|#
directive|undef
name|PCVT_SLOW_INTERRUPT
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCVT_DISABLE_INTR
parameter_list|()
value|s = spltty()
end_define

begin_define
define|#
directive|define
name|PCVT_ENABLE_INTR
parameter_list|()
value|splx(s)
end_define

begin_undef
undef|#
directive|undef
name|PCVT_SLOW_INTERRUPT
end_undef

begin_define
define|#
directive|define
name|PCVT_SLOW_INTERRUPT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* perform option consistency checks */
end_comment

begin_if
if|#
directive|if
name|defined
name|PCVT_FREEBSD
operator|&&
name|PCVT_FREEBSD
operator|==
literal|1
end_if

begin_undef
undef|#
directive|undef
name|PCVT_FREEBSD
end_undef

begin_define
define|#
directive|define
name|PCVT_FREEBSD
value|102
end_define

begin_comment
comment|/* assume 1.0 release */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|PCVT_NETBSD
operator|&&
name|PCVT_NETBSD
operator|==
literal|1
end_if

begin_undef
undef|#
directive|undef
name|PCVT_NETBSD
end_undef

begin_define
define|#
directive|define
name|PCVT_NETBSD
value|9
end_define

begin_comment
comment|/* assume 0.9 release for now */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|+
name|PCVT_NETBSD
operator|==
literal|0
end_if

begin_error
error|#
directive|error
literal|"pcvt_hdr.h: You MUST define one of PCVT_{NET,FREE}BSD \ in the config file"
end_error

begin_elif
elif|#
directive|elif
operator|(
name|PCVT_FREEBSD
operator|&&
name|PCVT_NETBSD
operator|)
end_elif

begin_error
error|#
directive|error
literal|"pcvt_hdr.h: You CAN only define *one* of PCVT_{NET,FREE}BSD \ in the config file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XSERVER
end_ifdef

begin_comment
comment|/* PCVT_NULLCHARS is mandatory for X server */
end_comment

begin_if
if|#
directive|if
operator|!
name|PCVT_NULLCHARS
end_if

begin_undef
undef|#
directive|undef
name|PCVT_NULLCHARS
end_undef

begin_define
define|#
directive|define
name|PCVT_NULLCHARS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_BACKUP_FONTS is mandatory for PCVT_USL_VT_COMPAT */
end_comment

begin_if
if|#
directive|if
name|PCVT_USL_VT_COMPAT
operator|&&
operator|!
name|PCVT_BACKUP_FONTS
end_if

begin_undef
undef|#
directive|undef
name|PCVT_BACKUP_FONTS
end_undef

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XSERVER */
end_comment

begin_if
if|#
directive|if
name|PCVT_USL_VT_COMPAT
end_if

begin_warning
warning|#
directive|warning
literal|"Option PCVT_USL_VT_COMPAT meaningless without XSERVER"
end_warning

begin_undef
undef|#
directive|undef
name|PCVT_USL_VT_COMPAT
end_undef

begin_define
define|#
directive|define
name|PCVT_USL_VT_COMPAT
value|0
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
comment|/* XSERVER */
end_comment

begin_comment
comment|/* PCVT_SCREENSAVER is mandatory for PCVT_PRETTYSCRNS */
end_comment

begin_if
if|#
directive|if
name|PCVT_PRETTYSCRNS
operator|&&
operator|!
name|PCVT_SCREENSAVER
end_if

begin_undef
undef|#
directive|undef
name|PCVT_SCREENSAVER
end_undef

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

begin_comment
comment|/* get the inline inb/outb back again ... */
end_comment

begin_if
if|#
directive|if
name|PCVT_NETBSD
end_if

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|==
literal|9
end_if

begin_include
include|#
directive|include
file|"machine/cpufunc.h"
end_include

begin_comment
comment|/* NetBSD 0.9 [...and earlier -currents] */
end_comment

begin_undef
undef|#
directive|undef
name|PCVT_USL_VT_COMPAT
end_undef

begin_define
define|#
directive|define
name|PCVT_USL_VT_COMPAT
value|0
end_define

begin_comment
comment|/* does not work, workaround ... */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"machine/pio.h"
end_include

begin_comment
comment|/* recent NetBSD -currents */
end_comment

begin_define
define|#
directive|define
name|NEW_AVERUNNABLE
end_define

begin_comment
comment|/* averunnable changes for younger currents */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_NETBSD == 9 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_NETBSD */
end_comment

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|>=
literal|200
end_if

begin_define
define|#
directive|define
name|NEW_AVERUNNABLE
end_define

begin_comment
comment|/* new averunnable changes for FreeBSD 2.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_SCANSET
operator|!=
literal|1
operator|&&
name|PCVT_SCANSET
operator|!=
literal|2
end_if

begin_error
error|#
directive|error
literal|"Supported keyboard scancode sets are 1 and 2 only (for now)!!!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Keyboard and Keyboard Controller  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_KBDIO_H_
end_ifndef

begin_define
define|#
directive|define
name|CONTROLLER_CTRL
value|0x64
end_define

begin_comment
comment|/* W - command, R - status	*/
end_comment

begin_define
define|#
directive|define
name|CONTROLLER_DATA
value|0x60
end_define

begin_comment
comment|/* R/W - data			*/
end_comment

begin_comment
comment|/* commands to control the CONTROLLER (8042) on the mainboard */
end_comment

begin_define
define|#
directive|define
name|CONTR_READ
value|0x20
end_define

begin_comment
comment|/* read command byte from controller */
end_comment

begin_define
define|#
directive|define
name|CONTR_WRITE
value|0x60
end_define

begin_comment
comment|/* write command to controller, see below */
end_comment

begin_define
define|#
directive|define
name|CONTR_SELFTEST
value|0xaa
end_define

begin_comment
comment|/* controller selftest, returns 0x55 when ok */
end_comment

begin_define
define|#
directive|define
name|CONTR_IFTEST
value|0xab
end_define

begin_comment
comment|/* interface selftest */
end_comment

begin_define
define|#
directive|define
name|CONTR_KBDISABL
value|0xad
end_define

begin_comment
comment|/* disable keyboard */
end_comment

begin_define
define|#
directive|define
name|CONTR_KBENABL
value|0xae
end_define

begin_comment
comment|/* enable keyboard */
end_comment

begin_comment
comment|/* command byte for writing to CONTROLLER (8042) via CONTR_WRITE */
end_comment

begin_define
define|#
directive|define
name|COMMAND_RES7
value|0x80
end_define

begin_comment
comment|/* bit 7, reserved, always write a ZERO ! */
end_comment

begin_define
define|#
directive|define
name|COMMAND_PCSCAN
value|0x40
end_define

begin_comment
comment|/* bit 6, 1 = convert to pc scan codes */
end_comment

begin_define
define|#
directive|define
name|COMMAND_RES5
value|0x20
end_define

begin_comment
comment|/* bit 5, perhaps (!) use 9bit frame 				 * instead of 11 */
end_comment

begin_define
define|#
directive|define
name|COMMAND_DISABL
value|0x10
end_define

begin_comment
comment|/* bit 4, 1 = disable keyboard */
end_comment

begin_define
define|#
directive|define
name|COMMAND_INHOVR
value|0x08
end_define

begin_comment
comment|/* bit 3, 1 = override security lock inhibit */
end_comment

begin_define
define|#
directive|define
name|COMMAND_SYSFLG
value|0x04
end_define

begin_comment
comment|/* bit 2, value stored as "system flag" */
end_comment

begin_define
define|#
directive|define
name|COMMAND_RES2
value|0x02
end_define

begin_comment
comment|/* bit 1, reserved, always write a ZERO ! */
end_comment

begin_define
define|#
directive|define
name|COMMAND_IRQEN
value|0x01
end_define

begin_comment
comment|/* bit 0, 1 = enable output buffer full 				 * interrupt */
end_comment

begin_comment
comment|/* status from CONTROLLER (8042) on the mainboard */
end_comment

begin_define
define|#
directive|define
name|STATUS_PARITY
value|0x80
end_define

begin_comment
comment|/* bit 7, 1 = parity error on last byte */
end_comment

begin_define
define|#
directive|define
name|STATUS_RXTIMO
value|0x40
end_define

begin_comment
comment|/* bit 6, 1 = receive timeout error occured */
end_comment

begin_define
define|#
directive|define
name|STATUS_TXTIMO
value|0x20
end_define

begin_comment
comment|/* bit 5, 1 = transmit timeout error occured */
end_comment

begin_define
define|#
directive|define
name|STATUS_ENABLE
value|0x10
end_define

begin_comment
comment|/* bit 4, 1 = keyboard unlocked */
end_comment

begin_define
define|#
directive|define
name|STATUS_WHAT
value|0x08
end_define

begin_comment
comment|/* bit 3, 1 = wrote cmd to 0x64, 0 = wrote 				 * data to 0x60 */
end_comment

begin_define
define|#
directive|define
name|STATUS_SYSFLG
value|0x04
end_define

begin_comment
comment|/* bit 2, value stored as "system flag" */
end_comment

begin_define
define|#
directive|define
name|STATUS_INPBF
value|0x02
end_define

begin_comment
comment|/* bit 1, 1 = input buffer full (to 8042) */
end_comment

begin_define
define|#
directive|define
name|STATUS_OUTPBF
value|0x01
end_define

begin_comment
comment|/* bit 0, 1 = output buffer full (from 8042) */
end_comment

begin_comment
comment|/* commands to the KEYBOARD (via the 8042 controller on mainboard..) */
end_comment

begin_define
define|#
directive|define
name|KEYB_C_RESET
value|0xff
end_define

begin_comment
comment|/* reset keyboard to power-on status */
end_comment

begin_define
define|#
directive|define
name|KEYB_C_RESEND
value|0xfe
end_define

begin_comment
comment|/* resend last byte in case of error */
end_comment

begin_define
define|#
directive|define
name|KEYB_C_TYPEM
value|0xf3
end_define

begin_comment
comment|/* set keyboard typematic rate/delay */
end_comment

begin_define
define|#
directive|define
name|KEYB_C_ID
value|0xf2
end_define

begin_comment
comment|/* return keyboard id */
end_comment

begin_define
define|#
directive|define
name|KEYB_C_ECHO
value|0xee
end_define

begin_comment
comment|/* diagnostic, echo 0xee */
end_comment

begin_define
define|#
directive|define
name|KEYB_C_LEDS
value|0xed
end_define

begin_comment
comment|/* set/reset numlock,capslock& scroll lock */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_ISA_KBDIO_H_ */
end_comment

begin_comment
comment|/* responses from the KEYBOARD (via the 8042 controller on mainboard..) */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_OVERRUN0
value|0x00
end_define

begin_comment
comment|/* keyboard buffer overflow */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_SELFOK
value|0xaa
end_define

begin_comment
comment|/* keyboard selftest ok after KEYB_C_RESET */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_EXT0
value|0xe0
end_define

begin_comment
comment|/* keyboard extended scancode prefix 1 */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_EXT1
value|0xe1
end_define

begin_comment
comment|/* keyboard extended scancode prefix 2 */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_ECHO
value|0xee
end_define

begin_comment
comment|/* keyboard response to KEYB_C_ECHO */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_BREAKPFX
value|0xf0
end_define

begin_comment
comment|/* break code prefix for set 2 and 3 */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_ACK
value|0xfa
end_define

begin_comment
comment|/* acknowledge after a command has rx'd */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_SELFBAD
value|0xfc
end_define

begin_comment
comment|/*keyboard selftest FAILED after KEYB_C_RESET*/
end_comment

begin_define
define|#
directive|define
name|KEYB_R_DIAGBAD
value|0xfd
end_define

begin_comment
comment|/* keyboard self diagnostic failure */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_RESEND
value|0xfe
end_define

begin_comment
comment|/* keyboard wants command resent or illegal 				 * command rx'd */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_OVERRUN1
value|0xff
end_define

begin_comment
comment|/* keyboard buffer overflow */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_MF2ID1
value|0xab
end_define

begin_comment
comment|/* MF II Keyboard id-byte #1 */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_MF2ID2
value|0x41
end_define

begin_comment
comment|/* MF II Keyboard id-byte #2 */
end_comment

begin_define
define|#
directive|define
name|KEYB_R_MF2ID2HP
value|0x83
end_define

begin_comment
comment|/* MF II Keyboard id-byte #2 from HP keybd's */
end_comment

begin_comment
comment|/* internal Keyboard Type */
end_comment

begin_define
define|#
directive|define
name|KB_UNKNOWN
value|0
end_define

begin_comment
comment|/* unknown keyboard type */
end_comment

begin_define
define|#
directive|define
name|KB_AT
value|1
end_define

begin_comment
comment|/* AT (84 keys) Keyboard */
end_comment

begin_define
define|#
directive|define
name|KB_MFII
value|2
end_define

begin_comment
comment|/* MF II (101/102 keys) Keyboard */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	CMOS ram access to get the "Equipment Byte"  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|RTC_EQUIPMENT
value|0x14
end_define

begin_comment
comment|/* equipment byte in cmos ram	*/
end_comment

begin_define
define|#
directive|define
name|EQ_EGAVGA
value|0
end_define

begin_comment
comment|/* reserved (= ega/vga)		*/
end_comment

begin_define
define|#
directive|define
name|EQ_40COLOR
value|1
end_define

begin_comment
comment|/* display = 40 col color	*/
end_comment

begin_define
define|#
directive|define
name|EQ_80COLOR
value|2
end_define

begin_comment
comment|/* display = 80 col color	*/
end_comment

begin_define
define|#
directive|define
name|EQ_80MONO
value|3
end_define

begin_comment
comment|/* display = 80 col mono	*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	VT220 -> internal color conversion table fields  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|VT_NORMAL
value|0x00
end_define

begin_comment
comment|/* no attributes at all */
end_comment

begin_define
define|#
directive|define
name|VT_BOLD
value|0x01
end_define

begin_comment
comment|/* bold attribute */
end_comment

begin_define
define|#
directive|define
name|VT_UNDER
value|0x02
end_define

begin_comment
comment|/* underline attribute */
end_comment

begin_define
define|#
directive|define
name|VT_BLINK
value|0x04
end_define

begin_comment
comment|/* blink attribute */
end_comment

begin_define
define|#
directive|define
name|VT_INVERSE
value|0x08
end_define

begin_comment
comment|/* inverse attribute */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	VGA GENERAL/EXTERNAL Registers          (3BA or 3DA and 3CA, 3C2, 3CC)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|GN_MISCOUTR
value|0x3CC
end_define

begin_comment
comment|/* misc output register read */
end_comment

begin_define
define|#
directive|define
name|GN_MISCOUTW
value|0x3C2
end_define

begin_comment
comment|/* misc output register write */
end_comment

begin_define
define|#
directive|define
name|GN_INPSTAT0
value|0x3C2
end_define

begin_comment
comment|/* input status 0, r/o */
end_comment

begin_define
define|#
directive|define
name|GN_INPSTAT1M
value|0x3BA
end_define

begin_comment
comment|/* input status 1, r/o, mono */
end_comment

begin_define
define|#
directive|define
name|GN_INPSTAT1C
value|0x3DA
end_define

begin_comment
comment|/* input status 1, r/o, color */
end_comment

begin_define
define|#
directive|define
name|GN_FEATR
value|0x3CA
end_define

begin_comment
comment|/* feature control, read */
end_comment

begin_define
define|#
directive|define
name|GN_FEATWM
value|0x3BA
end_define

begin_comment
comment|/* feature control, write, mono */
end_comment

begin_define
define|#
directive|define
name|GN_FEATWC
value|0x3DA
end_define

begin_comment
comment|/* feature control, write, color */
end_comment

begin_define
define|#
directive|define
name|GN_VSUBSYS
value|0x3C3
end_define

begin_comment
comment|/* video subsystem register r/w */
end_comment

begin_define
define|#
directive|define
name|GN_DMCNTLM
value|0x3B8
end_define

begin_comment
comment|/* display mode control, r/w, mono */
end_comment

begin_define
define|#
directive|define
name|GN_DMCNTLC
value|0x3D8
end_define

begin_comment
comment|/* display mode control, r/w, color */
end_comment

begin_define
define|#
directive|define
name|GN_COLORSEL
value|0x3D9
end_define

begin_comment
comment|/* color select register, w/o */
end_comment

begin_define
define|#
directive|define
name|GN_HERCOMPAT
value|0x3BF
end_define

begin_comment
comment|/* Hercules compatibility reg, w/o */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	VGA CRTC Registers			  (3B4 and 3B5 or 3D4 and 3D5)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|MONO_BASE
value|0x3B4
end_define

begin_comment
comment|/* crtc index register address mono */
end_comment

begin_define
define|#
directive|define
name|CGA_BASE
value|0x3D4
end_define

begin_comment
comment|/* crtc index register address color */
end_comment

begin_define
define|#
directive|define
name|CRTC_ADDR
value|0x00
end_define

begin_comment
comment|/* index register */
end_comment

begin_define
define|#
directive|define
name|CRTC_HTOTAL
value|0x00
end_define

begin_comment
comment|/* horizontal total */
end_comment

begin_define
define|#
directive|define
name|CRTC_HDISPLE
value|0x01
end_define

begin_comment
comment|/* horizontal display end */
end_comment

begin_define
define|#
directive|define
name|CRTC_HBLANKS
value|0x02
end_define

begin_comment
comment|/* horizontal blank start */
end_comment

begin_define
define|#
directive|define
name|CRTC_HBLANKE
value|0x03
end_define

begin_comment
comment|/* horizontal blank end */
end_comment

begin_define
define|#
directive|define
name|CRTC_HSYNCS
value|0x04
end_define

begin_comment
comment|/* horizontal sync start */
end_comment

begin_define
define|#
directive|define
name|CRTC_HSYNCE
value|0x05
end_define

begin_comment
comment|/* horizontal sync end */
end_comment

begin_define
define|#
directive|define
name|CRTC_VTOTAL
value|0x06
end_define

begin_comment
comment|/* vertical total */
end_comment

begin_define
define|#
directive|define
name|CRTC_OVERFLL
value|0x07
end_define

begin_comment
comment|/* overflow low */
end_comment

begin_define
define|#
directive|define
name|CRTC_IROWADDR
value|0x08
end_define

begin_comment
comment|/* inital row address */
end_comment

begin_define
define|#
directive|define
name|CRTC_MAXROW
value|0x09
end_define

begin_comment
comment|/* maximum row address */
end_comment

begin_define
define|#
directive|define
name|CRTC_CURSTART
value|0x0A
end_define

begin_comment
comment|/* cursor start row address */
end_comment

begin_define
define|#
directive|define
name|CURSOR_ON_BIT
value|0x20
end_define

begin_comment
comment|/* cursor on/off on mda/cga/vga */
end_comment

begin_define
define|#
directive|define
name|CRTC_CUREND
value|0x0B
end_define

begin_comment
comment|/* cursor end row address */
end_comment

begin_define
define|#
directive|define
name|CRTC_STARTADRH
value|0x0C
end_define

begin_comment
comment|/* linear start address mid */
end_comment

begin_define
define|#
directive|define
name|CRTC_STARTADRL
value|0x0D
end_define

begin_comment
comment|/* linear start address low */
end_comment

begin_define
define|#
directive|define
name|CRTC_CURSORH
value|0x0E
end_define

begin_comment
comment|/* cursor address mid */
end_comment

begin_define
define|#
directive|define
name|CRTC_CURSORL
value|0x0F
end_define

begin_comment
comment|/* cursor address low */
end_comment

begin_define
define|#
directive|define
name|CRTC_VSYNCS
value|0x10
end_define

begin_comment
comment|/* vertical sync start */
end_comment

begin_define
define|#
directive|define
name|CRTC_VSYNCE
value|0x11
end_define

begin_comment
comment|/* vertical sync end */
end_comment

begin_define
define|#
directive|define
name|CRTC_VDE
value|0x12
end_define

begin_comment
comment|/* vertical display end */
end_comment

begin_define
define|#
directive|define
name|CRTC_OFFSET
value|0x13
end_define

begin_comment
comment|/* row offset */
end_comment

begin_define
define|#
directive|define
name|CRTC_ULOC
value|0x14
end_define

begin_comment
comment|/* underline row address */
end_comment

begin_define
define|#
directive|define
name|CRTC_VBSTART
value|0x15
end_define

begin_comment
comment|/* vertical blank start */
end_comment

begin_define
define|#
directive|define
name|CRTC_VBEND
value|0x16
end_define

begin_comment
comment|/* vertical blank end */
end_comment

begin_define
define|#
directive|define
name|CRTC_MODE
value|0x17
end_define

begin_comment
comment|/* CRTC mode register */
end_comment

begin_define
define|#
directive|define
name|CRTC_SPLITL
value|0x18
end_define

begin_comment
comment|/* split screen start low */
end_comment

begin_comment
comment|/* start of ET4000 extensions */
end_comment

begin_define
define|#
directive|define
name|CRTC_RASCAS
value|0x32
end_define

begin_comment
comment|/* ras/cas configuration */
end_comment

begin_define
define|#
directive|define
name|CRTC_EXTSTART
value|0x33
end_define

begin_comment
comment|/* extended start address */
end_comment

begin_define
define|#
directive|define
name|CRTC_COMPAT6845
value|0x34
end_define

begin_comment
comment|/* 6845 comatibility control */
end_comment

begin_define
define|#
directive|define
name|CRTC_OVFLHIGH
value|0x35
end_define

begin_comment
comment|/* overflow high */
end_comment

begin_define
define|#
directive|define
name|CRTC_SYSCONF1
value|0x36
end_define

begin_comment
comment|/* video system configuration 1 */
end_comment

begin_define
define|#
directive|define
name|CRTC_SYSCONF2
value|0x36
end_define

begin_comment
comment|/* video system configuration 2 */
end_comment

begin_comment
comment|/* start of WD/Paradise extensions */
end_comment

begin_define
define|#
directive|define
name|CRTC_PR10
value|0x29
end_define

begin_comment
comment|/* r/w unlocking */
end_comment

begin_define
define|#
directive|define
name|CRTC_PR11
value|0x2A
end_define

begin_comment
comment|/* ega switches */
end_comment

begin_define
define|#
directive|define
name|CRTC_PR12
value|0x2B
end_define

begin_comment
comment|/* scratch pad */
end_comment

begin_define
define|#
directive|define
name|CRTC_PR13
value|0x2C
end_define

begin_comment
comment|/* interlace h/2 start */
end_comment

begin_define
define|#
directive|define
name|CRTC_PR14
value|0x2D
end_define

begin_comment
comment|/* interlace h/2 end */
end_comment

begin_define
define|#
directive|define
name|CRTC_PR15
value|0x2E
end_define

begin_comment
comment|/* misc control #1 */
end_comment

begin_define
define|#
directive|define
name|CRTC_PR16
value|0x2F
end_define

begin_comment
comment|/* misc control #2 */
end_comment

begin_define
define|#
directive|define
name|CRTC_PR17
value|0x30
end_define

begin_comment
comment|/* misc control #3 */
end_comment

begin_comment
comment|/* 0x31 .. 0x3f reserved */
end_comment

begin_comment
comment|/* Video 7 */
end_comment

begin_define
define|#
directive|define
name|CRTC_V7ID
value|0x1f
end_define

begin_comment
comment|/* identification register */
end_comment

begin_comment
comment|/* Trident */
end_comment

begin_define
define|#
directive|define
name|CRTC_MTEST
value|0x1e
end_define

begin_comment
comment|/* module test register */
end_comment

begin_define
define|#
directive|define
name|CRTC_SOFTPROG
value|0x1f
end_define

begin_comment
comment|/* software programming */
end_comment

begin_define
define|#
directive|define
name|CRTC_LATCHRDB
value|0x22
end_define

begin_comment
comment|/* latch read back register */
end_comment

begin_define
define|#
directive|define
name|CRTC_ATTRSRDB
value|0x24
end_define

begin_comment
comment|/* attribute state read back register*/
end_comment

begin_define
define|#
directive|define
name|CRTC_ATTRIRDB
value|0x26
end_define

begin_comment
comment|/* attribute index read back register*/
end_comment

begin_define
define|#
directive|define
name|CRTC_HOSTAR
value|0x27
end_define

begin_comment
comment|/* high order start address register */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	VGA TIMING& SEQUENCER Registers			 (3C4 and 3C5)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|TS_INDEX
value|0x3C4
end_define

begin_comment
comment|/* index register */
end_comment

begin_define
define|#
directive|define
name|TS_DATA
value|0x3C5
end_define

begin_comment
comment|/* data register */
end_comment

begin_define
define|#
directive|define
name|TS_SYNCRESET
value|0x00
end_define

begin_comment
comment|/* synchronous reset */
end_comment

begin_define
define|#
directive|define
name|TS_MODE
value|0x01
end_define

begin_comment
comment|/* ts mode register */
end_comment

begin_define
define|#
directive|define
name|TS_WRPLMASK
value|0x02
end_define

begin_comment
comment|/* write plane mask */
end_comment

begin_define
define|#
directive|define
name|TS_FONTSEL
value|0x03
end_define

begin_comment
comment|/* font select register */
end_comment

begin_define
define|#
directive|define
name|TS_MEMMODE
value|0x04
end_define

begin_comment
comment|/* memory mode register */
end_comment

begin_comment
comment|/* ET4000 only */
end_comment

begin_define
define|#
directive|define
name|TS_RESERVED
value|0x05
end_define

begin_comment
comment|/* undef, reserved */
end_comment

begin_define
define|#
directive|define
name|TS_STATECNTL
value|0x06
end_define

begin_comment
comment|/* state control register */
end_comment

begin_define
define|#
directive|define
name|TS_AUXMODE
value|0x07
end_define

begin_comment
comment|/* auxiliary mode control */
end_comment

begin_comment
comment|/* WD/Paradise only */
end_comment

begin_define
define|#
directive|define
name|TS_UNLOCKSEQ
value|0x06
end_define

begin_comment
comment|/* PR20 - unlock sequencer register */
end_comment

begin_define
define|#
directive|define
name|TS_DISCFSTAT
value|0x07
end_define

begin_comment
comment|/* PR21 - display config status */
end_comment

begin_define
define|#
directive|define
name|TS_MEMFIFOCTL
value|0x10
end_define

begin_comment
comment|/* PR30 - memory i/f& fifo control */
end_comment

begin_define
define|#
directive|define
name|TS_SYSIFCNTL
value|0x11
end_define

begin_comment
comment|/* PR31 - system interface control */
end_comment

begin_define
define|#
directive|define
name|TS_MISC4
value|0x12
end_define

begin_comment
comment|/* PR32 - misc control #4 */
end_comment

begin_comment
comment|/* Video 7 */
end_comment

begin_define
define|#
directive|define
name|TS_EXTCNTL
value|0x06
end_define

begin_comment
comment|/* extensions control */
end_comment

begin_define
define|#
directive|define
name|TS_CLRVDISP
value|0x30
end_define

begin_comment
comment|/* clear vertical display 0x30-0x3f */
end_comment

begin_define
define|#
directive|define
name|TS_V7CHIPREV
value|0x8e
end_define

begin_comment
comment|/* chipset revision 0x8e-0x8f */
end_comment

begin_define
define|#
directive|define
name|TS_SWBANK
value|0xe8
end_define

begin_comment
comment|/* single/write bank register, rev 5+*/
end_comment

begin_define
define|#
directive|define
name|TS_RDBANK
value|0xe8
end_define

begin_comment
comment|/* read bank register, rev 4+ */
end_comment

begin_define
define|#
directive|define
name|TS_MISCCNTL
value|0xe8
end_define

begin_comment
comment|/* misc control register, rev 4+ */
end_comment

begin_define
define|#
directive|define
name|TS_SWSTROBE
value|0xea
end_define

begin_comment
comment|/* switch strobe */
end_comment

begin_define
define|#
directive|define
name|TS_MWRCNTL
value|0xf3
end_define

begin_comment
comment|/* masked write control */
end_comment

begin_define
define|#
directive|define
name|TS_MWRMVRAM
value|0xf4
end_define

begin_comment
comment|/* masked write mask VRAM only */
end_comment

begin_define
define|#
directive|define
name|TS_BANKSEL
value|0xf6
end_define

begin_comment
comment|/* bank select */
end_comment

begin_define
define|#
directive|define
name|TS_SWREADB
value|0xf7
end_define

begin_comment
comment|/* switch readback */
end_comment

begin_define
define|#
directive|define
name|TS_PAGESEL
value|0xf9
end_define

begin_comment
comment|/* page select */
end_comment

begin_define
define|#
directive|define
name|TS_COMPAT
value|0xfc
end_define

begin_comment
comment|/* compatibility control */
end_comment

begin_define
define|#
directive|define
name|TS_16BITCTL
value|0xff
end_define

begin_comment
comment|/* 16 bit interface control */
end_comment

begin_comment
comment|/* Trident */
end_comment

begin_define
define|#
directive|define
name|TS_HWVERS
value|0x0b
end_define

begin_comment
comment|/* hardware version, switch old/new! */
end_comment

begin_define
define|#
directive|define
name|TS_CONFPORT1
value|0x0c
end_define

begin_comment
comment|/* config port 1 and 2    - caution! */
end_comment

begin_define
define|#
directive|define
name|TS_MODEC2
value|0x0d
end_define

begin_comment
comment|/* old/new mode control 2 - caution! */
end_comment

begin_define
define|#
directive|define
name|TS_MODEC1
value|0x0e
end_define

begin_comment
comment|/* old/new mode control 1 - caution! */
end_comment

begin_define
define|#
directive|define
name|TS_PUPM2
value|0x0f
end_define

begin_comment
comment|/* power up mode 2 */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	VGA GRAPHICS DATA CONTROLLER Registers		    (3CE, 3CF and 3CD)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|GDC_SEGSEL
value|0x3CD
end_define

begin_comment
comment|/* segment select register */
end_comment

begin_define
define|#
directive|define
name|GDC_INDEX
value|0x3CE
end_define

begin_comment
comment|/* index register */
end_comment

begin_define
define|#
directive|define
name|GDC_DATA
value|0x3CF
end_define

begin_comment
comment|/* data register */
end_comment

begin_define
define|#
directive|define
name|GDC_SETRES
value|0x00
end_define

begin_comment
comment|/* set / reset bits */
end_comment

begin_define
define|#
directive|define
name|GDC_ENSETRES
value|0x01
end_define

begin_comment
comment|/* enable set / reset */
end_comment

begin_define
define|#
directive|define
name|GDC_COLORCOMP
value|0x02
end_define

begin_comment
comment|/* color compare register */
end_comment

begin_define
define|#
directive|define
name|GDC_ROTFUNC
value|0x03
end_define

begin_comment
comment|/* data rotate / function select */
end_comment

begin_define
define|#
directive|define
name|GDC_RDPLANESEL
value|0x04
end_define

begin_comment
comment|/* read plane select */
end_comment

begin_define
define|#
directive|define
name|GDC_MODE
value|0x05
end_define

begin_comment
comment|/* gdc mode register */
end_comment

begin_define
define|#
directive|define
name|GDC_MISC
value|0x06
end_define

begin_comment
comment|/* gdc misc register */
end_comment

begin_define
define|#
directive|define
name|GDC_COLORCARE
value|0x07
end_define

begin_comment
comment|/* color care register */
end_comment

begin_define
define|#
directive|define
name|GDC_BITMASK
value|0x08
end_define

begin_comment
comment|/* bit mask register */
end_comment

begin_comment
comment|/* WD/Paradise only */
end_comment

begin_define
define|#
directive|define
name|GDC_BANKSWA
value|0x09
end_define

begin_comment
comment|/* PR0A - bank switch a */
end_comment

begin_define
define|#
directive|define
name|GDC_BANKSWB
value|0x0a
end_define

begin_comment
comment|/* PR0B - bank switch b */
end_comment

begin_define
define|#
directive|define
name|GDC_MEMSIZE
value|0x0b
end_define

begin_comment
comment|/* PR1 memory size */
end_comment

begin_define
define|#
directive|define
name|GDC_VIDEOSEL
value|0x0c
end_define

begin_comment
comment|/* PR2 video configuration */
end_comment

begin_define
define|#
directive|define
name|GDC_CRTCNTL
value|0x0d
end_define

begin_comment
comment|/* PR3 crt address control */
end_comment

begin_define
define|#
directive|define
name|GDC_VIDEOCNTL
value|0x0e
end_define

begin_comment
comment|/* PR4 video control */
end_comment

begin_define
define|#
directive|define
name|GDC_PR5GPLOCK
value|0x0f
end_define

begin_comment
comment|/* PR5 gp status and lock */
end_comment

begin_comment
comment|/* Video 7 */
end_comment

begin_define
define|#
directive|define
name|GDC_DATALATCH
value|0x22
end_define

begin_comment
comment|/* gdc data latch */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	VGA ATTRIBUTE CONTROLLER Registers			 (3C0 and 3C1)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|ATC_INDEX
value|0x3C0
end_define

begin_comment
comment|/* index register  AND	*/
end_comment

begin_define
define|#
directive|define
name|ATC_DATAW
value|0x3C0
end_define

begin_comment
comment|/* data write	   !!!	*/
end_comment

begin_define
define|#
directive|define
name|ATC_DATAR
value|0x3C1
end_define

begin_comment
comment|/* data read */
end_comment

begin_define
define|#
directive|define
name|ATC_ACCESS
value|0x20
end_define

begin_comment
comment|/* access bit in ATC index register */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE0
value|0x00
end_define

begin_comment
comment|/* color palette register 0 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE1
value|0x01
end_define

begin_comment
comment|/* color palette register 1 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE2
value|0x02
end_define

begin_comment
comment|/* color palette register 2 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE3
value|0x03
end_define

begin_comment
comment|/* color palette register 3 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE4
value|0x04
end_define

begin_comment
comment|/* color palette register 4 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE5
value|0x05
end_define

begin_comment
comment|/* color palette register 5 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE6
value|0x06
end_define

begin_comment
comment|/* color palette register 6 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE7
value|0x07
end_define

begin_comment
comment|/* color palette register 7 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE8
value|0x08
end_define

begin_comment
comment|/* color palette register 8 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTE9
value|0x09
end_define

begin_comment
comment|/* color palette register 9 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTEA
value|0x0A
end_define

begin_comment
comment|/* color palette register 10 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTEB
value|0x0B
end_define

begin_comment
comment|/* color palette register 11 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTEC
value|0x0C
end_define

begin_comment
comment|/* color palette register 12 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTED
value|0x0D
end_define

begin_comment
comment|/* color palette register 13 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTEE
value|0x0E
end_define

begin_comment
comment|/* color palette register 14 */
end_comment

begin_define
define|#
directive|define
name|ATC_PALETTEF
value|0x0F
end_define

begin_comment
comment|/* color palette register 15 */
end_comment

begin_define
define|#
directive|define
name|ATC_MODE
value|0x10
end_define

begin_comment
comment|/* atc mode register */
end_comment

begin_define
define|#
directive|define
name|ATC_OVERSCAN
value|0x11
end_define

begin_comment
comment|/* overscan register */
end_comment

begin_define
define|#
directive|define
name|ATC_COLPLEN
value|0x12
end_define

begin_comment
comment|/* color plane enable register */
end_comment

begin_define
define|#
directive|define
name|ATC_HORPIXPAN
value|0x13
end_define

begin_comment
comment|/* horizontal pixel panning */
end_comment

begin_define
define|#
directive|define
name|ATC_COLRESET
value|0x14
end_define

begin_comment
comment|/* color reset */
end_comment

begin_define
define|#
directive|define
name|ATC_MISC
value|0x16
end_define

begin_comment
comment|/* misc register (ET3000/ET4000) */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	VGA palette handling (output DAC palette)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|VGA_DAC
value|0x3C6
end_define

begin_comment
comment|/* vga dac address */
end_comment

begin_define
define|#
directive|define
name|VGA_PMSK
value|0x3F
end_define

begin_comment
comment|/* palette mask, 64 distinct values */
end_comment

begin_define
define|#
directive|define
name|NVGAPEL
value|256
end_define

begin_comment
comment|/* number of palette entries */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	function key labels  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|LABEL_LEN
value|9
end_define

begin_comment
comment|/* length of one label */
end_comment

begin_define
define|#
directive|define
name|LABEL_MID
value|8
end_define

begin_comment
comment|/* mid-part (row/col)	*/
end_comment

begin_define
define|#
directive|define
name|LABEL_ROWH
value|((4*LABEL_LEN)+1)
end_define

begin_define
define|#
directive|define
name|LABEL_ROWL
value|((4*LABEL_LEN)+2)
end_define

begin_define
define|#
directive|define
name|LABEL_COLU
value|((4*LABEL_LEN)+4)
end_define

begin_define
define|#
directive|define
name|LABEL_COLH
value|((4*LABEL_LEN)+5)
end_define

begin_define
define|#
directive|define
name|LABEL_COLL
value|((4*LABEL_LEN)+6)
end_define

begin_comment
comment|/* tab setting */
end_comment

begin_define
define|#
directive|define
name|MAXTAB
value|132
end_define

begin_comment
comment|/* no of possible tab stops */
end_comment

begin_comment
comment|/* escape detection state machine */
end_comment

begin_define
define|#
directive|define
name|STATE_INIT
value|0
end_define

begin_comment
comment|/* normal	*/
end_comment

begin_define
define|#
directive|define
name|STATE_ESC
value|1
end_define

begin_comment
comment|/* got ESC	*/
end_comment

begin_define
define|#
directive|define
name|STATE_BLANK
value|2
end_define

begin_comment
comment|/* got ESC space*/
end_comment

begin_define
define|#
directive|define
name|STATE_HASH
value|3
end_define

begin_comment
comment|/* got ESC #	*/
end_comment

begin_define
define|#
directive|define
name|STATE_BROPN
value|4
end_define

begin_comment
comment|/* got ESC (	*/
end_comment

begin_define
define|#
directive|define
name|STATE_BRCLO
value|5
end_define

begin_comment
comment|/* got ESC )	*/
end_comment

begin_define
define|#
directive|define
name|STATE_CSI
value|6
end_define

begin_comment
comment|/* got ESC [	*/
end_comment

begin_define
define|#
directive|define
name|STATE_CSIQM
value|7
end_define

begin_comment
comment|/* got ESC [ ?	*/
end_comment

begin_define
define|#
directive|define
name|STATE_AMPSND
value|8
end_define

begin_comment
comment|/* got ESC&	*/
end_comment

begin_define
define|#
directive|define
name|STATE_STAR
value|9
end_define

begin_comment
comment|/* got ESC *	*/
end_comment

begin_define
define|#
directive|define
name|STATE_PLUS
value|10
end_define

begin_comment
comment|/* got ESC +	*/
end_comment

begin_define
define|#
directive|define
name|STATE_DCS
value|11
end_define

begin_comment
comment|/* got ESC P	*/
end_comment

begin_define
define|#
directive|define
name|STATE_SCA
value|12
end_define

begin_comment
comment|/* got ESC<Ps> " */
end_comment

begin_define
define|#
directive|define
name|STATE_STR
value|13
end_define

begin_comment
comment|/* got ESC !	*/
end_comment

begin_define
define|#
directive|define
name|STATE_MINUS
value|14
end_define

begin_comment
comment|/* got ESC -	*/
end_comment

begin_define
define|#
directive|define
name|STATE_DOT
value|15
end_define

begin_comment
comment|/* got ESC .	*/
end_comment

begin_define
define|#
directive|define
name|STATE_SLASH
value|16
end_define

begin_comment
comment|/* got ESC /	*/
end_comment

begin_comment
comment|/* for storing escape sequence parameters */
end_comment

begin_define
define|#
directive|define
name|MAXPARMS
value|10
end_define

begin_comment
comment|/* maximum no of parms */
end_comment

begin_comment
comment|/* terminal responses */
end_comment

begin_define
define|#
directive|define
name|DA_VT220
value|"\033[?62;1;2;6;7;8;9c"
end_define

begin_comment
comment|/* sub-states for Device Control String processing */
end_comment

begin_define
define|#
directive|define
name|DCS_INIT
value|0
end_define

begin_comment
comment|/* got ESC P ... */
end_comment

begin_define
define|#
directive|define
name|DCS_AND_UDK
value|1
end_define

begin_comment
comment|/* got ESC P ... | */
end_comment

begin_define
define|#
directive|define
name|DCS_UDK_DEF
value|2
end_define

begin_comment
comment|/* got ESC P ... | fnckey / */
end_comment

begin_define
define|#
directive|define
name|DCS_UDK_ESC
value|3
end_define

begin_comment
comment|/* got ESC P ... | fnckey / ... ESC */
end_comment

begin_define
define|#
directive|define
name|DCS_DLD_DSCS
value|4
end_define

begin_comment
comment|/* got ESC P ... { */
end_comment

begin_define
define|#
directive|define
name|DCS_DLD_DEF
value|5
end_define

begin_comment
comment|/* got ESC P ... { dscs */
end_comment

begin_define
define|#
directive|define
name|DCS_DLD_ESC
value|6
end_define

begin_comment
comment|/* got ESC P ... { dscs ... / ... ESC */
end_comment

begin_comment
comment|/* vt220 user defined keys and vt220 downloadable charset */
end_comment

begin_define
define|#
directive|define
name|MAXUDKDEF
value|300
end_define

begin_comment
comment|/* max 256 char + 1 '\0' + space.. */
end_comment

begin_define
define|#
directive|define
name|MAXUDKEYS
value|18
end_define

begin_comment
comment|/* plus holes .. */
end_comment

begin_define
define|#
directive|define
name|DSCS_LENGTH
value|3
end_define

begin_comment
comment|/* descriptor length */
end_comment

begin_define
define|#
directive|define
name|MAXSIXEL
value|8
end_define

begin_comment
comment|/* sixels forever ! */
end_comment

begin_comment
comment|/* sub-states for HP-terminal emulator */
end_comment

begin_define
define|#
directive|define
name|SHP_INIT
value|0
end_define

begin_comment
comment|/* esc& f family */
end_comment

begin_define
define|#
directive|define
name|SHP_AND_F
value|1
end_define

begin_define
define|#
directive|define
name|SHP_AND_Fa
value|2
end_define

begin_define
define|#
directive|define
name|SHP_AND_Fak
value|3
end_define

begin_define
define|#
directive|define
name|SHP_AND_Fak1
value|4
end_define

begin_define
define|#
directive|define
name|SHP_AND_Fakd
value|5
end_define

begin_define
define|#
directive|define
name|SHP_AND_FakdL
value|6
end_define

begin_define
define|#
directive|define
name|SHP_AND_FakdLl
value|7
end_define

begin_define
define|#
directive|define
name|SHP_AND_FakdLls
value|8
end_define

begin_comment
comment|/* esc& j family */
end_comment

begin_define
define|#
directive|define
name|SHP_AND_J
value|9
end_define

begin_define
define|#
directive|define
name|SHP_AND_JL
value|10
end_define

begin_comment
comment|/* esc& every-thing-else */
end_comment

begin_define
define|#
directive|define
name|SHP_AND_ETE
value|11
end_define

begin_comment
comment|/* additionals for function key labels */
end_comment

begin_define
define|#
directive|define
name|MAX_LABEL
value|16
end_define

begin_define
define|#
directive|define
name|MAX_STRING
value|80
end_define

begin_define
define|#
directive|define
name|MAX_STATUS
value|160
end_define

begin_comment
comment|/* MAX values for screen sizes for possible video adaptors */
end_comment

begin_define
define|#
directive|define
name|MAXROW_MDACGA
value|25
end_define

begin_comment
comment|/* MDA/CGA can do 25 x 80 max */
end_comment

begin_define
define|#
directive|define
name|MAXCOL_MDACGA
value|80
end_define

begin_define
define|#
directive|define
name|MAXROW_EGA
value|43
end_define

begin_comment
comment|/* EGA can do 43 x 80 max */
end_comment

begin_define
define|#
directive|define
name|MAXCOL_EGA
value|80
end_define

begin_define
define|#
directive|define
name|MAXROW_VGA
value|50
end_define

begin_comment
comment|/* VGA can do 50 x 80 max */
end_comment

begin_define
define|#
directive|define
name|MAXCOL_VGA
value|80
end_define

begin_define
define|#
directive|define
name|MAXCOL_SVGA
value|132
end_define

begin_comment
comment|/* Super VGA can do 50 x 132 max */
end_comment

begin_comment
comment|/* switch 80/132 columns */
end_comment

begin_define
define|#
directive|define
name|SCR_COL80
value|80
end_define

begin_comment
comment|/* in 80 col mode */
end_comment

begin_define
define|#
directive|define
name|SCR_COL132
value|132
end_define

begin_comment
comment|/* in 132 col mode */
end_comment

begin_define
define|#
directive|define
name|MAXDECSCA
value|(((MAXCOL_SVGA * MAXROW_VGA) \ 			/ (8 * sizeof(unsigned int)) ) + 1 )
end_define

begin_comment
comment|/* screen memory start, monochrome */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MONO_BUF
end_ifndef

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|&&
operator|(
name|PCVT_FREEBSD
operator|>
literal|102
operator|)
end_if

begin_define
define|#
directive|define
name|MONO_BUF
value|(KERNBASE+0xB0000)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MONO_BUF
value|0xfe0B0000
end_define

begin_comment
comment|/* NetBSD-current: isa.h */
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
comment|/* screen memory start, color */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGA_BUF
end_ifndef

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|&&
operator|(
name|PCVT_FREEBSD
operator|>
literal|102
operator|)
end_if

begin_define
define|#
directive|define
name|CGA_BUF
value|(KERNBASE+0xB8000)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CGA_BUF
value|0xfe0B8000
end_define

begin_comment
comment|/* NetBSD-current: isa.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHR
value|2
end_define

begin_comment
comment|/* bytes per word in screen mem */
end_comment

begin_define
define|#
directive|define
name|NVGAFONTS
value|8
end_define

begin_comment
comment|/* number of vga fonts loadable */
end_comment

begin_define
define|#
directive|define
name|MAXKEYNUM
value|127
end_define

begin_comment
comment|/* max no of keys in table */
end_comment

begin_comment
comment|/* charset tables */
end_comment

begin_define
define|#
directive|define
name|CSL
value|0x0000
end_define

begin_comment
comment|/* ega/vga charset, lower half of 512 */
end_comment

begin_define
define|#
directive|define
name|CSH
value|0x0800
end_define

begin_comment
comment|/* ega/vga charset, upper half of 512 */
end_comment

begin_define
define|#
directive|define
name|CSSIZE
value|96
end_define

begin_comment
comment|/* (physical) size of a character set */
end_comment

begin_comment
comment|/* charset designations */
end_comment

begin_define
define|#
directive|define
name|D_G0
value|0
end_define

begin_comment
comment|/* designated as G0 */
end_comment

begin_define
define|#
directive|define
name|D_G1
value|1
end_define

begin_comment
comment|/* designated as G1 */
end_comment

begin_define
define|#
directive|define
name|D_G2
value|2
end_define

begin_comment
comment|/* designated as G2 */
end_comment

begin_define
define|#
directive|define
name|D_G3
value|3
end_define

begin_comment
comment|/* designated as G3 */
end_comment

begin_define
define|#
directive|define
name|D_G1_96
value|4
end_define

begin_comment
comment|/* designated as G1 for 96-char charsets */
end_comment

begin_define
define|#
directive|define
name|D_G2_96
value|5
end_define

begin_comment
comment|/* designated as G2 for 96-char charsets */
end_comment

begin_define
define|#
directive|define
name|D_G3_96
value|6
end_define

begin_comment
comment|/* designated as G3 for 96-char charsets */
end_comment

begin_comment
comment|/* which fkey-labels */
end_comment

begin_define
define|#
directive|define
name|SYS_FKL
value|0
end_define

begin_comment
comment|/* in hp mode, sys-fkls are active */
end_comment

begin_define
define|#
directive|define
name|USR_FKL
value|1
end_define

begin_comment
comment|/* in hp mode, user-fkls are active */
end_comment

begin_comment
comment|/* arguments to async_update() */
end_comment

begin_define
define|#
directive|define
name|UPDATE_START
value|((void *)0)
end_define

begin_comment
comment|/* do cursor update and requeue */
end_comment

begin_define
define|#
directive|define
name|UPDATE_STOP
value|((void *)1)
end_define

begin_comment
comment|/* suspend cursor updates */
end_comment

begin_define
define|#
directive|define
name|UPDATE_KERN
value|((void *)2)
end_define

begin_comment
comment|/* do cursor updates for kernel output */
end_comment

begin_comment
comment|/* variables */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXTERN
end_ifdef

begin_define
define|#
directive|define
name|WAS_EXTERN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTERN
name|u_char
modifier|*
name|more_chars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* response buffer via kbd */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|char_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* response char count */
end_comment

begin_decl_stmt
name|EXTERN
name|u_char
name|color
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color or mono display */
end_comment

begin_decl_stmt
name|EXTERN
name|u_short
name|kern_attr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel messages char attributes */
end_comment

begin_decl_stmt
name|EXTERN
name|u_short
name|user_attr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character attributes */
end_comment

begin_if
if|#
directive|if
operator|!
name|PCVT_EMU_MOUSE
end_if

begin_if
if|#
directive|if
name|PCVT_NETBSD
end_if

begin_decl_stmt
name|EXTERN
name|struct
name|tty
modifier|*
name|pc_tty
index|[
name|PCVT_NSCREENS
index|]
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
operator|!
operator|(
name|PCVT_FREEBSD
operator|>
literal|110
operator|&&
name|PCVT_FREEBSD
operator|<
literal|200
operator|)
end_elif

begin_decl_stmt
name|EXTERN
name|struct
name|tty
name|pccons
index|[
name|PCVT_NSCREENS
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXTERN
name|struct
name|tty
modifier|*
name|pccons
index|[
name|PCVT_NSCREENS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_NETBSD */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCVT_EMU_MOUSE */
end_comment

begin_if
if|#
directive|if
name|PCVT_NETBSD
end_if

begin_decl_stmt
name|EXTERN
name|struct
name|tty
modifier|*
name|pc_tty
index|[
name|PCVT_NSCREENS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
operator|!
operator|(
name|PCVT_FREEBSD
operator|>
literal|110
operator|&&
name|PCVT_FREEBSD
operator|<
literal|200
operator|)
end_elif

begin_decl_stmt
name|EXTERN
name|struct
name|tty
name|pccons
index|[
name|PCVT_NSCREENS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXTERN
name|struct
name|tty
modifier|*
name|pccons
index|[
name|PCVT_NSCREENS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_EMU_MOUSE */
end_comment

begin_struct
struct|struct
name|sixels
block|{
name|u_char
name|lower
index|[
name|MAXSIXEL
index|]
decl_stmt|;
comment|/* lower half of char */
name|u_char
name|upper
index|[
name|MAXSIXEL
index|]
decl_stmt|;
comment|/* upper half of char */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|udkentry
block|{
name|u_char
name|first
index|[
name|MAXUDKEYS
index|]
decl_stmt|;
comment|/* index to first char */
name|u_char
name|length
index|[
name|MAXUDKEYS
index|]
decl_stmt|;
comment|/* length of this entry */
block|}
struct|;
end_struct

begin_comment
comment|/* VGA palette handling */
end_comment

begin_struct
struct|struct
name|rgb
block|{
name|u_char
name|r
decl_stmt|,
name|g
decl_stmt|,
name|b
decl_stmt|;
comment|/* red/green/blue, valid 0..VGA_PMSK */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|video_state
block|{
name|u_short
modifier|*
name|Crtat
decl_stmt|;
comment|/* video page start addr */
name|u_short
modifier|*
name|Memory
decl_stmt|;
comment|/* malloc'ed memory start address */
name|struct
name|tty
modifier|*
name|vs_tty
decl_stmt|;
comment|/* pointer to this screen's tty */
name|u_char
name|maxcol
decl_stmt|;
comment|/* 80 or 132 cols on screen */
name|u_char
name|row
decl_stmt|,
name|col
decl_stmt|;
comment|/* current cursor position */
name|u_short
name|c_attr
decl_stmt|;
comment|/* current character attributes */
name|u_char
name|vtsgr
decl_stmt|;
comment|/* current sgr configuration */
name|u_short
name|cur_offset
decl_stmt|;
comment|/* current cursor position offset */
name|u_char
name|bell_on
decl_stmt|;
comment|/* flag, bell enabled */
name|u_char
name|sevenbit
decl_stmt|;
comment|/* flag, data path 7 bits wide */
name|u_char
name|dis_fnc
decl_stmt|;
comment|/* flag, display functions enable */
name|u_char
name|transparent
decl_stmt|;
comment|/* flag, mk path tmp trnsprnt for ctls*/
name|u_char
name|scrr_beg
decl_stmt|;
comment|/* scrolling region, begin */
name|u_char
name|scrr_len
decl_stmt|;
comment|/* scrolling region, length */
name|u_char
name|scrr_end
decl_stmt|;
comment|/* scrolling region, end */
name|u_char
name|screen_rows
decl_stmt|;
comment|/* screen size, length - status lines */
name|u_char
name|screen_rowsize
decl_stmt|;
comment|/* screen size, length */
name|u_char
name|vga_charset
decl_stmt|;
comment|/* VGA character set value */
name|u_char
name|lastchar
decl_stmt|;
comment|/* flag, vt100 behaviour of last char */
name|u_char
name|lastrow
decl_stmt|;
comment|/* save row, --------- " -----------  */
name|u_char
modifier|*
name|report_chars
decl_stmt|;
comment|/* ptr, status reports from terminal */
name|u_char
name|report_count
decl_stmt|;
comment|/* count, ----------- " ------------ */
name|u_char
name|state
decl_stmt|;
comment|/* escape sequence state machine */
name|u_char
name|m_awm
decl_stmt|;
comment|/* flag, vt100 mode, auto wrap */
name|u_char
name|m_om
decl_stmt|;
comment|/* flag, vt100 mode, origin mode */
name|u_char
name|sc_flag
decl_stmt|;
comment|/* flag, vt100 mode,saved parms valid */
name|u_char
name|sc_row
decl_stmt|;
comment|/* saved row */
name|u_char
name|sc_col
decl_stmt|;
comment|/* saved col */
name|u_short
name|sc_cur_offset
decl_stmt|;
comment|/* saved cursor addr offset */
name|u_short
name|sc_attr
decl_stmt|;
comment|/* saved attributes */
name|u_char
name|sc_vtsgr
decl_stmt|;
comment|/* saved sgr configuration */
name|u_char
name|sc_awm
decl_stmt|;
comment|/* saved auto wrap mode */
name|u_char
name|sc_om
decl_stmt|;
comment|/* saved origin mode */
name|u_short
modifier|*
name|sc_G0
decl_stmt|;
comment|/* save G0 ptr */
name|u_short
modifier|*
name|sc_G1
decl_stmt|;
comment|/* save G1 ptr */
name|u_short
modifier|*
name|sc_G2
decl_stmt|;
comment|/* save G2 ptr */
name|u_short
modifier|*
name|sc_G3
decl_stmt|;
comment|/* save G3 ptr */
name|u_short
modifier|*
modifier|*
name|sc_GL
decl_stmt|;
comment|/* save GL ptr */
name|u_short
modifier|*
modifier|*
name|sc_GR
decl_stmt|;
comment|/* save GR ptr */
name|u_char
name|sc_sel
decl_stmt|;
comment|/* selective erase state */
name|u_char
name|ufkl
index|[
literal|8
index|]
index|[
literal|17
index|]
decl_stmt|;
comment|/* user fkey-labels */
name|u_char
name|sfkl
index|[
literal|8
index|]
index|[
literal|17
index|]
decl_stmt|;
comment|/* system fkey-labels */
name|u_char
name|labels_on
decl_stmt|;
comment|/* display fkey labels etc. on/off */
name|u_char
name|which_fkl
decl_stmt|;
comment|/* which fkey labels are active */
name|char
name|tab_stops
index|[
name|MAXTAB
index|]
decl_stmt|;
comment|/* table of active tab stops */
name|u_char
name|parmi
decl_stmt|;
comment|/* parameter index */
name|u_char
name|parms
index|[
name|MAXPARMS
index|]
decl_stmt|;
comment|/* parameter array */
name|u_char
name|hp_state
decl_stmt|;
comment|/* hp escape sequence state machine */
name|u_char
name|attribute
decl_stmt|;
comment|/* attribute normal, tx only, local */
name|u_char
name|key
decl_stmt|;
comment|/* fkey label no */
name|u_char
name|l_len
decl_stmt|;
comment|/* buffer length's */
name|u_char
name|s_len
decl_stmt|;
name|u_char
name|m_len
decl_stmt|;
name|u_char
name|i
decl_stmt|;
comment|/* help (got short of names ...) */
name|u_char
name|l_buf
index|[
name|MAX_LABEL
operator|+
literal|1
index|]
decl_stmt|;
comment|/* buffers */
name|u_char
name|s_buf
index|[
name|MAX_STRING
operator|+
literal|1
index|]
decl_stmt|;
name|u_char
name|m_buf
index|[
name|MAX_STATUS
operator|+
literal|1
index|]
decl_stmt|;
name|u_char
name|openf
decl_stmt|;
comment|/* we are opened ! */
name|u_char
name|vt_pure_mode
decl_stmt|;
comment|/* no fkey labels, row/col, status */
name|u_char
name|cursor_start
decl_stmt|;
comment|/* Start of cursor */
name|u_char
name|cursor_end
decl_stmt|;
comment|/* End of cursor */
name|u_char
name|cursor_on
decl_stmt|;
comment|/* cursor switched on */
name|u_char
name|ckm
decl_stmt|;
comment|/* true = cursor key normal mode */
name|u_char
name|irm
decl_stmt|;
comment|/* true = insert mode */
name|u_char
name|lnm
decl_stmt|;
comment|/* Line Feed/New Line Mode */
name|u_char
name|dcs_state
decl_stmt|;
comment|/* dcs escape sequence state machine */
name|u_char
name|udk_def
index|[
name|MAXUDKDEF
index|]
decl_stmt|;
comment|/* new definitions for vt220 FKeys */
name|u_char
name|udk_defi
decl_stmt|;
comment|/* index for FKey definitions */
name|u_char
name|udk_deflow
decl_stmt|;
comment|/* low or high nibble in sequence */
name|u_char
name|udk_fnckey
decl_stmt|;
comment|/* function key to assign to */
name|u_char
name|dld_dscs
index|[
name|DSCS_LENGTH
index|]
decl_stmt|;
comment|/* designate soft character set id */
name|u_char
name|dld_dscsi
decl_stmt|;
comment|/* index for dscs */
name|u_char
name|dld_sixel_lower
decl_stmt|;
comment|/* upper/lower sixels of character */
name|u_char
name|dld_sixelli
decl_stmt|;
comment|/* index for lower sixels */
name|u_char
name|dld_sixelui
decl_stmt|;
comment|/* index for upper sixels */
name|struct
name|sixels
name|sixel
decl_stmt|;
comment|/* structure for storing char sixels */
name|u_char
name|selchar
decl_stmt|;
comment|/* true = selective attribute on */
name|u_int
name|decsca
index|[
name|MAXDECSCA
index|]
decl_stmt|;
comment|/* Select Character Attrib bit array */
name|u_short
modifier|*
modifier|*
name|GL
decl_stmt|;
comment|/* ptr to current GL conversion table*/
name|u_short
modifier|*
modifier|*
name|GR
decl_stmt|;
comment|/* ptr to current GR conversion table*/
name|u_short
modifier|*
name|G0
decl_stmt|;
comment|/* ptr to current G0 conversion table*/
name|u_short
modifier|*
name|G1
decl_stmt|;
comment|/* ptr to current G1 conversion table*/
name|u_char
name|force24
decl_stmt|;
comment|/* force 24 lines in DEC 25 and HP 28*/
name|u_short
modifier|*
name|G2
decl_stmt|;
comment|/* ptr to current G2 conversion table*/
name|u_short
modifier|*
name|G3
decl_stmt|;
comment|/* ptr to current G3 conversion table*/
name|u_char
name|dld_id
index|[
name|DSCS_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
comment|/* soft character set id */
name|u_char
name|which
index|[
name|DSCS_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
comment|/* which set to designate */
name|u_char
name|whichi
decl_stmt|;
comment|/* index into which ..	*/
name|u_char
name|ss
decl_stmt|;
comment|/* flag, single shift G2 / G3 -> GL */
name|u_short
modifier|*
modifier|*
name|Gs
decl_stmt|;
comment|/* ptr to cur. G2/G3 conversion table*/
name|u_char
name|udkbuf
index|[
name|MAXUDKDEF
index|]
decl_stmt|;
comment|/* buffer for user defined keys */
name|struct
name|udkentry
name|ukt
decl_stmt|;
comment|/* index& length for each udk */
name|u_char
name|udkff
decl_stmt|;
comment|/* index into buffer first free entry*/
name|struct
name|rgb
name|palette
index|[
name|NVGAPEL
index|]
decl_stmt|;
comment|/* saved VGA DAC palette */
name|u_char
name|wd132col
decl_stmt|;
comment|/* we are on a wd vga and in 132 col */
name|u_char
name|scroll_lock
decl_stmt|;
comment|/* scroll lock active */
name|u_char
name|caps_lock
decl_stmt|;
comment|/* caps lock active */
name|u_char
name|shift_lock
decl_stmt|;
comment|/* shiftlock flag (virtual ..) */
name|u_char
name|num_lock
decl_stmt|;
comment|/* num lock, true = keypad num mode */
name|u_char
name|abs_write
decl_stmt|;
comment|/* write outside of scroll region */
if|#
directive|if
name|PCVT_USL_VT_COMPAT
comment|/* SysV compatibility :-( */
name|struct
name|vt_mode
name|smode
decl_stmt|;
name|struct
name|proc
modifier|*
name|proc
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
name|unsigned
name|vt_status
decl_stmt|;
define|#
directive|define
name|VT_WAIT_REL
value|1
comment|/* wait till process released vt */
define|#
directive|define
name|VT_WAIT_ACK
value|2
comment|/* wait till process ack vt acquire */
define|#
directive|define
name|VT_GRAFX
value|4
comment|/* vt runs graphics mode */
define|#
directive|define
name|VT_WAIT_ACT
value|8
comment|/* a process is sleeping on this vt */
comment|/*  becoming active */
endif|#
directive|endif
comment|/* PCVT_USL_VT_COMPAT */
block|}
name|video_state
typedef|;
end_typedef

begin_decl_stmt
name|EXTERN
name|video_state
name|vs
index|[
name|PCVT_NSCREENS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parameters for screens */
end_comment

begin_struct
struct|struct
name|vga_char_state
block|{
name|int
name|loaded
decl_stmt|;
comment|/* Whether a font is loaded here */
name|int
name|secondloaded
decl_stmt|;
comment|/* an extension characterset was loaded, */
comment|/*	the number is found here	 */
name|u_char
name|char_scanlines
decl_stmt|;
comment|/* Scanlines per character */
name|u_char
name|scr_scanlines
decl_stmt|;
comment|/* Low byte of scanlines per screen */
name|int
name|screen_size
decl_stmt|;
comment|/* Screen size in SIZ_YYROWS */
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|vga_char_state
name|vgacs
index|[
name|NVGAFONTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character set states */
end_comment

begin_if
if|#
directive|if
name|PCVT_EMU_MOUSE
end_if

begin_struct
struct|struct
name|mousestat
block|{
name|struct
name|timeval
name|lastmove
decl_stmt|;
comment|/* last time the pointer moved */
name|u_char
name|opened
decl_stmt|;
comment|/* someone would like to use a mouse */
name|u_char
name|minor
decl_stmt|;
comment|/* minor device number */
name|u_char
name|buttons
decl_stmt|;
comment|/* current "buttons" pressed */
name|u_char
name|extendedseen
decl_stmt|;
comment|/* 0xe0 has been seen, do not use next key */
name|u_char
name|breakseen
decl_stmt|;
comment|/* key break has been seen for a sticky btn */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_EMU_MOUSE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WAS_EXTERN
end_ifdef

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|>
literal|9
end_if

begin_function_decl
name|int
name|pcprobe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcattach
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|cfdriver
name|vtcd
init|=
block|{
name|NULL
block|,
literal|"vt"
block|,
name|pcprobe
block|,
name|pcattach
block|,
name|DV_TTY
block|,
expr|sizeof
operator|(
expr|struct
name|device
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|pcprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|isa_driver
name|vtdriver
init|=
block|{
comment|/* driver routines */
name|pcprobe
block|,
name|pcattach
block|,
literal|"vt"
block|,
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_NETBSD> 9 */
end_comment

begin_decl_stmt
name|u_char
name|fgansitopc
index|[]
init|=
block|{
comment|/* foreground ANSI color -> pc */
name|FG_BLACK
block|,
name|FG_RED
block|,
name|FG_GREEN
block|,
name|FG_BROWN
block|,
name|FG_BLUE
block|,
name|FG_MAGENTA
block|,
name|FG_CYAN
block|,
name|FG_LIGHTGREY
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|bgansitopc
index|[]
init|=
block|{
comment|/* background ANSI color -> pc */
name|BG_BLACK
block|,
name|BG_RED
block|,
name|BG_GREEN
block|,
name|BG_BROWN
block|,
name|BG_BLUE
block|,
name|BG_MAGENTA
block|,
name|BG_CYAN
block|,
name|BG_LIGHTGREY
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|PCVT_NETBSD
end_if

begin_comment
comment|/* XXX Crtat is shared with syscons. */
end_comment

begin_decl_stmt
name|u_short
modifier|*
name|Crtat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* screen start address */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|PCVT_FREEBSD
operator|>
literal|110
operator|&&
name|PCVT_FREEBSD
operator|<
literal|200
operator|)
end_if

begin_decl_stmt
name|struct
name|tty
modifier|*
name|pcconsp
init|=
operator|&
name|pccons
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to current device */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCVT_FREEBSD> 110 */
end_comment

begin_decl_stmt
name|struct
name|tty
modifier|*
name|pcconsp
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(PCVT_FREEBSD> 110) */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|tty
modifier|*
name|pcconsp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to current device, see pcattach() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_NETBSD */
end_comment

begin_if
if|#
directive|if
name|PCVT_EMU_MOUSE
end_if

begin_decl_stmt
name|struct
name|mousestat
name|mouse
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mousedefs
name|mousedef
init|=
block|{
literal|0x3b
block|,
literal|0x3c
block|,
literal|0x3d
block|,
literal|0
block|,
literal|250000
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_EMU_MOUSE */
end_comment

begin_comment
comment|/*  F1,   F2,   F3,   false, 0.25 sec */
end_comment

begin_decl_stmt
name|video_state
modifier|*
name|vsp
init|=
operator|&
name|vs
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to current screen parms */
end_comment

begin_if
if|#
directive|if
name|PCVT_USL_VT_COMPAT
end_if

begin_decl_stmt
name|int
name|vt_switch_pending
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if> 0, a vt switch is */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_USL_VT_COMPAT */
end_comment

begin_comment
comment|/* pending; contains the # */
end_comment

begin_comment
comment|/* of the old vt + 1 */
end_comment

begin_decl_stmt
name|u_int
name|addr_6845
init|=
name|MONO_BASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* crtc base addr */
end_comment

begin_decl_stmt
name|u_char
name|do_initialization
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we have to init ourselves */
end_comment

begin_decl_stmt
name|u_char
name|pcvt_is_console
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* until we know it */
end_comment

begin_decl_stmt
name|u_char
name|shift_down
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shift key down flag */
end_comment

begin_decl_stmt
name|u_char
name|ctrl_down
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ctrl key down flag */
end_comment

begin_decl_stmt
name|u_char
name|meta_down
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* alt key down flag */
end_comment

begin_decl_stmt
name|u_char
name|altgr_down
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* altgr key down flag */
end_comment

begin_decl_stmt
name|u_char
name|kbrepflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key repeat flag */
end_comment

begin_decl_stmt
name|u_char
name|totalscreens
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* screens available */
end_comment

begin_decl_stmt
name|u_char
name|current_video_screen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* displayed screen no */
end_comment

begin_decl_stmt
name|u_char
name|adaptor_type
init|=
name|UNKNOWN_ADAPTOR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* adaptor type */
end_comment

begin_decl_stmt
name|u_char
name|vga_type
init|=
name|VGA_UNKNOWN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vga chipset */
end_comment

begin_decl_stmt
name|u_char
name|can_do_132col
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vga chipset can 132 cols */
end_comment

begin_decl_stmt
name|u_char
name|vga_family
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vga manufacturer */
end_comment

begin_decl_stmt
name|u_char
name|totalfonts
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fonts available */
end_comment

begin_decl_stmt
name|u_char
name|chargen_access
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* synchronize access */
end_comment

begin_decl_stmt
name|u_char
name|keyboard_type
init|=
name|KB_UNKNOWN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of keyboard */
end_comment

begin_decl_stmt
name|u_char
name|keyboard_is_initialized
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for ddb sanity */
end_comment

begin_decl_stmt
name|u_char
name|kbd_polling
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyboard is being polled */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_I386_ISA_KBDIO_H_
end_ifdef

begin_decl_stmt
name|u_char
name|reset_keyboard
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* OK to reset keyboard */
end_comment

begin_decl_stmt
name|KBDC
name|kbdc
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyboard controller */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_ISA_KBDIO_H_ */
end_comment

begin_if
if|#
directive|if
name|PCVT_SHOWKEYS
end_if

begin_decl_stmt
name|u_char
name|keyboard_show
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* normal display */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_SHOWKEYS */
end_comment

begin_decl_stmt
name|u_char
name|cursor_pos_valid
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sput left a valid position*/
end_comment

begin_decl_stmt
name|u_char
name|critical_scroll
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inside scrolling up */
end_comment

begin_decl_stmt
name|int
name|switch_page
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which page to switch to */
end_comment

begin_if
if|#
directive|if
name|PCVT_SCREENSAVER
end_if

begin_decl_stmt
name|u_char
name|reset_screen_saver
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reset the saver next time */
end_comment

begin_decl_stmt
name|u_char
name|scrnsv_active
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active flag */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_SCREENSAVER */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XSERVER
end_ifdef

begin_decl_stmt
name|unsigned
name|scrnsv_timeout
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initially off */
end_comment

begin_if
if|#
directive|if
operator|!
name|PCVT_USL_VT_COMPAT
end_if

begin_decl_stmt
name|u_char
name|pcvt_xmode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display is grafx */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_USL_VT_COMPAT */
end_comment

begin_decl_stmt
name|u_char
name|pcvt_kbd_raw
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyboard sends scans */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XSERVER */
end_comment

begin_if
if|#
directive|if
name|PCVT_BACKUP_FONTS
end_if

begin_decl_stmt
name|u_char
modifier|*
name|saved_charsets
index|[
name|NVGAFONTS
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* backup copy of fonts */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_BACKUP_FONTS */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  	VT220 attributes -> internal emulator attributes conversion tables  	be careful when designing color combinations, because on 	EGA and VGA displays, bit 3 of the attribute byte is used 	for characterset switching, and is no longer available for 	foreground intensity (bold)!  ---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* color displays */
end_comment

begin_decl_stmt
name|u_char
name|sgr_tab_color
index|[
literal|16
index|]
init|=
block|{
comment|/*00*/
operator|(
name|BG_BLACK
operator||
name|FG_LIGHTGREY
operator|)
block|,
comment|/* normal               */
comment|/*01*/
operator|(
name|BG_BLUE
operator||
name|FG_LIGHTGREY
operator|)
block|,
comment|/* bold                 */
comment|/*02*/
operator|(
name|BG_BROWN
operator||
name|FG_LIGHTGREY
operator|)
block|,
comment|/* underline            */
comment|/*03*/
operator|(
name|BG_MAGENTA
operator||
name|FG_LIGHTGREY
operator|)
block|,
comment|/* bold+underline       */
comment|/*04*/
operator|(
name|BG_BLACK
operator||
name|FG_LIGHTGREY
operator||
name|FG_BLINK
operator|)
block|,
comment|/* blink                */
comment|/*05*/
operator|(
name|BG_BLUE
operator||
name|FG_LIGHTGREY
operator||
name|FG_BLINK
operator|)
block|,
comment|/* bold+blink           */
comment|/*06*/
operator|(
name|BG_BROWN
operator||
name|FG_LIGHTGREY
operator||
name|FG_BLINK
operator|)
block|,
comment|/* underline+blink      */
comment|/*07*/
operator|(
name|BG_MAGENTA
operator||
name|FG_LIGHTGREY
operator||
name|FG_BLINK
operator|)
block|,
comment|/* bold+underline+blink */
comment|/*08*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator|)
block|,
comment|/* invers               */
comment|/*09*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLUE
operator|)
block|,
comment|/* bold+invers          */
comment|/*10*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BROWN
operator|)
block|,
comment|/* underline+invers     */
comment|/*11*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_MAGENTA
operator|)
block|,
comment|/* bold+underline+invers*/
comment|/*12*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator|)
block|,
comment|/* blink+invers         */
comment|/*13*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLUE
operator||
name|FG_BLINK
operator|)
block|,
comment|/* bold+blink+invers    */
comment|/*14*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BROWN
operator||
name|FG_BLINK
operator|)
block|,
comment|/* underline+blink+invers*/
comment|/*15*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_MAGENTA
operator||
name|FG_BLINK
operator|)
comment|/*bold+underl+blink+invers*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* monochrome displays (VGA version, no intensity) */
end_comment

begin_decl_stmt
name|u_char
name|sgr_tab_mono
index|[
literal|16
index|]
init|=
block|{
comment|/*00*/
operator|(
name|BG_BLACK
operator||
name|FG_LIGHTGREY
operator|)
block|,
comment|/* normal               */
comment|/*01*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator|)
block|,
comment|/* bold                 */
comment|/*02*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator|)
block|,
comment|/* underline            */
comment|/*03*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator|)
block|,
comment|/* bold+underline       */
comment|/*04*/
operator|(
name|BG_BLACK
operator||
name|FG_LIGHTGREY
operator||
name|FG_BLINK
operator|)
block|,
comment|/* blink                */
comment|/*05*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator||
name|FG_BLINK
operator|)
block|,
comment|/* bold+blink           */
comment|/*06*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator||
name|FG_BLINK
operator|)
block|,
comment|/* underline+blink      */
comment|/*07*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator||
name|FG_BLINK
operator|)
block|,
comment|/* bold+underline+blink */
comment|/*08*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator|)
block|,
comment|/* invers               */
comment|/*09*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator|)
block|,
comment|/* bold+invers          */
comment|/*10*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator|)
block|,
comment|/* underline+invers     */
comment|/*11*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator|)
block|,
comment|/* bold+underline+invers*/
comment|/*12*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator|)
block|,
comment|/* blink+invers         */
comment|/*13*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator|)
block|,
comment|/* bold+blink+invers    */
comment|/*14*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator|)
block|,
comment|/* underline+blink+invers*/
comment|/*15*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator|)
comment|/*bold+underl+blink+invers*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* monochrome displays (MDA version, with intensity) */
end_comment

begin_decl_stmt
name|u_char
name|sgr_tab_imono
index|[
literal|16
index|]
init|=
block|{
comment|/*00*/
operator|(
name|BG_BLACK
operator||
name|FG_LIGHTGREY
operator|)
block|,
comment|/* normal               */
comment|/*01*/
operator|(
name|BG_BLACK
operator||
name|FG_LIGHTGREY
operator||
name|FG_INTENSE
operator|)
block|,
comment|/* bold                 */
comment|/*02*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator|)
block|,
comment|/* underline            */
comment|/*03*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator||
name|FG_INTENSE
operator|)
block|,
comment|/* bold+underline       */
comment|/*04*/
operator|(
name|BG_BLACK
operator||
name|FG_LIGHTGREY
operator||
name|FG_BLINK
operator|)
block|,
comment|/* blink                */
comment|/*05*/
operator|(
name|BG_BLACK
operator||
name|FG_LIGHTGREY
operator||
name|FG_INTENSE
operator||
name|FG_BLINK
operator|)
block|,
comment|/* bold+blink  */
comment|/*06*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator||
name|FG_BLINK
operator|)
block|,
comment|/* underline+blink      */
comment|/*07*/
operator|(
name|BG_BLACK
operator||
name|FG_UNDERLINE
operator||
name|FG_BLINK
operator||
name|FG_INTENSE
operator|)
block|,
comment|/* bold+underline+blink */
comment|/*08*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator|)
block|,
comment|/* invers               */
comment|/*09*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_INTENSE
operator|)
block|,
comment|/* bold+invers          */
comment|/*10*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator|)
block|,
comment|/* underline+invers     */
comment|/*11*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_INTENSE
operator|)
block|,
comment|/* bold+underline+invers*/
comment|/*12*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator|)
block|,
comment|/* blink+invers         */
comment|/*13*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator||
name|FG_INTENSE
operator|)
block|,
comment|/* bold+blink+invers*/
comment|/*14*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator|)
block|,
comment|/* underline+blink+invers*/
comment|/*15*/
operator|(
name|BG_LIGHTGREY
operator||
name|FG_BLACK
operator||
name|FG_BLINK
operator||
name|FG_INTENSE
operator|)
comment|/* bold+underl+blink+invers */
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WAS_EXTERN */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|vga_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|pcconsp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|video_state
modifier|*
name|vsp
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|PCVT_EMU_MOUSE
end_if

begin_decl_stmt
specifier|extern
name|struct
name|mousestat
name|mouse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mousedefs
name|mousedef
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_EMU_MOUSE */
end_comment

begin_if
if|#
directive|if
name|PCVT_USL_VT_COMPAT
end_if

begin_decl_stmt
specifier|extern
name|int
name|vt_switch_pending
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_USL_VT_COMPAT */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|addr_6845
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|Crtat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|do_initialization
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|pcvt_is_console
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|bgansitopc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|fgansitopc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|shift_down
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ctrl_down
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|meta_down
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|altgr_down
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|kbrepflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|adaptor_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|current_video_screen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|totalfonts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|totalscreens
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|chargen_access
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|keyboard_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|can_do_132col
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|vga_family
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|keyboard_is_initialized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|kbd_polling
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_I386_ISA_KBDIO_H_
end_ifdef

begin_decl_stmt
specifier|extern
name|u_char
name|reset_keyboard
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KBDC
name|kbdc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_ISA_KBDIO_H_ */
end_comment

begin_if
if|#
directive|if
name|PCVT_SHOWKEYS
end_if

begin_decl_stmt
specifier|extern
name|u_char
name|keyboard_show
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_SHOWKEYS */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|cursor_pos_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|critical_scroll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|switch_page
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|PCVT_SCREENSAVER
end_if

begin_decl_stmt
specifier|extern
name|u_char
name|reset_screen_saver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|scrnsv_active
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_SCREENSAVER */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|sgr_tab_color
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|sgr_tab_mono
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|sgr_tab_imono
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|XSERVER
end_ifdef

begin_decl_stmt
specifier|extern
name|unsigned
name|scrnsv_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|pcvt_xmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|pcvt_kbd_raw
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XSERVER */
end_comment

begin_if
if|#
directive|if
name|PCVT_BACKUP_FONTS
end_if

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|saved_charsets
index|[
name|NVGAFONTS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_BACKUP_FONTS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WAS_EXTERN */
end_comment

begin_comment
comment|/*  * FreeBSD> 1.0.2 cleaned up the kernel definitions (with the aim of  * getting ANSI-clean). Since there has been a mixed usage of types like  * "dev_t" (actually some short) in prototyped and non-prototyped fasion,  * each of those types is declared as "int" within function prototypes  * (which is what the compiler would actually promote it to).  *  * The macros below are used to clarify which type a parameter ought to  * be, regardless of its actual promotion to "int".  */
end_comment

begin_define
define|#
directive|define
name|Dev_t
value|int
end_define

begin_define
define|#
directive|define
name|U_short
value|int
end_define

begin_define
define|#
directive|define
name|U_char
value|int
end_define

begin_comment
comment|/*  * In FreeBSD>= 2.0, dev_t has type `unsigned long', so promoting it  * doesn't cause any problems in prototypes.  */
end_comment

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|>=
literal|200
end_if

begin_undef
undef|#
directive|undef
name|Dev_t
end_undef

begin_define
define|#
directive|define
name|Dev_t
value|dev_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|PCVT_FREEBSD
operator|||
operator|(
name|PCVT_FREEBSD
operator|<
literal|210
operator|)
end_if

begin_function_decl
specifier|extern
name|void
name|bcopyb
parameter_list|(
name|void
modifier|*
name|from
parameter_list|,
name|void
modifier|*
name|to
parameter_list|,
name|u_int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|PCVT_FREEBSD
operator|||
operator|(
name|PCVT_FREEBSD
operator|<
literal|200
operator|)
end_if

begin_function_decl
specifier|extern
name|void
name|fillw
parameter_list|(
name|U_short
name|value
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|u_int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pcparam
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|termios
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * In FreeBSD> 2.0.6, driver console functions are declared in machine/cons.h  * and some return void, so don't declare them here.  */
end_comment

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|<=
literal|205
end_if

begin_function_decl
name|int
name|pccnprobe
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccninit
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccngetc
parameter_list|(
name|Dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccncheckc
parameter_list|(
name|Dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccnputc
parameter_list|(
name|Dev_t
name|dev
parameter_list|,
name|U_char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|pcstart
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcstop
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|PCVT_FREEBSD
operator|<
literal|200
end_if

begin_function_decl
name|void
name|consinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|PCVT_USL_VT_COMPAT
end_if

begin_function_decl
name|void
name|switch_screen
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|oldgrafx
parameter_list|,
name|int
name|newgrafx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usl_vt_ioctl
parameter_list|(
name|Dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vt_activate
parameter_list|(
name|int
name|newscreen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vgapage
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_usl_keymap
parameter_list|(
name|keymap_t
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_usl_modes
parameter_list|(
name|struct
name|video_state
modifier|*
name|vsx
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|vgapage
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_USL_VT_COMPAT */
end_comment

begin_if
if|#
directive|if
name|PCVT_EMU_MOUSE
end_if

begin_function_decl
name|int
name|mouse_ioctl
parameter_list|(
name|Dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  PCVT_EMU_MOUSE */
end_comment

begin_if
if|#
directive|if
name|PCVT_SCREENSAVER
end_if

begin_function_decl
name|void
name|pcvt_scrnsv_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_SCREENSAVER */
end_comment

begin_if
if|#
directive|if
name|PCVT_SCREENSAVER
operator|&&
name|defined
argument_list|(
name|XSERVER
argument_list|)
end_if

begin_function_decl
name|void
name|pcvt_set_scrnsv_tmo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_SCREENSAVER&& defined(XSERVER) */
end_comment

begin_function_decl
name|void
name|vga_move_charset
parameter_list|(
name|unsigned
name|n
parameter_list|,
name|unsigned
name|char
modifier|*
name|b
parameter_list|,
name|int
name|save_it
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|async_update
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clr_parms
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cons_highlight
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cons_normal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dprintf
parameter_list|(
name|unsigned
name|flgs
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|egavga_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fkl_off
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fkl_on
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tty
modifier|*
name|get_pccons
parameter_list|(
name|Dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_sfkl
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_ufkl
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_KBDIO_H_
end_ifndef

begin_function_decl
name|int
name|kbd_cmd
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbd_response
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_ISA_KBDIO_H_ */
end_comment

begin_function_decl
name|void
name|kbd_code_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kbd_code_init1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|PCVT_SCANSET
operator|>
literal|1
end_if

begin_function_decl
name|void
name|kbd_emulate_pc
parameter_list|(
name|int
name|do_emulation
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|kbdioctl
parameter_list|(
name|Dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|loadchar
parameter_list|(
name|int
name|fontset
parameter_list|,
name|int
name|character
parameter_list|,
name|int
name|char_scanlines
parameter_list|,
name|u_char
modifier|*
name|char_table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mda2egaorvga
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|roll_up
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|select_vga_charset
parameter_list|(
name|int
name|vga_charset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_2ndcharset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_charset
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|,
name|int
name|curvgacs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_emulation_mode
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_screen_size
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
modifier|*
name|sgetc
parameter_list|(
name|int
name|noblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sixel_vga
parameter_list|(
name|struct
name|sixels
modifier|*
name|charsixel
parameter_list|,
name|u_char
modifier|*
name|charvga
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sput
parameter_list|(
name|u_char
modifier|*
name|s
parameter_list|,
name|U_char
name|attrib
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sw_cursor
parameter_list|(
name|int
name|onoff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sw_sfkl
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sw_ufkl
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swritefkl
parameter_list|(
name|int
name|num
parameter_list|,
name|u_char
modifier|*
name|string
parameter_list|,
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|toggl_awm
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|toggl_bell
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|toggl_columns
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|toggl_dspf
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|toggl_sevenbit
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_hp
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_led
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vga10_vga10
parameter_list|(
name|u_char
modifier|*
name|invga
parameter_list|,
name|u_char
modifier|*
name|outvga
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vga10_vga14
parameter_list|(
name|u_char
modifier|*
name|invga
parameter_list|,
name|u_char
modifier|*
name|outvga
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vga10_vga16
parameter_list|(
name|u_char
modifier|*
name|invga
parameter_list|,
name|u_char
modifier|*
name|outvga
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vga10_vga8
parameter_list|(
name|u_char
modifier|*
name|invga
parameter_list|,
name|u_char
modifier|*
name|outvga
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
name|vga_chipset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vga_col
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|,
name|int
name|cols
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vga_screen_off
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vga_screen_on
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vga_string
parameter_list|(
name|int
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vga_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vgaioctl
parameter_list|(
name|Dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vgapaletteio
parameter_list|(
name|unsigned
name|idx
parameter_list|,
name|struct
name|rgb
modifier|*
name|val
parameter_list|,
name|int
name|writeit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_aln
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_clearudk
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_clreol
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_clreos
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_clrtab
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vt_col
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|,
name|int
name|cols
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_coldmalloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_cub
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_cud
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_cuf
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_curadr
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_cuu
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_da
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_dch
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_dcsentry
parameter_list|(
name|U_char
name|ch
parameter_list|,
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_designate
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_dl
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_dld
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_dsr
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_ech
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_ic
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_il
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_ind
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_initsel
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_keyappl
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_keynum
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_mc
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_nel
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_rc
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_reqtparm
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_reset_ansi
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_reset_dec_priv_qm
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_ri
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_ris
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_sc
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_sca
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_sd
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_sed
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_sel
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_set_ansi
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_set_dec_priv_qm
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_sgr
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_stbm
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_str
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_su
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_tst
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_udk
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|toggl_24l
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PCVT_INCLUDE_VT_SELATTR
end_ifdef

begin_define
define|#
directive|define
name|INT_BITS
value|(sizeof(unsigned int) * 8)
end_define

begin_define
define|#
directive|define
name|INT_INDEX
parameter_list|(
name|n
parameter_list|)
value|((n) / INT_BITS)
end_define

begin_define
define|#
directive|define
name|BIT_INDEX
parameter_list|(
name|n
parameter_list|)
value|((n) % INT_BITS)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	set selective attribute if appropriate  *---------------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
name|__inline
name|void
name|vt_selattr
parameter_list|(
name|struct
name|video_state
modifier|*
name|svsp
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
operator|(
name|svsp
operator|->
name|Crtat
operator|+
name|svsp
operator|->
name|cur_offset
operator|)
operator|-
name|svsp
operator|->
name|Crtat
expr_stmt|;
if|if
condition|(
name|svsp
operator|->
name|selchar
condition|)
name|svsp
operator|->
name|decsca
index|[
name|INT_INDEX
argument_list|(
name|i
argument_list|)
index|]
operator||=
operator|(
literal|1
operator|<<
name|BIT_INDEX
argument_list|(
name|i
argument_list|)
operator|)
expr_stmt|;
else|else
name|svsp
operator|->
name|decsca
index|[
name|INT_INDEX
argument_list|(
name|i
argument_list|)
index|]
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|BIT_INDEX
argument_list|(
name|i
argument_list|)
operator|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCVT_INCLUDE_VT_SELATTR */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	produce 7 us delay accessing the keyboard controller  *---------------------------------------------------------------------------*/
end_comment

begin_if
if|#
directive|if
name|PCVT_PORTIO_DELAY
end_if

begin_comment
comment|/* use multiple dummy accesses to port    */
end_comment

begin_comment
comment|/* 0x84 to produce keyboard controller    */
end_comment

begin_comment
comment|/* access delays                          */
end_comment

begin_define
define|#
directive|define
name|PCVT_KBD_DELAY
parameter_list|()
define|\
value|{ (void)inb(0x84); } \ 	{ (void)inb(0x84); } \ 	{ (void)inb(0x84); } \ 	{ (void)inb(0x84); } \ 	{ (void)inb(0x84); } \ 	{ (void)inb(0x84); }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCVT_PORTIO_DELAY */
end_comment

begin_comment
comment|/* use system supplied delay function for */
end_comment

begin_comment
comment|/* producing delays for accesssing the    */
end_comment

begin_comment
comment|/* keyboard controller                    */
end_comment

begin_if
if|#
directive|if
name|PCVT_NETBSD
operator|>
literal|9
end_if

begin_define
define|#
directive|define
name|PCVT_KBD_DELAY
parameter_list|()
value|delay(7)
end_define

begin_elif
elif|#
directive|elif
name|PCVT_FREEBSD
operator|||
operator|(
name|PCVT_NETBSD
operator|<=
literal|9
operator|)
end_elif

begin_define
define|#
directive|define
name|PCVT_KBD_DELAY
parameter_list|()
value|DELAY(7)
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
comment|/* PCVT_PORTIO_DELAY */
end_comment

begin_comment
comment|/*---------------------------------- E O F ----------------------------------*/
end_comment

end_unit

