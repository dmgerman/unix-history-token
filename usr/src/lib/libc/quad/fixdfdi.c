begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)fixdfdi.c	5.1 (Berkeley) %G%"
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
file|"longlong.h"
end_include

begin_function
name|long
name|long
name|__fixdfdi
parameter_list|(
name|a
parameter_list|)
name|double
name|a
decl_stmt|;
block|{
name|long
name|long
name|__fixunsdfdi
argument_list|(
name|double
name|a
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
return|return
operator|-
name|__fixunsdfdi
argument_list|(
operator|-
name|a
argument_list|)
return|;
return|return
name|__fixunsdfdi
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

