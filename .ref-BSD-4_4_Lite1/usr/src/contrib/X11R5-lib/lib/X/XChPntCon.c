begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XChPntCon.c,v 11.9 91/01/06 11:44:21 rws Exp $ */
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
name|XChangePointerControl
argument_list|(
name|dpy
argument_list|,
name|do_acc
argument_list|,
name|do_thresh
argument_list|,
name|acc_numerator
argument_list|,
name|acc_denominator
argument_list|,
name|threshold
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Bool
name|do_acc
decl_stmt|,
name|do_thresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acc_numerator
decl_stmt|,
name|acc_denominator
decl_stmt|,
name|threshold
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|xChangePointerControlReq
modifier|*
name|req
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|GetReq
argument_list|(
name|ChangePointerControl
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|doAccel
operator|=
name|do_acc
expr_stmt|;
name|req
operator|->
name|doThresh
operator|=
name|do_thresh
expr_stmt|;
name|req
operator|->
name|accelNum
operator|=
name|acc_numerator
expr_stmt|;
name|req
operator|->
name|accelDenum
operator|=
name|acc_denominator
expr_stmt|;
name|req
operator|->
name|threshold
operator|=
name|threshold
expr_stmt|;
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

