begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)getlogin.c	8.1 (Berkeley) %G%"
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_decl_stmt
name|int
name|_logname_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* known to setlogin() */
end_comment

begin_function
name|char
modifier|*
name|getlogin
parameter_list|()
block|{
specifier|static
name|char
name|logname
index|[
name|MAXLOGNAME
operator|+
literal|1
index|]
decl_stmt|;
if|if
condition|(
name|_logname_valid
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|_getlogin
argument_list|(
name|logname
argument_list|,
sizeof|sizeof
argument_list|(
name|logname
argument_list|)
operator|-
literal|1
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
name|_logname_valid
operator|=
literal|1
expr_stmt|;
block|}
return|return
operator|(
operator|*
name|logname
condition|?
name|logname
else|:
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
end_function

end_unit

