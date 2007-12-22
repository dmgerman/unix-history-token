begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: strerror.c,v 1.23 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

begin_comment
comment|/* **  define strerror for platforms that lack it. */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* sys_errlist, on some platforms */
end_comment

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_comment
comment|/* sm_snprintf */
end_comment

begin_include
include|#
directive|include
file|<sm/string.h>
end_include

begin_include
include|#
directive|include
file|<sm/conf.h>
end_include

begin_include
include|#
directive|include
file|<sm/errstring.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ERRLIST_PREDEFINED
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(ERRLIST_PREDEFINED) */
end_comment

begin_if
if|#
directive|if
operator|!
name|HASSTRERROR
end_if

begin_comment
comment|/* **  STRERROR -- return error message string corresponding to an error number. ** **	Parameters: **		err -- error number. ** **	Returns: **		Error string (might be pointer to static buffer). */
end_comment

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|err
parameter_list|)
name|int
name|err
decl_stmt|;
block|{
specifier|static
name|char
name|buf
index|[
literal|64
index|]
decl_stmt|;
if|if
condition|(
name|err
operator|>=
literal|0
operator|&&
name|err
operator|<
name|sys_nerr
condition|)
return|return
operator|(
name|char
operator|*
operator|)
name|sys_errlist
index|[
name|err
index|]
return|;
else|else
block|{
operator|(
name|void
operator|)
name|sm_snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"Error %d"
argument_list|,
name|err
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HASSTRERROR */
end_comment

end_unit

