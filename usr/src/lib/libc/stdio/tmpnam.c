begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)tmpnam.c	8.3 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|char
modifier|*
name|tmpnam
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
specifier|static
name|u_long
name|tmpcount
decl_stmt|;
specifier|static
name|char
name|buf
index|[
name|L_tmpnam
index|]
decl_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
name|s
operator|=
name|buf
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|s
argument_list|,
name|L_tmpnam
argument_list|,
literal|"%stmp.%lu.XXXXXX"
argument_list|,
name|P_tmpdir
argument_list|,
name|tmpcount
argument_list|)
expr_stmt|;
operator|++
name|tmpcount
expr_stmt|;
return|return
operator|(
name|mktemp
argument_list|(
name|s
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

