begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)getpagesize.c	5.1 (Berkeley) %G%"
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

begin_decl_stmt
name|int
name|getpagesize
argument_list|(
name|void
argument_list|)
else|#
directive|else
name|int
name|getpagesize
argument_list|()
endif|#
directive|endif
block|{
name|int
name|mib
index|[
literal|2
index|]
decl_stmt|,
name|size
decl_stmt|,
name|value
decl_stmt|;
name|mib
index|[
literal|0
index|]
operator|=
name|CTL_HW
expr_stmt|;
name|mib
index|[
literal|1
index|]
operator|=
name|HW_PAGESIZE
expr_stmt|;
name|size
operator|=
sizeof|sizeof
name|value
expr_stmt|;
if|if
condition|(
name|sysctl
argument_list|(
name|mib
argument_list|,
literal|2
argument_list|,
operator|&
name|value
argument_list|,
operator|&
name|size
argument_list|,
name|NULL
argument_list|,
literal|0
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
name|value
operator|)
return|;
block|}
end_decl_stmt

end_unit

