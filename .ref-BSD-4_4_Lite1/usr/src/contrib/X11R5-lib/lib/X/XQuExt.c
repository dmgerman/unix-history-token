begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XQuExt.c,v 11.18 91/01/06 11:47:31 rws Exp $ */
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

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_decl_stmt
name|Bool
name|XQueryExtension
argument_list|(
specifier|register
name|Display
operator|*
name|dpy
argument_list|,
name|_Xconst
name|char
operator|*
name|name
argument_list|,
name|int
operator|*
name|major_opcode
argument_list|,
comment|/* RETURN */
name|int
operator|*
name|first_event
argument_list|,
comment|/* RETURN */
name|int
operator|*
name|first_error
argument_list|)
comment|/* RETURN */
else|#
directive|else
name|Bool
name|XQueryExtension
argument_list|(
name|dpy
argument_list|,
name|name
argument_list|,
name|major_opcode
argument_list|,
name|first_event
argument_list|,
name|first_error
argument_list|)
decl|register
name|Display
modifier|*
name|dpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|major_opcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RETURN */
end_comment

begin_decl_stmt
name|int
modifier|*
name|first_event
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RETURN */
end_comment

begin_decl_stmt
name|int
modifier|*
name|first_error
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RETURN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|xQueryExtensionReply
name|rep
decl_stmt|;
specifier|register
name|xQueryExtensionReq
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
name|QueryExtension
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|nbytes
operator|=
name|name
condition|?
name|strlen
argument_list|(
name|name
argument_list|)
else|:
literal|0
expr_stmt|;
name|req
operator|->
name|length
operator|+=
operator|(
name|req
operator|->
name|nbytes
operator|+
operator|(
name|unsigned
operator|)
literal|3
operator|)
operator|>>
literal|2
expr_stmt|;
name|_XSend
argument_list|(
name|dpy
argument_list|,
name|name
argument_list|,
operator|(
name|long
operator|)
name|req
operator|->
name|nbytes
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
name|major_opcode
operator|=
name|rep
operator|.
name|major_opcode
expr_stmt|;
operator|*
name|first_event
operator|=
name|rep
operator|.
name|first_event
expr_stmt|;
operator|*
name|first_error
operator|=
name|rep
operator|.
name|first_error
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|SyncHandle
argument_list|()
expr_stmt|;
return|return
operator|(
name|rep
operator|.
name|present
operator|)
return|;
block|}
end_block

end_unit

