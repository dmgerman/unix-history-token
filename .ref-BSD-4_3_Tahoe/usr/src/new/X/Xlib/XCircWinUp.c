begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XCircWinUp.c,v 10.4 86/02/01 15:30:15 tony Rel $ */
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
name|XCircWindowUp
argument_list|(
name|w
argument_list|)
specifier|register
name|Window
name|w
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|Display
modifier|*
name|dpy
decl_stmt|;
specifier|register
name|XReq
modifier|*
name|req
decl_stmt|;
name|GetReq
argument_list|(
name|X_CircWindowUp
argument_list|,
name|w
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

