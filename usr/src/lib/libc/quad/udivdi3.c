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
literal|"@(#)udivdi3.c	5.4 (Berkeley) %G%"
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
comment|/*  * Divide two unsigned quads.  */
end_comment

begin_function
name|u_quad_t
name|__udivdi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|u_quad_t
name|a
decl_stmt|,
name|b
decl_stmt|;
block|{
return|return
operator|(
name|__qdivrem
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
operator|(
name|u_quad_t
operator|*
operator|)
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

