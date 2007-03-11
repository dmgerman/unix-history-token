begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * Copyright (c) Peter Wemm<peter@netplex.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCPU_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|CPUSAVE_LEN
value|8
end_define

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|int		pc_inside_intr;					\ 	struct pmap	*pc_curpmap;
comment|/* current pmap */
value|\         struct thread   *pc_fputhread;
comment|/* current fpu user */
value|\ 	register_t	pc_tempsave[CPUSAVE_LEN];			\ 	register_t	pc_disisave[CPUSAVE_LEN];			\ 	register_t	pc_dbsave[CPUSAVE_LEN];
end_define

begin_comment
comment|/* Definitions for register offsets within the exception tmp save areas */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R28
value|0
end_define

begin_comment
comment|/* where r28 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R29
value|1
end_define

begin_comment
comment|/* where r29 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R30
value|2
end_define

begin_comment
comment|/* where r30 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_R31
value|3
end_define

begin_comment
comment|/* where r31 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_DAR
value|4
end_define

begin_comment
comment|/* where SPR_DAR gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_DSISR
value|5
end_define

begin_comment
comment|/* where SPR_DSISR gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_SRR0
value|6
end_define

begin_comment
comment|/* where SRR0 gets saved */
end_comment

begin_define
define|#
directive|define
name|CPUSAVE_SRR1
value|7
end_define

begin_comment
comment|/* where SRR1 gets saved */
end_comment

begin_define
define|#
directive|define
name|PCPUP
value|((struct pcpu *) powerpc_get_pcpup())
end_define

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|(PCPUP->pc_ ## member)
end_define

begin_comment
comment|/*  * XXX The implementation of this operation should be made atomic  * with respect to preemption.  */
end_comment

begin_define
define|#
directive|define
name|PCPU_LAZY_INC
parameter_list|(
name|member
parameter_list|)
value|(++PCPUP->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|member
parameter_list|)
value|(&PCPUP->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(PCPUP->pc_ ## member = (value))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PCPU_H_ */
end_comment

end_unit

