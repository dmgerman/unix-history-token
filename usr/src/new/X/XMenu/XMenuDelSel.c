begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuDelSel.c,v 10.8 86/02/12 16:19:00 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  * 	XMenuDeleteSelection - Deletes a selection from an XMenu object.  *  *	Author:		Tony Della Fera, DEC  *			20-Nov-85  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function
name|int
name|XMenuDeleteSelection
parameter_list|(
name|menu
parameter_list|,
name|p_num
parameter_list|,
name|s_num
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
comment|/* Pane number to be deleted. */
specifier|register
name|int
name|s_num
decl_stmt|;
comment|/* Selection number to be deleted. */
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* Loop index. */
specifier|register
name|XMPane
modifier|*
name|p_ptr
decl_stmt|;
comment|/* Pointer to pane being deleted. */
specifier|register
name|XMSelect
modifier|*
name|s_ptr
decl_stmt|;
comment|/* Pointer to selections being deleted. */
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
comment|/*      * Remove the selection from the association table.      */
name|XDeleteAssoc
argument_list|(
name|menu
operator|->
name|assoc_tab
argument_list|,
name|s_ptr
operator|->
name|window
argument_list|)
expr_stmt|;
comment|/*      * Remove the selection from the parent pane's selection      * list and update the selection count.      */
name|remque
argument_list|(
name|s_ptr
argument_list|)
expr_stmt|;
name|p_ptr
operator|->
name|s_count
operator|--
expr_stmt|;
comment|/*      * Destroy the selection transparency.      */
if|if
condition|(
name|s_ptr
operator|->
name|window
condition|)
name|XDestroyWindow
argument_list|(
name|s_ptr
operator|->
name|window
argument_list|)
expr_stmt|;
comment|/*      * Free the selection's XMSelect structure.      */
name|free
argument_list|(
name|s_ptr
argument_list|)
expr_stmt|;
comment|/*      * Schedule a recompute.      */
name|menu
operator|->
name|recompute
operator|=
literal|1
expr_stmt|;
comment|/*      * Return the selection number just deleted.      */
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

