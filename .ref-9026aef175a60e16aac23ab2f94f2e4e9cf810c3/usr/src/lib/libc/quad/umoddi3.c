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
literal|"@(#)umoddi3.c	8.1 (Berkeley) %G%"
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
comment|/*  * Return remainder after dividing two unsigned quads.  */
end_comment

begin_function
name|u_quad_t
name|__umoddi3
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
name|u_quad_t
name|r
decl_stmt|;
operator|(
name|void
operator|)
name|__qdivrem
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

end_unit

