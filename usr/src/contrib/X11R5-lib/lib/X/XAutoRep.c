begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XAutoRep.c,v 11.9 91/01/06 11:44:08 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_expr_stmt
name|XAutoRepeatOn
argument_list|(
name|dpy
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|XKeyboardControl
name|values
decl_stmt|;
name|values
operator|.
name|auto_repeat_mode
operator|=
name|AutoRepeatModeOn
expr_stmt|;
name|XChangeKeyboardControl
argument_list|(
name|dpy
argument_list|,
name|KBAutoRepeatMode
argument_list|,
operator|&
name|values
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|XAutoRepeatOff
argument_list|(
name|dpy
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|XKeyboardControl
name|values
decl_stmt|;
name|values
operator|.
name|auto_repeat_mode
operator|=
name|AutoRepeatModeOff
expr_stmt|;
name|XChangeKeyboardControl
argument_list|(
name|dpy
argument_list|,
name|KBAutoRepeatMode
argument_list|,
operator|&
name|values
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

