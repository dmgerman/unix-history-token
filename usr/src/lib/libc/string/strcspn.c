begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/*  * Sys5 compat routine  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strcspn.c	5.1 (Berkeley) 85/08/05"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|strcspn
argument_list|(
name|s
argument_list|,
name|set
argument_list|)
specifier|register
name|char
operator|*
name|s
operator|,
operator|*
name|set
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|n
operator|=
literal|0
expr_stmt|;
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
operator|++
condition|)
block|{
for|for
control|(
name|p
operator|=
name|set
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
break|break;
if|if
condition|(
operator|*
name|p
condition|)
return|return
operator|(
name|n
operator|)
return|;
name|n
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|n
operator|)
return|;
block|}
end_block

end_unit

