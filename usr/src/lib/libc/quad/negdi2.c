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
literal|"@(#)negdi2.c	5.5 (Berkeley) %G%"
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
comment|/*  * Return -a (or, equivalently, 0 - a), in quad.  See subdi3.c.  */
end_comment

begin_function
name|quad_t
name|__negdi2
parameter_list|(
name|a
parameter_list|)
name|quad_t
name|a
decl_stmt|;
block|{
name|union
name|uu
name|aa
decl_stmt|,
name|res
decl_stmt|;
name|aa
operator|.
name|q
operator|=
name|a
expr_stmt|;
name|res
operator|.
name|ul
index|[
name|L
index|]
operator|=
operator|-
name|aa
operator|.
name|ul
index|[
name|L
index|]
expr_stmt|;
name|res
operator|.
name|ul
index|[
name|H
index|]
operator|=
operator|-
name|aa
operator|.
name|ul
index|[
name|H
index|]
operator|-
operator|(
name|res
operator|.
name|ul
index|[
name|L
index|]
operator|>
literal|0
operator|)
expr_stmt|;
return|return
operator|(
name|res
operator|.
name|q
operator|)
return|;
block|}
end_function

end_unit

