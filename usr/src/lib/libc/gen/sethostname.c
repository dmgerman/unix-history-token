begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)sethostname.c	8.1 (Berkeley) %G%"
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
file|<sys/sysctl.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function
name|long
name|sethostname
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
else|#
directive|else
function|long sethostname
parameter_list|(
name|name
parameter_list|,
name|namelen
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|namelen
decl_stmt|;
endif|#
directive|endif
block|{
name|int
name|mib
index|[
literal|2
index|]
decl_stmt|;
name|mib
index|[
literal|0
index|]
operator|=
name|CTL_KERN
expr_stmt|;
name|mib
index|[
literal|1
index|]
operator|=
name|KERN_HOSTNAME
expr_stmt|;
if|if
condition|(
name|sysctl
argument_list|(
name|mib
argument_list|,
literal|2
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|(
name|void
operator|*
operator|)
name|name
argument_list|,
name|namelen
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

