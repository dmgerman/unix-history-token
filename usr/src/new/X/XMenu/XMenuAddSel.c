begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuAddSel.c,v 10.8 86/02/12 16:18:33 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  * 	XMenuAddSelection - Adds a selection to an XMenu object.  *  *	Author:		Tony Della Fera, DEC  *			August, 1985  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function
name|int
name|XMenuAddSelection
parameter_list|(
name|menu
parameter_list|,
name|p_num
parameter_list|,
name|data
parameter_list|,
name|label
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
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Data value. */
name|char
modifier|*
name|label
decl_stmt|;
comment|/* Selection label. */
name|int
name|active
decl_stmt|;
comment|/* Make selection active? */
block|{
specifier|register
name|XMPane
modifier|*
name|pane
decl_stmt|;
comment|/* Pane containing the new selection. */
specifier|register
name|XMSelect
modifier|*
name|select
decl_stmt|;
comment|/* Newly created selection. */
specifier|register
name|int
name|i
decl_stmt|;
comment|/* Loop index. */
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
name|pane
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
name|pane
operator|==
name|NULL
condition|)
return|return
operator|(
name|XM_FAILURE
operator|)
return|;
comment|/*      * Calloc the XMSelect structure.      */
name|select
operator|=
operator|(
name|XMSelect
operator|*
operator|)
name|calloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|XMSelect
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|select
operator|==
name|NULL
condition|)
block|{
name|_XMErrorCode
operator|=
name|XME_CALLOC
expr_stmt|;
return|return
operator|(
name|XM_FAILURE
operator|)
return|;
block|}
comment|/*      * Determine label size.      */
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
comment|/*      * Fill the XMSelect structure.      */
name|select
operator|->
name|type
operator|=
name|SELECTION
expr_stmt|;
name|select
operator|->
name|active
operator|=
name|active
expr_stmt|;
name|select
operator|->
name|serial
operator|=
operator|-
literal|1
expr_stmt|;
name|select
operator|->
name|label
operator|=
name|label
expr_stmt|;
name|select
operator|->
name|label_width
operator|=
name|label_width
expr_stmt|;
name|select
operator|->
name|label_length
operator|=
name|label_length
expr_stmt|;
name|select
operator|->
name|data
operator|=
name|data
expr_stmt|;
name|select
operator|->
name|parent_p
operator|=
name|pane
expr_stmt|;
comment|/*      * Insert the selection at the end of the selection list.      */
name|insque
argument_list|(
name|select
argument_list|,
name|pane
operator|->
name|s_list
operator|->
name|prev
argument_list|)
expr_stmt|;
comment|/*      * Update the selection count.      */
name|pane
operator|->
name|s_count
operator|++
expr_stmt|;
comment|/*      * Schedule a recompute.      */
name|menu
operator|->
name|recompute
operator|=
literal|1
expr_stmt|;
comment|/*      * Return the selection number just added.      */
name|_XMErrorCode
operator|=
name|XME_NO_ERROR
expr_stmt|;
return|return
operator|(
operator|(
name|pane
operator|->
name|s_count
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_function

end_unit

