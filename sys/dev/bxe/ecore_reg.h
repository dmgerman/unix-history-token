begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2014 QLogic Corporation. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ECORE_REG_H
end_ifndef

begin_define
define|#
directive|define
name|ECORE_REG_H
end_define

begin_define
define|#
directive|define
name|ATC_ATC_INT_STS_REG_ADDRESS_ERROR
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|ATC_ATC_INT_STS_REG_ATC_GPA_MULTIPLE_HITS
define|\
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|ATC_ATC_INT_STS_REG_ATC_IREQ_LESS_THAN_STU
define|\
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|ATC_ATC_INT_STS_REG_ATC_RCPL_TO_EMPTY_CNT
define|\
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|ATC_ATC_INT_STS_REG_ATC_TCPL_ERROR
define|\
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|ATC_ATC_INT_STS_REG_ATC_TCPL_TO_NOT_PEND
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|ATC_REG_ATC_INIT_DONE
define|\
value|0x1100bcUL
end_define

begin_define
define|#
directive|define
name|ATC_REG_ATC_INT_STS_CLR
define|\
value|0x1101c0UL
end_define

begin_define
define|#
directive|define
name|ATC_REG_ATC_PRTY_MASK
define|\
value|0x1101d8UL
end_define

begin_define
define|#
directive|define
name|ATC_REG_ATC_PRTY_STS_CLR
define|\
value|0x1101d0UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_BRB1_INT_MASK
define|\
value|0x60128UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_BRB1_PRTY_MASK
define|\
value|0x60138UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_BRB1_PRTY_STS_CLR
define|\
value|0x60130UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_MAC_GUARANTIED_0
define|\
value|0x601e8UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_MAC_GUARANTIED_1
define|\
value|0x60240UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_NUM_OF_FULL_BLOCKS
define|\
value|0x60090UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_PAUSE_HIGH_THRESHOLD_0
define|\
value|0x60078UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_PAUSE_LOW_THRESHOLD_0
define|\
value|0x60068UL
end_define

begin_define
define|#
directive|define
name|BRB1_REG_PORT_NUM_OCC_BLOCKS_0
define|\
value|0x60094UL
end_define

begin_define
define|#
directive|define
name|CCM_REG_CCM_INT_MASK
define|\
value|0xd01e4UL
end_define

begin_define
define|#
directive|define
name|CCM_REG_CCM_PRTY_MASK
define|\
value|0xd01f4UL
end_define

begin_define
define|#
directive|define
name|CCM_REG_CCM_PRTY_STS_CLR
define|\
value|0xd01ecUL
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_GLOBAL_PARAMS
define|\
value|0x101020UL
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_INT_MASK
define|\
value|0x10103cUL
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_PRTY_MASK
define|\
value|0x10104cUL
end_define

begin_define
define|#
directive|define
name|CDU_REG_CDU_PRTY_STS_CLR
define|\
value|0x101044UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_AC_INIT_DONE
define|\
value|0x104078UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_CAM_INIT_DONE
define|\
value|0x10407cUL
end_define

begin_define
define|#
directive|define
name|CFC_REG_CFC_INT_MASK
define|\
value|0x104108UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_CFC_INT_STS_CLR
define|\
value|0x104100UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_CFC_PRTY_MASK
define|\
value|0x104118UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_CFC_PRTY_STS_CLR
define|\
value|0x104110UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_DEBUG0
define|\
value|0x104050UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_INIT_REG
define|\
value|0x10404cUL
end_define

begin_define
define|#
directive|define
name|CFC_REG_LL_INIT_DONE
define|\
value|0x104074UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_NUM_LCIDS_INSIDE_PF
define|\
value|0x104120UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_STRONG_ENABLE_PF
define|\
value|0x104128UL
end_define

begin_define
define|#
directive|define
name|CFC_REG_WEAK_ENABLE_PF
define|\
value|0x104124UL
end_define

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_INT_MASK_0
define|\
value|0xc229cUL
end_define

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_INT_MASK_1
define|\
value|0xc22acUL
end_define

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_PRTY_MASK
define|\
value|0xc22bcUL
end_define

begin_define
define|#
directive|define
name|CSDM_REG_CSDM_PRTY_STS_CLR
define|\
value|0xc22b4UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_INT_MASK_0
define|\
value|0x200110UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_INT_MASK_1
define|\
value|0x200120UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_PRTY_MASK_0
define|\
value|0x200130UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_PRTY_MASK_1
define|\
value|0x200140UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_PRTY_STS_CLR_0
define|\
value|0x200128UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_CSEM_PRTY_STS_CLR_1
define|\
value|0x200138UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_FAST_MEMORY
define|\
value|0x220000UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_INT_TABLE
define|\
value|0x200400UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_PASSIVE_BUFFER
define|\
value|0x202000UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_PRAM
define|\
value|0x240000UL
end_define

begin_define
define|#
directive|define
name|CSEM_REG_VFPF_ERR_NUM
define|\
value|0x200380UL
end_define

begin_define
define|#
directive|define
name|DBG_REG_DBG_PRTY_MASK
define|\
value|0xc0a8UL
end_define

begin_define
define|#
directive|define
name|DBG_REG_DBG_PRTY_STS_CLR
define|\
value|0xc0a0UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_BACKWARD_COMP_EN
define|\
value|0x10207cUL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_CMD_MEM
define|\
value|0x102400UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_DMAE_INT_MASK
define|\
value|0x102054UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_DMAE_PRTY_MASK
define|\
value|0x102064UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_DMAE_PRTY_STS_CLR
define|\
value|0x10205cUL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C0
define|\
value|0x102080UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C1
define|\
value|0x102084UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C10
define|\
value|0x102088UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C11
define|\
value|0x10208cUL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C12
define|\
value|0x102090UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C13
define|\
value|0x102094UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C14
define|\
value|0x102098UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C15
define|\
value|0x10209cUL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C2
define|\
value|0x1020a0UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C3
define|\
value|0x1020a4UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C4
define|\
value|0x1020a8UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C5
define|\
value|0x1020acUL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C6
define|\
value|0x1020b0UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C7
define|\
value|0x1020b4UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C8
define|\
value|0x1020b8UL
end_define

begin_define
define|#
directive|define
name|DMAE_REG_GO_C9
define|\
value|0x1020bcUL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_INT_MASK
define|\
value|0x170180UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_INT_STS_CLR
define|\
value|0x170178UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_PRTY_MASK
define|\
value|0x170190UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_DORQ_PRTY_STS_CLR
define|\
value|0x170188UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_DPM_CID_OFST
define|\
value|0x170030UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_MAX_RVFID_SIZE
define|\
value|0x1701ecUL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_NORM_CID_OFST
define|\
value|0x17002cUL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_USAGE_CNT
define|\
value|0x1701d0UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_NORM_CID_BASE
define|\
value|0x1701a0UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_NORM_CID_OFST
define|\
value|0x1701f4UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_NORM_CID_WND_SIZE
define|\
value|0x1701a4UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_NORM_MAX_CID_COUNT
define|\
value|0x1701e4UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_NORM_VF_BASE
define|\
value|0x1701a8UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_TYPE_MASK_0
define|\
value|0x170218UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_TYPE_MAX_MCID_0
define|\
value|0x1702d8UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_TYPE_MIN_MCID_0
define|\
value|0x170298UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_TYPE_VALUE_0
define|\
value|0x170258UL
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_USAGE_CT_LIMIT
define|\
value|0x170340UL
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_ATTN_BIT_EN_0
define|\
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_BLOCK_DISABLE_0
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_INT_LINE_EN_0
define|\
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_MSI_ATTN_EN_0
define|\
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_MSI_MSIX_INT_EN_0
define|\
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_0_REG_SINGLE_ISR_EN_0
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|HC_CONFIG_1_REG_BLOCK_DISABLE_1
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|HC_REG_ATTN_MSG0_ADDR_L
define|\
value|0x108018UL
end_define

begin_define
define|#
directive|define
name|HC_REG_ATTN_MSG1_ADDR_L
define|\
value|0x108020UL
end_define

begin_define
define|#
directive|define
name|HC_REG_COMMAND_REG
define|\
value|0x108180UL
end_define

begin_define
define|#
directive|define
name|HC_REG_CONFIG_0
define|\
value|0x108000UL
end_define

begin_define
define|#
directive|define
name|HC_REG_CONFIG_1
define|\
value|0x108004UL
end_define

begin_define
define|#
directive|define
name|HC_REG_HC_PRTY_MASK
define|\
value|0x1080a0UL
end_define

begin_define
define|#
directive|define
name|HC_REG_HC_PRTY_STS_CLR
define|\
value|0x108098UL
end_define

begin_define
define|#
directive|define
name|HC_REG_INT_MASK
define|\
value|0x108108UL
end_define

begin_define
define|#
directive|define
name|HC_REG_LEADING_EDGE_0
define|\
value|0x108040UL
end_define

begin_define
define|#
directive|define
name|HC_REG_MAIN_MEMORY
define|\
value|0x108800UL
end_define

begin_define
define|#
directive|define
name|HC_REG_MAIN_MEMORY_SIZE
define|\
value|152
end_define

begin_define
define|#
directive|define
name|HC_REG_TRAILING_EDGE_0
define|\
value|0x108044UL
end_define

begin_define
define|#
directive|define
name|IGU_BLOCK_CONFIGURATION_REG_BACKWARD_COMP_EN
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|IGU_BLOCK_CONFIGURATION_REG_BLOCK_ENABLE
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|IGU_REG_ATTENTION_ACK_BITS
define|\
value|0x130108UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_ATTN_MSG_ADDR_H
define|\
value|0x13011cUL
end_define

begin_define
define|#
directive|define
name|IGU_REG_ATTN_MSG_ADDR_L
define|\
value|0x130120UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_BLOCK_CONFIGURATION
define|\
value|0x130000UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_COMMAND_REG_32LSB_DATA
define|\
value|0x130124UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_COMMAND_REG_CTRL
define|\
value|0x13012cUL
end_define

begin_define
define|#
directive|define
name|IGU_REG_CSTORM_TYPE_0_SB_CLEANUP
define|\
value|0x130200UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_IGU_PRTY_MASK
define|\
value|0x1300a8UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_IGU_PRTY_STS_CLR
define|\
value|0x1300a0UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_LEADING_EDGE_LATCH
define|\
value|0x130134UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_MAPPING_MEMORY
define|\
value|0x131000UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_MAPPING_MEMORY_SIZE
define|\
value|136
end_define

begin_define
define|#
directive|define
name|IGU_REG_PBA_STATUS_LSB
define|\
value|0x130138UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_PBA_STATUS_MSB
define|\
value|0x13013cUL
end_define

begin_define
define|#
directive|define
name|IGU_REG_PCI_PF_MSIX_EN
define|\
value|0x130144UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_PCI_PF_MSIX_FUNC_MASK
define|\
value|0x130148UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_PCI_PF_MSI_EN
define|\
value|0x130140UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_PENDING_BITS_STATUS
define|\
value|0x130300UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_PF_CONFIGURATION
define|\
value|0x130154UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_PROD_CONS_MEMORY
define|\
value|0x132000UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_RESET_MEMORIES
define|\
value|0x130158UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_SB_INT_BEFORE_MASK_LSB
define|\
value|0x13015cUL
end_define

begin_define
define|#
directive|define
name|IGU_REG_SB_INT_BEFORE_MASK_MSB
define|\
value|0x130160UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_SB_MASK_LSB
define|\
value|0x130164UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_SB_MASK_MSB
define|\
value|0x130168UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_STATISTIC_NUM_MESSAGE_SENT
define|\
value|0x130800UL
end_define

begin_define
define|#
directive|define
name|IGU_REG_TRAILING_EDGE_LATCH
define|\
value|0x130104UL
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_ACCESS_LOCK
define|\
value|0x8009c
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_GP_INPUTS
define|\
value|0x800c0
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_GP_OENABLE
define|\
value|0x800c8
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_GP_OUTPUTS
define|\
value|0x800c4
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_IMC_COMMAND
define|\
value|0x85900
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_IMC_DATAREG0
define|\
value|0x85920
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_IMC_SLAVE_CONTROL
define|\
value|0x85904
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_ACCESS_ENABLE
define|\
value|0x86424
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_ADDR
define|\
value|0x8640c
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_CFG4
define|\
value|0x8642c
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_COMMAND
define|\
value|0x86400
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_READ
define|\
value|0x86410
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_SW_ARB
define|\
value|0x86420
end_define

begin_define
define|#
directive|define
name|MCP_REG_MCPR_NVM_WRITE
define|\
value|0x86408
end_define

begin_define
define|#
directive|define
name|MISC_AEU_GENERAL_MASK_REG_AEU_NIG_CLOSE_MASK
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|MISC_AEU_GENERAL_MASK_REG_AEU_PXP_CLOSE_MASK
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_1_FUNC_0
define|\
value|0xa42cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_2_FUNC_0
define|\
value|0xa438UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_3_FUNC_0
define|\
value|0xa444UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_4_FUNC_0
define|\
value|0xa450UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_4_MCP
define|\
value|0xa458UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_AFTER_INVERT_5_FUNC_0
define|\
value|0xa700UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_CLR_LATCH_SIGNAL
define|\
value|0xa45cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_0
define|\
value|0xa06cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_1
define|\
value|0xa07cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_0_OUT_2
define|\
value|0xa08cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_0
define|\
value|0xa10cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_1
define|\
value|0xa11cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE1_FUNC_1_OUT_2
define|\
value|0xa12cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_0_OUT_0
define|\
value|0xa078UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_FUNC_1_OUT_0
define|\
value|0xa118UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_NIG_0
define|\
value|0xa0f8UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_NIG_1
define|\
value|0xa198UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_PXP_0
define|\
value|0xa108UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE4_PXP_1
define|\
value|0xa1a8UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE5_FUNC_0_OUT_0
define|\
value|0xa688UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_ENABLE5_FUNC_1_OUT_0
define|\
value|0xa6b0UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_1
define|\
value|0xa004UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_10
define|\
value|0xa028UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_11
define|\
value|0xa02cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_12
define|\
value|0xa030UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_2
define|\
value|0xa008UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_3
define|\
value|0xa00cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_4
define|\
value|0xa010UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_5
define|\
value|0xa014UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_6
define|\
value|0xa018UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_7
define|\
value|0xa01cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_8
define|\
value|0xa020UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_ATTN_9
define|\
value|0xa024UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_GENERAL_MASK
define|\
value|0xa61cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_MASK_ATTN_FUNC_0
define|\
value|0xa060UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_AEU_MASK_ATTN_FUNC_1
define|\
value|0xa064UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_BOND_ID
define|\
value|0xa400UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CHIP_NUM
define|\
value|0xa408UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CHIP_REV
define|\
value|0xa40cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CHIP_TYPE
define|\
value|0xac60UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CHIP_TYPE_57811_MASK
define|\
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MISC_REG_CPMU_LP_DR_ENABLE
define|\
value|0xa858UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CPMU_LP_FW_ENABLE_P0
define|\
value|0xa84cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CPMU_LP_IDLE_THR_P0
define|\
value|0xa8a0UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CPMU_LP_MASK_ENT_P0
define|\
value|0xa880UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CPMU_LP_MASK_EXT_P0
define|\
value|0xa888UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CPMU_LP_SM_ENT_CNT_P0
define|\
value|0xa8b8UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_CPMU_LP_SM_ENT_CNT_P1
define|\
value|0xa8bcUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_DRIVER_CONTROL_1
define|\
value|0xa510UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_DRIVER_CONTROL_7
define|\
value|0xa3c8UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_FOUR_PORT_PATH_SWAP
define|\
value|0xa75cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_FOUR_PORT_PATH_SWAP_OVWR
define|\
value|0xa738UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_FOUR_PORT_PORT_SWAP
define|\
value|0xa754UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_FOUR_PORT_PORT_SWAP_OVWR
define|\
value|0xa734UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GENERIC_CR_0
define|\
value|0xa460UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GENERIC_CR_1
define|\
value|0xa464UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GENERIC_POR_1
define|\
value|0xa474UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GEN_PURP_HWG
define|\
value|0xa9a0UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GPIO
define|\
value|0xa490UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GPIO_EVENT_EN
define|\
value|0xa2bcUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GPIO_INT
define|\
value|0xa494UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GRC_RSV_ATTN
define|\
value|0xa3c0UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_GRC_TIMEOUT_ATTN
define|\
value|0xa3c4UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_LCPLL_E40_PWRDWN
define|\
value|0xaa74UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_LCPLL_E40_RESETB_ANA
define|\
value|0xaa78UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_LCPLL_E40_RESETB_DIG
define|\
value|0xaa7cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_MISC_INT_MASK
define|\
value|0xa388UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_MISC_PRTY_MASK
define|\
value|0xa398UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_MISC_PRTY_STS_CLR
define|\
value|0xa390UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_PORT4MODE_EN
define|\
value|0xa750UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_PORT4MODE_EN_OVWR
define|\
value|0xa720UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_RESET_REG_1
define|\
value|0xa580UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_RESET_REG_2
define|\
value|0xa590UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_SHARED_MEM_ADDR
define|\
value|0xa2b4UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_SPIO
define|\
value|0xa4fcUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_SPIO_EVENT_EN
define|\
value|0xa2b8UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_SPIO_INT
define|\
value|0xa500UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_TWO_PORT_PATH_SWAP
define|\
value|0xa758UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_TWO_PORT_PATH_SWAP_OVWR
define|\
value|0xa72cUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_UNPREPARED
define|\
value|0xa424UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_WC0_CTRL_PHY_ADDR
define|\
value|0xa9ccUL
end_define

begin_define
define|#
directive|define
name|MISC_REG_WC0_RESET
define|\
value|0xac30UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_XMAC_CORE_PORT_MODE
define|\
value|0xa964UL
end_define

begin_define
define|#
directive|define
name|MISC_REG_XMAC_PHY_PORT_MODE
define|\
value|0xa960UL
end_define

begin_define
define|#
directive|define
name|MSTAT_REG_RX_STAT_GR64_LO
define|\
value|0x200UL
end_define

begin_define
define|#
directive|define
name|MSTAT_REG_TX_STAT_GTXPOK_LO
define|\
value|0UL
end_define

begin_define
define|#
directive|define
name|NIG_LLH0_XCM_MASK_REG_LLH0_XCM_MASK_BCN
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|NIG_LLH1_XCM_MASK_REG_LLH1_XCM_MASK_BCN
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|NIG_MASK_INTERRUPT_PORT0_REG_MASK_EMAC0_MISC_MI_INT
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|NIG_MASK_INTERRUPT_PORT0_REG_MASK_SERDES0_LINK_STATUS
define|\
value|(0x1<<9)
end_define

begin_define
define|#
directive|define
name|NIG_MASK_INTERRUPT_PORT0_REG_MASK_XGXS0_LINK10G
define|\
value|(0x1<<15)
end_define

begin_define
define|#
directive|define
name|NIG_MASK_INTERRUPT_PORT0_REG_MASK_XGXS0_LINK_STATUS
define|\
value|(0xf<<18)
end_define

