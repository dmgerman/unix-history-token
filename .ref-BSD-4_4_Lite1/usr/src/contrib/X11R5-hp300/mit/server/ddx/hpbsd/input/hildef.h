begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HILDEF_H
end_ifndef

begin_define
define|#
directive|define
name|HILDEF_H
end_define

begin_comment
comment|/* $Header: /host/kaukau/disk2/X11R5/R5-hp300/mit/server/ddx/hpbsd/input/RCS/hildef.h,v 1.1 1992/09/30 03:14:10 root Exp $ */
end_comment

begin_comment
comment|/*  Copyright (c) 1986, 1987 by Hewlett-Packard Company Copyright (c) 1986, 1987 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS SOFWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE.  Hewlett-Packard shall not be liable for errors  contained herein or direct, indirect, special, incidental or  consequential damages in connection with the furnishing,  performance, or use of this material.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_comment
comment|/* ** 	File: hildefs.h ** **	 defines for hil devices to the X environment. ** */
end_comment

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_include
include|#
directive|include
file|"X.h"
end_include

begin_include
include|#
directive|include
file|"scrnintstr.h"
end_include

begin_include
include|#
directive|include
file|"misc.h"
end_include

begin_include
include|#
directive|include
file|"dixstruct.h"
end_include

begin_comment
comment|/***************************************************************/
end_comment

begin_comment
comment|/* KEEP THE FOLLOWING IN SYNC WITH THE DIX DEFINITION          */
end_comment

begin_comment
comment|/***************************************************************/
end_comment

begin_if
if|#
directive|if
operator|(
name|NOFILE
operator|<=
literal|128
operator|)
end_if

begin_comment
comment|/* 128 is value of MAXCLIENTS in dix layer */
end_comment

