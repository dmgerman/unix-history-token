begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)dtopreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1992 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log:	dtop.h,v $  * Revision 2.3  92/03/05  17:08:17  rpd  * 	Define how many buttons and coordinates we can take.  * 	[92/03/05            af]  *   * Revision 2.2  92/03/02  18:32:17  rpd  * 	Created from DEC specs:  * 	"DESKTOPinterconnect Description and Protocol Specification"  * 	Version 0.9, Jun 17 1991  * 	"Open Desktop Bus, Locator Device Protocol Specification"  * 	Version 0.4, Dec 13 1990  * 	"Open Desktop Bus, Keyboard Device Protocol Specification"  * 	Version 0.7, Jan 9 1991  * 	[92/01/19            af]  *   */
end_comment

begin_comment
comment|/*  *	File: dtop.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	1/92  *  *	Definitions for the Desktop serial bus (i2c aka ACCESS).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DTOP_H_
end_ifndef

begin_define
define|#
directive|define
name|_DTOP_H_
end_define

begin_define
define|#
directive|define
name|DTOP_MAX_DEVICES
value|14
end_define

begin_define
define|#
directive|define
name|DTOP_MAX_MSG_SIZE
value|36
end_define

begin_comment
comment|/* 3 hdr + 32 data + 1 checksum */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|dest_address
decl_stmt|;
comment|/* low bit is zero */
name|unsigned
name|char
name|src_address
decl_stmt|;
comment|/* ditto */
union|union
block|{
struct|struct
block|{
name|unsigned
name|char
name|len
range|:
literal|5
decl_stmt|,
comment|/* message byte len */
name|sub
range|:
literal|2
decl_stmt|,
comment|/* sub-address */
name|P
range|:
literal|1
decl_stmt|;
comment|/* Control(1)/Data(0) marker */
block|}
name|val
struct|;
name|unsigned
name|char
name|bits
decl_stmt|;
comment|/* quick check */
block|}
name|code
union|;
comment|/* varzise, checksum byte at end */
name|unsigned
name|char
name|body
index|[
name|DTOP_MAX_MSG_SIZE
operator|-
literal|3
index|]
decl_stmt|;
block|}
name|dtop_message
operator|,
typedef|*
name|dtop_message_t
typedef|;
end_typedef

begin_comment
comment|/*  * Standard addresses  */
end_comment

begin_define
define|#
directive|define
name|DTOP_ADDR_HOST
value|0x50
end_define

begin_comment
comment|/* address for the (only) host */
end_comment

begin_define
define|#
directive|define
name|DTOP_ADDR_DEFAULT
value|0x6e
end_define

begin_comment
comment|/* power-up default address */
end_comment

begin_define
define|#
directive|define
name|DTOP_ADDR_FIRST
value|0x52
end_define

begin_comment
comment|/* first assignable address */
end_comment

begin_define
define|#
directive|define
name|DTOP_ADDR_LAST
value|0x6c
end_define

begin_comment
comment|/* last, inclusive */
end_comment

begin_comment
comment|/*  * Standard messages  */
end_comment

begin_comment
comment|/* from host to devices */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_RESET
value|0xf0
end_define

begin_comment
comment|/* preceeded by 0x81: P,len 1 */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_ID_REQUEST
value|0xf1
end_define

begin_comment
comment|/* preceeded by 0x81: P,len 1 */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_ASSIGN_ADDRESS
value|0xf2
end_define

begin_comment
comment|/* preceeded by 0x9e: P,len 30 */
end_comment

begin_comment
comment|/* followed by a dtop_id_reply_t */
end_comment

begin_comment
comment|/* and by the new_IC_address */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_CAP_REQUEST
value|0xf3
end_define

begin_comment
comment|/* preceeded by 0x83: P,len 3 */
end_comment

begin_comment
comment|/* followed by a 16 bit u_offset */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_APPL_TEST
value|0xb1
end_define

begin_comment
comment|/* preceed by P, sub, len 1 */
end_comment

begin_comment
comment|/* from devices to host */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_ATTENTION
value|0xe0
end_define

