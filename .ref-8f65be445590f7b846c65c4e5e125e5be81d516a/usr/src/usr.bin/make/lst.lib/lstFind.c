begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)lstFind.c	5.3 (Berkeley) %G%"
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

begin_decl_stmt
name|LstNode
name|Lst_Find
argument_list|(
name|l
argument_list|,
name|d
argument_list|,
name|cProc
argument_list|)
name|Lst
name|l
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ClientData
name|d
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|cProc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

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

