begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  * from: $Header: kbio.h,v 1.3 92/06/17 05:35:49 torek Exp $ (LBL)  *  * from: sparc/dev/kbio.h	7.2 (Berkeley) 7/21/92  *  *	@(#)kbio.h	7.1 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/*  * The following is a minimal emulation of Sun's `kio' structures  * and related operations necessary to make X11 happy (i.e., make it  * compile, and make old X11 binaries run).  */
end_comment

begin_comment
comment|/*  * The kiockey structure apparently gets and/or sets keyboard mappings.  * It seems to be kind of useless, but X11 uses it (according to the  * comments) to figure out when a Sun 386i has a type-4 keyboard but  * claims to have a type-3 keyboard.  We need just enough to cause the  * appropriate ioctl to return the appropriate magic value.  *  * KIOCGETKEY fills in kio_entry from kio_station.  Not sure what tablemask  * is for; X sets it before the call, so it is not an output, but we do not  * care anyway.  KIOCSDIRECT is supposed to tell the kernel whether to send  * keys to the console or to X; we just send them to X whenever the keyboard  * is open at all.  (XXX may need to change this later)  *  * Keyboard commands and types are defined in kbd.h as they are actually  * real hardware commands and type numbers.  */
end_comment

begin_struct
struct|struct
name|kiockey
block|{
name|int
name|kio_tablemask
decl_stmt|;
comment|/* whatever */
name|u_char
name|kio_station
decl_stmt|;
comment|/* key number */
name|u_char
name|kio_entry
decl_stmt|;
comment|/* HOLE if not present */
name|char
name|kio_text
index|[
literal|10
index|]
decl_stmt|;
comment|/* the silly escape sequences (unsupported) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOLE
value|0x302
end_define

begin_comment
comment|/* value for kio_entry to say `really type 3' */
end_comment

begin_define
define|#
directive|define
name|KIOCTRANS
value|_IOW('k', 0, int)
end_define

begin_comment
comment|/* set translation mode */
end_comment

begin_comment
comment|/* (we only accept TR_UNTRANS_EVENT) */
end_comment

begin_define
define|#
directive|define
name|KIOCGETKEY
value|_IOWR('k', 2, struct kiockey)
end_define

begin_comment
comment|/* fill in kio_entry */
end_comment

begin_define
define|#
directive|define
name|KIOCGTRANS
value|_IOR('k', 5, int)
end_define

begin_comment
comment|/* get translation mode */
end_comment

begin_define
define|#
directive|define
name|KIOCCMD
value|_IOW('k', 8, int)
end_define

begin_comment
comment|/* X uses this to ring bell */
end_comment

begin_define
define|#
directive|define
name|KIOCTYPE
value|_IOR('k', 9, int)
end_define

begin_comment
comment|/* get keyboard type */
end_comment

begin_define
define|#
directive|define
name|KIOCSDIRECT
value|_IOW('k', 10, int)
end_define

begin_comment
comment|/* keys to console? */
end_comment

begin_define
define|#
directive|define
name|TR_UNTRANS_EVENT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KIOCMOUSE
value|_IOW('k', 20, int)
end_define

begin_comment
comment|/* enable/disabel to trace mouse motion */
end_comment

end_unit

