begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)vuid_event.h	7.3 (Berkeley) %G%  *  * from: $Header: vuid_event.h,v 1.4 92/11/26 01:20:27 torek Exp $ (LBL)  */
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

