begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuChgSel.c,v 10.9 86/02/01 16:14:32 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  *	XMenuChangeSelection - Change a menu selection.  *  *	Author:		Tony Della Fera, DEC  *			December 19, 1985  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function
name|int
name|XMenuChangeSelection
parameter_list|(
name|menu
parameter_list|,
name|p_num
parameter_list|,
name|s_num
parameter_list|,
name|data
parameter_list|,
name|data_sw
parameter_list|,
name|label
parameter_list|,
name|label_sw
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
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Data value. */
name|int
name|data_sw
decl_stmt|;
comment|/* Change to new data value? */
name|char
modifier|*
name|label
decl_stmt|;
comment|/* Selection label. */
name|int
name|label_sw
decl_stmt|;
comment|/* Change to new label? */
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
name|int
name|label_length
decl_stmt|;
comment|/* Label lenght in characters. */
name|int
name|label_width
decl_stmt|;
comment|/* Label width in pixels. */
comment|/*      * Check for NULL pointers!      */
if|if
condition|(
name|label
operator|==
name|NULL
condition|)
block|{
name|_XMErrorCode
operator|=
name|XME_ARG_BOUNDS
expr_stmt|;
return|return
operator|(
name|XM_FAILURE
operator|)
return|;
block|}
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
comment|/*      * Reset the label?      */
if|if
condition|(
name|label_sw
condition|)
block|{
comment|/* 	 * Determine label size. 	 */
name|label_length
operator|=
name|strlen
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|label_width
operator|=
name|XQueryWidth
argument_list|(
name|label
argument_list|,
name|menu
operator|->
name|s_fnt_info
operator|->
name|id
argument_list|)
expr_stmt|;
comment|/* 	 * Change the selection data. 	 */
name|s_ptr
operator|->
name|label
operator|=
name|label
expr_stmt|;
name|s_ptr
operator|->
name|label_width
operator|=
name|label_width
expr_stmt|;
name|s_ptr
operator|->
name|label_length
operator|=
name|label_length
expr_stmt|;
comment|/* 	 * Schedule a recompute. 	 */
name|menu
operator|->
name|recompute
operator|=
literal|1
expr_stmt|;
block|}
comment|/*      * Reset the data?      */
if|if
condition|(
name|data_sw
condition|)
name|s_ptr
operator|->
name|data
operator|=
name|data
expr_stmt|;
comment|/*      * Return successfully.      */
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

