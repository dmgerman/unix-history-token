begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Justin Hibbits  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_HWPMC_POWERPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_HWPMC_POWERPC_H_
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|POWERPC_PMC_CAPS
value|(PMC_CAP_INTERRUPT | PMC_CAP_USER |     \ 				 PMC_CAP_SYSTEM | PMC_CAP_EDGE |	\ 				 PMC_CAP_THRESHOLD | PMC_CAP_READ |	\ 				 PMC_CAP_WRITE | PMC_CAP_INVERT |	\ 				 PMC_CAP_QUALIFIER)
end_define

begin_define
define|#
directive|define
name|POWERPC_PMC_KERNEL_ENABLE
value|(0x1<< 30)
end_define

begin_define
define|#
directive|define
name|POWERPC_PMC_USER_ENABLE
value|(0x1<< 31)
end_define

begin_define
define|#
directive|define
name|POWERPC_PMC_ENABLE
value|(POWERPC_PMC_KERNEL_ENABLE | POWERPC_PMC_USER_ENABLE)
end_define

begin_define
define|#
directive|define
name|POWERPC_RELOAD_COUNT_TO_PERFCTR_VALUE
parameter_list|(
name|V
parameter_list|)
value|(0x80000000-(V))
end_define

begin_define
define|#
directive|define
name|POWERPC_PERFCTR_VALUE_TO_RELOAD_COUNT
parameter_list|(
name|P
parameter_list|)
value|(0x80000000-(P))
end_define

begin_struct
struct|struct
name|powerpc_cpu
block|{
name|struct
name|pmc_hw
modifier|*
name|pc_ppcpmcs
decl_stmt|;
name|enum
name|pmc_class
name|pc_class
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|powerpc_cpu
modifier|*
modifier|*
name|powerpc_pcpu
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|pmc_mpc7xxx_initialize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|pmc_mdep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pmc_ppc970_initialize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|pmc_mdep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|powerpc_describe
parameter_list|(
name|int
name|cpu
parameter_list|,
name|int
name|ri
parameter_list|,
name|struct
name|pmc_info
modifier|*
name|pi
parameter_list|,
name|struct
name|pmc
modifier|*
modifier|*
name|ppmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|powerpc_get_config
parameter_list|(
name|int
name|cpu
parameter_list|,
name|int
name|ri
parameter_list|,
name|struct
name|pmc
modifier|*
modifier|*
name|ppm
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _DEV_HWPMC_POWERPC_H_ */
end_comment

end_unit

