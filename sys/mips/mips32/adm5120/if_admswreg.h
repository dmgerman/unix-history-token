begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: if_admswreg.h,v 1.1 2007/03/20 08:52:02 dyoung Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 Ruslan Ermilov and Vsevolod Lobko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ADMSWREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_ADMSWREG_H_
end_define

begin_define
define|#
directive|define
name|ADMSW_BOOT_DONE
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADMSW_BOOT_DONE_BO
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ADMSW_SW_RES
value|0x000c
end_define

begin_define
define|#
directive|define
name|ADMSW_SW_RES_SWR
value|__BITS(31, 0)
end_define

begin_define
define|#
directive|define
name|ADMSW_INT_ST
value|0x00b0
end_define

begin_define
define|#
directive|define
name|ADMSW_INT_MASK
value|0x00b4
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_RSVD
value|__BITS(31, 25)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_CPUH
value|__BIT(24)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_SDE
value|__BIT(23)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_RDE
value|__BIT(22)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_W1TE
value|__BIT(21)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_W0TE
value|__BIT(20)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_MI
value|__BIT(19)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_PSC
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_BCS
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_MD
value|__BIT(15)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_GQF
value|__BIT(14)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_CPQ
value|__BIT(13)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_P5QF
value|__BIT(11)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_P4QF
value|__BIT(10)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_P3QF
value|__BIT(9)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_P2QF
value|__BIT(8)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_P1QF
value|__BIT(7)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_P0QF
value|__BIT(6)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_LDF
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_HDF
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_RLD
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_RHD
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_SLD
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|ADMSW_INTR_SHD
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|ADMSW_INT_FMT
define|\
value|"\x10"\ 	"\x01SHD"\ 	"\x02SLD"\ 	"\x03RHD"\ 	"\x04RLD"\ 	"\x05HDF"\ 	"\x06LDF"\ 	"\x07P0QF"\ 	"\x08P1QF"\ 	"\x09P2QF"\ 	"\x0aP3QF"\ 	"\x0bP4QF"\ 	"\x0cP5QF"\ 	"\x0e"\ 	"CPQ"\ 	"\x0fGQF"\ 	"\x10MD"\ 	"\x11"\ 	"BCS"\ 	"\x13PSC"\ 	"\x14MI"\ 	"\x15W0TE"\ 	"\x16W1TE"\ 	"\x17RDE"\ 	"\x18SDE"\ 	"\x19"\ 	"CPUH"
end_define

begin_define
define|#
directive|define
name|CODE_REG
value|0x0000
end_define

begin_define
define|#
directive|define
name|SFTREST_REG
value|0x0004
end_define

begin_define
define|#
directive|define
name|BOOT_DONE_REG
value|0x0008
end_define

begin_define
define|#
directive|define
name|GLOBAL_ST_REG
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_ST_REG
value|0x0014
end_define

begin_define
define|#
directive|define
name|PHY_ST_LINKUP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PHY_ST_100M
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PHY_ST_FDX
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PORT_ST_REG
value|0x0018
end_define

begin_define
define|#
directive|define
name|MEM_CONTROL_REG
value|0x001C
end_define

begin_define
define|#
directive|define
name|SW_CONF_REG
value|0x0020
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_REG
value|0x0024
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_DCPUP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_CRCP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_BTM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_DUNP_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_DUNP_MASK
value|(0x3F<< CPUP_CONF_DUNP_SHIFT)
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_DMCP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_DMCP_MASK
value|(0x3F<< CPUP_CONF_DMCP_SHIFT)
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_DBCP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CPUP_CONF_DBCP_MASK
value|(0x3F<< CPUP_CONF_DBCP_SHIFT)
end_define

begin_define
define|#
directive|define
name|PORT_CONF0_REG
value|0x0028
end_define

begin_define
define|#
directive|define
name|PORT_CONF0_DP_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|PORT_CONF0_EMCP_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|PORT_CONF0_EMCP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PORT_CONF0_EMBP_MASK
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|PORT_CONF0_EMBP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PORT_CONF1_REG
value|0x002C
end_define

begin_define
define|#
directive|define
name|PORT_CONF2_REG
value|0x0030
end_define

begin_define
define|#
directive|define
name|VLAN_G1_REG
value|0x0040
end_define

begin_define
define|#
directive|define
name|VLAN_G2_REG
value|0x0044
end_define

begin_define
define|#
directive|define
name|SEND_TRIG_REG
value|0x0048
end_define

begin_define
define|#
directive|define
name|SRCH_CMD_REG
value|0x004C
end_define

