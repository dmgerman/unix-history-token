begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  *  * from: $Header: isnan.c,v 1.1 91/07/08 19:03:34 torek Exp $  */
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
literal|"@(#)isnan.c	8.1 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/ieee.h>
end_include

begin_macro
name|isnan
argument_list|(
argument|d
argument_list|)
end_macro

begin_decl_stmt
name|double
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|ieee_double
modifier|*
name|p
init|=
operator|(
expr|struct
name|ieee_double
operator|*
operator|)
operator|&
name|d
decl_stmt|;
return|return
operator|(
name|p
operator|->
name|dbl_exp
operator|==
name|DBL_EXP_INFNAN
operator|&&
operator|(
name|p
operator|->
name|dbl_frach
operator|!=
literal|0
operator|||
name|p
operator|->
name|dbl_fracl
operator|!=
literal|0
operator|)
operator|)
return|;
block|}
end_block

end_unit

