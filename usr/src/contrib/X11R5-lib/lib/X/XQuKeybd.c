begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XQuKeybd.c,v 11.11 91/01/06 11:47:33 rws Exp $ */
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

begin_struct
struct|struct
name|kmap
block|{
name|char
name|map
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|XQueryKeymap
argument_list|(
name|dpy
argument_list|,
name|keys
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
name|keys
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|xQueryKeymapReply
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
name|QueryKeymap
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
operator|(
name|SIZEOF
argument_list|(
name|xQueryKeymapReply
argument_list|)
operator|-
name|SIZEOF
argument_list|(
name|xReply
argument_list|)
operator|)
operator|>>
literal|2
argument_list|,
name|xTrue
argument_list|)
expr_stmt|;
operator|*
operator|(
expr|struct
name|kmap
operator|*
operator|)
name|keys
operator|=
operator|*
operator|(
expr|struct
name|kmap
operator|*
operator|)
name|rep
operator|.
name|map
expr_stmt|;
comment|/* faster than bcopy */
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

