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

begin_include
include|#
directive|include
file|"aed.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	Linemod sets the current line drawing style.  *  *	Results:	None.  *  *	Side Effects:  *	The AED line style is set based on string s which  *	must be one of "dotted", "solid", "longdashed", "shortdashed",  *	or "dotdashed".  If s isn't recognized, then "solid" is used.  *---------------------------------------------------------  */
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
if|if
condition|(
name|strcmp
argument_list|(
name|s
argument_list|,
literal|"dotted"
argument_list|)
operator|==
literal|0
condition|)
name|fputs
argument_list|(
literal|"1AAFF"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|s
argument_list|,
literal|"longdashed"
argument_list|)
operator|==
literal|0
condition|)
name|fputs
argument_list|(
literal|"1F055"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|s
argument_list|,
literal|"shortdashed"
argument_list|)
operator|==
literal|0
condition|)
name|fputs
argument_list|(
literal|"1F0FF"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|s
argument_list|,
literal|"dotdashed"
argument_list|)
operator|==
literal|0
condition|)
name|fputs
argument_list|(
literal|"1E4FF"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
else|else
name|fputs
argument_list|(
literal|"1FFFF"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

