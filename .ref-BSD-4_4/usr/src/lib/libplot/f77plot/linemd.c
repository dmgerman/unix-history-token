begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)linemd.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_expr_stmt
name|linemd_
argument_list|(
name|s
argument_list|,
name|len
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|cend
decl_stmt|;
name|cp
operator|=
name|buf
expr_stmt|;
name|cend
operator|=
name|cp
operator|+
operator|(
name|len
operator|<
literal|255
condition|?
name|len
else|:
literal|255
operator|)
expr_stmt|;
while|while
condition|(
name|cp
operator|<
name|cend
operator|&&
operator|*
name|s
operator|!=
literal|' '
condition|)
operator|*
name|cp
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
operator|*
name|cp
operator|=
literal|0
expr_stmt|;
name|linemod
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