begin_define
define|#
directive|define
name|NIG_REG_BMAC0_IN_EN
define|\
value|0x100acUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_BMAC0_OUT_EN
define|\
value|0x100e0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_BMAC0_PAUSE_OUT_EN
define|\
value|0x10110UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_BMAC0_REGS_OUT_EN
define|\
value|0x100e8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_BRB0_PAUSE_IN_EN
define|\
value|0x100c4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_BRB1_PAUSE_IN_EN
define|\
value|0x100c8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_DEBUG_PACKET_LB
define|\
value|0x10800UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_DRAIN0_MODE
define|\
value|0x10060UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_EMAC0_OUT_EN
define|\
value|0x10120UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_EGRESS_EMAC0_PORT
define|\
value|0x10058UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_EMAC0_IN_EN
define|\
value|0x100a4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_EMAC0_PAUSE_OUT_EN
define|\
value|0x10118UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_EMAC0_STATUS_MISC_MI_INT
define|\
value|0x10494UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_INGRESS_BMAC0_MEM
define|\
value|0x10c00UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_INGRESS_BMAC1_MEM
define|\
value|0x11000UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_INGRESS_EOP_LB_EMPTY
define|\
value|0x104e0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_INGRESS_EOP_LB_FIFO
define|\
value|0x104e4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LATCH_BC_0
define|\
value|0x16210UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LATCH_STATUS_0
define|\
value|0x18000UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LED_10G_P0
define|\
value|0x10320UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_BLINK_RATE_ENA_P0
define|\
value|0x10318UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_BLINK_RATE_P0
define|\
value|0x10310UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_BLINK_TRAFFIC_P0
define|\
value|0x10308UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_OVERRIDE_TRAFFIC_P0
define|\
value|0x102f8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LED_CONTROL_TRAFFIC_P0
define|\
value|0x10300UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LED_MODE_P0
define|\
value|0x102f0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_EGRESS_SRC_ENABLE_0
define|\
value|0x16070UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_EGRESS_SRC_ENABLE_1
define|\
value|0x16074UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_ENABLE_0
define|\
value|0x16208UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_ENABLE_1
define|\
value|0x1620cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_HIGH_PRIORITY_CLASSES_0
define|\
value|0x16058UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_HIGH_PRIORITY_CLASSES_1
define|\
value|0x1605cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_LOW_PRIORITY_CLASSES_0
define|\
value|0x16060UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_LOW_PRIORITY_CLASSES_1
define|\
value|0x16064UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_OUT_EN_0
define|\
value|0x160c8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLFC_OUT_EN_1
define|\
value|0x160ccUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_BRB1_DRV_MASK
define|\
value|0x10244UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_BRB1_DRV_MASK_MF
define|\
value|0x16048UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_BRB1_NOT_MCP
define|\
value|0x1025cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_CLS_TYPE
define|\
value|0x16080UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_FUNC_EN
define|\
value|0x160fcUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_FUNC_MEM
define|\
value|0x16180UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_FUNC_MEM_ENABLE
define|\
value|0x16140UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_FUNC_VLAN_ID
define|\
value|0x16100UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH0_XCM_MASK
define|\
value|0x10130UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_BRB1_NOT_MCP
define|\
value|0x102dcUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_CLS_TYPE
define|\
value|0x16084UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_FUNC_MEM
define|\
value|0x161c0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_FUNC_MEM_ENABLE
define|\
value|0x16160UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_FUNC_MEM_SIZE
define|\
value|16
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_MF_MODE
define|\
value|0x18614UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH1_XCM_MASK
define|\
value|0x10134UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_E1HOV_MODE
define|\
value|0x160d8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_MF_MODE
define|\
value|0x16024UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_MASK_INTERRUPT_PORT0
define|\
value|0x10330UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_MASK_INTERRUPT_PORT1
define|\
value|0x10334UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_EMAC0_EN
define|\
value|0x1003cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_INGRESS_EMAC0_NO_CRC
define|\
value|0x10044UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_INT_STS_CLR_0
define|\
value|0x103b4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_PRTY_MASK
define|\
value|0x103dcUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_PRTY_MASK_0
define|\
value|0x183c8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_PRTY_MASK_1
define|\
value|0x183d8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_PRTY_STS_CLR
define|\
value|0x103d4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_PRTY_STS_CLR_0
define|\
value|0x183c0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_NIG_PRTY_STS_CLR_1
define|\
value|0x183d0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_HDRS_AFTER_BASIC
define|\
value|0x18038UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_HWPFC_ENABLE
define|\
value|0x18078UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_LLH_FUNC_MEM2
define|\
value|0x18480UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_MAC_IN_EN
define|\
value|0x185acUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_MAC_OUT_EN
define|\
value|0x185b0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_MAC_PAUSE_OUT_EN
define|\
value|0x185b4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_PKT_PRIORITY_TO_COS
define|\
value|0x18054UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_RX_COS0_PRIORITY_MASK
define|\
value|0x18058UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_RX_COS1_PRIORITY_MASK
define|\
value|0x1805cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_RX_COS2_PRIORITY_MASK
define|\
value|0x186b0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_RX_COS3_PRIORITY_MASK
define|\
value|0x186b4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_RX_COS4_PRIORITY_MASK
define|\
value|0x186b8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_RX_COS5_PRIORITY_MASK
define|\
value|0x186bcUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CLIENT_CREDIT_MAP
define|\
value|0x180f0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CLIENT_CREDIT_MAP2_LSB
define|\
value|0x18688UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CLIENT_CREDIT_MAP2_MSB
define|\
value|0x1868cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CLIENT_IS_STRICT
define|\
value|0x180e8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CLIENT_IS_SUBJECT2WFQ
define|\
value|0x180ecUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_0
define|\
value|0x1810cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_1
define|\
value|0x18110UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_2
define|\
value|0x18114UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_3
define|\
value|0x18118UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_4
define|\
value|0x1811cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_5
define|\
value|0x186a0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_6
define|\
value|0x186a4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_7
define|\
value|0x186a8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_UPPER_BOUND_8
define|\
value|0x186acUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_0
define|\
value|0x180f8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_1
define|\
value|0x180fcUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_2
define|\
value|0x18100UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_3
define|\
value|0x18104UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_4
define|\
value|0x18108UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_5
define|\
value|0x18690UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_6
define|\
value|0x18694UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_7
define|\
value|0x18698UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_CREDIT_WEIGHT_8
define|\
value|0x1869cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_NUM_STRICT_ARB_SLOTS
define|\
value|0x180f4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_PRIORITY_CLIENT
define|\
value|0x180e4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_PRIORITY_CLIENT2_LSB
define|\
value|0x18680UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P0_TX_ARB_PRIORITY_CLIENT2_MSB
define|\
value|0x18684UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_HDRS_AFTER_BASIC
define|\
value|0x1818cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_HWPFC_ENABLE
define|\
value|0x181d0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_LLH_FUNC_MEM2
define|\
value|0x184c0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_MAC_IN_EN
define|\
value|0x185c0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_MAC_OUT_EN
define|\
value|0x185c4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_MAC_PAUSE_OUT_EN
define|\
value|0x185c8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_PKT_PRIORITY_TO_COS
define|\
value|0x181a8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_RX_COS0_PRIORITY_MASK
define|\
value|0x181acUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_RX_COS1_PRIORITY_MASK
define|\
value|0x181b0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_RX_COS2_PRIORITY_MASK
define|\
value|0x186f8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CLIENT_CREDIT_MAP2_LSB
define|\
value|0x186e8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CLIENT_CREDIT_MAP2_MSB
define|\
value|0x186ecUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CLIENT_IS_STRICT
define|\
value|0x18234UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CLIENT_IS_SUBJECT2WFQ
define|\
value|0x18238UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_UPPER_BOUND_0
define|\
value|0x18258UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_UPPER_BOUND_1
define|\
value|0x1825cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_UPPER_BOUND_2
define|\
value|0x18260UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_UPPER_BOUND_3
define|\
value|0x18264UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_UPPER_BOUND_4
define|\
value|0x18268UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_UPPER_BOUND_5
define|\
value|0x186f4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_WEIGHT_0
define|\
value|0x18244UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_WEIGHT_1
define|\
value|0x18248UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_WEIGHT_2
define|\
value|0x1824cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_WEIGHT_3
define|\
value|0x18250UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_WEIGHT_4
define|\
value|0x18254UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_CREDIT_WEIGHT_5
define|\
value|0x186f0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_NUM_STRICT_ARB_SLOTS
define|\
value|0x18240UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_PRIORITY_CLIENT2_LSB
define|\
value|0x186e0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_P1_TX_ARB_PRIORITY_CLIENT2_MSB
define|\
value|0x186e4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_PAUSE_ENABLE_0
define|\
value|0x160c0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_PAUSE_ENABLE_1
define|\
value|0x160c4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_PORT_SWAP
define|\
value|0x10394UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_PPP_ENABLE_0
define|\
value|0x160b0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_PPP_ENABLE_1
define|\
value|0x160b4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_PRS_REQ_IN_EN
define|\
value|0x100b8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_SERDES0_CTRL_MD_DEVAD
define|\
value|0x10370UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_SERDES0_CTRL_MD_ST
define|\
value|0x1036cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_SERDES0_CTRL_PHY_ADDR
define|\
value|0x10374UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_SERDES0_STATUS_LINK_STATUS
define|\
value|0x10578UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STAT0_BRB_DISCARD
define|\
value|0x105f0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STAT0_BRB_TRUNCATE
define|\
value|0x105f8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STAT0_EGRESS_MAC_PKT0
define|\
value|0x10750UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STAT0_EGRESS_MAC_PKT1
define|\
value|0x10760UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STAT1_BRB_DISCARD
define|\
value|0x10628UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STAT1_EGRESS_MAC_PKT0
define|\
value|0x107a0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STAT1_EGRESS_MAC_PKT1
define|\
value|0x107b0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STAT2_BRB_OCTET
define|\
value|0x107e0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STATUS_INTERRUPT_PORT0
define|\
value|0x10328UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_STRAP_OVERRIDE
define|\
value|0x10398UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XCM0_OUT_EN
define|\
value|0x100f0UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XCM1_OUT_EN
define|\
value|0x100f4UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_CTRL_MD_DEVAD
define|\
value|0x1033cUL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_CTRL_MD_ST
define|\
value|0x10338UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_CTRL_PHY_ADDR
define|\
value|0x10340UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_STATUS_LINK10G
define|\
value|0x10680UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XGXS0_STATUS_LINK_STATUS
define|\
value|0x10684UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XGXS_LANE_SEL_P0
define|\
value|0x102e8UL
end_define

begin_define
define|#
directive|define
name|NIG_REG_XGXS_SERDES0_MODE_SEL
define|\
value|0x102e0UL
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_EMAC0_MISC_MI_INT
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_SERDES0_LINK_STATUS
define|\
value|(0x1<<9)
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK10G
define|\
value|(0x1<<15)
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK_STATUS
define|\
value|(0xf<<18)
end_define

begin_define
define|#
directive|define
name|NIG_STATUS_INTERRUPT_PORT0_REG_STATUS_XGXS0_LINK_STATUS_SIZE
define|\
value|18
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS0_UPPER_BOUND
define|\
value|0x15c05cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS0_UPPER_BOUND_P0
define|\
value|0x15c2ccUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS0_UPPER_BOUND_P1
define|\
value|0x15c2e4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS0_WEIGHT
define|\
value|0x15c054UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS0_WEIGHT_P0
define|\
value|0x15c2a8UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS0_WEIGHT_P1
define|\
value|0x15c2c0UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS1_UPPER_BOUND
define|\
value|0x15c060UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS1_WEIGHT
define|\
value|0x15c058UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS1_WEIGHT_P0
define|\
value|0x15c2acUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS1_WEIGHT_P1
define|\
value|0x15c2c4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS2_WEIGHT_P0
define|\
value|0x15c2b0UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS2_WEIGHT_P1
define|\
value|0x15c2c8UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS3_WEIGHT_P0
define|\
value|0x15c2b4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS4_WEIGHT_P0
define|\
value|0x15c2b8UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_COS5_WEIGHT_P0
define|\
value|0x15c2bcUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_CREDIT_LB_Q
define|\
value|0x140338UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_CREDIT_Q0
define|\
value|0x14033cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_CREDIT_Q1
define|\
value|0x140340UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_DISABLE_NEW_TASK_PROC_P0
define|\
value|0x14005cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_DISABLE_PF
define|\
value|0x1402e8UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_CLIENT_CREDIT_MAP_P0
define|\
value|0x15c288UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_CLIENT_CREDIT_MAP_P1
define|\
value|0x15c28cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_CLIENT_IS_STRICT_P0
define|\
value|0x15c278UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_CLIENT_IS_STRICT_P1
define|\
value|0x15c27cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_CLIENT_IS_SUBJECT2WFQ_P0
define|\
value|0x15c280UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_CLIENT_IS_SUBJECT2WFQ_P1
define|\
value|0x15c284UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_NUM_STRICT_ARB_SLOTS_P0
define|\
value|0x15c2a0UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_NUM_STRICT_ARB_SLOTS_P1
define|\
value|0x15c2a4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_PRIORITY_CLIENT_P0
define|\
value|0x15c270UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ARB_PRIORITY_CLIENT_P1
define|\
value|0x15c274UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_ETS_ENABLED
define|\
value|0x15c050UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_HDRS_AFTER_BASIC
define|\
value|0x15c0a8UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_HDRS_AFTER_TAG_0
define|\
value|0x15c0b8UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_HIGH_PRIORITY_COS_NUM
define|\
value|0x15c04cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_INIT_CRD_LB_Q
define|\
value|0x15c248UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_INIT_CRD_Q0
define|\
value|0x15c230UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_INIT_CRD_Q1
define|\
value|0x15c234UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_INIT_P0
define|\
value|0x140004UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_INTERNAL_CRD_FREED_CNT_LB_Q
define|\
value|0x140354UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_INTERNAL_CRD_FREED_CNT_Q0
define|\
value|0x140358UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_INTERNAL_CRD_FREED_CNT_Q1
define|\
value|0x14035cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_MUST_HAVE_HDRS
define|\
value|0x15c0c4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_NUM_STRICT_ARB_SLOTS
define|\
value|0x15c064UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P0_ARB_THRSH
define|\
value|0x1400e4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P0_CREDIT
define|\
value|0x140200UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P0_INIT_CRD
define|\
value|0x1400d0UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P0_INTERNAL_CRD_FREED_CNT
define|\
value|0x140308UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P0_PAUSE_ENABLE
define|\
value|0x140014UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P0_TQ_LINES_FREED_CNT
define|\
value|0x1402f0UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P0_TQ_OCCUPANCY
define|\
value|0x1402fcUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P1_CREDIT
define|\
value|0x140208UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P1_INIT_CRD
define|\
value|0x1400d4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P1_INTERNAL_CRD_FREED_CNT
define|\
value|0x14030cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P1_TQ_LINES_FREED_CNT
define|\
value|0x1402f4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P1_TQ_OCCUPANCY
define|\
value|0x140300UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P4_CREDIT
define|\
value|0x140210UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P4_INIT_CRD
define|\
value|0x1400e0UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P4_INTERNAL_CRD_FREED_CNT
define|\
value|0x140310UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P4_TQ_LINES_FREED_CNT
define|\
value|0x1402f8UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_P4_TQ_OCCUPANCY
define|\
value|0x140304UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_PBF_INT_MASK
define|\
value|0x1401d4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_PBF_PRTY_MASK
define|\
value|0x1401e4UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_PBF_PRTY_STS_CLR
define|\
value|0x1401dcUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_TAG_ETHERTYPE_0
define|\
value|0x15c090UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_TAG_LEN_0
define|\
value|0x15c09cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_TQ_LINES_FREED_CNT_LB_Q
define|\
value|0x14038cUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_TQ_LINES_FREED_CNT_Q0
define|\
value|0x140390UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_TQ_LINES_FREED_CNT_Q1
define|\
value|0x140394UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_TQ_OCCUPANCY_LB_Q
define|\
value|0x1403a8UL
end_define

begin_define
define|#
directive|define
name|PBF_REG_TQ_OCCUPANCY_Q0
define|\
value|0x1403acUL
end_define

begin_define
define|#
directive|define
name|PBF_REG_TQ_OCCUPANCY_Q1
define|\
value|0x1403b0UL
end_define

begin_define
define|#
directive|define
name|PB_REG_PB_INT_MASK
define|\
value|0x28UL
end_define

begin_define
define|#
directive|define
name|PB_REG_PB_PRTY_MASK
define|\
value|0x38UL
end_define

begin_define
define|#
directive|define
name|PB_REG_PB_PRTY_STS_CLR
define|\
value|0x30UL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_ADDRESS_ERROR
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_CSSNOOP_FIFO_OVERFLOW
define|\
value|(0x1<<8)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_INCORRECT_RCV_BEHAVIOR
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_TCPL_ERROR_ATTN
define|\
value|(0x1<<6)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_TCPL_IN_TWO_RCBS_ATTN
define|\
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_VF_GRC_SPACE_VIOLATION_ATTN
define|\
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_VF_LENGTH_VIOLATION_ATTN
define|\
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_VF_MSIX_BAR_VIOLATION_ATTN
define|\
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_PGLUE_B_INT_STS_REG_WAS_ERROR_ATTN
define|\
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_FLR_REQUEST_PF_7_0_CLR
define|\
value|0x9418UL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_INTERNAL_PFID_ENABLE_MASTER
define|\
value|0x942cUL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_INTERNAL_PFID_ENABLE_TARGET_READ
define|\
value|0x9430UL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_LATCHED_ERRORS_CLR
define|\
value|0x943CUL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_PGLUE_B_INT_STS
define|\
value|0x9298UL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_PGLUE_B_INT_STS_CLR
define|\
value|0x929cUL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_PGLUE_B_PRTY_MASK
define|\
value|0x92b4UL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_PGLUE_B_PRTY_STS_CLR
define|\
value|0x92acUL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_SHADOW_BME_PF_7_0_CLR
define|\
value|0x9458UL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_TAGS_63_32
define|\
value|0x9244UL
end_define

begin_define
define|#
directive|define
name|PGLUE_B_REG_WAS_ERROR_PF_7_0_CLR
define|\
value|0x9470UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_A_PRSU_20
define|\
value|0x40134UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_CFC_SEARCH_INITIAL_CREDIT
define|\
value|0x4011cUL
end_define

begin_define
define|#
directive|define
name|PRS_REG_E1HOV_MODE
define|\
value|0x401c8UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_HDRS_AFTER_BASIC
define|\
value|0x40238UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_HDRS_AFTER_BASIC_PORT_0
define|\
value|0x40270UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_HDRS_AFTER_BASIC_PORT_1
define|\
value|0x40290UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_HDRS_AFTER_TAG_0
define|\
value|0x40248UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_HDRS_AFTER_TAG_0_PORT_0
define|\
value|0x40280UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_HDRS_AFTER_TAG_0_PORT_1
define|\
value|0x402a0UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_MUST_HAVE_HDRS
define|\
value|0x40254UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_MUST_HAVE_HDRS_PORT_0
define|\
value|0x4028cUL
end_define

begin_define
define|#
directive|define
name|PRS_REG_MUST_HAVE_HDRS_PORT_1
define|\
value|0x402acUL
end_define

begin_define
define|#
directive|define
name|PRS_REG_NIC_MODE
define|\
value|0x40138UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_NUM_OF_PACKETS
define|\
value|0x40124UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_PRS_PRTY_MASK
define|\
value|0x401a4UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_PRS_PRTY_STS_CLR
define|\
value|0x4019cUL
end_define

begin_define
define|#
directive|define
name|PRS_REG_TAG_ETHERTYPE_0
define|\
value|0x401d4UL
end_define

begin_define
define|#
directive|define
name|PRS_REG_TAG_LEN_0
define|\
value|0x4022cUL
end_define

begin_define
define|#
directive|define
name|PXP2_PXP2_INT_MASK_0_REG_PGL_CPL_AFT
define|\
value|(0x1<<19)
end_define

begin_define
define|#
directive|define
name|PXP2_PXP2_INT_MASK_0_REG_PGL_CPL_OF
define|\
value|(0x1<<20)
end_define

begin_define
define|#
directive|define
name|PXP2_PXP2_INT_MASK_0_REG_PGL_PCIE_ATTN
define|\
value|(0x1<<22)
end_define

begin_define
define|#
directive|define
name|PXP2_PXP2_INT_MASK_0_REG_PGL_READ_BLOCKED
define|\
value|(0x1<<23)
end_define

begin_define
define|#
directive|define
name|PXP2_PXP2_INT_MASK_0_REG_PGL_WRITE_BLOCKED
define|\
value|(0x1<<24)
end_define

