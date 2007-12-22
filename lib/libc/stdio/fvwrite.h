begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fvwrite.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * I/O descriptors for __sfvwrite().  */
end_comment

begin_struct
struct|struct
name|__siov
block|{
name|void
modifier|*
name|iov_base
decl_stmt|;
name|size_t
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__suio
block|{
name|struct
name|__siov
modifier|*
name|uio_iov
decl_stmt|;
name|int
name|uio_iovcnt
decl_stmt|;
name|int
name|uio_resid
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|__sfvwrite
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|__suio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

