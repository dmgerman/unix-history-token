begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XGetSSaver.c,v 11.11 91/01/06 11:46:18 rws Exp $ */
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
name|XGetScreenSaver
argument_list|(
name|dpy
argument_list|,
name|timeout
argument_list|,
name|interval
argument_list|,
name|prefer_blanking
argument_list|,
name|allow_exp
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
name|timeout
decl_stmt|,
modifier|*
name|interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|prefer_blanking
decl_stmt|,
modifier|*
name|allow_exp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*boolean */
end_comment

begin_block
block|{
name|xGetScreenSaverReply
name|rep
decl_stmt|;
specifier|register
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
name|GetScreenSaver
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
name|timeout
operator|=
name|rep
operator|.
name|timeout
expr_stmt|;
operator|*
name|interval
operator|=
name|rep
operator|.
name|interval
expr_stmt|;
operator|*
name|prefer_blanking
operator|=
name|rep
operator|.
name|preferBlanking
expr_stmt|;
operator|*
name|allow_exp
operator|=
name|rep
operator|.
name|allowExposures
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

