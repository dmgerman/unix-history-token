begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: mem2.c,v 1.6 2002/01/21 19:49:52 tv Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__RCSID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: mem2.c,v 1.6 2002/01/21 19:49:52 tv Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"lint2.h"
end_include

begin_comment
comment|/* length of new allocated memory blocks */
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|mblklen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset of next free byte in mbuf */
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|nxtfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current buffer to server memory requests from */
end_comment

begin_decl_stmt
specifier|static
name|void
modifier|*
name|mbuf
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|initmem
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|pgsz
decl_stmt|;
name|pgsz
operator|=
name|getpagesize
argument_list|()
expr_stmt|;
name|mblklen
operator|=
operator|(
operator|(
name|MBLKSIZ
operator|+
name|pgsz
operator|-
literal|1
operator|)
operator|/
name|pgsz
operator|)
operator|*
name|pgsz
expr_stmt|;
name|nxtfree
operator|=
name|mblklen
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Allocate memory in large chunks to avoid space and time overhead of  * malloc(). This is possible because memory allocated by xalloc()  * need never to be freed.  */
end_comment

begin_function
name|void
modifier|*
name|xalloc
parameter_list|(
name|size_t
name|sz
parameter_list|)
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|int
name|prot
decl_stmt|,
name|flags
decl_stmt|;
comment|/* Align to at least 8 bytes. */
name|sz
operator|=
operator|(
name|sz
operator|+
literal|7
operator|)
operator|&
operator|~
literal|7L
expr_stmt|;
if|if
condition|(
name|nxtfree
operator|+
name|sz
operator|>
name|mblklen
condition|)
block|{
comment|/* use mmap() instead of malloc() to avoid malloc overhead. */
name|prot
operator|=
name|PROT_READ
operator||
name|PROT_WRITE
expr_stmt|;
name|flags
operator|=
name|MAP_ANON
operator||
name|MAP_PRIVATE
expr_stmt|;
name|mbuf
operator|=
name|mmap
argument_list|(
name|NULL
argument_list|,
name|mblklen
argument_list|,
name|prot
argument_list|,
name|flags
argument_list|,
operator|-
literal|1
argument_list|,
operator|(
name|off_t
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|mbuf
operator|==
operator|(
name|void
operator|*
operator|)
name|MAP_FAILED
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"can't map memory"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|memset
argument_list|(
name|mbuf
argument_list|,
literal|0
argument_list|,
name|mblklen
argument_list|)
expr_stmt|;
name|nxtfree
operator|=
literal|0
expr_stmt|;
block|}
name|ptr
operator|=
operator|(
name|char
operator|*
operator|)
name|mbuf
operator|+
name|nxtfree
expr_stmt|;
name|nxtfree
operator|+=
name|sz
expr_stmt|;
return|return
operator|(
name|ptr
operator|)
return|;
block|}
end_function

end_unit

