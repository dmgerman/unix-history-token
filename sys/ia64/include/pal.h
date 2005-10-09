begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PAL_H_
end_define

begin_comment
comment|/*  * Architected static calling convention procedures.  */
end_comment

begin_define
define|#
directive|define
name|PAL_CACHE_FLUSH
value|1
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_INFO
value|2
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_INIT
value|3
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_SUMMARY
value|4
end_define

begin_define
define|#
directive|define
name|PAL_MEM_ATTRIB
value|5
end_define

begin_define
define|#
directive|define
name|PAL_PTCE_INFO
value|6
end_define

begin_define
define|#
directive|define
name|PAL_VM_INFO
value|7
end_define

begin_define
define|#
directive|define
name|PAL_VM_SUMMARY
value|8
end_define

begin_define
define|#
directive|define
name|PAL_BUS_GET_FEATURES
value|9
end_define

begin_define
define|#
directive|define
name|PAL_BUS_SET_FEATURES
value|10
end_define

begin_define
define|#
directive|define
name|PAL_DEBUG_INFO
value|11
end_define

begin_define
define|#
directive|define
name|PAL_FIXED_ADDR
value|12
end_define

begin_define
define|#
directive|define
name|PAL_FREQ_BASE
value|13
end_define

begin_define
define|#
directive|define
name|PAL_FREQ_RATIOS
value|14
end_define

begin_define
define|#
directive|define
name|PAL_PERF_MON_INFO
value|15
end_define

begin_define
define|#
directive|define
name|PAL_PLATFORM_ADDR
value|16
end_define

begin_define
define|#
directive|define
name|PAL_PROC_GET_FEATURE
value|17
end_define

begin_define
define|#
directive|define
name|PAL_PROC_SET_FEATURE
value|18
end_define

begin_define
define|#
directive|define
name|PAL_RSE_INFO
value|19
end_define

begin_define
define|#
directive|define
name|PAL_VERSION
value|20
end_define

begin_define
define|#
directive|define
name|PAL_MC_CLEAR_LOG
value|21
end_define

begin_define
define|#
directive|define
name|PAL_MC_DRAIN
value|22
end_define

begin_define
define|#
directive|define
name|PAL_MC_DYNAMIC_STATE
value|24
end_define

begin_define
define|#
directive|define
name|PAL_MC_ERROR_INFO
value|25
end_define

begin_define
define|#
directive|define
name|PAL_MC_EXPECTED
value|23
end_define

begin_define
define|#
directive|define
name|PAL_MC_REGISTER_MEM
value|27
end_define

begin_define
define|#
directive|define
name|PAL_MC_RESUME
value|26
end_define

begin_define
define|#
directive|define
name|PAL_HALT
value|28
end_define

begin_define
define|#
directive|define
name|PAL_HALT_LIGHT
value|29
end_define

begin_define
define|#
directive|define
name|PAL_COPY_INFO
value|30
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_LINE_INIT
value|31
end_define

begin_define
define|#
directive|define
name|PAL_PMI_ENTRYPOINT
value|32
end_define

begin_define
define|#
directive|define
name|PAL_ENTER_IA_32_ENV
value|33
end_define

begin_define
define|#
directive|define
name|PAL_VM_PAGE_SIZE
value|34
end_define

begin_define
define|#
directive|define
name|PAL_MEM_FOR_TEST
value|37
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_PROT_INFO
value|38
end_define

begin_define
define|#
directive|define
name|PAL_REGISTER_INFO
value|39
end_define

begin_define
define|#
directive|define
name|PAL_SHUTDOWN
value|40
end_define

begin_define
define|#
directive|define
name|PAL_PREFETCH_VISIBILITY
value|41
end_define

begin_comment
comment|/*  * Architected stacked calling convention procedures.  */
end_comment

begin_define
define|#
directive|define
name|PAL_COPY_PAL
value|256
end_define

begin_define
define|#
directive|define
name|PAL_HALT_INFO
value|257
end_define

begin_define
define|#
directive|define
name|PAL_TEST_PROC
value|258
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_READ
value|259
end_define

begin_define
define|#
directive|define
name|PAL_CACHE_WRITE
value|260
end_define

begin_define
define|#
directive|define
name|PAL_VM_TR_READ
value|261
end_define

begin_comment
comment|/*  * Default physical address of the Processor Interrupt Block (PIB).  * See also: IA-64 SDM, rev 1.1, volume 2, page 5-31.  */
end_comment

begin_define
define|#
directive|define
name|PAL_PIB_DEFAULT_ADDR
value|0x00000000FEE00000L
end_define

begin_struct
struct|struct
name|ia64_pal_result
block|{
name|int64_t
name|pal_status
decl_stmt|;
name|u_int64_t
name|pal_result
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|ia64_pal_result
name|ia64_call_pal_static
parameter_list|(
name|u_int64_t
name|proc
parameter_list|,
name|u_int64_t
name|arg1
parameter_list|,
name|u_int64_t
name|arg2
parameter_list|,
name|u_int64_t
name|arg3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ia64_pal_result
name|ia64_call_pal_static_physical
parameter_list|(
name|u_int64_t
name|proc
parameter_list|,
name|u_int64_t
name|arg1
parameter_list|,
name|u_int64_t
name|arg2
parameter_list|,
name|u_int64_t
name|arg3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ia64_pal_result
name|ia64_call_pal_stacked
parameter_list|(
name|u_int64_t
name|proc
parameter_list|,
name|u_int64_t
name|arg1
parameter_list|,
name|u_int64_t
name|arg2
parameter_list|,
name|u_int64_t
name|arg3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ia64_pal_result
name|ia64_call_pal_stacked_physical
parameter_list|(
name|u_int64_t
name|proc
parameter_list|,
name|u_int64_t
name|arg1
parameter_list|,
name|u_int64_t
name|arg2
parameter_list|,
name|u_int64_t
name|arg3
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PAL_H_ */
end_comment

end_unit

