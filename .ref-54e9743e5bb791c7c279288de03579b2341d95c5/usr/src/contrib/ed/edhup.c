begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rodney Ruddock of the University of Guelph.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)edhup.c	8.1 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DBI
end_ifdef

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ed.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * If a SIGHUP is received then user contact is severed. Try, if possible,  * to save the buffer. But be nice and don't save over remembered filename  * (you can figure out why, can't you?).  The buffer is saved in a file  * named "ed.hup" in the directory that ed was started-up in.  If a write  * cannot be made to that directory (say because it is read-only) then try  * writting "ed.hup" in the user's $HOME directory. Then exit.  */
end_comment

begin_function
name|__dead
name|void
name|do_hup
parameter_list|()
block|{
name|char
name|l_filename
index|[
name|FILENAME_LEN
index|]
decl_stmt|,
modifier|*
name|l_temp
decl_stmt|;
name|FILE
modifier|*
name|l_fp
decl_stmt|;
name|sigspecial
operator|++
expr_stmt|;
if|if
condition|(
name|change_flag
operator|==
literal|0
condition|)
name|exit
argument_list|(
name|exit_code
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|/* No need to save buffer contents. */
if|if
condition|(
operator|(
name|l_fp
operator|=
name|fopen
argument_list|(
literal|"ed.hup"
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* Try writting ed.hup to the $HOME directory instead. */
name|l_temp
operator|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|l_temp
operator|==
name|NULL
operator|)
operator|||
operator|(
operator|(
name|strlen
argument_list|(
name|l_temp
argument_list|)
operator|+
literal|7
operator|)
operator|>
name|FILENAME_LEN
operator|)
condition|)
name|exit
argument_list|(
name|exit_code
operator|+
literal|2
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|l_filename
argument_list|,
name|l_temp
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|l_filename
argument_list|,
literal|"/ed.hup"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|l_fp
operator|=
name|fopen
argument_list|(
name|l_filename
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|exit
argument_list|(
name|exit_code
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|/* We tried... */
block|}
name|edwrite
argument_list|(
name|l_fp
argument_list|,
name|top
argument_list|,
name|bottom
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|l_fp
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|STDIO
name|fclose
argument_list|(
name|fhtmp
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|template
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DBI
call|(
name|dbhtmp
operator|->
name|close
call|)
argument_list|(
name|dbhtmp
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|template
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|exit
argument_list|(
name|exit_code
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|/* Hangup */
block|}
end_function

end_unit