begin_define
define|#
directive|define
name|PXP2_PXP2_INT_STS_0_REG_WR_PGLUE_EOP_ERROR
define|\
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|PXP2_PXP2_INT_STS_CLR_0_REG_WR_PGLUE_EOP_ERROR
define|\
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_88_F0
define|\
value|0x120534UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_88_F1
define|\
value|0x120544UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_8C_F0
define|\
value|0x120538UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_8C_F1
define|\
value|0x120548UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_90_F0
define|\
value|0x12053cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_90_F1
define|\
value|0x12054cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_94_F0
define|\
value|0x120540UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_ADDR_94_F1
define|\
value|0x120550UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_EXP_ROM2
define|\
value|0x120808UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F0
define|\
value|0x120674UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_PRETEND_FUNC_F1
define|\
value|0x120678UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PGL_TAGS_LIMIT
define|\
value|0x1205a8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD1
define|\
value|0x1201c0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD10
define|\
value|0x1201e4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD11
define|\
value|0x1201e8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD2
define|\
value|0x1201c4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD28
define|\
value|0x120228UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD3
define|\
value|0x1201c8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD6
define|\
value|0x1201d4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD7
define|\
value|0x1201d8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD8
define|\
value|0x1201dcUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_ADD9
define|\
value|0x1201e0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L1
define|\
value|0x1202b0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L10
define|\
value|0x1202d4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L11
define|\
value|0x1202d8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L2
define|\
value|0x1202b4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L28
define|\
value|0x120318UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L3
define|\
value|0x1202b8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L6
define|\
value|0x1202c4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L7
define|\
value|0x1202c8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L8
define|\
value|0x1202ccUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_L9
define|\
value|0x1202d0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_RD
define|\
value|0x120324UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB1
define|\
value|0x120238UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB10
define|\
value|0x12025cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB11
define|\
value|0x120260UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB2
define|\
value|0x12023cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB28
define|\
value|0x1202a0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB3
define|\
value|0x120240UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB6
define|\
value|0x12024cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB7
define|\
value|0x120250UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB8
define|\
value|0x120254UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_UB9
define|\
value|0x120258UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_BW_WR
define|\
value|0x120328UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_CDU0_L2P
define|\
value|0x120000UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_QM0_L2P
define|\
value|0x120038UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_SRC0_L2P
define|\
value|0x120054UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PSWRQ_TM0_L2P
define|\
value|0x12001cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_MASK_0
define|\
value|0x120578UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_MASK_1
define|\
value|0x120614UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_STS_0
define|\
value|0x12056cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_STS_1
define|\
value|0x120608UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_INT_STS_CLR_0
define|\
value|0x120570UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_PRTY_MASK_0
define|\
value|0x120588UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_PRTY_MASK_1
define|\
value|0x120598UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_PRTY_STS_CLR_0
define|\
value|0x120580UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_PXP2_PRTY_STS_CLR_1
define|\
value|0x120590UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_BLK_CNT
define|\
value|0x120418UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_CDURD_SWAP_MODE
define|\
value|0x120404UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_DISABLE_INPUTS
define|\
value|0x120374UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_INIT_DONE
define|\
value|0x120370UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_PBF_SWAP_MODE
define|\
value|0x1203f4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_PORT_IS_IDLE_0
define|\
value|0x12041cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_PORT_IS_IDLE_1
define|\
value|0x120420UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_QM_SWAP_MODE
define|\
value|0x1203f8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_SRC_SWAP_MODE
define|\
value|0x120400UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_SR_CNT
define|\
value|0x120414UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_START_INIT
define|\
value|0x12036cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RD_TM_SWAP_MODE
define|\
value|0x1203fcUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD0
define|\
value|0x1201bcUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD12
define|\
value|0x1201ecUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD13
define|\
value|0x1201f0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD14
define|\
value|0x1201f4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD15
define|\
value|0x1201f8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD16
define|\
value|0x1201fcUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD17
define|\
value|0x120200UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD18
define|\
value|0x120204UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD19
define|\
value|0x120208UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD20
define|\
value|0x12020cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD22
define|\
value|0x120210UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD23
define|\
value|0x120214UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD24
define|\
value|0x120218UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD25
define|\
value|0x12021cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD26
define|\
value|0x120220UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD27
define|\
value|0x120224UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD4
define|\
value|0x1201ccUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_ADD5
define|\
value|0x1201d0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L0
define|\
value|0x1202acUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L12
define|\
value|0x1202dcUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L13
define|\
value|0x1202e0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L14
define|\
value|0x1202e4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L15
define|\
value|0x1202e8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L16
define|\
value|0x1202ecUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L17
define|\
value|0x1202f0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L18
define|\
value|0x1202f4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L19
define|\
value|0x1202f8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L20
define|\
value|0x1202fcUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L22
define|\
value|0x120300UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L23
define|\
value|0x120304UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L24
define|\
value|0x120308UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L25
define|\
value|0x12030cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L26
define|\
value|0x120310UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L27
define|\
value|0x120314UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L4
define|\
value|0x1202bcUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_L5
define|\
value|0x1202c0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND0
define|\
value|0x120234UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND12
define|\
value|0x120264UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND13
define|\
value|0x120268UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND14
define|\
value|0x12026cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND15
define|\
value|0x120270UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND16
define|\
value|0x120274UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND17
define|\
value|0x120278UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND18
define|\
value|0x12027cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND19
define|\
value|0x120280UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND20
define|\
value|0x120284UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND22
define|\
value|0x120288UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND23
define|\
value|0x12028cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND24
define|\
value|0x120290UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND25
define|\
value|0x120294UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND26
define|\
value|0x120298UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND27
define|\
value|0x12029cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND4
define|\
value|0x120244UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_RD_UBOUND5
define|\
value|0x120248UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_ADD29
define|\
value|0x12022cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_ADD30
define|\
value|0x120230UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_L29
define|\
value|0x12031cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_L30
define|\
value|0x120320UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_UBOUND29
define|\
value|0x1202a4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_BW_WR_UBOUND30
define|\
value|0x1202a8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU_ENDIAN_M
define|\
value|0x1201a0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU_FIRST_ILT
define|\
value|0x12061cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU_LAST_ILT
define|\
value|0x120620UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CDU_P_SIZE
define|\
value|0x120018UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_CFG_DONE
define|\
value|0x1201b4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_DBG_ENDIAN_M
define|\
value|0x1201a4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_DISABLE_INPUTS
define|\
value|0x120330UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_DRAM_ALIGN
define|\
value|0x1205b0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_DRAM_ALIGN_RD
define|\
value|0x12092cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_DRAM_ALIGN_SEL
define|\
value|0x120930UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_HC_ENDIAN_M
define|\
value|0x1201a8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_ONCHIP_AT
define|\
value|0x122000UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_ONCHIP_AT_B0
define|\
value|0x128000UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_PDR_LIMIT
define|\
value|0x12033cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_QM_ENDIAN_M
define|\
value|0x120194UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_QM_FIRST_ILT
define|\
value|0x120634UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_QM_LAST_ILT
define|\
value|0x120638UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_QM_P_SIZE
define|\
value|0x120050UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_RBC_DONE
define|\
value|0x1201b0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_RD_MBS0
define|\
value|0x120160UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_RD_MBS1
define|\
value|0x120168UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_SRC_ENDIAN_M
define|\
value|0x12019cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_SRC_FIRST_ILT
define|\
value|0x12063cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_SRC_LAST_ILT
define|\
value|0x120640UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_SRC_P_SIZE
define|\
value|0x12006cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_TM_ENDIAN_M
define|\
value|0x120198UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_TM_FIRST_ILT
define|\
value|0x120644UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_TM_LAST_ILT
define|\
value|0x120648UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_TM_P_SIZE
define|\
value|0x120034UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_WR_MBS0
define|\
value|0x12015cUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_RQ_WR_MBS1
define|\
value|0x120164UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_CDU_MPS
define|\
value|0x1205f0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_CSDM_MPS
define|\
value|0x1205d0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_DBG_MPS
define|\
value|0x1205e8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_DMAE_MPS
define|\
value|0x1205ecUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_HC_MPS
define|\
value|0x1205c8UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_QM_MPS
define|\
value|0x1205dcUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_SRC_MPS
define|\
value|0x1205e4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_TM_MPS
define|\
value|0x1205e0UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_TSDM_MPS
define|\
value|0x1205d4UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_USDMDP_TH
define|\
value|0x120348UL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_USDM_MPS
define|\
value|0x1205ccUL
end_define

begin_define
define|#
directive|define
name|PXP2_REG_WR_XSDM_MPS
define|\
value|0x1205d8UL
end_define

begin_define
define|#
directive|define
name|PXP_REG_HST_DISCARD_DOORBELLS
define|\
value|0x1030a4UL
end_define

begin_define
define|#
directive|define
name|PXP_REG_HST_DISCARD_INTERNAL_WRITES
define|\
value|0x1030a8UL
end_define

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_MASK_0
define|\
value|0x103074UL
end_define

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_MASK_1
define|\
value|0x103084UL
end_define

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_STS_CLR_0
define|\
value|0x10306cUL
end_define

begin_define
define|#
directive|define
name|PXP_REG_PXP_INT_STS_CLR_1
define|\
value|0x10307cUL
end_define

begin_define
define|#
directive|define
name|PXP_REG_PXP_PRTY_MASK
define|\
value|0x103094UL
end_define

begin_define
define|#
directive|define
name|PXP_REG_PXP_PRTY_STS_CLR
define|\
value|0x10308cUL
end_define

begin_define
define|#
directive|define
name|QM_REG_BASEADDR
define|\
value|0x168900UL
end_define

begin_define
define|#
directive|define
name|QM_REG_BASEADDR_EXT_A
define|\
value|0x16e100UL
end_define

begin_define
define|#
directive|define
name|QM_REG_BYTECRDCMDQ_0
define|\
value|0x16e6e8UL
end_define

begin_define
define|#
directive|define
name|QM_REG_CONNNUM_0
define|\
value|0x168020UL
end_define

begin_define
define|#
directive|define
name|QM_REG_PF_EN
define|\
value|0x16e70cUL
end_define

begin_define
define|#
directive|define
name|QM_REG_PF_USG_CNT_0
define|\
value|0x16e040UL
end_define

begin_define
define|#
directive|define
name|QM_REG_PTRTBL
define|\
value|0x168a00UL
end_define

begin_define
define|#
directive|define
name|QM_REG_PTRTBL_EXT_A
define|\
value|0x16e200UL
end_define

begin_define
define|#
directive|define
name|QM_REG_QM_INT_MASK
define|\
value|0x168444UL
end_define

begin_define
define|#
directive|define
name|QM_REG_QM_PRTY_MASK
define|\
value|0x168454UL
end_define

begin_define
define|#
directive|define
name|QM_REG_QM_PRTY_STS_CLR
define|\
value|0x16844cUL
end_define

begin_define
define|#
directive|define
name|QM_REG_QVOQIDX_0
define|\
value|0x1680f4UL
end_define

begin_define
define|#
directive|define
name|QM_REG_SOFT_RESET
define|\
value|0x168428UL
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQQMASK_0_LSB
define|\
value|0x168240UL
end_define

begin_define
define|#
directive|define
name|SEM_FAST_REG_PARITY_RST
define|\
value|0x18840UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_COUNTFREE0
define|\
value|0x40500UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_FIRSTFREE0
define|\
value|0x40510UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_0
define|\
value|0x40458UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_1
define|\
value|0x4045cUL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_2
define|\
value|0x40460UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_3
define|\
value|0x40464UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_4
define|\
value|0x40468UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_5
define|\
value|0x4046cUL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_6
define|\
value|0x40470UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_7
define|\
value|0x40474UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_8
define|\
value|0x40478UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_KEYSEARCH_9
define|\
value|0x4047cUL
end_define

begin_define
define|#
directive|define
name|SRC_REG_LASTFREE0
define|\
value|0x40530UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_NUMBER_HASH_BITS0
define|\
value|0x40400UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_SOFT_RST
define|\
value|0x4049cUL
end_define

begin_define
define|#
directive|define
name|SRC_REG_SRC_PRTY_MASK
define|\
value|0x404c8UL
end_define

begin_define
define|#
directive|define
name|SRC_REG_SRC_PRTY_STS_CLR
define|\
value|0x404c0UL
end_define

begin_define
define|#
directive|define
name|TCM_REG_PRS_IFEN
define|\
value|0x50020UL
end_define

begin_define
define|#
directive|define
name|TCM_REG_TCM_INT_MASK
define|\
value|0x501dcUL
end_define

begin_define
define|#
directive|define
name|TCM_REG_TCM_PRTY_MASK
define|\
value|0x501ecUL
end_define

begin_define
define|#
directive|define
name|TCM_REG_TCM_PRTY_STS_CLR
define|\
value|0x501e4UL
end_define

begin_define
define|#
directive|define
name|TM_REG_EN_LINEAR0_TIMER
define|\
value|0x164014UL
end_define

begin_define
define|#
directive|define
name|TM_REG_LIN0_MAX_ACTIVE_CID
define|\
value|0x164048UL
end_define

begin_define
define|#
directive|define
name|TM_REG_LIN0_NUM_SCANS
define|\
value|0x1640a0UL
end_define

begin_define
define|#
directive|define
name|TM_REG_LIN0_SCAN_ON
define|\
value|0x1640d0UL
end_define

begin_define
define|#
directive|define
name|TM_REG_LIN0_SCAN_TIME
define|\
value|0x16403cUL
end_define

begin_define
define|#
directive|define
name|TM_REG_LIN0_VNIC_UC
define|\
value|0x164128UL
end_define

begin_define
define|#
directive|define
name|TM_REG_TM_INT_MASK
define|\
value|0x1640fcUL
end_define

begin_define
define|#
directive|define
name|TM_REG_TM_PRTY_MASK
define|\
value|0x16410cUL
end_define

begin_define
define|#
directive|define
name|TM_REG_TM_PRTY_STS_CLR
define|\
value|0x164104UL
end_define

begin_define
define|#
directive|define
name|TSDM_REG_ENABLE_IN1
define|\
value|0x42238UL
end_define

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_INT_MASK_0
define|\
value|0x4229cUL
end_define

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_INT_MASK_1
define|\
value|0x422acUL
end_define

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_PRTY_MASK
define|\
value|0x422bcUL
end_define

begin_define
define|#
directive|define
name|TSDM_REG_TSDM_PRTY_STS_CLR
define|\
value|0x422b4UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_FAST_MEMORY
define|\
value|0x1a0000UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_INT_TABLE
define|\
value|0x180400UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_PASSIVE_BUFFER
define|\
value|0x181000UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_PRAM
define|\
value|0x1c0000UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_INT_MASK_0
define|\
value|0x180100UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_INT_MASK_1
define|\
value|0x180110UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_PRTY_MASK_0
define|\
value|0x180120UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_PRTY_MASK_1
define|\
value|0x180130UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_PRTY_STS_CLR_0
define|\
value|0x180118UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_TSEM_PRTY_STS_CLR_1
define|\
value|0x180128UL
end_define

begin_define
define|#
directive|define
name|TSEM_REG_VFPF_ERR_NUM
define|\
value|0x180380UL
end_define

begin_define
define|#
directive|define
name|UCM_REG_UCM_INT_MASK
define|\
value|0xe01d4UL
end_define

begin_define
define|#
directive|define
name|UCM_REG_UCM_PRTY_MASK
define|\
value|0xe01e4UL
end_define

begin_define
define|#
directive|define
name|UCM_REG_UCM_PRTY_STS_CLR
define|\
value|0xe01dcUL
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_HD_ENA
define|\
value|(0x1<<10)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_IGNORE_TX_PAUSE
define|\
value|(0x1<<28)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_LOOP_ENA
define|\
value|(0x1<<15)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_NO_LGTH_CHECK
define|\
value|(0x1<<24)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_PAD_EN
define|\
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_PAUSE_IGNORE
define|\
value|(0x1<<8)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_PROMIS_EN
define|\
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_RX_ENA
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_SW_RESET
define|\
value|(0x1<<13)
end_define

begin_define
define|#
directive|define
name|UMAC_COMMAND_CONFIG_REG_TX_ENA
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|UMAC_REG_COMMAND_CONFIG
define|\
value|0x8UL
end_define

begin_define
define|#
directive|define
name|UMAC_REG_EEE_WAKE_TIMER
define|\
value|0x6cUL
end_define

begin_define
define|#
directive|define
name|UMAC_REG_MAC_ADDR0
define|\
value|0xcUL
end_define

begin_define
define|#
directive|define
name|UMAC_REG_MAC_ADDR1
define|\
value|0x10UL
end_define

begin_define
define|#
directive|define
name|UMAC_REG_MAXFR
define|\
value|0x14UL
end_define

begin_define
define|#
directive|define
name|UMAC_REG_UMAC_EEE_CTRL
define|\
value|0x64UL
end_define

begin_define
define|#
directive|define
name|UMAC_UMAC_EEE_CTRL_REG_EEE_EN
define|\
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|USDM_REG_USDM_INT_MASK_0
define|\
value|0xc42a0UL
end_define

begin_define
define|#
directive|define
name|USDM_REG_USDM_INT_MASK_1
define|\
value|0xc42b0UL
end_define

begin_define
define|#
directive|define
name|USDM_REG_USDM_PRTY_MASK
define|\
value|0xc42c0UL
end_define

begin_define
define|#
directive|define
name|USDM_REG_USDM_PRTY_STS_CLR
define|\
value|0xc42b8UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_FAST_MEMORY
define|\
value|0x320000UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_INT_TABLE
define|\
value|0x300400UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_PASSIVE_BUFFER
define|\
value|0x302000UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_PRAM
define|\
value|0x340000UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_INT_MASK_0
define|\
value|0x300110UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_INT_MASK_1
define|\
value|0x300120UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_PRTY_MASK_0
define|\
value|0x300130UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_PRTY_MASK_1
define|\
value|0x300140UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_PRTY_STS_CLR_0
define|\
value|0x300128UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_USEM_PRTY_STS_CLR_1
define|\
value|0x300138UL
end_define

begin_define
define|#
directive|define
name|USEM_REG_VFPF_ERR_NUM
define|\
value|0x300380UL
end_define

begin_define
define|#
directive|define
name|VFC_MEMORIES_RST_REG_CAM_RST
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|VFC_MEMORIES_RST_REG_RAM_RST
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|VFC_REG_MEMORIES_RST
define|\
value|0x1943cUL
end_define

begin_define
define|#
directive|define
name|XCM_REG_XCM_INT_MASK
define|\
value|0x202b4UL
end_define

begin_define
define|#
directive|define
name|XCM_REG_XCM_PRTY_MASK
define|\
value|0x202c4UL
end_define

begin_define
define|#
directive|define
name|XCM_REG_XCM_PRTY_STS_CLR
define|\
value|0x202bcUL
end_define

begin_define
define|#
directive|define
name|XMAC_CLEAR_RX_LSS_STATUS_REG_CLEAR_LOCAL_FAULT_STATUS
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|XMAC_CLEAR_RX_LSS_STATUS_REG_CLEAR_REMOTE_FAULT_STATUS
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|XMAC_CTRL_REG_LINE_LOCAL_LPBK
define|\
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|XMAC_CTRL_REG_RX_EN
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|XMAC_CTRL_REG_SOFT_RESET
define|\
value|(0x1<<6)
end_define

begin_define
define|#
directive|define
name|XMAC_CTRL_REG_TX_EN
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|XMAC_CTRL_REG_XLGMII_ALIGN_ENB
define|\
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|XMAC_PAUSE_CTRL_REG_RX_PAUSE_EN
define|\
value|(0x1<<18)
end_define

begin_define
define|#
directive|define
name|XMAC_PAUSE_CTRL_REG_TX_PAUSE_EN
define|\
value|(0x1<<17)
end_define

begin_define
define|#
directive|define
name|XMAC_PFC_CTRL_HI_REG_FORCE_PFC_XON
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|XMAC_PFC_CTRL_HI_REG_PFC_REFRESH_EN
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|XMAC_PFC_CTRL_HI_REG_PFC_STATS_EN
define|\
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|XMAC_PFC_CTRL_HI_REG_RX_PFC_EN
define|\
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|XMAC_PFC_CTRL_HI_REG_TX_PFC_EN
define|\
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|XMAC_REG_CLEAR_RX_LSS_STATUS
define|\
value|0x60UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_CTRL
define|\
value|0UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_CTRL_SA_HI
define|\
value|0x2cUL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_CTRL_SA_LO
define|\
value|0x28UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_EEE_CTRL
define|\
value|0xd8UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_EEE_TIMERS_HI
define|\
value|0xe4UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_PAUSE_CTRL
define|\
value|0x68UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_PFC_CTRL
define|\
value|0x70UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_PFC_CTRL_HI
define|\
value|0x74UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_RX_LSS_CTRL
define|\
value|0x50UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_RX_LSS_STATUS
define|\
value|0x58UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_RX_MAX_SIZE
define|\
value|0x40UL
end_define

