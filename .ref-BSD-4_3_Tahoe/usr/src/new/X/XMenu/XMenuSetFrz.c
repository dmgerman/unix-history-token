begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuSetFrz.c,v 10.3 86/02/12 16:19:56 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  *	XMenuSetFreeze - Forcibly set the menu freeze mode switch  *			 overriding the Xdefaults setting.  *			 This is necessary in some situations.  *  *	Author:		Tony Della Fera, DEC  *			January 29, 1986  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_expr_stmt
name|XMenuSetFreeze
argument_list|(
name|menu
argument_list|,
name|freeze
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
name|freeze
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Freeze mode? */
end_comment

begin_block
block|{
comment|/*      * Set the freeze mode switch.      */
name|menu
operator|->
name|freeze
operator|=
name|freeze
expr_stmt|;
block|}
end_block

end_unit

