begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XConvSel.c,v 11.7 91/01/06 11:44:45 rws Exp $ */
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
name|XConvertSelection
argument_list|(
name|dpy
argument_list|,
name|selection
argument_list|,
name|target
argument_list|,
name|property
argument_list|,
name|requestor
argument_list|,
name|time
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Atom
name|selection
decl_stmt|,
name|target
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Atom
name|property
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Window
name|requestor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Time
name|time
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|xConvertSelectionReq
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
name|ConvertSelection
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|selection
operator|=
name|selection
expr_stmt|;
name|req
operator|->
name|target
operator|=
name|target
expr_stmt|;
name|req
operator|->
name|property
operator|=
name|property
expr_stmt|;
name|req
operator|->
name|requestor
operator|=
name|requestor
expr_stmt|;
name|req
operator|->
name|time
operator|=
name|time
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

