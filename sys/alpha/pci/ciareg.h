begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: ciareg.h,v 1.22 1998/06/06 20:40:14 thorpej Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Chris G. Demetriou, Jason R. Thorpe  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * 21171 Chipset registers and constants.  *  * Taken from EC-QE18B-TE.  */
end_comment

begin_define
define|#
directive|define
name|REGVAL
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int32_t *)ALPHA_PHYS_TO_K0SEG(r))
end_define

begin_define
define|#
directive|define
name|REGVAL64
parameter_list|(
name|r
parameter_list|)
value|(*(volatile u_int64_t *)ALPHA_PHYS_TO_K0SEG(r))
end_define

begin_comment
comment|/*  * Base addresses  */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_SMEM1
value|0x8000000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_SMEM2
value|0x8400000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_SMEM3
value|0x8500000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_SIO1
value|0x8580000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_SIO2
value|0x85c0000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_DENSE
value|0x8600000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_CONF
value|0x8700000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_IACK
value|0x8720000000UL
end_define

begin_define
define|#
directive|define
name|CIA_CSRS
value|0x8740000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_MC_CSRS
value|0x8750000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_ATRANS
value|0x8760000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_TBIA
value|0x8760000100UL
end_define

begin_define
define|#
directive|define
name|CIA_EV56_BWMEM
value|0x8800000000UL
end_define

begin_define
define|#
directive|define
name|CIA_EV56_BWIO
value|0x8900000000UL
end_define

begin_define
define|#
directive|define
name|CIA_EV56_BWCONF0
value|0x8a00000000UL
end_define

begin_define
define|#
directive|define
name|CIA_EV56_BWCONF1
value|0x8b00000000UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_W0BASE
value|0x8760000400UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_W0MASK
value|0x8760000440UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_T0BASE
value|0x8760000480UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_W1BASE
value|0x8760000500UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_W1MASK
value|0x8760000540UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_T1BASE
value|0x8760000580UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_W2BASE
value|0x8760000600UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_W2MASK
value|0x8760000640UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_T2BASE
value|0x8760000680UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_W3BASE
value|0x8760000700UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_W3MASK
value|0x8760000740UL
end_define

begin_define
define|#
directive|define
name|CIA_PCI_T3BASE
value|0x8760000780UL
end_define

begin_define
define|#
directive|define
name|PYXIS_INT_REQ
value|0x87a0000000UL
end_define

begin_define
define|#
directive|define
name|PYXIS_INT_MASK
value|0x87a0000040UL
end_define

begin_define
define|#
directive|define
name|PYXIS_GPO
value|0x87a0000180UL
end_define

begin_comment
comment|/*  * Values for CIA_PCI_TBIA  */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_TBIA_NOOP
value|0
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_TBIA_LOCKED
value|1
end_define

begin_comment
comment|/* invalidate and unlock locked tags */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_TBIA_UNLOCKED
value|2
end_define

begin_comment
comment|/* invalidate unlocked tags */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_TBIA_ALL
value|3
end_define

begin_comment
comment|/* invalidate and unlock all tags */
end_comment

begin_define
define|#
directive|define
name|CIA_TLB_NTAGS
value|8
end_define

begin_comment
comment|/* number of TLB entries */
end_comment

begin_comment
comment|/*  * Values for CIA_PCI_WnBASE  */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_WnBASE_W_BASE
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnBASE_DAC_EN
value|0x00000008
end_define

begin_comment
comment|/* W3BASE only */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_WnBASE_MEMCS_EN
value|0x00000004
end_define

begin_comment
comment|/* W0BASE only */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_WnBASE_SG_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnBASE_W_EN
value|0x00000001
end_define

begin_comment
comment|/*  * Values for CIA_PCI_WnMASK  */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_W_MASK
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_1M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_2M
value|0x00100000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_4M
value|0x00300000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_8M
value|0x00700000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_16M
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_32M
value|0x01f00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_64M
value|0x03f00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_128M
value|0x07f00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_256M
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_512M
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_1G
value|0x3ff00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_2G
value|0x7ff00000
end_define

begin_define
define|#
directive|define
name|CIA_PCI_WnMASK_4G
value|0xfff00000
end_define

begin_comment
comment|/*  * Values for CIA_PCI_TnBASE  */
end_comment

begin_define
define|#
directive|define
name|CIA_PCI_TnBASE_MASK
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|CIA_PCI_TnBASE_SHIFT
value|2
end_define

begin_comment
comment|/*  * General CSRs  */
end_comment

begin_define
define|#
directive|define
name|CIA_CSR_REV
value|(CIA_CSRS + 0x80)
end_define

begin_define
define|#
directive|define
name|REV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|REV_ALT_MEM
value|0x00000100
end_define

begin_comment
comment|/* not on Pyxis */
end_comment

