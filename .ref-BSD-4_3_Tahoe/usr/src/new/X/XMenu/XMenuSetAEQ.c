begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuSetAEQ.c,v 10.1 86/03/12 11:42:28 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  *	XMenuSetAEQ - Set Asynchronous event queueing mode.  *		      When enabled asynchronous events will be queue while  *		      a menu is being displayed and restored to the X  *		      event queue when the menu is taken down.  *  *	Author:		Tony Della Fera, DEC  *			March 12, 1986  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_expr_stmt
name|XMenuSetAEQ
argument_list|(
name|menu
argument_list|,
name|aeq
argument_list|)
specifier|register
name|XMenu
operator|*
name|menu
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Menu object to be modified. */
end_comment

begin_decl_stmt
specifier|register
name|int
name|aeq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AEQ mode? */
end_comment

begin_block
block|{
comment|/*      * Set the AEQ mode switch.      */
name|menu
operator|->
name|aeq
operator|=
name|aeq
expr_stmt|;
block|}
end_block

end_unit

