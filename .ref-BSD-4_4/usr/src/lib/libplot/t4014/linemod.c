begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)linemod.c	8.1 (Berkeley) 6/4/93"
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
name|linemod
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|c
decl_stmt|;
name|putch
argument_list|(
literal|033
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|s
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|'l'
case|:
name|c
operator|=
literal|'d'
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
if|if
condition|(
name|s
index|[
literal|3
index|]
operator|!=
literal|'d'
condition|)
name|c
operator|=
literal|'a'
expr_stmt|;
else|else
name|c
operator|=
literal|'b'
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
if|if
condition|(
name|s
index|[
literal|5
index|]
operator|!=
literal|'\0'
condition|)
name|c
operator|=
literal|'c'
expr_stmt|;
else|else
name|c
operator|=
literal|'`'
expr_stmt|;
block|}
name|putch
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

