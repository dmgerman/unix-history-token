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
literal|"@(#)memccpy.c	5.1 (Berkeley) 85/08/05"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|memccpy
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|t
decl_stmt|,
decl|*
name|f
decl_stmt|;
end_function

begin_expr_stmt
specifier|register
name|c
operator|,
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
if|if
condition|(
operator|(
operator|*
name|t
operator|++
operator|=
operator|*
name|f
operator|++
operator|)
operator|==
name|c
condition|)
return|return
operator|(
name|t
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