begin_comment
comment|/* preceeded by P, len */
end_comment

begin_define
define|#
directive|define
name|DTOP_ATN_OK_STATUS
value|0x00
end_define

begin_comment
comment|/* anything else bad */
end_comment

begin_comment
comment|/* followed by 0-30 bytes */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_ID_REPLY
value|0xe1
end_define

begin_comment
comment|/* preceeded by P,len (29..32) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|module_revision
index|[
literal|8
index|]
decl_stmt|;
comment|/* ascii, blank padded */
name|unsigned
name|char
name|vendor_name
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|module_name
index|[
literal|8
index|]
decl_stmt|;
name|int
name|device_number
decl_stmt|;
comment|/* 32 bits cpl-2 */
comment|/* 0-3 optional bytes follow, ignore */
block|}
name|dtop_id_reply_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DTOP_MSG_CAP_REPLY
value|0xe3
end_define

begin_comment
comment|/* preceeded by P,len (3..32) */
end_comment

begin_comment
comment|/* followed by 16 bit u_offset */
end_comment

begin_comment
comment|/* followed by data */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_APPL_SIGNAL
value|0xa0
end_define

begin_comment
comment|/* application level signal */
end_comment

begin_define
define|#
directive|define
name|DTOP_SIG_ATTENTION
value|0x00
end_define

begin_define
define|#
directive|define
name|DTOP_SIG_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|DTOP_SIG_HALT
value|0x02
end_define

begin_define
define|#
directive|define
name|DTOP_MSG_APPL_TREPLY
value|0xa1
end_define

begin_comment
comment|/* followed by status (0-->ok) */
end_comment

begin_comment
comment|/* and 0..30 bytes of result data  */
end_comment

begin_comment
comment|/* reserved message codes (testing, manifacturing) */
end_comment

begin_define
define|#
directive|define
name|DTOP_MSG_RES0
value|0xc0
end_define

begin_define
define|#
directive|define
name|DTOP_MSG_RES1
value|0xc1
end_define

begin_define
define|#
directive|define
name|DTOP_MSG_RES2
value|0xc2
end_define

begin_define
define|#
directive|define
name|DTOP_MSG_RES3
value|0xc3
end_define

begin_comment
comment|/*  *	Device specific definitions:  Keyboard  */
end_comment

begin_comment
comment|/* from host to keyboard */
end_comment

begin_define
define|#
directive|define
name|DTOP_KMSG_CLICK
value|0x01
end_define

begin_comment
comment|/* preceeded by P, sub len 2 */
end_comment

begin_define
define|#
directive|define
name|DTOP_CLICK_VOLUME_MAX
value|0x7
end_define

begin_comment
comment|/* followed by one byte */
end_comment

begin_define
define|#
directive|define
name|DTOP_KMSG_BELL
value|0x02
end_define

begin_comment
comment|/* preceeded by P, sub len 2 */
end_comment

begin_comment
comment|/* same as above */
end_comment

begin_define
define|#
directive|define
name|DTOP_KMSG_LED
value|0x03
end_define

begin_comment
comment|/* preceeded by P, sub len 2 */
end_comment

begin_comment
comment|/* four lower bits turn leds on */
end_comment

begin_define
define|#
directive|define
name|DTOP_KMSG_POLL
value|0x04
end_define

begin_comment
comment|/* preceeded by P, sub len 1 */
end_comment

begin_comment
comment|/* keyboard sends up to 11 codes in a data message, distinguished values: */
end_comment

begin_define
define|#
directive|define
name|DTOP_KBD_EMPTY
value|0x00
end_define

begin_define
define|#
directive|define
name|DTOP_KBD_OUT_ERR
value|0x01
end_define

begin_define
define|#
directive|define
name|DTOP_KBD_IN_ERR
value|0x02
end_define

begin_define
define|#
directive|define
name|DTOP_KBD_KEY_MIN
value|0x08
end_define

begin_define
define|#
directive|define
name|DTOP_KBD_KEY_MAX
value|0xff
end_define

