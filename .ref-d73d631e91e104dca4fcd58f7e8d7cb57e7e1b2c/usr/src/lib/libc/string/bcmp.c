begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)bcmp.c	5.4 (Berkeley) %G%"
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

begin_comment
comment|/*  * bcmp -- vax cmpc3 instruction  */
end_comment

begin_expr_stmt
name|bcmp
argument_list|(
name|b1
argument_list|,
name|b2
argument_list|,
name|length
argument_list|)
specifier|register
name|char
operator|*
name|b1
operator|,
operator|*
name|b2
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|size_t
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|length
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
do|do
if|if
condition|(
operator|*
name|b1
operator|++
operator|!=
operator|*
name|b2
operator|++
condition|)
break|break;
do|while
condition|(
operator|--
name|length
condition|)
do|;
return|return
operator|(
name|length
operator|)
return|;
block|}
end_block

end_unit

