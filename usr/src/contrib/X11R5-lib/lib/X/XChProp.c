begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XChProp.c,v 11.22 91/01/06 11:44:22 rws Exp $ */
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
file|"Xlibint.h"
end_include

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|XChangeProperty
argument_list|(
argument|register Display *dpy
argument_list|,
argument|Window w
argument_list|,
argument|Atom property
argument_list|,
argument|Atom type
argument_list|,
argument|int format
argument_list|,
comment|/* 8, 16, or 32 */
argument|int mode
argument_list|,
comment|/* PropModeReplace, PropModePrepend, PropModeAppend */
argument|_Xconst unsigned char *data
argument_list|,
argument|int nelements
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|XChangeProperty
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|,
name|property
argument_list|,
name|type
argument_list|,
name|format
argument_list|,
name|mode
argument_list|,
name|data
argument_list|,
name|nelements
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
name|Atom
name|property
decl_stmt|,
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 8, 16, or 32 */
end_comment

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PropModeReplace, PropModePrepend, PropModeAppend */
end_comment

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nelements
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|xChangePropertyReq
modifier|*
name|req
decl_stmt|;
specifier|register
name|long
name|len
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|GetReq
argument_list|(
name|ChangeProperty
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|window
operator|=
name|w
expr_stmt|;
name|req
operator|->
name|property
operator|=
name|property
expr_stmt|;
name|req
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|req
operator|->
name|format
operator|=
name|format
expr_stmt|;
name|req
operator|->
name|mode
operator|=
name|mode
expr_stmt|;
if|if
condition|(
name|nelements
operator|<
literal|0
condition|)
block|{
name|req
operator|->
name|nUnits
operator|=
literal|0
expr_stmt|;
name|req
operator|->
name|format
operator|=
literal|0
expr_stmt|;
comment|/* ask for garbage, get garbage */
block|}
else|else
name|req
operator|->
name|nUnits
operator|=
name|nelements
expr_stmt|;
switch|switch
condition|(
name|format
condition|)
block|{
case|case
literal|8
case|:
name|len
operator|=
name|req
operator|->
name|length
operator|+
operator|(
operator|(
operator|(
name|long
operator|)
name|nelements
operator|+
literal|3
operator|)
operator|>>
literal|2
operator|)
expr_stmt|;
if|if
condition|(
name|len
operator|<=
literal|65535
condition|)
block|{
name|req
operator|->
name|length
operator|=
name|len
expr_stmt|;
name|Data
argument_list|(
name|dpy
argument_list|,
operator|(
name|char
operator|*
operator|)
name|data
argument_list|,
name|nelements
argument_list|)
expr_stmt|;
block|}
comment|/* else force BadLength */
break|break;
case|case
literal|16
case|:
name|len
operator|=
name|req
operator|->
name|length
operator|+
operator|(
operator|(
operator|(
name|long
operator|)
name|nelements
operator|+
literal|1
operator|)
operator|>>
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|len
operator|<=
literal|65535
condition|)
block|{
name|req
operator|->
name|length
operator|=
name|len
expr_stmt|;
name|len
operator|=
operator|(
name|long
operator|)
name|nelements
operator|<<
literal|1
expr_stmt|;
name|Data16
argument_list|(
name|dpy
argument_list|,
operator|(
name|short
operator|*
operator|)
name|data
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
comment|/* else force BadLength */
break|break;
case|case
literal|32
case|:
name|len
operator|=
name|req
operator|->
name|length
operator|+
operator|(
name|long
operator|)
name|nelements
expr_stmt|;
if|if
condition|(
name|len
operator|<=
literal|65535
condition|)
block|{
name|req
operator|->
name|length
operator|=
name|len
expr_stmt|;
name|len
operator|=
operator|(
name|long
operator|)
name|nelements
operator|<<
literal|2
expr_stmt|;
name|Data32
argument_list|(
name|dpy
argument_list|,
operator|(
name|long
operator|*
operator|)
name|data
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
comment|/* else force BadLength */
break|break;
default|default:
comment|/* BadValue will be generated */
empty_stmt|;
block|}
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|SyncHandle
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

