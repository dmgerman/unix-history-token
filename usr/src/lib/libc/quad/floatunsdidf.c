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
literal|"@(#)floatunsdidf.c	8.1 (Berkeley) %G%"
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
comment|/*  * Convert (unsigned) quad to double.  * This is exactly like floatdidf.c except that negatives never occur.  */
end_comment

begin_function
name|double
name|__floatunsdidf
parameter_list|(
name|x
parameter_list|)
name|u_quad_t
name|x
decl_stmt|;
block|{
name|double
name|d
decl_stmt|;
name|union
name|uu
name|u
decl_stmt|;
name|u
operator|.
name|uq
operator|=
name|x
expr_stmt|;
name|d
operator|=
operator|(
name|double
operator|)
name|u
operator|.
name|ul
index|[
name|H
index|]
operator|*
operator|(
operator|(
literal|1
operator|<<
operator|(
name|LONG_BITS
operator|-
literal|2
operator|)
operator|)
operator|*
literal|4.0
operator|)
expr_stmt|;
name|d
operator|+=
name|u
operator|.
name|ul
index|[
name|L
index|]
expr_stmt|;
return|return
operator|(
name|d
operator|)
return|;
block|}
end_function

end_unit

