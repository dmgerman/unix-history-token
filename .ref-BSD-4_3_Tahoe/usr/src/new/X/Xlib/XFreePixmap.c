begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XFreePixmap.c,v 10.5 86/02/01 15:34:23 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_expr_stmt
name|XFreePixmap
argument_list|(
name|pixmap
argument_list|)
specifier|register
name|Pixmap
name|pixmap
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|Display
modifier|*
name|dpy
init|=
name|_XlibCurrentDisplay
decl_stmt|;
specifier|register
name|XReq
modifier|*
name|req
decl_stmt|;
if|if
condition|(
name|pixmap
operator|==
name|dpy
operator|->
name|black
operator|||
name|pixmap
operator|==
name|dpy
operator|->
name|white
condition|)
return|return;
comment|/* don't free the constant tile pixmaps! */
name|GetReq
argument_list|(
name|X_FreePixmap
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|req
operator|->
name|param
operator|.
name|l
index|[
literal|0
index|]
operator|=
name|pixmap
expr_stmt|;
return|return;
block|}
end_block

end_unit

