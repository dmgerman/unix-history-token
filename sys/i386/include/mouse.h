begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993 Erik Forsberg.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL I BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: mouse.h,v 1.7 1997/02/22 09:34:50 peter Exp $  */
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
comment|/*  * NOTE: MOUSEIOC, MOUSEIOCREAD, and mouseinfo are now obsolete,   * but will stay for compatibility reasons. But, remember,   * the MOUSEIOCREAD ioctl command doesn't work and never worked before.    * Some day we shall get rid of these...   */
end_comment

begin_define
define|#
directive|define
name|MOUSEIOC
value|('M'<<8)
end_define

begin_define
define|#
directive|define
name|MOUSEIOCREAD
value|(MOUSEIOC|60)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mouseinfo
block|{
name|unsigned
name|char
name|status
decl_stmt|;
name|char
name|xmotion
decl_stmt|;
name|char
name|ymotion
decl_stmt|;
block|}
name|mouseinfo_t
typedef|;
end_typedef

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|BUTSTATMASK
value|0x07
end_define

begin_comment
comment|/* Any mouse button down if any bit set */
end_comment

begin_define
define|#
directive|define
name|BUTCHNGMASK
value|0x38
end_define

begin_comment
comment|/* Any mouse button changed if any bit set */
end_comment

begin_define
define|#
directive|define
name|BUT3STAT
value|0x01
end_define

begin_comment
comment|/* Button 3 down if set */
end_comment

begin_define
define|#
directive|define
name|BUT2STAT
value|0x02
end_define

begin_comment
comment|/* Button 2 down if set */
end_comment

begin_define
define|#
directive|define
name|BUT1STAT
value|0x04
end_define

begin_comment
comment|/* Button 1 down if set */
end_comment

begin_define
define|#
directive|define
name|BUT3CHNG
value|0x08
end_define

begin_comment
comment|/* Button 3 changed if set */
end_comment

begin_define
define|#
directive|define
name|BUT2CHNG
value|0x10
end_define

begin_comment
comment|/* Button 2 changed if set */
end_comment

begin_define
define|#
directive|define
name|BUT1CHNG
value|0x20
end_define

begin_comment
comment|/* Button 1 changed if set */
end_comment

begin_define
define|#
directive|define
name|MOVEMENT
value|0x40
end_define

begin_comment
comment|/* Mouse movement detected */
end_comment

begin_define
define|#
directive|define
name|MOUSE_GETSTATE
value|_IOR('M',0,mousestatus_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_GETHWINFO
value|_IOR('M',1,mousehw_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_GETMODE
value|_IOR('M',2,mousemode_t)
end_define

begin_define
define|#
directive|define
name|MOUSE_SETMODE
value|_IOW('M',3,mousemode_t)
end_define

begin_comment
comment|/* new ioctls */
end_comment

begin_comment
comment|/* mouse status block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mousestatus
block|{
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
value|0x00f8
end_define

begin_comment
comment|/* the others */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mousehw
block|{
name|int
name|buttons
decl_stmt|;
name|int
name|iftype
decl_stmt|;
comment|/* MOUSE_IF_XXX */
name|int
name|type
decl_stmt|;
comment|/* mouse/track ball/pad... */
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
comment|/* 1:low, 2:medium low, 3:medium high 				 * 4:high, 0: default, -1 if unknown  				 */
name|int
name|accelfactor
decl_stmt|;
comment|/* accelation factor (must be 1 or greater) */
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
comment|/* MS/ATI inport mouse */
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
comment|/* middle button, in the 4th byte */
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
value|0x08
end_define

begin_comment
comment|/* 0x0c for 2 button mouse */
end_comment

begin_define
define|#
directive|define
name|MOUSE_PS2_SYNC
value|0x08
end_define

begin_comment
comment|/* 0x0c for 2 button mouse */
end_comment

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
name|MOUSE_PS2_BUTTON4UP
value|0x08
end_define

begin_comment
comment|/* GlidePoint tapping feature  					 * Yes! this is the same bit as SYNC! 					 */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MOUSE_H_ */
end_comment

end_unit

