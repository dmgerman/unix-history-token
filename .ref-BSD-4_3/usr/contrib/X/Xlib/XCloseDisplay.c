begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XCloseDisplay.c,v 10.4 86/02/01 15:30:31 tony Rel $ */
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
comment|/*   * XCloseDisplay - XSync the connection to the X Server, close the connection,  * and free all associated storage.  Signals must be masked out during this  * operation to guarantee atomicity.  */
end_comment

begin_expr_stmt
name|XCloseDisplay
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
specifier|register
name|int
name|sig_mask
decl_stmt|;
comment|/*  	 * Mask out all signals so that the library internal state can 	 * be sync'ed with the rest of the world.  We don't want to be 	 * interupted while we are flushing and freeing buffers. 	 */
name|sig_mask
operator|=
name|sigsetmask
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|XSync
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|close
argument_list|(
name|dpy
operator|->
name|fd
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Argh! someone already closed the descriptor! */
name|_XIOError
argument_list|(
name|_XlibCurrentDisplay
argument_list|)
expr_stmt|;
block|}
name|sigsetmask
argument_list|(
name|sig_mask
argument_list|)
expr_stmt|;
comment|/* Return signals to normal. */
if|if
condition|(
name|dpy
operator|->
name|displayname
condition|)
name|free
argument_list|(
name|dpy
operator|->
name|displayname
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|dpy
operator|->
name|buffer
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

