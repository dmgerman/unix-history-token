begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XSetDisplay.c,v 10.4 86/02/01 15:39:42 tony Rel $ */
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
comment|/*   * XSetDisplay - This proceedure sets the current display (_XlibCurrentDisplay)  * with which the library is communicating.  */
end_comment

begin_expr_stmt
name|XSetDisplay
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
name|_XlibCurrentDisplay
operator|=
name|dpy
expr_stmt|;
block|}
end_block

end_unit

