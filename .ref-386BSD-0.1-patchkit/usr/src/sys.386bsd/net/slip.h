begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions that user level programs might need to know to interact  * with serial line IP (slip) lines.   * @(#) $Header: slip.h,v 1.4 92/02/02 17:26:02 leres Exp $ (LBL)  *  * Copyright (c) 1990 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/*  * ioctl to get slip interface unit number (e.g., sl0, sl1, etc.)  * assigned to some terminal line with a slip module pushed on it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|SLIOGUNIT
value|_IOR('B', 1, int)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SLIOGUNIT
value|_IOR(B, 1, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * definitions of the pseudo- link-level header attached to slip  * packets grabbed by the packet filter (bpf) traffic monitor.  */
end_comment

begin_define
define|#
directive|define
name|SLIP_HDRLEN
value|16
end_define

begin_define
define|#
directive|define
name|SLX_DIR
value|0
end_define

begin_define
define|#
directive|define
name|SLX_CHDR
value|1
end_define

begin_define
define|#
directive|define
name|CHDR_LEN
value|15
end_define

begin_define
define|#
directive|define
name|SLIPDIR_IN
value|0
end_define

begin_define
define|#
directive|define
name|SLIPDIR_OUT
value|1
end_define

end_unit

