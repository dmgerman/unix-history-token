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
literal|"@(#)yyseman.c	5.1 (Berkeley) 6/5/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree_ty.h"
end_include

begin_comment
comment|/* must be included for yy.h */
end_comment

begin_include
include|#
directive|include
file|"yy.h"
end_include

begin_comment
comment|/*  * Assign semantics to a generated token  *  * Most terminals have a semantic value the current  * input line.  If they are generated they are flagged  * by having this number negated.  *  * The terminals which have true semantics such  * as identifiers and strings are instead given  * semantic value NIL here - we do not attempt  * to do repair, e.g. by giving generated integers  * the value 1, etc.  */
end_comment

begin_macro
name|nullsem
argument_list|(
argument|ch
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ch
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
name|YID
case|:
case|case
name|YINT
case|:
case|case
name|YNUMB
case|:
case|case
name|YBINT
case|:
case|case
name|YSTRING
case|:
return|return
operator|(
name|NIL
operator|)
return|;
default|default:
return|return
operator|(
operator|-
name|yyeline
operator|)
return|;
block|}
block|}
end_block

end_unit

