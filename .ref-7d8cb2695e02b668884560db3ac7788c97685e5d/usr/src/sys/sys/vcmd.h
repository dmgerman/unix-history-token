begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vcmd.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|VPRINT
value|0100
end_define

begin_define
define|#
directive|define
name|VPLOT
value|0200
end_define

begin_define
define|#
directive|define
name|VPRINTPLOT
value|0400
end_define

begin_define
define|#
directive|define
name|VGETSTATE
value|_IOR('v', 0, int)
end_define

begin_define
define|#
directive|define
name|VSETSTATE
value|_IOW('v', 1, int)
end_define

end_unit

