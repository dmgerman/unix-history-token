begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_HAL_SYS_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_HAL_SYS_H__
end_define

begin_comment
comment|/** * @file_name sys.h * @author Netlogic Microsystems * @brief HAL for System configuration registers */
end_comment

begin_define
define|#
directive|define
name|SYS_CHIP_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|SYS_POWER_ON_RESET_CFG
value|0x01
end_define

begin_define
define|#
directive|define
name|SYS_EFUSE_DEVICE_CFG_STATUS0
value|0x02
end_define

begin_define
define|#
directive|define
name|SYS_EFUSE_DEVICE_CFG_STATUS1
value|0x03
end_define

begin_define
define|#
directive|define
name|SYS_EFUSE_DEVICE_CFG_STATUS2
value|0x04
end_define

begin_define
define|#
directive|define
name|SYS_EFUSE_DEVICE_CFG3
value|0x05
end_define

begin_define
define|#
directive|define
name|SYS_EFUSE_DEVICE_CFG4
value|0x06
end_define

begin_define
define|#
directive|define
name|SYS_EFUSE_DEVICE_CFG5
value|0x07
end_define

begin_define
define|#
directive|define
name|SYS_EFUSE_DEVICE_CFG6
value|0x08
end_define

begin_define
define|#
directive|define
name|SYS_EFUSE_DEVICE_CFG7
value|0x09
end_define

begin_define
define|#
directive|define
name|SYS_PLL_CTRL
value|0x0a
end_define

begin_define
define|#
directive|define
name|SYS_CPU_RESET
value|0x0b
end_define

begin_define
define|#
directive|define
name|SYS_CPU_NONCOHERENT_MODE
value|0x0d
end_define

begin_define
define|#
directive|define
name|SYS_CORE_DFS_DIS_CTRL
value|0x0e
end_define

begin_define
define|#
directive|define
name|SYS_CORE_DFS_RST_CTRL
value|0x0f
end_define

begin_define
define|#
directive|define
name|SYS_CORE_DFS_BYP_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|SYS_CORE_DFS_PHA_CTRL
value|0x11
end_define

begin_define
define|#
directive|define
name|SYS_CORE_DFS_DIV_INC_CTRL
value|0x12
end_define

begin_define
define|#
directive|define
name|SYS_CORE_DFS_DIV_DEC_CTRL
value|0x13
end_define

begin_define
define|#
directive|define
name|SYS_CORE_DFS_DIV_VALUE
value|0x14
end_define

begin_define
define|#
directive|define
name|SYS_RESET
value|0x15
end_define

begin_define
define|#
directive|define
name|SYS_DFS_DIS_CTRL
value|0x16
end_define

begin_define
define|#
directive|define
name|SYS_DFS_RST_CTRL
value|0x17
end_define

begin_define
define|#
directive|define
name|SYS_DFS_BYP_CTRL
value|0x18
end_define

begin_define
define|#
directive|define
name|SYS_DFS_DIV_INC_CTRL
value|0x19
end_define

begin_define
define|#
directive|define
name|SYS_DFS_DIV_DEC_CTRL
value|0x1a
end_define

begin_define
define|#
directive|define
name|SYS_DFS_DIV_VALUE0
value|0x1b
end_define

begin_define
define|#
directive|define
name|SYS_DFS_DIV_VALUE1
value|0x1c
end_define

begin_define
define|#
directive|define
name|SYS_SENSE_AMP_DLY
value|0x1d
end_define

begin_define
define|#
directive|define
name|SYS_SOC_SENSE_AMP_DLY
value|0x1e
end_define

begin_define
define|#
directive|define
name|SYS_CTRL0
value|0x1f
end_define

begin_define
define|#
directive|define
name|SYS_CTRL1
value|0x20
end_define

begin_define
define|#
directive|define
name|SYS_TIMEOUT_BS1
value|0x21
end_define

begin_define
define|#
directive|define
name|SYS_BYTE_SWAP
value|0x22
end_define

begin_define
define|#
directive|define
name|SYS_VRM_VID
value|0x23
end_define

begin_define
define|#
directive|define
name|SYS_PWR_RAM_CMD
value|0x24
end_define

begin_define
define|#
directive|define
name|SYS_PWR_RAM_ADDR
value|0x25
end_define

begin_define
define|#
directive|define
name|SYS_PWR_RAM_DATA0
value|0x26
end_define

begin_define
define|#
directive|define
name|SYS_PWR_RAM_DATA1
value|0x27
end_define

begin_define
define|#
directive|define
name|SYS_PWR_RAM_DATA2
value|0x28
end_define

begin_define
define|#
directive|define
name|SYS_PWR_UCODE
value|0x29
end_define

begin_define
define|#
directive|define
name|SYS_CPU0_PWR_STATUS
value|0x2a
end_define

begin_define
define|#
directive|define
name|SYS_CPU1_PWR_STATUS
value|0x2b
end_define

begin_define
define|#
directive|define
name|SYS_CPU2_PWR_STATUS
value|0x2c
end_define

