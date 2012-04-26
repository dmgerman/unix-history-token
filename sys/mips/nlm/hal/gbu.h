begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NLM_HAL_GBU_H__
end_ifndef

begin_define
define|#
directive|define
name|_NLM_HAL_GBU_H__
end_define

begin_comment
comment|/* Global Bus Unit (GBU) for flash Specific registers */
end_comment

begin_define
define|#
directive|define
name|GBU_CS_BASEADDR
parameter_list|(
name|cs
parameter_list|)
value|(0x0+cs)
end_define

begin_define
define|#
directive|define
name|GBU_CS0_BASEADDR
value|0x0
end_define

begin_define
define|#
directive|define
name|GBU_CS1_BASEADDR
value|0x1
end_define

begin_define
define|#
directive|define
name|GBU_CS2_BASEADDR
value|0x2
end_define

begin_define
define|#
directive|define
name|GBU_CS3_BASEADDR
value|0x3
end_define

begin_define
define|#
directive|define
name|GBU_CS4_BASEADDR
value|0x4
end_define

begin_define
define|#
directive|define
name|GBU_CS5_BASEADDR
value|0x5
end_define

begin_define
define|#
directive|define
name|GBU_CS6_BASEADDR
value|0x6
end_define

begin_define
define|#
directive|define
name|GBU_CS7_BASEADDR
value|0x7
end_define

begin_define
define|#
directive|define
name|GBU_CS_BASELIMIT
parameter_list|(
name|cs
parameter_list|)
value|(0x8+cs)
end_define

begin_define
define|#
directive|define
name|GBU_CS0_BASELIMIT
value|0x8
end_define

begin_define
define|#
directive|define
name|GBU_CS1_BASELIMIT
value|0x9
end_define

begin_define
define|#
directive|define
name|GBU_CS2_BASELIMIT
value|0xa
end_define

begin_define
define|#
directive|define
name|GBU_CS3_BASELIMIT
value|0xb
end_define

begin_define
define|#
directive|define
name|GBU_CS4_BASELIMIT
value|0xc
end_define

begin_define
define|#
directive|define
name|GBU_CS5_BASELIMIT
value|0xd
end_define

begin_define
define|#
directive|define
name|GBU_CS6_BASELIMIT
value|0xe
end_define

begin_define
define|#
directive|define
name|GBU_CS7_BASELIMIT
value|0xf
end_define

begin_define
define|#
directive|define
name|GBU_CS_DEVPARAM
parameter_list|(
name|cs
parameter_list|)
value|(0x10+cs)
end_define

begin_define
define|#
directive|define
name|GBU_CS0_DEVPARAM
value|0x10
end_define

begin_define
define|#
directive|define
name|GBU_CS1_DEVPARAM
value|0x11
end_define

begin_define
define|#
directive|define
name|GBU_CS2_DEVPARAM
value|0x12
end_define

begin_define
define|#
directive|define
name|GBU_CS3_DEVPARAM
value|0x13
end_define

begin_define
define|#
directive|define
name|GBU_CS4_DEVPARAM
value|0x14
end_define

begin_define
define|#
directive|define
name|GBU_CS5_DEVPARAM
value|0x15
end_define

begin_define
define|#
directive|define
name|GBU_CS6_DEVPARAM
value|0x16
end_define

begin_define
define|#
directive|define
name|GBU_CS7_DEVPARAM
value|0x17
end_define

begin_define
define|#
directive|define
name|GBU_CS_DEVTIME0
parameter_list|(
name|cs
parameter_list|)
value|(0x18+cs)
end_define

begin_define
define|#
directive|define
name|GBU_CS0_DEVTIME0
value|0x18
end_define

begin_define
define|#
directive|define
name|GBU_CS1_DEVTIME0
value|0x1a
end_define

begin_define
define|#
directive|define
name|GBU_CS2_DEVTIME0
value|0x1c
end_define

begin_define
define|#
directive|define
name|GBU_CS3_DEVTIME0
value|0x1e
end_define

begin_define
define|#
directive|define
name|GBU_CS4_DEVTIME0
value|0x20
end_define

begin_define
define|#
directive|define
name|GBU_CS5_DEVTIME0
value|0x22
end_define

begin_define
define|#
directive|define
name|GBU_CS6_DEVTIME0
value|0x24
end_define

begin_define
define|#
directive|define
name|GBU_CS7_DEVTIME0
value|0x26
end_define

begin_define
define|#
directive|define
name|GBU_CS_DEVTIME1
parameter_list|(
name|cs
parameter_list|)
value|(0x19+cs)
end_define

begin_define
define|#
directive|define
name|GBU_CS0_DEVTIME1
value|0x19
end_define

begin_define
define|#
directive|define
name|GBU_CS1_DEVTIME1
value|0x1b
end_define

begin_define
define|#
directive|define
name|GBU_CS2_DEVTIME1
value|0x1d
end_define

begin_define
define|#
directive|define
name|GBU_CS3_DEVTIME1
value|0x1f
end_define

begin_define
define|#
directive|define
name|GBU_CS4_DEVTIME1
value|0x21
end_define

begin_define
define|#
directive|define
name|GBU_CS5_DEVTIME1
value|0x23
end_define

begin_define
define|#
directive|define
name|GBU_CS6_DEVTIME1
value|0x25
end_define

begin_define
define|#
directive|define
name|GBU_CS7_DEVTIME1
value|0x27
end_define

begin_define
define|#
directive|define
name|GBU_SYSCTRL
value|0x28
end_define

begin_define
define|#
directive|define
name|GBU_BYTESWAP
value|0x29
end_define

begin_define
define|#
directive|define
name|GBU_DI_TIMEOUT_VAL
value|0x2d
end_define

begin_define
define|#
directive|define
name|GBU_INTSTAT
value|0x2e
end_define

begin_define
define|#
directive|define
name|GBU_INTEN
value|0x2f
end_define

begin_define
define|#
directive|define
name|GBU_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|GBU_ERRLOG0
value|0x2a
end_define

begin_define
define|#
directive|define
name|GBU_ERRLOG1
value|0x2b
end_define

begin_define
define|#
directive|define
name|GBU_ERRLOG2
value|0x2c
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_define
define|#
directive|define
name|nlm_read_gbu_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_write_gbu_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_get_gbu_pcibase
parameter_list|(
name|node
parameter_list|)
define|\
value|nlm_pcicfg_base(XLP_IO_NOR_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_get_gbu_regbase
parameter_list|(
name|node
parameter_list|)
define|\
value|(nlm_get_gbu_pcibase(node) + XLP_IO_PCI_HDRSZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE&& !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NLM_HAL_GBU_H__ */
end_comment

end_unit