begin_define
define|#
directive|define
name|XMAC_REG_TX_CTRL
define|\
value|0x20UL
end_define

begin_define
define|#
directive|define
name|XMAC_RX_LSS_CTRL_REG_LOCAL_FAULT_DISABLE
define|\
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|XMAC_RX_LSS_CTRL_REG_REMOTE_FAULT_DISABLE
define|\
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|XSDM_REG_OPERATION_GEN
define|\
value|0x1664c4UL
end_define

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_INT_MASK_0
define|\
value|0x16629cUL
end_define

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_INT_MASK_1
define|\
value|0x1662acUL
end_define

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_PRTY_MASK
define|\
value|0x1662bcUL
end_define

begin_define
define|#
directive|define
name|XSDM_REG_XSDM_PRTY_STS_CLR
define|\
value|0x1662b4UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_FAST_MEMORY
define|\
value|0x2a0000UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_INT_TABLE
define|\
value|0x280400UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_PASSIVE_BUFFER
define|\
value|0x282000UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_PRAM
define|\
value|0x2c0000UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_VFPF_ERR_NUM
define|\
value|0x280380UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_INT_MASK_0
define|\
value|0x280110UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_INT_MASK_1
define|\
value|0x280120UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_PRTY_MASK_0
define|\
value|0x280130UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_PRTY_MASK_1
define|\
value|0x280140UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_PRTY_STS_CLR_0
define|\
value|0x280128UL
end_define

begin_define
define|#
directive|define
name|XSEM_REG_XSEM_PRTY_STS_CLR_1
define|\
value|0x280138UL
end_define

begin_define
define|#
directive|define
name|MCPR_ACCESS_LOCK_LOCK
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|MCPR_IMC_COMMAND_ENABLE
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|MCPR_IMC_COMMAND_IMC_STATUS_BITSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MCPR_IMC_COMMAND_OPERATION_BITSHIFT
value|28
end_define

