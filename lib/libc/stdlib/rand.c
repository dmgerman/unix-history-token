begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Posix rand_r function added May 1999 by Wes Peters<wes@softweyr.com>.  *  * $FreeBSD$  */
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
literal|"@(#)rand.c	8.1 (Berkeley) 6/14/93"
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
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TEST
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEST */
end_comment

begin_function
specifier|static
name|int
name|do_rand
parameter_list|(
name|unsigned
name|long
modifier|*
name|ctx
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|*
name|ctx
operator|=
operator|*
name|ctx
operator|*
literal|1103515245
operator|+
literal|12345
operator|)
operator|%
operator|(
operator|(
name|u_long
operator|)
name|RAND_MAX
operator|+
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|rand_r
parameter_list|(
name|unsigned
name|int
modifier|*
name|ctx
parameter_list|)
block|{
name|u_long
name|val
init|=
operator|(
name|u_long
operator|)
operator|*
name|ctx
decl_stmt|;
operator|*
name|ctx
operator|=
name|do_rand
argument_list|(
operator|&
name|val
argument_list|)
expr_stmt|;
return|return
operator|(
name|int
operator|)
operator|*
name|ctx
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|u_long
name|next
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|rand
parameter_list|()
block|{
return|return
name|do_rand
argument_list|(
operator|&
name|next
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|srand
parameter_list|(
name|seed
parameter_list|)
name|u_int
name|seed
decl_stmt|;
block|{
name|next
operator|=
name|seed
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|TEST
end_ifdef

begin_function
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|myseed
decl_stmt|;
name|printf
argument_list|(
literal|"seeding rand with 0x19610910: \n"
argument_list|)
expr_stmt|;
name|srand
argument_list|(
literal|0x19610910
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"generating three pseudo-random numbers:\n"
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
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"next random number = %d\n"
argument_list|,
name|rand
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"generating the same sequence with rand_r:\n"
argument_list|)
expr_stmt|;
name|myseed
operator|=
literal|0x19610910
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"next random number = %d\n"
argument_list|,
name|rand_r
argument_list|(
operator|&
name|myseed
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEST */
end_comment

end_unit

