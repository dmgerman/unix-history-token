begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_comment
comment|/*static char sccsid[] = "from: @(#)dirent.c	5.1 (Berkeley) 3/7/91";*/
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"dirent.c,v 1.4 1993/08/01 18:58:21 mycroft Exp"
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
file|"shell.h"
end_include

begin_comment
comment|/* definitions for pointer, NULL, DIRENT, and BSD */
end_comment

begin_if
if|#
directive|if
operator|!
name|DIRENT
end_if

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_comment
comment|/* macro to test for directory file */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|int
name|stat
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|stat
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The BSD opendir routine doesn't check that what is being opened is a  * directory, so we have to include the check in a wrapper routine.  */
end_comment

begin_undef
undef|#
directive|undef
name|opendir
end_undef

begin_function
name|DIR
modifier|*
name|myopendir
parameter_list|(
name|dirname
parameter_list|)
name|char
modifier|*
name|dirname
decl_stmt|;
comment|/* name of directory */
block|{
name|struct
name|stat
name|statb
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|dirname
argument_list|,
operator|&
name|statb
argument_list|)
operator|!=
literal|0
operator|||
operator|!
name|S_ISDIR
argument_list|(
name|statb
operator|.
name|st_mode
argument_list|)
condition|)
block|{
name|errno
operator|=
name|ENOTDIR
expr_stmt|;
return|return
name|NULL
return|;
comment|/* not a directory */
block|}
return|return
name|opendir
argument_list|(
name|dirname
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not BSD */
end_comment

begin_comment
comment|/*  * Dirent routines for old style file systems.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|pointer
name|malloc
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fstat
parameter_list|(
name|int
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|pointer
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fstat
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|DIR
modifier|*
name|opendir
parameter_list|(
name|dirname
parameter_list|)
name|char
modifier|*
name|dirname
decl_stmt|;
comment|/* name of directory */
block|{
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* -> malloc'ed storage */
specifier|register
name|int
name|fd
decl_stmt|;
comment|/* file descriptor for read */
name|struct
name|stat
name|statb
decl_stmt|;
comment|/* result of fstat() */
ifdef|#
directive|ifdef
name|O_NDELAY
name|fd
operator|=
name|open
argument_list|(
name|dirname
argument_list|,
name|O_RDONLY
operator||
name|O_NDELAY
argument_list|)
expr_stmt|;
else|#
directive|else
name|fd
operator|=
name|open
argument_list|(
name|dirname
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
return|return
name|NULL
return|;
comment|/* errno set by open() */
if|if
condition|(
name|fstat
argument_list|(
name|fd
argument_list|,
operator|&
name|statb
argument_list|)
operator|!=
literal|0
operator|||
operator|!
name|S_ISDIR
argument_list|(
name|statb
operator|.
name|st_mode
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|errno
operator|=
name|ENOTDIR
expr_stmt|;
return|return
name|NULL
return|;
comment|/* not a directory */
block|}
if|if
condition|(
operator|(
name|dirp
operator|=
operator|(
name|DIR
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|DIR
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|errno
operator|=
name|ENOMEM
expr_stmt|;
return|return
name|NULL
return|;
comment|/* not enough memory */
block|}
name|dirp
operator|->
name|dd_fd
operator|=
name|fd
expr_stmt|;
name|dirp
operator|->
name|dd_nleft
operator|=
literal|0
expr_stmt|;
comment|/* refill needed */
return|return
name|dirp
return|;
block|}
end_function

begin_function
name|int
name|closedir
parameter_list|(
name|dirp
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* stream from opendir() */
block|{
specifier|register
name|int
name|fd
decl_stmt|;
if|if
condition|(
name|dirp
operator|==
name|NULL
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return
operator|-
literal|1
return|;
comment|/* invalid pointer */
block|}
name|fd
operator|=
name|dirp
operator|->
name|dd_fd
expr_stmt|;
name|free
argument_list|(
operator|(
name|pointer
operator|)
name|dirp
argument_list|)
expr_stmt|;
return|return
name|close
argument_list|(
name|fd
argument_list|)
return|;
block|}
end_function

begin_function
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|(
name|dirp
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* stream from opendir() */
block|{
specifier|register
name|struct
name|direct
modifier|*
name|dp
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|(
name|dirp
operator|->
name|dd_nleft
operator|-=
sizeof|sizeof
argument_list|(
expr|struct
name|direct
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|i
operator|=
name|read
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
operator|(
name|char
operator|*
operator|)
name|dirp
operator|->
name|dd_buf
argument_list|,
name|DIRBUFENT
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|direct
argument_list|)
argument_list|)
operator|)
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|errno
operator|=
literal|0
expr_stmt|;
comment|/* unnecessary */
return|return
name|NULL
return|;
comment|/* EOF or error */
block|}
name|dirp
operator|->
name|dd_loc
operator|=
name|dirp
operator|->
name|dd_buf
expr_stmt|;
name|dirp
operator|->
name|dd_nleft
operator|=
name|i
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|direct
argument_list|)
expr_stmt|;
block|}
name|dp
operator|=
name|dirp
operator|->
name|dd_loc
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|dp
operator|->
name|d_ino
operator|==
literal|0
condition|)
do|;
name|dirp
operator|->
name|dd_entry
operator|.
name|d_ino
operator|=
name|dp
operator|->
name|d_ino
expr_stmt|;
comment|/* now copy the name, nul terminating it */
name|p
operator|=
name|dp
operator|->
name|d_name
expr_stmt|;
name|q
operator|=
name|dirp
operator|->
name|dd_entry
operator|.
name|d_name
expr_stmt|;
name|i
operator|=
name|DIRSIZ
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
operator|*
name|q
operator|++
operator|=
operator|*
name|p
operator|++
expr_stmt|;
operator|*
name|q
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|&
name|dirp
operator|->
name|dd_entry
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIRENT */
end_comment

end_unit

