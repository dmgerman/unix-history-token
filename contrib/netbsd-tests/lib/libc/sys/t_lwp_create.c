begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_lwp_create.c,v 1.2 2012/05/22 09:23:39 martin Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This code is partly based on code by Joel Sing<joel at sing.id.au>  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<lwp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_include
include|#
directive|include
file|<machine/alpha_cpu.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__hppa__
end_ifdef

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__m68k__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sh3__
argument_list|)
operator|||
name|defined
name|__vax__
end_if

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|volatile
name|lwpid_t
name|the_lwp_id
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|lwp_main_func
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|the_lwp_id
operator|=
name|_lwp_self
argument_list|()
expr_stmt|;
name|_lwp_exit
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Hard to document - see usage examples below.  */
end_comment

begin_define
define|#
directive|define
name|INVALID_UCONTEXT
parameter_list|(
name|ARCH
parameter_list|,
name|NAME
parameter_list|,
name|DESC
parameter_list|)
define|\
value|static void ARCH##_##NAME(ucontext_t *);	\ ATF_TC(lwp_create_##ARCH##_fail_##NAME);	\ ATF_TC_HEAD(lwp_create_##ARCH##_fail_##NAME, tc)	\ {	\ 	atf_tc_set_md_var(tc, "descr", "verify rejection of invalid ucontext " \ 		"on " #ARCH " due to " DESC);	\ }	\ 	\ ATF_TC_BODY(lwp_create_##ARCH##_fail_##NAME, tc)	\ {	\ 	ucontext_t uc;		\ 	lwpid_t lid;		\ 	int error;		\ 				\ 	getcontext(&uc);	\ 	uc.uc_flags = _UC_CPU;	\ 	ARCH##_##NAME(&uc);	\ 				\ 	error = _lwp_create(&uc, 0,&lid);	\ 	ATF_REQUIRE(error != 0&& errno == EINVAL);	\ }	\ static void ARCH##_##NAME(ucontext_t *uc)	\ {
end_define

