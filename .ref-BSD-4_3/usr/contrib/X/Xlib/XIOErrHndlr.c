begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XIOErrHndlr.c,v 10.4 86/02/01 15:35:36 tony Rel $ */
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
comment|/*   * XIOErrorHandler - This proceedure sets the X fatal I/O error handler  * (_XIOErrorFunction) to be the specified routine.  If NULL is passed in   * the original error handler is restored.  */
end_comment

begin_expr_stmt
name|XIOErrorHandler
argument_list|(
name|handler
argument_list|)
specifier|register
name|int
argument_list|(
operator|*
name|handler
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|handler
operator|!=
name|NULL
condition|)
block|{
name|_XIOErrorFunction
operator|=
name|handler
expr_stmt|;
block|}
else|else
block|{
name|_XIOErrorFunction
operator|=
name|_XIOError
expr_stmt|;
block|}
block|}
end_block

end_unit

