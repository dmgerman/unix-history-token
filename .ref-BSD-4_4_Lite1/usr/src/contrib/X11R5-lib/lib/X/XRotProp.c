begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XRotProp.c,v 11.14 91/01/06 11:47:49 rws Exp $ */
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
name|XRotateWindowProperties
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|,
name|properties
argument_list|,
name|nprops
argument_list|,
name|npositions
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Window
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Atom
modifier|*
name|properties
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
name|nprops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|npositions
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|long
name|nbytes
decl_stmt|;
specifier|register
name|xRotatePropertiesReq
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
name|RotateProperties
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|window
operator|=
name|w
expr_stmt|;
name|req
operator|->
name|nAtoms
operator|=
name|nprops
expr_stmt|;
name|req
operator|->
name|nPositions
operator|=
name|npositions
expr_stmt|;
name|req
operator|->
name|length
operator|+=
name|nprops
expr_stmt|;
name|nbytes
operator|=
name|nprops
operator|<<
literal|2
expr_stmt|;
comment|/* XXX Cray needs packing here.... */
name|Data32
argument_list|(
name|dpy
argument_list|,
operator|(
name|long
operator|*
operator|)
name|properties
argument_list|,
name|nbytes
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

