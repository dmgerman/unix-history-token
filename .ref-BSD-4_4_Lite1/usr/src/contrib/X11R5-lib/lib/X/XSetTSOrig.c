begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XSetTSOrig.c,v 11.4 91/01/06 11:48:15 rws Exp $ */
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

begin_expr_stmt
name|XSetTSOrigin
argument_list|(
name|dpy
argument_list|,
name|gc
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|GC
name|gc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|XGCValues
modifier|*
name|gv
init|=
operator|&
name|gc
operator|->
name|values
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|!=
name|gv
operator|->
name|ts_x_origin
condition|)
block|{
name|gv
operator|->
name|ts_x_origin
operator|=
name|x
expr_stmt|;
name|gc
operator|->
name|dirty
operator||=
name|GCTileStipXOrigin
expr_stmt|;
block|}
if|if
condition|(
name|y
operator|!=
name|gv
operator|->
name|ts_y_origin
condition|)
block|{
name|gv
operator|->
name|ts_y_origin
operator|=
name|y
expr_stmt|;
name|gc
operator|->
name|dirty
operator||=
name|GCTileStipYOrigin
expr_stmt|;
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

