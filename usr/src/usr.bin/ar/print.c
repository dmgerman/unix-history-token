begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Hugh Smith at The University of Guelph.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)print.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"archive.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_decl_stmt
specifier|extern
name|CHDR
name|chdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* converted header */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|archive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive name */
end_comment

begin_comment
comment|/*  * print --  *	Prints archive members on stdout - if member names given only  *	print those members, otherwise print all members.  */
end_comment

begin_macro
name|print
argument_list|(
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|CF
name|cf
decl_stmt|;
specifier|register
name|int
name|afd
decl_stmt|,
name|all
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|afd
operator|=
name|open_archive
argument_list|(
name|O_RDONLY
argument_list|)
expr_stmt|;
comment|/* Read from an archive, write to stdout; pad on read. */
name|SETCF
argument_list|(
name|afd
argument_list|,
name|archive
argument_list|,
name|STDOUT_FILENO
argument_list|,
literal|"stdout"
argument_list|,
name|RPAD
argument_list|)
expr_stmt|;
for|for
control|(
name|all
operator|=
operator|!
operator|*
name|argv
init|;
name|get_arobj
argument_list|(
name|afd
argument_list|)
condition|;
control|)
block|{
if|if
condition|(
name|all
condition|)
name|file
operator|=
name|chdr
operator|.
name|name
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
operator|(
name|file
operator|=
name|files
argument_list|(
name|argv
argument_list|)
operator|)
condition|)
block|{
name|skip_arobj
argument_list|(
name|afd
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|options
operator|&
name|AR_V
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n<%s>\n\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
name|copy_ar
argument_list|(
operator|&
name|cf
argument_list|,
name|chdr
operator|.
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|all
operator|&&
operator|!
operator|*
name|argv
condition|)
break|break;
block|}
name|close_archive
argument_list|(
name|afd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|argv
condition|)
block|{
name|orphans
argument_list|(
name|argv
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

