begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vcmd.h	7.2 (Berkeley) 12/18/87  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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

