begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/*  * Sys5 compat routine  */
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
literal|"@(#)memcpy.c	5.2 (Berkeley) 86/03/09"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|memcpy
argument_list|(
name|t
argument_list|,
name|f
argument_list|,
name|n
argument_list|)
decl|register
name|char
modifier|*
name|t
decl_stmt|,
modifier|*
name|f
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|register
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
init|=
name|t
decl_stmt|;
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
operator|*
name|t
operator|++
operator|=
operator|*
name|f
operator|++
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_block

end_unit