begin_define
define|#
directive|define
name|SYS_CPU3_PWR_STATUS
value|0x2d
end_define

begin_define
define|#
directive|define
name|SYS_CPU4_PWR_STATUS
value|0x2e
end_define

begin_define
define|#
directive|define
name|SYS_CPU5_PWR_STATUS
value|0x2f
end_define

begin_define
define|#
directive|define
name|SYS_CPU6_PWR_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|SYS_CPU7_PWR_STATUS
value|0x31
end_define

begin_define
define|#
directive|define
name|SYS_STATUS
value|0x32
end_define

begin_define
define|#
directive|define
name|SYS_INT_POL
value|0x33
end_define

begin_define
define|#
directive|define
name|SYS_INT_TYPE
value|0x34
end_define

begin_define
define|#
directive|define
name|SYS_INT_STATUS
value|0x35
end_define

begin_define
define|#
directive|define
name|SYS_INT_MASK0
value|0x36
end_define

begin_define
define|#
directive|define
name|SYS_INT_MASK1
value|0x37
end_define

begin_define
define|#
directive|define
name|SYS_UCO_S_ECC
value|0x38
end_define

begin_define
define|#
directive|define
name|SYS_UCO_M_ECC
value|0x39
end_define

begin_define
define|#
directive|define
name|SYS_UCO_ADDR
value|0x3a
end_define

begin_define
define|#
directive|define
name|SYS_PLL_DFS_BYP_CTRL
value|0x3a
end_define

begin_comment
comment|/* Bx stepping */
end_comment

begin_define
define|#
directive|define
name|SYS_UCO_INSTR
value|0x3b
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST0
value|0x3c
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST1
value|0x3d
end_define

begin_define
define|#
directive|define
name|SYS_PLL_DFS_DIV_VALUE
value|0x3d
end_define

begin_comment
comment|/* Bx stepping */
end_comment

begin_define
define|#
directive|define
name|SYS_MEM_BIST2
value|0x3e
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST3
value|0x3f
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST4
value|0x40
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST5
value|0x41
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST6
value|0x42
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST7
value|0x43
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST8
value|0x44
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST9
value|0x45
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST10
value|0x46
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST11
value|0x47
end_define

begin_define
define|#
directive|define
name|SYS_MEM_BIST12
value|0x48
end_define

begin_define
define|#
directive|define
name|SYS_SCRTCH0
value|0x49
end_define

begin_define
define|#
directive|define
name|SYS_SCRTCH1
value|0x4a
end_define

begin_define
define|#
directive|define
name|SYS_SCRTCH2
value|0x4b
end_define

begin_define
define|#
directive|define
name|SYS_SCRTCH3
value|0x4c
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
name|nlm_read_sys_reg
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
name|nlm_write_sys_reg
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
name|nlm_get_sys_pcibase
parameter_list|(
name|node
parameter_list|)
value|nlm_pcicfg_base(XLP_IO_SYS_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_get_sys_regbase
parameter_list|(
name|node
parameter_list|)
value|(nlm_get_sys_pcibase(node) + XLP_IO_PCI_HDRSZ)
end_define

begin_enum
enum|enum
block|{
comment|/* Don't change order and it must start from zero */
name|DFS_DEVICE_NAE
init|=
literal|0
block|,
name|DFS_DEVICE_SAE
block|,
name|DFS_DEVICE_RSA
block|,
name|DFS_DEVICE_DTRE
block|,
name|DFS_DEVICE_CMP
block|,
name|DFS_DEVICE_KBP
block|,
name|DFS_DEVICE_DMC
block|,
name|DFS_DEVICE_NAND
block|,
name|DFS_DEVICE_MMC
block|,
name|DFS_DEVICE_NOR
block|,
name|DFS_DEVICE_CORE
block|,
name|DFS_DEVICE_REGEX_SLOW
block|,
name|DFS_DEVICE_REGEX_FAST
block|,
name|DFS_DEVICE_SATA
block|,
name|INVALID_DFS_DEVICE
init|=
literal|0xFF
block|}
enum|;
end_enum

begin_function
specifier|static
name|__inline
name|void
name|nlm_sys_enable_block
parameter_list|(
name|uint64_t
name|sys_base
parameter_list|,
name|int
name|block
parameter_list|)
block|{
name|uint32_t
name|dfsdis
decl_stmt|,
name|mask
decl_stmt|;
name|mask
operator|=
literal|1
operator|<<
name|block
expr_stmt|;
name|dfsdis
operator|=
name|nlm_read_sys_reg
argument_list|(
name|sys_base
argument_list|,
name|SYS_DFS_DIS_CTRL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|dfsdis
operator|&
name|mask
operator|)
operator|==
literal|0
condition|)
return|return;
comment|/* already enabled, nothing to do */
name|dfsdis
operator|&=
operator|~
name|mask
expr_stmt|;
name|nlm_write_sys_reg
argument_list|(
name|sys_base
argument_list|,
name|SYS_DFS_DIS_CTRL
argument_list|,
name|dfsdis
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

