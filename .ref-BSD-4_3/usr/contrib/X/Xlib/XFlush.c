begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XFlush.c,v 10.4 86/02/01 15:33:43 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_comment
comment|/* Flush all buffered output requests. */
end_comment

begin_comment
comment|/* NOTE: NOT necessary when calling any of the Xlib routines. */
end_comment

begin_macro
name|XFlush
argument_list|()
end_macro

begin_block
block|{
name|_XFlush
argument_list|(
name|_XlibCurrentDisplay
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

