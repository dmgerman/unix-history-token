begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)setjmperr.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * This routine is called from longjmp() when an error occurs.  * Programs that wish to exit gracefully from this error may  * write their own versions.  * If this routine returns, the program is aborted.  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|void
name|longjmperror
parameter_list|()
block|{
define|#
directive|define
name|ERRMSG
value|"longjmp botch.\n"
operator|(
name|void
operator|)
name|write
argument_list|(
name|STDERR_FILENO
argument_list|,
name|ERRMSG
argument_list|,
sizeof|sizeof
argument_list|(
name|ERRMSG
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

