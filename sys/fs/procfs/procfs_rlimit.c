begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Adrian Chadd  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)procfs_status.c	8.4 (Berkeley) 6/15/94  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * To get resource.h to include our rlimit_ident[] array of rlimit identifiers  */
end_comment

begin_define
define|#
directive|define
name|_RLIMIT_IDENT
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/sbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<fs/pseudofs/pseudofs.h>
end_include

begin_include
include|#
directive|include
file|<fs/procfs/procfs.h>
end_include

begin_function
name|int
name|procfs_doprocrlimit
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
block|{
name|struct
name|plimit
modifier|*
name|limp
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* 	 * Obtain a private reference to resource limits 	 */
name|PROC_LOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|limp
operator|=
name|lim_hold
argument_list|(
name|p
operator|->
name|p_limit
argument_list|)
expr_stmt|;
name|PROC_UNLOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|RLIM_NLIMITS
condition|;
name|i
operator|++
control|)
block|{
comment|/* 		 * Add the rlimit ident 		 */
name|sbuf_printf
argument_list|(
name|sb
argument_list|,
literal|"%s "
argument_list|,
name|rlimit_ident
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* 		 * Replace RLIM_INFINITY with -1 in the string 		 */
comment|/* 		 * current limit 		 */
if|if
condition|(
name|limp
operator|->
name|pl_rlimit
index|[
name|i
index|]
operator|.
name|rlim_cur
operator|==
name|RLIM_INFINITY
condition|)
block|{
name|sbuf_printf
argument_list|(
name|sb
argument_list|,
literal|"-1 "
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sbuf_printf
argument_list|(
name|sb
argument_list|,
literal|"%llu "
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
name|limp
operator|->
name|pl_rlimit
index|[
name|i
index|]
operator|.
name|rlim_cur
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * maximum limit 		 */
if|if
condition|(
name|limp
operator|->
name|pl_rlimit
index|[
name|i
index|]
operator|.
name|rlim_max
operator|==
name|RLIM_INFINITY
condition|)
block|{
name|sbuf_printf
argument_list|(
name|sb
argument_list|,
literal|"-1\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sbuf_printf
argument_list|(
name|sb
argument_list|,
literal|"%llu\n"
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
name|limp
operator|->
name|pl_rlimit
index|[
name|i
index|]
operator|.
name|rlim_max
argument_list|)
expr_stmt|;
block|}
block|}
name|lim_free
argument_list|(
name|limp
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

