begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XChGC.c,v 11.10 91/01/06 11:44:19 rws Exp $ */
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
name|XChangeGC
argument_list|(
name|dpy
argument_list|,
name|gc
argument_list|,
name|valuemask
argument_list|,
name|values
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
name|unsigned
name|long
name|valuemask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XGCValues
modifier|*
name|values
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|valuemask
operator|&=
operator|(
literal|1L
operator|<<
operator|(
name|GCLastBit
operator|+
literal|1
operator|)
operator|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|valuemask
condition|)
name|_XUpdateGCCache
argument_list|(
name|gc
argument_list|,
name|valuemask
argument_list|,
name|values
argument_list|)
expr_stmt|;
comment|/* if any Resource ID changed, must flush */
if|if
condition|(
name|gc
operator|->
name|dirty
operator|&
operator|(
name|GCFont
operator||
name|GCTile
operator||
name|GCStipple
operator|)
condition|)
name|_XFlushGCCache
argument_list|(
name|dpy
argument_list|,
name|gc
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