begin_define
define|#
directive|define
name|REV_PYXIS_ID_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|REV_PYXIS_ID_21174
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CIA_CSR_CTRL
value|(CIA_CSRS + 0x100)
end_define

begin_define
define|#
directive|define
name|CTRL_RCI_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CTRL_PCI_LOCK_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CTRL_PCI_LOOP_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CTRL_FST_BB_EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CTRL_PCI_MST_EN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CTRL_PCI_MEM_EN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CTRL_PCI_REQ64_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CTRL_PCI_ACK64_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CTRL_ADDR_PE_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CTRL_PERR_EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CTRL_FILL_ERR_EN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CTRL_ECC_CHK_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CTRL_CACK_EN_PE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CTRL_CON_IDLE_BC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CTRL_CSR_IOA_BYPASS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CTRL_IO_FLUSHREQ_EN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CTRL_CPU_CLUSHREQ_EN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CTRL_ARB_EV5_EN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CTRL_EN_ARB_LINK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CTRL_RD_TYPE
value|0x00300000
end_define

begin_define
define|#
directive|define
name|CTRL_RL_TYPE
value|0x03000000
end_define

begin_define
define|#
directive|define
name|CTRL_RM_TYPE
value|0x30000000
end_define

begin_comment
comment|/* a.k.a. CIA_CSR_PYXIS_CTRL1 */
end_comment

begin_define
define|#
directive|define
name|CIA_CSR_CNFG
value|(CIA_CSRS + 0x140)
end_define

begin_define
define|#
directive|define
name|CNFG_BWEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CNFG_MWEN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CNFG_DWEN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CNFG_WLEN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CIA_CSR_CNFG_BITS
value|"\20\11WLEN\6DWEN\5MWEN\1BWEN"
end_define

begin_define
define|#
directive|define
name|CIA_CSR_HAE_MEM
value|(CIA_CSRS + 0x400)
end_define

begin_define
define|#
directive|define
name|HAE_MEM_REG1_START
parameter_list|(
name|x
parameter_list|)
value|(((u_int32_t)(x)& 0xe0000000UL)<< 0)
end_define

begin_define
define|#
directive|define
name|HAE_MEM_REG1_MASK
value|0x1fffffffUL
end_define

begin_define
define|#
directive|define
name|HAE_MEM_REG2_START
parameter_list|(
name|x
parameter_list|)
value|(((u_int32_t)(x)& 0x0000f800UL)<< 16)
end_define

begin_define
define|#
directive|define
name|HAE_MEM_REG2_MASK
value|0x07ffffffUL
end_define

begin_define
define|#
directive|define
name|HAE_MEM_REG3_START
parameter_list|(
name|x
parameter_list|)
value|(((u_int32_t)(x)& 0x000000fcUL)<< 24)
end_define

begin_define
define|#
directive|define
name|HAE_MEM_REG3_MASK
value|0x03ffffffUL
end_define

begin_define
define|#
directive|define
name|CIA_CSR_HAE_IO
value|(CIA_CSRS + 0x440)
end_define

begin_define
define|#
directive|define
name|HAE_IO_REG1_START
parameter_list|(
name|x
parameter_list|)
value|0UL
end_define

begin_define
define|#
directive|define
name|HAE_IO_REG1_MASK
value|0x01ffffffUL
end_define

begin_define
define|#
directive|define
name|HAE_IO_REG2_START
parameter_list|(
name|x
parameter_list|)
value|(((u_int32_t)(x)& 0xfe000000UL)<< 0)
end_define

begin_define
define|#
directive|define
name|HAE_IO_REG2_MASK
value|0x01ffffffUL
end_define

begin_define
define|#
directive|define
name|CIA_CSR_CFG
value|(CIA_CSRS + 0x480)
end_define

begin_define
define|#
directive|define
name|CFG_CFG_MASK
value|0x00000003UL
end_define

begin_define
define|#
directive|define
name|CIA_CSR_CIA_ERR
value|(CIA_CSRS + 0x8200)
end_define

begin_define
define|#
directive|define
name|CIA_ERR_COR_ERR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CIA_ERR_UN_COR_ERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CIA_ERR_CPU_PE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CIA_ERR_MEM_NEM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CIA_ERR_PCI_SERR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CIA_ERR_PERR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CIA_ERR_PCI_ADDR_PE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CIA_ERR_RCVD_MAS_ABT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CIA_ERR_RCVD_TAR_ABT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CIA_ERR_PA_PTE_INV
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CIA_ERR_FROM_WRT_ERR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CIA_ERR_IOA_TIMEOUT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_COR_ERR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_UN_COR_ERR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_CPU_PE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_MEM_NEM
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_PERR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_PCI_ADDR_PE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_RCVD_MAS_ABT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_RCVD_TAR_ABT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_PA_PTE_INV
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_FROM_WRT_ERR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_LOST_IOA_TIMEOUT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CIA_ERR_VALID
value|0x80000000
end_define

end_unit

