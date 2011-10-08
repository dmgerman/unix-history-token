begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Jason L. Wright (jason@thought.net)  * Copyright (c) 2005 by Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULLAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: OpenBSD: schizoreg.h,v 1.8 2005/05/19 18:28:59 mickey Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_PCI_SCHIZOREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_PCI_SCHIZOREG_H_
end_define

begin_define
define|#
directive|define
name|STX_NINTR
value|5
end_define

begin_comment
comment|/* 4 via OFW + 1 CDMA */
end_comment

begin_define
define|#
directive|define
name|STX_NRANGE
value|4
end_define

begin_define
define|#
directive|define
name|SCZ_NREG
value|3
end_define

begin_define
define|#
directive|define
name|TOM_NREG
value|4
end_define

begin_define
define|#
directive|define
name|STX_PCI
value|0
end_define

begin_define
define|#
directive|define
name|STX_CTRL
value|1
end_define

begin_define
define|#
directive|define
name|STX_PCICFG
value|2
end_define

begin_define
define|#
directive|define
name|STX_ICON
value|3
end_define

begin_comment
comment|/* PCI configuration and status registers */
end_comment

begin_define
define|#
directive|define
name|SX_PCI_CFG_ICD
value|0x00110
end_define

begin_define
define|#
directive|define
name|STX_PCI_IOMMU
value|0x00200
end_define

begin_define
define|#
directive|define
name|STX_PCI_IOMMU_CTXFLUSH
value|0x00218
end_define

begin_define
define|#
directive|define
name|STX_PCI_IMAP_BASE
value|0x01000
end_define

begin_define
define|#
directive|define
name|STX_PCI_ICLR_BASE
value|0x01400
end_define

begin_define
define|#
directive|define
name|STX_PCI_INTR_RETRY_TIM
value|0x01a00
end_define

begin_define
define|#
directive|define
name|SCZ_PCI_DMA_SYNC
value|0x01a08
end_define

begin_define
define|#
directive|define
name|TOM_PCI_DMA_SYNC_COMP
value|0x01a10
end_define

begin_define
define|#
directive|define
name|TOMXMS_PCI_DMA_SYNC_PEND
value|0x01a18
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL
value|0x02000
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR
value|0x02010
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFAR
value|0x02018
end_define

begin_define
define|#
directive|define
name|STX_PCI_DIAG
value|0x02020
end_define

begin_define
define|#
directive|define
name|XMS_PCI_PARITY_DETECT
value|0x02040
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_CSR
value|0x02248
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_TAG
value|0x02290
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_DATA
value|0x02290
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT
value|0x02300
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_DIAG
value|0x02308
end_define

begin_define
define|#
directive|define
name|XMS_PCI_UPPER_RETRY_COUNTER
value|0x02310
end_define

begin_define
define|#
directive|define
name|STX_PCI_STRBUF
value|0x02800
end_define

begin_define
define|#
directive|define
name|STX_PCI_STRBUF_CTXFLUSH
value|0x02818
end_define

begin_define
define|#
directive|define
name|STX_PCI_IOMMU_SVADIAG
value|0x0a400
end_define

begin_define
define|#
directive|define
name|STX_PCI_IOMMU_TLB_CMP_DIAG
value|0x0a408
end_define

begin_define
define|#
directive|define
name|STX_PCI_IOMMU_QUEUE_DIAG
value|0x0a500
end_define

begin_define
define|#
directive|define
name|STX_PCI_IOMMU_TLB_TAG_DIAG
value|0x0a580
end_define

begin_define
define|#
directive|define
name|STX_PCI_IOMMU_TLB_DATA_DIAG
value|0x0a600
end_define

begin_define
define|#
directive|define
name|STX_PCI_IOBIO_DIAG
value|0x0a808
end_define

begin_define
define|#
directive|define
name|STX_PCI_STRBUF_CTXMATCH
value|0x10000
end_define

begin_comment
comment|/* PCI configuration/idle check diagnostic register */
end_comment

begin_define
define|#
directive|define
name|SX_PCI_CFG_ICD_PCI_2_0_COMPAT
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|SX_PCI_CFG_ICD_DMAW_PERR_IEN
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|SX_PCI_CFG_ICD_IFC_NOT_IDLE
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|SX_PCI_CFG_ICD_MDU_NOT_IDLE
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|SX_PCI_CFG_ICD_MMU_NOT_IDLE
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|SX_PCI_CFG_ICD_PBM_NOT_IDLE
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|SX_PCI_CFG_ICD_STC_NOT_IDLE
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI IOMMU control register */
end_comment

