begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005, Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Machine dependent interfaces */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_HWPMC_PENTIUM_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_HWPMC_PENTIUM_H_
value|1
end_define

begin_comment
comment|/* Intel Pentium PMCs */
end_comment

begin_define
define|#
directive|define
name|PENTIUM_NPMCS
value|3
end_define

begin_comment
comment|/* 1 TSC + 2 PMCs */
end_comment

begin_define
define|#
directive|define
name|PENTIUM_CESR_PC1
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_CC1_MASK
value|0x01C00000
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_TO_CC1
parameter_list|(
name|C
parameter_list|)
value|(((C)& 0x07)<< 22)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_ES1_MASK
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_TO_ES1
parameter_list|(
name|E
parameter_list|)
value|(((E)& 0x3F)<< 16)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_PC0
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_CC0_MASK
value|0x000001C0
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_TO_CC0
parameter_list|(
name|C
parameter_list|)
value|(((C)& 0x07)<< 6)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_ES0_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_TO_ES0
parameter_list|(
name|E
parameter_list|)
value|((E)& 0x3F)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_RESERVED
value|0xFC00FC00
end_define

begin_define
define|#
directive|define
name|PENTIUM_MSR_CESR
value|0x11
end_define

begin_define
define|#
directive|define
name|PENTIUM_MSR_CTR0
value|0x12
end_define

begin_define
define|#
directive|define
name|PENTIUM_MSR_CTR1
value|0x13
end_define

begin_struct
struct|struct
name|pmc_md_pentium_op_pmcallocate
block|{
name|uint32_t
name|pm_pentium_config
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* MD extension for 'struct pmc' */
end_comment

begin_struct
struct|struct
name|pmc_md_pentium_pmc
block|{
name|uint32_t
name|pm_pentium_cesr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_function_decl
name|int
name|pmc_initialize_p5
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pentium PMCs */
end_comment

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
comment|/* _DEV_HWPMC_PENTIUM_H_ */
end_comment

end_unit

