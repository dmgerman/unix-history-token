begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  * NETLOGIC_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_SYS_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_SYS_H__
end_define

begin_comment
comment|/** * @file_name sys.h * @author Netlogic Microsystems * @brief HAL for System configuration registers */
end_comment

begin_define
define|#
directive|define
name|XLP_SYS_CHIP_RESET_REG
value|0x40
end_define

begin_define
define|#
directive|define
name|XLP_SYS_POWER_ON_RESET_REG
value|0x41
end_define

begin_define
define|#
directive|define
name|XLP_SYS_EFUSE_DEVICE_CFG_STATUS0_REG
value|0x42
end_define

begin_define
define|#
directive|define
name|XLP_SYS_EFUSE_DEVICE_CFG_STATUS1_REG
value|0x43
end_define

begin_define
define|#
directive|define
name|XLP_SYS_EFUSE_DEVICE_CFG_STATUS2_REG
value|0x44
end_define

begin_define
define|#
directive|define
name|XLP_SYS_EFUSE_DEVICE_CFG3_REG
value|0x45
end_define

begin_define
define|#
directive|define
name|XLP_SYS_EFUSE_DEVICE_CFG4_REG
value|0x46
end_define

begin_define
define|#
directive|define
name|XLP_SYS_EFUSE_DEVICE_CFG5_REG
value|0x47
end_define

begin_define
define|#
directive|define
name|XLP_SYS_EFUSE_DEVICE_CFG6_REG
value|0x48
end_define

begin_define
define|#
directive|define
name|XLP_SYS_EFUSE_DEVICE_CFG7_REG
value|0x49
end_define

begin_define
define|#
directive|define
name|XLP_SYS_PLL_CTRL_REG
value|0x4a
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU_RESET_REG
value|0x4b
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU_NONCOHERENT_MODE_REG
value|0x4d
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CORE_DFS_DIS_CTRL_REG
value|0x4e
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CORE_DFS_RST_CTRL_REG
value|0x4f
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CORE_DFS_BYP_CTRL_REG
value|0x50
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CORE_DFS_PHA_CTRL_REG
value|0x51
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CORE_DFS_DIV_INC_CTRL_REG
value|0x52
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CORE_DFS_DIV_DEC_CTRL_REG
value|0x53
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CORE_DFS_DIV_VALUE_REG
value|0x54
end_define

begin_define
define|#
directive|define
name|XLP_SYS_RESET_REG
value|0x55
end_define

begin_define
define|#
directive|define
name|XLP_SYS_DFS_DIS_CTRL_REG
value|0x56
end_define

begin_define
define|#
directive|define
name|XLP_SYS_DFS_RST_CTRL_REG
value|0x57
end_define

begin_define
define|#
directive|define
name|XLP_SYS_DFS_BYP_CTRL_REG
value|0x58
end_define

begin_define
define|#
directive|define
name|XLP_SYS_DFS_DIV_INC_CTRL_REG
value|0x59
end_define

begin_define
define|#
directive|define
name|XLP_SYS_DFS_DIV_DEC_CTRL_REG
value|0x5a
end_define

begin_define
define|#
directive|define
name|XLP_SYS_DFS_DIV_VALUE0_REG
value|0x5b
end_define

begin_define
define|#
directive|define
name|XLP_SYS_DFS_DIV_VALUE1_REG
value|0x5c
end_define

begin_define
define|#
directive|define
name|XLP_SYS_SENSE_AMP_DLY_REG
value|0x5d
end_define

begin_define
define|#
directive|define
name|XLP_SYS_SOC_SENSE_AMP_DLY_REG
value|0x5e
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CTRL0_REG
value|0x5f
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CTRL1_REG
value|0x60
end_define

begin_define
define|#
directive|define
name|XLP_SYS_TIMEOUT_BS1_REG
value|0x61
end_define

begin_define
define|#
directive|define
name|XLP_SYS_BYTE_SWAP_REG
value|0x62
end_define

