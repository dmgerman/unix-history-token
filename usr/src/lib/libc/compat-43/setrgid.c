begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)setrgid.c	8.1 (Berkeley) %G%"
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
file|<unistd.h>
end_include

begin_function
name|int
ifdef|#
directive|ifdef
name|__STDC__
name|setrgid
parameter_list|(
name|gid_t
name|rgid
parameter_list|)
else|#
directive|else
function|setrgid
parameter_list|(
name|rgid
parameter_list|)
name|int
name|rgid
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|setregid
argument_list|(
name|rgid
argument_list|,
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

