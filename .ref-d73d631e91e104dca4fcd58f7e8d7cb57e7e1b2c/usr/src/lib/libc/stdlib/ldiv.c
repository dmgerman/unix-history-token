begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)ldiv.c	5.1 (Berkeley) %G%"
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
file|<stdlib.h>
end_include

begin_comment
comment|/* ldiv_t */
end_comment

begin_comment
comment|/*  * I AM NOT SURE THIS IS COMPLETELY PORTABLE  * (or that it is even right)  */
end_comment

begin_function
name|ldiv_t
name|ldiv
parameter_list|(
name|num
parameter_list|,
name|denom
parameter_list|)
name|long
name|num
decl_stmt|,
name|denom
decl_stmt|;
block|{
name|ldiv_t
name|r
decl_stmt|;
comment|/* see div.c for comments */
if|if
condition|(
name|num
operator|>
literal|0
operator|&&
name|denom
operator|<
literal|0
condition|)
block|{
name|num
operator|=
operator|-
name|num
expr_stmt|;
name|denom
operator|=
operator|-
name|denom
expr_stmt|;
block|}
name|r
operator|.
name|quot
operator|=
name|num
operator|/
name|denom
expr_stmt|;
name|r
operator|.
name|rem
operator|=
name|num
operator|%
name|denom
expr_stmt|;
if|if
condition|(
name|num
operator|<
literal|0
operator|&&
name|denom
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|r
operator|.
name|rem
operator|>
literal|0
condition|)
block|{
name|r
operator|.
name|quot
operator|++
expr_stmt|;
name|r
operator|.
name|rem
operator|-=
name|denom
expr_stmt|;
block|}
block|}
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

end_unit