begin_define
define|#
directive|define
name|TOM_PCI_IOMMU_ERR_BAD_VA
value|0x0000000010000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOMMU_ERR_ILLTSBTBW
value|0x0000000008000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOMMU_ECC_ERR
value|0x0000000006000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOMMU_TIMEOUT_ERR
value|0x0000000004000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOMMU_INVALID_ERR
value|0x0000000002000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOMMU_PROTECTION_ERR
value|0x0000000000000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOMMU_ERRMASK
define|\
value|(TOM_PCI_IOMMU_PROTECTION_ERR | TOM_PCI_IOMMU_INVALID_ERR |	\ 	TOM_PCI_IOMMU_TIMEOUT_ERR | TOM_PCI_IOMMU_ECC_ERR)
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOMMU_ERR
value|0x0000000001000000ULL
end_define

begin_comment
comment|/* PCI control/status register */
end_comment

begin_define
define|#
directive|define
name|SCZ_PCI_CTRL_BUS_UNUS
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_CTRL_DTO_ERR
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_CTRL_DTO_IEN
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_PCI_CTRL_ESLCK
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_CTRL_DMA_WR_PERR
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_PCI_CTRL_ERRSLOT
value|0x0007000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_TTO_ERR
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_RTRY_ERR
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_MMU_ERR
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_PCI_CTRL_SBH_ERR
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_SERR
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_PCI_CTRL_PCISPD
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_CTRL_X_MODE
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_CTRL_PRM
value|0x0000000040000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_CTRL_PRO
value|0x0000000020000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_CTRL_PRL
value|0x0000000010000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_PTO
value|0x0000000003000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_CTRL_X_ERRINT_EN
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_MMU_IEN
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_SBH_IEN
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_ERR_IEN
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_ARB_PARK
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_PCI_CTRL_PCIRST
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_CTRL_ARB_MASK
value|0x00000000000000ffULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_CTRL_XMITS10_ARB_MASK
value|0x000000000000000fULL
end_define

begin_comment
comment|/* PCI asynchronous fault status register */
end_comment

begin_define
define|#
directive|define
name|STX_PCI_AFSR_P_MA
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_P_TA
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_P_RTRY
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_P_PERR
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_P_TTO
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_P_UNUS
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_S_MA
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_S_TA
value|0x0100000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_S_RTRY
value|0x0080000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_S_PERR
value|0x0040000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_S_TTO
value|0x0020000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_S_UNUS
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_DWMASK
value|0x0000030000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_BMASK
value|0x000000ff00000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_BLK
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_CFG
value|0x0000000040000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_MEM
value|0x0000000020000000ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_AFSR_IO
value|0x0000000010000000ULL
end_define

begin_comment
comment|/* PCI diagnostic register */
end_comment

begin_define
define|#
directive|define
name|SCZ_PCI_DIAG_BADECC_DIS
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_DIAG_BYPASS_DIS
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_DIAG_TTO_DIS
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|SCZ_PCI_DIAG_RTRYARB_DIS
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_DIAG_RETRY_DIS
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_DIAG_INTRSYNC_DIS
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_DIAG_DMAPARITY_INV
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_DIAG_PIODPARITY_INV
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|STX_PCI_DIAG_PIOAPARITY_INV
value|0x0000000000000002ULL
end_define

begin_comment
comment|/* Tomatillo I/O cache register */
end_comment

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PW
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRM
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRO
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRL
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRM_LEN
value|0x000000000000c000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRM_LEN_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRO_LEN
value|0x0000000000003000ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRO_LEN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRL_LEN
value|0x0000000000000c00ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PRL_LEN_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PREF_OFF
value|0x0000000000000038ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_PREF_OFF_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_CPRM
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_CPRO
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|TOM_PCI_IOC_CPRL
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* XMITS PCI-X error status register */
end_comment

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_P_SC_DSCRD
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_P_SC_TTO
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_P_SDSTAT
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_P_SMMU
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_P_CDSTAT
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_P_CMMU
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_S_SC_DSCRD
value|0x0080000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_S_SC_TTO
value|0x0040000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_S_SDSTAT
value|0x0020000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_S_SMMU
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_S_CDSTAT
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_S_CMMU
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_PERR_RCV_IEN
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_PERR_RCV
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_ERR_STAT_SERR_ON_PERR
value|0x0000000100000000ULL
end_define

begin_comment
comment|/* XMITS PCI-X diagnostic register */
end_comment