begin_define
define|#
directive|define
name|MAXSOCKS
value|(NOFILE - 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXSOCKS
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mskcnt
value|((MAXSOCKS + 31) / 32)
end_define

begin_comment
comment|/* size of bit array */
end_comment

begin_define
define|#
directive|define
name|READ_SIZ
value|2000
end_define

begin_comment
comment|/* leave room for partial packets*/
end_comment

begin_define
define|#
directive|define
name|BUF_SIZ
value|2048
end_define

begin_comment
comment|/* size of static buffer to use  */
end_comment

begin_define
define|#
directive|define
name|MAX_X_NAMELEN
value|64
end_define

begin_define
define|#
directive|define
name|MAX_AXES
value|8
end_define

begin_define
define|#
directive|define
name|ILLEGAL
value|-1
end_define

begin_define
define|#
directive|define
name|UP_MASK
value|1<< 0
end_define

begin_define
define|#
directive|define
name|HIL_POLL_HDR_BITS
value|0xE3
end_define

begin_define
define|#
directive|define
name|MOTION_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|KEY_DATA_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|SET1_KEY_MASK
value|1<< 6
end_define

begin_define
define|#
directive|define
name|PROXIMITY_IN
value|0x8e
end_define

begin_define
define|#
directive|define
name|PROXIMITY_OUT
value|0x8f
end_define

begin_define
define|#
directive|define
name|BUTTON_BASE
value|0x80
end_define

begin_define
define|#
directive|define
name|BUTTON_1_OFFSET
value|0x7e
end_define

begin_define
define|#
directive|define
name|VERTICAL
value|0
end_define

begin_define
define|#
directive|define
name|HORIZONTAL
value|1
end_define

begin_define
define|#
directive|define
name|MATRIX
value|2
end_define

begin_define
define|#
directive|define
name|NOWRAP
value|0
end_define

begin_define
define|#
directive|define
name|WRAP
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT
value|2
end_define

begin_define
define|#
directive|define
name|SAMESCREEN
value|3
end_define

begin_define
define|#
directive|define
name|CHANGE_BY_TWO
value|4
end_define

begin_define
define|#
directive|define
name|CHORDING_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CHORDING_ON
value|1
end_define

begin_define
define|#
directive|define
name|CHORDING_DEFAULT
value|2
end_define

begin_define
define|#
directive|define
name|LATCHING_OFF
value|0
end_define

begin_define
define|#
directive|define
name|LATCHING_ON
value|1
end_define

begin_define
define|#
directive|define
name|SCREEN_CHANGE_DEFAULT
value|255
end_define

begin_define
define|#
directive|define
name|IS_SERIAL_DEVICE
value|0x40
end_define

begin_define
define|#
directive|define
name|OPEN_THIS_DEVICE
value|0x20
end_define

begin_define
define|#
directive|define
name|SECOND_LOGICAL_DEVICE
value|0x10
end_define

begin_define
define|#
directive|define
name|MERGED_DEVICE
value|0x08
end_define

begin_define
define|#
directive|define
name|DATA_SIZE_BITS
value|0x07
end_define

begin_define
define|#
directive|define
name|HIL_ABSOLUTE
value|0x40
end_define

begin_comment
comment|/* Device has absolute positioning data */
end_comment

begin_define
define|#
directive|define
name|HIL_16_BITS
value|0x20
end_define

begin_comment
comment|/* Device has position data 16 bit accuracy */
end_comment

begin_define
define|#
directive|define
name|HIL_IOB
value|0x10
end_define

begin_comment
comment|/* Device has I/O description byte */
end_comment

begin_define
define|#
directive|define
name|HIL_NUM_AXES
value|0x03
end_define

begin_comment
comment|/* Number of axes supported */
end_comment

begin_define
define|#
directive|define
name|HAS_LEDS
value|0xf0
end_define

begin_comment
comment|/* Device has leds                        */
end_comment

begin_define
define|#
directive|define
name|HILIOB_PAA
value|0x80
end_define

begin_comment
comment|/* Device supports prompt and acknowledge */
end_comment

begin_define
define|#
directive|define
name|HILIOB_NPA
value|0x70
end_define

begin_comment
comment|/* Number of prompts& acknowledges supported */
end_comment

begin_define
define|#
directive|define
name|HILIOB_PIO
value|0x08
end_define

begin_comment
comment|/* Device supports Proximity In/Out */
end_comment

begin_define
define|#
directive|define
name|HILIOB_BUTTONS
value|0x07
end_define

begin_comment
comment|/* Number of buttons on device */
end_comment

begin_define
define|#
directive|define
name|HILPRH_KEYSET
value|0x60
end_define

begin_comment
comment|/* Keycode set bits            */
end_comment

begin_define
define|#
directive|define
name|HILPRH_KEYSET1
value|0x40
end_define

begin_comment
comment|/* Keycode set 1 data          */
end_comment

begin_define
define|#
directive|define
name|NLOCK
value|3
end_define

begin_define
define|#
directive|define
name|CAPSCODE
value|0x37
end_define

begin_define
define|#
directive|define
name|KBSIZE
value|32
end_define

begin_comment
comment|/* bytes to hold 256 bits (1 per key/button */
end_comment

begin_define
define|#
directive|define
name|LedOn
parameter_list|(
name|dev
parameter_list|,
name|d
parameter_list|,
name|cd
parameter_list|,
name|data
parameter_list|)
define|\
value|(dev->key->modifierMap[cd]& d->led[0] ? ioctl(d->file_ds,LedCmd[0].on,data) : \  dev->key->modifierMap[cd]& d->led[1] ? ioctl(d->file_ds,LedCmd[1].on,data) : \  dev->key->modifierMap[cd]& d->led[2] ? ioctl(d->file_ds,LedCmd[2].on,data) : \  ioctl(d->file_ds, LedCmd[3].on, data))
end_define

begin_define
define|#
directive|define
name|LedOff
parameter_list|(
name|dev
parameter_list|,
name|d
parameter_list|,
name|cd
parameter_list|,
name|data
parameter_list|)
define|\
value|(dev->key->modifierMap[cd]& d->led[0] ? ioctl(d->file_ds,LedCmd[0].off,data): \  dev->key->modifierMap[cd]& d->led[1] ? ioctl(d->file_ds,LedCmd[1].off,data): \  dev->key->modifierMap[cd]& d->led[2] ? ioctl(d->file_ds,LedCmd[2].off,data): \  ioctl(d->file_ds, LedCmd[3].off, data))
end_define

begin_define
define|#
directive|define
name|LatchKey
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(d->kb_latched[code>>3] |= (1<<(code& 7)))
end_define

begin_define
define|#
directive|define
name|LatchButton
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(LatchKey(d,code))
end_define

begin_define
define|#
directive|define
name|UnlatchKey
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(d->kb_latched[code>>3]&= ~(1<<(code& 7)))
end_define

begin_define
define|#
directive|define
name|UnlatchButton
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(UnlatchKey(d,code))
end_define

begin_define
define|#
directive|define
name|DeviceHasLeds
parameter_list|(
name|d
parameter_list|)
value|(d->hil_header.iob& HILIOB_NPA)
end_define

begin_define
define|#
directive|define
name|KeyHasLed
parameter_list|(
name|dev
parameter_list|,
name|d
parameter_list|,
name|cd
parameter_list|)
value|((dev->key->modifierMap[cd]& d->led[0]) || \ (dev->key->modifierMap[cd]& d->led[1]) || \ (dev->key->modifierMap[cd]& d->led[2]) || \ (dev->key->modifierMap[cd]& d->led[3]))
end_define

begin_define
define|#
directive|define
name|KeyIsLatched
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(d->kb_latched[code>>3]& (1<<(code& 7)))
end_define

begin_define
define|#
directive|define
name|KeyIsIgnored
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(d->kb_ignore[code>>3]& (1<<(code& 7)))
end_define

begin_define
define|#
directive|define
name|IgnoreKey
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(d->kb_ignore[code>>3] |= (1<<(code& 7)))
end_define

begin_define
define|#
directive|define
name|UnignoreKey
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(d->kb_ignore[code>>3]&= ~(1<<(code& 7)))
end_define

begin_define
define|#
directive|define
name|ButtonIsLatched
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(KeyIsLatched(d,code))
end_define

begin_define
define|#
directive|define
name|ButtonIsIgnored
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(KeyIsIgnored(d,code))
end_define

begin_define
define|#
directive|define
name|IgnoreButton
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(IgnoreKey(d,code))
end_define

begin_define
define|#
directive|define
name|UnignoreButton
parameter_list|(
name|d
parameter_list|,
name|code
parameter_list|)
value|(UnignoreKey(d,code))
end_define

begin_define
define|#
directive|define
name|KeyDownEvent
parameter_list|(
name|ev
parameter_list|)
value|(ev->u.u.type==KeyPress | ev->u.u.type==DeviceKeyPress)
end_define

begin_define
define|#
directive|define
name|ButtonDownEvent
parameter_list|(
name|ev
parameter_list|)
value|(ev->u.u.type==ButtonPress | \ 			     ev->u.u.type==DeviceButtonPress)
end_define

begin_define
define|#
directive|define
name|KeyUpEvent
parameter_list|(
name|ev
parameter_list|)
value|(ev->u.u.type==KeyRelease | \ 			     ev->u.u.type==DeviceKeyRelease)
end_define

begin_define
define|#
directive|define
name|IsLockKey
parameter_list|(
name|dev
parameter_list|,
name|code
parameter_list|)
value|(dev->key->modifierMap[code]& LockMask)
end_define

begin_define
define|#
directive|define
name|KeyIsDown
parameter_list|(
name|dev
parameter_list|,
name|code
parameter_list|)
value|(dev->key&& \     (dev->key->down[code>> 3]& (1<< (code& 7))))
end_define

begin_define
define|#
directive|define
name|KeyIsRepeating
parameter_list|(
name|dev
parameter_list|,
name|code
parameter_list|)
value|(dev->kbdfeed&& \     (dev->kbdfeed->ctrl.autoRepeat || \     (dev->kbdfeed->ctrl.autoRepeats[code>> 3]& (1<< (code& 7)))))
end_define

begin_struct
struct|struct
name|hil_desc_record
block|{
name|int
name|resx
decl_stmt|;
comment|/* x-axis counts / meter	*/
name|int
name|resy
decl_stmt|;
comment|/* x-axis counts / meter	*/
name|int
name|size_x
decl_stmt|;
comment|/* maximum x value   		*/
name|int
name|size_y
decl_stmt|;
comment|/* maximum y value   		*/
name|u_char
name|flags
decl_stmt|;
comment|/* device characteristics	*/
name|u_char
name|ax_num
decl_stmt|;
comment|/* number of axes		*/
name|u_short
name|min_kcode
decl_stmt|;
comment|/* minimum keycode           	*/
name|u_short
name|max_kcode
decl_stmt|;
comment|/* maximum keycode           	*/
name|u_char
name|id
decl_stmt|;
comment|/* device HIL id		*/
name|u_char
name|iob
decl_stmt|;
comment|/* I/O descriptor Byte 		*/
name|u_char
name|p_button_count
decl_stmt|;
comment|/* count of physical buttons 	*/
name|u_char
name|v_button_count
decl_stmt|;
comment|/* count of virtual buttons  	*/
name|u_char
name|num_keys
decl_stmt|;
comment|/* number of keys            	*/
name|u_char
name|num_leds
decl_stmt|;
comment|/* number of leds            	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_DeviceClients
modifier|*
name|DeviceClientsPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DeviceClients
block|{
name|DeviceClientsPtr
name|next
decl_stmt|;
name|ClientPtr
name|client
decl_stmt|;
comment|/* which client wants this device       */
name|XID
name|resource
decl_stmt|;
comment|/* id for putting into resource manager */
name|int
name|mode
decl_stmt|;
name|int
name|count
decl_stmt|;
comment|/* # of open requests for this client   */
block|}
name|DeviceClients
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_indevices
block|{
name|struct
name|hil_desc_record
name|hil_header
decl_stmt|;
comment|/* HIL hdr 	*/
name|float
name|scaleX
decl_stmt|;
comment|/* Tablet scaling 		*/
name|float
name|scaleY
decl_stmt|;
comment|/* Tablet scaling 		*/
name|int
name|file_ds
decl_stmt|;
comment|/* file descriptor              */
name|DeviceClientsPtr
name|clients
decl_stmt|;
comment|/* clients using device 	*/
name|ScreenPtr
name|pScreen
decl_stmt|;
comment|/* Screen pointer is on         */
name|int
name|repeat_rate
decl_stmt|;
comment|/* keyboard repeat rate         */
name|int
name|coords
index|[
name|MAX_AXES
index|]
decl_stmt|;
comment|/* current coords of device    */
name|Atom
name|x_atom
decl_stmt|;
comment|/* atom for x type		*/
name|u_int
name|button_state
decl_stmt|;
comment|/* device button state          */
name|int
name|change_xmax
decl_stmt|;
name|int
name|change_ymax
decl_stmt|;
name|int
name|change_ymin
decl_stmt|;
name|int
name|change_xmin
decl_stmt|;
name|short
name|change_amt
decl_stmt|;
name|short
name|id_detail
decl_stmt|;
name|u_char
name|dev_type
decl_stmt|;
comment|/* HIL device type		*/
name|u_char
name|sent_button
decl_stmt|;
comment|/* flag for button sent		*/
name|u_char
name|ignoremask
decl_stmt|;
comment|/* for button emulation         */
name|u_char
name|savebutton
decl_stmt|;
comment|/* saved button			*/
name|char
name|x_type
decl_stmt|;
comment|/* MOUSE or KEYBOARD		*/
name|u_char
name|dev_id
decl_stmt|;
comment|/* device X id			*/
name|u_char
name|mode
decl_stmt|;
comment|/* abs or rel movement  	*/
name|u_char
name|pad0
decl_stmt|;
comment|/* X event on button or key up  */
name|u_char
name|pad1
decl_stmt|;
comment|/* X event on button or key dn  */
name|u_char
name|pad2
decl_stmt|;
comment|/* X event on motion		*/
name|char
name|open_cnt
decl_stmt|;
comment|/* # clients accessing device   */
name|char
name|dev_name
index|[
name|MAX_X_NAMELEN
index|]
decl_stmt|;
name|char
name|x_name
index|[
name|MAX_X_NAMELEN
index|]
decl_stmt|;
name|u_char
name|bell1
index|[
literal|4
index|]
decl_stmt|;
comment|/* arrays for the s300 beeper params */
name|u_char
name|bell2
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|bell3
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|hpflags
decl_stmt|;
comment|/* hp-specific feature flags    */
name|u_char
name|led
index|[
name|NLOCK
operator|+
literal|1
index|]
decl_stmt|;
name|u_char
name|kb_latched
index|[
name|KBSIZE
index|]
decl_stmt|;
name|u_char
name|kb_ignore
index|[
name|KBSIZE
index|]
decl_stmt|;
block|}
name|HPInputDevice
typedef|;
end_typedef

begin_struct
struct|struct
name|dev_info
block|{
name|unsigned
name|int
name|timestamp
decl_stmt|;
name|unsigned
name|char
name|poll_hdr
decl_stmt|;
name|unsigned
name|char
name|dev_data
index|[
literal|36
index|]
decl_stmt|;
name|HPInputDevice
modifier|*
name|hil_dev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|inputs_selected
block|{
name|long
name|input_mask
index|[
name|mskcnt
index|]
decl_stmt|;
name|int
name|max_fd
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

