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
literal|"@(#)getcwd_.c	5.2 (Berkeley) 4/12/91"
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
comment|/*  * Get pathname of current working directory.  *  * calling sequence:  *	character*128 path  *	ierr = getcwd(path)  * where:  *	path will receive the pathname of the current working directory.  *	ierr will be 0 if successful, a system error code otherwise.  */
end_comment

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

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|long
name|getcwd_
parameter_list|(
name|path
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
name|long
name|len
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|char
name|pathname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|p
operator|=
name|getwd
argument_list|(
name|pathname
argument_list|)
expr_stmt|;
name|b_char
argument_list|(
name|pathname
argument_list|,
name|path
argument_list|,
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
condition|)
return|return
operator|(
literal|0L
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|long
operator|)
name|errno
operator|)
return|;
block|}
end_function

end_unit

