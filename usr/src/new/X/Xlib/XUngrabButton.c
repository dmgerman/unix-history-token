begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XUngrabButton.c,v 10.4 86/02/01 15:41:18 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_macro
name|XUngrabButton
argument_list|(
argument|mask
argument_list|)
end_macro

begin_decl_stmt
name|int
name|mask
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|XReq
modifier|*
name|req
decl_stmt|;
specifier|register
name|Display
modifier|*
name|dpy
decl_stmt|;
name|GetReq
argument_list|(
name|X_UngrabButton
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|req
operator|->
name|mask
operator|=
name|mask
expr_stmt|;
block|}
end_block

end_unit

