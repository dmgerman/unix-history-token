begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XDrLines.c,v 11.15 91/01/06 11:45:14 rws Exp $ */
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
name|XDrawLines
argument_list|(
name|dpy
argument_list|,
name|d
argument_list|,
name|gc
argument_list|,
name|points
argument_list|,
name|npoints
argument_list|,
name|mode
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Drawable
name|d
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GC
name|gc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XPoint
modifier|*
name|points
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|npoints
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|xPolyLineReq
modifier|*
name|req
decl_stmt|;
specifier|register
name|long
name|length
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|FlushGC
argument_list|(
name|dpy
argument_list|,
name|gc
argument_list|)
expr_stmt|;
name|GetReq
argument_list|(
name|PolyLine
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|drawable
operator|=
name|d
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
name|coordMode
operator|=
name|mode
expr_stmt|;
if|if
condition|(
operator|(
name|req
operator|->
name|length
operator|+
name|npoints
operator|)
operator|>
operator|(
name|unsigned
operator|)
literal|65535
condition|)
name|npoints
operator|=
literal|65535
operator|-
name|req
operator|->
name|length
expr_stmt|;
comment|/* force BadLength, if possible */
name|req
operator|->
name|length
operator|+=
name|npoints
expr_stmt|;
comment|/* each point is 2 16-bit integers */
name|length
operator|=
name|npoints
operator|<<
literal|2
expr_stmt|;
comment|/* watch out for macros... */
name|Data16
argument_list|(
name|dpy
argument_list|,
operator|(
name|short
operator|*
operator|)
name|points
argument_list|,
name|length
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

