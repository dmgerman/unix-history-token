begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstForeach.c --  *	Perform a given function on all elements of a list.  *  * Copyright (c) 1988 by University of California Regents  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: lstForEach.c,v 1.8 89/11/14 16:59:42 adam Exp $ SPRITE (Berkeley)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_ForEach --  *	Apply the given function to each element of the given list. The  *	function should return 0 if Lst_ForEach should continue and non-  *	zero if it should abort.  *  * Results:  *	None.  *  * Side Effects:  *	Only those created by the passed-in function.  *  *-----------------------------------------------------------------------  */
end_comment

begin_comment
comment|/*VARARGS2*/
end_comment

begin_decl_stmt
name|void
name|Lst_ForEach
argument_list|(
name|l
argument_list|,
name|proc
argument_list|,
name|d
argument_list|)
name|Lst
name|l
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|register
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|register
name|ClientData
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|Lst_ForEachFrom
argument_list|(
name|l
argument_list|,
name|Lst_First
argument_list|(
name|l
argument_list|)
argument_list|,
name|proc
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

