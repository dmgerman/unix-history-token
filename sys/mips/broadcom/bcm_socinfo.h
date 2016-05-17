begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michael Zhilin<mizhka@gmail.com>  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_BROADCOM_BCM_SOCINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_BROADCOM_BCM_SOCINFO_H_
end_define

begin_include
include|#
directive|include
file|<machine/cpuregs.h>
end_include

begin_struct
struct|struct
name|bcm_socinfo
block|{
name|uint32_t
name|id
decl_stmt|;
name|uint32_t
name|cpurate
decl_stmt|;
comment|/* in MHz */
name|uint32_t
name|uartrate
decl_stmt|;
comment|/* in Hz */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|bcm_socinfo
modifier|*
name|bcm_get_socinfo_by_socid
parameter_list|(
name|uint32_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bcm_socinfo
modifier|*
name|bcm_get_socinfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BCM_SOCADDR
value|0x18000000
end_define

begin_define
define|#
directive|define
name|BCM_REG_CHIPC_ID
value|0x0
end_define

begin_define
define|#
directive|define
name|BCM_REG_CHIPC_UART
value|0x300
end_define

begin_define
define|#
directive|define
name|BCM_REG_CHIPC_PMUWD_OFFS
value|0x634
end_define

begin_define
define|#
directive|define
name|BCM_SOCREG
parameter_list|(
name|reg
parameter_list|)
define|\
value|MIPS_PHYS_TO_KSEG1((BCM_SOCADDR + (reg)))
end_define

begin_define
define|#
directive|define
name|BCM_READ_REG32
parameter_list|(
name|reg
parameter_list|)
define|\
value|*((volatile uint32_t *)BCM_SOCREG(reg))
end_define

begin_define
define|#
directive|define
name|BCM_WRITE_REG32
parameter_list|(
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|do {								\ 		writel((void*)BCM_SOCREG((reg)),value);			\ 	} while (0);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_BROADCOM_BCM_SOCINFO_H_ */
end_comment

end_unit

