begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XLockToggle.c,v 10.4 86/02/01 15:36:10 tony Rel $ */
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
name|XLockToggle
argument_list|()
end_macro

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
name|X_ShiftLock
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|req
operator|->
name|func
operator|=
name|LockToggleMode
expr_stmt|;
block|}
end_block

end_unit

