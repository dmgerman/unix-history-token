begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lfs_bio.c	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"specdev.h"
end_include

begin_include
include|#
directive|include
file|"mount.h"
end_include

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_include
include|#
directive|include
file|"resourcevar.h"
end_include

begin_include
include|#
directive|include
file|"lfs.h"
end_include

begin_comment
comment|/*  * lfs_bwrite --  *	LFS version of bawrite, bdwrite, bwrite.  Set the delayed write flag  *	and use reassignbuf to move the buffer from the clean list to the  *	dirty one.  Then unlock the buffer.  */
end_comment

begin_expr_stmt
name|lfs_bwrite
argument_list|(
name|bp
argument_list|)
specifier|register
name|BUF
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|curproc
operator|->
name|p_stats
operator|->
name|p_ru
operator|.
name|ru_oublock
operator|++
expr_stmt|;
comment|/* XXX: no one paid yet */
name|bp
operator|->
name|b_flags
operator|&=
operator|~
operator|(
name|B_READ
operator||
name|B_DONE
operator||
name|B_ERROR
operator||
name|B_DELWRI
operator|)
expr_stmt|;
name|bp
operator|->
name|b_flags
operator||=
name|B_DELWRI
expr_stmt|;
name|reassignbuf
argument_list|(
name|bp
argument_list|,
name|bp
operator|->
name|b_vp
argument_list|)
expr_stmt|;
comment|/* XXX: do this inline */
name|brelse
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

