begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software developed by the Computer Systems  * Engineering group at Lawrence Berkeley Laboratory under DARPA contract  * BG 91-66 and contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kvm_private.h	8.1 (Berkeley) 6/4/93  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|__kvm
block|{
comment|/* 	 * a string to be prepended to error messages 	 * provided for compatibility with sun's interface 	 * if this value is null, errors are saved in errbuf[] 	 */
specifier|const
name|char
modifier|*
name|program
decl_stmt|;
name|char
modifier|*
name|errp
decl_stmt|;
comment|/* XXX this can probably go away */
name|char
name|errbuf
index|[
name|_POSIX2_LINE_MAX
index|]
decl_stmt|;
define|#
directive|define
name|ISALIVE
parameter_list|(
name|kd
parameter_list|)
value|((kd)->vmfd>= 0)
name|int
name|pmfd
decl_stmt|;
comment|/* physical memory file (or crashdump) */
name|int
name|vmfd
decl_stmt|;
comment|/* virtual memory file (-1 if crashdump) */
name|int
name|unused
decl_stmt|;
comment|/* was: swap file (e.g., /dev/drum) */
name|int
name|nlfd
decl_stmt|;
comment|/* namelist file (e.g., /kernel) */
name|struct
name|kinfo_proc
modifier|*
name|procbase
decl_stmt|;
name|char
modifier|*
name|argspc
decl_stmt|;
comment|/* (dynamic) storage for argv strings */
name|int
name|arglen
decl_stmt|;
comment|/* length of the above */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* (dynamic) storage for argv pointers */
name|int
name|argc
decl_stmt|;
comment|/* length of above (not actual # present) */
name|char
modifier|*
name|argbuf
decl_stmt|;
comment|/* (dynamic) temporary storage */
comment|/* 	 * Kernel virtual address translation state.  This only gets filled 	 * in for dead kernels; otherwise, the running kernel (i.e. kmem) 	 * will do the translations for us.  It could be big, so we 	 * only allocate it if necessary. 	 */
name|struct
name|vmstate
modifier|*
name|vmst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Functions used internally by kvm, but across kvm modules.  */
end_comment

begin_function_decl
name|void
name|_kvm_err
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
specifier|const
name|char
modifier|*
name|program
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_kvm_freeprocs
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kvm_freevtop
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_initvtop
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_kvatop
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_kvm_malloc
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_kvm_realloc
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kvm_syserr
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
specifier|const
name|char
modifier|*
name|program
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|_kvm_uvatop
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|proc
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_function_decl
name|void
name|_kvm_minidump_freevtop
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_minidump_initvtop
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_kvm_minidump_kvatop
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

