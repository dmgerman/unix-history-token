begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)ffs.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * ffs -- vax ffs instruction  */
end_comment

begin_expr_stmt
name|ffs
argument_list|(
name|mask
argument_list|)
specifier|register
name|int
name|mask
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|bit
decl_stmt|;
if|if
condition|(
name|mask
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
for|for
control|(
name|bit
operator|=
literal|1
init|;
operator|!
operator|(
name|mask
operator|&
literal|1
operator|)
condition|;
name|bit
operator|++
control|)
name|mask
operator|>>=
literal|1
expr_stmt|;
return|return
operator|(
name|bit
operator|)
return|;
block|}
end_block

end_unit

