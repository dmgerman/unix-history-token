begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)bzero.c	5.1 (Berkeley) 1/27/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * bzero -- vax movc5 instruction  */
end_comment

begin_expr_stmt
name|bzero
argument_list|(
name|b
argument_list|,
name|length
argument_list|)
specifier|register
name|char
operator|*
name|b
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|length
condition|)
do|do
operator|*
name|b
operator|++
operator|=
literal|'\0'
expr_stmt|;
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

