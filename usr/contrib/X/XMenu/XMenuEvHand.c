begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuEvHand.c,v 10.7 86/02/01 16:14:56 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  * 	XMenuEventHandler - Set the XMenu asynchronous event handler.  *  *	Author:		Tony Della Fera, DEC  *			December 19, 1985  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function_decl
name|XMenuEventHandler
function_decl|(
name|handler
function_decl|)
name|int
argument_list|(
argument|*handler
argument_list|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
comment|/*      * Set the global event handler variable.      */
name|_XMEventHandler
operator|=
name|handler
expr_stmt|;
block|}
end_block

end_unit

