begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vsio.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VSIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VSIO_H_
end_define

begin_comment
comment|/****************************************************************************  *									    *  *  Copyright (c) 1983, 1984 by						    *  *  DIGITAL EQUIPMENT CORPORATION, Maynard, Massachusetts.		    *  *  All rights reserved.						    *  * 									    *  *  This software is furnished on an as-is basis and may be used and copied *  *  only with inclusion of the above copyright notice. This software or any *  *  other copies thereof may be provided or otherwise made available to     *  *  others only for non-commercial purposes.  No title to or ownership of   *  *  the software is hereby transferred.					    *  * 									    *  *  The information in this software is  subject to change without notice   *  *  and  should  not  be  construed as  a commitment by DIGITAL EQUIPMENT   *  *  CORPORATION.							    *  * 									    *  *  DIGITAL assumes no responsibility for the use  or  reliability of its   *  *  software on equipment which is not supplied by DIGITAL.		    *  * 									    *  *									    *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * vsio.h - VS100 I/O command definitions  *  * Author:	Christopher A. Kent  *		Digital Equipment Corporation  *		Western Research Lab  * Date:	Tue Jun 21 1983  */
end_comment

begin_comment
comment|/*  * Possible ioctl calls  */
end_comment

begin_define
define|#
directive|define
name|VSIOINIT
value|_IO('V', 0)
end_define

begin_comment
comment|/* init the device */
end_comment

begin_define
define|#
directive|define
name|VSIOSTART
value|_IOW('V', 1, int)
end_define

begin_comment
comment|/* start microcode */
end_comment

begin_define
define|#
directive|define
name|VSIOABORT
value|_IO('V', 2)
end_define

begin_comment
comment|/* abort a command chain */
end_comment

begin_define
define|#
directive|define
name|VSIOPWRUP
value|_IO('V', 3)
end_define

begin_comment
comment|/* power-up reset */
end_comment

begin_define
define|#
directive|define
name|VSIOGETVER
value|_IOR('V', 4, int)
end_define

begin_comment
comment|/* get rom version */
end_comment

begin_define
define|#
directive|define
name|VSIOSYNC
value|_IO('V', 6)
end_define

begin_comment
comment|/* synch with device */
end_comment

begin_define
define|#
directive|define
name|VSIOBBACTL
value|_IOW('V', 8, int)
end_define

begin_comment
comment|/* control the BBA */
end_comment

begin_define
define|#
directive|define
name|VSIOFIBCTL
value|_IOW('V', 9, int)
end_define

begin_comment
comment|/* lamp on/off */
end_comment

begin_define
define|#
directive|define
name|VSIOFIBRETRY
value|_IOW('V',10, int)
end_define

begin_comment
comment|/* fiber retries */
end_comment

begin_define
define|#
directive|define
name|VSIOGETSTATS
value|_IOR('V',11, vsStats)
end_define

begin_comment
comment|/* get statistics */
end_comment

begin_define
define|#
directive|define
name|VSIOGETIOA
value|_IOR('V',13, vsIoAddrAddr)
end_define

begin_comment
comment|/* get ioreg address */
end_comment

begin_define
define|#
directive|define
name|VSIOUSERWAIT
value|_IO('V', 15)
end_define

begin_comment
comment|/* wait for user I/O completion */
end_comment

begin_define
define|#
directive|define
name|VSIOWAITGO
value|_IOW('V', 16, caddr_t)
end_define

begin_comment
comment|/* wait then go */
end_comment

begin_define
define|#
directive|define
name|VSIO_OFF
value|0
end_define

begin_comment
comment|/* option off */
end_comment

begin_define
define|#
directive|define
name|VSIO_ON
value|1
end_define

begin_comment
comment|/* option on */
end_comment

begin_define
define|#
directive|define
name|VS_FIB_FINITE
value|1
end_define

begin_comment
comment|/* finite retries */
end_comment

begin_define
define|#
directive|define
name|VS_FIB_INFINITE
value|2
end_define

begin_comment
comment|/* infinite retries */
end_comment

begin_comment
comment|/*  * Event queue entries  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vs_event
block|{
name|u_short
name|vse_x
decl_stmt|;
comment|/* x position */
name|u_short
name|vse_y
decl_stmt|;
comment|/* y position */
name|u_short
name|vse_time
decl_stmt|;
comment|/* 10 millisecond units (button only) */
name|char
name|vse_type
decl_stmt|;
comment|/* button or motion? */
name|u_char
name|vse_key
decl_stmt|;
comment|/* the key (button only) */
name|char
name|vse_direction
decl_stmt|;
comment|/* which direction (button only) */
name|char
name|vse_device
decl_stmt|;
comment|/* which device (button only) */
block|}
name|vsEvent
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VSE_BUTTON
value|0
end_define

begin_comment
comment|/* button moved */
end_comment

begin_define
define|#
directive|define
name|VSE_MMOTION
value|1
end_define

begin_comment
comment|/* mouse moved */
end_comment

begin_define
define|#
directive|define
name|VSE_TMOTION
value|2
end_define

begin_comment
comment|/* tablet moved */
end_comment

begin_define
define|#
directive|define
name|VSE_KBTUP
value|0
end_define

begin_comment
comment|/* up */
end_comment

begin_define
define|#
directive|define
name|VSE_KBTDOWN
value|1
end_define

begin_comment
comment|/* down */
end_comment

begin_define
define|#
directive|define
name|VSE_MOUSE
value|1
end_define

begin_comment
comment|/* mouse */
end_comment

begin_define
define|#
directive|define
name|VSE_DKB
value|2
end_define

begin_comment
comment|/* main keyboard */
end_comment

begin_define
define|#
directive|define
name|VSE_TABLET
value|3
end_define

begin_comment
comment|/* graphics tablet */
end_comment

begin_define
define|#
directive|define
name|VSE_AUX
value|4
end_define

begin_comment
comment|/* auxiliary */
end_comment

begin_define
define|#
directive|define
name|VSE_CONSOLE
value|5
end_define

begin_comment
comment|/* console */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vsStats
block|{
name|int
name|errors
decl_stmt|;
comment|/* count errors */
name|int
name|unsolIntr
decl_stmt|;
comment|/* count unsolicited interrupts */
name|int
name|overruns
decl_stmt|;
comment|/* event queue overruns */
name|int
name|flashes
decl_stmt|;
comment|/* flashes on fiber link */
name|int
name|ignites
decl_stmt|;
comment|/* times turned on */
name|int
name|douses
decl_stmt|;
comment|/* times turned off */
name|int
name|linkErrors
decl_stmt|;
comment|/* link errors */
block|}
name|vsStats
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_vs_cursor
block|{
name|short
name|x
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|vsCursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_vs_box
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
name|vsBox
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_vsIoAddr
block|{
name|short
modifier|*
name|ioreg
decl_stmt|;
name|short
name|status
decl_stmt|;
name|caddr_t
name|obuff
decl_stmt|;
name|int
name|obufflen
decl_stmt|;
name|int
name|reloc
decl_stmt|;
name|vsEvent
modifier|*
name|ibuff
decl_stmt|;
name|int
name|iqsize
decl_stmt|;
comment|/* may assume power of 2 */
name|int
name|ihead
decl_stmt|;
comment|/* atomic write */
name|int
name|itail
decl_stmt|;
comment|/* atomic read */
name|vsCursor
name|mouse
decl_stmt|;
comment|/* atomic read/write */
name|vsBox
name|mbox
decl_stmt|;
comment|/* atomic read/write */
block|}
name|vsIoAddr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|vsIoAddr
modifier|*
name|vsIoAddrAddr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