begin_define
define|#
directive|define
name|XLP_SYS_VRM_VID_REG
value|0x63
end_define

begin_define
define|#
directive|define
name|XLP_SYS_PWR_RAM_CMD_REG
value|0x64
end_define

begin_define
define|#
directive|define
name|XLP_SYS_PWR_RAM_ADDR_REG
value|0x65
end_define

begin_define
define|#
directive|define
name|XLP_SYS_PWR_RAM_DATA0_REG
value|0x66
end_define

begin_define
define|#
directive|define
name|XLP_SYS_PWR_RAM_DATA1_REG
value|0x67
end_define

begin_define
define|#
directive|define
name|XLP_SYS_PWR_RAM_DATA2_REG
value|0x68
end_define

begin_define
define|#
directive|define
name|XLP_SYS_PWR_UCODE_REG
value|0x69
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU0_PWR_STATUS_REG
value|0x6a
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU1_PWR_STATUS_REG
value|0x6b
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU2_PWR_STATUS_REG
value|0x6c
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU3_PWR_STATUS_REG
value|0x6d
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU4_PWR_STATUS_REG
value|0x6e
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU5_PWR_STATUS_REG
value|0x6f
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU6_PWR_STATUS_REG
value|0x70
end_define

begin_define
define|#
directive|define
name|XLP_SYS_CPU7_PWR_STATUS_REG
value|0x71
end_define

begin_define
define|#
directive|define
name|XLP_SYS_STATUS_REG
value|0x72
end_define

begin_define
define|#
directive|define
name|XLP_SYS_INT_POL_REG
value|0x73
end_define

begin_define
define|#
directive|define
name|XLP_SYS_INT_TYPE_REG
value|0x74
end_define

begin_define
define|#
directive|define
name|XLP_SYS_INT_STATUS_REG
value|0x75
end_define

begin_define
define|#
directive|define
name|XLP_SYS_INT_MASK0_REG
value|0x76
end_define

begin_define
define|#
directive|define
name|XLP_SYS_INT_MASK1_REG
value|0x77
end_define

begin_define
define|#
directive|define
name|XLP_SYS_UCO_S_ECC_REG
value|0x78
end_define

begin_define
define|#
directive|define
name|XLP_SYS_UCO_M_ECC_REG
value|0x79
end_define

begin_define
define|#
directive|define
name|XLP_SYS_UCO_ADDR_REG
value|0x7a
end_define

begin_define
define|#
directive|define
name|XLP_SYS_UCO_INSTR_REG
value|0x7b
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST0_REG
value|0x7c
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST1_REG
value|0x7d
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST2_REG
value|0x7e
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST3_REG
value|0x7f
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST4_REG
value|0x80
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST5_REG
value|0x81
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST6_REG
value|0x82
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST7_REG
value|0x83
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST8_REG
value|0x84
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST9_REG
value|0x85
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST10_REG
value|0x86
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST11_REG
value|0x87
end_define

begin_define
define|#
directive|define
name|XLP_SYS_MEM_BIST12_REG
value|0x88
end_define

begin_define
define|#
directive|define
name|XLP_SYS_SCRTCH0_REG
value|0x89
end_define

begin_define
define|#
directive|define
name|XLP_SYS_SCRTCH1_REG
value|0x8a
end_define

begin_define
define|#
directive|define
name|XLP_SYS_SCRTCH2_REG
value|0x8b
end_define

begin_define
define|#
directive|define
name|XLP_SYS_SCRTCH3_REG
value|0x8c
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
name|nlm_rdreg_sys
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg_kseg(b,r)
end_define

begin_define
define|#
directive|define
name|nlm_wreg_sys
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg_kseg(b,r,v)
end_define

begin_define
define|#
directive|define
name|nlm_pcibase_sys
parameter_list|(
name|node
parameter_list|)
value|nlm_pcicfg_base(XLP_IO_SYS_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_regbase_sys
parameter_list|(
name|node
parameter_list|)
value|nlm_pcibase_sys(node)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

