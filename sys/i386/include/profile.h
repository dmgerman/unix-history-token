begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)profile.h	8.1 (Berkeley) 6/11/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PROFILE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Config generates something to tell the compiler to align functions on 16  * byte boundaries.  A strict alignment is good for keeping the tables small.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|16
end_define

begin_comment
comment|/*  * The kernel uses assembler stubs instead of unportable inlines.  * This is mainly to save a little time when profiling is not enabled,  * which is the usual case for the kernel.  */
end_comment

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

begin_define
define|#
directive|define
name|CALIB_SCALE
value|1000
end_define

begin_define
define|#
directive|define
name|KCOUNT
parameter_list|(
name|p
parameter_list|,
name|index
parameter_list|)
value|((p)->kcount[(index) \ 			 / (HISTFRACTION * sizeof(HISTCOUNTER))])
end_define

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PC_TO_I
parameter_list|(
name|p
parameter_list|,
name|pc
parameter_list|)
value|((uintfptr_t)(pc) - (uintfptr_t)(p)->lowpc)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
value|u_long s;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|{ s = read_eflags(); \  			  __asm __volatile("cli" : : : "memory"); \ 			  s_lock_np(&mcount_lock); }
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|{ s_unlock_np(&mcount_lock); write_eflags(s); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|{ s = read_eflags(); disable_intr(); }
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|(write_eflags(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GUPROF */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|static __inline void _mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|void \ mcount() \ { \ 	uintfptr_t selfpc, frompc; \
comment|/* \ 	 * Find the return address for mcount, \ 	 * and the return address for mcount's caller. \ 	 * \ 	 * selfpc = pc pushed by call to mcount \ 	 */
value|\ 	asm("movl 4(%%ebp),%0" : "=r" (selfpc)); \
comment|/* \ 	 * frompc = pc pushed by call to mcount's caller. \ 	 * The caller's stack frame has already been built, so %ebp is \ 	 * the caller's frame pointer.  The caller's raddr is in the \ 	 * caller's frame following the caller's caller's frame pointer. \ 	 */
value|\ 	asm("movl (%%ebp),%0" : "=r" (frompc)); \ 	frompc = ((uintfptr_t *)frompc)[1]; \ 	_mcount(frompc, selfpc); \ }
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uintfptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * An unsigned integral type that can hold non-negative difference between  * function pointers.  */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|fptrdiff_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
name|void
name|mcount
name|__P
argument_list|(
operator|(
name|uintfptr_t
name|frompc
operator|,
name|uintfptr_t
name|selfpc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

begin_struct_decl
struct_decl|struct
name|gmonparam
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|nullfunc_loop_profiled
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nullfunc_profiled
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|startguprof
name|__P
argument_list|(
operator|(
expr|struct
name|gmonparam
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stopguprof
name|__P
argument_list|(
operator|(
expr|struct
name|gmonparam
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|startguprof
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|stopguprof
parameter_list|(
name|p
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GUPROF */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
ifdef|#
directive|ifdef
name|__GNUC__
ifdef|#
directive|ifdef
name|__ELF__
name|void
name|mcount
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm(".mcount");
else|#
directive|else
name|void
name|mcount
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
asm|__asm("mcount");
endif|#
directive|endif
endif|#
directive|endif
decl|static
name|void
name|_mcount
name|__P
argument_list|(
operator|(
name|uintfptr_t
name|frompc
operator|,
name|uintfptr_t
name|selfpc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
endif|#
directive|endif
comment|/* _KERNEL */
ifdef|#
directive|ifdef
name|GUPROF
comment|/* XXX doesn't quite work outside kernel yet. */
specifier|extern
name|int
name|cputime_bias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|cputime
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|empty_loop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mexitcount
name|__P
argument_list|(
operator|(
name|uintfptr_t
name|selfpc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nullfunc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nullfunc_loop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PROFILE_H_ */
end_comment

end_unit

