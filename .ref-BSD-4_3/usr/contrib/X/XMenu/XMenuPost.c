begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuPost.c,v 10.5 86/02/01 16:15:27 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  *	XMenuPost -	Maps a given menu to the display and activates  *			the menu for user selection.  The user is allowed to  *			specify the mouse button event mask that will be used  *			to identify a selection request.  When a selection   *			request is recieved (i.e., when the specified mouse  *			event occurs) the data  returned will be either the  *			data associated with the particular selection active  *			at the time of the selection request or NULL if no  *			selection was active.  A menu selection is shown to  *			be active by placing a highlight box around the  *			selection as the mouse cursor enters its active  *			region.  Inactive selections will not be highlighted.  *			As the mouse cursor moved from one menu pane  *			to another menu pane the pane being entered is raised  *			and activated and the pane being left is inactivated.  *			If an error occurs NULL will be returned with the  *			p_num set to POST_ERROR, s_num set to  *			NO_SELECTION and _XMErrorCode set to an  *			appropriate value.  *			Every time the routine returns successfully the  *			p_num and s_num indices will be set to indicate  *			the currently active pane and/or selection.  If the  *			mouse was not in a selection window at the time  *			s_num will be set to NO_SELECTION.  *  *	Author:		Tony Della Fera, DEC  *			August, 1984  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function
name|char
modifier|*
name|XMenuPost
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
name|event_mask
parameter_list|)
specifier|register
name|XMenu
modifier|*
name|menu
decl_stmt|;
comment|/* Menu to post. */
specifier|register
name|int
modifier|*
name|p_num
decl_stmt|;
comment|/* Pane number selected. */
specifier|register
name|int
modifier|*
name|s_num
decl_stmt|;
comment|/* Selection number selected. */
specifier|register
name|int
name|x_pos
decl_stmt|;
comment|/* X coordinate of menu position. */
specifier|register
name|int
name|y_pos
decl_stmt|;
comment|/* Y coordinate of menu position. */
name|int
name|event_mask
decl_stmt|;
comment|/* Mouse button event mask. */
block|{
specifier|register
name|int
name|stat
decl_stmt|;
comment|/* Routine call return status. */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Return data. */
comment|/*      * Set up initial pane and selection assumptions.      */
operator|*
name|p_num
operator|=
literal|0
expr_stmt|;
operator|*
name|s_num
operator|=
literal|0
expr_stmt|;
comment|/*      * Make the proceedure call.      */
name|stat
operator|=
name|XMenuActivate
argument_list|(
name|menu
argument_list|,
name|p_num
argument_list|,
name|s_num
argument_list|,
name|x_pos
argument_list|,
name|y_pos
argument_list|,
name|event_mask
argument_list|,
operator|&
name|data
argument_list|)
expr_stmt|;
comment|/*      * Check the return value and return accordingly.      */
switch|switch
condition|(
name|stat
condition|)
block|{
case|case
name|XM_FAILURE
case|:
operator|*
name|p_num
operator|=
name|POST_ERROR
expr_stmt|;
operator|*
name|s_num
operator|=
name|NO_SELECTION
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
case|case
name|XM_NO_SELECT
case|:
case|case
name|XM_IA_SELECT
case|:
operator|*
name|s_num
operator|=
name|NO_SELECTION
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
case|case
name|XM_SUCCESS
case|:
default|default:
return|return
operator|(
name|data
operator|)
return|;
block|}
block|}
end_function

end_unit

