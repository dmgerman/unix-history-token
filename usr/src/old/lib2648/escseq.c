begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)escseq.c	5.1 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * escseq: get us out of any escape sequence we are in the middle of  * and put us into the requested kind of escape sequence.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|escseq
argument_list|(
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|mode
operator|==
name|_escmode
condition|)
return|return;
comment|/* Get out of previous mode */
switch|switch
condition|(
name|_escmode
condition|)
block|{
case|case
name|NONE
case|:
break|break;
case|case
name|ESCD
case|:
if|if
condition|(
name|mode
operator|==
name|TEXT
condition|)
block|{
name|outchar
argument_list|(
literal|'s'
argument_list|)
expr_stmt|;
name|_escmode
operator|=
name|mode
expr_stmt|;
return|return;
block|}
case|case
name|ESCP
case|:
case|case
name|ESCM
case|:
name|outchar
argument_list|(
literal|'Z'
argument_list|)
expr_stmt|;
comment|/* no-op */
break|break;
case|case
name|TEXT
case|:
name|outstr
argument_list|(
literal|"\33*dT"
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* Get into new mode */
switch|switch
condition|(
name|_escmode
operator|=
name|mode
condition|)
block|{
case|case
name|NONE
case|:
break|break;
case|case
name|ESCD
case|:
name|outstr
argument_list|(
literal|"\33*d"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ESCP
case|:
name|outstr
argument_list|(
literal|"\33*p"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ESCM
case|:
name|outstr
argument_list|(
literal|"\33*m"
argument_list|)
expr_stmt|;
break|break;
case|case
name|TEXT
case|:
name|outstr
argument_list|(
literal|"\33*dS"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_block

end_unit

