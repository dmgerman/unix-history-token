begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)fixdfdi.c	5.3 (Berkeley) %G%"
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

begin_ifndef
ifndef|#
directive|ifndef
name|QUAD_MAX
end_ifndef

begin_comment
comment|/* should be in<limits.h> maybe? */
end_comment

begin_define
define|#
directive|define
name|QUAD_MAX
value|((quad)(((u_quad)1<< (QUAD_BITS - 1)) - 1))
end_define

begin_define
define|#
directive|define
name|QUAD_MIN
value|(-QUAD_MAX - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Convert double to (signed) quad.  * We clamp anything that is out of range.  */
end_comment

begin_function
name|quad
name|__fixdfdi
parameter_list|(
name|double
name|x
parameter_list|)
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
name|quad
operator|)
operator|-
operator|(
name|u_quad
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
name|quad
operator|)
operator|(
name|u_quad
operator|)
name|x
operator|)
return|;
block|}
end_function

end_unit

