begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)s_copy.c	5.2 (Berkeley) 4/12/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_macro
name|s_copy
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|la
argument_list|,
argument|lb
argument_list|)
end_macro

begin_comment
comment|/* assign strings:  a = b */
end_comment

begin_decl_stmt
name|char
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|la
decl_stmt|,
name|lb
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|aend
decl_stmt|,
modifier|*
name|bend
decl_stmt|;
name|aend
operator|=
name|a
operator|+
name|la
expr_stmt|;
if|if
condition|(
name|la
operator|<=
name|lb
condition|)
while|while
condition|(
name|a
operator|<
name|aend
condition|)
operator|*
name|a
operator|++
operator|=
operator|*
name|b
operator|++
expr_stmt|;
else|else
block|{
name|bend
operator|=
name|b
operator|+
name|lb
expr_stmt|;
while|while
condition|(
name|b
operator|<
name|bend
condition|)
operator|*
name|a
operator|++
operator|=
operator|*
name|b
operator|++
expr_stmt|;
while|while
condition|(
name|a
operator|<
name|aend
condition|)
operator|*
name|a
operator|++
operator|=
literal|' '
expr_stmt|;
block|}
block|}
end_block

end_unit

