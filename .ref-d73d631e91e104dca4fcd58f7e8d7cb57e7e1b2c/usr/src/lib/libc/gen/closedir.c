begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)closedir.c	5.8 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_comment
comment|/*  * close a directory.  */
end_comment

begin_expr_stmt
name|closedir
argument_list|(
name|dirp
argument_list|)
specifier|register
name|DIR
operator|*
name|dirp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|fd
decl_stmt|;
name|fd
operator|=
name|dirp
operator|->
name|dd_fd
expr_stmt|;
name|dirp
operator|->
name|dd_fd
operator|=
operator|-
literal|1
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
operator|(
name|void
operator|)
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|dirp
operator|->
name|dd_buf
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|dirp
argument_list|)
expr_stmt|;
return|return
operator|(
name|close
argument_list|(
name|fd
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

