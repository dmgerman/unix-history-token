begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ed James.  *  * %sccs.include.redist.c%  *  *	@(#)include.h	5.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987 by Ed James, UC Berkeley.  All rights reserved.  *  * Copy permission is hereby granted provided that this notice is  * retained on all partial or complete copies.  *  * For more info on this and all of my stuff, mail edjames@berkeley.edu.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy((b), (a), (c))
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset((a), '\0', (b))
end_define

begin_define
define|#
directive|define
name|srandom
value|srand
end_define

begin_define
define|#
directive|define
name|random
value|rand
end_define

begin_define
define|#
directive|define
name|sgttyb
value|termio
end_define

begin_define
define|#
directive|define
name|sg_erase
value|c_cc[2]
end_define

begin_define
define|#
directive|define
name|sg_kill
value|c_cc[3]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"def.h"
end_include

begin_include
include|#
directive|include
file|"struct.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_include
include|#
directive|include
file|"tunable.h"
end_include

end_unit

