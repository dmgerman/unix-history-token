begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)findfp.c	8.2 (Berkeley) 1/4/94";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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
file|<libc_private.h>
end_include

begin_include
include|#
directive|include
file|<spinlock.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_include
include|#
directive|include
file|"glue.h"
end_include

begin_decl_stmt
name|int
name|__sdidinit
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NDYNAMIC
value|10
end_define

begin_comment
comment|/* add ten more whenever necessary */
end_comment

begin_define
define|#
directive|define
name|std
parameter_list|(
name|flags
parameter_list|,
name|file
parameter_list|)
define|\
value|{0,0,0,flags,file,{0},0,__sF+file,__sclose,__sread,__sseek,__swrite}
end_define

begin_comment
comment|/*	 p r w flags file _bf z  cookie      close    read    seek    write */
end_comment

begin_comment
comment|/* the usual - (stdin + stdout + stderr) */
end_comment

begin_decl_stmt
specifier|static
name|FILE
name|usual
index|[
name|FOPEN_MAX
operator|-
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|glue
name|uglue
init|=
block|{
literal|0
block|,
name|FOPEN_MAX
operator|-
literal|3
block|,
name|usual
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
name|__sF
index|[
literal|3
index|]
init|=
block|{
name|std
argument_list|(
name|__SRD
argument_list|,
name|STDIN_FILENO
argument_list|)
block|,
comment|/* stdin */
name|std
argument_list|(
name|__SWR
argument_list|,
name|STDOUT_FILENO
argument_list|)
block|,
comment|/* stdout */
name|std
argument_list|(
argument|__SWR|__SNBF
argument_list|,
argument|STDERR_FILENO
argument_list|)
comment|/* stderr */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|glue
name|__sglue
init|=
block|{
operator|&
name|uglue
block|,
literal|3
block|,
name|__sF
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The following kludge is done to ensure enough binary compatibility  * with future versions of libc.  Or rather it allows us to work with  * libraries that have been built with a newer libc that defines these  * symbols and expects libc to provide them.  We only have need to support  * i386 and alpha because they are the only "old" systems we have deployed.  */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|__stdinp
init|=
operator|&
name|__sF
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|__stdoutp
init|=
operator|&
name|__sF
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|__stderrp
init|=
operator|&
name|__sF
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|glue
modifier|*
name|moreglue
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|spinlock_t
name|thread_lock
init|=
name|_SPINLOCK_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|THREAD_LOCK
parameter_list|()
value|if (__isthreaded) _SPINLOCK(&thread_lock)
end_define

begin_define
define|#
directive|define
name|THREAD_UNLOCK
parameter_list|()
value|if (__isthreaded) _SPINUNLOCK(&thread_lock)
end_define

begin_function
specifier|static
name|struct
name|glue
modifier|*
name|moreglue
parameter_list|(
name|n
parameter_list|)
specifier|register
name|int
name|n
decl_stmt|;
block|{
specifier|register
name|struct
name|glue
modifier|*
name|g
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|p
decl_stmt|;
specifier|static
name|FILE
name|empty
decl_stmt|;
name|g
operator|=
operator|(
expr|struct
name|glue
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|g
argument_list|)
operator|+
name|ALIGNBYTES
operator|+
name|n
operator|*
sizeof|sizeof
argument_list|(
name|FILE
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|g
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|p
operator|=
operator|(
name|FILE
operator|*
operator|)
name|ALIGN
argument_list|(
name|g
operator|+
literal|1
argument_list|)
expr_stmt|;
name|g
operator|->
name|next
operator|=
name|NULL
expr_stmt|;
name|g
operator|->
name|niobs
operator|=
name|n
expr_stmt|;
name|g
operator|->
name|iobs
operator|=
name|p
expr_stmt|;
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
operator|*
name|p
operator|++
operator|=
name|empty
expr_stmt|;
return|return
operator|(
name|g
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Find a free FILE for fopen et al.  */
end_comment

begin_function
name|FILE
modifier|*
name|__sfp
parameter_list|()
block|{
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
specifier|register
name|struct
name|glue
modifier|*
name|g
decl_stmt|;
if|if
condition|(
operator|!
name|__sdidinit
condition|)
name|__sinit
argument_list|()
expr_stmt|;
name|THREAD_LOCK
argument_list|()
expr_stmt|;
for|for
control|(
name|g
operator|=
operator|&
name|__sglue
init|;
condition|;
name|g
operator|=
name|g
operator|->
name|next
control|)
block|{
for|for
control|(
name|fp
operator|=
name|g
operator|->
name|iobs
operator|,
name|n
operator|=
name|g
operator|->
name|niobs
init|;
operator|--
name|n
operator|>=
literal|0
condition|;
name|fp
operator|++
control|)
if|if
condition|(
name|fp
operator|->
name|_flags
operator|==
literal|0
condition|)
goto|goto
name|found
goto|;
if|if
condition|(
name|g
operator|->
name|next
operator|==
name|NULL
operator|&&
operator|(
name|g
operator|->
name|next
operator|=
name|moreglue
argument_list|(
name|NDYNAMIC
argument_list|)
operator|)
operator|==
name|NULL
condition|)
break|break;
block|}
name|THREAD_UNLOCK
argument_list|()
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
name|found
label|:
name|fp
operator|->
name|_flags
operator|=
literal|1
expr_stmt|;
comment|/* reserve this slot; caller sets real flags */
name|THREAD_UNLOCK
argument_list|()
expr_stmt|;
name|fp
operator|->
name|_p
operator|=
name|NULL
expr_stmt|;
comment|/* no current pointer */
name|fp
operator|->
name|_w
operator|=
literal|0
expr_stmt|;
comment|/* nothing to read or write */
name|fp
operator|->
name|_r
operator|=
literal|0
expr_stmt|;
name|fp
operator|->
name|_bf
operator|.
name|_base
operator|=
name|NULL
expr_stmt|;
comment|/* no buffer */
name|fp
operator|->
name|_bf
operator|.
name|_size
operator|=
literal|0
expr_stmt|;
name|fp
operator|->
name|_lbfsize
operator|=
literal|0
expr_stmt|;
comment|/* not line buffered */
name|fp
operator|->
name|_file
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* no file */
comment|/*	fp->_cookie =<any>; */
comment|/* caller sets cookie, _read/_write etc */
name|fp
operator|->
name|_ub
operator|.
name|_base
operator|=
name|NULL
expr_stmt|;
comment|/* no ungetc buffer */
name|fp
operator|->
name|_ub
operator|.
name|_size
operator|=
literal|0
expr_stmt|;
name|fp
operator|->
name|_lb
operator|.
name|_base
operator|=
name|NULL
expr_stmt|;
comment|/* no line buffer */
name|fp
operator|->
name|_lb
operator|.
name|_size
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|fp
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * XXX.  Force immediate allocation of internal memory.  Not used by stdio,  * but documented historically for certain applications.  Bad applications.  */
end_comment

begin_expr_stmt
name|__warn_references
argument_list|(
name|f_prealloc
argument_list|,
literal|"warning: this program uses f_prealloc(), which is not recommended."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|f_prealloc
parameter_list|()
block|{
specifier|register
name|struct
name|glue
modifier|*
name|g
decl_stmt|;
name|int
name|n
decl_stmt|;
name|n
operator|=
name|getdtablesize
argument_list|()
operator|-
name|FOPEN_MAX
operator|+
literal|20
expr_stmt|;
comment|/* 20 for slop. */
for|for
control|(
name|g
operator|=
operator|&
name|__sglue
init|;
operator|(
name|n
operator|-=
name|g
operator|->
name|niobs
operator|)
operator|>
literal|0
operator|&&
name|g
operator|->
name|next
condition|;
name|g
operator|=
name|g
operator|->
name|next
control|)
comment|/* void */
empty_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
name|g
operator|->
name|next
operator|=
name|moreglue
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * exit() calls _cleanup() through *__cleanup, set whenever we  * open or buffer a file.  This chicanery is done so that programs  * that do not use stdio need not link it all in.  *  * The name `_cleanup' is, alas, fairly well known outside stdio.  */
end_comment

begin_function
name|void
name|_cleanup
parameter_list|()
block|{
comment|/* (void) _fwalk(fclose); */
operator|(
name|void
operator|)
name|_fwalk
argument_list|(
name|__sflush
argument_list|)
expr_stmt|;
comment|/* `cheating' */
block|}
end_function

begin_comment
comment|/*  * __sinit() is called whenever stdio's internal variables must be set up.  */
end_comment

begin_function
name|void
name|__sinit
parameter_list|()
block|{
comment|/* make sure we clean up on exit */
name|__cleanup
operator|=
name|_cleanup
expr_stmt|;
comment|/* conservative */
name|__sdidinit
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

