begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      Copyright 1992,1993 by Holger Veit  *	May be freely used with Bill Jolitz's port of   *	386bsd and may be included in a 386bsd collection  *	as long as binary and source are available and reproduce the above  *	copyright.  *  *	You may freely modify this code and contribute improvements based  *	on this code as long as you don't claim to be the original author.  *	Commercial use of this source requires permittance of the copyright   *	holder. A general license for 386bsd will override this restriction.  *  *	Use at your own risk. The copyright holder or any person who makes  *	this code available for the public (administrators of public archives  *	for instance) are not responsible for any harm to hardware or software  *	that might happen due to wrong application or program faults.  *  * Addendum: The XFree86 developers and maintainers are hereby granted the   * right to distribute this file together with their source distributions  * and patchkits of XFree86 without further explicit permission of the  * above copyright holder.   * This and another file is a necessary include file for the unified   * pccons/codrv implementation of XFree86. This file is needed if  * someone wants to compile an Xserver on a system which does not have,   * for some reasons, the codrv console driver which comes with this file. The  * availability of this file avoids a large number of #ifdef's and  * allows to make the xserver code easier runtime-configurable.  * To make use of this file, it must be installed in /usr/include/sys.  * This file is not the complete console device driver, so it is possible  * that properties described in this file do not work without having the  * complete driver distribution. This is not a fault of the Xserver that  * was built with this file.  *  *  *  *	From: @(#)$RCSfile: ioctl_pc.h,v  *	Revision: 1.1.1.1  (Contributed to 386bsd)  *	Date: 1993/06/12 14:58:11  *  *	Important notice: #defined values are subject to be changed!!!  *	Don't use the constant, use the name instead!  *  *	codrv1-style uses ioctls	'K': 1-33,255  *					'V': 100-109  *  *	-hv-	Holger Veit, Holger.Veit@gmd.de  *	-hm	Hellmuth Michaelis, hm@hcshh.hcs.de  *      -vak-   Sergey Vakulenko, vak@kiae.su  *  *	25-07-92	-hv-	First version  *	16-08-92	-hm	adding vga ioctl for cursor shape  *      25-10-92	-hv-	X11 + video related ioctls  *      01/12/92        -vak-   8x16 font loading, beep ioctl,  *                              LED reassignment ioctl.  *	22-04-93	-hv-	unified most CODRV1/CODRV2 codes  *	24-04-93	-hv-	revised parts of keymap structures  *  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_PC_H_
end_ifndef

begin_define
define|#
directive|define
name|_IOCTL_PC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NOTDEF
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/***************************************************************************  *   Basic definitions  ***************************************************************************/
end_comment

begin_comment
comment|/* Use this data type when manipulating characters, don't use 'char' or 'u_char'  * some day this will be changed to 'u_short' or 'u_long' size to allow  * characters> 255  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|XCHAR
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************  *   driver identification  ***************************************************************************/
end_comment

begin_comment
comment|/*  * This defines the CONSOLE INFORMATION data structure, used to  * describe console capabilities, to distinguish between different  * versions. If this ioctl fail, you probably have an old style "pccons"   * driver (or an "improved" console driver, whose writer is not interested  * in providing compatibility for anything).  * In this case, a considerable number of features may not work as expected,  * or do not work at all.  */
end_comment

begin_define
define|#
directive|define
name|MAXINFOSIZE
value|16
end_define

