begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)lstFind.c	8.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*-  * LstFind.c --  *	Find a node on a list.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Find --  *	Find a node on the given list using the given comparison function  *	and the given datum.  *  * Results:  *	The found node or NILLNODE if none matches.  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function_decl
name|LstNode
name|Lst_Find
parameter_list|(
name|l
parameter_list|,
name|d
parameter_list|,
name|cProc
parameter_list|)
name|Lst
name|l
decl_stmt|;
name|ClientData
name|d
decl_stmt|;
function_decl|int
parameter_list|(
function_decl|*cProc
end_function_decl

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|ClientData
operator|,
name|ClientData
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
operator|(
name|Lst_FindFrom
argument_list|(
name|l
argument_list|,
name|Lst_First
argument_list|(
name|l
argument_list|)
argument_list|,
name|d
argument_list|,
name|cProc
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

