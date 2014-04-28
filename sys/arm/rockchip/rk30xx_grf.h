begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RK30_GRF_H_
end_ifndef

begin_define
define|#
directive|define
name|_RK30_GRF_H_
end_define

begin_define
define|#
directive|define
name|RK30_GRF_BASE
value|0xF0008000
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0L_DIR
value|0x0000
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0H_DIR
value|0x0004
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1L_DIR
value|0x0008
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1H_DIR
value|0x000c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2L_DIR
value|0x0010
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2H_DIR
value|0x0014
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3L_DIR
value|0x0018
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3H_DIR
value|0x001c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0L_DO
value|0x0020
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0H_DO
value|0x0024
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1L_DO
value|0x0028
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1H_DO
value|0x002c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2L_DO
value|0x0030
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2H_DO
value|0x0034
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3L_DO
value|0x0038
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3H_DO
value|0x003c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0L_EN
value|0x0040
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0H_EN
value|0x0044
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1L_EN
value|0x0048
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1H_EN
value|0x004c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2L_EN
value|0x0050
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2H_EN
value|0x0054
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3L_EN
value|0x0058
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3H_EN
value|0x005c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0C_IOMUX
value|0x0068
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0D_IOMUX
value|0x006c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1A_IOMUX
value|0x0070
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1B_IOMUX
value|0x0074
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1C_IOMUX
value|0x0078
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1D_IOMUX
value|0x007c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2A_IOMUX
value|0x0080
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2B_IOMUX
value|0x0084
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2C_IOMUX
value|0x0088
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2D_IOMUX
value|0x008c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3A_IOMUX
value|0x0090
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3B_IOMUX
value|0x0094
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3C_IOMUX
value|0x0098
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3D_IOMUX
value|0x009c
end_define

begin_define
define|#
directive|define
name|GRF_SOC_CON0
value|0x00a0
end_define

begin_define
define|#
directive|define
name|GRF_SOC_CON1
value|0x00a4
end_define

begin_define
define|#
directive|define
name|GRF_SOC_CON2
value|0x00a8
end_define

begin_define
define|#
directive|define
name|GRF_SOC_STATUS0
value|0x00ac
end_define

begin_define
define|#
directive|define
name|GRF_DMAC1_CON0
value|0x00b0
end_define

begin_define
define|#
directive|define
name|GRF_DMAC1_CON1
value|0x00b4
end_define

begin_define
define|#
directive|define
name|GRF_DMAC1_CON2
value|0x00b8
end_define

begin_define
define|#
directive|define
name|GRF_DMAC2_CON0
value|0x00bc
end_define

begin_define
define|#
directive|define
name|GRF_DMAC2_CON1
value|0x00c0
end_define

begin_define
define|#
directive|define
name|GRF_DMAC2_CON2
value|0x00c4
end_define

begin_define
define|#
directive|define
name|GRF_DMAC2_CON3
value|0x00c8
end_define

begin_define
define|#
directive|define
name|GRF_CPU_CON0
value|0x00cc
end_define

begin_define
define|#
directive|define
name|GRF_CPU_CON1
value|0x00d0
end_define

begin_define
define|#
directive|define
name|GRF_CPU_CON2
value|0x00d4
end_define

begin_define
define|#
directive|define
name|GRF_CPU_CON3
value|0x00d8
end_define

begin_define
define|#
directive|define
name|GRF_CPU_CON4
value|0x00dc
end_define

begin_define
define|#
directive|define
name|GRF_CPU_CON5
value|0x00e0
end_define

begin_define
define|#
directive|define
name|GRF_DDRC_CON0
value|0x00ec
end_define

begin_define
define|#
directive|define
name|GRF_DDRC_STAT
value|0x00f0
end_define

begin_define
define|#
directive|define
name|GRF_IO_CON0
value|0x00f4
end_define

begin_define
define|#
directive|define
name|GRF_IO_CON1
value|0x00f8
end_define

begin_define
define|#
directive|define
name|GRF_IO_CON2
value|0x00fc
end_define

begin_define
define|#
directive|define
name|GRF_IO_CON3
value|0x0100
end_define

begin_define
define|#
directive|define
name|GRF_IO_CON4
value|0x0104
end_define

begin_define
define|#
directive|define
name|GRF_SOC_STATUS1
value|0x0108
end_define

begin_define
define|#
directive|define
name|GRF_UOC0_CON0
value|0x010c
end_define

begin_define
define|#
directive|define
name|GRF_UOC0_CON1
value|0x0110
end_define

begin_define
define|#
directive|define
name|GRF_UOC0_CON2
value|0x0114
end_define

begin_define
define|#
directive|define
name|GRF_UOC0_CON3
value|0x0118
end_define

begin_define
define|#
directive|define
name|GRF_UOC1_CON0
value|0x011c
end_define

begin_define
define|#
directive|define
name|GRF_UOC1_CON1
value|0x0120
end_define

begin_define
define|#
directive|define
name|GRF_UOC1_CON2
value|0x0124
end_define

begin_define
define|#
directive|define
name|GRF_UOC1_CON3
value|0x0128
end_define

begin_define
define|#
directive|define
name|GRF_UOC2_CON0
value|0x012c
end_define

begin_define
define|#
directive|define
name|GRF_UOC2_CON1
value|0x0130
end_define

begin_define
define|#
directive|define
name|GRF_UOC3_CON0
value|0x0138
end_define

begin_define
define|#
directive|define
name|GRF_UOC3_CON1
value|0x013c
end_define

begin_define
define|#
directive|define
name|GRF_HSIC_STAT
value|0x0140
end_define

begin_define
define|#
directive|define
name|GRF_OS_REG0
value|0x0144
end_define

begin_define
define|#
directive|define
name|GRF_OS_REG1
value|0x0148
end_define

begin_define
define|#
directive|define
name|GRF_OS_REG2
value|0x014c
end_define

begin_define
define|#
directive|define
name|GRF_OS_REG3
value|0x0150
end_define

begin_define
define|#
directive|define
name|GRF_OS_REG4
value|0x0154
end_define

begin_define
define|#
directive|define
name|GRF_OS_REG5
value|0x0158
end_define

begin_define
define|#
directive|define
name|GRF_OS_REG6
value|0x015c
end_define

begin_define
define|#
directive|define
name|GRF_OS_REG7
value|0x0160
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0B_PULL
value|0x0164
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0C_PULL
value|0x0168
end_define

begin_define
define|#
directive|define
name|GRF_GPIO0D_PULL
value|0x016c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1A_PULL
value|0x0170
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1B_PULL
value|0x0174
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1C_PULL
value|0x0178
end_define

begin_define
define|#
directive|define
name|GRF_GPIO1D_PULL
value|0x017c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2A_PULL
value|0x0180
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2B_PULL
value|0x0184
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2C_PULL
value|0x0188
end_define

begin_define
define|#
directive|define
name|GRF_GPIO2D_PULL
value|0x018c
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3A_PULL
value|0x0190
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3B_PULL
value|0x0194
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3C_PULL
value|0x0198
end_define

begin_define
define|#
directive|define
name|GRF_GPIO3D_PULL
value|0x019c
end_define

begin_define
define|#
directive|define
name|GRF_FLASH_DATA_PULL
value|0x01a0
end_define

begin_define
define|#
directive|define
name|GRF_FLASH_CMD_PULL
value|0x01a4
end_define

begin_function_decl
name|void
name|rk30_grf_gpio_pud
parameter_list|(
name|uint32_t
name|bank
parameter_list|,
name|uint32_t
name|pin
parameter_list|,
name|uint32_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RK30_GRF_H_ */
end_comment

end_unit

