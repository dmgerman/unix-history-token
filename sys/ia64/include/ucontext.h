begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_UCONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_UCONTEXT_H_
end_define

begin_include
include|#
directive|include
file|<machine/_regset.h>
end_include

begin_comment
comment|/*  * The mc_flags field provides the necessary clues when dealing with the gory  * details of ia64 specific contexts. A comprehensive explanation is added for  * everybody's sanity, including the author's.  *  * The first and foremost variation in the context is synchronous contexts  * (= synctx) versus asynchronous contexts (= asynctx). A synctx is created  * synchronously WRT program execution and has the advantage that none of the  * scratch registers have to be saved. They are assumed to be clobbered by the  * call to the function that creates the context. An asynctx needs to have the  * scratch registers preserved because it can describe any point in a thread's  * (or process') execution.  * The second variation is for synchronous contexts. When the kernel creates  * a synchronous context if needs to preserve the scratch registers, because  * the syscall argument and return values are stored there in the trapframe  * and they need to be preserved in order to restart a syscall or return the  * proper return values. Also, the IIP and CFM fields need to be preserved  * as they point to the syscall stub, which the kernel saves as a favor to  * userland (it keeps the stubs small and simple).  *  * Below a description of the flags and their meaning:  *  *	_MC_FLAGS_ASYNC_CONTEXT  *		If set, indicates that mc_scratch and mc_scratch_fp are both  *		valid. IFF not set, _MC_FLAGS_SYSCALL_CONTEXT indicates if the  *		synchronous context is one corresponding to a syscall or not.  *		Only the kernel is expected to create such a context and it's  *		probably wise to let the kernel restore it.  *	_MC_FLAGS_HIGHFP_VALID  *		If set, indicates that the high FP registers (f32-f127) are  *		valid. This flag is very likely not going to be set for any  *		sensible synctx, but is not explicitly disallowed. Any synctx  *		that has this flag may or may not have the high FP registers  *		restored. In short: don't do it.  *	_MC_FLAGS_SYSCALL_CONTEXT  *		If set (hence _MC_FLAGS_ASYNC_CONTEXT is not set) indicates  *		that the scratch registers contain syscall arguments and  *		return values and that additionally IIP and CFM are valid.  *		Only the kernel is expected to create such a context. It's  *		probably wise to let the kernel restore it.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__mcontext
block|{
name|unsigned
name|long
name|mc_flags
decl_stmt|;
define|#
directive|define
name|_MC_FLAGS_ASYNC_CONTEXT
value|0x0001
define|#
directive|define
name|_MC_FLAGS_HIGHFP_VALID
value|0x0002
define|#
directive|define
name|_MC_FLAGS_KSE_SET_MBOX
value|0x0004
comment|/* Undocumented. Has to go. */
define|#
directive|define
name|_MC_FLAGS_SYSCALL_CONTEXT
value|0x0008
name|unsigned
name|long
name|_reserved_
decl_stmt|;
name|struct
name|_special
name|mc_special
decl_stmt|;
name|struct
name|_callee_saved
name|mc_preserved
decl_stmt|;
name|struct
name|_callee_saved_fp
name|mc_preserved_fp
decl_stmt|;
name|struct
name|_caller_saved
name|mc_scratch
decl_stmt|;
name|struct
name|_caller_saved_fp
name|mc_scratch_fp
decl_stmt|;
name|struct
name|_high_fp
name|mc_high_fp
decl_stmt|;
block|}
name|mcontext_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_UCONTEXT_H_ */
end_comment

end_unit

