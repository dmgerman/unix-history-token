begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lfs_bio.c	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<ufs/lfs/lfs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/lfs/lfs_extern.h>
end_include

begin_function
name|int
name|lfs_bwrite
parameter_list|(
name|bp
parameter_list|)
specifier|register
name|BUF
modifier|*
name|bp
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|VERBOSE
name|printf
argument_list|(
literal|"lfs_bwrite\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * 	 * LFS version of bawrite, bdwrite, bwrite.  Set the delayed write 	 * flag and use reassignbuf to move the buffer from the clean list 	 * to the dirty one, then unlock the buffer.  Note, we set the 	 * B_LOCKED flag, which causes brelse to move the buffer onto the 	 * LOCKED free list.  This is necessary, otherwise getnewbuf() would 	 * try to reclaim them using bawrite, which isn't going to work. 	 * 	 * XXX 	 * No accounting for the cost of the write is currently done. 	 * This is almost certainly wrong for synchronous operations, i.e. NFS. 	 */
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
operator|)
expr_stmt|;
name|bp
operator|->
name|b_flags
operator||=
name|B_DELWRI
operator||
name|B_LOCKED
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
name|brelse
argument_list|(
name|bp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

