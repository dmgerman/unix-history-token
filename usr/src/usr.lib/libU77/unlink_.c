begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)unlink_.c	5.1	6/7/85  */
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

