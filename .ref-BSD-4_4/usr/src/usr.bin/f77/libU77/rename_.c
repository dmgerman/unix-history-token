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
literal|"@(#)rename_.c	5.2 (Berkeley) 4/12/91"
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
comment|/*  * rename a file atomically  *  * synopsis:  *	integer function rename (from, to)  *	character*(*) from, to  *  * where:  *	return value will be zero normally, an error number otherwise.  */
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
name|rename_
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|frlen
parameter_list|,
name|tolen
parameter_list|)
name|char
modifier|*
name|from
decl_stmt|,
decl|*
name|to
decl_stmt|;
end_function

begin_decl_stmt
name|long
name|frlen
decl_stmt|,
name|tolen
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|frbuf
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|tobuf
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
if|if
condition|(
name|frlen
operator|<=
literal|0
operator|||
name|tolen
operator|<=
literal|0
operator|||
operator|*
name|from
operator|==
literal|' '
operator|||
operator|*
name|to
operator|==
literal|' '
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
if|if
condition|(
name|frlen
operator|>=
sizeof|sizeof
name|frbuf
operator|||
name|tolen
operator|>=
sizeof|sizeof
name|tobuf
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
name|from
argument_list|,
name|frlen
argument_list|,
name|frbuf
argument_list|)
expr_stmt|;
name|g_char
argument_list|(
name|to
argument_list|,
name|tolen
argument_list|,
name|tobuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|rename
argument_list|(
name|from
argument_list|,
name|to
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
end_block

end_unit