begin_define
define|#
directive|define
name|MCPR_IMC_COMMAND_TRANSFER_ADDRESS_BITSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_ACCESS_ENABLE_EN
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_ACCESS_ENABLE_WR_EN
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_ADDR_NVM_ADDR_VALUE
value|(0xffffffL<<0)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_CFG4_FLASH_SIZE
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_DOIT
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_DONE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_FIRST
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_LAST
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_COMMAND_WR
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_SW_ARB_ARB_ARB1
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_SW_ARB_ARB_REQ_CLR1
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|MCPR_NVM_SW_ARB_ARB_REQ_SET1
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_BMAC_CONTROL
value|(0x00<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_BMAC_XGXS_CONTROL
value|(0x01<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_CNT_MAX_SIZE
value|(0x05<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_CONTROL
value|(0x21<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_LLFC_MSG_FLDS
value|(0x46<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_LSS_STATUS
value|(0x43<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_MAX_SIZE
value|(0x23<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_STAT_GR64
value|(0x26<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_RX_STAT_GRIPJ
value|(0x42<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_CONTROL
value|(0x07<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_MAX_SIZE
value|(0x09<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_PAUSE_THRESHOLD
value|(0x0A<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_SOURCE_ADDR
value|(0x08<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_STAT_GTBYT
value|(0x20<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC_REGISTER_TX_STAT_GTPKT
value|(0x0C<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_BMAC_CONTROL
value|(0x00<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_BMAC_XGXS_CONTROL
value|(0x01<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_CNT_MAX_SIZE
value|(0x05<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_PFC_CONTROL
value|(0x06<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_CONTROL
value|(0x3A<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_LLFC_MSG_FLDS
value|(0x62<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_LSS_STAT
value|(0x3E<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_MAX_SIZE
value|(0x3C<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_STAT_GR64
value|(0x40<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_RX_STAT_GRIPJ
value|(0x5f<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_CONTROL
value|(0x1C<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_MAX_SIZE
value|(0x1E<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_PAUSE_CONTROL
value|(0x20<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_SOURCE_ADDR
value|(0x1D<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_STAT_GTBYT
value|(0x39<<3)
end_define

begin_define
define|#
directive|define
name|BIGMAC2_REGISTER_TX_STAT_GTPOK
value|(0x22<<3)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_1000MB_OVERRIDE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_100MB_OVERRIDE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_10MB_OVERRIDE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|EMAC_LED_OVERRIDE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_COMMAND_ADDRESS
value|(0L<<26)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_COMMAND_READ_22
value|(2L<<26)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_COMMAND_READ_45
value|(3L<<26)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_COMMAND_WRITE_22
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_COMMAND_WRITE_45
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_DATA
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_COMM_START_BUSY
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_MODE_AUTO_POLL
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_MODE_CLAUSE_45
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_MODE_CLOCK_CNT
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_MODE_CLOCK_CNT_BITSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|EMAC_MDIO_STATUS_10MB
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_25G_MODE
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_HALF_DUPLEX
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_PORT_GMII
value|(2L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_PORT_MII
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_PORT_MII_10M
value|(3L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_LED
value|0xc
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MAC_MATCH
value|0x10
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MDIO_COMM
value|0xac
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MDIO_MODE
value|0xb4
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MDIO_STATUS
value|0xb0
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_MODE
value|0x0
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_MODE
value|0xc8
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_MTU_SIZE
value|0x9c
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_STAT_AC
value|0x180
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_STAT_AC_28
value|0x1f4
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_RX_STAT_AC_COUNT
value|23
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_TX_MODE
value|0xbc
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_TX_STAT_AC
value|0x280
end_define

begin_define
define|#
directive|define
name|EMAC_REG_EMAC_TX_STAT_AC_COUNT
value|22
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_MODE
value|0x320
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_MODE_PRIORITIES
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_MODE_RX_EN
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_MODE_TX_EN
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_PARAM
value|0x324
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_PARAM_OPCODE_BITSHIFT
value|0
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_PARAM_PRIORITY_EN_BITSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_STATS_XOFF_RCVD
value|0x328
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_STATS_XOFF_RCVD_COUNT
value|(0xffff<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_STATS_XOFF_SENT
value|0x330
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_STATS_XOFF_SENT_COUNT
value|(0xffff<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_STATS_XON_RCVD
value|0x32c
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_STATS_XON_RCVD_COUNT
value|(0xffff<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_STATS_XON_SENT
value|0x334
end_define

begin_define
define|#
directive|define
name|EMAC_REG_RX_PFC_STATS_XON_SENT_COUNT
value|(0xffff<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_FLOW_EN
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_KEEP_MAC_CONTROL
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_KEEP_VLAN_TAG
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_PROMISCUOUS
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_MTU_SIZE_JUMBO_ENA
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_MODE_EXT_PAUSE_EN
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_MODE_FLOW_EN
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_0
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_1
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_2
value|2
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_3
value|3
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_CLR_POS
value|16
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_FLOAT
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_FLOAT_POS
value|24
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INPUT_HI_Z
value|2
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INT_CLR_POS
value|24
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INT_OUTPUT_CLR
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INT_OUTPUT_SET
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_INT_SET_POS
value|16
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_LOW
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_OUTPUT_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_PORT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_GPIO_SET_POS
value|8
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_CLEAR
value|0x588
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_RST_BRB1
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_RST_DORQ
define|\
value|(0x1<<19)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_RST_HC
define|\
value|(0x1<<29)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_RST_PXP
define|\
value|(0x1<<26)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_RST_PXPV
define|\
value|(0x1<<27)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_RST_QM
define|\
value|(0x1<<17)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_1_SET
value|0x584
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_CLEAR
value|0x598
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_MSTAT0
define|\
value|(0x1<<24)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_MSTAT1
define|\
value|(0x1<<25)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_PGLC
define|\
value|(0x1<<19)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_ATC
define|\
value|(0x1<<17)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_BMAC0
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_BMAC1
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_EMAC0
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_EMAC0_HARD_CORE
define|\
value|(0x1<<14)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_EMAC1
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_EMAC1_HARD_CORE
define|\
value|(0x1<<15)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_GRC
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_MCP_N_HARD_CORE_RST_B
value|(0x1<<6)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_MCP_N_RESET_CMN_CORE
value|(0x1<<8)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_MCP_N_RESET_CMN_CPU
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_MCP_N_RESET_REG_HARD_CORE
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_MISC_CORE
define|\
value|(0x1<<11)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_PCI_MDIO
define|\
value|(0x1<<13)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_PXP_RQ_RD_WR
define|\
value|(0x1<<16)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_RST_RBCN
value|(0x1<<9)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_SET
value|0x594
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_UMAC0
define|\
value|(0x1<<20)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_UMAC1
define|\
value|(0x1<<21)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_XMAC
define|\
value|(0x1<<22)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_2_XMAC_SOFT
define|\
value|(0x1<<23)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_CLEAR
value|0x5a8
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_IDDQ
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_PWRDWN
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_PWRDWN_SD
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_SERDES0_RSTB_HW
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_IDDQ
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_PWRDWN
value|(0x1<<6)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_PWRDWN_SD
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_RSTB_HW
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_MISC_NIG_MUX_XGXS0_TXD_FIFO_RSTB
value|(0x1<<8)
end_define

begin_define
define|#
directive|define
name|MISC_REGISTERS_RESET_REG_3_SET
value|0x5a4
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_CLR_POS
value|16
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_FLOAT
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_FLOAT_POS
value|24
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_INPUT_HI_Z
value|2
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_INT_OLD_SET_POS
value|16
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_OUTPUT_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_SET_POS
value|8
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_SPIO4
value|0x10
end_define

begin_define
define|#
directive|define
name|MISC_SPIO_SPIO5
value|0x20
end_define

begin_define
define|#
directive|define
name|HW_LOCK_MAX_RESOURCE_VALUE
value|31
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_DRV_FLAGS
value|10
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_GPIO
value|1
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_NVRAM
value|12
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_PORT0_ATT_MASK
value|3
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_RECOVERY_LEADER_0
value|8
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_RECOVERY_LEADER_1
value|9
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_RECOVERY_REG
value|11
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_RESET
value|5
end_define

begin_define
define|#
directive|define
name|HW_LOCK_RESOURCE_SPIO
value|2
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_ATC_HW_INTERRUPT
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_ATC_PARITY_ERROR
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_BRB_HW_INTERRUPT
value|(0x1<<19)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_BRB_PARITY_ERROR
value|(0x1<<18)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CCM_HW_INTERRUPT
value|(0x1<<31)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CCM_PARITY_ERROR
value|(0x1<<30)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CDU_HW_INTERRUPT
value|(0x1<<9)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CDU_PARITY_ERROR
value|(0x1<<8)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CFC_HW_INTERRUPT
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CFC_PARITY_ERROR
value|(0x1<<6)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CSDM_HW_INTERRUPT
value|(0x1<<29)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CSDM_PARITY_ERROR
value|(0x1<<28)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CSEMI_HW_INTERRUPT
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_CSEMI_PARITY_ERROR
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DEBUG_PARITY_ERROR
value|(0x1<<18)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DMAE_HW_INTERRUPT
value|(0x1<<11)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DMAE_PARITY_ERROR
value|(0x1<<10)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DOORBELLQ_HW_INTERRUPT
value|(0x1<<13)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_DOORBELLQ_PARITY_ERROR
value|(0x1<<12)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_GPIO0_FUNCTION_0
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_IGU_PARITY_ERROR
value|(0x1<<12)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_MCP_LATCHED_ROM_PARITY
value|(0x1<<28)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_MCP_LATCHED_SCPAD_PARITY
value|(0x1UL<<31)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_MCP_LATCHED_UMP_RX_PARITY
value|(0x1<<29)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_MCP_LATCHED_UMP_TX_PARITY
value|(0x1<<30)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_MISC_HW_INTERRUPT
value|(0x1<<15)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_MISC_PARITY_ERROR
value|(0x1<<14)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_NIG_PARITY_ERROR
value|(0x1<<14)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PARSER_PARITY_ERROR
value|(0x1<<20)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PBCLIENT_HW_INTERRUPT
value|(0x1UL<<31)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PBCLIENT_PARITY_ERROR
value|(0x1<<30)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PBF_PARITY_ERROR
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PGLUE_HW_INTERRUPT
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PGLUE_PARITY_ERROR
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_HW_INTERRUPT
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_PARITY_ERROR
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PXP_HW_INTERRUPT
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_PXP_PARITY_ERROR
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_QM_HW_INTERRUPT
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_QM_PARITY_ERROR
value|(0x1<<2)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_SEARCHER_PARITY_ERROR
value|(0x1<<22)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_SPIO5
value|(0x1<<15)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TCM_HW_INTERRUPT
value|(0x1<<27)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TCM_PARITY_ERROR
value|(0x1<<26)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TIMERS_HW_INTERRUPT
value|(0x1<<5)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TIMERS_PARITY_ERROR
value|(0x1<<4)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TSDM_HW_INTERRUPT
value|(0x1<<25)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TSDM_PARITY_ERROR
value|(0x1<<24)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TSEMI_HW_INTERRUPT
value|(0x1<<29)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_TSEMI_PARITY_ERROR
value|(0x1<<28)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_UCM_HW_INTERRUPT
value|(0x1<<23)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_UCM_PARITY_ERROR
value|(0x1<<22)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_UPB_HW_INTERRUPT
value|(0x1<<27)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_UPB_PARITY_ERROR
value|(0x1<<26)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_USDM_HW_INTERRUPT
value|(0x1<<21)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_USDM_PARITY_ERROR
value|(0x1<<20)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_USEMI_HW_INTERRUPT
value|(0x1<<25)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_USEMI_PARITY_ERROR
value|(0x1<<24)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_VAUX_PCI_CORE_PARITY_ERROR
value|(0x1<<16)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XCM_HW_INTERRUPT
value|(0x1<<9)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XCM_PARITY_ERROR
value|(0x1<<8)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XSDM_HW_INTERRUPT
value|(0x1<<7)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XSDM_PARITY_ERROR
value|(0x1<<6)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XSEMI_HW_INTERRUPT
value|(0x1<<11)
end_define

begin_define
define|#
directive|define
name|AEU_INPUTS_ATTN_BITS_XSEMI_PARITY_ERROR
value|(0x1<<10)
end_define

begin_define
define|#
directive|define
name|HW_PRTY_ASSERT_SET_0
define|\
value|(AEU_INPUTS_ATTN_BITS_BRB_PARITY_ERROR	    |\   AEU_INPUTS_ATTN_BITS_PARSER_PARITY_ERROR   |\   AEU_INPUTS_ATTN_BITS_TSDM_PARITY_ERROR     |\   AEU_INPUTS_ATTN_BITS_SEARCHER_PARITY_ERROR |\   AEU_INPUTS_ATTN_BITS_TSEMI_PARITY_ERROR |\   AEU_INPUTS_ATTN_BITS_TCM_PARITY_ERROR |\   AEU_INPUTS_ATTN_BITS_PBCLIENT_PARITY_ERROR)
end_define

begin_define
define|#
directive|define
name|HW_PRTY_ASSERT_SET_1
define|\
value|(AEU_INPUTS_ATTN_BITS_PBF_PARITY_ERROR		 |\   AEU_INPUTS_ATTN_BITS_QM_PARITY_ERROR		  |\   AEU_INPUTS_ATTN_BITS_TIMERS_PARITY_ERROR	  |\   AEU_INPUTS_ATTN_BITS_XSDM_PARITY_ERROR	  |\   AEU_INPUTS_ATTN_BITS_XCM_PARITY_ERROR		  |\   AEU_INPUTS_ATTN_BITS_XSEMI_PARITY_ERROR	  |\   AEU_INPUTS_ATTN_BITS_DOORBELLQ_PARITY_ERROR	  |\   AEU_INPUTS_ATTN_BITS_NIG_PARITY_ERROR		  |\   AEU_INPUTS_ATTN_BITS_VAUX_PCI_CORE_PARITY_ERROR |\   AEU_INPUTS_ATTN_BITS_DEBUG_PARITY_ERROR	  |\   AEU_INPUTS_ATTN_BITS_USDM_PARITY_ERROR	  |\   AEU_INPUTS_ATTN_BITS_UCM_PARITY_ERROR		  |\   AEU_INPUTS_ATTN_BITS_USEMI_PARITY_ERROR	  |\   AEU_INPUTS_ATTN_BITS_UPB_PARITY_ERROR		  |\   AEU_INPUTS_ATTN_BITS_CSDM_PARITY_ERROR	  |\   AEU_INPUTS_ATTN_BITS_CCM_PARITY_ERROR)
end_define

begin_define
define|#
directive|define
name|HW_PRTY_ASSERT_SET_2
define|\
value|(AEU_INPUTS_ATTN_BITS_CSEMI_PARITY_ERROR	     |\   AEU_INPUTS_ATTN_BITS_PXP_PARITY_ERROR		      |\   AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_PARITY_ERROR |\   AEU_INPUTS_ATTN_BITS_CFC_PARITY_ERROR		      |\   AEU_INPUTS_ATTN_BITS_CDU_PARITY_ERROR		      |\   AEU_INPUTS_ATTN_BITS_DMAE_PARITY_ERROR	      |\   AEU_INPUTS_ATTN_BITS_IGU_PARITY_ERROR		      |\   AEU_INPUTS_ATTN_BITS_MISC_PARITY_ERROR)
end_define

begin_define
define|#
directive|define
name|HW_PRTY_ASSERT_SET_3
define|\
value|(AEU_INPUTS_ATTN_BITS_MCP_LATCHED_ROM_PARITY	     | \   AEU_INPUTS_ATTN_BITS_MCP_LATCHED_UMP_RX_PARITY      | \   AEU_INPUTS_ATTN_BITS_MCP_LATCHED_UMP_TX_PARITY      | \   AEU_INPUTS_ATTN_BITS_MCP_LATCHED_SCPAD_PARITY)
end_define

begin_define
define|#
directive|define
name|HW_PRTY_ASSERT_SET_4
define|\
value|(AEU_INPUTS_ATTN_BITS_PGLUE_PARITY_ERROR |\   AEU_INPUTS_ATTN_BITS_ATC_PARITY_ERROR)
end_define

begin_define
define|#
directive|define
name|HW_INTERRUT_ASSERT_SET_0
define|\
value|(AEU_INPUTS_ATTN_BITS_TSDM_HW_INTERRUPT  |\   AEU_INPUTS_ATTN_BITS_TCM_HW_INTERRUPT   |\   AEU_INPUTS_ATTN_BITS_TSEMI_HW_INTERRUPT |\   AEU_INPUTS_ATTN_BITS_BRB_HW_INTERRUPT   |\   AEU_INPUTS_ATTN_BITS_PBCLIENT_HW_INTERRUPT)
end_define

begin_define
define|#
directive|define
name|HW_INTERRUT_ASSERT_SET_1
define|\
value|(AEU_INPUTS_ATTN_BITS_QM_HW_INTERRUPT	    |\   AEU_INPUTS_ATTN_BITS_TIMERS_HW_INTERRUPT   |\   AEU_INPUTS_ATTN_BITS_XSDM_HW_INTERRUPT     |\   AEU_INPUTS_ATTN_BITS_XCM_HW_INTERRUPT      |\   AEU_INPUTS_ATTN_BITS_XSEMI_HW_INTERRUPT    |\   AEU_INPUTS_ATTN_BITS_USDM_HW_INTERRUPT     |\   AEU_INPUTS_ATTN_BITS_UCM_HW_INTERRUPT      |\   AEU_INPUTS_ATTN_BITS_USEMI_HW_INTERRUPT    |\   AEU_INPUTS_ATTN_BITS_UPB_HW_INTERRUPT      |\   AEU_INPUTS_ATTN_BITS_CSDM_HW_INTERRUPT     |\   AEU_INPUTS_ATTN_BITS_CCM_HW_INTERRUPT)
end_define

begin_define
define|#
directive|define
name|HW_INTERRUT_ASSERT_SET_2
define|\
value|(AEU_INPUTS_ATTN_BITS_CSEMI_HW_INTERRUPT	       |\   AEU_INPUTS_ATTN_BITS_PXP_HW_INTERRUPT			|\   AEU_INPUTS_ATTN_BITS_CFC_HW_INTERRUPT			|\   AEU_INPUTS_ATTN_BITS_CDU_HW_INTERRUPT			|\   AEU_INPUTS_ATTN_BITS_DMAE_HW_INTERRUPT		|\   AEU_INPUTS_ATTN_BITS_PXPPCICLOCKCLIENT_HW_INTERRUPT	|\   AEU_INPUTS_ATTN_BITS_MISC_HW_INTERRUPT)
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_0
value|0
end_define

begin_define
define|#
directive|define
name|EVEREST_GEN_ATTN_IN_USE_MASK
value|0x7ffe0
end_define

begin_define
define|#
directive|define
name|EVEREST_LATCHED_ATTN_IN_USE_MASK
value|0xffe00000
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_6
value|6
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_7
value|7
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_8
value|8
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_9
value|9
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_10
value|10
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_11
value|11
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_12
value|12
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_13
value|13
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_14
value|14
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_15
value|15
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_16
value|16
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_17
value|17
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_18
value|18
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_19
value|19
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_20
value|20
end_define

begin_define
define|#
directive|define
name|RESERVED_GENERAL_ATTENTION_BIT_21
value|21
end_define

begin_comment
comment|/* storm asserts attention bits */
end_comment

begin_define
define|#
directive|define
name|TSTORM_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_7
end_define

begin_define
define|#
directive|define
name|USTORM_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_8
end_define

begin_define
define|#
directive|define
name|CSTORM_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_9
end_define

begin_define
define|#
directive|define
name|XSTORM_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_10
end_define

begin_comment
comment|/* mcp error attention bit */
end_comment

begin_define
define|#
directive|define
name|MCP_FATAL_ASSERT_ATTENTION_BIT
value|RESERVED_GENERAL_ATTENTION_BIT_11
end_define

begin_comment
comment|/*E1H NIG status sync attention mapped to group 4-7*/
end_comment

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_0
value|RESERVED_GENERAL_ATTENTION_BIT_12
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_1
value|RESERVED_GENERAL_ATTENTION_BIT_13
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_2
value|RESERVED_GENERAL_ATTENTION_BIT_14
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_3
value|RESERVED_GENERAL_ATTENTION_BIT_15
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_4
value|RESERVED_GENERAL_ATTENTION_BIT_16
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_5
value|RESERVED_GENERAL_ATTENTION_BIT_17
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_6
value|RESERVED_GENERAL_ATTENTION_BIT_18
end_define

begin_define
define|#
directive|define
name|LINK_SYNC_ATTENTION_BIT_FUNC_7
value|RESERVED_GENERAL_ATTENTION_BIT_19
end_define

begin_comment
comment|/* Used For Error Recovery: changing this will require more \ 	changes in code that assume  * error recovery uses general attn bit20 ! */
end_comment

begin_define
define|#
directive|define
name|ERROR_RECOVERY_ATTENTION_BIT
define|\
value|RESERVED_GENERAL_ATTENTION_BIT_20
end_define

begin_define
define|#
directive|define
name|RESERVED_ATTENTION_BIT
define|\
value|RESERVED_GENERAL_ATTENTION_BIT_21
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCR
value|23
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCT
value|24
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCN
value|25
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCU
value|26
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RBCP
value|27
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_TIMEOUT_GRC
value|28
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_RSVD_GRC
value|29
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_ROM_PARITY_MCP
value|30
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_UM_RX_PARITY_MCP
value|31
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_UM_TX_PARITY_MCP
value|32
end_define

begin_define
define|#
directive|define
name|LATCHED_ATTN_SCPAD_PARITY_MCP
value|33
end_define

begin_define
define|#
directive|define
name|GENERAL_ATTEN_WORD
parameter_list|(
name|atten_name
parameter_list|)
value|((94 + atten_name) / 32)
end_define

begin_define
define|#
directive|define
name|GENERAL_ATTEN_OFFSET
parameter_list|(
name|atten_name
parameter_list|)
value|(1UL<< ((94 + atten_name) % 32))
end_define

begin_comment
comment|/*  * This file defines GRC base address for every block.  * This file is included by chipsim, asm microcode and cpp microcode.  * These values are used in Design.xml on regBase attribute  * Use the base with the generated offsets of specific registers.  */
end_comment

begin_define
define|#
directive|define
name|GRCBASE_PXPCS
value|0x000000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PCICONFIG
value|0x002000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PCIREG
value|0x002400
end_define

begin_define
define|#
directive|define
name|GRCBASE_EMAC0
value|0x008000
end_define

begin_define
define|#
directive|define
name|GRCBASE_EMAC1
value|0x008400
end_define

begin_define
define|#
directive|define
name|GRCBASE_DBU
value|0x008800
end_define

begin_define
define|#
directive|define
name|GRCBASE_PGLUE_B
value|0x009000
end_define

begin_define
define|#
directive|define
name|GRCBASE_MISC
value|0x00A000
end_define

begin_define
define|#
directive|define
name|GRCBASE_DBG
value|0x00C000
end_define

begin_define
define|#
directive|define
name|GRCBASE_NIG
value|0x010000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XCM
value|0x020000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PRS
value|0x040000
end_define

begin_define
define|#
directive|define
name|GRCBASE_SRCH
value|0x040400
end_define

begin_define
define|#
directive|define
name|GRCBASE_TSDM
value|0x042000
end_define

begin_define
define|#
directive|define
name|GRCBASE_TCM
value|0x050000
end_define

begin_define
define|#
directive|define
name|GRCBASE_BRB1
value|0x060000
end_define

begin_define
define|#
directive|define
name|GRCBASE_MCP
value|0x080000
end_define

begin_define
define|#
directive|define
name|GRCBASE_UPB
value|0x0C1000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CSDM
value|0x0C2000
end_define

begin_define
define|#
directive|define
name|GRCBASE_USDM
value|0x0C4000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CCM
value|0x0D0000
end_define

begin_define
define|#
directive|define
name|GRCBASE_UCM
value|0x0E0000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CDU
value|0x101000
end_define

begin_define
define|#
directive|define
name|GRCBASE_DMAE
value|0x102000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PXP
value|0x103000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CFC
value|0x104000
end_define

begin_define
define|#
directive|define
name|GRCBASE_HC
value|0x108000
end_define

begin_define
define|#
directive|define
name|GRCBASE_ATC
value|0x110000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PXP2
value|0x120000
end_define

begin_define
define|#
directive|define
name|GRCBASE_IGU
value|0x130000
end_define

begin_define
define|#
directive|define
name|GRCBASE_PBF
value|0x140000
end_define

begin_define
define|#
directive|define
name|GRCBASE_UMAC0
value|0x160000
end_define

begin_define
define|#
directive|define
name|GRCBASE_UMAC1
value|0x160400
end_define

begin_define
define|#
directive|define
name|GRCBASE_XPB
value|0x161000
end_define

begin_define
define|#
directive|define
name|GRCBASE_MSTAT0
value|0x162000
end_define

begin_define
define|#
directive|define
name|GRCBASE_MSTAT1
value|0x162800
end_define

begin_define
define|#
directive|define
name|GRCBASE_XMAC0
value|0x163000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XMAC1
value|0x163800
end_define

begin_define
define|#
directive|define
name|GRCBASE_TIMERS
value|0x164000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XSDM
value|0x166000
end_define

begin_define
define|#
directive|define
name|GRCBASE_QM
value|0x168000
end_define

begin_define
define|#
directive|define
name|GRCBASE_QM_4PORT
value|0x168000
end_define

begin_define
define|#
directive|define
name|GRCBASE_DQ
value|0x170000
end_define

begin_define
define|#
directive|define
name|GRCBASE_TSEM
value|0x180000
end_define

begin_define
define|#
directive|define
name|GRCBASE_CSEM
value|0x200000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XSEM
value|0x280000
end_define

begin_define
define|#
directive|define
name|GRCBASE_XSEM_4PORT
value|0x280000
end_define

begin_define
define|#
directive|define
name|GRCBASE_USEM
value|0x300000
end_define

begin_define
define|#
directive|define
name|GRCBASE_MCP_A
value|0x380000
end_define

begin_define
define|#
directive|define
name|GRCBASE_MISC_AEU
value|GRCBASE_MISC
end_define

begin_define
define|#
directive|define
name|GRCBASE_Tstorm
value|GRCBASE_TSEM
end_define

begin_define
define|#
directive|define
name|GRCBASE_Cstorm
value|GRCBASE_CSEM
end_define

begin_define
define|#
directive|define
name|GRCBASE_Xstorm
value|GRCBASE_XSEM
end_define

begin_define
define|#
directive|define
name|GRCBASE_Ustorm
value|GRCBASE_USEM
end_define

begin_comment
comment|/* offset of configuration space in the pci core register */
end_comment

begin_define
define|#
directive|define
name|PCICFG_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCICFG_VENDOR_ID_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_ID_OFFSET
value|0x02
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_IO_SPACE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_MEM_SPACE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_BUS_MASTER
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_SPECIAL_CYCLES
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_MWI_CYCLES
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_VGA_SNOOP
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_PERR_ENA
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_STEPPING
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_SERR_ENA
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_FAST_B2B
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_INT_DISABLE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|PCICFG_COMMAND_RESERVED
value|(0x1f<<11)
end_define

begin_define
define|#
directive|define
name|PCICFG_STATUS_OFFSET
value|0x06
end_define

begin_define
define|#
directive|define
name|PCICFG_REVISION_ID_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|PCICFG_REVESION_ID_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|PCICFG_REVESION_ID_ERROR_VAL
value|0xff
end_define

begin_define
define|#
directive|define
name|PCICFG_CACHE_LINE_SIZE
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCICFG_LATENCY_TIMER
value|0x0d
end_define

begin_define
define|#
directive|define
name|PCICFG_HEADER_TYPE
value|0x0e
end_define

begin_define
define|#
directive|define
name|PCICFG_HEADER_TYPE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|PCICFG_HEADER_TYPE_BRIDGE
value|1
end_define

begin_define
define|#
directive|define
name|PCICFG_HEADER_TYPE_CARDBUS
value|2
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_1_LOW
value|0x10
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_1_HIGH
value|0x14
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_2_LOW
value|0x18
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_2_HIGH
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_3_LOW
value|0x20
end_define

begin_define
define|#
directive|define
name|PCICFG_BAR_3_HIGH
value|0x24
end_define

begin_define
define|#
directive|define
name|PCICFG_SUBSYSTEM_VENDOR_ID_OFFSET
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCICFG_SUBSYSTEM_ID_OFFSET
value|0x2e
end_define

begin_define
define|#
directive|define
name|PCICFG_INT_LINE
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCICFG_INT_PIN
value|0x3d
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY
value|0x48
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_VERSION
value|(0x3<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_CLOCK
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_RESERVED
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_DSI
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_AUX_CURRENT
value|(0x7<<22)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_D1_SUPPORT
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_D2_SUPPORT
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D0
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D1
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D2
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D3_HOT
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CAPABILITY_PME_IN_D3_COLD
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_OFFSET
value|0x4c
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_STATE
value|(0x3<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_PME_ENABLE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PCICFG_PM_CSR_PME_STATUS
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|PCICFG_VPD_FLAG_ADDR_OFFSET
value|0x50
end_define

begin_define
define|#
directive|define
name|PCICFG_VPD_DATA_OFFSET
value|0x54
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CAP_ID_OFFSET
value|0x58
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_ENABLE
value|(0x1<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MCAP
value|(0x7<<17)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MENA
value|(0x7<<20)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_64_BIT_ADDR_CAP
value|(0x1<<23)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_CONTROL_MSI_PVMASK_CAPABLE
value|(0x1<<24)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_ADDR_LOW_OFFSET
value|0x5c
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_ADDR_HIGH_OFFSET
value|0x60
end_define

begin_define
define|#
directive|define
name|PCICFG_MSI_DATA_OFFSET
value|0x64
end_define

begin_define
define|#
directive|define
name|PCICFG_GRC_ADDRESS
value|0x78
end_define

begin_define
define|#
directive|define
name|PCICFG_GRC_DATA
value|0x80
end_define

begin_define
define|#
directive|define
name|PCICFG_ME_REGISTER
value|0x98
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CAP_ID_OFFSET
value|0xa0
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_TABLE_SIZE
value|(0x7ff<<16)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_RESERVED
value|(0x7<<27)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_FUNC_MASK
value|(0x1<<30)
end_define

begin_define
define|#
directive|define
name|PCICFG_MSIX_CONTROL_MSIX_ENABLE
value|(0x1<<31)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_CONTROL
value|0xb4
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_CONTROL_NP_TRANSACTION_PEND
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS
value|0xb6
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_CORR_ERR_DET
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_NON_FATAL_ERR_DET
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_FATAL_ERR_DET
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_UNSUP_REQ_DET
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_AUX_PWR_DET
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PCICFG_DEVICE_STATUS_NO_PEND
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PCICFG_LINK_CONTROL
value|0xbc
end_define

begin_comment
comment|/* config_2 offset */
end_comment

begin_define
define|#
directive|define
name|GRC_CONFIG_2_SIZE_REG
value|0x408
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR1_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_RETRY
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_CFG_CYCLE_RETRY
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_FIRST_CFG_DONE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_DISABLED
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_2K
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_4K
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_8K
value|(3L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_16K
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_32K
value|(5L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_64K
value|(6L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_128K
value|(7L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_256K
value|(8L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_512K
value|(9L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_1M
value|(10L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_2M
value|(11L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_4M
value|(12L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_8M
value|(13L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_16M
value|(14L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_EXP_ROM_SIZE_32M
value|(15L<<8)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR_PREFETCH
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_RESERVED0
value|(0x7fffL<<17)
end_define

begin_comment
comment|/* config_3 offset */
end_comment

begin_define
define|#
directive|define
name|GRC_CONFIG_3_SIZE_REG
value|0x40c
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_STICKY_BYTE
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_FORCE_PME
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PME_STATUS
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PME_ENABLE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PM_STATE
value|(0x3L<<27)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_VAUX_PRESET
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_3_PCI_POWER
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|GRC_REG_DEVICE_CONTROL
value|0x4d8
end_define

begin_define
define|#
directive|define
name|PCIE_SRIOV_DISABLE_IN_PROGRESS
define|\
value|(1<< 29)
end_define

begin_comment
comment|/*When VF Enable is cleared(after it was previously set),  this register will read a value of 1, indicating that all the  VFs that belong to this PF should be flushed.  Software should clear this bit within 1 second of VF Enable  being set by writing a 1 to it, so that VFs are visible to the system again. 							WC */
end_comment

begin_define
define|#
directive|define
name|PCIE_FLR_IN_PROGRESS
define|\
value|(1<< 27)
end_define

begin_comment
comment|/*When FLR is initiated, this register will read a \ 	value of 1 indicating that the  Function is in FLR state. Func can be brought out of FLR state either by  writing 1 to this register (at least 50 ms after FLR was initiated),  or it can also be cleared automatically after 55 ms if auto_clear bit  in private reg space is set. This bit also exists in VF register space 							WC */
end_comment

begin_define
define|#
directive|define
name|GRC_BAR2_CONFIG
value|0x4e0
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR2_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|GRC_BAR3_CONFIG
value|0x4f4
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_2_BAR3_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PCI_PM_DATA_A
value|0x410
end_define

begin_define
define|#
directive|define
name|PCI_PM_DATA_B
value|0x414
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL1
value|0x434
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL2
value|0x438
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL3
value|0x43c
end_define

begin_define
define|#
directive|define
name|PCI_ID_VAL3_REVISION_ID_ERROR
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|GRC_CONFIG_REG_VF_BAR_REG_1
value|0x608
end_define

begin_define
define|#
directive|define
name|GRC_CONFIG_REG_VF_BAR_REG_BAR0_SIZE
value|0xf
end_define

begin_define
define|#
directive|define
name|GRC_CONFIG_REG_VF_MSIX_CONTROL
value|0x61C
end_define

begin_define
define|#
directive|define
name|GRC_CR_VF_MSIX_CTRL_VF_MSIX_TBL_SIZE_MASK
define|\
value|0x3F
end_define

begin_comment
comment|/*This field resides in VF only and does not exist in PF.  This register controls the read value of the MSIX_CONTROL[10:0] register  in the VF configuration space. A value of "00000000011" indicates  a table size of 4. The value is controlled by IOV_MSIX_TBL_SIZ  define in version.v */
end_comment

begin_define
define|#
directive|define
name|GRC_CONFIG_REG_PF_INIT_VF
value|0x624
end_define

begin_define
define|#
directive|define
name|GRC_CR_PF_INIT_VF_PF_FIRST_VF_NUM_MASK
define|\
value|0xf
end_define

begin_comment
comment|/*First VF_NUM for PF is encoded in this register.  The number of VFs assigned to a PF is assumed to be a multiple of 8. 	Software should program these bits based on Total Number of VFs \ 	programmed for each PF.  Since registers from 0x000-0x7ff are spilt across functions, each PF will have  the same location for the same 4 bits*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5
value|0x814
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_UNKNOWNTYPE_ERR_ATTN
value|(1<< 29)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_BOUNDARY4K_ERR_ATTN
value|(1<< 28)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_MRRS_ERR_ATTN
value|(1<< 27)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_MPS_ERR_ATTN
value|(1<< 26)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_TTX_BRIDGE_FORWARD_ERR
value|(1<< 25)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_TTX_TXINTF_OVERFLOW
value|(1<< 24)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_PHY_ERR_ATTN
value|(1<< 23)
end_define

begin_comment
comment|/*RO*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_DL_ERR_ATTN
value|(1<< 22)
end_define

begin_comment
comment|/*RO*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_TTX_ERR_NP_TAG_IN_USE
value|(1<< 21)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_TRX_ERR_UNEXP_RTAG
value|(1<< 20)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_PRI_SIG_TARGET_ABORT1
value|(1<< 19)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_UNSPPORT1
value|(1<< 18)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_ECRC1
value|(1<< 17)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_MALF_TLP1
value|(1<< 16)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_RX_OFLOW1
value|(1<< 15)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_UNEXP_CPL1
value|(1<< 14)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_MASTER_ABRT1
value|(1<< 13)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_CPL_TIMEOUT1
value|(1<< 12)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_FC_PRTL1
value|(1<< 11)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_PSND_TLP1
value|(1<< 10)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_PRI_SIG_TARGET_ABORT
value|(1<< 9)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_UNSPPORT
value|(1<< 8)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_ECRC
value|(1<< 7)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_MALF_TLP
value|(1<< 6)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_RX_OFLOW
value|(1<< 5)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_UNEXP_CPL
value|(1<< 4)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_MASTER_ABRT
value|(1<< 3)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_CPL_TIMEOUT
value|(1<< 2)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_FC_PRTL
value|(1<< 1)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_CONTROL_5_ERR_PSND_TLP
value|(1<< 0)
end_define

begin_comment
comment|/*WC*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT
value|0x854
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_PRI_SIG_TARGET_ABORT4
value|(1<< 29)
end_define

begin_comment
comment|/* WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT4
define|\
value|(1<< 28)
end_define

begin_comment
comment|/* Unsupported Request Error Status in function4, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_ECRC4
define|\
value|(1<< 27)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status in function 4, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MALF_TLP4
define|\
value|(1<< 26)
end_define

begin_comment
comment|/* Malformed TLP Status Status in function 4, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_RX_OFLOW4
define|\
value|(1<< 25)
end_define

begin_comment
comment|/* Receiver Overflow Status Status in function 4, if \ 	set, generate pcie_err_attn output when this error is seen.. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNEXP_CPL4
define|\
value|(1<< 24)
end_define

begin_comment
comment|/* Unexpected Completion Status Status in function 4, \ 	if set, generate pcie_err_attn output when this error is seen. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MASTER_ABRT4
define|\
value|(1<< 23)
end_define

begin_comment
comment|/* Receive UR Statusin function 4. If set, generate \ 	pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_CPL_TIMEOUT4
define|\
value|(1<< 22)
end_define

begin_comment
comment|/* Completer Timeout Status Status in function 4, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_FC_PRTL4
define|\
value|(1<< 21)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status in \ 	function 4, if set, generate pcie_err_attn output when this error \ 	is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_PSND_TLP4
define|\
value|(1<< 20)
end_define

begin_comment
comment|/* Poisoned Error Status Status in function 4, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_PRI_SIG_TARGET_ABORT3
value|(1<< 19)
end_define

begin_comment
comment|/* WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT3
define|\
value|(1<< 18)
end_define

begin_comment
comment|/* Unsupported Request Error Status in function3, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_ECRC3
define|\
value|(1<< 17)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status in function 3, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MALF_TLP3
define|\
value|(1<< 16)
end_define

begin_comment
comment|/* Malformed TLP Status Status in function 3, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_RX_OFLOW3
define|\
value|(1<< 15)
end_define

begin_comment
comment|/* Receiver Overflow Status Status in function 3, if \ 	set, generate pcie_err_attn output when this error is seen.. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNEXP_CPL3
define|\
value|(1<< 14)
end_define

begin_comment
comment|/* Unexpected Completion Status Status in function 3, \ 	if set, generate pcie_err_attn output when this error is seen. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MASTER_ABRT3
define|\
value|(1<< 13)
end_define

begin_comment
comment|/* Receive UR Statusin function 3. If set, generate \ 	pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_CPL_TIMEOUT3
define|\
value|(1<< 12)
end_define

begin_comment
comment|/* Completer Timeout Status Status in function 3, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_FC_PRTL3
define|\
value|(1<< 11)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status in \ 	function 3, if set, generate pcie_err_attn output when this error \ 	is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_PSND_TLP3
define|\
value|(1<< 10)
end_define

begin_comment
comment|/* Poisoned Error Status Status in function 3, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_PRI_SIG_TARGET_ABORT2
value|(1<< 9)
end_define

begin_comment
comment|/* WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT2
define|\
value|(1<< 8)
end_define

begin_comment
comment|/* Unsupported Request Error Status for Function 2, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_ECRC2
define|\
value|(1<< 7)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status for Function 2, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MALF_TLP2
define|\
value|(1<< 6)
end_define

begin_comment
comment|/* Malformed TLP Status Status for Function 2, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_RX_OFLOW2
define|\
value|(1<< 5)
end_define

begin_comment
comment|/* Receiver Overflow Status Status for Function 2, if \ 	set, generate pcie_err_attn output when this error is seen.. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_UNEXP_CPL2
define|\
value|(1<< 4)
end_define

begin_comment
comment|/* Unexpected Completion Status Status for Function 2, \ 	if set, generate pcie_err_attn output when this error is seen. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_MASTER_ABRT2
define|\
value|(1<< 3)
end_define

begin_comment
comment|/* Receive UR Statusfor Function 2. If set, generate \ 	pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_CPL_TIMEOUT2
define|\
value|(1<< 2)
end_define

begin_comment
comment|/* Completer Timeout Status Status for Function 2, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_FC_PRTL2
define|\
value|(1<< 1)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status for \ 	Function 2, if set, generate pcie_err_attn output when this error \ 	is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC345_STAT_ERR_PSND_TLP2
define|\
value|(1<< 0)
end_define

begin_comment
comment|/* Poisoned Error Status Status for Function 2, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT
value|0x85C
end_define

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_PRI_SIG_TARGET_ABORT7
value|(1<< 29)
end_define

begin_comment
comment|/*	 WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT7
define|\
value|(1<< 28)
end_define

begin_comment
comment|/* Unsupported Request Error Status in function7, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_ECRC7
define|\
value|(1<< 27)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status in function 7, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MALF_TLP7
define|\
value|(1<< 26)
end_define

begin_comment
comment|/* Malformed TLP Status Status in function 7, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_RX_OFLOW7
define|\
value|(1<< 25)
end_define

begin_comment
comment|/* Receiver Overflow Status Status in function 7, if \ 	set, generate pcie_err_attn output when this error is seen.. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNEXP_CPL7
define|\
value|(1<< 24)
end_define

begin_comment
comment|/* Unexpected Completion Status Status in function 7, \ 	if set, generate pcie_err_attn output when this error is seen. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MASTER_ABRT7
define|\
value|(1<< 23)
end_define

begin_comment
comment|/* Receive UR Statusin function 7. If set, generate \ 	pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_CPL_TIMEOUT7
define|\
value|(1<< 22)
end_define

begin_comment
comment|/* Completer Timeout Status Status in function 7, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_FC_PRTL7
define|\
value|(1<< 21)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status in \ 	function 7, if set, generate pcie_err_attn output when this error \ 	is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_PSND_TLP7
define|\
value|(1<< 20)
end_define

begin_comment
comment|/* Poisoned Error Status Status in function 7, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_PRI_SIG_TARGET_ABORT6
value|(1<< 19)
end_define

begin_comment
comment|/*	  WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT6
define|\
value|(1<< 18)
end_define

begin_comment
comment|/* Unsupported Request Error Status in function6, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_ECRC6
define|\
value|(1<< 17)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status in function 6, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MALF_TLP6
define|\
value|(1<< 16)
end_define

begin_comment
comment|/* Malformed TLP Status Status in function 6, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_RX_OFLOW6
define|\
value|(1<< 15)
end_define

begin_comment
comment|/* Receiver Overflow Status Status in function 6, if \ 	set, generate pcie_err_attn output when this error is seen.. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNEXP_CPL6
define|\
value|(1<< 14)
end_define

begin_comment
comment|/* Unexpected Completion Status Status in function 6, \ 	if set, generate pcie_err_attn output when this error is seen. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MASTER_ABRT6
define|\
value|(1<< 13)
end_define

begin_comment
comment|/* Receive UR Statusin function 6. If set, generate \ 	pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_CPL_TIMEOUT6
define|\
value|(1<< 12)
end_define

begin_comment
comment|/* Completer Timeout Status Status in function 6, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_FC_PRTL6
define|\
value|(1<< 11)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status in \ 	function 6, if set, generate pcie_err_attn output when this error \ 	is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_PSND_TLP6
define|\
value|(1<< 10)
end_define

begin_comment
comment|/* Poisoned Error Status Status in function 6, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_PRI_SIG_TARGET_ABORT5
value|(1<< 9)
end_define

begin_comment
comment|/*    WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT5
define|\
value|(1<< 8)
end_define

begin_comment
comment|/* Unsupported Request Error Status for Function 5, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_ECRC5
define|\
value|(1<< 7)
end_define

begin_comment
comment|/* ECRC Error TLP Status Status for Function 5, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MALF_TLP5
define|\
value|(1<< 6)
end_define

begin_comment
comment|/* Malformed TLP Status Status for Function 5, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_RX_OFLOW5
define|\
value|(1<< 5)
end_define

begin_comment
comment|/* Receiver Overflow Status Status for Function 5, if \ 	set, generate pcie_err_attn output when this error is seen.. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_UNEXP_CPL5
define|\
value|(1<< 4)
end_define

begin_comment
comment|/* Unexpected Completion Status Status for Function 5, \ 	if set, generate pcie_err_attn output when this error is seen. WC \ 	*/
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_MASTER_ABRT5
define|\
value|(1<< 3)
end_define

begin_comment
comment|/* Receive UR Statusfor Function 5. If set, generate \ 	pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_CPL_TIMEOUT5
define|\
value|(1<< 2)
end_define

begin_comment
comment|/* Completer Timeout Status Status for Function 5, if \ 	set, generate pcie_err_attn output when this error is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_FC_PRTL5
define|\
value|(1<< 1)
end_define

begin_comment
comment|/* Flow Control Protocol Error Status Status for \ 	Function 5, if set, generate pcie_err_attn output when this error \ 	is seen. WC */
end_comment

begin_define
define|#
directive|define
name|PXPCS_TL_FUNC678_STAT_ERR_PSND_TLP5
define|\
value|(1<< 0)
end_define

begin_comment
comment|/* Poisoned Error Status Status for Function 5, if set, \ 	generate pcie_err_attn output when this error is seen.. WC */
end_comment

begin_define
define|#
directive|define
name|BAR_USTRORM_INTMEM
value|0x400000
end_define

begin_define
define|#
directive|define
name|BAR_CSTRORM_INTMEM
value|0x410000
end_define

begin_define
define|#
directive|define
name|BAR_XSTRORM_INTMEM
value|0x420000
end_define

begin_define
define|#
directive|define
name|BAR_TSTRORM_INTMEM
value|0x430000
end_define

begin_comment
comment|/* for accessing the IGU in case of status block ACK */
end_comment

begin_define
define|#
directive|define
name|BAR_IGU_INTMEM
value|0x440000
end_define

begin_define
define|#
directive|define
name|BAR_DOORBELL_OFFSET
value|0x800000
end_define

begin_define
define|#
directive|define
name|BAR_ME_REGISTER
value|0x450000
end_define

begin_define
define|#
directive|define
name|ME_REG_PF_NUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ME_REG_PF_NUM
define|\
value|(7L<<ME_REG_PF_NUM_SHIFT)
end_define

begin_comment
comment|/* Relative PF Num */
end_comment

begin_define
define|#
directive|define
name|ME_REG_VF_VALID
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|ME_REG_VF_NUM_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|ME_REG_VF_NUM_MASK
value|(0x3f<<ME_REG_VF_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|ME_REG_VF_ERR
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|ME_REG_ABS_PF_NUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ME_REG_ABS_PF_NUM
define|\
value|(7L<<ME_REG_ABS_PF_NUM_SHIFT)
end_define

begin_comment
comment|/* Absolute PF Num */
end_comment

begin_define
define|#
directive|define
name|PXP_VF_ADRR_NUM_QUEUES
value|136
end_define

begin_define
define|#
directive|define
name|PXP_ADDR_QUEUE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|PXP_ADDR_REG_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_IGU_START
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_IGU_SIZE
value|(0x3000)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_IGU_END
define|\
value|((PXP_VF_ADDR_IGU_START) + (PXP_VF_ADDR_IGU_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_USDM_QUEUES_START
value|0x3000
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_USDM_QUEUES_SIZE
define|\
value|(PXP_VF_ADRR_NUM_QUEUES * PXP_ADDR_QUEUE_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_USDM_QUEUES_END
define|\
value|((PXP_VF_ADDR_USDM_QUEUES_START) + (PXP_VF_ADDR_USDM_QUEUES_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_CSDM_QUEUES_START
value|0x4100
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_CSDM_QUEUES_SIZE
define|\
value|(PXP_VF_ADRR_NUM_QUEUES * PXP_ADDR_QUEUE_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_CSDM_QUEUES_END
define|\
value|((PXP_VF_ADDR_CSDM_QUEUES_START) + (PXP_VF_ADDR_CSDM_QUEUES_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_XSDM_QUEUES_START
value|0x5200
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_XSDM_QUEUES_SIZE
define|\
value|(PXP_VF_ADRR_NUM_QUEUES * PXP_ADDR_QUEUE_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_XSDM_QUEUES_END
define|\
value|((PXP_VF_ADDR_XSDM_QUEUES_START) + (PXP_VF_ADDR_XSDM_QUEUES_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_TSDM_QUEUES_START
value|0x6300
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_TSDM_QUEUES_SIZE
define|\
value|(PXP_VF_ADRR_NUM_QUEUES * PXP_ADDR_QUEUE_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_TSDM_QUEUES_END
define|\
value|((PXP_VF_ADDR_TSDM_QUEUES_START) + (PXP_VF_ADDR_TSDM_QUEUES_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_USDM_GLOBAL_START
value|0x7400
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_USDM_GLOBAL_SIZE
value|(PXP_ADDR_REG_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_USDM_GLOBAL_END
define|\
value|((PXP_VF_ADDR_USDM_GLOBAL_START) + (PXP_VF_ADDR_USDM_GLOBAL_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_CSDM_GLOBAL_START
value|0x7600
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_CSDM_GLOBAL_SIZE
value|(PXP_ADDR_REG_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_CSDM_GLOBAL_END
define|\
value|((PXP_VF_ADDR_CSDM_GLOBAL_START) + (PXP_VF_ADDR_CSDM_GLOBAL_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_XSDM_GLOBAL_START
value|0x7800
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_XSDM_GLOBAL_SIZE
value|(PXP_ADDR_REG_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_XSDM_GLOBAL_END
define|\
value|((PXP_VF_ADDR_XSDM_GLOBAL_START) + (PXP_VF_ADDR_XSDM_GLOBAL_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_TSDM_GLOBAL_START
value|0x7a00
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_TSDM_GLOBAL_SIZE
value|(PXP_ADDR_REG_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_TSDM_GLOBAL_END
define|\
value|((PXP_VF_ADDR_TSDM_GLOBAL_START) + (PXP_VF_ADDR_TSDM_GLOBAL_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_DB_START
value|0x7c00
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_DB_SIZE
value|(0x200)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_DB_END
define|\
value|((PXP_VF_ADDR_DB_START) + (PXP_VF_ADDR_DB_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_GRC_START
value|0x7e00
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_GRC_SIZE
value|(0x200)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_GRC_END
define|\
value|((PXP_VF_ADDR_GRC_START) + (PXP_VF_ADDR_GRC_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_DORQ_START
value|(0x0)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_DORQ_SIZE
value|(0xffffffff)
end_define

begin_define
define|#
directive|define
name|PXP_VF_ADDR_DORQ_END
value|(0xffffffff)
end_define

begin_define
define|#
directive|define
name|PXP_BAR_GRC
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_TSDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_USDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_XSDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_CSDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_IGU
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_DQ
value|1
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_IGU
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_USDM_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_TSDM_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_XSDM_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_CSDM_QUEUES
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_USDM_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_TSDM_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_XSDM_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_CSDM_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_DB
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_GRC
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR_DORQ
value|1
end_define

begin_comment
comment|/* PCI CAPABILITIES*/
end_comment

begin_define
define|#
directive|define
name|PCI_CAP_PCIE
value|0x10
end_define

begin_comment
comment|/*PCIe capability ID*/
end_comment

begin_define
define|#
directive|define
name|PCIE_DEV_CAPS
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIE_DEV_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIE_DEV_CTRL_FLR
value|0x8000;
end_define

begin_define
define|#
directive|define
name|PCIE_DEV_STATUS
value|0x0A
end_define

begin_define
define|#
directive|define
name|PCI_CAP_MSIX
value|0x11
end_define

begin_comment
comment|/*MSI-X capability ID*/
end_comment

begin_define
define|#
directive|define
name|PCI_MSIX_CONTROL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCI_MSIX_TABLE_SIZE_MASK
value|0x07FF
end_define

begin_define
define|#
directive|define
name|PCI_MSIX_TABLE_ENABLE_MASK
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_CL73_IEEEB0
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB0_CL73_AN_CONTROL
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB0_CL73_AN_CONTROL_RESTART_AN
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB0_CL73_AN_CONTROL_AN_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB0_CL73_AN_CONTROL_MAIN_RST
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_CL73_IEEEB1
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1
value|0x00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1_ASYMMETRIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1_PAUSE_BOTH
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV1_PAUSE_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2
value|0x01
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2_ADVR_1000M
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2_ADVR_1000M_KX
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2_ADVR_10G_KX4
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_ADV2_ADVR_10G_KR
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1
value|0x03
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1_ASYMMETRIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1_PAUSE_BOTH
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV1_PAUSE_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_IEEEB1_AN_LP_ADV2
value|0x04
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX0
value|0x80b0
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_STATUS_SIGDET
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_STATUS_RX_SEQ_DONE
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX0_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX1
value|0x80c0
end_define

begin_define
define|#
directive|define
name|MDIO_RX1_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX1_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX1_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX2
value|0x80d0
end_define

begin_define
define|#
directive|define
name|MDIO_RX2_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX2_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX2_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX3
value|0x80e0
end_define

begin_define
define|#
directive|define
name|MDIO_RX3_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX3_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX3_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_RX_ALL
value|0x80f0
end_define

begin_define
define|#
directive|define
name|MDIO_RX_ALL_RX_EQ_BOOST
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_RX_ALL_RX_EQ_BOOST_EQUALIZER_CTRL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_RX_ALL_RX_EQ_BOOST_OFFSET_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_TX0
value|0x8060
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_MASK
value|0x000e
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_ICBUF1T
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_TX1
value|0x8070
end_define

begin_define
define|#
directive|define
name|MDIO_TX1_TX_DRIVER
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_MASK
value|0x000e
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_ICBUF1T
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_TX2
value|0x8080
end_define

begin_define
define|#
directive|define
name|MDIO_TX2_TX_DRIVER
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_MASK
value|0x000e
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_ICBUF1T
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_TX3
value|0x8090
end_define

begin_define
define|#
directive|define
name|MDIO_TX3_TX_DRIVER
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_PREEMPHASIS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IPREDRIVER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_MASK
value|0x000e
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_IFULLSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_TX0_TX_DRIVER_ICBUF1T
value|1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_XGXS_BLOCK0
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK0_XGXS_CONTROL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_XGXS_BLOCK1
value|0x8010
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK1_LANE_CTRL0
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK1_LANE_CTRL1
value|0x16
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK1_LANE_CTRL2
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_BLOCK1_LANE_PRBS
value|0x19
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_XGXS_BLOCK2
value|0x8100
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_RX_LN_SWAP
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_RX_LN_SWAP_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_RX_LN_SWAP_FORCE_ENABLE
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_TX_LN_SWAP
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_TX_LN_SWAP_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_UNICORE_MODE_10G
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_UNICORE_MODE_10G_CX4_XGXS
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_UNICORE_MODE_10G_HIGIG_XGXS
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_XGXS_BLOCK2_TEST_MODE_LANE
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_GP_STATUS
value|0x8120
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1
value|0x1B
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_AUTONEG_COMPLETE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_CL37_AUTONEG_COMPLETE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_LINK_STATUS
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_DUPLEX_STATUS
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_MR_LP_NP_AN_ABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_CL73_LP_NP_BAM_ABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_PAUSE_RSOLUTION_TXSIDE
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_PAUSE_RSOLUTION_RXSIDE
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_MASK
value|0x3f00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10M
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_100M
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_1G
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_2_5G
value|0x0300
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_5G
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_6G
value|0x0500
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_HIG
value|0x0600
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_CX4
value|0x0700
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_12G_HIG
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_12_5G
value|0x0900
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_13G
value|0x0A00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_15G
value|0x0B00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_16G
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_1G_KX
value|0x0D00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_KX4
value|0x0E00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_KR
value|0x0F00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_XFI
value|0x1B00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_20G_DXGXS
value|0x1E00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_10G_SFI
value|0x1F00
end_define

begin_define
define|#
directive|define
name|MDIO_GP_STATUS_TOP_AN_STATUS1_ACTUAL_SPEED_20G_KR2
value|0x3900
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_10G_PARALLEL_DETECT
value|0x8130
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_STATUS_PD_LINK
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_CONTROL
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_CONTROL_PARDET10G_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_LINK
value|0x13
end_define

begin_define
define|#
directive|define
name|MDIO_10G_PARALLEL_DETECT_PAR_DET_10G_LINK_CNT
value|(0xb71<<1)
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_SERDES_DIGITAL
value|0x8300
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_FIBER_MODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_TBI_IF
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_SIGNAL_DETECT_EN
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_INVERT_SIGNAL_DETECT
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_AUTODET
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL1_MSTR_MODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL2
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL2_PRL_DT_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_CONTROL2_AN_FST_TMR
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SGMII
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_LINK
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_DUPLEX
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_MASK
value|0x0018
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_2_5G
value|0x0018
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_1G
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_100M
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS1_SPEED_10M
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS2
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_A_1000X_STATUS2_AN_DISABLED
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1
value|0x18
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_MASK
value|0xE000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_25M
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_100M
value|0x2000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_125M
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_156_25M
value|0x6000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_REFCLK_SEL_187_5M
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_SEL
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_2_5G
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_5G
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_6G
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_10G_HIG
value|0x0003
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_10G_CX4
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_12G
value|0x0005
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_12_5G
value|0x0006
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_13G
value|0x0007
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_15G
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_SERDES_DIGITAL_MISC1_FORCE_SPEED_16G
value|0x0009
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_OVER_1G
value|0x8320
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_DIGCTL_3_4
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_DIGCTL_3_4_MP_ID_MASK
value|0xffe0
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_DIGCTL_3_4_MP_ID_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1
value|0x19
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_2_5G
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_5G
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_6G
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_10G
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_10GH
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_12G
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_12_5G
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_13G
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_15G
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP1_16G
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP2
value|0x1A
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP2_IPREDRIVER_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP2_IDRIVER_MASK
value|0x0038
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP2_PREEMPHASIS_MASK
value|0x03C0
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP3
value|0x1B
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_UP3_HIGIG2
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP1
value|0x1C
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP2
value|0x1D
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP2_MR_ADV_OVER_1G_MASK
value|0x03ff
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP2_PREEMPHASIS_MASK
value|0x0780
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP2_PREEMPHASIS_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MDIO_OVER_1G_LP_UP3
value|0x1E
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_REMOTE_PHY
value|0x8330
end_define

begin_define
define|#
directive|define
name|MDIO_REMOTE_PHY_MISC_RX_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_REMOTE_PHY_MISC_RX_STATUS_CL37_FSM_RECEIVED_OVER1G_MSG
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_REMOTE_PHY_MISC_RX_STATUS_CL37_FSM_RECEIVED_BRCM_OUI_MSG
value|0x0600
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_BAM_NEXT_PAGE
value|0x8350
end_define

begin_define
define|#
directive|define
name|MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL_BAM_MODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_BAM_NEXT_PAGE_MP5_NEXT_PAGE_CTRL_TETON_AN
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_CL73_USERB0
value|0x8370
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_UCTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_UCTRL_USTAT1_MUXSEL
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_USTAT1
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_USTAT1_LINK_STATUS_CHECK
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_USTAT1_AN_GOOD_CHECK_BAM37
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL1
value|0x12
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_EN
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_STATION_MNGR_EN
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL1_BAM_NP_AFTER_BP_EN
value|0x2000
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL3
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_CL73_USERB0_CL73_BAM_CTRL3_USE_CL73_HCD_MR
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_AER_BLOCK
value|0xFFD0
end_define

begin_define
define|#
directive|define
name|MDIO_AER_BLOCK_AER_REG
value|0x1E
end_define

begin_define
define|#
directive|define
name|MDIO_REG_BANK_COMBO_IEEE0
value|0xFFE0
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_MII_CONTROL
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_MASK
value|0x2040
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_100
value|0x2000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_MAN_SGMII_SP_1000
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_FULL_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_RESTART_AN
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_AN_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEO_MII_CONTROL_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_MII_STATUS
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_MII_STATUS_LINK_PASS
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_MII_STATUS_AUTONEG_COMPLETE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV
value|0x14
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_FULL_DUPLEX
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_HALF_DUPLEX
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_MASK
value|0x0180
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_SYMMETRIC
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH
value|0x0180
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_ADV_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_ACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_PAUSE_MASK
value|0x0180
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_PAUSE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_PAUSE_BOTH
value|0x0180
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_HALF_DUP_CAP
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_FULL_DUP_CAP
value|0x0020
end_define

begin_comment
comment|/*WhenthelinkpartnerisinSGMIImode(bit0=1), then bit15=link, bit12=duplex, bits11:10=speed, bit14=acknowledge. Theotherbitsarereservedandshouldbezero*/
end_comment

begin_define
define|#
directive|define
name|MDIO_COMBO_IEEE0_AUTO_NEG_LINK_PARTNER_ABILITY1_SGMII_MODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_DEVAD
value|0x1
end_define

begin_comment
comment|/*ieee*/
end_comment

begin_define
define|#
directive|define
name|MDIO_PMA_REG_CTRL
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_STATUS
value|0x1
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_10G_CTRL2
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_TX_DISABLE
value|0x0009
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_RX_SD
value|0xa
end_define

begin_comment
comment|/*bcm*/
end_comment

begin_define
define|#
directive|define
name|MDIO_PMA_REG_BCM_CTRL
value|0x0096
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_FEC_CTRL
value|0x00ab
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_LASI_RXCTRL
value|0x9000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_LASI_TXCTRL
value|0x9001
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_LASI_CTRL
value|0x9002
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_LASI_RXSTAT
value|0x9003
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_LASI_TXSTAT
value|0x9004
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_LASI_STAT
value|0x9005
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_PHY_IDENTIFIER
value|0xc800
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_DIGITAL_CTRL
value|0xc808
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_DIGITAL_STATUS
value|0xc809
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_TX_POWER_DOWN
value|0xca02
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_CMU_PLL_BYPASS
value|0xca09
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_MISC_CTRL
value|0xca0a
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_GEN_CTRL
value|0xca10
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_GEN_CTRL_ROM_RESET_INTERNAL_MP
value|0x0188
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_GEN_CTRL_ROM_MICRO_RESET
value|0x018a
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_M8051_MSGIN_REG
value|0xca12
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_M8051_MSGOUT_REG
value|0xca13
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_ROM_VER1
value|0xca19
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_ROM_VER2
value|0xca1a
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_EDC_FFE_MAIN
value|0xca1b
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_PLL_BANDWIDTH
value|0xca1d
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_PLL_CTRL
value|0xca1e
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_MISC_CTRL0
value|0xca23
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_LRM_MODE
value|0xca3f
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_CDR_BANDWIDTH
value|0xca46
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_MISC_CTRL1
value|0xca85
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_CTRL
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_CTRL_STATUS_MASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_IDLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_COMPLETE
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_IN_PROGRESS
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_STATUS_FAILED
value|0x000c
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_BYTE_CNT
value|0x8002
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_SFP_TWO_WIRE_MEM_ADDR
value|0x8003
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8726_TWO_WIRE_DATA_BUF
value|0xc820
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8726_TWO_WIRE_DATA_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8726_TX_CTRL1
value|0xca01
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8726_TX_CTRL2
value|0xca05
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TWO_WIRE_SLAVE_ADDR
value|0x8005
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TWO_WIRE_DATA_BUF
value|0x8007
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TWO_WIRE_DATA_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_MISC_CTRL
value|0x8309
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TX_CTRL1
value|0xca02
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_TX_CTRL2
value|0xca05
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_PCS_OPT_CTRL
value|0xc808
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_GPIO_CTRL
value|0xc80e
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_PCS_GP
value|0xc842
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8727_OPT_CFG_REG
value|0xc8e4
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8727_MISC_CTRL
value|0x8309
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8073_CHIP_REV
value|0xc801
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8073_SPEED_LINK_STATUS
value|0xc820
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8073_XAUI_WA
value|0xc841
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8073_OPT_DIGITAL_CTRL
value|0xcd08
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7101_RESET
value|0xc000
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7107_LED_CNTL
value|0xc007
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7107_LINK_LED_CNTL
value|0xc009
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7101_VER1
value|0xc026
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_7101_VER2
value|0xc027
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_PMD_SIGNAL
value|0xa811
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED1_MASK
value|0xa82c
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED2_MASK
value|0xa82f
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED3_MASK
value|0xa832
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED3_BLINK
value|0xa834
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LED5_MASK
value|0xa838
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_SIGNAL_MASK
value|0xa835
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LINK_SIGNAL
value|0xa83b
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LINK_SIGNAL_LED4_ENABLE_MASK
value|0x800
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_8481_LINK_SIGNAL_LED4_ENABLE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|MDIO_WIS_DEVAD
value|0x2
end_define

begin_comment
comment|/*bcm*/
end_comment

begin_define
define|#
directive|define
name|MDIO_WIS_REG_LASI_CNTL
value|0x9002
end_define

begin_define
define|#
directive|define
name|MDIO_WIS_REG_LASI_STATUS
value|0x9005
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_DEVAD
value|0x3
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_STATUS
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_LASI_STATUS
value|0x9005
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_DSP_ACCESS
value|0xD000
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_MUX
value|0xD008
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_CTRL_ADDR
value|0xE12A
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_RESET_BIT
value|(5)
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_FIFO_ADDR
value|0xE02A
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_FIFO_ADDR_WRITE_ENABLE_CMD
value|(6)
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_FIFO_ADDR_BULK_ERASE_CMD
value|(0xC7)
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_FIFO_ADDR_PAGE_PROGRAM_CMD
value|(2)
end_define

begin_define
define|#
directive|define
name|MDIO_PCS_REG_7101_SPI_BYTES_TO_TRANSFER_ADDR
value|0xE028
end_define

begin_define
define|#
directive|define
name|MDIO_XS_DEVAD
value|0x4
end_define

begin_define
define|#
directive|define
name|MDIO_XS_REG_STATUS
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_XS_PLL_SEQUENCER
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_XS_SFX7101_XGXS_TEST1
value|0xc00a
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RX0
value|0x80bc
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RX1
value|0x80cc
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RX2
value|0x80dc
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RX3
value|0x80ec
end_define

begin_define
define|#
directive|define
name|MDIO_XS_8706_REG_BANK_RXA
value|0x80fc
end_define

begin_define
define|#
directive|define
name|MDIO_XS_REG_8073_RX_CTRL_PCIE
value|0x80FA
end_define

begin_define
define|#
directive|define
name|MDIO_AN_DEVAD
value|0x7
end_define

begin_comment
comment|/*ieee*/
end_comment

begin_define
define|#
directive|define
name|MDIO_AN_REG_CTRL
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_STATUS
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_STATUS_AN_COMPLETE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE_ASYMMETRIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE_BOTH
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV_PAUSE_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV
value|0x0011
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_ADV2
value|0x0012
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_LP_AUTO_NEG
value|0x0013
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_LP_AUTO_NEG2
value|0x0014
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_MASTER_STATUS
value|0x0021
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_EEE_ADV
value|0x003c
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_LP_EEE_ADV
value|0x003d
end_define

begin_comment
comment|/*bcm*/
end_comment

begin_define
define|#
directive|define
name|MDIO_AN_REG_LINK_STATUS
value|0x8304
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_CL37_CL73
value|0x8370
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_CL37_AN
value|0xffe0
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_CL37_FC_LD
value|0xffe4
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_CL37_FC_LP
value|0xffe5
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_1000T_STATUS
value|0xffea
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8073_2_5G
value|0x8329
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8073_BAM
value|0x8350
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_10GBASE_T_AN_CTRL
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_MII_CTRL
value|0xffe0
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_MII_CTRL_FORCE_1G
value|0x40
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_MII_STATUS
value|0xffe1
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_AN_ADV
value|0xffe4
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_AN_EXPANSION
value|0xffe6
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_1000T_CTRL
value|0xffe9
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_1G_100T_EXT_CTRL
value|0xfff0
end_define

begin_define
define|#
directive|define
name|MIDO_AN_REG_8481_EXT_CTRL_FORCE_LEDS_OFF
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_EXPANSION_REG_RD_RW
value|0xfff5
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_EXPANSION_REG_ACCESS
value|0xfff7
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_AUX_CTRL
value|0xfff8
end_define

begin_define
define|#
directive|define
name|MDIO_AN_REG_8481_LEGACY_SHADOW
value|0xfffc
end_define

begin_comment
comment|/* BCM84823 only */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTL_DEVAD
value|0x1e
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA
value|0x401a
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_MAC_MASK
value|0x0018
end_define

begin_comment
comment|/* These pins configure the BCM84823 interface to MAC after reset. */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_CTRL_MAC_XFI
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_MAC_XAUI_M
value|0x0010
end_define

begin_comment
comment|/* These pins configure the BCM84823 interface to Line after reset. */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_LINE_MASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_LINE_XAUI_L
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_LINE_XFI
value|0x0040
end_define

begin_comment
comment|/* When this pin is active high during reset, 10GBASE-T core is power 	 * down, When it is active low the 10GBASE-T is power up 	 */
end_comment

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_COPPER_CORE_DOWN
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_PRIORITY_MASK
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_PRIORITY_COPPER
value|0x0000
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_PRIORITY_FIBER
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_MEDIA_FIBER_1G
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_USER_CTRL_REG
value|0x4005
end_define

begin_define
define|#
directive|define
name|MDIO_CTL_REG_84823_USER_CTRL_CMS
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_84823_CTL_SLOW_CLK_CNT_HIGH
value|0xa82b
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_84823_BLINK_RATE_VAL_15P9HZ
value|0x2f
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_84823_CTL_LED_CTL_1
value|0xa8e3
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_84833_CTL_LED_CTL_1
value|0xa8ec
end_define

begin_define
define|#
directive|define
name|MDIO_PMA_REG_84823_LED3_STRETCH_EN
value|0x0080
end_define

begin_comment
comment|/* BCM84833 only */
end_comment

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_FW_REV
value|0x400f
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_FW_EEE
value|0x10b1
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_FW_NO_EEE
value|0x1f81
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_XGPHY_STRAP1
value|0x401a
end_define

begin_define
define|#
directive|define
name|MDIO_84833_SUPER_ISOLATE
value|0x8000
end_define

begin_comment
comment|/* These are mailbox register set used by 84833. */
end_comment

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG0
value|0x4005
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG1
value|0x4006
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG2
value|0x4007
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG3
value|0x4008
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG4
value|0x4009
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG26
value|0x4037
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG27
value|0x4038
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG28
value|0x4039
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG29
value|0x403a
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG30
value|0x403b
end_define

begin_define
define|#
directive|define
name|MDIO_84833_TOP_CFG_SCRATCH_REG31
value|0x403c
end_define

begin_define
define|#
directive|define
name|MDIO_84833_CMD_HDLR_COMMAND
value|MDIO_84833_TOP_CFG_SCRATCH_REG0
end_define

begin_define
define|#
directive|define
name|MDIO_84833_CMD_HDLR_STATUS
value|MDIO_84833_TOP_CFG_SCRATCH_REG26
end_define

begin_define
define|#
directive|define
name|MDIO_84833_CMD_HDLR_DATA1
value|MDIO_84833_TOP_CFG_SCRATCH_REG27
end_define

begin_define
define|#
directive|define
name|MDIO_84833_CMD_HDLR_DATA2
value|MDIO_84833_TOP_CFG_SCRATCH_REG28
end_define

begin_define
define|#
directive|define
name|MDIO_84833_CMD_HDLR_DATA3
value|MDIO_84833_TOP_CFG_SCRATCH_REG29
end_define

begin_define
define|#
directive|define
name|MDIO_84833_CMD_HDLR_DATA4
value|MDIO_84833_TOP_CFG_SCRATCH_REG30
end_define

begin_define
define|#
directive|define
name|MDIO_84833_CMD_HDLR_DATA5
value|MDIO_84833_TOP_CFG_SCRATCH_REG31
end_define

begin_comment
comment|/* Mailbox command set used by 84833. */
end_comment

begin_define
define|#
directive|define
name|PHY84833_CMD_SET_PAIR_SWAP
value|0x8001
end_define

begin_define
define|#
directive|define
name|PHY84833_CMD_GET_EEE_MODE
value|0x8008
end_define

begin_define
define|#
directive|define
name|PHY84833_CMD_SET_EEE_MODE
value|0x8009
end_define

begin_define
define|#
directive|define
name|PHY84833_CMD_GET_CURRENT_TEMP
value|0x8031
end_define

begin_comment
comment|/* Mailbox status set used by 84833. */
end_comment

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_RECEIVED
value|0x0001
end_define

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_IN_PROGRESS
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_COMPLETE_PASS
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_COMPLETE_ERROR
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_OPEN_FOR_CMDS
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_SYSTEM_BOOT
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_NOT_OPEN_FOR_CMDS
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_CLEAR_COMPLETE
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY84833_STATUS_CMD_OPEN_OVERRIDE
value|0xa5a5
end_define

begin_comment
comment|/* Warpcore clause 45 addressing */
end_comment

begin_define
define|#
directive|define
name|MDIO_WC_DEVAD
value|0x3
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_IEEE0BLK_MIICNTL
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_IEEE0BLK_AUTONEGNP
value|0x7
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_AN_IEEE1BLK_AN_ADVERTISEMENT0
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_AN_IEEE1BLK_AN_ADVERTISEMENT1
value|0x11
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_AN_IEEE1BLK_AN_ADVERTISEMENT2
value|0x12
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_AN_IEEE1BLK_AN_ADV2_FEC_ABILITY
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_AN_IEEE1BLK_AN_ADV2_FEC_REQ
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_PCS_STATUS2
value|0x0021
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_PMD_KR_CONTROL
value|0x0096
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK0_XGXSCONTROL
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK0_MISCCONTROL1
value|0x800e
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK1_DESKEW
value|0x8010
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK1_LANECTRL0
value|0x8015
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK1_LANECTRL1
value|0x8016
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK1_LANECTRL2
value|0x8017
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK1_LANECTRL3
value|0x8018
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK1_LANETEST0
value|0x801a
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX0_ANA_CTRL0
value|0x8061
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX1_ANA_CTRL0
value|0x8071
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX2_ANA_CTRL0
value|0x8081
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX3_ANA_CTRL0
value|0x8091
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX0_TX_DRIVER
value|0x8067
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX0_TX_DRIVER_IPRE_DRIVER_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX0_TX_DRIVER_IPRE_DRIVER_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX0_TX_DRIVER_IDRIVER_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX0_TX_DRIVER_IDRIVER_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX0_TX_DRIVER_POST2_COEFF_OFFSET
value|0x0c
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX0_TX_DRIVER_POST2_COEFF_MASK
value|0x7000
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX1_TX_DRIVER
value|0x8077
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX2_TX_DRIVER
value|0x8087
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX3_TX_DRIVER
value|0x8097
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX0_ANARXCONTROL1G
value|0x80b9
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX2_ANARXCONTROL1G
value|0x80d9
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX0_PCI_CTRL
value|0x80ba
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX1_PCI_CTRL
value|0x80ca
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX2_PCI_CTRL
value|0x80da
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX3_PCI_CTRL
value|0x80ea
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RXB_ANA_RX_CONTROL_PCI
value|0x80fa
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXSBLK2_UNICORE_MODE_10G
value|0x8104
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXS_STATUS3
value|0x8129
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_PAR_DET_10G_STATUS
value|0x8130
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_PAR_DET_10G_CTRL
value|0x8131
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXS_STATUS4
value|0x813c
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXS_X2_CONTROL2
value|0x8141
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXS_X2_CONTROL3
value|0x8142
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXS_RX_LN_SWAP1
value|0x816B
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_XGXS_TX_LN_SWAP1
value|0x8169
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_0
value|0x81d0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_1
value|0x81d1
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_2
value|0x81d2
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_3
value|0x81d3
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_4
value|0x81d4
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_4_CL73_AN_CMPL
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_4_CL37_AN_CMPL
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_4_CL37_LP_AN_CAP
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_GP2_STATUS_GP_2_4_CL37_AN_CAP
value|0x1
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B0_DEAD_TRAP
value|0x81EE
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_VERSION
value|0x81F0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_MODE
value|0x81F2
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_LANE0_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_MODE_DEFAULT
value|0x0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_MODE_SFP_OPT_LR
value|0x1
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_MODE_SFP_DAC
value|0x2
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_MODE_SFP_XLAUI
value|0x3
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_MODE_LONG_CH_6G
value|0x4
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_LANE1_OFFSET
value|0x4
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_LANE2_OFFSET
value|0x8
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_FIRMWARE_LANE3_OFFSET
value|0xc
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_UC_INFO_B1_CRC
value|0x81FE
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DSC1B0_UC_CTRL
value|0x820e
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DSC1B0_UC_CTRL_RDY4CMD
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DSC_SMC
value|0x8213
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DSC2B0_DSC_MISC_CTRL0
value|0x821e
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX_FIR_TAP
value|0x82e2
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX_FIR_TAP_PRE_TAP_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX_FIR_TAP_PRE_TAP_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX_FIR_TAP_MAIN_TAP_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX_FIR_TAP_MAIN_TAP_MASK
value|0x03f0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX_FIR_TAP_POST_TAP_OFFSET
value|0x0a
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX_FIR_TAP_POST_TAP_MASK
value|0x7c00
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX_FIR_TAP_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL72_USERB0_CL72_TX_FIR_TAP
value|0x82e2
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL72_USERB0_CL72_MISC1_CONTROL
value|0x82e3
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL72_USERB0_CL72_OS_DEF_CTRL
value|0x82e6
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL72_USERB0_CL72_BR_DEF_CTRL
value|0x82e7
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL72_USERB0_CL72_2P5_DEF_CTRL
value|0x82e8
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL72_USERB0_CL72_MISC4_CONTROL
value|0x82ec
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_SERDESDIGITAL_CONTROL1000X1
value|0x8300
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_SERDESDIGITAL_CONTROL1000X2
value|0x8301
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_SERDESDIGITAL_CONTROL1000X3
value|0x8302
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_SERDESDIGITAL_STATUS1000X1
value|0x8304
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_SERDESDIGITAL_MISC1
value|0x8308
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_SERDESDIGITAL_MISC2
value|0x8309
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL3_UP1
value|0x8329
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL3_LP_UP1
value|0x832c
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL4_MISC3
value|0x833c
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL4_MISC5
value|0x833e
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL5_MISC6
value|0x8345
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL5_MISC7
value|0x8349
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL5_LINK_STATUS
value|0x834d
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL5_ACTUAL_SPEED
value|0x834e
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_DIGITAL6_MP5_NEXTPAGECTRL
value|0x8350
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL49_USERB0_CTRL
value|0x8368
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL73_USERB0_CTRL
value|0x8370
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL73_USERB0_USTAT
value|0x8371
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL73_BAM_CTRL1
value|0x8372
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL73_BAM_CTRL2
value|0x8373
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL73_BAM_CTRL3
value|0x8374
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL73_BAM_CODE_FIELD
value|0x837b
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_EEE_COMBO_CONTROL0
value|0x8390
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_TX66_CONTROL
value|0x83b0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_CONTROL
value|0x83c0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_SCW0
value|0x83c2
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_SCW1
value|0x83c3
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_SCW2
value|0x83c4
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_SCW3
value|0x83c5
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_SCW0_MASK
value|0x83c6
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_SCW1_MASK
value|0x83c7
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_SCW2_MASK
value|0x83c8
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_RX66_SCW3_MASK
value|0x83c9
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_FX100_CTRL1
value|0x8400
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_FX100_CTRL3
value|0x8402
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL82_USERB1_TX_CTRL5
value|0x8436
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL82_USERB1_TX_CTRL6
value|0x8437
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL82_USERB1_TX_CTRL7
value|0x8438
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL82_USERB1_TX_CTRL9
value|0x8439
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL82_USERB1_RX_CTRL10
value|0x843a
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_CL82_USERB1_RX_CTRL11
value|0x843b
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_ETA_CL73_OUI1
value|0x8453
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_ETA_CL73_OUI2
value|0x8454
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_ETA_CL73_OUI3
value|0x8455
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_ETA_CL73_LD_BAM_CODE
value|0x8456
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_ETA_CL73_LD_UD_CODE
value|0x8457
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_MICROBLK_CMD
value|0xffc2
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_MICROBLK_DL_STATUS
value|0xffc5
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_MICROBLK_CMD3
value|0xffcc
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_AERBLK_AER
value|0xffde
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_COMBO_IEEE0_MIICTRL
value|0xffe0
end_define

begin_define
define|#
directive|define
name|MDIO_WC_REG_COMBO_IEEE0_MIIISTAT
value|0xffe1
end_define

begin_define
define|#
directive|define
name|MDIO_WC0_XGXS_BLK2_LANE_RESET
value|0x810A
end_define

begin_define
define|#
directive|define
name|MDIO_WC0_XGXS_BLK2_LANE_RESET_RX_BITSHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MDIO_WC0_XGXS_BLK2_LANE_RESET_TX_BITSHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MDIO_WC0_XGXS_BLK6_XGXS_X2_CONTROL2
value|0x8141
end_define

begin_define
define|#
directive|define
name|DIGITAL5_ACTUAL_SPEED_TX_MASK
value|0x003f
end_define

begin_comment
comment|/* 54618se */
end_comment

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_MII_STATUS
value|0x1
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_PHYID_LSB
value|0x3
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_CL45_ADDR_REG
value|0xd
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_CL45_REG_WRITE
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_CL45_REG_READ
value|0xc000
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_CL45_DATA_REG
value|0xe
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_EEE_RESOLVED
value|0x803e
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_EXP_ACCESS_GATE
value|0x15
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_EXP_ACCESS
value|0x17
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_EXP_ACCESS_TOP
value|0xd00
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_EXP_TOP_2K_BUF
value|0x40
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_AUX_STATUS
value|0x19
end_define

begin_define
define|#
directive|define
name|MDIO_REG_INTR_STATUS
value|0x1a
end_define

begin_define
define|#
directive|define
name|MDIO_REG_INTR_MASK
value|0x1b
end_define

begin_define
define|#
directive|define
name|MDIO_REG_INTR_MASK_LINK_STATUS
value|(0x1<< 1)
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_SHADOW
value|0x1c
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_SHADOW_LED_SEL1
value|(0x0d<< 10)
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_SHADOW_LED_SEL2
value|(0x0e<< 10)
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_SHADOW_WR_ENA
value|(0x1<< 15)
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_SHADOW_AUTO_DET_MED
value|(0x1e<< 10)
end_define

begin_define
define|#
directive|define
name|MDIO_REG_GPHY_SHADOW_INVERT_FIB_SD
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|IGU_FUNC_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSIX
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_INT_ACK
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_PROD_UPD
value|0x0201
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_ATTN_BITS_UPD
value|0x0202
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_ATTN_BITS_SET
value|0x0203
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_ATTN_BITS_CLR
value|0x0204
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_COALESCE_NOW
value|0x0205
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_SIMD_MASK
value|0x0206
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_SIMD_NOMASK
value|0x0207
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSI_CTL
value|0x0210
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSI_ADDR_LO
value|0x0211
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSI_ADDR_HI
value|0x0212
end_define

begin_define
define|#
directive|define
name|IGU_ADDR_MSI_DATA
value|0x0213
end_define

begin_define
define|#
directive|define
name|IGU_USE_REGISTER_ustorm_type_0_sb_cleanup
value|0
end_define

begin_define
define|#
directive|define
name|IGU_USE_REGISTER_ustorm_type_1_sb_cleanup
value|1
end_define

begin_define
define|#
directive|define
name|IGU_USE_REGISTER_cstorm_type_0_sb_cleanup
value|2
end_define

begin_define
define|#
directive|define
name|IGU_USE_REGISTER_cstorm_type_1_sb_cleanup
value|3
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_INT_ACK
value|0x0
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_PROD_UPD
value|0x4
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_ATTN_BITS_UPD
value|0x8
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_ATTN_BITS_SET
value|0xc
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_ATTN_BITS_CLR
value|0x10
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_COALESCE_NOW
value|0x14
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_SIMD_MASK
value|0x18
end_define

begin_define
define|#
directive|define
name|COMMAND_REG_SIMD_NOMASK
value|0x1c
end_define

begin_define
define|#
directive|define
name|IGU_MEM_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_UPPER
value|0x007f
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_RESERVED_UPPER
value|0x01ff
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_BASE
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_UPPER
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGU_CMD_BACKWARD_COMP_PROD_UPD
value|0x0201
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_RESERVED_UPPER
value|0x03ff
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_UPPER
define|\
value|(IGU_CMD_INT_ACK_BASE + MAX_SB_PER_PATH - 1)
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_RESERVED_UPPER
value|0x04ff
end_define

begin_define
define|#
directive|define
name|IGU_CMD_E2_PROD_UPD_BASE
value|0x0500
end_define

begin_define
define|#
directive|define
name|IGU_CMD_E2_PROD_UPD_UPPER
define|\
value|(IGU_CMD_E2_PROD_UPD_BASE + MAX_SB_PER_PATH  - 1)
end_define

begin_define
define|#
directive|define
name|IGU_CMD_E2_PROD_UPD_RESERVED_UPPER
value|0x059f
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_UPD_UPPER
value|0x05a0
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_SET_UPPER
value|0x05a1
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_CLR_UPPER
value|0x05a2
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_UPPER
value|0x05a3
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_LSB_UPPER
value|0x05a4
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_MSB_UPPER
value|0x05a5
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WOMASK_UPPER
value|0x05a6
end_define

begin_define
define|#
directive|define
name|IGU_REG_RESERVED_UPPER
value|0x05ff
end_define

begin_define
define|#
directive|define
name|IGU_SEG_IDX_ATTN
value|2
end_define

begin_define
define|#
directive|define
name|IGU_SEG_IDX_DEFAULT
value|1
end_define

begin_comment
comment|/* Fields of IGU PF CONFIGRATION REGISTER */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_FUNC_EN
value|(0x1<<0)
end_define

begin_comment
comment|/* function enable	      */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_MSI_MSIX_EN
value|(0x1<<1)
end_define

begin_comment
comment|/* MSI/MSIX enable	      */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_INT_LINE_EN
value|(0x1<<2)
end_define

begin_comment
comment|/* INT enable	      */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_ATTN_BIT_EN
value|(0x1<<3)
end_define

begin_comment
comment|/* attention enable       */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_SINGLE_ISR_EN
value|(0x1<<4)
end_define

begin_comment
comment|/* single ISR mode enable */
end_comment

begin_define
define|#
directive|define
name|IGU_PF_CONF_SIMD_MODE
value|(0x1<<5)
end_define

begin_comment
comment|/* simd all ones mode     */
end_comment

begin_comment
comment|/* Fields of IGU VF CONFIGRATION REGISTER */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_FUNC_EN
value|(0x1<<0)
end_define

begin_comment
comment|/* function enable        */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_MSI_MSIX_EN
value|(0x1<<1)
end_define

begin_comment
comment|/* MSI/MSIX enable        */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_PARENT_MASK
value|(0x3<<2)
end_define

begin_comment
comment|/* Parent PF	       */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_PARENT_SHIFT
value|2
end_define

begin_comment
comment|/* Parent PF	       */
end_comment

begin_define
define|#
directive|define
name|IGU_VF_CONF_SINGLE_ISR_EN
value|(0x1<<4)
end_define

begin_comment
comment|/* single ISR mode enable */
end_comment

begin_define
define|#
directive|define
name|IGU_BC_DSB_NUM_SEGS
value|5
end_define

begin_define
define|#
directive|define
name|IGU_BC_NDSB_NUM_SEGS
value|2
end_define

begin_define
define|#
directive|define
name|IGU_NORM_DSB_NUM_SEGS
value|2
end_define

begin_define
define|#
directive|define
name|IGU_NORM_NDSB_NUM_SEGS
value|1
end_define

begin_define
define|#
directive|define
name|IGU_BC_BASE_DSB_PROD
value|128
end_define

begin_define
define|#
directive|define
name|IGU_NORM_BASE_DSB_PROD
value|136
end_define

begin_comment
comment|/* FID (if VF - [6] = 0; [5:0] = VF number; if PF - [6] = 1; \ 	[5:2] = 0; [1:0] = PF number) */
end_comment

begin_define
define|#
directive|define
name|IGU_FID_ENCODE_IS_PF
value|(0x1<<6)
end_define

begin_define
define|#
directive|define
name|IGU_FID_ENCODE_IS_PF_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|IGU_FID_VF_NUM_MASK
value|(0x3f)
end_define

begin_define
define|#
directive|define
name|IGU_FID_PF_NUM_MASK
value|(0x7)
end_define

begin_define
define|#
directive|define
name|IGU_REG_MAPPING_MEMORY_VALID
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|IGU_REG_MAPPING_MEMORY_VECTOR_MASK
value|(0x3F<<1)
end_define

begin_define
define|#
directive|define
name|IGU_REG_MAPPING_MEMORY_VECTOR_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|IGU_REG_MAPPING_MEMORY_FID_MASK
value|(0x7F<<7)
end_define

begin_define
define|#
directive|define
name|IGU_REG_MAPPING_MEMORY_FID_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|CDU_REGION_NUMBER_XCM_AG
value|2
end_define

begin_define
define|#
directive|define
name|CDU_REGION_NUMBER_UCM_AG
value|4
end_define

begin_comment
comment|/* String-to-compress [31:8] = CID (all 24 bits)  * String-to-compress [7:4] = Region  * String-to-compress [3:0] = Type  */
end_comment

begin_define
define|#
directive|define
name|CDU_VALID_DATA
parameter_list|(
name|_cid
parameter_list|,
name|_region
parameter_list|,
name|_type
parameter_list|)
define|\
value|(((_cid)<< 8) | (((_region)&0xf)<<4) | (((_type)&0xf)))
end_define

begin_define
define|#
directive|define
name|CDU_CRC8
parameter_list|(
name|_cid
parameter_list|,
name|_region
parameter_list|,
name|_type
parameter_list|)
define|\
value|(calc_crc8(CDU_VALID_DATA(_cid, _region, _type), 0xff))
end_define

begin_define
define|#
directive|define
name|CDU_RSRVD_VALUE_TYPE_A
parameter_list|(
name|_cid
parameter_list|,
name|_region
parameter_list|,
name|_type
parameter_list|)
define|\
value|(0x80 | ((CDU_CRC8(_cid, _region, _type))& 0x7f))
end_define

begin_define
define|#
directive|define
name|CDU_RSRVD_VALUE_TYPE_B
parameter_list|(
name|_crc
parameter_list|,
name|_type
parameter_list|)
define|\
value|(0x80 | ((_type)&0xf<< 3) | ((CDU_CRC8(_cid, _region, _type))& 0x7))
end_define

begin_define
define|#
directive|define
name|CDU_RSRVD_INVALIDATE_CONTEXT_VALUE
parameter_list|(
name|_val
parameter_list|)
value|((_val)& ~0x80)
end_define

begin_comment
comment|/******************************************************************************  * Description:  *	   Calculates crc 8 on a word value: polynomial 0-1-2-8  *	   Code was translated from Verilog.  * Return:  *****************************************************************************/
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|calc_crc8
parameter_list|(
name|uint32_t
name|data
parameter_list|,
name|uint8_t
name|crc
parameter_list|)
block|{
name|uint8_t
name|D
index|[
literal|32
index|]
decl_stmt|;
name|uint8_t
name|NewCRC
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|C
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|crc_res
decl_stmt|;
name|uint8_t
name|i
decl_stmt|;
comment|/* split the data into 31 bits */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
name|D
index|[
name|i
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|data
operator|&
literal|1
argument_list|)
expr_stmt|;
name|data
operator|=
name|data
operator|>>
literal|1
expr_stmt|;
block|}
comment|/* split the crc into 8 bits */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
name|C
index|[
name|i
index|]
operator|=
name|crc
operator|&
literal|1
expr_stmt|;
name|crc
operator|=
name|crc
operator|>>
literal|1
expr_stmt|;
block|}
name|NewCRC
index|[
literal|0
index|]
operator|=
name|D
index|[
literal|31
index|]
operator|^
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|23
index|]
operator|^
name|D
index|[
literal|21
index|]
operator|^
name|D
index|[
literal|19
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|8
index|]
operator|^
name|D
index|[
literal|7
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|6
index|]
operator|^
name|C
index|[
literal|7
index|]
expr_stmt|;
name|NewCRC
index|[
literal|1
index|]
operator|=
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|24
index|]
operator|^
name|D
index|[
literal|23
index|]
operator|^
name|D
index|[
literal|22
index|]
operator|^
name|D
index|[
literal|21
index|]
operator|^
name|D
index|[
literal|20
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|9
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|1
index|]
operator|^
name|D
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|5
index|]
operator|^
name|C
index|[
literal|6
index|]
expr_stmt|;
name|NewCRC
index|[
literal|2
index|]
operator|=
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|25
index|]
operator|^
name|D
index|[
literal|24
index|]
operator|^
name|D
index|[
literal|22
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|10
index|]
operator|^
name|D
index|[
literal|8
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|2
index|]
operator|^
name|D
index|[
literal|1
index|]
operator|^
name|D
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|1
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|5
index|]
expr_stmt|;
name|NewCRC
index|[
literal|3
index|]
operator|=
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|26
index|]
operator|^
name|D
index|[
literal|25
index|]
operator|^
name|D
index|[
literal|23
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|11
index|]
operator|^
name|D
index|[
literal|9
index|]
operator|^
name|D
index|[
literal|7
index|]
operator|^
name|D
index|[
literal|3
index|]
operator|^
name|D
index|[
literal|2
index|]
operator|^
name|D
index|[
literal|1
index|]
operator|^
name|C
index|[
literal|1
index|]
operator|^
name|C
index|[
literal|2
index|]
operator|^
name|C
index|[
literal|5
index|]
operator|^
name|C
index|[
literal|6
index|]
expr_stmt|;
name|NewCRC
index|[
literal|4
index|]
operator|=
name|D
index|[
literal|31
index|]
operator|^
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|27
index|]
operator|^
name|D
index|[
literal|26
index|]
operator|^
name|D
index|[
literal|24
index|]
operator|^
name|D
index|[
literal|19
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|10
index|]
operator|^
name|D
index|[
literal|8
index|]
operator|^
name|D
index|[
literal|4
index|]
operator|^
name|D
index|[
literal|3
index|]
operator|^
name|D
index|[
literal|2
index|]
operator|^
name|C
index|[
literal|0
index|]
operator|^
name|C
index|[
literal|2
index|]
operator|^
name|C
index|[
literal|3
index|]
operator|^
name|C
index|[
literal|6
index|]
operator|^
name|C
index|[
literal|7
index|]
expr_stmt|;
name|NewCRC
index|[
literal|5
index|]
operator|=
name|D
index|[
literal|31
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|27
index|]
operator|^
name|D
index|[
literal|25
index|]
operator|^
name|D
index|[
literal|20
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|11
index|]
operator|^
name|D
index|[
literal|9
index|]
operator|^
name|D
index|[
literal|5
index|]
operator|^
name|D
index|[
literal|4
index|]
operator|^
name|D
index|[
literal|3
index|]
operator|^
name|C
index|[
literal|1
index|]
operator|^
name|C
index|[
literal|3
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|7
index|]
expr_stmt|;
name|NewCRC
index|[
literal|6
index|]
operator|=
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|28
index|]
operator|^
name|D
index|[
literal|26
index|]
operator|^
name|D
index|[
literal|21
index|]
operator|^
name|D
index|[
literal|19
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|16
index|]
operator|^
name|D
index|[
literal|14
index|]
operator|^
name|D
index|[
literal|12
index|]
operator|^
name|D
index|[
literal|10
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|5
index|]
operator|^
name|D
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|2
index|]
operator|^
name|C
index|[
literal|4
index|]
operator|^
name|C
index|[
literal|5
index|]
expr_stmt|;
name|NewCRC
index|[
literal|7
index|]
operator|=
name|D
index|[
literal|30
index|]
operator|^
name|D
index|[
literal|29
index|]
operator|^
name|D
index|[
literal|27
index|]
operator|^
name|D
index|[
literal|22
index|]
operator|^
name|D
index|[
literal|20
index|]
operator|^
name|D
index|[
literal|18
index|]
operator|^
name|D
index|[
literal|17
index|]
operator|^
name|D
index|[
literal|15
index|]
operator|^
name|D
index|[
literal|13
index|]
operator|^
name|D
index|[
literal|11
index|]
operator|^
name|D
index|[
literal|7
index|]
operator|^
name|D
index|[
literal|6
index|]
operator|^
name|D
index|[
literal|5
index|]
operator|^
name|C
index|[
literal|3
index|]
operator|^
name|C
index|[
literal|5
index|]
operator|^
name|C
index|[
literal|6
index|]
expr_stmt|;
name|crc_res
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
name|crc_res
operator||=
operator|(
name|NewCRC
index|[
name|i
index|]
operator|<<
name|i
operator|)
expr_stmt|;
block|}
return|return
name|crc_res
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECORE_REG_H */
end_comment

end_unit

