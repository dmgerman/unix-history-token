begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XFreeCols.c,v 11.10 91/01/06 11:45:44 rws Exp $ */
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
name|XFreeColors
argument_list|(
name|dpy
argument_list|,
name|cmap
argument_list|,
name|pixels
argument_list|,
name|npixels
argument_list|,
name|planes
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Colormap
name|cmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
modifier|*
name|pixels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LISTofCARD32 */
end_comment

begin_decl_stmt
name|int
name|npixels
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|planes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CARD32 */
end_comment

begin_block
block|{
specifier|register
name|xFreeColorsReq
modifier|*
name|req
decl_stmt|;
specifier|register
name|long
name|nbytes
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|GetReq
argument_list|(
name|FreeColors
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|cmap
operator|=
name|cmap
expr_stmt|;
name|req
operator|->
name|planeMask
operator|=
name|planes
expr_stmt|;
comment|/* on the VAX, each pixel is a 32-bit (unsigned) integer */
name|req
operator|->
name|length
operator|+=
name|npixels
expr_stmt|;
name|nbytes
operator|=
name|npixels
operator|<<
literal|2
expr_stmt|;
comment|/* watch out for macros... */
name|Data32
argument_list|(
name|dpy
argument_list|,
operator|(
name|long
operator|*
operator|)
name|pixels
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

