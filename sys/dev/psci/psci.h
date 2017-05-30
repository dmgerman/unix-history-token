begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013, 2014 Robin Randhawa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PSCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PSCI_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|psci_initfn_t
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|psci_callfn_t
function_decl|)
parameter_list|(
name|register_t
parameter_list|,
name|register_t
parameter_list|,
name|register_t
parameter_list|,
name|register_t
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|psci_present
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|psci_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|psci_cpu_on
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|psci_hvc_despatch
parameter_list|(
name|register_t
parameter_list|,
name|register_t
parameter_list|,
name|register_t
parameter_list|,
name|register_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|psci_smc_despatch
parameter_list|(
name|register_t
parameter_list|,
name|register_t
parameter_list|,
name|register_t
parameter_list|,
name|register_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PSCI return codes.  */
end_comment

begin_define
define|#
directive|define
name|PSCI_RETVAL_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|PSCI_RETVAL_NOT_SUPPORTED
value|-1
end_define

begin_define
define|#
directive|define
name|PSCI_RETVAL_INVALID_PARAMS
value|-2
end_define

begin_define
define|#
directive|define
name|PSCI_RETVAL_DENIED
value|-3
end_define

begin_define
define|#
directive|define
name|PSCI_RETVAL_ALREADY_ON
value|-4
end_define

begin_define
define|#
directive|define
name|PSCI_RETVAL_ON_PENDING
value|-5
end_define

begin_define
define|#
directive|define
name|PSCI_RETVAL_INTERNAL_FAILURE
value|-6
end_define

begin_define
define|#
directive|define
name|PSCI_RETVAL_NOT_PRESENT
value|-7
end_define

begin_define
define|#
directive|define
name|PSCI_RETVAL_DISABLED
value|-8
end_define

begin_comment
comment|/*  * PSCI function codes (as per PSCI v0.2).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__aarch64__
end_ifdef

begin_define
define|#
directive|define
name|PSCI_FNID_VERSION
value|0x84000000
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_CPU_SUSPEND
value|0xc4000001
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_CPU_OFF
value|0x84000002
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_CPU_ON
value|0xc4000003
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_AFFINITY_INFO
value|0xc4000004
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_MIGRATE
value|0xc4000005
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_MIGRATE_INFO_TYPE
value|0x84000006
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_MIGRATE_INFO_UP_CPU
value|0xc4000007
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_SYSTEM_OFF
value|0x84000008
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_SYSTEM_RESET
value|0x84000009
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PSCI_FNID_VERSION
value|0x84000000
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_CPU_SUSPEND
value|0x84000001
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_CPU_OFF
value|0x84000002
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_CPU_ON
value|0x84000003
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_AFFINITY_INFO
value|0x84000004
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_MIGRATE
value|0x84000005
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_MIGRATE_INFO_TYPE
value|0x84000006
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_MIGRATE_INFO_UP_CPU
value|0x84000007
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_SYSTEM_OFF
value|0x84000008
end_define

begin_define
define|#
directive|define
name|PSCI_FNID_SYSTEM_RESET
value|0x84000009
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PSCI_VER_MAJOR
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 16)& 0xFF)
end_define

begin_define
define|#
directive|define
name|PSCI_VER_MINOR
parameter_list|(
name|v
parameter_list|)
value|((v)& 0xFF)
end_define

begin_enum
enum|enum
name|psci_fn
block|{
name|PSCI_FN_VERSION
block|,
name|PSCI_FN_CPU_SUSPEND
block|,
name|PSCI_FN_CPU_OFF
block|,
name|PSCI_FN_CPU_ON
block|,
name|PSCI_FN_AFFINITY_INFO
block|,
name|PSCI_FN_MIGRATE
block|,
name|PSCI_FN_MIGRATE_INFO_TYPE
block|,
name|PSCI_FN_MIGRATE_INFO_UP_CPU
block|,
name|PSCI_FN_SYSTEM_OFF
block|,
name|PSCI_FN_SYSTEM_RESET
block|,
name|PSCI_FN_MAX
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PSCI_H_ */
end_comment

end_unit

