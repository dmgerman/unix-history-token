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
literal|"@(#)ffs.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * ffs -- vax ffs instruction  */
end_comment

begin_expr_stmt
name|ffs
argument_list|(
name|mask
argument_list|)
specifier|register
name|long
name|mask
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|cnt
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
name|cnt
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
name|cnt
operator|++
control|)
name|mask
operator|>>=
literal|1
expr_stmt|;
return|return
operator|(
name|cnt
operator|)
return|;
block|}
end_block

end_unit

