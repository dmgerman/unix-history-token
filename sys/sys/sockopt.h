begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socketvar.h	8.3 (Berkeley) 2/19/95  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKOPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SOCKOPT_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Argument structure for sosetopt et seq.  This is in the KERNEL  * section because it will never be visible to user code.  */
end_comment

begin_enum
enum|enum
name|sopt_dir
block|{
name|SOPT_GET
block|,
name|SOPT_SET
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sockopt
block|{
name|enum
name|sopt_dir
name|sopt_dir
decl_stmt|;
comment|/* is this a get or a set? */
name|int
name|sopt_level
decl_stmt|;
comment|/* second arg of [gs]etsockopt */
name|int
name|sopt_name
decl_stmt|;
comment|/* third arg of [gs]etsockopt */
name|void
modifier|*
name|sopt_val
decl_stmt|;
comment|/* fourth arg of [gs]etsockopt */
name|size_t
name|sopt_valsize
decl_stmt|;
comment|/* (almost) fifth arg of [gs]etsockopt */
name|struct
name|thread
modifier|*
name|sopt_td
decl_stmt|;
comment|/* calling thread or null if kernel */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|sosetopt
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sogetopt
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sooptcopyin
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
name|minlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sooptcopyout
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX; prepare mbuf for (__FreeBSD__< 3) routines. */
end_comment

begin_function_decl
name|int
name|soopt_getm
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|soopt_mcopyin
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|soopt_mcopyout
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|accept_filt_getopt
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|accept_filt_setopt
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|so_setsockopt
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|optname
parameter_list|,
name|void
modifier|*
name|optval
parameter_list|,
name|size_t
name|optlen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SOCKOPT_H_ */
end_comment

end_unit

