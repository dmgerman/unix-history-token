begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuLocate.c,v 10.4 86/02/01 16:15:24 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  *	XMenuLocate - Return data necessary to position and locate  *		      a menu on the screen.  *  *	Author:		Tony Della Fera, DEC  *			January 11, 1985  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function
name|int
name|XMenuLocate
parameter_list|(
name|menu
parameter_list|,
name|p_num
parameter_list|,
name|s_num
parameter_list|,
name|x_pos
parameter_list|,
name|y_pos
parameter_list|,
name|ul_x
parameter_list|,
name|ul_y
parameter_list|,
name|width
parameter_list|,
name|height
parameter_list|)
specifier|register
name|XMenu
modifier|*
name|menu
decl_stmt|;
comment|/* Menu object being located. */
name|int
name|p_num
decl_stmt|;
comment|/* Active pane number. */
name|int
name|s_num
decl_stmt|;
comment|/* Active selection number. */
name|int
name|x_pos
decl_stmt|;
comment|/* X coordinate of mouse active position. */
name|int
name|y_pos
decl_stmt|;
comment|/* Y coordinate of mouse active position. */
name|int
modifier|*
name|ul_x
decl_stmt|;
comment|/* Returned upper left menu X coordinate. */
name|int
modifier|*
name|ul_y
decl_stmt|;
comment|/* Returned upper left menu Y coordinate. */
name|int
modifier|*
name|width
decl_stmt|;
comment|/* Returned menu width. */
name|int
modifier|*
name|height
decl_stmt|;
comment|/* Returned menu height. */
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
comment|/*      * Are the position arguments positive?      */
if|if
condition|(
operator|(
name|x_pos
operator|<=
literal|0
operator|)
operator|||
operator|(
name|y_pos
operator|<=
literal|0
operator|)
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
comment|/*      * Check to see that the menu's dependencies have been      * recomputed and are up to date.  If not, do it now.      */
if|if
condition|(
name|menu
operator|->
name|recompute
condition|)
name|XMenuRecompute
argument_list|(
name|menu
argument_list|)
expr_stmt|;
comment|/*      * Compute the new menu origin such that the active point lies      * in the center of the desired active pane and selection.      * This sets the values of ul_x and ul_y.      */
name|_XMTransToOrigin
argument_list|(
name|menu
argument_list|,
name|p_ptr
argument_list|,
name|s_ptr
argument_list|,
name|x_pos
argument_list|,
name|y_pos
argument_list|,
name|ul_x
argument_list|,
name|ul_y
argument_list|)
expr_stmt|;
comment|/*      * Set remaining return argument values.      */
operator|*
name|width
operator|=
name|menu
operator|->
name|width
expr_stmt|;
operator|*
name|height
operator|=
name|menu
operator|->
name|height
expr_stmt|;
comment|/*      * Return successfully.      */
name|_XMErrorCode
operator|=
name|XME_NO_ERROR
expr_stmt|;
return|return
operator|(
name|XM_SUCCESS
operator|)
return|;
block|}
end_function

end_unit