begin_struct
struct|struct
name|consinfo
block|{
name|u_long
name|info1
decl_stmt|;
name|u_long
name|__reserved1__
decl_stmt|;
name|u_long
name|__reserved2__
decl_stmt|;
name|u_long
name|__reserved3__
decl_stmt|;
name|XCHAR
name|drv_name
index|[
name|MAXINFOSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|emul_name
index|[
name|MAXINFOSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|__reserved1_name__
index|[
name|MAXINFOSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|__reserved2_name__
index|[
name|MAXINFOSIZE
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|oldconsinfo
block|{
name|u_long
name|info1
decl_stmt|;
name|u_long
name|__reserved__
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CONSGINFO
value|_IOR('K',255,struct consinfo)
end_define

begin_comment
comment|/* Get console capabilities */
end_comment

begin_define
define|#
directive|define
name|OLDCONSGINFO
value|_IOR('K',255,struct oldconsinfo)
end_define

begin_comment
comment|/* compatibility */
end_comment

begin_define
define|#
directive|define
name|CONS_ISPC
value|0x00000001
end_define

begin_comment
comment|/* is derived from old PCCONS */
end_comment

begin_define
define|#
directive|define
name|CONS_ISCO
value|0x00000002
end_define

begin_comment
comment|/* is derived from CO driver */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved1
value|0x00000004
end_define

begin_comment
comment|/* reserved for other console drivers */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved2
value|0x00000008
end_define

begin_comment
comment|/* reserved for other console drivers */
end_comment

begin_define
define|#
directive|define
name|CONS_HASKBD
value|0x00000010
end_define

begin_comment
comment|/* has /dev/kbd */
end_comment

begin_define
define|#
directive|define
name|CONS_HASSCAN
value|0x00000020
end_define

begin_comment
comment|/* uses Scan codes */
end_comment

begin_define
define|#
directive|define
name|CONS_HASKEYNUM
value|0x00000040
end_define

begin_comment
comment|/* uses KEYNUMS */
end_comment

begin_define
define|#
directive|define
name|CONS_HASVTY
value|0x00000080
end_define

begin_comment
comment|/* has /dev/vty* */
end_comment

begin_define
define|#
directive|define
name|CONS_HASPC3
value|0x00000100
end_define

begin_comment
comment|/* unused, historical */
end_comment

begin_define
define|#
directive|define
name|CONS_HASVTHP
value|0x00000200
end_define

begin_comment
comment|/* unused, historical */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved3
value|0x00000400
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved4
value|0x00000800
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_HASPX386
value|0x00001000
end_define

begin_comment
comment|/* has X386 probing support +new CONSOLE_X_MODE */
end_comment

begin_define
define|#
directive|define
name|CONS_HASOX386
value|0x00002000
end_define

begin_comment
comment|/* has old X386 support CONSOLE_X_MODE_ON/OFF */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved5
value|0x00004000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved6
value|0x00008000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_HASKCAP
value|0x00010000
end_define

begin_comment
comment|/* has ioctl keycap support */
end_comment

begin_define
define|#
directive|define
name|CONS_HASFNT
value|0x00020000
end_define

begin_comment
comment|/* has ioctl font support */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved7
value|0x00040000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved8
value|0x00080000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_USE7BIT
value|0x00100000
end_define

begin_comment
comment|/* does not support 8bit characters */
end_comment

begin_define
define|#
directive|define
name|CONS_USEPC8
value|0x00200000
end_define

begin_comment
comment|/* uses PC8 8-bit mapping */
end_comment

begin_define
define|#
directive|define
name|CONS_USELATIN1
value|0x00400000
end_define

begin_comment
comment|/* uses ISO LATIN1 mapping */
end_comment

begin_define
define|#
directive|define
name|CONS_HAS10646
value|0x00800000
end_define

begin_comment
comment|/* has /dev/unicode */
end_comment

begin_define
define|#
directive|define
name|CONS_PCCONS2
value|0x01000000
end_define

begin_comment
comment|/* modified pccons */
end_comment

begin_define
define|#
directive|define
name|CONS_CODRV1
value|0x02000000
end_define

begin_comment
comment|/* old codrv ioctls */
end_comment

begin_define
define|#
directive|define
name|CONS_CODRV2
value|0x04000000
end_define

begin_comment
comment|/* codrv ioctls 0.1.2 */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved9
value|0x08000000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved10
value|0x10000000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved11
value|0x20000000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved12
value|0x40000000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|CONS_reserved13
value|0x80000000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_escape
end_escape

begin_comment
comment|/***************************************************************************  *   IOCTLs for AT Keyboard  ***************************************************************************/
end_comment

begin_comment
comment|/**** initializing the keyboard ****/
end_comment

begin_comment
comment|/* reset keyboard, run selftests and set default values:  * default keymap, no overloaded keys, default typematic rate  * KBD_TPD500|KBD_TPM100, repetition on  */
end_comment

begin_define
define|#
directive|define
name|KBDCOLDRESET
value|_IO('K',  1)
end_define

begin_comment
comment|/* reset keyboard and set default 					 * values: 					 * default keymap, no overloaded 					 * keys, default typematic rate 					 * KBD_TPD500|KBD_TPM100 					 */
end_comment

begin_comment
comment|/* resets the mode in keyboard controller only */
end_comment

begin_define
define|#
directive|define
name|KBDWARMRESET
value|_IO('K', 23)
end_define

begin_comment
comment|/**** key repetition (typematic) feature ****/
end_comment

begin_comment
comment|/* get (G) / set (S) key repetition rate and delay  * see below for a definition of rate and delay and the necessary  * argument  */
end_comment

begin_define
define|#
directive|define
name|KBDGTPMAT
value|_IOR('K', 2, int)
end_define

begin_define
define|#
directive|define
name|KBDSTPMAT
value|_IOW('K', 3, int)
end_define

begin_comment
comment|/*   Typematic rates:  *   Rate = 1 / Period, with   *   Period = (8+ (Val&7)) * 2^((Val>>3)&3) * 0.00417 seconds,  *   and Val the typematic value below  *  *   The typematic delay is determined by  *   Delay = (1+((Val>>5)&3)) * 250 msec +/- 20 %  *  *  Source IBM/AT reference manual, 1987  *  *  Note that you have to pass one TPD* and one TPM* value to the KBDSTPMAT  *  ioctl: they are different flags of the same data word. Also note that  *  0x00 is a valid value: KBD_TPD250|KBD_TPM300 which is really fast, instead  *  of turning off key repetition entirely. You can turn off key repetition  *  with the ioctls KBDGREPSW/KBDSREPSW. */
end_comment

begin_define
define|#
directive|define
name|KBD_TPD250
value|0x0000
end_define

begin_comment
comment|/* 250 ms */
end_comment

begin_define
define|#
directive|define
name|KBD_TPD500
value|0x0020
end_define

begin_comment
comment|/* 500 ms */
end_comment

begin_define
define|#
directive|define
name|KBD_TPD750
value|0x0040
end_define

begin_comment
comment|/* 750 ms */
end_comment

begin_define
define|#
directive|define
name|KBD_TPD1000
value|0x0060
end_define

begin_comment
comment|/* 1000 ms */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM300
value|0x0000
end_define

begin_comment
comment|/* 30.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM267
value|0x0001
end_define

begin_comment
comment|/* 26.7 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM240
value|0x0002
end_define

begin_comment
comment|/* 24.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM218
value|0x0003
end_define

begin_comment
comment|/* 21.8 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM200
value|0x0004
end_define

begin_comment
comment|/* 20.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM185
value|0x0005
end_define

begin_comment
comment|/* 18.5 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM171
value|0x0006
end_define

begin_comment
comment|/* 17.1 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM160
value|0x0007
end_define

begin_comment
comment|/* 16.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM150
value|0x0008
end_define

begin_comment
comment|/* 15.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM133
value|0x0009
end_define

begin_comment
comment|/* 13.3 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM120
value|0x000a
end_define

begin_comment
comment|/* 12.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM109
value|0x000b
end_define

begin_comment
comment|/* 10.9 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM100
value|0x000c
end_define

begin_comment
comment|/* 10.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM92
value|0x000d
end_define

begin_comment
comment|/*  9.2 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM86
value|0x000e
end_define

begin_comment
comment|/*  8.6 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM80
value|0x000f
end_define

begin_comment
comment|/*  8.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM75
value|0x0010
end_define

begin_comment
comment|/*  7.5 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM67
value|0x0011
end_define

begin_comment
comment|/*  6.7 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM60
value|0x0012
end_define

begin_comment
comment|/*  6.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM55
value|0x0013
end_define

begin_comment
comment|/*  5.5 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM50
value|0x0014
end_define

begin_comment
comment|/*  5.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM46
value|0x0015
end_define

begin_comment
comment|/*  4.6 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM43
value|0x0016
end_define

begin_comment
comment|/*  4.3 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM40
value|0x0017
end_define

begin_comment
comment|/*  4.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM37
value|0x0018
end_define

begin_comment
comment|/*  3.7 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM33
value|0x0019
end_define

begin_comment
comment|/*  3.3 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM30
value|0x001a
end_define

begin_comment
comment|/*  3.0 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM27
value|0x001b
end_define

begin_comment
comment|/*  2.7 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM25
value|0x001c
end_define

begin_comment
comment|/*  2.5 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM23
value|0x001d
end_define

begin_comment
comment|/*  2.3 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM21
value|0x001e
end_define

begin_comment
comment|/*  2.1 rate */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM20
value|0x001f
end_define

begin_comment
comment|/*  2.0 rate */
end_comment

begin_comment
comment|/* get (G) / set (S) the key repetition switch */
end_comment

begin_define
define|#
directive|define
name|KBD_REPEATOFF
value|0
end_define

begin_define
define|#
directive|define
name|KBD_REPEATON
value|1
end_define

begin_define
define|#
directive|define
name|KBDGREPSW
value|_IOR('K', 4, int)
end_define

begin_define
define|#
directive|define
name|KBDSREPSW
value|_IOW('K', 5, int)
end_define

begin_comment
comment|/**** handling keyboard LEDS and Lock keys ****/
end_comment

begin_comment
comment|/* get (G) / set (S) the keyboard LEDs,  * does not influence the state of the lock keys.  * Note: if keyboard serves tty console mode (VTYs have keyboard focus),  * the lock keys will still modify the state when used  */
end_comment

begin_define
define|#
directive|define
name|KBDGLEDS
value|_IOR('K', 6, int)
end_define

begin_define
define|#
directive|define
name|KBDSLEDS
value|_IOW('K', 7, int)
end_define

begin_comment
comment|/* get (G) / set (S) the SCROLL, NUM, CAPS ALTGRLOCK keys  * (note: ALTGRLOCK or SHIFTLOCK are not necessarily accessible   * on your keyboard)  */
end_comment

begin_define
define|#
directive|define
name|KBD_LOCKSCROLL
value|0x0001
end_define

begin_define
define|#
directive|define
name|KBD_LOCKNUM
value|0x0002
end_define

begin_define
define|#
directive|define
name|KBD_LOCKCAPS
value|0x0004
end_define

begin_define
define|#
directive|define
name|KBD_LOCKALTGR
value|0x0008
end_define

begin_define
define|#
directive|define
name|KBD_LOCKSHIFT
value|0x0010
end_define

begin_define
define|#
directive|define
name|KBDGLOCK
value|_IOR('K', 8, int)
end_define

begin_define
define|#
directive|define
name|KBDSLOCK
value|_IOW('K', 9, int)
end_define

begin_comment
comment|/**** making noise ****/
end_comment

begin_comment
comment|/* get (G) / set (S) the beeper frequency and tone duration  * the nr param determines the VTY which parameters are changed  * VTY# = 0...n, n< max_vtys  * nr = -1: actual vty  * nr = -2: Set the system default beep frequency  *  * in some emulations, you can also set pitch and duration by an ESC code  */
end_comment

begin_define
define|#
directive|define
name|KBD_ACTVTY
value|-1
end_define

begin_define
define|#
directive|define
name|KBD_DEFLT
value|-2
end_define

begin_struct
struct|struct
name|kbd_bell
block|{
name|int
name|pitch
decl_stmt|;
name|int
name|duration
decl_stmt|;
name|int
name|nr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KBDGETBEEP
value|_IOWR('K',28, struct kbd_bell)
end_define

begin_define
define|#
directive|define
name|KBDSETBEEP
value|_IOW('K',29, struct kbd_bell)
end_define

begin_comment
comment|/* do a beep of specified frequency and duration  * the argument nr is unused  * a NULL arg performs a default system beep  */
end_comment

begin_define
define|#
directive|define
name|KBDBELL
value|_IOW('K',30, struct kbd_bell)
end_define

begin_comment
comment|/**** I/O access ****/
end_comment

begin_comment
comment|/* This call allows programs to access I/O ports.   * The ioctl is intended to perform several tasks for the XFree86 Xserver,  * but currently has other interesting applications. This is why it is  * priviledged and can only be executed by root (or with setuid-root).  * In future the ioctl might be restricted to allow access to video ports  * only.  */
end_comment

begin_define
define|#
directive|define
name|X_MODE_ON
value|1
end_define

begin_define
define|#
directive|define
name|X_MODE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CONSOLE_X_MODE
value|_IOW('K',22,int)
end_define

begin_escape
end_escape

begin_comment
comment|/**** keyboard overloading ****/
end_comment

begin_comment
comment|/* Codrv allows loading of strings to keys in six layers.  * Any string may have a length of up to KBDMAXOVLKEYSIZE XCHARS.  * !!! Warning: This ioctl uses the type XCHAR. In future, this may  * !!! no longer be a char type, so str*** functions might not work any more  * !!! some day.  * The available layers are:  *  * - unshifted  * - with shift key  * - with ctrl key  * - with meta key (usually ALT-left)  * - with altgr key (usually ALT-right)  * - with shift+altgr key  *  * There are no combinations: shift-ctrl, ctrl-alt, shift-meta.  * The combination ctrl-altleft-somekey is reserved for system purposes.  * These keys are usually processed before the above keys. To gain control  * over these keys, you must run the keyboard in raw mode (/dev/kbd) and  * do ALL the processing yourself. The Xserver for instance does it this way.  * The following special keys are currently defined:  *   * CTRL-ALTLEFT-DELETE:	Reboot  * CTRL-ALTLEFT-ESCAPE: Call the debugger (if compiled into the kernel)  * CTRL-ALTLEFT-KP+:	Switch to next resolution (Xserver only)  * CTRL-ALTLEFT-KP-:	Switch to previous resolution (Xserver only)  */
end_comment

begin_comment
comment|/* values for type field of various kbd_overload ioctls */
end_comment

begin_define
define|#
directive|define
name|KBD_NONE
value|0
end_define

begin_comment
comment|/* no function, key is disabled */
end_comment

begin_define
define|#
directive|define
name|KBD_SHIFT
value|1
end_define

begin_comment
comment|/* keyboard shift */
end_comment

begin_define
define|#
directive|define
name|KBD_META
value|2
end_define

begin_comment
comment|/* (ALT) alternate shift, sets bit8 to ASCII code */
end_comment

begin_define
define|#
directive|define
name|KBD_NUM
value|3
end_define

begin_comment
comment|/* numeric shift  cursors vs. numeric */
end_comment

begin_define
define|#
directive|define
name|KBD_CTL
value|4
end_define

begin_comment
comment|/* control shift  -- allows ctl function */
end_comment

begin_define
define|#
directive|define
name|KBD_CAPS
value|5
end_define

begin_comment
comment|/* caps shift -- swaps case of letter */
end_comment

begin_define
define|#
directive|define
name|KBD_ASCII
value|6
end_define

begin_comment
comment|/* ascii code for this key */
end_comment

begin_define
define|#
directive|define
name|KBD_SCROLL
value|7
end_define

begin_comment
comment|/* stop output */
end_comment

begin_define
define|#
directive|define
name|KBD_FUNC
value|8
end_define

begin_comment
comment|/* function key */
end_comment

begin_define
define|#
directive|define
name|KBD_KP
value|9
end_define

begin_comment
comment|/* Keypad keys */
end_comment

begin_define
define|#
directive|define
name|KBD_BREAK
value|10
end_define

begin_comment
comment|/* The damned BREAK key, ignored in ioctl */
end_comment

begin_define
define|#
directive|define
name|KBD_ALTGR
value|11
end_define

begin_comment
comment|/* AltGr Translation feature */
end_comment

begin_define
define|#
directive|define
name|KBD_SHFTLOCK
value|12
end_define

begin_comment
comment|/* some people are accustomed to this nonsense */
end_comment

begin_define
define|#
directive|define
name|KBD_ALTGRLOCK
value|13
end_define

begin_comment
comment|/* Useful for 8-bit national kbds (cyrillic) */
end_comment

begin_define
define|#
directive|define
name|KBD_DOALTCAPS
value|0x0400
end_define

begin_comment
comment|/* change by altgr + caps shift */
end_comment

begin_define
define|#
directive|define
name|KBD_DOCAPS
value|0x0800
end_define

begin_comment
comment|/* change by caps shift */
end_comment

begin_define
define|#
directive|define
name|KBD_DIACPFX
value|0x4000
end_define

begin_comment
comment|/* Key carries a diacritical prefix */
end_comment

begin_define
define|#
directive|define
name|KBD_OVERLOAD
value|0x8000
end_define

begin_comment
comment|/* Key is overloaded, ignored in ioctl */
end_comment

begin_define
define|#
directive|define
name|KBD_MASK
value|0x001f
end_define

begin_comment
comment|/* mask for type */
end_comment

begin_define
define|#
directive|define
name|KBDMAXOVLKEYSIZE
value|15
end_define

begin_comment
comment|/* excl. zero byte */
end_comment

begin_struct
struct|struct
name|kbd_ovlkey
block|{
name|u_short
name|keynum
decl_stmt|;
name|u_short
name|type
decl_stmt|;
name|XCHAR
name|unshift
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|shift
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|ctrl
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|meta
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|altgr
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|shiftaltgr
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Get (G) / Set (S) a key assignment. This will influence the current  * key value only  */
end_comment

begin_define
define|#
directive|define
name|KBDGCKEY
value|_IOWR('K',16, struct kbd_ovlkey)
end_define

begin_define
define|#
directive|define
name|KBDSCKEY
value|_IOW('K',17, struct kbd_ovlkey)
end_define

begin_comment
comment|/* Get (G) the default (old) key assignment. You cannot overwrite the  * default setting, so this ioctl is unpaired  */
end_comment

begin_define
define|#
directive|define
name|KBDGOKEY
value|_IOWR('K',18, struct kbd_ovlkey)
end_define

begin_comment
comment|/* Remove a key assignment for a key, i.e. restore default setting for key  * arg = keynum  */
end_comment

begin_define
define|#
directive|define
name|KBDRMKEY
value|_IOW('K', 19, int)
end_define

begin_comment
comment|/* Restore the default key setting */
end_comment

begin_define
define|#
directive|define
name|KBDDEFAULT
value|_IO('K',20)
end_define

begin_comment
comment|/* Set behavior of unassigned key layers  * Note that there is a hack from further versions which uses  * the flags KBD_C0 and KBD_A0 for this. This is still supported, but  * is not recommended way to do. It may disappear in future  * (what means that it won't :-))  */
end_comment

begin_define
define|#
directive|define
name|KBD_CLEARCTRL
value|2
end_define

begin_define
define|#
directive|define
name|KBD_CLEARMETA
value|4
end_define

begin_define
define|#
directive|define
name|KBD_CLEARALT
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|KBD_CLEARNORM
value|8
end_define

begin_define
define|#
directive|define
name|KBD_CLEARSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|KBD_CLEARSHALT
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KBDSCLRLYR
value|_IOW('K',31,int)
end_define

begin_comment
comment|/* get (G) / set (S) CAPSLOCK LED behaviour.  * Not all of this keys may be accessible at your keyboard  * Note: For compatibility, the S ioctl returns the old state in arg  */
end_comment

begin_define
define|#
directive|define
name|KBD_CAPSCAPS
value|0
end_define

begin_comment
comment|/* LED follows CAPSLOCK state */
end_comment

begin_define
define|#
directive|define
name|KBD_CAPSSHIFT
value|1
end_define

begin_comment
comment|/* LED follows SHIFTLOCK state */
end_comment

begin_define
define|#
directive|define
name|KBD_CAPSALTGR
value|2
end_define

begin_comment
comment|/* LED follows ALTGRLOCK state */
end_comment

begin_define
define|#
directive|define
name|KBD_CAPSINIT
value|0x04
end_define

begin_comment
comment|/* bit to set to set a default for all VTYs */
end_comment

begin_define
define|#
directive|define
name|KBDGCAPSLED
value|_IOR('K',27,int)
end_define

begin_define
define|#
directive|define
name|KBDSCAPSLED
value|_IOWR('K',25,int)
end_define

begin_comment
comment|/* extended functions: functions that are triggered by a keypress  * before key is converted to ASCII  *  * use function KBD_HOTKEYDELETE to remove a hotkey from a key  */
end_comment

begin_struct
struct|struct
name|kbd_hotkey
block|{
name|u_short
name|key
decl_stmt|;
name|u_short
name|modifier
decl_stmt|;
name|u_short
name|function
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KBDGSPECF
value|_IOWR('K',32,struct kbd_hotkey)
end_define

begin_define
define|#
directive|define
name|KBDSSPECF
value|_IOW('K',33,struct kbd_hotkey)
end_define

begin_comment
comment|/* extended function prefixes (in modifier field)  * 	bit set triggers a special function on the key layer  */
end_comment

begin_define
define|#
directive|define
name|KBD_NOEXT
value|0x00
end_define

begin_comment
comment|/* trigger never */
end_comment

begin_define
define|#
directive|define
name|KBD_EXT_N
value|0x01
end_define

begin_comment
comment|/* on normal key (normal layer) */
end_comment

begin_define
define|#
directive|define
name|KBD_EXT_S
value|0x02
end_define

begin_comment
comment|/* on shift key (shift layer) */
end_comment

begin_define
define|#
directive|define
name|KBD_EXT_C
value|0x04
end_define

begin_comment
comment|/* on ctrl key (ctrl layer) */
end_comment

begin_define
define|#
directive|define
name|KBD_EXT_A
value|0x08
end_define

begin_comment
comment|/* on alt key (alt layer) */
end_comment

begin_define
define|#
directive|define
name|KBD_EXT_SK
value|0x10
end_define

begin_comment
comment|/* on syskey (PRINTSCREEN) (Meta Layer) */
end_comment

begin_define
define|#
directive|define
name|KBD_EXT_CA
value|0x20
end_define

begin_comment
comment|/* on ctrl-alt (shift alt layer) */
end_comment

begin_comment
comment|/* extended functions (in function field) */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY0
value|0
end_define

begin_comment
comment|/* select vty 0 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY1
value|1
end_define

begin_comment
comment|/* select vty 1 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY2
value|2
end_define

begin_comment
comment|/* select vty 2 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY3
value|3
end_define

begin_comment
comment|/* select vty 3 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY4
value|4
end_define

begin_comment
comment|/* select vty 4 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY5
value|5
end_define

begin_comment
comment|/* select vty 5 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY6
value|6
end_define

begin_comment
comment|/* select vty 6 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY7
value|7
end_define

begin_comment
comment|/* select vty 7 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY8
value|8
end_define

begin_comment
comment|/* select vty 8 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY9
value|9
end_define

begin_comment
comment|/* select vty 9 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY10
value|10
end_define

begin_comment
comment|/* select vty 10 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTY11
value|11
end_define

begin_comment
comment|/* select vty 11 */
end_comment

begin_define
define|#
directive|define
name|KBD_VTYUP
value|0x80
end_define

begin_comment
comment|/* select next vty */
end_comment

begin_define
define|#
directive|define
name|KBD_VTYDOWN
value|0x81
end_define

begin_comment
comment|/* select previous vty */
end_comment

begin_define
define|#
directive|define
name|KBD_RESETKEY
value|0x82
end_define

begin_comment
comment|/* the CTRL-ALT-DEL key (movable) */
end_comment

begin_define
define|#
directive|define
name|KBD_DEBUGKEY
value|0x83
end_define

begin_comment
comment|/* the CTRL-ALT-ESC key (debugger) */
end_comment

begin_define
define|#
directive|define
name|KBD_HOTKEYDELETE
value|0xff
end_define

begin_comment
comment|/* use to delete a hotkey KBDSSPECF */
end_comment

begin_escape
end_escape

begin_comment
comment|/* These are names used in older versions of keycap/codrv */
end_comment

begin_comment
comment|/* do not use the following functions any longer in future */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_CO011
end_ifdef

begin_define
define|#
directive|define
name|KBDRESET
value|KBDCOLDRESET
end_define

begin_define
define|#
directive|define
name|KBDRESET8042
value|KBDWARMRESET
end_define

begin_define
define|#
directive|define
name|KBDFORCEASCII
value|_IOW('K', 24, int)
end_define

begin_comment
comment|/* no op in codrv-0.1.2 */
end_comment

begin_define
define|#
directive|define
name|KBD_SCROLLLOCK
value|KBD_LOCKSCROLL
end_define

begin_define
define|#
directive|define
name|KBD_NUMLOCK
value|KBD_LOCKNUM
end_define

begin_define
define|#
directive|define
name|KBD_CAPSLOCK
value|KBD_LOCKCAPS
end_define

begin_define
define|#
directive|define
name|KBDASGNLEDS
value|KBDSCAPSLED
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_struct
struct|struct
name|kbd_sound
block|{
name|int
name|pitch
decl_stmt|;
comment|/* Frequency in Hz */
name|int
name|duration
decl_stmt|;
comment|/* Time in msec */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KBDSETBELL
value|_IOW('K',21, struct kbd_sound)
end_define

begin_comment
comment|/* do some music */
end_comment

begin_define
define|#
directive|define
name|OLDKBDSETBEEP
value|_IOW('K',26, struct kbd_sound)
end_define

begin_comment
comment|/* change beep settings */
end_comment

begin_struct
struct|struct
name|oldkbd_ovlkey
block|{
name|u_short
name|keynum
decl_stmt|;
name|u_short
name|type
decl_stmt|;
name|char
name|unshift
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|shift
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|ctrl
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|altgr
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OLDKBDGCKEY
value|_IOWR('K',16, struct oldkbd_ovlkey)
end_define

begin_comment
comment|/* get current key values */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*COMPAT_CO011*/
end_comment

begin_comment
comment|/***************************************************************************  *   IOCTLs for Video Adapter  ***************************************************************************/
end_comment

begin_comment
comment|/* to define the cursor shape for ioctl */
end_comment

begin_struct
struct|struct
name|cursorshape
block|{
name|int
name|start
decl_stmt|;
comment|/* topmost scanline, range 0...31 */
name|int
name|end
decl_stmt|;
comment|/* bottom scanline, range 0...31 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGAGCURSOR
value|_IOR('V',100, struct cursorshape)
end_define

begin_comment
comment|/* get cursor shape */
end_comment

begin_define
define|#
directive|define
name|VGASCURSOR
value|_IOW('V',101, struct cursorshape)
end_define

begin_comment
comment|/* set cursor shape */
end_comment

begin_comment
comment|/**** information ****/
end_comment

begin_comment
comment|/* the video information structure for ioctl */
end_comment

begin_struct
struct|struct
name|videoinfo
block|{
name|char
name|name
index|[
literal|20
index|]
decl_stmt|;
comment|/* ASCIZ name of detected card */
name|short
name|type
decl_stmt|;
comment|/* Adapter type, see below */
name|short
name|subtype
decl_stmt|;
comment|/* Adapter specific subtype */
name|short
name|ram
decl_stmt|;
comment|/* in KBytes */
name|short
name|iobase
decl_stmt|;
comment|/* Address of 6845: 0x3b0 / 0x3d0 */
block|}
struct|;
end_struct

begin_comment
comment|/* Get information about the videoboard */
end_comment

begin_define
define|#
directive|define
name|VGAGINFO
value|_IOR('V',102, struct videoinfo)
end_define

begin_comment
comment|/* recognized Adapter types */
end_comment

begin_define
define|#
directive|define
name|VG_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|VG_MONO
value|1
end_define

begin_define
define|#
directive|define
name|VG_CGA
value|2
end_define

begin_define
define|#
directive|define
name|VG_EGA
value|3
end_define

begin_define
define|#
directive|define
name|VG_VGA
value|4
end_define

begin_define
define|#
directive|define
name|VG_CHIPS
value|5
end_define

begin_comment
comment|/*	CHIPS& TECHNOLOGIES has subtypes:  *		0x10	82c451  *		0x11	82c452  *		0x20	82c455  *		0x30	82c453  *		0x50	82c455  */
end_comment

begin_define
define|#
directive|define
name|VG_GENOA
value|6
end_define

begin_comment
comment|/*	GENOA has subtypes:  *		0x33/0x55	5100-5400, ET3000 based  *		0x22		6100  *		0x00		6200,6300  *		0x11		6400,6600  */
end_comment

begin_define
define|#
directive|define
name|VG_PARADISE
value|7
end_define

begin_comment
comment|/*	PARADISE has subtypes:  *		01	PVGA1A,WD90C90  *		02	WD90C00  *		03	WD90C10  *		04	WD90C11  */
end_comment

begin_define
define|#
directive|define
name|VG_TVGA
value|8
end_define

begin_comment
comment|/*	TVGA	has subtypes:  *		00-02	8800  *		03	8900B  *		04	8900C  *		13	8900C  *		23	9000  */
end_comment

begin_define
define|#
directive|define
name|VG_ET3000
value|9
end_define

begin_define
define|#
directive|define
name|VG_ET4000
value|10
end_define

begin_define
define|#
directive|define
name|VG_VIDEO7
value|11
end_define

begin_comment
comment|/*	VIDEO7  has subtypes:  *		0x80-0xfe	VEGA VGA  *		0x70-0x7e	V7VGA FASTWRITE/VRAM  *		0x50-0x59	V7VGA version 5  *		0x41-0x49	1024i  */
end_comment

begin_define
define|#
directive|define
name|VG_ATI
value|12
end_define

begin_comment
comment|/*	ATI	has subtypes:  *		0x01nn	18800  *		0x02nn	18800-1  *		0x03nn	28800-2  *		0x04nn-05nn  *	with nn:  *		0x01	VGA WONDER  *		0x02	EGA WONDER800+  *		0x03	VGA BASIC 16+  */
end_comment

begin_comment
comment|/**** Screen blanking ****/
end_comment

begin_comment
comment|/* Get (G) / Set (S) screen blanker timeout (seconds),  * time=0 disables blanking  *  * The blanking state is coded in bits 31 and 30 of word returned by get  */
end_comment

begin_define
define|#
directive|define
name|VGA_BLANKOFF
value|0x00000000
end_define

begin_comment
comment|/* display is on, no blanking */
end_comment

begin_define
define|#
directive|define
name|VGA_BLANKON
value|0x40000000
end_define

begin_comment
comment|/* display is on, wait for blank */
end_comment

begin_define
define|#
directive|define
name|VGA_BLANKED
value|0x80000000
end_define

begin_comment
comment|/* display is dark */
end_comment

begin_define
define|#
directive|define
name|VGAGBLANK
value|_IOR('V',2,int)
end_define

begin_define
define|#
directive|define
name|VGASBLANK
value|_IOW('V',3,int)
end_define

begin_comment
comment|/**** Text/Attribute direct access, block move ****/
end_comment

begin_struct
struct|struct
name|vga_block
block|{
name|short
name|mode
decl_stmt|;
name|short
name|pagenum
decl_stmt|;
name|short
name|x0
decl_stmt|,
name|y0
decl_stmt|;
comment|/* upper left coordinates 0..x-1, 0..y-1 */
name|short
name|x1
decl_stmt|,
name|y1
decl_stmt|;
comment|/* lower right coordinates>= x0,y0 */
name|u_char
modifier|*
name|map
decl_stmt|;
comment|/* must be allocated by user process ! */
block|}
struct|;
end_struct

begin_comment
comment|/* mode word */
end_comment

begin_define
define|#
directive|define
name|VGA_SCREEN
value|0x01
end_define

begin_comment
comment|/* entire screen, ignore x,y */
end_comment

begin_define
define|#
directive|define
name|VGA_WINDOW
value|0x02
end_define

begin_comment
comment|/* use x,y for a rectangular window */
end_comment

begin_define
define|#
directive|define
name|VGA_TEXT
value|0x10
end_define

begin_comment
comment|/* copy text information only */
end_comment

begin_define
define|#
directive|define
name|VGA_ATTR
value|0x20
end_define

begin_comment
comment|/* copy attribute information only */
end_comment

begin_define
define|#
directive|define
name|VGA_BOTH
value|0x30
end_define

begin_comment
comment|/* copy text and attribute */
end_comment

begin_define
define|#
directive|define
name|VGA_ALL
value|0x31
end_define

begin_comment
comment|/* copy complete screen */
end_comment

begin_comment
comment|/* Get (G) / Set (S) a rectangular block of screen  * The virtual screen need not be visible.  * The buffer must be provided by the user process and must be large enough  * use VGAGVRES to find out how many bytes  * pagenum: 0..n, n< max_vty, VTY number  *	    -1, actual VTY  */
end_comment

begin_define
define|#
directive|define
name|VGAGBLOCK
value|_IOWR('V',4,struct vga_block)
end_define

begin_define
define|#
directive|define
name|VGASBLOCK
value|_IOW('V',5,struct vga_block)
end_define

begin_define
define|#
directive|define
name|VGA_TXTPAGE0
value|0
end_define

begin_define
define|#
directive|define
name|VGA_TXTPAGE1
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|VGA_GFXPAGE
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VGA_PC8CODING
value|0x80
end_define

begin_comment
comment|/* obsolete ! */
end_comment

begin_comment
comment|/* maximum dimension of pixels  * Note: this is the space reserved in the fontchar map, but  * does not mean, that this resolution is accepted in the current release  * codrv-0.1.2 accepts 8x16 / "9x16" fonts only  */
end_comment

begin_define
define|#
directive|define
name|VGA_MAXX
value|16
end_define

begin_define
define|#
directive|define
name|VGA_MAXY
value|16
end_define

begin_struct
struct|struct
name|fchar
block|{
name|XCHAR
name|encoding
decl_stmt|;
comment|/* encoding of character */
name|char
name|_f1_
decl_stmt|,
name|_f2_
decl_stmt|,
name|_f3_
decl_stmt|;
comment|/* filler */
name|u_char
name|map
index|[
name|VGA_MAXX
operator|/
literal|8
operator|*
name|VGA_MAXY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fmap
block|{
name|short
name|page
decl_stmt|;
comment|/* page to load */
name|short
name|nr
decl_stmt|;
comment|/* nr of characters to load */
name|char
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* x,y pixel width */
name|XCHAR
name|start
decl_stmt|;
comment|/* first character in sequence (get only) */
name|struct
name|fchar
modifier|*
name|fntmap
decl_stmt|;
comment|/* allocated by user process */
block|}
struct|;
end_struct

begin_comment
comment|/* get (G) / set (S) font map. Must provide page,nr,start for get */
end_comment

begin_define
define|#
directive|define
name|VGAGFONTMAP
value|_IOWR('V',6,struct fmap)
end_define

begin_define
define|#
directive|define
name|VGASFONTMAP
value|_IOW('V',7,struct fmap)
end_define

begin_comment
comment|/* do not use the following functions any longer in future */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_CO011
end_ifdef

begin_comment
comment|/* miscellaneous functions: */
end_comment

begin_define
define|#
directive|define
name|VGA_DIS1
value|1
end_define

begin_comment
comment|/* disable font 1 */
end_comment

begin_define
define|#
directive|define
name|VGA_GTENC
value|2
end_define

begin_comment
comment|/* get current encoding */
end_comment

begin_define
define|#
directive|define
name|VGA_SBLANK
value|3
end_define

begin_comment
comment|/* set screen blanking timeout (use VGASBLANK!) */
end_comment

begin_define
define|#
directive|define
name|VGA_GBLANK
value|4
end_define

begin_comment
comment|/* get screen blanking timeout (use VGAGBLANK!) */
end_comment

begin_struct
struct|struct
name|miscfcns
block|{
name|u_char
name|cmd
decl_stmt|;
union|union
block|{
name|short
name|enc
index|[
literal|2
index|]
decl_stmt|;
name|int
name|timeout
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGAMISCFCNS
value|_IOWR('V',107,struct miscfcns)
end_define

begin_comment
comment|/* misc functions */
end_comment

begin_comment
comment|/* Font mapping this needs at least an EGA card (else EINVAL) */
end_comment

begin_define
define|#
directive|define
name|VGAFNTLATIN1
value|0x00
end_define

begin_define
define|#
directive|define
name|VGAFNTEXTEND1
value|0x01
end_define

begin_define
define|#
directive|define
name|VGAFNTEXTEND2
value|0x02
end_define

begin_define
define|#
directive|define
name|VGAFNTGREEK
value|0x03
end_define

begin_define
define|#
directive|define
name|VGAFNTCYRILLIC
value|0x04
end_define

begin_define
define|#
directive|define
name|VGAFNTHEBREW
value|0x05
end_define

begin_define
define|#
directive|define
name|VGAFNTARABIAN
value|0x06
end_define

begin_define
define|#
directive|define
name|VGA_FNTNCHARS
value|256
end_define

begin_define
define|#
directive|define
name|VGA_FNTCSIZE
value|15
end_define

begin_struct
struct|struct
name|fontchar
block|{
name|u_char
name|page
decl_stmt|;
comment|/* which font page */
name|u_char
name|idx
decl_stmt|;
comment|/* which char in font page */
name|u_char
name|cmap
index|[
name|VGA_FNTCSIZE
index|]
decl_stmt|;
comment|/* character bitmap */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OLDVGAGCHAR
value|_IOWR('V',105,struct fontchar)
end_define

begin_comment
comment|/* get character of font */
end_comment

begin_define
define|#
directive|define
name|OLDVGASCHAR
value|_IOW('V',106,struct fontchar)
end_define

begin_comment
comment|/* set character in font */
end_comment

begin_struct
struct|struct
name|fontmap
block|{
name|u_char
name|page
decl_stmt|;
comment|/* page to load */
name|u_short
name|encoding
decl_stmt|;
comment|/* font encoding */
name|u_char
name|map
index|[
name|VGA_FNTNCHARS
operator|*
name|VGA_FNTCSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OLDVGAGFNTMAP
value|_IOWR('V',103,struct fontmap)
end_define

begin_comment
comment|/* get font */
end_comment

begin_define
define|#
directive|define
name|VGAGFNTMAP
value|OLDVGAGFNTMAP
end_define

begin_define
define|#
directive|define
name|OLDVGASFNTMAP
value|_IOW('V',104,struct fontmap)
end_define

begin_comment
comment|/* set font */
end_comment

begin_define
define|#
directive|define
name|VGASFNTMAP
value|OLDVGASFNTMAP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|textpage
block|{
name|u_char
name|pagenum
decl_stmt|;
comment|/* note: only page 0 used by vtys */
define|#
directive|define
name|VGA_TEXTATTR
value|0
define|#
directive|define
name|VGA_TEXTDATA
value|1
name|u_char
name|ad
decl_stmt|;
define|#
directive|define
name|VGA_LINES
value|50
comment|/* only 25 used for now */
define|#
directive|define
name|VGA_COLUMNS
value|80
name|u_char
name|map
index|[
name|VGA_LINES
operator|*
name|VGA_COLUMNS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGAGPAGE
value|_IOWR('V',108,struct textpage)
end_define

begin_comment
comment|/* get a data page */
end_comment

begin_define
define|#
directive|define
name|VGASPAGE
value|_IOW('V',109,struct textpage)
end_define

begin_comment
comment|/* set a data page */
end_comment

begin_comment
comment|/**** Signalling access ****/
end_comment

begin_comment
comment|/* Use "take control" in an application program to signal the kernel  * that the program wants to use video memory (such as Xserver)  * before the program switches modes  *  * Use "give control" to return the control to the kernel. The application  * should have restored the original state before giving back control.  * Close /dev/vga also returns control.  *  * However, the kernel remains the master in the house, and reserves the right  * to grab control back at any time. (It usually doesn't).  *  */
end_comment

begin_define
define|#
directive|define
name|VGATAKECTRL
value|_IO('V',8)
end_define

begin_define
define|#
directive|define
name|VGAGIVECTRL
value|_IO('V',9)
end_define

begin_comment
comment|/***************************************************************************  *   Pandora's box, don't even think of using the following ioctl's  *   (if you happen to find some; codrv_experimental might not be  *   available at your system)  ***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PANDORA
end_ifdef

begin_include
include|#
directive|include
file|"codrv_experimental.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/***************************************************************************  *   XFree86 pccons support  ***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_PCCONS
end_ifdef

begin_comment
comment|/* The following calls are special to the old pccons driver and are  * not understood or supported by codrv.   * This file serves as a central definition base for these calls  * in order to avoid defining them in applications that want to   * use them.  *  * One word of warning: There are different purpose tty ioctls  * with the same encoding, see<sys/ioctl.h>  * TIOCSDTR = _IO('t', 121)  * TIOCCBRK = _IO('t', 122)  *  */
end_comment

begin_define
define|#
directive|define
name|CONSOLE_X_MODE_ON
value|_IO('t',121)
end_define

begin_define
define|#
directive|define
name|CONSOLE_X_MODE_OFF
value|_IO('t',122)
end_define

begin_define
define|#
directive|define
name|CONSOLE_X_BELL
value|_IOW('t',123,int[2])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_PCCONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IOCTL_PC_H_ */
end_comment

end_unit

