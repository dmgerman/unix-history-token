begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vuid_event.h	8.1 (Berkeley) 6/11/93  *  * from: $Header: vuid_event.h,v 1.4 92/11/26 01:20:27 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * The following is a minimal emulation of Sun's `Firm_event' structures  * and related operations necessary to make X11 happy (i.e., make it  * compile, and make old X11 binaries run).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|firm_event
block|{
name|u_short
name|id
decl_stmt|;
comment|/* key or MS_* or LOC_[XY]_DELTA */
name|u_short
name|pad
decl_stmt|;
comment|/* unused, at least by X11 */
name|int
name|value
decl_stmt|;
comment|/* VKEY_{UP,DOWN} or locator delta */
name|struct
name|timeval
name|time
decl_stmt|;
block|}
name|Firm_event
typedef|;
end_typedef

begin_comment
comment|/*  * Special `id' fields.  These weird numbers simply match the old binaries.  * Others are in 0..0x7f and are keyboard key numbers (keyboard dependent!).  */
end_comment

begin_define
define|#
directive|define
name|MS_LEFT
value|0x7f20
end_define

begin_comment
comment|/* left mouse button */
end_comment

begin_define
define|#
directive|define
name|MS_MIDDLE
value|0x7f21
end_define

begin_comment
comment|/* middle mouse button */
end_comment

begin_define
define|#
directive|define
name|MS_RIGHT
value|0x7f22
end_define

begin_comment
comment|/* right mouse button */
end_comment

begin_define
define|#
directive|define
name|LOC_X_DELTA
value|0x7f80
end_define

begin_comment
comment|/* mouse delta-X */
end_comment

begin_define
define|#
directive|define
name|LOC_Y_DELTA
value|0x7f81
end_define

begin_comment
comment|/* mouse delta-Y */
end_comment

begin_comment
comment|/*  * Special `value' fields.  These apply to keys and mouse buttons.  The  * value of a mouse delta is the delta.  Note that positive deltas are  * left and up (not left and down as you might expect).  */
end_comment

begin_define
define|#
directive|define
name|VKEY_UP
value|0
end_define

begin_comment
comment|/* key or button went up */
end_comment

begin_define
define|#
directive|define
name|VKEY_DOWN
value|1
end_define

begin_comment
comment|/* key or button went down */
end_comment

begin_comment
comment|/*  * The following ioctls are clearly intended to take things in and out  * of `firm event' mode.  Since we always run in this mode (as far as  * /dev/kbd and /dev/mouse are concerned, anyway), we always claim to  * be in this mode and reject anything else.  */
end_comment

begin_define
define|#
directive|define
name|VUIDSFORMAT
value|_IOW('v', 1, int)
end_define

begin_define
define|#
directive|define
name|VUIDGFORMAT
value|_IOR('v', 2, int)
end_define

begin_define
define|#
directive|define
name|VUID_FIRM_EVENT
value|1
end_define

begin_comment
comment|/* the only format we support */
end_comment

end_unit

