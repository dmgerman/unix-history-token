begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993 Erik Forsberg.  * Copyright (c) 1996, 1997 Kazutaka YOKOTA  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL I BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MOUSE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MOUSE_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* ioctls */
end_comment

begin_define
define|#
directive|define
name|MOUSE_GETSTATUS
value|_IOR('M', 0, mousestatus_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_GETHWINFO
value|_IOR('M', 1, mousehw_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_GETMODE
value|_IOR('M', 2, mousemode_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_SETMODE
value|_IOW('M', 3, mousemode_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_GETLEVEL
value|_IOR('M', 4, int)
end_define

begin_define
define|#
directive|define
name|MOUSE_SETLEVEL
value|_IOW('M', 5, int)
end_define

begin_define
define|#
directive|define
name|MOUSE_GETVARS
value|_IOR('M', 6, mousevar_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_SETVARS
value|_IOW('M', 7, mousevar_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_READSTATE
value|_IOWR('M', 8, mousedata_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_READDATA
value|_IOWR('M', 9, mousedata_t)
end_define

begin_if
if|#
directive|if
name|notyet
end_if

begin_define
define|#
directive|define
name|MOUSE_SETRESOLUTION
value|_IOW('M', 10, int)
end_define

begin_define
define|#
directive|define
name|MOUSE_SETSCALING
value|_IOW('M', 11, int)
end_define

begin_define
define|#
directive|define
name|MOUSE_SETRATE
value|_IOW('M', 12, int)
end_define

begin_define
define|#
directive|define
name|MOUSE_GETHWID
value|_IOR('M', 13, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mouse status block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mousestatus
block|{
name|int
name|flags
decl_stmt|;
comment|/* state change flags */
name|int
name|button
decl_stmt|;
comment|/* button status */
name|int
name|obutton
decl_stmt|;
comment|/* previous button status */
name|int
name|dx
decl_stmt|;
comment|/* x movement */
name|int
name|dy
decl_stmt|;
comment|/* y movement */
name|int
name|dz
decl_stmt|;
comment|/* z movement */
block|}
name|mousestatus_t
typedef|;
end_typedef

begin_comment
comment|/* button */
end_comment

begin_define
define|#
directive|define
name|MOUSE_BUTTON1DOWN
value|0x0001
end_define

begin_comment
comment|/* left */
end_comment

begin_define
define|#
directive|define
name|MOUSE_BUTTON2DOWN
value|0x0002
end_define

begin_comment
comment|/* middle */
end_comment

begin_define
define|#
directive|define
name|MOUSE_BUTTON3DOWN
value|0x0004
end_define

begin_comment
comment|/* right */
end_comment

begin_define
define|#
directive|define
name|MOUSE_BUTTON4DOWN
value|0x0008
end_define

begin_define
define|#
directive|define
name|MOUSE_BUTTON5DOWN
value|0x0010
end_define

begin_define
define|#
directive|define
name|MOUSE_BUTTON6DOWN
value|0x0020
end_define

begin_define
define|#
directive|define
name|MOUSE_BUTTON7DOWN
value|0x0040
end_define

begin_define
define|#
directive|define
name|MOUSE_BUTTON8DOWN
value|0x0080
end_define

begin_define
define|#
directive|define
name|MOUSE_MAXBUTTON
value|31
end_define

begin_define
define|#
directive|define
name|MOUSE_STDBUTTONS
value|0x0007
end_define

begin_comment
comment|/* buttons 1-3 */
end_comment

begin_define
define|#
directive|define
name|MOUSE_EXTBUTTONS
value|0x7ffffff8
end_define

begin_comment
comment|/* the others (28 of them!) */
end_comment

begin_define
define|#
directive|define
name|MOUSE_BUTTONS
value|(MOUSE_STDBUTTONS | MOUSE_EXTBUTTONS)
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|MOUSE_STDBUTTONSCHANGED
value|MOUSE_STDBUTTONS
end_define

begin_define
define|#
directive|define
name|MOUSE_EXTBUTTONSCHANGED
value|MOUSE_EXTBUTTONS
end_define

begin_define
define|#
directive|define
name|MOUSE_BUTTONSCHANGED
value|MOUSE_BUTTONS
end_define

begin_define
define|#
directive|define
name|MOUSE_POSCHANGED
value|0x80000000
end_define

begin_typedef
typedef|typedef
struct|struct
name|mousehw
block|{
name|int
name|buttons
decl_stmt|;
comment|/* -1 if unknown */
name|int
name|iftype
decl_stmt|;
comment|/* MOUSE_IF_XXX */
name|int
name|type
decl_stmt|;
comment|/* mouse/track ball/pad... */
name|int
name|model
decl_stmt|;
comment|/* I/F dependent model ID: MOUSE_MODEL_XXX */
name|int
name|hwid
decl_stmt|;
comment|/* I/F dependent hardware ID 				 * for the PS/2 mouse, it will be PSM_XXX_ID  				 */
block|}
name|mousehw_t
typedef|;
end_typedef

begin_comment
comment|/* iftype */
end_comment

begin_define
define|#
directive|define
name|MOUSE_IF_UNKNOWN
value|(-1)
end_define

begin_define
define|#
directive|define
name|MOUSE_IF_SERIAL
value|0
end_define

begin_define
define|#
directive|define
name|MOUSE_IF_BUS
value|1
end_define

begin_define
define|#
directive|define
name|MOUSE_IF_INPORT
value|2
end_define

begin_define
define|#
directive|define
name|MOUSE_IF_PS2
value|3
end_define

begin_define
define|#
directive|define
name|MOUSE_IF_SYSMOUSE
value|4
end_define

begin_comment
comment|/* type */
end_comment

begin_define
define|#
directive|define
name|MOUSE_UNKNOWN
value|(-1)
end_define

begin_comment
comment|/* should be treated as a mouse */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MOUSE
value|0
end_define

begin_define
define|#
directive|define
name|MOUSE_TRACKBALL
value|1
end_define

begin_define
define|#
directive|define
name|MOUSE_STICK
value|2
end_define

begin_define
define|#
directive|define
name|MOUSE_PAD
value|3
end_define

begin_comment
comment|/* model */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MODEL_UNKNOWN
value|(-1)
end_define

begin_define
define|#
directive|define
name|MOUSE_MODEL_GENERIC
value|0
end_define

begin_define
define|#
directive|define
name|MOUSE_MODEL_GLIDEPOINT
value|1
end_define

begin_define
define|#
directive|define
name|MOUSE_MODEL_NETSCROLL
value|2
end_define

begin_define
define|#
directive|define
name|MOUSE_MODEL_NET
value|3
end_define

begin_define
define|#
directive|define
name|MOUSE_MODEL_INTELLI
value|4
end_define

begin_define
define|#
directive|define
name|MOUSE_MODEL_THINK
value|5
end_define

begin_define
define|#
directive|define
name|MOUSE_MODEL_EASYSCROLL
value|6
end_define

begin_define
define|#
directive|define
name|MOUSE_MODEL_MOUSEMANPLUS
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
name|mousemode
block|{
name|int
name|protocol
decl_stmt|;
comment|/* MOUSE_PROTO_XXX */
name|int
name|rate
decl_stmt|;
comment|/* report rate (per sec), -1 if unknown */
name|int
name|resolution
decl_stmt|;
comment|/* MOUSE_RES_XXX, -1 if unknown */
name|int
name|accelfactor
decl_stmt|;
comment|/* accelation factor (must be 1 or greater) */
name|int
name|level
decl_stmt|;
comment|/* driver operation level */
name|int
name|packetsize
decl_stmt|;
comment|/* the length of the data packet */
name|unsigned
name|char
name|syncmask
index|[
literal|2
index|]
decl_stmt|;
comment|/* sync. data bits in the header byte */
block|}
name|mousemode_t
typedef|;
end_typedef

begin_comment
comment|/* protocol */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_UNKNOWN
value|(-1)
end_define

begin_define
define|#
directive|define
name|MOUSE_PROTO_MS
value|0
end_define

begin_comment
comment|/* Microsoft Serial, 3 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_MSC
value|1
end_define

begin_comment
comment|/* Mouse Systems, 5 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_LOGI
value|2
end_define

begin_comment
comment|/* Logitech, 3 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_MM
value|3
end_define

begin_comment
comment|/* MM series, 3 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_LOGIMOUSEMAN
value|4
end_define

begin_comment
comment|/* Logitech MouseMan 3/4 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_BUS
value|5
end_define

begin_comment
comment|/* MS/Logitech bus mouse */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_INPORT
value|6
end_define

begin_comment
comment|/* MS/ATI InPort mouse */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_PS2
value|7
end_define

begin_comment
comment|/* PS/2 mouse, 3 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_HITTAB
value|8
end_define

begin_comment
comment|/* Hitachi Tablet 3 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_GLIDEPOINT
value|9
end_define

begin_comment
comment|/* ALPS GlidePoint, 3/4 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_INTELLI
value|10
end_define

begin_comment
comment|/* MS IntelliMouse, 4 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_THINK
value|11
end_define

begin_comment
comment|/* Kensignton Thinking Mouse, 3/4 bytes */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PROTO_SYSMOUSE
value|12
end_define

begin_comment
comment|/* /dev/sysmouse */
end_comment

begin_define
define|#
directive|define
name|MOUSE_RES_UNKNOWN
value|(-1)
end_define

begin_define
define|#
directive|define
name|MOUSE_RES_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|MOUSE_RES_LOW
value|(-2)
end_define

begin_define
define|#
directive|define
name|MOUSE_RES_MEDIUMLOW
value|(-3)
end_define

begin_define
define|#
directive|define
name|MOUSE_RES_MEDIUMHIGH
value|(-4)
end_define

begin_define
define|#
directive|define
name|MOUSE_RES_HIGH
value|(-5)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mousedata
block|{
name|int
name|len
decl_stmt|;
comment|/* # of data in the buffer */
name|int
name|buf
index|[
literal|16
index|]
decl_stmt|;
comment|/* data buffer */
block|}
name|mousedata_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|MOUSE_GETVARS
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|mousevar
block|{
name|int
name|var
index|[
literal|16
index|]
decl_stmt|;
block|}
name|mousevar_t
typedef|;
end_typedef

begin_comment
comment|/* magic numbers in var[0] */
end_comment

begin_define
define|#
directive|define
name|MOUSE_VARS_PS2_SIG
value|0x00325350
end_define

begin_comment
comment|/* 'PS2' */
end_comment

begin_define
define|#
directive|define
name|MOUSE_VARS_BUS_SIG
value|0x00535542
end_define

begin_comment
comment|/* 'BUS' */
end_comment

begin_define
define|#
directive|define
name|MOUSE_VARS_INPORT_SIG
value|0x00504e49
end_define

begin_comment
comment|/* 'INP' */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOUSE_GETVARS */
end_comment

begin_comment
comment|/* Microsoft Serial mouse data packet */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MSS_PACKETSIZE
value|3
end_define

begin_define
define|#
directive|define
name|MOUSE_MSS_SYNCMASK
value|0x40
end_define

begin_define
define|#
directive|define
name|MOUSE_MSS_SYNC
value|0x40
end_define

begin_define
define|#
directive|define
name|MOUSE_MSS_BUTTONS
value|0x30
end_define

begin_define
define|#
directive|define
name|MOUSE_MSS_BUTTON1DOWN
value|0x20
end_define

begin_comment
comment|/* left */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MSS_BUTTON2DOWN
value|0x00
end_define

begin_comment
comment|/* no middle button */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MSS_BUTTON3DOWN
value|0x10
end_define

begin_comment
comment|/* right */
end_comment

begin_comment
comment|/* Logitech MouseMan data packet (M+ protocol) */
end_comment

begin_define
define|#
directive|define
name|MOUSE_LMAN_BUTTON2DOWN
value|0x20
end_define

begin_comment
comment|/* middle button, the 4th byte */
end_comment

begin_comment
comment|/* ALPS GlidePoint extention (variant of M+ protocol) */
end_comment

begin_define
define|#
directive|define
name|MOUSE_ALPS_BUTTON2DOWN
value|0x20
end_define

begin_comment
comment|/* middle button, the 4th byte */
end_comment

begin_define
define|#
directive|define
name|MOUSE_ALPS_TAP
value|0x10
end_define

begin_comment
comment|/* `tapping' action, the 4th byte */
end_comment

begin_comment
comment|/* Kinsington Thinking Mouse extention (variant of M+ protocol) */
end_comment

begin_define
define|#
directive|define
name|MOUSE_THINK_BUTTON2DOWN
value|0x20
end_define

begin_comment
comment|/* lower-left button, the 4th byte */
end_comment

begin_define
define|#
directive|define
name|MOUSE_THINK_BUTTON4DOWN
value|0x10
end_define

begin_comment
comment|/* lower-right button, the 4th byte */
end_comment

begin_comment
comment|/* MS IntelliMouse (variant of MS Serial) */
end_comment

begin_define
define|#
directive|define
name|MOUSE_INTELLI_PACKETSIZE
value|4
end_define

begin_define
define|#
directive|define
name|MOUSE_INTELLI_BUTTON2DOWN
value|0x10
end_define

begin_comment
comment|/* middle button the 4th byte */
end_comment

begin_comment
comment|/* Mouse Systems Corp. mouse data packet */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MSC_PACKETSIZE
value|5
end_define

begin_define
define|#
directive|define
name|MOUSE_MSC_SYNCMASK
value|0xf8
end_define

begin_define
define|#
directive|define
name|MOUSE_MSC_SYNC
value|0x80
end_define

begin_define
define|#
directive|define
name|MOUSE_MSC_BUTTONS
value|0x07
end_define

begin_define
define|#
directive|define
name|MOUSE_MSC_BUTTON1UP
value|0x04
end_define

begin_comment
comment|/* left */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MSC_BUTTON2UP
value|0x02
end_define

begin_comment
comment|/* middle */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MSC_BUTTON3UP
value|0x01
end_define

begin_comment
comment|/* right */
end_comment

begin_comment
comment|/* MM series mouse data packet */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MM_PACKETSIZE
value|3
end_define

begin_define
define|#
directive|define
name|MOUSE_MM_SYNCMASK
value|0xe0
end_define

begin_define
define|#
directive|define
name|MOUSE_MM_SYNC
value|0x80
end_define

begin_define
define|#
directive|define
name|MOUSE_MM_BUTTONS
value|0x07
end_define

begin_define
define|#
directive|define
name|MOUSE_MM_BUTTON1DOWN
value|0x04
end_define

begin_comment
comment|/* left */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MM_BUTTON2DOWN
value|0x02
end_define

begin_comment
comment|/* middle */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MM_BUTTON3DOWN
value|0x01
end_define

begin_comment
comment|/* right */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MM_XPOSITIVE
value|0x10
end_define

begin_define
define|#
directive|define
name|MOUSE_MM_YPOSITIVE
value|0x08
end_define

begin_comment
comment|/* PS/2 mouse data packet */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PS2_PACKETSIZE
value|3
end_define

begin_define
define|#
directive|define
name|MOUSE_PS2_SYNCMASK
value|0xc8
end_define

begin_define
define|#
directive|define
name|MOUSE_PS2_SYNC
value|0x08
end_define

begin_define
define|#
directive|define
name|MOUSE_PS2_BUTTONS
value|0x07
end_define

begin_comment
comment|/* 0x03 for 2 button mouse */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PS2_BUTTON1DOWN
value|0x01
end_define

begin_comment
comment|/* left */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PS2_BUTTON2DOWN
value|0x04
end_define

begin_comment
comment|/* middle */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PS2_BUTTON3DOWN
value|0x02
end_define

begin_comment
comment|/* right */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PS2_TAP
value|MOUSE_PS2_SYNC
end_define

begin_comment
comment|/* GlidePoint (PS/2) `tapping' 					        * Yes! this is the same bit  						* as SYNC! 					 	*/
end_comment

begin_define
define|#
directive|define
name|MOUSE_PS2PLUS_BUTTON4DOWN
value|0x10
end_define

begin_comment
comment|/* 4th button on MouseMan+ */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PS2_XNEG
value|0x10
end_define

begin_define
define|#
directive|define
name|MOUSE_PS2_YNEG
value|0x20
end_define

begin_define
define|#
directive|define
name|MOUSE_PS2_XOVERFLOW
value|0x40
end_define

begin_define
define|#
directive|define
name|MOUSE_PS2_YOVERFLOW
value|0x80
end_define

begin_define
define|#
directive|define
name|MOUSE_PS2PLUS_ZNEG
value|0x08
end_define

begin_comment
comment|/* MouseMan+ negative wheel movement */
end_comment

begin_comment
comment|/* sysmouse extended data packet */
end_comment

begin_comment
comment|/*  * /dev/sysmouse sends data in two formats, depending on the protocol  * level.  At the level 0, format is exactly the same as MousSystems'  * five byte packet.  At the level 1, the first five bytes are the same  * as at the level 0.  There are additional three bytes which shows  * `dz' and the states of additional buttons.  `dz' is expressed as the  * sum of the byte 5 and 6 which contain signed seven bit values.  * The states of the button 4 though 10 are in the bit 0 though 6 in   * the byte 7 respectively: 1 indicates the button is up.  */
end_comment

begin_define
define|#
directive|define
name|MOUSE_SYS_PACKETSIZE
value|8
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_SYNCMASK
value|0xf8
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_SYNC
value|0x80
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON1UP
value|0x04
end_define

begin_comment
comment|/* left, 1st byte */
end_comment

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON2UP
value|0x02
end_define

begin_comment
comment|/* middle, 1st byte */
end_comment

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON3UP
value|0x01
end_define

begin_comment
comment|/* right, 1st byte */
end_comment

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON4UP
value|0x0001
end_define

begin_comment
comment|/* 7th byte */
end_comment

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON5UP
value|0x0002
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON6UP
value|0x0004
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON7UP
value|0x0008
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON8UP
value|0x0010
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON9UP
value|0x0020
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_BUTTON10UP
value|0x0040
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_MAXBUTTON
value|10
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_STDBUTTONS
value|0x07
end_define

begin_define
define|#
directive|define
name|MOUSE_SYS_EXTBUTTONS
value|0x7f
end_define

begin_comment
comment|/* the others */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MOUSE_H_ */
end_comment

end_unit

