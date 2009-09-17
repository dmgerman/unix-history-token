begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)clist.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CLIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CLIST_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  * Clists are character lists, which is a variable length linked list  * of cblocks, with a count of the number of characters in the list.  */
end_comment

begin_struct
struct|struct
name|clist
block|{
name|int
name|c_cc
decl_stmt|;
comment|/* Number of characters in the clist. */
name|int
name|c_cbcount
decl_stmt|;
comment|/* Number of cblocks. */
name|int
name|c_cbmax
decl_stmt|;
comment|/* Max # cblocks allowed for this clist. */
name|int
name|c_cbreserved
decl_stmt|;
comment|/* # cblocks reserved for this clist. */
name|char
modifier|*
name|c_cf
decl_stmt|;
comment|/* Pointer to the first cblock. */
name|char
modifier|*
name|c_cl
decl_stmt|;
comment|/* Pointer to the last cblock. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cblock
block|{
name|struct
name|cblock
modifier|*
name|c_next
decl_stmt|;
comment|/* next cblock in queue */
name|unsigned
name|char
name|c_info
index|[
name|CBSIZE
index|]
decl_stmt|;
comment|/* characters */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|b_to_q
parameter_list|(
name|char
modifier|*
name|cp
parameter_list|,
name|int
name|cc
parameter_list|,
name|struct
name|clist
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clist_alloc_cblocks
parameter_list|(
name|struct
name|clist
modifier|*
name|q
parameter_list|,
name|int
name|ccmax
parameter_list|,
name|int
name|ccres
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clist_free_cblocks
parameter_list|(
name|struct
name|clist
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getc
parameter_list|(
name|struct
name|clist
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ndflush
parameter_list|(
name|struct
name|clist
modifier|*
name|q
parameter_list|,
name|int
name|cc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putc
parameter_list|(
name|char
name|c
parameter_list|,
name|struct
name|clist
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|q_to_b
parameter_list|(
name|struct
name|clist
modifier|*
name|q
parameter_list|,
name|char
modifier|*
name|cp
parameter_list|,
name|int
name|cc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unputc
parameter_list|(
name|struct
name|clist
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

