begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_comment
comment|/*static char *sccsid = "from: @(#)findfp.c	5.10 (Berkeley) 2/24/91";*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: findfp.c,v 1.15 1994/01/27 06:08:25 proven Exp $"
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
file|<pthread.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<posix.h>
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

begin_define
define|#
directive|define
name|NSTATIC
value|20
end_define

begin_comment
comment|/* stdin + stdout + stderr + the usual */
end_comment

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
value|{0,0,0,flags,file,{0},0 }
end_define

begin_comment
comment|/*	 p r w flags file _bf z  */
end_comment

begin_decl_stmt
specifier|static
name|FILE
name|usual
index|[
name|NSTATIC
operator|-
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the usual */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|glue
name|uglue
init|=
block|{
literal|0
block|,
name|NSTATIC
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
literal|0
argument_list|)
block|,
comment|/* stdin */
name|std
argument_list|(
name|__SWR
argument_list|,
literal|1
argument_list|)
block|,
comment|/* stdout */
name|std
argument_list|(
argument|__SWR|__SNBF
argument_list|,
literal|2
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

begin_decl_stmt
name|pthread_mutex_t
name|__sfp_mutex
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_cond_t
name|__sfp_cond
init|=
name|PTHREAD_COND_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_once_t
name|__sdidinit
init|=
name|PTHREAD_ONCE_INIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * __sfp_state = 0, when free,> 0 when in _fwalk   * This allows multiple readers in _fwalk, but only one writer __sfp,  * or freopen() at a time.  */
end_comment

begin_decl_stmt
name|int
name|__sfp_state
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|struct
name|glue
modifier|*
name|moreglue
parameter_list|(
specifier|register
name|int
name|n
parameter_list|)
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
operator|(
name|g
operator|+
literal|1
operator|)
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
block|{
name|fp
operator|->
name|_flags
operator|=
literal|1
expr_stmt|;
comment|/* reserve this slot; caller sets real flags */
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
goto|goto
name|__sfp_done
goto|;
block|}
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
block|{
name|fp
operator|=
name|NULL
expr_stmt|;
break|break;
block|}
block|}
name|__sfp_done
label|:
empty_stmt|;
return|return
operator|(
name|fp
operator|)
return|;
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
operator|(
name|void
operator|)
name|__swalk_sflush
expr_stmt|;
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
name|__sdidinit
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

