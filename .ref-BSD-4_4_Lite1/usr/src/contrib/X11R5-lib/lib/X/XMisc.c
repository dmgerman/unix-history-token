begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XMisc.c,v 1.4 91/01/06 11:47:02 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1988	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_function
name|long
name|XMaxRequestSize
parameter_list|(
name|dpy
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
block|{
return|return
name|dpy
operator|->
name|max_request_size
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|XResourceManagerString
parameter_list|(
name|dpy
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
block|{
return|return
name|dpy
operator|->
name|xdefaults
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|XDisplayMotionBufferSize
parameter_list|(
name|dpy
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
block|{
return|return
name|dpy
operator|->
name|motion_buffer
return|;
block|}
end_function

begin_macro
name|XDisplayKeycodes
argument_list|(
argument|dpy
argument_list|,
argument|min_keycode_return
argument_list|,
argument|max_keycode_return
argument_list|)
end_macro

begin_decl_stmt
name|Display
modifier|*
name|dpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|min_keycode_return
decl_stmt|,
modifier|*
name|max_keycode_return
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|min_keycode_return
operator|=
name|dpy
operator|->
name|min_keycode
expr_stmt|;
operator|*
name|max_keycode_return
operator|=
name|dpy
operator|->
name|max_keycode
expr_stmt|;
block|}
end_block

begin_function
name|VisualID
name|XVisualIDFromVisual
parameter_list|(
name|visual
parameter_list|)
name|Visual
modifier|*
name|visual
decl_stmt|;
block|{
return|return
name|visual
operator|->
name|visualid
return|;
block|}
end_function

end_unit

