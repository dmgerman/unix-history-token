begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)fixdfdi.c	8.1 (Berkeley) %G%"
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
file|"quad.h"
end_include

begin_comment
comment|/*  * Convert double to (signed) quad.  * We clamp anything that is out of range.  */
end_comment

begin_function
name|quad_t
name|__fixdfdi
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
if|if
condition|(
name|x
operator|<
literal|0
condition|)
if|if
condition|(
name|x
operator|<=
name|QUAD_MIN
condition|)
return|return
operator|(
name|QUAD_MIN
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|quad_t
operator|)
operator|-
operator|(
name|u_quad_t
operator|)
operator|-
name|x
operator|)
return|;
elseif|else
if|if
condition|(
name|x
operator|>=
name|QUAD_MAX
condition|)
return|return
operator|(
name|QUAD_MAX
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|quad_t
operator|)
operator|(
name|u_quad_t
operator|)
name|x
operator|)
return|;
block|}
end_function

end_unit

