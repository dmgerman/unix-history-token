begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)linemod.c	6.1 (Berkeley) 8/29/86"
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
file|"grnplot.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	Linemod sets the current line drawing style.  *  *	Results:	None.  *  *	Side Effects:  *	The line style is set based on string s which  *	must be one of "dotted", "solid", "longdashed", "shortdashed",  *	or "dotdashed".  If s isn't recognized, then "solid" is used.  *---------------------------------------------------------  */
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
name|endvector
argument_list|()
expr_stmt|;
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
name|linestyle
operator|=
literal|1
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
name|linestyle
operator|=
literal|4
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
name|linestyle
operator|=
literal|4
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
name|linestyle
operator|=
literal|2
expr_stmt|;
else|else
name|linestyle
operator|=
name|DEFAULTLINE
expr_stmt|;
block|}
end_block

end_unit

