begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2002-2003 NetGroup, Politecnico di Torino (Italy)  * Copyright (C) 2005-2009 Jung-uk Kim<jkim@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_BPF_JITTER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_BPF_JITTER_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_BPFJIT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|bpf_jitter_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototype of a filtering function created by the jitter.  *  * The syntax and the meaning of the parameters is analogous to the one of  * bpf_filter(). Notice that the filter is not among the parameters because  * it is hardwired in the function.  */
end_comment

begin_typedef
typedef|typedef
name|u_int
function_decl|(
modifier|*
name|bpf_filter_func
function_decl|)
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Structure describing a native filtering program created by the jitter. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bpf_jit_filter
block|{
comment|/* The native filtering binary, in the form of a bpf_filter_func. */
name|bpf_filter_func
name|func
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
name|bpf_jit_filter
typedef|;
end_typedef

begin_comment
comment|/*  * BPF jitter, builds a machine function from a BPF program.  *  * param fp	The BPF pseudo-assembly filter that will be translated  *		into native code.  * param nins	Number of instructions of the input filter.  * return	The bpf_jit_filter structure containing the native filtering  *		binary.  *  * bpf_jitter allocates the buffers for the new native filter and  * then translates the program pointed by fp calling bpf_jit_compile().  */
end_comment

begin_function_decl
name|bpf_jit_filter
modifier|*
name|bpf_jitter
parameter_list|(
name|struct
name|bpf_insn
modifier|*
name|fp
parameter_list|,
name|int
name|nins
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Deletes a filtering function that was previously created by bpf_jitter().  *  * param filter	The filter to destroy.  *  * This function frees the variuos buffers (code, memory, etc.) associated  * with a filtering function.  */
end_comment

begin_function_decl
name|void
name|bpf_destroy_jit_filter
parameter_list|(
name|bpf_jit_filter
modifier|*
name|filter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Declarations for machine-dependent functions.  */
end_comment

begin_struct_decl
struct_decl|struct
name|bpf_insn
struct_decl|;
end_struct_decl

begin_function_decl
name|bpf_filter_func
name|bpf_jit_compile
parameter_list|(
name|struct
name|bpf_insn
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_BPF_JITTER_H_ */
end_comment

end_unit

