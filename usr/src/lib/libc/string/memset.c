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
literal|"@(#)memset.c	5.1 (Berkeley) 85/08/05"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|memset
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
function|register c
operator|,
function|n;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
init|=
name|s
decl_stmt|;
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
operator|*
name|s
operator|++
operator|=
name|c
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_block

end_unit

