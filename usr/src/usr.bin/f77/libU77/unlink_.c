begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)unlink_.c	5.2 (Berkeley) 4/12/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * unlink (remove) a file  *  * calling sequence:  *	integer unlink  *	ierror = unlink(filename)  * where:  *	ierror will be a returned status (0 == OK)  *	filename is the file to be unlinked  */
end_comment

begin_include
include|#
directive|include
file|"../libI77/f_errno.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|long
name|unlink_
parameter_list|(
name|fname
parameter_list|,
name|namlen
parameter_list|)
name|char
modifier|*
name|fname
decl_stmt|;
name|long
name|namlen
decl_stmt|;
block|{
name|char
name|buf
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
if|if
condition|(
name|namlen
operator|>=
sizeof|sizeof
name|buf
condition|)
return|return
operator|(
call|(
name|long
call|)
argument_list|(
name|errno
operator|=
name|F_ERARG
argument_list|)
operator|)
return|;
name|g_char
argument_list|(
name|fname
argument_list|,
name|namlen
argument_list|,
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|unlink
argument_list|(
name|buf
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|(
name|long
operator|)
name|errno
operator|)
return|;
return|return
operator|(
literal|0L
operator|)
return|;
block|}
end_function

end_unit

