begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lfs_bio.c	5.4 (Berkeley) %G%  */
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
file|<lfs/lfs.h>
end_include

begin_include
include|#
directive|include
file|<lfs/lfs_extern.h>
end_include

begin_comment
comment|/*  * LFS version of bawrite, bdwrite, bwrite.  Set the delayed write flag and  * use reassignbuf to move the buffer from the clean list to the dirty one,  * then unlock the buffer.  */
end_comment

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
name|DO_ACCOUNTING
name|Not
name|included
name|as
name|this
name|gets
name|called
name|from
name|lots
name|of
name|places
name|where
name|the
name|current
name|proc
name|structure
name|is
name|probably
name|wrong
operator|.
name|Ignore
for|for now. 	curproc->p_stats->p_ru.ru_oublock++
empty_stmt|;
comment|/* XXX: no one paid yet */
endif|#
directive|endif
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
name|B_WRITE
operator||
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
comment|/* XXX: do this inline? */
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

