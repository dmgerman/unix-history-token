begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XSetDashes.c,v 11.12 91/01/06 11:47:57 rws Exp $ */
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

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|XSetDashes
argument_list|(
argument|register Display *dpy
argument_list|,
argument|GC gc
argument_list|,
argument|int dash_offset
argument_list|,
argument|_Xconst char *list
argument_list|,
argument|int n
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|XSetDashes
argument_list|(
name|dpy
argument_list|,
name|gc
argument_list|,
name|dash_offset
argument_list|,
name|list
argument_list|,
name|n
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
name|dash_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|xSetDashesReq
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
name|SetDashes
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|gc
operator|=
name|gc
operator|->
name|gid
expr_stmt|;
name|req
operator|->
name|dashOffset
operator|=
name|gc
operator|->
name|values
operator|.
name|dash_offset
operator|=
name|dash_offset
expr_stmt|;
name|req
operator|->
name|nDashes
operator|=
name|n
expr_stmt|;
name|req
operator|->
name|length
operator|+=
operator|(
name|n
operator|+
literal|3
operator|)
operator|>>
literal|2
expr_stmt|;
name|gc
operator|->
name|dashes
operator|=
literal|1
expr_stmt|;
name|gc
operator|->
name|dirty
operator|&=
operator|~
operator|(
name|GCDashList
operator||
name|GCDashOffset
operator|)
expr_stmt|;
name|Data
argument_list|(
name|dpy
argument_list|,
name|list
argument_list|,
operator|(
name|long
operator|)
name|n
argument_list|)
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

