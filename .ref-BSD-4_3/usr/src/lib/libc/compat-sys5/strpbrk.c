begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/*  * Sys 5 compat routine...  */
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
literal|"@(#)strpbrk.c	5.2 (Berkeley) 86/03/09"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|strpbrk
parameter_list|(
name|s
parameter_list|,
name|brk
parameter_list|)
specifier|register
name|char
modifier|*
name|s
decl_stmt|,
decl|*
name|brk
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|c
expr_stmt|;
while|while
condition|(
name|c
operator|=
operator|*
name|s
condition|)
block|{
for|for
control|(
name|p
operator|=
name|brk
init|;
operator|*
name|p
condition|;
name|p
operator|++
control|)
if|if
condition|(
name|c
operator|==
operator|*
name|p
condition|)
return|return
operator|(
name|s
operator|)
return|;
name|s
operator|++
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

