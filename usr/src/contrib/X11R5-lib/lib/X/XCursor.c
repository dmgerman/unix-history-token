begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XCursor.c,v 11.14 91/01/06 11:45:02 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1987	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_decl_stmt
specifier|static
name|XColor
name|foreground
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* black */
end_comment

begin_decl_stmt
specifier|static
name|XColor
name|background
init|=
block|{
literal|0
block|,
literal|65535
block|,
literal|65535
block|,
literal|65535
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* white */
end_comment

begin_function
name|Cursor
name|XCreateFontCursor
parameter_list|(
name|dpy
parameter_list|,
name|which
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
name|unsigned
name|int
name|which
decl_stmt|;
block|{
comment|/*  	 * the cursor font contains the shape glyph followed by the mask 	 * glyph; so character position 0 contains a shape, 1 the mask for 0, 	 * 2 a shape, etc.<X11/cursorfont.h> contains hash define names 	 * for all of these. 	 */
if|if
condition|(
name|dpy
operator|->
name|cursor_font
operator|==
name|None
condition|)
block|{
name|dpy
operator|->
name|cursor_font
operator|=
name|XLoadFont
argument_list|(
name|dpy
argument_list|,
name|CURSORFONT
argument_list|)
expr_stmt|;
if|if
condition|(
name|dpy
operator|->
name|cursor_font
operator|==
name|None
condition|)
return|return
name|None
return|;
block|}
return|return
name|XCreateGlyphCursor
argument_list|(
name|dpy
argument_list|,
name|dpy
operator|->
name|cursor_font
argument_list|,
name|dpy
operator|->
name|cursor_font
argument_list|,
name|which
argument_list|,
name|which
operator|+
literal|1
argument_list|,
operator|&
name|foreground
argument_list|,
operator|&
name|background
argument_list|)
return|;
block|}
end_function

end_unit