begin_comment
comment|/* powerup status values: 0 ok, else.. */
end_comment

begin_define
define|#
directive|define
name|DTOP_KBD_ROM_FAIL
value|0x01
end_define

begin_define
define|#
directive|define
name|DTOP_KBD_RAM_FAIL
value|0x02
end_define

begin_define
define|#
directive|define
name|DTOP_KBD_KEY_DOWN
value|0x03
end_define

begin_comment
comment|/*  *	Device specific definitions:  Locators (mouse)  */
end_comment

begin_comment
comment|/* locator sends this type of report data */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|buttons
decl_stmt|;
comment|/* 1->pressed */
name|short
name|x
decl_stmt|;
name|short
name|y
decl_stmt|;
name|short
name|z
decl_stmt|;
comment|/* possibly 3 more dimensions for gloves */
block|}
name|dtop_locator_msg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DTOP_LMSG_SET_RATE
value|0x01
end_define

begin_comment
comment|/* preceeded by P,sub, len 2 */
end_comment

begin_comment
comment|/* followed by sampling interval, 					   from 8 to 25 msecs (0->polled */
end_comment

begin_define
define|#
directive|define
name|DTOP_LMSG_POLL
value|0x02
end_define

begin_comment
comment|/* preceeded by P,sub, len 1 */
end_comment

begin_comment
comment|/* Powerup codes same as keyboard */
end_comment

begin_comment
comment|/*  * Implementation specific definitions  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|dtop_message
name|unknown_report
decl_stmt|;
struct|struct
block|{
name|char
name|last_codes_count
decl_stmt|;
name|unsigned
name|char
name|last_codes
index|[
literal|11
index|]
decl_stmt|;
comment|/* max as per specs */
name|unsigned
name|int
name|last_msec
decl_stmt|;
comment|/* autorepeat state */
name|unsigned
name|short
name|poll_frequency
decl_stmt|;
name|unsigned
name|char
name|k_ar_state
decl_stmt|;
define|#
directive|define
name|K_AR_IDLE
value|0
comment|/* quiescent, no polling */
define|#
directive|define
name|K_AR_OFF
value|4
comment|/* turn off polling pls */
define|#
directive|define
name|K_AR_ACTIVE
value|2
comment|/* polling, no autos yet */
define|#
directive|define
name|K_AR_TRIGGER
value|1
comment|/* sent one autorepeat */
block|}
name|keyboard
struct|;
struct|struct
block|{
name|unsigned
name|char
name|type
range|:
literal|7
decl_stmt|,
comment|/* DEV_MOUSE, DEV_TABLET, .. */
name|relative
range|:
literal|1
decl_stmt|;
name|unsigned
name|char
name|n_coords
decl_stmt|;
name|unsigned
name|short
name|prev_buttons
decl_stmt|;
define|#
directive|define
name|L_BUTTON_MAX
value|16
name|unsigned
name|char
name|button_code
index|[
name|L_BUTTON_MAX
index|]
decl_stmt|;
define|#
directive|define
name|L_COORD_MAX
value|6
name|unsigned
name|int
name|coordinate
index|[
name|L_COORD_MAX
index|]
decl_stmt|;
comment|/* max 6D */
block|}
name|locator
struct|;
comment|/* add more as they come along */
block|}
name|dtop_device
operator|,
typedef|*
name|dtop_device_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DTOP_EVENT_RECEIVE_PACKET
value|1
end_define

begin_define
define|#
directive|define
name|DTOP_EVENT_BAD_PACKET
value|2
end_define

begin_define
define|#
directive|define
name|DTOP_EVENT_PUTC
value|4
end_define

begin_define
define|#
directive|define
name|DTOP_EVENT_POLL
value|8
end_define

begin_comment
comment|/*  * Device numbers.  */
end_comment

begin_define
define|#
directive|define
name|DTOPKBD_PORT
value|0
end_define

begin_define
define|#
directive|define
name|DTOPMOUSE_PORT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DTOP_H_ */
end_comment

end_unit

