begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 Semihalf, Rafal Jaworowski  * Copyright 2006 by Juniper Networks.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPC85XX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPC85XX_H_
end_define

begin_comment
comment|/*  * Configuration control and status registers  */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|ccsrbar_va
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CCSRBAR_VA
value|ccsrbar_va
end_define

begin_define
define|#
directive|define
name|OCP85XX_CCSRBAR
value|(CCSRBAR_VA + 0x0)
end_define

begin_define
define|#
directive|define
name|OCP85XX_BPTR
value|(CCSRBAR_VA + 0x20)
end_define

begin_comment
comment|/*  * E500 Coherency Module registers  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_EEBPCR
value|(CCSRBAR_VA + 0x1010)
end_define

begin_comment
comment|/*  * Local access registers  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_LAWBAR
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc08 + 0x20 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_LAWSR
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc10 + 0x20 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_LBC
value|4
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM_INTL
value|11
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RIO
value|12
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM1
value|15
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM2
value|22
end_define

begin_comment
comment|/*  * L2 cache registers  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_L2CTL
value|(CCSRBAR_VA + 0x20000)
end_define

begin_comment
comment|/*  * Power-On Reset configuration  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR
value|(CCSRBAR_VA + 0xe000c)
end_define

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR_IO_SEL
value|0x00780000
end_define

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR_IO_SEL_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR2
value|(CCSRBAR_VA + 0xe0014)
end_define

begin_comment
comment|/*  * Status Registers.  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_RSTCR
value|(CCSRBAR_VA + 0xe00b0)
end_define

begin_comment
comment|/*  * Prototypes.  */
end_comment

begin_function_decl
name|uint32_t
name|ccsr_read4
parameter_list|(
name|uintptr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ccsr_write4
parameter_list|(
name|uintptr_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|law_enable
parameter_list|(
name|int
name|trgt
parameter_list|,
name|u_long
name|addr
parameter_list|,
name|u_long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|law_disable
parameter_list|(
name|int
name|trgt
parameter_list|,
name|u_long
name|addr
parameter_list|,
name|u_long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|law_getmax
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|law_pci_target
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MPC85XX_H_ */
end_comment

end_unit

