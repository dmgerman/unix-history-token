begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XSync.c,v 10.4 86/02/01 15:40:36 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_decl_stmt
specifier|extern
name|_QEvent
modifier|*
name|_qfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Synchronize with errors and events, optionally discarding pending events. */
end_comment

begin_macro
name|XSync
argument_list|(
argument|discard
argument_list|)
end_macro

begin_decl_stmt
name|int
name|discard
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 or 1 */
end_comment

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
name|XRep
name|rep
decl_stmt|;
name|GetReq
argument_list|(
name|X_SetUp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_XReply
argument_list|(
name|dpy
argument_list|,
operator|&
name|rep
argument_list|)
expr_stmt|;
if|if
condition|(
name|discard
operator|&&
name|dpy
operator|->
name|head
condition|)
block|{
name|dpy
operator|->
name|tail
operator|->
name|next
operator|=
name|_qfree
expr_stmt|;
name|_qfree
operator|=
name|dpy
operator|->
name|head
expr_stmt|;
name|dpy
operator|->
name|head
operator|=
name|dpy
operator|->
name|tail
operator|=
name|NULL
expr_stmt|;
name|dpy
operator|->
name|qlen
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_block

end_unit

