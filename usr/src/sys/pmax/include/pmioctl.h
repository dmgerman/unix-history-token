begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)pmioctl.h	7.1 (Berkeley) %G%  *  * graphics.h --  *  *     	Defines for the graphics device.  *  * Copyright (C) 1989 by Digital Equipment Corporation, Maynard MA  *  *			All Rights Reserved  *  * Permission to use, copy, modify, and distribute this software and its   * documentation for any purpose and without fee is hereby granted,   * provided that the above copyright notice appear in all copies and that  * both that copyright notice and this permission notice appear in   * supporting documentation, and that the name of Digital not be  * used in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.    *  * Digitial disclaims all warranties with regard to this software, including  * all implied warranties of merchantability and fitness.  In no event shall  * Digital be liable for any special, indirect or consequential damages or  * any damages whatsoever resulting from loss of use, data or profits,  * whether in an action of contract, negligence or other tortious action,  * arising out of or in connection with the use or performance of this  * software.  *  * from: $Header: devSerialPmax.c,  *	v 1.4 89/05/22 13:31:07 mnelson Exp $ SPRITE (DECWRL)  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/*  * Events.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|;
comment|/* x position */
name|short
name|y
decl_stmt|;
comment|/* y position */
name|unsigned
name|int
name|time
decl_stmt|;
comment|/* 1 millisecond units */
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* button up/down/raw or motion */
name|unsigned
name|char
name|key
decl_stmt|;
comment|/* the key (button only) */
name|unsigned
name|char
name|index
decl_stmt|;
comment|/* which instance of device */
name|unsigned
name|char
name|device
decl_stmt|;
comment|/* which device */
block|}
name|pmEvent
typedef|;
end_typedef

begin_comment
comment|/*  * type field  */
end_comment

begin_define
define|#
directive|define
name|BUTTON_UP_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|BUTTON_DOWN_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|BUTTON_RAW_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|MOTION_TYPE
value|3
end_define

begin_comment
comment|/*  * device field  */
end_comment

begin_define
define|#
directive|define
name|NULL_DEVICE
value|0
end_define

begin_comment
comment|/* NULL event (for QD_GETEVENT ret) */
end_comment

begin_define
define|#
directive|define
name|MOUSE_DEVICE
value|1
end_define

begin_comment
comment|/* mouse */
end_comment

begin_define
define|#
directive|define
name|KEYBOARD_DEVICE
value|2
end_define

begin_comment
comment|/* main keyboard */
end_comment

begin_define
define|#
directive|define
name|TABLET_DEVICE
value|3
end_define

begin_comment
comment|/* graphics tablet */
end_comment

begin_define
define|#
directive|define
name|AUX_DEVICE
value|4
end_define

begin_comment
comment|/* auxiliary */
end_comment

begin_define
define|#
directive|define
name|CONSOLE_DEVICE
value|5
end_define

begin_comment
comment|/* console */
end_comment

begin_define
define|#
directive|define
name|KNOB_DEVICE
value|8
end_define

begin_define
define|#
directive|define
name|JOYSTICK_DEVICE
value|9
end_define

begin_define
define|#
directive|define
name|PM_MAXEVQ
value|64
end_define

begin_comment
comment|/* must be power of 2 */
end_comment

begin_define
define|#
directive|define
name|PM_EVROUND
parameter_list|(
name|x
parameter_list|)
value|((x)& (PM_MAXEVQ - 1))
end_define

begin_define
define|#
directive|define
name|MOTION_BUFFER_SIZE
value|100
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|time
decl_stmt|;
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|pmTimeCoord
typedef|;
end_typedef

begin_comment
comment|/*  * The event queue. This structure is normally included in the info  * returned by the device driver.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|pmEvent
modifier|*
name|events
decl_stmt|;
name|unsigned
name|int
name|eSize
decl_stmt|;
name|unsigned
name|int
name|eHead
decl_stmt|;
name|unsigned
name|int
name|eTail
decl_stmt|;
name|unsigned
name|long
name|timestamp_ms
decl_stmt|;
name|pmTimeCoord
modifier|*
name|tcs
decl_stmt|;
comment|/* history of pointer motions */
name|unsigned
name|int
name|tcSize
decl_stmt|;
name|unsigned
name|int
name|tcNext
decl_stmt|;
comment|/* simple ring buffer, old events are tossed */
block|}
name|pmEventQueue
typedef|;
end_typedef