begin_define
define|#
directive|define
name|ADDR_ST0_REG
value|0x0050
end_define

begin_define
define|#
directive|define
name|ADDR_ST1_REG
value|0x0054
end_define

begin_define
define|#
directive|define
name|MAC_WT0_REG
value|0x0058
end_define

begin_define
define|#
directive|define
name|MAC_WT0_WRITE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MAC_WT0_WRITE_DONE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MAC_WT0_FILTER_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MAC_WT0_VLANID_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|MAC_WT0_VLANID_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|MAC_WT0_VLANID_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MAC_WT0_PORTMAP_MASK
value|0x00001F80
end_define

begin_define
define|#
directive|define
name|MAC_WT0_PORTMAP_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MAC_WT0_AGE_MASK
value|(0x7<<	13)
end_define

begin_define
define|#
directive|define
name|MAC_WT0_AGE_STATIC
value|(0x7<<	13)
end_define

begin_define
define|#
directive|define
name|MAC_WT0_AGE_VALID
value|(0x1<<	13)
end_define

begin_define
define|#
directive|define
name|MAC_WT0_AGE_EMPTY
value|0
end_define

begin_define
define|#
directive|define
name|MAC_WT1_REG
value|0x005C
end_define

begin_define
define|#
directive|define
name|BW_CNTL0_REG
value|0x0060
end_define

begin_define
define|#
directive|define
name|BW_CNTL1_REG
value|0x0064
end_define

begin_define
define|#
directive|define
name|PHY_CNTL0_REG
value|0x0068
end_define

begin_define
define|#
directive|define
name|PHY_CNTL1_REG
value|0x006C
end_define

begin_define
define|#
directive|define
name|FC_TH_REG
value|0x0070
end_define

begin_define
define|#
directive|define
name|FC_TH_FCS_MASK
value|0x01FF0000
end_define

begin_define
define|#
directive|define
name|FC_TH_D2R_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|FC_TH_D2S_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|ADJ_PORT_TH_REG
value|0x0074
end_define

begin_define
define|#
directive|define
name|PORT_TH_REG
value|0x0078
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_REG
value|0x007C
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_AUTONEG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_ANE_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_SC_MASK
value|0x000003E0
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_SC_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_100M
value|(1<< PHY_CNTL2_SC_SHIFT)
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_DC_MASK
value|0x00007C00
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_DC_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_FDX
value|(1<< PHY_CNTL2_DC_SHIFT)
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_RFCV_MASK
value|0x000F8000
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_RFCV_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_PHYR_MASK
value|0x01F00000
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_PHYR_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_AMDIX_MASK
value|0x3E000000
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_AMDIX_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|PHY_CNTL2_RMAE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PHY_CNTL3_REG
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_CNTL3_RNT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PRI_CNTL_REG
value|0x0084
end_define

begin_define
define|#
directive|define
name|VLAN_PRI_REG
value|0x0088
end_define

begin_define
define|#
directive|define
name|TOS_EN_REG
value|0x008C
end_define

begin_define
define|#
directive|define
name|TOS_MAP0_REG
value|0x0090
end_define

begin_define
define|#
directive|define
name|TOS_MAP1_REG
value|0x0094
end_define

begin_define
define|#
directive|define
name|CUSTOM_PRI1_REG
value|0x0098
end_define

begin_define
define|#
directive|define
name|CUSTOM_PRI2_REG
value|0x009C
end_define

begin_define
define|#
directive|define
name|EMPTY_CNT_REG
value|0x00A4
end_define

begin_define
define|#
directive|define
name|PORT_CNT_SEL_REG
value|0x00A8
end_define

begin_define
define|#
directive|define
name|PORT_CNT_REG
value|0x00AC
end_define

begin_define
define|#
directive|define
name|INT_MASK
value|0x1FDEFFF
end_define

begin_define
define|#
directive|define
name|GPIO_CONF0_REG
value|0x00B8
end_define

begin_define
define|#
directive|define
name|GPIO_CONF2_REG
value|0x00BC
end_define

begin_define
define|#
directive|define
name|SWAP_IN_REG
value|0x00C8
end_define

begin_define
define|#
directive|define
name|SWAP_OUT_REG
value|0x00CC
end_define

begin_define
define|#
directive|define
name|SEND_HBADDR_REG
value|0x00D0
end_define

begin_define
define|#
directive|define
name|SEND_LBADDR_REG
value|0x00D4
end_define

begin_define
define|#
directive|define
name|RECV_HBADDR_REG
value|0x00D8
end_define

