begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)erase.c	8.1 (Berkeley) %G%"
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
file|"grnplot.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	This routine erases the screen.  *  *	Results:	None.  *	Side Effects:	A new grn file is begun  *	but: it is concatentated to the old one.  *---------------------------------------------------------  */
end_comment

begin_macro
name|erase
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|ingrnfile
condition|)
block|{
name|closepl
argument_list|()
expr_stmt|;
name|fputs
argument_list|(
literal|"multiple grn files in output must be separated by hand!\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"sungremlinfile\n0.00 0.00\n"
argument_list|)
expr_stmt|;
name|ingrnfile
operator|=
literal|1
expr_stmt|;
name|invector
operator|=
literal|0
expr_stmt|;
name|scale
operator|=
literal|1
expr_stmt|;
name|curx
operator|=
name|cury
operator|=
name|xbot
operator|=
name|ybot
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