begin_comment
comment|/*  * mouse cursor position  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|pmCursor
typedef|;
end_typedef

begin_comment
comment|/*  * mouse motion rectangle  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|bottom
decl_stmt|;
name|short
name|right
decl_stmt|;
name|short
name|left
decl_stmt|;
name|short
name|top
decl_stmt|;
block|}
name|pmBox
typedef|;
end_typedef

begin_comment
comment|/*  * Structures used by ioctl's.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pm_kpcmd
block|{
name|char
name|nbytes
decl_stmt|;
comment|/* number of bytes in parameter */
name|unsigned
name|char
name|cmd
decl_stmt|;
comment|/* command to be sent, peripheral bit will */
comment|/* be forced by driver */
name|unsigned
name|char
name|par
index|[
literal|2
index|]
decl_stmt|;
comment|/* bytes of parameters to be sent */
block|}
name|pmKpCmd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pm_info
block|{
name|pmEventQueue
name|qe
decl_stmt|;
comment|/* event& motion queues	*/
name|short
name|mswitches
decl_stmt|;
comment|/* current value of mouse buttons */
name|pmCursor
name|tablet
decl_stmt|;
comment|/* current tablet position	*/
name|short
name|tswitches
decl_stmt|;
comment|/* current tablet buttons NI!	*/
name|pmCursor
name|cursor
decl_stmt|;
comment|/* current cursor position	*/
name|short
name|row
decl_stmt|;
comment|/* screen row			*/
name|short
name|col
decl_stmt|;
comment|/* screen col			*/
name|short
name|max_row
decl_stmt|;
comment|/* max character row		*/
name|short
name|max_col
decl_stmt|;
comment|/* max character col		*/
name|short
name|max_x
decl_stmt|;
comment|/* max x position		*/
name|short
name|max_y
decl_stmt|;
comment|/* max y position		*/
name|short
name|max_cur_x
decl_stmt|;
comment|/* max cursor x position 	*/
name|short
name|max_cur_y
decl_stmt|;
comment|/* max cursor y position	*/
name|int
name|version
decl_stmt|;
comment|/* version of driver		*/
name|char
modifier|*
name|bitmap
decl_stmt|;
comment|/* bit map position		*/
name|short
modifier|*
name|scanmap
decl_stmt|;
comment|/* scanline map position        */
name|short
modifier|*
name|cursorbits
decl_stmt|;
comment|/* cursor bit position		*/
name|short
modifier|*
name|pmaddr
decl_stmt|;
comment|/* virtual address           	*/
name|char
modifier|*
name|planemask
decl_stmt|;
comment|/* plane mask virtual location  */
name|pmCursor
name|mouse
decl_stmt|;
comment|/* atomic read/write		*/
name|pmBox
name|mbox
decl_stmt|;
comment|/* atomic read/write		*/
name|short
name|mthreshold
decl_stmt|;
comment|/* mouse motion parameter	*/
name|short
name|mscale
decl_stmt|;
comment|/* mouse scale factor (if  					   negative, then do square).	*/
name|short
name|min_cur_x
decl_stmt|;
comment|/* min cursor x position	*/
name|short
name|min_cur_y
decl_stmt|;
comment|/* min cursor y position	*/
block|}
name|PM_Info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|Map
decl_stmt|;
name|unsigned
name|short
name|index
decl_stmt|;
struct|struct
block|{
name|unsigned
name|short
name|red
decl_stmt|;
name|unsigned
name|short
name|green
decl_stmt|;
name|unsigned
name|short
name|blue
decl_stmt|;
block|}
name|Entry
struct|;
block|}
name|ColorMap
typedef|;
end_typedef

begin_comment
comment|/*  * CAUTION:  *	The numbers of these ioctls must match  *	the ioctls in qvioctl.h  */
end_comment

begin_define
define|#
directive|define
name|QIOCGINFO
value|_IOR('q', 1, struct pm_info *)
end_define

begin_comment
comment|/* get the info	 */
end_comment

begin_define
define|#
directive|define
name|QIOCPMSTATE
value|_IOW('q', 2, pmCursor)
end_define

begin_comment
comment|/* set mouse pos */
end_comment

begin_define
define|#
directive|define
name|QIOWCURSORCOLOR
value|_IOW('q', 3, unsigned int [6])
end_define

begin_comment
comment|/* bg/fg r/g/b */
end_comment

begin_define
define|#
directive|define
name|QIOCINIT
value|_IO('q', 4)
end_define

begin_comment
comment|/* init screen   */
end_comment

begin_define
define|#
directive|define
name|QIOCKPCMD
value|_IOW('q', 5, struct pm_kpcmd)
end_define

begin_comment
comment|/* keybd. per. cmd */
end_comment

begin_define
define|#
directive|define
name|QIOCADDR
value|_IOR('q', 6, struct pm_info *)
end_define

begin_comment
comment|/* get address */
end_comment

begin_define
define|#
directive|define
name|QIOWCURSOR
value|_IOW('q', 7, short [32])
end_define

begin_comment
comment|/* write cursor bit map */
end_comment

begin_define
define|#
directive|define
name|QIOKERNLOOP
value|_IO('q', 8)
end_define

begin_comment
comment|/* re-route kernel console output */
end_comment

begin_define
define|#
directive|define
name|QIOKERNUNLOOP
value|_IO('q', 9)
end_define

begin_comment
comment|/* don't re-route kernel console output */
end_comment

begin_define
define|#
directive|define
name|QIOVIDEOON
value|_IO('q', 10)
end_define

begin_comment
comment|/* turn on the video */
end_comment

begin_define
define|#
directive|define
name|QIOVIDEOOFF
value|_IO('q', 11)
end_define

begin_comment
comment|/* turn off the video */
end_comment

begin_define
define|#
directive|define
name|QIOSETCMAP
value|_IOW('q', 12, ColorMap)
end_define

end_unit