begin_expr_stmt
name|ATF_TC
argument_list|(
name|lwp_create_works
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|lwp_create_works
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Verify creation of a lwp and waiting"
literal|" for it to finish"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|lwp_create_works
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|ucontext_t
name|uc
decl_stmt|;
name|lwpid_t
name|lid
decl_stmt|;
name|int
name|error
decl_stmt|;
name|void
modifier|*
name|stack
decl_stmt|;
specifier|static
specifier|const
name|size_t
name|ssize
init|=
literal|16
operator|*
literal|1024
decl_stmt|;
name|stack
operator|=
name|malloc
argument_list|(
name|ssize
argument_list|)
expr_stmt|;
name|_lwp_makecontext
argument_list|(
operator|&
name|uc
argument_list|,
name|lwp_main_func
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|stack
argument_list|,
name|ssize
argument_list|)
expr_stmt|;
name|error
operator|=
name|_lwp_create
argument_list|(
operator|&
name|uc
argument_list|,
literal|0
argument_list|,
operator|&
name|lid
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|error
operator|==
literal|0
argument_list|)
expr_stmt|;
name|error
operator|=
name|_lwp_wait
argument_list|(
name|lid
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|error
operator|==
literal|0
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|lid
operator|==
name|the_lwp_id
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|INVALID_UCONTEXT
argument_list|(
argument|generic
argument_list|,
argument|no_uc_cpu
argument_list|,
literal|"not setting cpu registers"
argument_list|)
end_macro

begin_expr_stmt
name|uc
operator|->
name|uc_flags
operator|&=
operator|~
name|_UC_CPU
expr_stmt|;
end_expr_stmt

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|alpha
operator|,
name|pslset
operator|,
literal|"trying to clear the USERMODE flag"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PS
index|]
operator|&=
operator|~
name|ALPHA_PSL_USERMODE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} INVALID_UCONTEXT
operator|(
name|alpha
operator|,
name|pslclr
operator|,
literal|"trying to set a 'must be zero' flag"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PS
index|]
operator||=
name|ALPHA_PSL_IPL_HIGH
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|amd64
operator|,
name|untouchable_rflags
operator|,
literal|"forbidden rflags changed"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_RFLAGS
index|]
operator||=
name|PSL_MBZ
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/*  * XXX: add invalid GS/DS selector tests  */
end_comment

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|amd64
operator|,
name|pc_too_high
operator|,
literal|"instruction pointer outside userland address space"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_RIP
index|]
operator|=
name|VM_MAXUSER_ADDRESS
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__arm__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|arm
operator|,
name|invalid_mode
operator|,
literal|"psr or r15 set to non-user-mode"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PC
index|]
operator||=
literal|0x1f
comment|/*PSR_SYS32_MODE*/
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_CPSR
index|]
operator||=
literal|0x03
comment|/*R15_MODE_SVC*/
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__hppa__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|hppa
operator|,
name|invalid_1
operator|,
literal|"set illegal bits in psw"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PSW
index|]
operator||=
name|PSW_MBZ
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} INVALID_UCONTEXT
operator|(
name|hppa
operator|,
name|invalid_0
operator|,
literal|"clear illegal bits in psw"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PSW
index|]
operator|&=
operator|~
name|PSW_MBS
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|i386
operator|,
name|untouchable_eflags
operator|,
literal|"changing forbidden eflags"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_EFL
index|]
operator||=
name|PSL_IOPL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} INVALID_UCONTEXT
operator|(
name|i386
operator|,
name|priv_escalation
operator|,
literal|"modifying priviledge level"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_CS
index|]
operator|&=
operator|~
name|SEL_RPL
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__m68k__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|m68k
operator|,
name|invalid_ps_bits
operator|,
literal|"setting forbidden bits in the ps register"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PS
index|]
operator||=
operator|(
name|PSL_MBZ
operator||
name|PSL_IPL
operator||
name|PSL_S
operator|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__sh3__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|sh3
operator|,
name|modify_userstatic
operator|,
literal|"modifying illegal bits in the status register"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_SR
index|]
operator||=
name|PSL_MD
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|sparc
operator|,
name|pc_odd
operator|,
literal|"mis-aligned instruction pointer"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PC
index|]
operator|=
literal|0x100002
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} INVALID_UCONTEXT
operator|(
name|sparc
operator|,
name|npc_odd
operator|,
literal|"mis-aligned next instruction pointer"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_nPC
index|]
operator|=
literal|0x100002
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} INVALID_UCONTEXT
operator|(
name|sparc
operator|,
name|pc_null
operator|,
literal|"NULL instruction pointer"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PC
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} INVALID_UCONTEXT
operator|(
name|sparc
operator|,
name|npc_null
operator|,
literal|"NULL next instruction pointer"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_nPC
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__vax__
end_ifdef

begin_expr_stmt
unit|INVALID_UCONTEXT
operator|(
name|vax
operator|,
name|psl_0
operator|,
literal|"clearing forbidden bits in psl"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PSL
index|]
operator|&=
operator|~
operator|(
name|PSL_U
operator||
name|PSL_PREVU
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} INVALID_UCONTEXT
operator|(
name|vax
operator|,
name|psl_1
operator|,
literal|"setting forbidden bits in psl"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PSL
index|]
operator||=
name|PSL_IPL
operator||
name|PSL_IS
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} INVALID_UCONTEXT
operator|(
name|vax
operator|,
name|psl_cm
operator|,
literal|"setting CM bit in psl"
operator|)
name|uc
operator|->
name|uc_mcontext
operator|.
name|__gregs
index|[
name|_REG_PSL
index|]
operator||=
name|PSL_CM
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|ATF_TP_ADD_TCS
operator|(
name|tp
operator|)
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_works
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_generic_fail_no_uc_cpu
argument_list|)
block|;
ifdef|#
directive|ifdef
name|__alpha__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_alpha_fail_pslset
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_alpha_fail_pslclr
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__amd64__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_amd64_fail_untouchable_rflags
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_amd64_fail_pc_too_high
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__arm__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_arm_fail_invalid_mode
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__hppa__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_hppa_fail_invalid_1
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_hppa_fail_invalid_0
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__i386__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_i386_fail_untouchable_eflags
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_i386_fail_priv_escalation
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__m68k__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_m68k_fail_invalid_ps_bits
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__sh3__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_sh3_fail_modify_userstatic
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__sparc__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_sparc_fail_pc_odd
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_sparc_fail_npc_odd
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_sparc_fail_pc_null
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_sparc_fail_npc_null
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__vax__
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_vax_fail_psl_0
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_vax_fail_psl_1
argument_list|)
block|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|lwp_create_vax_fail_psl_cm
argument_list|)
block|;
endif|#
directive|endif
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_expr_stmt

end_unit

