begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuDelPane.c,v 10.8 86/02/01 16:14:44 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  * 	XMenuDeletePane - Deletes a pane from an XMenu object.  *  *	Author:		Tony Della Fera, DEC  *			20-Nov-85  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function
name|int
name|XMenuDeletePane
parameter_list|(
name|menu
parameter_list|,
name|p_num
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
comment|/*      * Remove the pane from the association table.      */
name|XDeleteAssoc
argument_list|(
name|menu
operator|->
name|assoc_tab
argument_list|,
name|p_ptr
operator|->
name|window
argument_list|)
expr_stmt|;
comment|/*      * Remove the pane from the pane list and update      * the pane count.      */
name|remque
argument_list|(
name|p_ptr
argument_list|)
expr_stmt|;
name|menu
operator|->
name|p_count
operator|--
expr_stmt|;
comment|/*      * Remove all the selections in the pane from the      * association table and free their XMSelect structures.      */
name|s_ptr
operator|=
name|p_ptr
operator|->
name|s_list
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|p_ptr
operator|->
name|s_count
condition|;
name|i
operator|++
control|)
block|{
name|XDeleteAssoc
argument_list|(
name|menu
operator|->
name|assoc_tab
argument_list|,
name|s_ptr
operator|->
name|prev
operator|->
name|window
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|s_ptr
operator|->
name|prev
argument_list|)
expr_stmt|;
name|s_ptr
operator|=
name|s_ptr
operator|->
name|next
expr_stmt|;
block|}
name|free
argument_list|(
name|s_ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|p_ptr
operator|->
name|window
condition|)
block|{
comment|/* 	 * Destroy the selection transparencies. 	 */
name|XDestroySubwindows
argument_list|(
name|p_ptr
operator|->
name|window
argument_list|)
expr_stmt|;
comment|/* 	 * Destroy the pane window. 	 */
name|XDestroyWindow
argument_list|(
name|p_ptr
operator|->
name|window
argument_list|)
expr_stmt|;
block|}
comment|/*      * Free the pane's XMPane structure.      */
name|free
argument_list|(
name|p_ptr
argument_list|)
expr_stmt|;
comment|/*      * Schedule a recompute.      */
name|menu
operator|->
name|recompute
operator|=
literal|1
expr_stmt|;
comment|/*      * Return the pane number just deleted.      */
name|_XMErrorCode
operator|=
name|XME_NO_ERROR
expr_stmt|;
return|return
operator|(
name|p_num
operator|)
return|;
block|}
end_function

end_unit

