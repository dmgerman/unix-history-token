begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuSetSel.c,v 10.6 86/02/01 16:15:40 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  *	XMenuSetSelection - Set a menu selection to be active or inactive.  *  *	Author:		Tony Della Fera, DEC  *			August, 1985  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function
name|int
name|XMenuSetSelection
parameter_list|(
name|menu
parameter_list|,
name|p_num
parameter_list|,
name|s_num
parameter_list|,
name|active
parameter_list|)
specifier|register
name|XMenu
modifier|*
name|menu
decl_stmt|;
comment|/* Menu object to be modified. */
specifier|register
name|int
name|p_num
decl_stmt|;
comment|/* Pane number to be modified. */
specifier|register
name|int
name|s_num
decl_stmt|;
comment|/* Selection number to modified. */
name|int
name|active
decl_stmt|;
comment|/* Make selection active? */
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* Loop counter. */
specifier|register
name|XMPane
modifier|*
name|p_ptr
decl_stmt|;
comment|/* XMPane pointer. */
specifier|register
name|XMSelect
modifier|*
name|s_ptr
decl_stmt|;
comment|/* XMSelect pointer. */
comment|/*      * Find the right pane.      */
name|p_ptr
operator|=
name|_XMGetPanePtr
argument_list|(
name|menu
argument_list|,
name|p_num
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_ptr
operator|==
name|NULL
condition|)
return|return
operator|(
name|XM_FAILURE
operator|)
return|;
comment|/*      * Find the right selection.      */
name|s_ptr
operator|=
name|_XMGetSelectionPtr
argument_list|(
name|p_ptr
argument_list|,
name|s_num
argument_list|)
expr_stmt|;
if|if
condition|(
name|s_ptr
operator|==
name|NULL
condition|)
return|return
operator|(
name|XM_FAILURE
operator|)
return|;
comment|/*      * Set its active switch.      */
name|s_ptr
operator|->
name|active
operator|=
name|active
expr_stmt|;
comment|/*      * Return the selection number just set.      */
name|_XMErrorCode
operator|=
name|XME_NO_ERROR
expr_stmt|;
return|return
operator|(
name|s_num
operator|)
return|;
block|}
end_function

end_unit

