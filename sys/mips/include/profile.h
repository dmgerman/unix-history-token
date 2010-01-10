begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: profile.h,v 1.2 1999/01/27 04:46:05 imp Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)profile.h	8.1 (Berkeley) 6/10/93  *	JNPR: profile.h,v 1.4 2006/12/02 09:53:41 katta  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void ___mcount
end_define

begin_comment
comment|/*XXX The cprestore instruction is a "dummy" to shut up as(1). */
end_comment

begin_comment
comment|/*XXX This is not MIPS64 safe. */
end_comment

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|__asm(".globl _mcount;"		\ 	".type _mcount,@function;"	\ 	"_mcount:;"			\ 	".set noreorder;"		\ 	".set noat;"			\ 	".cpload $25;"			\ 	".cprestore 4;"			\ 	"sw $4,8($29);"			\ 	"sw $5,12($29);"		\ 	"sw $6,16($29);"		\ 	"sw $7,20($29);"		\ 	"sw $1,0($29);"			\ 	"sw $31,4($29);"		\ 	"move $5,$31;"			\ 	"jal ___mcount;"		\ 	"move $4,$1;"			\ 	"lw $4,8($29);"			\ 	"lw $5,12($29);"		\ 	"lw $6,16($29);"		\ 	"lw $7,20($29);"		\ 	"lw $31,4($29);"		\ 	"lw $1,0($29);"			\ 	"addu $29,$29,8;"		\ 	"j $31;"			\ 	"move $31,$1;"			\ 	".set reorder;"			\ 	".set at");
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * The following two macros do splhigh and splx respectively.  * They have to be defined this way because these are real  * functions on the MIPS, and we do not want to invoke mcount  * recursively.  */
end_comment

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

begin_decl_stmt
specifier|extern
name|int
name|mcount_lock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|{					\ 	s = disable_intr();					\ 	while (!atomic_cmpset_acq_int(&mcount_lock, 0, 1))	\
comment|/* nothing */
value|;					\ }
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|{					\ 	atomic_store_rel_int(&mcount_lock, 0);			\ 	enableintr(s);						\ }
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
value|{ s = disable_intr(); }
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|(enableintr(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REVISIT for mips */
end_comment

begin_comment
comment|/*  * Config generates something to tell the compiler to align functions on 16  * byte boundaries.  A strict alignment is good for keeping the tables small.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|16
end_define

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

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|4
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

begin_function_decl
name|void
name|mcount
parameter_list|(
name|uintfptr_t
name|frompc
parameter_list|,
name|uintfptr_t
name|selfpc
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|nullfunc_loop_profiled
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nullfunc_profiled
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|startguprof
parameter_list|(
name|struct
name|gmonparam
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stopguprof
parameter_list|(
name|struct
name|gmonparam
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

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
argument_list|(
name|void
argument_list|)
asm|__asm(".mcount");
else|#
directive|else
name|void
name|mcount
argument_list|(
name|void
argument_list|)
asm|__asm("mcount");
endif|#
directive|endif
endif|#
directive|endif
name|void
name|_mcount
argument_list|(
name|uintfptr_t
name|frompc
argument_list|,
name|uintfptr_t
name|selfpc
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

begin_function_decl
name|__BEGIN_DECLS
name|int
name|cputime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|empty_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mexitcount
parameter_list|(
name|uintfptr_t
name|selfpc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nullfunc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nullfunc_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

