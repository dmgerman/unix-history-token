begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_MoveOpaque_c
init|=
literal|"$Header: MoveOpaque.c,v 10.4 86/11/19 16:24:08 jg Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  *			COPYRIGHT 1985, 1986  *		   DIGITAL EQUIPMENT CORPORATION  *		       MAYNARD, MASSACHUSETTS  *			ALL RIGHTS RESERVED.  *  * THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT NOTICE AND  * SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL EQUIPMENT CORPORATION.  * DIGITAL MAKES NO REPRESENTATIONS ABOUT THE SUITIBILITY OF THIS SOFTWARE FOR  * ANY PURPOSE.  IT IS SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.  *  * IF THE SOFTWARE IS MODIFIED IN A MANNER CREATING DERIVATIVE COPYRIGHT RIGHTS,  * APPROPRIATE LEGENDS MAY BE PLACED ON THE DERIVATIVE WORK IN ADDITION TO THAT  * SET FORTH ABOVE.  *  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting documentation,  * and that the name of Digital Equipment Corporation not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission.  *  */
end_comment

begin_comment
comment|/*  * MODIFICATION HISTORY  *  * 000 -- M. Gancarz, DEC Ultrix Engineering Group  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)MoveOpaque.c	1.7	1/24/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uwm.h"
end_include

begin_function
name|Bool
name|MoveOpaque
parameter_list|(
name|window
parameter_list|,
name|mask
parameter_list|,
name|button
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
name|Window
name|window
decl_stmt|;
comment|/* Event window. */
name|int
name|mask
decl_stmt|;
comment|/* Button/key mask. */
name|short
name|button
decl_stmt|;
comment|/* Button event detail. */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* Event mouse position. */
block|{
name|int
name|prev_x
decl_stmt|,
name|prev_y
decl_stmt|;
comment|/* Previous mouse location. */
name|int
name|cur_x
decl_stmt|,
name|cur_y
decl_stmt|;
comment|/* Current mouse location. */
name|int
name|win_x
decl_stmt|,
name|win_y
decl_stmt|;
comment|/* Current window location. */
name|WindowInfo
name|window_info
decl_stmt|;
comment|/* Event window information. */
name|Window
name|sub_window
decl_stmt|;
comment|/* Query mouse event sub-window. */
name|XButtonEvent
name|button_event
decl_stmt|;
comment|/* Button event packet. */
comment|/*      * Do not try to move the root window.      */
if|if
condition|(
name|window
operator|==
name|RootWindow
condition|)
return|return
operator|(
name|FALSE
operator|)
return|;
comment|/*      * Change the cursor.      */
name|status
operator|=
name|XGrabButton
argument_list|(
name|RootWindow
argument_list|,
name|ArrowCrossCursor
argument_list|,
name|mask
argument_list|,
name|EVENTMASK
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|FAILURE
condition|)
name|Error
argument_list|(
literal|"MoveOpaque -> Unable to grab button and change cursor."
argument_list|)
expr_stmt|;
comment|/*      * Gather info on the event window.      */
name|status
operator|=
name|XQueryWindow
argument_list|(
name|window
argument_list|,
operator|&
name|window_info
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|FAILURE
condition|)
return|return
operator|(
name|FALSE
operator|)
return|;
comment|/*      * Initialize movement variables.      */
name|prev_x
operator|=
name|cur_x
operator|=
name|x
expr_stmt|;
name|prev_y
operator|=
name|cur_y
operator|=
name|y
expr_stmt|;
name|win_x
operator|=
name|window_info
operator|.
name|x
expr_stmt|;
name|win_y
operator|=
name|window_info
operator|.
name|y
expr_stmt|;
comment|/*      * Main loop.      */
while|while
condition|(
name|TRUE
condition|)
block|{
comment|/* 	 * Check to see if we have a change in mouse button status. 	 * This is how we get out of this "while" loop. 	 */
if|if
condition|(
name|XPending
argument_list|()
operator|&&
name|GetButton
argument_list|(
operator|&
name|button_event
argument_list|)
condition|)
block|{
comment|/* 	     * If the button event was something other than the              * release of the original button pressed, then move the              * window back to where it was originally. 	     */
if|if
condition|(
operator|(
name|button_event
operator|.
name|type
operator|!=
name|ButtonReleased
operator|)
operator|||
operator|(
operator|(
name|button_event
operator|.
name|detail
operator|&
name|ValueMask
operator|)
operator|!=
name|button
operator|)
condition|)
name|XMoveWindow
argument_list|(
name|window
argument_list|,
name|window_info
operator|.
name|x
argument_list|,
name|window_info
operator|.
name|y
argument_list|)
expr_stmt|;
comment|/*              * Reset the cursor and return.              */
name|Grab
argument_list|(
name|mask
argument_list|)
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
comment|/*          * Take care of all the little things that have changed;           * i.e., move the window, if necessary.          */
name|XUpdateMouse
argument_list|(
name|RootWindow
argument_list|,
operator|&
name|cur_x
argument_list|,
operator|&
name|cur_y
argument_list|,
operator|&
name|sub_window
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|cur_x
operator|!=
name|prev_x
operator|)
operator|||
operator|(
name|cur_y
operator|!=
name|prev_y
operator|)
condition|)
block|{
name|win_x
operator|+=
operator|(
name|cur_x
operator|-
name|prev_x
operator|)
expr_stmt|;
name|win_y
operator|+=
operator|(
name|cur_y
operator|-
name|prev_y
operator|)
expr_stmt|;
name|XMoveWindow
argument_list|(
name|window
argument_list|,
name|win_x
argument_list|,
name|win_y
argument_list|)
expr_stmt|;
name|prev_x
operator|=
name|cur_x
expr_stmt|;
name|prev_y
operator|=
name|cur_y
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

