begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)rcv.h	5.1 (Berkeley) 6/6/85  */
end_comment

begin_comment
comment|/*  * Mail -- a mail program  *  * This file is included by normal files which want both  * globals and declarations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_include
include|#
directive|include
file|<whoami.h>
end_include

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
file|"glob.h"
end_include

end_unit

