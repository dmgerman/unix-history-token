begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XGetPCnt.c,v 11.11 91/01/06 11:46:12 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1986	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_define
define|#
directive|define
name|NEED_REPLIES
end_define

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_expr_stmt
name|XGetPointerControl
argument_list|(
name|dpy
argument_list|,
name|accel_numer
argument_list|,
name|accel_denom
argument_list|,
name|threshold
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* the following are return only vars */
end_comment

begin_decl_stmt
name|int
modifier|*
name|accel_numer
decl_stmt|,
modifier|*
name|accel_denom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|threshold
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|xGetPointerControlReply
name|rep
decl_stmt|;
name|xReq
modifier|*
name|req
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|GetEmptyReq
argument_list|(
name|GetPointerControl
argument_list|,
name|req
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|_XReply
argument_list|(
name|dpy
argument_list|,
operator|(
name|xReply
operator|*
operator|)
operator|&
name|rep
argument_list|,
literal|0
argument_list|,
name|xTrue
argument_list|)
expr_stmt|;
operator|*
name|accel_numer
operator|=
name|rep
operator|.
name|accelNumerator
expr_stmt|;
operator|*
name|accel_denom
operator|=
name|rep
operator|.
name|accelDenominator
expr_stmt|;
operator|*
name|threshold
operator|=
name|rep
operator|.
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