begin_define
define|#
directive|define
name|XMS_PCI_X_DIAG_DIS_FAIR
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_DIAG_CRCQ_VALID
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_DIAG_SRCQ_ONE
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_DIAG_CRCQ_FLUSH
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_DIAG_BUGCNTL_MASK
value|0x0000ffff00000000ULL
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_DIAG_BUGCNTL_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|XMS_PCI_X_DIAG_SRCQ_MASK
value|0x00000000000000ffULL
end_define

begin_comment
comment|/* Controller configuration and status registers */
end_comment

begin_comment
comment|/* Note that these are shared on Schizo but per-PBM on Tomatillo. */
end_comment

begin_define
define|#
directive|define
name|STX_CTRL_BUS_ERRLOG
value|0x00018
end_define

begin_define
define|#
directive|define
name|STX_CTRL_ECCCTRL
value|0x00020
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR
value|0x00030
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFAR
value|0x00038
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR
value|0x00040
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFAR
value|0x00048
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF
value|0x07000
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_CNT
value|0x07008
end_define

begin_comment
comment|/* Safari/JBus error log register */
end_comment

begin_define
define|#
directive|define
name|STX_CTRL_BUS_ERRLOG_BADCMD
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_SSMDIS
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_BADMA
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_BADMB
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_BADMC
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_SNOOP_GR
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_SNOOP_PCI
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_SNOOP_RD
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_SNOOP_RDS
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_SNOOP_RDSA
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_SNOOP_OWN
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_SNOOP_RDO
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_CPU1PS
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_WDATA_PERR
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_CPU1PB
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_CTRL_PERR
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_CPU0PS
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_SNOOP_ERR
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_CPU0PB
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_JBUS_ILL_B
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_CIQTO
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_LPQTO
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_JBUS_ILL_C
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_SFPQTO
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_UFPQTO
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_BUS_ERRLOG_RD_PERR
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_BUS_ERRLOG_APERR
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_BUS_ERRLOG_UNMAP
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_BUS_ERRLOG_BUSERR
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_BUS_ERRLOG_TIMEOUT
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_BUS_ERRLOG_ILL
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* ECC control register */
end_comment

begin_define
define|#
directive|define
name|STX_CTRL_ECCCTRL_EE
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_ECCCTRL_UE
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_ECCCTRL_CE
value|0x2000000000000000ULL
end_define

begin_comment
comment|/* Uncorrectable error asynchronous fault status register */
end_comment

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_P_PIO
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_P_DRD
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_P_DWR
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_S_PIO
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_S_DRD
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_S_DWR
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_ERRPNDG
value|0x0300000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_BMASK
value|0x000003ff00000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_QOFF
value|0x00000000c0000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_AID
value|0x000000001f000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_PARTIAL
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_OWNEDIN
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_MTAGSYND
value|0x00000000000f0000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_MTAG
value|0x000000000000e000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_UE_AFSR_ECCSYND
value|0x00000000000001ffULL
end_define

begin_comment
comment|/* Correctable error asynchronous fault status register */
end_comment

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_P_PIO
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_P_DRD
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_P_DWR
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_S_PIO
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_S_DRD
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_S_DWR
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_ERRPNDG
value|0x0300000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_BMASK
value|0x000003ff00000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_QOFF
value|0x00000000c0000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_AID
value|0x000000001f000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_PARTIAL
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_OWNEDIN
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_MTAGSYND
value|0x00000000000f0000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_MTAG
value|0x000000000000e000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_CE_AFSR_ECCSYND
value|0x00000000000001ffULL
end_define

begin_comment
comment|/*  * Safari/JBus performance control register  * NB: for Tomatillo only events 0x00 through 0x08 are documented as  * implemented.  */
end_comment

begin_define
define|#
directive|define
name|SCZ_CTRL_PERF_ZDATA_OUT
value|0x0000000000000016ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_PERF_ZDATA_IN
value|0x0000000000000015ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_PERF_ORQFULL
value|0x0000000000000014ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_PERF_DVMA_WR
value|0x0000000000000013ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_PERF_DVMA_RD
value|0x0000000000000012ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_PERF_CYCPSESYS
value|0x0000000000000011ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_PCI_B
value|0x000000000000000fULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_PCI_A
value|0x000000000000000eULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_UPA
value|0x000000000000000dULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_PIOINTRNL
value|0x000000000000000cULL
end_define

begin_define
define|#
directive|define
name|TOM_CTRL_PERF_WRI_WRIS
value|0x000000000000000bULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_INTRS
value|0x000000000000000aULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_PRTLWRMRGBUF
value|0x0000000000000009ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_FGN_IO_HITS
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_FGN_IO_TRNS
value|0x0000000000000007ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_OWN_CHRNT_HITS
value|0x0000000000000006ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_OWN_CHRNT_TRNS
value|0x0000000000000005ULL
end_define

