begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XStName.c,v 11.15 91/01/08 14:42:00 gildea Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1986	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|<X11/Xlibint.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|XStoreName
argument_list|(
argument|register Display *dpy
argument_list|,
argument|Window w
argument_list|,
argument|_Xconst char *name
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|XStoreName
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|,
name|name
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Window
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|XChangeProperty
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|,
name|XA_WM_NAME
argument_list|,
name|XA_STRING
argument_list|,
literal|8
argument_list|,
name|PropModeReplace
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|name
argument_list|,
name|name
condition|?
name|strlen
argument_list|(
name|name
argument_list|)
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|XSetIconName
argument_list|(
argument|register Display *dpy
argument_list|,
argument|Window w
argument_list|,
argument|_Xconst char *icon_name
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|XSetIconName
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|,
name|icon_name
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Window
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|icon_name
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|XChangeProperty
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|,
name|XA_WM_ICON_NAME
argument_list|,
name|XA_STRING
argument_list|,
literal|8
argument_list|,
name|PropModeReplace
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|icon_name
argument_list|,
name|icon_name
condition|?
name|strlen
argument_list|(
name|icon_name
argument_list|)
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

