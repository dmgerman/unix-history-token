begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Hugh Smith at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)append.c	5.6 (Berkeley) 3/12/91"
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
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
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
file|<string.h>
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
name|char
modifier|*
name|archive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive name */
end_comment

begin_comment
comment|/*  * append --  *	Append files to the archive - modifies original archive or creates  *	a new archive if named archive does not exist.  */
end_comment

begin_macro
name|append
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
specifier|register
name|int
name|fd
decl_stmt|,
name|afd
decl_stmt|;
specifier|register
name|char
modifier|*
name|file
decl_stmt|;
name|struct
name|stat
name|sb
decl_stmt|;
name|CF
name|cf
decl_stmt|;
name|int
name|eval
decl_stmt|;
name|afd
operator|=
name|open_archive
argument_list|(
name|O_CREAT
operator||
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|afd
argument_list|,
operator|(
name|off_t
operator|)
literal|0
argument_list|,
name|SEEK_END
argument_list|)
operator|==
operator|(
name|off_t
operator|)
operator|-
literal|1
condition|)
name|error
argument_list|(
name|archive
argument_list|)
expr_stmt|;
comment|/* Read from disk, write to an archive; pad on write. */
name|SETCF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|afd
argument_list|,
name|archive
argument_list|,
name|WPAD
argument_list|)
expr_stmt|;
for|for
control|(
name|eval
operator|=
literal|0
init|;
name|file
operator|=
operator|*
name|argv
operator|++
condition|;
control|)
block|{
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|file
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ar: %s: %s.\n"
argument_list|,
name|file
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|eval
operator|=
literal|1
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|options
operator|&
name|AR_V
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"q - %s\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|cf
operator|.
name|rfd
operator|=
name|fd
expr_stmt|;
name|cf
operator|.
name|rname
operator|=
name|file
expr_stmt|;
name|put_arobj
argument_list|(
operator|&
name|cf
argument_list|,
operator|&
name|sb
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
name|close_archive
argument_list|(
name|afd
argument_list|)
expr_stmt|;
return|return
operator|(
name|eval
operator|)
return|;
block|}
end_block

end_unit

