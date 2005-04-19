begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003, Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Machine dependent interfaces */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PMC_MDEP_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PMC_MDEP_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/pmc.h>
end_include

begin_comment
comment|/* AMD K7 PMCs */
end_comment

begin_define
define|#
directive|define
name|K8_NPMCS
value|5
end_define

begin_comment
comment|/* 1 TSC + 4 PMCs */
end_comment

begin_define
define|#
directive|define
name|K8_PMC_COUNTERMASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|K8_PMC_TO_COUNTER
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 24)& K8_PMC_COUNTERMASK)
end_define

begin_define
define|#
directive|define
name|K8_PMC_INVERT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|K8_PMC_ENABLE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|K8_PMC_INT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|K8_PMC_PC
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|K8_PMC_EDGE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|K8_PMC_OS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|K8_PMC_USR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|K8_PMC_UNITMASK_M
value|0x10
end_define

begin_define
define|#
directive|define
name|K8_PMC_UNITMASK_O
value|0x08
end_define

begin_define
define|#
directive|define
name|K8_PMC_UNITMASK_E
value|0x04
end_define

begin_define
define|#
directive|define
name|K8_PMC_UNITMASK_S
value|0x02
end_define

begin_define
define|#
directive|define
name|K8_PMC_UNITMASK_I
value|0x01
end_define

begin_define
define|#
directive|define
name|K8_PMC_UNITMASK_MOESI
value|0x1F
end_define

begin_define
define|#
directive|define
name|K8_PMC_UNITMASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|K8_PMC_EVENTMASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|K8_PMC_TO_UNITMASK
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 8)& K8_PMC_UNITMASK)
end_define

begin_define
define|#
directive|define
name|K8_PMC_TO_EVENTMASK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|K8_VALID_BITS
value|(K8_PMC_COUNTERMASK | K8_PMC_INVERT |      \ 	K8_PMC_ENABLE | K8_PMC_INT | K8_PMC_PC | K8_PMC_EDGE | K8_PMC_OS | \ 	K8_PMC_USR | K8_PMC_UNITMASK | K8_PMC_EVENTMASK)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_amd_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__i386__) */
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
comment|/* _MACHINE_PMC_MDEP_H */
end_comment

end_unit

