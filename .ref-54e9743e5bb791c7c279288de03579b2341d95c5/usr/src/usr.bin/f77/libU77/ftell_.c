begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)ftell_.c	5.2 (Berkeley) %G%"
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
comment|/*  * return current file position  *  * calling sequence:  *	integer curpos, ftell  *	curpos = ftell(lunit)  * where:  *	lunit is an open logical unit  *	curpos will be the current offset in bytes from the start of the  *		file associated with that logical unit  *		or a (negative) system error code.  */
end_comment

begin_include
include|#
directive|include
file|"../libI77/fiodefs.h"
end_include

begin_include
include|#
directive|include
file|"../libI77/f_errno.h"
end_include

begin_decl_stmt
specifier|extern
name|unit
name|units
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|ftell_
parameter_list|(
name|lu
parameter_list|)
name|long
modifier|*
name|lu
decl_stmt|;
block|{
if|if
condition|(
operator|*
name|lu
operator|<
literal|0
operator|||
operator|*
name|lu
operator|>=
name|MXUNIT
condition|)
return|return
operator|(
operator|-
call|(
name|long
call|)
argument_list|(
name|errno
operator|=
name|F_ERUNIT
argument_list|)
operator|)
return|;
if|if
condition|(
operator|!
name|units
index|[
operator|*
name|lu
index|]
operator|.
name|ufd
condition|)
return|return
operator|(
operator|-
call|(
name|long
call|)
argument_list|(
name|errno
operator|=
name|F_ERNOPEN
argument_list|)
operator|)
return|;
return|return
operator|(
name|ftell
argument_list|(
name|units
index|[
operator|*
name|lu
index|]
operator|.
name|ufd
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

