begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)vprintf.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_function
name|int
name|vprintf
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
block|{
name|int
name|len
decl_stmt|;
name|len
operator|=
name|_doprnt
argument_list|(
name|fmt
argument_list|,
name|ap
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
return|return
operator|(
name|ferror
argument_list|(
name|stdout
argument_list|)
condition|?
name|EOF
else|:
name|len
operator|)
return|;
block|}
end_function

end_unit