begin_define
define|#
directive|define
name|SCZ_CTRL_PERF_FGN_CHRNT_HITS
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_FGN_CHRNT_TRNS
value|0x0000000000000003ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_CYCLES_PAUSE
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_BUSCYC
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_DIS
value|0x0000000000000000ULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_CNT1_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_CNT0_SHIFT
value|4
end_define

begin_comment
comment|/* Safari/JBus performance counter register */
end_comment

begin_define
define|#
directive|define
name|STX_CTRL_PERF_CNT_MASK
value|0x00000000ffffffffULL
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_CNT_CNT1_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|STX_CTRL_PERF_CNT_CNT0_SHIFT
value|0
end_define

begin_comment
comment|/* INO defines */
end_comment

begin_define
define|#
directive|define
name|STX_FB0_INO
value|0x2a
end_define

begin_comment
comment|/* FB0 int. shared w/ UPA64s */
end_comment

begin_define
define|#
directive|define
name|STX_FB1_INO
value|0x2b
end_define

begin_comment
comment|/* FB1 int. shared w/ UPA64s */
end_comment

begin_define
define|#
directive|define
name|STX_UE_INO
value|0x30
end_define

begin_comment
comment|/* uncorrectable error */
end_comment

begin_define
define|#
directive|define
name|STX_CE_INO
value|0x31
end_define

begin_comment
comment|/* correctable error */
end_comment

begin_define
define|#
directive|define
name|STX_PCIERR_A_INO
value|0x32
end_define

begin_comment
comment|/* PCI bus A error */
end_comment

begin_define
define|#
directive|define
name|STX_PCIERR_B_INO
value|0x33
end_define

begin_comment
comment|/* PCI bus B error */
end_comment

begin_define
define|#
directive|define
name|STX_BUS_INO
value|0x34
end_define

begin_comment
comment|/* Safari/JBus error */
end_comment

begin_define
define|#
directive|define
name|STX_CDMA_A_INO
value|0x35
end_define

begin_comment
comment|/* PCI bus A CDMA */
end_comment

begin_define
define|#
directive|define
name|STX_CDMA_B_INO
value|0x36
end_define

begin_comment
comment|/* PCI bus B CDMA */
end_comment

begin_define
define|#
directive|define
name|STX_MAX_INO
value|0x37
end_define

begin_comment
comment|/* Device space defines */
end_comment

begin_define
define|#
directive|define
name|STX_CONF_SIZE
value|0x1000000
end_define

begin_define
define|#
directive|define
name|STX_CONF_BUS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|STX_CONF_DEV_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|STX_CONF_FUNC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|STX_CONF_REG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|STX_IO_SIZE
value|0x1000000
end_define

begin_define
define|#
directive|define
name|STX_MEM_SIZE
value|0x100000000
end_define

begin_define
define|#
directive|define
name|STX_CONF_OFF
parameter_list|(
name|bus
parameter_list|,
name|slot
parameter_list|,
name|func
parameter_list|,
name|reg
parameter_list|)
define|\
value|(((bus)<< STX_CONF_BUS_SHIFT) |				\ 	((slot)<< STX_CONF_DEV_SHIFT) |				\ 	((func)<< STX_CONF_FUNC_SHIFT) |				\ 	((reg)<< STX_CONF_REG_SHIFT))
end_define

begin_comment
comment|/* Definitions for the Schizo/Tomatillo configuration space */
end_comment

begin_define
define|#
directive|define
name|STX_CS_DEVICE
value|0
end_define

begin_comment
comment|/* bridge CS device number */
end_comment

begin_define
define|#
directive|define
name|STX_CS_FUNC
value|0
end_define

begin_comment
comment|/* brdige CS function number */
end_comment

begin_comment
comment|/* Non-Standard registers in the configration space */
end_comment

begin_comment
comment|/*  * NB: for Tomatillo the secondary and subordinate bus number registers  * apparently are read-only although documented otherwise; writing to  * them just triggers a PCI bus error interrupt or has no effect at best.  */
end_comment

begin_define
define|#
directive|define
name|STX_CSR_SECBUS
value|0x40
end_define

begin_comment
comment|/* secondary bus number */
end_comment

begin_define
define|#
directive|define
name|STX_CSR_SUBBUS
value|0x41
end_define

begin_comment
comment|/* subordinate bus number */
end_comment

begin_comment
comment|/* Width of the physical addresses the IOMMU translates to */
end_comment

begin_define
define|#
directive|define
name|STX_IOMMU_BITS
value|43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_PCI_SCHIZOREG_H_ */
end_comment

end_unit