begin_define
define|#
directive|define
name|RECV_LBADDR_REG
value|0x00DC
end_define

begin_define
define|#
directive|define
name|SEND_HWADDR_REG
value|0x00E0
end_define

begin_define
define|#
directive|define
name|SEND_LWADDR_REG
value|0x00E4
end_define

begin_define
define|#
directive|define
name|RECV_HWADDR_REG
value|0x00E8
end_define

begin_define
define|#
directive|define
name|RECV_LWADDR_REG
value|0x00EC
end_define

begin_define
define|#
directive|define
name|TIMER_INT_REG
value|0x00F0
end_define

begin_define
define|#
directive|define
name|TIMER_REG
value|0x00F4
end_define

begin_define
define|#
directive|define
name|PORT0_LED_REG
value|0x0100
end_define

begin_define
define|#
directive|define
name|PORT1_LED_REG
value|0x0104
end_define

begin_define
define|#
directive|define
name|PORT2_LED_REG
value|0x0108
end_define

begin_define
define|#
directive|define
name|PORT3_LED_REG
value|0x010c
end_define

begin_define
define|#
directive|define
name|PORT4_LED_REG
value|0x0110
end_define

begin_comment
comment|/* Hardware descriptor format */
end_comment

begin_struct
struct|struct
name|admsw_desc
block|{
specifier|volatile
name|uint32_t
name|data
decl_stmt|;
specifier|volatile
name|uint32_t
name|cntl
decl_stmt|;
specifier|volatile
name|uint32_t
name|len
decl_stmt|;
specifier|volatile
name|uint32_t
name|status
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__aligned__
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|ADM5120_DMA_MASK
value|0x01ffffff
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_OWN
value|0x80000000
end_define

begin_comment
comment|/* buffer owner */
end_comment

begin_define
define|#
directive|define
name|ADM5120_DMA_RINGEND
value|0x10000000
end_define

begin_comment
comment|/* Last in DMA ring */
end_comment

begin_define
define|#
directive|define
name|ADM5120_DMA_BUF2ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_PORTID
value|0x00007000
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_PORTSHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_LEN
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_LENSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_TYPE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_TYPE_IP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_TYPE_PPPOE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_CSUM
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ADM5120_DMA_CSUMFAIL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SW_DEVS
value|6
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*	CODE_REG	*/
end_comment

begin_define
define|#
directive|define
name|CODE_ID_MASK
value|0x00FFFF
end_define

begin_define
define|#
directive|define
name|CODE_ADM5120_ID
value|0x5120
end_define

begin_define
define|#
directive|define
name|CODE_REV_MASK
value|0x0F0000
end_define

begin_define
define|#
directive|define
name|CODE_REV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CODE_REV_ADM5120_0
value|0x8
end_define

begin_define
define|#
directive|define
name|CODE_CLK_MASK
value|0x300000
end_define

begin_define
define|#
directive|define
name|CODE_CLK_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CPU_CLK_175MHZ
value|0x0
end_define

begin_define
define|#
directive|define
name|CPU_CLK_200MHZ
value|0x1
end_define

begin_define
define|#
directive|define
name|CPU_CLK_225MHZ
value|0x2
end_define

begin_define
define|#
directive|define
name|CPU_CLK_250MHZ
value|0x3
end_define

begin_define
define|#
directive|define
name|CPU_SPEED_175M
value|(175000000/2)
end_define

begin_define
define|#
directive|define
name|CPU_SPEED_200M
value|(200000000/2)
end_define

begin_define
define|#
directive|define
name|CPU_SPEED_225M
value|(225000000/2)
end_define

begin_define
define|#
directive|define
name|CPU_SPEED_250M
value|(250000000/2)
end_define

begin_define
define|#
directive|define
name|CPU_NAND_BOOT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CPU_DCACHE_2K_WAY
value|(0x1<<	25)
end_define

begin_define
define|#
directive|define
name|CPU_DCACHE_2WAY
value|(0x1<<	26)
end_define

begin_define
define|#
directive|define
name|CPU_ICACHE_2K_WAY
value|(0x1<<	27)
end_define

begin_define
define|#
directive|define
name|CPU_ICACHE_2WAY
value|(0x1<<	28)
end_define

begin_define
define|#
directive|define
name|CPU_GMII_SUPPORT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CPU_PQFP_MODE
value|(0x1<<	29)
end_define

begin_define
define|#
directive|define
name|CPU_CACHE_LINE_SIZE
value|16
end_define

begin_comment
comment|/*	SftRest_REG	*/
end_comment

begin_define
define|#
directive|define
name|SOFTWARE_RESET
value|0x1
end_define

begin_comment
comment|/*	Boot_done_REG	*/
end_comment

begin_define
define|#
directive|define
name|BOOT_DONE
value|0x1
end_define

begin_comment
comment|/*	SWReset_REG	*/
end_comment

begin_define
define|#
directive|define
name|SWITCH_RESET
value|0x1
end_define

begin_comment
comment|/*	Global_St_REG	*/
end_comment

begin_define
define|#
directive|define
name|DATA_BUF_BIST_FAILED
value|(0x1<<	0)
end_define

begin_define
define|#
directive|define
name|LINK_TAB_BIST_FAILED
value|(0x1<<	1)
end_define

begin_define
define|#
directive|define
name|MC_TAB_BIST_FAILED
value|(0x1<<	2)
end_define

begin_define
define|#
directive|define
name|ADDR_TAB_BIST_FAILED
value|(0x1<<	3)
end_define

begin_define
define|#
directive|define
name|DCACHE_D_FAILED
value|(0x3<<	4)
end_define

begin_define
define|#
directive|define
name|DCACHE_T_FAILED
value|(0x1<<	6)
end_define

begin_define
define|#
directive|define
name|ICACHE_D_FAILED
value|(0x3<<	7)
end_define

begin_define
define|#
directive|define
name|ICACHE_T_FAILED
value|(0x1<<	9)
end_define

begin_define
define|#
directive|define
name|BIST_FAILED_MASK
value|0x03FF
end_define

begin_define
define|#
directive|define
name|ALLMEM_TEST_DONE
value|(0x1<<	10)
end_define

begin_define
define|#
directive|define
name|SKIP_BLK_CNT_MASK
value|0x1FF000
end_define

begin_define
define|#
directive|define
name|SKIP_BLK_CNT_SHIFT
value|12
end_define

begin_comment
comment|/*	PHY_st_REG	*/
end_comment

begin_define
define|#
directive|define
name|PORT_LINK_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|PORT_MII_LINKFAIL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PORT_SPEED_MASK
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|PORT_GMII_SPD_MASK
value|0x00006000
end_define

begin_define
define|#
directive|define
name|PORT_GMII_SPD_10M
value|0
end_define

begin_define
define|#
directive|define
name|PORT_GMII_SPD_100M
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PORT_GMII_SPD_1000M
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PORT_DUPLEX_MASK
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|PORT_FLOWCTRL_MASK
value|0x1F000000
end_define

begin_define
define|#
directive|define
name|PORT_GMII_FLOWCTRL_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|PORT_GMII_FC_ON
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PORT_GMII_RXFC_ON
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PORT_GMII_TXFC_ON
value|0x40000000
end_define

begin_comment
comment|/*	Port_st_REG	*/
end_comment

begin_define
define|#
directive|define
name|PORT_SECURE_ST_MASK
value|0x001F
end_define

begin_define
define|#
directive|define
name|MII_PORT_TXC_ERR
value|0x0080
end_define

begin_comment
comment|/*	Mem_control_REG	*/
end_comment

begin_define
define|#
directive|define
name|SDRAM_SIZE_4MBYTES
value|0x0001
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_8MBYTES
value|0x0002
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_16MBYTES
value|0x0003
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_64MBYTES
value|0x0004
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_128MBYTES
value|0x0005
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|MEMCNTL_SDRAM1_EN
value|(0x1<<	5)
end_define

begin_define
define|#
directive|define
name|ROM_SIZE_DISABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ROM_SIZE_512KBYTES
value|0x0001
end_define

begin_define
define|#
directive|define
name|ROM_SIZE_1MBYTES
value|0x0002
end_define

begin_define
define|#
directive|define
name|ROM_SIZE_2MBYTES
value|0x0003
end_define

begin_define
define|#
directive|define
name|ROM_SIZE_4MBYTES
value|0x0004
end_define

begin_define
define|#
directive|define
name|ROM_SIZE_8MBYTES
value|0x0005
end_define

begin_define
define|#
directive|define
name|ROM_SIZE_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|ROM0_SIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ROM1_SIZE_SHIFT
value|16
end_define

begin_comment
comment|/*	SW_conf_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_AGE_TIMER_MASK
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_FAST
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_300SEC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_600SEC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_1200SEC
value|0x00000030
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_2400SEC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_4800SEC
value|0x00000050
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_9600SEC
value|0x00000060
end_define

begin_define
define|#
directive|define
name|SW_AGE_TIMER_19200SEC
value|0x00000070
end_define

begin_comment
comment|//#define	SW_AGE_TIMER_38400SEC	0x00000070
end_comment

begin_define
define|#
directive|define
name|SW_BC_PREV_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|SW_BC_PREV_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|SW_BC_PREV_64BC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SW_BC_PREV_48BC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SW_BC_PREV_32BC
value|0x00000300
end_define

begin_define
define|#
directive|define
name|SW_MAX_LEN_MASK
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|SW_MAX_LEN_1536
value|0
end_define

begin_define
define|#
directive|define
name|SW_MAX_LEN_1522
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SW_MAX_LEN_1518
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SW_DIS_COLABT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SW_HASH_ALG_MASK
value|0x00006000
end_define

begin_define
define|#
directive|define
name|SW_HASH_ALG_DIRECT
value|0
end_define

begin_define
define|#
directive|define
name|SW_HASH_ALG_XOR48
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SW_HASH_ALG_XOR32
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SW_DISABLE_BACKOFF_TIMER
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SW_BP_NUM_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|SW_BP_NUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SW_BP_MODE_MASK
value|0x00300000
end_define

begin_define
define|#
directive|define
name|SW_BP_MODE_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|SW_BP_MODE_JAM
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SW_BP_MODE_JAMALL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SW_BP_MODE_CARRIER
value|0x00300000
end_define

begin_define
define|#
directive|define
name|SW_RESRV_MC_FILTER
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SW_BISR_DISABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SW_DIS_MII_WAS_TX
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SW_BISS_EN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SW_BISS_TH_MASK
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|SW_BISS_TH_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|SW_REQ_LATENCY_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|SW_REQ_LATENCY_SHIFT
value|28
end_define

begin_comment
comment|/*	CPUp_conf_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_CPU_PORT_DISABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SW_PADING_CRC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SW_BRIDGE_MODE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SW_DIS_UN_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|SW_DIS_UN_MASK
value|(0x3F<<	SW_DIS_UN_SHIFT)
end_define

begin_define
define|#
directive|define
name|SW_DIS_MC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SW_DIS_MC_MASK
value|(0x3F<<	SW_DIS_MC_SHIFT)
end_define

begin_define
define|#
directive|define
name|SW_DIS_BC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SW_DIS_BC_MASK
value|(0x3F<<	SW_DIS_BC_SHIFT)
end_define

begin_comment
comment|/*	Port_conf0_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_DISABLE_PORT_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|SW_EN_MC_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|SW_EN_MC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SW_EN_BP_MASK
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|SW_EN_BP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SW_EN_FC_MASK
value|0x3F000000
end_define

begin_define
define|#
directive|define
name|SW_EN_FC_SHIFT
value|24
end_define

begin_comment
comment|/*	Port_conf1_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_DIS_SA_LEARN_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|SW_PORT_BLOCKING_MASK
value|0x00000FC0
end_define

begin_define
define|#
directive|define
name|SW_PORT_BLOCKING_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|SW_PORT_BLOCKING_ON
value|0x1
end_define

begin_define
define|#
directive|define
name|SW_PORT_BLOCKING_MODE_MASK
value|0x0003F000
end_define

begin_define
define|#
directive|define
name|SW_PORT_BLOCKING_MODE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SW_PORT_BLOCKING_CTRLONLY
value|0x1
end_define

begin_define
define|#
directive|define
name|SW_EN_PORT_AGE_MASK
value|0x03F00000
end_define

begin_define
define|#
directive|define
name|SW_EN_PORT_AGE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|SW_EN_SA_SECURED_MASK
value|0xFC000000
end_define

begin_define
define|#
directive|define
name|SW_EN_SA_SECURED_SHIFT
value|26
end_define

begin_comment
comment|/*	Port_conf2_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_GMII_AN_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SW_GMII_FORCE_SPD_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|SW_GMII_FORCE_SPD_10M
value|0
end_define

begin_define
define|#
directive|define
name|SW_GMII_FORCE_SPD_100M
value|0x2
end_define

begin_define
define|#
directive|define
name|SW_GMII_FORCE_SPD_1000M
value|0x4
end_define

begin_define
define|#
directive|define
name|SW_GMII_FORCE_FULL_DUPLEX
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SW_GMII_FORCE_RXFC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SW_GMII_FORCE_TXFC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SW_GMII_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SW_GMII_REVERSE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SW_GMII_TXC_CHECK_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SW_LED_FLASH_TIME_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|SW_LED_FLASH_TIME_30MS
value|0
end_define

begin_define
define|#
directive|define
name|SW_LED_FLASH_TIME_60MS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SW_LED_FLASH_TIME_240MS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SW_LED_FLASH_TIME_480MS
value|0x00030000
end_define

begin_comment
comment|/*	Send_trig_REG	*/
end_comment

begin_define
define|#
directive|define
name|SEND_TRIG_LOW
value|0x0001
end_define

begin_define
define|#
directive|define
name|SEND_TRIG_HIGH
value|0x0002
end_define

begin_comment
comment|/*	Srch_cmd_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_MAC_SEARCH_START
value|0x000001
end_define

begin_define
define|#
directive|define
name|SW_MAX_SEARCH_AGAIN
value|0x000002
end_define

begin_comment
comment|/*	MAC_wt0_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_MAC_WRITE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SW_MAC_WRITE_DONE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SW_MAC_FILTER_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SW_MAC_VLANID_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SW_MAC_VLANID_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|SW_MAC_VLANID_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SW_MAC_PORTMAP_MASK
value|0x00001F80
end_define

begin_define
define|#
directive|define
name|SW_MAC_PORTMAP_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|SW_MAC_AGE_MASK
value|(0x7<<	13)
end_define

begin_define
define|#
directive|define
name|SW_MAC_AGE_STATIC
value|(0x7<<	13)
end_define

begin_define
define|#
directive|define
name|SW_MAC_AGE_VALID
value|(0x1<<	13)
end_define

begin_define
define|#
directive|define
name|SW_MAC_AGE_EMPTY
value|0
end_define

begin_comment
comment|/*	BW_cntl0_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_PORT_TX_NOLIMIT
value|0
end_define

begin_define
define|#
directive|define
name|SW_PORT_TX_64K
value|1
end_define

begin_define
define|#
directive|define
name|SW_PORT_TX_128K
value|2
end_define

begin_define
define|#
directive|define
name|SW_PORT_TX_256K
value|3
end_define

begin_define
define|#
directive|define
name|SW_PORT_TX_512K
value|4
end_define

begin_define
define|#
directive|define
name|SW_PORT_TX_1M
value|5
end_define

begin_define
define|#
directive|define
name|SW_PORT_TX_4M
value|6
end_define

begin_define
define|#
directive|define
name|SW_PORT_TX_10MK
value|7
end_define

begin_comment
comment|/*	BW_cntl1_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_TRAFFIC_SHAPE_IPG
value|(0x1<<	31)
end_define

begin_comment
comment|/*	PHY_cntl0_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_PHY_ADDR_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|PHY_ADDR_MAX
value|0x1f
end_define

begin_define
define|#
directive|define
name|SW_PHY_REG_ADDR_MASK
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|SW_PHY_REG_ADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PHY_REG_ADDR_MAX
value|0x1f
end_define

begin_define
define|#
directive|define
name|SW_PHY_WRITE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SW_PHY_READ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SW_PHY_WDATA_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|SW_PHY_WDATA_SHIFT
value|16
end_define

begin_comment
comment|/*	PHY_cntl1_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_PHY_WRITE_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SW_PHY_READ_DONE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SW_PHY_RDATA_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|SW_PHY_RDATA_SHIFT
value|16
end_define

begin_comment
comment|/*	FC_th_REG	*/
end_comment

begin_comment
comment|/*	Adj_port_th_REG	*/
end_comment

begin_comment
comment|/*	Port_th_REG	*/
end_comment

begin_comment
comment|/*	PHY_cntl2_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_PHY_AN_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|SW_PHY_SPD_MASK
value|0x000003E0
end_define

begin_define
define|#
directive|define
name|SW_PHY_SPD_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|SW_PHY_DPX_MASK
value|0x00007C00
end_define

begin_define
define|#
directive|define
name|SW_PHY_DPX_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|SW_FORCE_FC_MASK
value|0x000F8000
end_define

begin_define
define|#
directive|define
name|SW_FORCE_FC_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|SW_PHY_NORMAL_MASK
value|0x01F00000
end_define

begin_define
define|#
directive|define
name|SW_PHY_NORMAL_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|SW_PHY_AUTOMDIX_MASK
value|0x3E000000
end_define

begin_define
define|#
directive|define
name|SW_PHY_AUTOMDIX_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|SW_PHY_REC_MCCAVERAGE
value|0x40000000
end_define

begin_comment
comment|/*	PHY_cntl3_REG	*/
end_comment

begin_comment
comment|/*	Pri_cntl_REG	*/
end_comment

begin_comment
comment|/*	VLAN_pri_REG	*/
end_comment

begin_comment
comment|/*	TOS_en_REG	*/
end_comment

begin_comment
comment|/*	TOS_map0_REG	*/
end_comment

begin_comment
comment|/*	TOS_map1_REG	*/
end_comment

begin_comment
comment|/*	Custom_pri1_REG	*/
end_comment

begin_comment
comment|/*	Custom_pri2_REG	*/
end_comment

begin_comment
comment|/*	Empty_cnt_REG	*/
end_comment

begin_comment
comment|/*	Port_cnt_sel_REG	*/
end_comment

begin_comment
comment|/*	Port_cnt_REG	*/
end_comment

begin_comment
comment|/*	SW_Int_st_REG&	SW_Int_mask_REG	*/
end_comment

begin_define
define|#
directive|define
name|SEND_H_DONE_INT
value|0x0000001
end_define

begin_define
define|#
directive|define
name|SEND_L_DONE_INT
value|0x0000002
end_define

begin_define
define|#
directive|define
name|RX_H_DONE_INT
value|0x0000004
end_define

begin_define
define|#
directive|define
name|RX_L_DONE_INT
value|0x0000008
end_define

begin_define
define|#
directive|define
name|RX_H_DESC_FULL_INT
value|0x0000010
end_define

begin_define
define|#
directive|define
name|RX_L_DESC_FULL_INT
value|0x0000020
end_define

begin_define
define|#
directive|define
name|PORT0_QUE_FULL_INT
value|0x0000040
end_define

begin_define
define|#
directive|define
name|PORT1_QUE_FULL_INT
value|0x0000080
end_define

begin_define
define|#
directive|define
name|PORT2_QUE_FULL_INT
value|0x0000100
end_define

begin_define
define|#
directive|define
name|PORT3_QUE_FULL_INT
value|0x0000200
end_define

begin_define
define|#
directive|define
name|PORT4_QUE_FULL_INT
value|0x0000400
end_define

begin_define
define|#
directive|define
name|PORT5_QUE_FULL_INT
value|0x0000800
end_define

begin_define
define|#
directive|define
name|CPU_QUE_FULL_INT
value|0x0002000
end_define

begin_define
define|#
directive|define
name|GLOBAL_QUE_FULL_INT
value|0x0004000
end_define

begin_define
define|#
directive|define
name|MUST_DROP_INT
value|0x0008000
end_define

begin_define
define|#
directive|define
name|BC_STORM_INT
value|0x0010000
end_define

begin_define
define|#
directive|define
name|PORT_STATUS_CHANGE_INT
value|0x0040000
end_define

begin_define
define|#
directive|define
name|INTRUDER_INT
value|0x0080000
end_define

begin_define
define|#
directive|define
name|WATCHDOG0_EXPR_INT
value|0x0100000
end_define

begin_define
define|#
directive|define
name|WATCHDOG1_EXPR_INT
value|0x0200000
end_define

begin_define
define|#
directive|define
name|RX_DESC_ERR_INT
value|0x0400000
end_define

begin_define
define|#
directive|define
name|SEND_DESC_ERR_INT
value|0x0800000
end_define

begin_define
define|#
directive|define
name|CPU_HOLD_INT
value|0x1000000
end_define

begin_define
define|#
directive|define
name|SWITCH_INT_MASK
value|0x1FDEFFF
end_define

begin_comment
comment|/*	GPIO_conf0_REG	*/
end_comment

begin_define
define|#
directive|define
name|GPIO0_INPUT_MODE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GPIO1_INPUT_MODE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GPIO2_INPUT_MODE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GPIO3_INPUT_MODE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GPIO4_INPUT_MODE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GPIO5_INPUT_MODE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GPIO6_INPUT_MODE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GPIO7_INPUT_MODE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|GPIO0_OUTPUT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO1_OUTPUT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO2_OUTPUT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO3_OUTPUT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO4_OUTPUT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO5_OUTPUT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO6_OUTPUT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO7_OUTPUT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|GPIO0_INPUT_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|GPIO1_INPUT_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|GPIO2_INPUT_MASK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|GPIO3_INPUT_MASK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|GPIO4_INPUT_MASK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|GPIO5_INPUT_MASK
value|0x00002000
end_define

begin_define
define|#
directive|define
name|GPIO6_INPUT_MASK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|GPIO7_INPUT_MASK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|GPIO0_OUTPUT_EN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|GPIO1_OUTPUT_EN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GPIO2_OUTPUT_EN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|GPIO3_OUTPUT_EN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|GPIO4_OUTPUT_EN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|GPIO5_OUTPUT_EN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|GPIO6_OUTPUT_EN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|GPIO7_OUTPUT_EN
value|0x00800000
end_define

begin_define
define|#
directive|define
name|GPIO_CONF0_OUTEN_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|GPIO0_OUTPUT_HI
value|0x01000000
end_define

begin_define
define|#
directive|define
name|GPIO1_OUTPUT_HI
value|0x02000000
end_define

begin_define
define|#
directive|define
name|GPIO2_OUTPUT_HI
value|0x04000000
end_define

begin_define
define|#
directive|define
name|GPIO3_OUTPUT_HI
value|0x08000000
end_define

begin_define
define|#
directive|define
name|GPIO4_OUTPUT_HI
value|0x10000000
end_define

begin_define
define|#
directive|define
name|GPIO5_OUTPUT_HI
value|0x20000000
end_define

begin_define
define|#
directive|define
name|GPIO6_OUTPUT_HI
value|0x40000000
end_define

begin_define
define|#
directive|define
name|GPIO7_OUTPUT_HI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|GPIO0_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|GPIO1_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|GPIO2_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|GPIO3_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|GPIO4_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|GPIO5_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|GPIO6_OUTPUT_LOW
value|0
end_define

begin_define
define|#
directive|define
name|GPIO7_OUTPUT_LOW
value|0
end_define

begin_comment
comment|/*	GPIO_conf2_REG	*/
end_comment

begin_define
define|#
directive|define
name|EXTIO_WAIT_EN
value|(0x1<<	6)
end_define

begin_define
define|#
directive|define
name|EXTIO_CS1_INT1_EN
value|(0x1<<	5)
end_define

begin_define
define|#
directive|define
name|EXTIO_CS0_INT0_EN
value|(0x1<<	4)
end_define

begin_comment
comment|/*	Timer_int_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_TIMER_INT_DISABLE
value|0x10000
end_define

begin_define
define|#
directive|define
name|SW_TIMER_INT
value|0x1
end_define

begin_comment
comment|/*	Timer_REG	*/
end_comment

begin_define
define|#
directive|define
name|SW_TIMER_EN
value|0x10000
end_define

begin_define
define|#
directive|define
name|SW_TIMER_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|SW_TIMER_10MS_TICKS
value|0x3D09
end_define

begin_define
define|#
directive|define
name|SW_TIMER_1MS_TICKS
value|0x61A
end_define

begin_define
define|#
directive|define
name|SW_TIMER_100US_TICKS
value|0x9D
end_define

begin_comment
comment|/*	Port0_LED_REG,	Port1_LED_REG,	Port2_LED_REG,	Port3_LED_REG,	Port4_LED_REG*/
end_comment

begin_define
define|#
directive|define
name|GPIOL_INPUT_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|GPIOL_OUTPUT_FLASH
value|0x01
end_define

begin_define
define|#
directive|define
name|GPIOL_OUTPUT_LOW
value|0x02
end_define

begin_define
define|#
directive|define
name|GPIOL_OUTPUT_HIGH
value|0x03
end_define

begin_define
define|#
directive|define
name|GPIOL_LINK_LED
value|0x04
end_define

begin_define
define|#
directive|define
name|GPIOL_SPEED_LED
value|0x05
end_define

begin_define
define|#
directive|define
name|GPIOL_DUPLEX_LED
value|0x06
end_define

begin_define
define|#
directive|define
name|GPIOL_ACT_LED
value|0x07
end_define

begin_define
define|#
directive|define
name|GPIOL_COL_LED
value|0x08
end_define

begin_define
define|#
directive|define
name|GPIOL_LINK_ACT_LED
value|0x09
end_define

begin_define
define|#
directive|define
name|GPIOL_DUPLEX_COL_LED
value|0x0A
end_define

begin_define
define|#
directive|define
name|GPIOL_10MLINK_ACT_LED
value|0x0B
end_define

begin_define
define|#
directive|define
name|GPIOL_100MLINK_ACT_LED
value|0x0C
end_define

begin_define
define|#
directive|define
name|GPIOL_CTRL_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|GPIOL_INPUT_MASK
value|0x7000
end_define

begin_define
define|#
directive|define
name|GPIOL_INPUT_0_MASK
value|0x1000
end_define

begin_define
define|#
directive|define
name|GPIOL_INPUT_1_MASK
value|0x2000
end_define

begin_define
define|#
directive|define
name|GPIOL_INPUT_2_MASK
value|0x4000
end_define

begin_define
define|#
directive|define
name|PORT_LED0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PORT_LED1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PORT_LED2_SHIFT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_ADMSWREG_H_ */
end_comment

end_unit

