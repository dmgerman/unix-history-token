begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_XLP_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_XLP_H__
end_define

begin_include
include|#
directive|include
file|<mips/nlm/hal/mips-extns.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/iomap.h>
end_include

begin_define
define|#
directive|define
name|PIC_UART_0_IRQ
value|9
end_define

begin_define
define|#
directive|define
name|PIC_UART_1_IRQ
value|10
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_0_IRQ
value|11
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_1_IRQ
value|12
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_2_IRQ
value|13
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_3_IRQ
value|14
end_define

begin_define
define|#
directive|define
name|PIC_EHCI_0_IRQ
value|39
end_define

begin_define
define|#
directive|define
name|PIC_EHCI_1_IRQ
value|42
end_define

begin_define
define|#
directive|define
name|PIC_MMC_IRQ
value|43
end_define

begin_comment
comment|/* XLP 8xx/4xx A0, A1, A2 CPU COP0 PRIDs */
end_comment

begin_define
define|#
directive|define
name|CHIP_PROCESSOR_ID_XLP_8XX
value|0x10
end_define

begin_define
define|#
directive|define
name|CHIP_PROCESSOR_ID_XLP_3XX
value|0x11
end_define

begin_comment
comment|/* Revision id's */
end_comment

begin_define
define|#
directive|define
name|XLP_REVISION_A0
value|0x00
end_define

begin_define
define|#
directive|define
name|XLP_REVISION_A1
value|0x01
end_define

begin_define
define|#
directive|define
name|XLP_REVISION_A2
value|0x02
end_define

begin_define
define|#
directive|define
name|XLP_REVISION_B0
value|0x03
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * FreeBSD can be started with few threads and cores turned off,  * so have a hardware thread id to FreeBSD cpuid mapping.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xlp_ncores
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xlp_threads_per_core
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|xlp_hw_thread_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xlp_cpuid_to_hwtid
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xlp_hwtid_to_cpuid
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function_decl
specifier|extern
name|void
name|xlp_enable_threads
parameter_list|(
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|uint32_t
name|xlp_get_cpu_frequency
parameter_list|(
name|int
name|core
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_pic_irt_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xlp_irt_to_irq
parameter_list|(
name|int
name|irt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xlp_irq_to_irt
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xlp_irq_is_picintr
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|nlm_is_xlp3xx
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|prid
init|=
operator|(
name|mips_rd_prid
argument_list|()
operator|>>
literal|8
operator|)
operator|&
literal|0xff
decl_stmt|;
return|return
operator|(
name|prid
operator|==
name|CHIP_PROCESSOR_ID_XLP_3XX
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|nlm_is_xlp8xx
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|prid
init|=
operator|(
name|mips_rd_prid
argument_list|()
operator|>>
literal|8
operator|)
operator|&
literal|0xff
decl_stmt|;
return|return
operator|(
name|prid
operator|==
name|CHIP_PROCESSOR_ID_XLP_8XX
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NLM_XLP_H__ */
end_comment

end_unit

