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
literal|"@(#)strrchr.c	5.7 (Berkeley) %G%"
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
file|<string.h>
end_include

begin_function
name|char
modifier|*
name|strrchr
parameter_list|(
name|p
parameter_list|,
name|ch
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|,
name|ch
decl_stmt|;
block|{
return|return
operator|(
name|rindex
argument_list|(
name|p
argument_list|,
name|ch
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

