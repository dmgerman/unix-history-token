begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen<luoqi@freebsd.org>  * Copyright (c) Peter Wemm<peter@netplex.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: src/sys/alpha/include/pcpu.h,v 1.15 2004/11/05 19:16:44 jhb  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_define
define|#
directive|define
name|PCPU_MD_COMMON_FIELDS
define|\
value|pd_entry_t	*pc_segbase;
comment|/* curthread segbase */
value|\ 	struct	pmap	*pc_curpmap;
comment|/* pmap of curthread */
value|\ 	u_int32_t	pc_next_asid;
comment|/* next ASID to alloc */
value|\ 	u_int32_t	pc_asid_generation;
comment|/* current ASID generation */
value|\ 	u_int		pc_pending_ipis;
comment|/* IPIs pending to this CPU */
value|\ 	struct	pcpu	*pc_self;
end_define

begin_comment
comment|/* globally-uniqe self pointer */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|PCPU_MD_MIPS64_FIELDS
define|\
value|PCPU_MD_COMMON_FIELDS						\ 	char		__pad[245]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCPU_MD_MIPS32_FIELDS
define|\
value|PCPU_MD_COMMON_FIELDS						\ 	char		__pad[125]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
value|PCPU_MD_MIPS64_FIELDS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
value|PCPU_MD_MIPS32_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|pcpu_space
index|[
name|MAXCPU
index|]
index|[
name|PAGE_SIZE
operator|*
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PCPU_ADDR
parameter_list|(
name|cpu
parameter_list|)
value|(struct pcpu *)(pcpu_space[(cpu)])
end_define

begin_decl_stmt
specifier|extern
name|struct
name|pcpu
modifier|*
name|pcpup
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PCPUP
value|pcpup
end_define

begin_comment
comment|/*  * Since we use a wired TLB entry to map the same VA to a different  * physical page for each CPU, get_pcpu() must use the pc_self  * field to obtain a globally-unique pointer.  */
end_comment

begin_define
define|#
directive|define
name|get_pcpu
parameter_list|()
value|(PCPUP->pc_self)
end_define

begin_define
define|#
directive|define
name|PCPU_ADD
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(PCPUP->pc_ ## member += (value))
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

begin_define
define|#
directive|define
name|PCPU_INC
parameter_list|(
name|member
parameter_list|)
value|PCPU_ADD(member, 1)
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

begin_define
define|#
directive|define
name|PCPU_LAZY_INC
parameter_list|(
name|member
parameter_list|)
value|(++PCPUP->pc_ ## member)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_comment
comment|/*  * Instantiate the wired TLB entry at PCPU_TLB_ENTRY to map 'pcpu' at 'pcpup'.  */
end_comment

begin_function_decl
name|void
name|mips_pcpu_tlb_init
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
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

