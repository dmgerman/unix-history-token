begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Konstantin Belousov<kib@FreeBSD.org>  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86_IOMMU_INTEL_REG_H
end_ifndef

begin_define
define|#
directive|define
name|__X86_IOMMU_INTEL_REG_H
end_define

begin_define
define|#
directive|define
name|DMAR_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|DMAR_PAGE_MASK
value|(DMAR_PAGE_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|DMAR_PAGE_SHIFT
value|PAGE_SHIFT
end_define

begin_define
define|#
directive|define
name|DMAR_NPTEPG
value|(DMAR_PAGE_SIZE / sizeof(dmar_pte_t))
end_define

begin_define
define|#
directive|define
name|DMAR_NPTEPGSHIFT
value|9
end_define

begin_define
define|#
directive|define
name|DMAR_PTEMASK
value|(DMAR_NPTEPG - 1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|dmar_root_entry
block|{
name|uint64_t
name|r1
decl_stmt|;
name|uint64_t
name|r2
decl_stmt|;
block|}
name|dmar_root_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DMAR_ROOT_R1_P
value|1
end_define

begin_comment
comment|/* Present */
end_comment

begin_define
define|#
directive|define
name|DMAR_ROOT_R1_CTP_MASK
value|0xfffffffffffff000
end_define

begin_comment
comment|/* Mask for Context-Entry 						      Table Pointer */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX_CNT
value|(DMAR_PAGE_SIZE / sizeof(dmar_root_entry_t))
end_define

begin_typedef
typedef|typedef
struct|struct
name|dmar_ctx_entry
block|{
name|uint64_t
name|ctx1
decl_stmt|;
name|uint64_t
name|ctx2
decl_stmt|;
block|}
name|dmar_ctx_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DMAR_CTX1_P
value|1
end_define

begin_comment
comment|/* Present */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX1_FPD
value|2
end_define

begin_comment
comment|/* Fault Processing Disable */
end_comment

begin_comment
comment|/* Translation Type: */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX1_T_UNTR
value|0
end_define

begin_comment
comment|/* only Untranslated */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX1_T_TR
value|4
end_define

begin_comment
comment|/* both Untranslated 						   and Translated */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX1_T_PASS
value|8
end_define

begin_comment
comment|/* Pass-Through */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX1_ASR_MASK
value|0xfffffffffffff000
end_define

begin_comment
comment|/* Mask for the Address 						   Space Root */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX2_AW_2LVL
value|0
end_define

begin_comment
comment|/* 2-level page tables */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX2_AW_3LVL
value|1
end_define

begin_comment
comment|/* 3-level page tables */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX2_AW_4LVL
value|2
end_define

begin_comment
comment|/* 4-level page tables */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX2_AW_5LVL
value|3
end_define

begin_comment
comment|/* 5-level page tables */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX2_AW_6LVL
value|4
end_define

begin_comment
comment|/* 6-level page tables */
end_comment

begin_define
define|#
directive|define
name|DMAR_CTX2_DID
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* Domain Identifier */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dmar_pte
block|{
name|uint64_t
name|pte
decl_stmt|;
block|}
name|dmar_pte_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DMAR_PTE_R
value|1
end_define

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|DMAR_PTE_W
value|(1<< 1)
end_define

begin_comment
comment|/* Write */
end_comment

begin_define
define|#
directive|define
name|DMAR_PTE_SP
value|(1<< 7)
end_define

begin_comment
comment|/* Super Page */
end_comment

begin_define
define|#
directive|define
name|DMAR_PTE_SNP
value|(1<< 11)
end_define

begin_comment
comment|/* Snoop Behaviour */
end_comment

begin_define
define|#
directive|define
name|DMAR_PTE_ADDR_MASK
value|0xffffffffff000
end_define

begin_comment
comment|/* Address Mask */
end_comment

begin_define
define|#
directive|define
name|DMAR_PTE_TM
value|(1ULL<< 62)
end_define

begin_comment
comment|/* Transient Mapping */
end_comment

begin_comment
comment|/* Version register */
end_comment

begin_define
define|#
directive|define
name|DMAR_VER_REG
value|0
end_define

begin_define
define|#
directive|define
name|DMAR_MAJOR_VER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|DMAR_MINOR_VER
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_comment
comment|/* Capabilities register */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_REG
value|0x8
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_DRD
value|(1ULL<< 55)
end_define

begin_comment
comment|/* DMA Read Draining */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_DWD
value|(1ULL<< 54)
end_define

begin_comment
comment|/* DMA Write Draining */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_MAMV
parameter_list|(
name|x
parameter_list|)
value|((u_int)(((x)>> 48)& 0x3f))
end_define

begin_comment
comment|/* Maximum Address Mask */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_NFR
parameter_list|(
name|x
parameter_list|)
value|((u_int)(((x)>> 40)& 0xff) + 1)
end_define

begin_comment
comment|/* Num of Fault-recording regs */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_PSI
value|(1ULL<< 39)
end_define

begin_comment
comment|/* Page Selective Invalidation */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_SPS
parameter_list|(
name|x
parameter_list|)
value|((u_int)(((x)>> 34)& 0xf))
end_define

begin_comment
comment|/* Super-Page Support */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_SPS_2M
value|0x1
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_SPS_1G
value|0x2
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_SPS_512G
value|0x4
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_SPS_1T
value|0x8
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_FRO
parameter_list|(
name|x
parameter_list|)
value|((u_int)(((x)>> 24)& 0x1ff))
end_define

begin_comment
comment|/* Fault-recording reg offset */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_ISOCH
value|(1<< 23)
end_define

begin_comment
comment|/* Isochrony */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_ZLR
value|(1<< 22)
end_define

begin_comment
comment|/* Zero-length reads */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_MGAW
parameter_list|(
name|x
parameter_list|)
value|((u_int)(((x)>> 16)& 0x3f))
end_define

begin_comment
comment|/* Max Guest Address Width */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_SAGAW
parameter_list|(
name|x
parameter_list|)
value|((u_int)(((x)>> 8)& 0x1f))
end_define

begin_comment
comment|/* Adjusted Guest Address Width */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_SAGAW_2LVL
value|0x01
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_SAGAW_3LVL
value|0x02
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_SAGAW_4LVL
value|0x04
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_SAGAW_5LVL
value|0x08
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_SAGAW_6LVL
value|0x10
end_define

begin_define
define|#
directive|define
name|DMAR_CAP_CM
value|(1<< 7)
end_define

begin_comment
comment|/* Caching mode */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_PHMR
value|(1<< 6)
end_define

begin_comment
comment|/* Protected High-mem Region */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_PLMR
value|(1<< 5)
end_define

begin_comment
comment|/* Protected Low-mem Region */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_RWBF
value|(1<< 4)
end_define

begin_comment
comment|/* Required Write-Buffer Flushing */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_AFL
value|(1<< 3)
end_define

begin_comment
comment|/* Advanced Fault Logging */
end_comment

begin_define
define|#
directive|define
name|DMAR_CAP_ND
parameter_list|(
name|x
parameter_list|)
value|((u_int)((x)& 0x3))
end_define

begin_comment
comment|/* Number of domains */
end_comment

begin_comment
comment|/* Extended Capabilities register */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|DMAR_ECAP_MHMV
parameter_list|(
name|x
parameter_list|)
value|((u_int)(((x)>> 20)& 0xf))
end_define

begin_comment
comment|/* Maximum Handle Mask Value */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_IRO
parameter_list|(
name|x
parameter_list|)
value|((u_int)(((x)>> 8)& 0x3ff))
end_define

begin_comment
comment|/* IOTLB Register Offset */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_SC
value|(1<< 7)
end_define

begin_comment
comment|/* Snoop Control */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_PT
value|(1<< 6)
end_define

begin_comment
comment|/* Pass Through */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_EIM
value|(1<< 4)
end_define

begin_comment
comment|/* Extended Interrupt Mode */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_IR
value|(1<< 3)
end_define

begin_comment
comment|/* Interrupt Remapping */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_DI
value|(1<< 2)
end_define

begin_comment
comment|/* Device IOTLB */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_QI
value|(1<< 1)
end_define

begin_comment
comment|/* Queued Invalidation */
end_comment

begin_define
define|#
directive|define
name|DMAR_ECAP_C
value|(1<< 0)
end_define

begin_comment
comment|/* Coherency */
end_comment

begin_comment
comment|/* Global Command register */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|DMAR_GCMD_TE
value|(1U<< 31)
end_define

begin_comment
comment|/* Translation Enable */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_SRTP
value|(1<< 30)
end_define

begin_comment
comment|/* Set Root Table Pointer */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_SFL
value|(1<< 29)
end_define

begin_comment
comment|/* Set Fault Log */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_EAFL
value|(1<< 28)
end_define

begin_comment
comment|/* Enable Advanced Fault Logging */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_WBF
value|(1<< 27)
end_define

begin_comment
comment|/* Write Buffer Flush */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_QIE
value|(1<< 26)
end_define

begin_comment
comment|/* Queued Invalidation Enable */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_IRE
value|(1<< 25)
end_define

begin_comment
comment|/* Interrupt Remapping Enable */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_SIRTP
value|(1<< 24)
end_define

begin_comment
comment|/* Set Interrupt Remap Table Pointer */
end_comment

begin_define
define|#
directive|define
name|DMAR_GCMD_CFI
value|(1<< 23)
end_define

begin_comment
comment|/* Compatibility Format Interrupt */
end_comment

begin_comment
comment|/* Global Status register */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_REG
value|0x1c
end_define

begin_define
define|#
directive|define
name|DMAR_GSTS_TES
value|(1U<< 31)
end_define

begin_comment
comment|/* Translation Enable Status */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_RTPS
value|(1<< 30)
end_define

begin_comment
comment|/* Root Table Pointer Status */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_FLS
value|(1<< 29)
end_define

begin_comment
comment|/* Fault Log Status */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_AFLS
value|(1<< 28)
end_define

begin_comment
comment|/* Advanced Fault Logging Status */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_WBFS
value|(1<< 27)
end_define

begin_comment
comment|/* Write Buffer Flush Status */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_QIES
value|(1<< 26)
end_define

begin_comment
comment|/* Queued Invalidation Enable Status */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_IRES
value|(1<< 25)
end_define

begin_comment
comment|/* Interrupt Remapping Enable Status */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_IRTPS
value|(1<< 24)
end_define

begin_comment
comment|/* Interrupt Remapping Table 					   Pointer Status */
end_comment

begin_define
define|#
directive|define
name|DMAR_GSTS_CFIS
value|(1<< 23)
end_define

begin_comment
comment|/* Compatibility Format 					   Interrupt Status */
end_comment

begin_comment
comment|/* Root-Entry Table Address register */
end_comment

begin_define
define|#
directive|define
name|DMAR_RTADDR_REG
value|0x20
end_define

begin_comment
comment|/* Context Command register */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_REG
value|0x28
end_define

begin_define
define|#
directive|define
name|DMAR_CCMD_ICC
value|(1ULL<< 63)
end_define

begin_comment
comment|/* Invalidate Context-Cache */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_ICC32
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DMAR_CCMD_CIRG_MASK
value|(0x3ULL<< 61)
end_define

begin_comment
comment|/* Context Invalidation 						   Request Granularity */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_CIRG_GLOB
value|(0x1ULL<< 61)
end_define

begin_comment
comment|/* Global */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_CIRG_DOM
value|(0x2ULL<< 61)
end_define

begin_comment
comment|/* Domain */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_CIRG_DEV
value|(0x3ULL<< 61)
end_define

begin_comment
comment|/* Device */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_CAIG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 59)& 0x3)
end_define

begin_comment
comment|/* Context Actual 						    Invalidation Granularity */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_CAIG_GLOB
value|0x1
end_define

begin_comment
comment|/* Global */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_CAIG_DOM
value|0x2
end_define

begin_comment
comment|/* Domain */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_CAIG_DEV
value|0x3
end_define

begin_comment
comment|/* Device */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_FM
value|(0x3UUL<< 32)
end_define

begin_comment
comment|/* Function Mask */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_SID
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 16)
end_define

begin_comment
comment|/* Source-ID */
end_comment

begin_define
define|#
directive|define
name|DMAR_CCMD_DID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
end_define

begin_comment
comment|/* Domain-ID */
end_comment

begin_comment
comment|/* Invalidate Address register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IVA_REG_OFF
value|0
end_define

begin_define
define|#
directive|define
name|DMAR_IVA_IH
value|(1<< 6)
end_define

begin_comment
comment|/* Invalidation Hint */
end_comment

begin_define
define|#
directive|define
name|DMAR_IVA_AM
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1f)
end_define

begin_comment
comment|/* Address Mask */
end_comment

begin_define
define|#
directive|define
name|DMAR_IVA_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)& ~0xfffULL)
end_define

begin_comment
comment|/* Address */
end_comment

begin_comment
comment|/* IOTLB Invalidate register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_REG_OFF
value|0x8
end_define

begin_define
define|#
directive|define
name|DMAR_IOTLB_IVT
value|(1ULL<< 63)
end_define

begin_comment
comment|/* Invalidate IOTLB */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IVT32
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DMAR_IOTLB_IIRG_MASK
value|(0x3ULL<< 60)
end_define

begin_comment
comment|/* Invalidation Request 						   Granularity */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IIRG_GLB
value|(0x1ULL<< 60)
end_define

begin_comment
comment|/* Global */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IIRG_DOM
value|(0x2ULL<< 60)
end_define

begin_comment
comment|/* Domain-selective */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IIRG_PAGE
value|(0x3ULL<< 60)
end_define

begin_comment
comment|/* Page-selective */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IAIG_MASK
value|(0x3ULL<< 57)
end_define

begin_comment
comment|/* Actual Invalidation 						   Granularity */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IAIG_INVLD
value|0
end_define

begin_comment
comment|/* Hw detected error */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IAIG_GLB
value|(0x1ULL<< 57)
end_define

begin_comment
comment|/* Global */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IAIG_DOM
value|(0x2ULL<< 57)
end_define

begin_comment
comment|/* Domain-selective */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_IAIG_PAGE
value|(0x3ULL<< 57)
end_define

begin_comment
comment|/* Page-selective */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_DR
value|(0x1ULL<< 49)
end_define

begin_comment
comment|/* Drain Reads */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_DW
value|(0x1ULL<< 48)
end_define

begin_comment
comment|/* Drain Writes */
end_comment

begin_define
define|#
directive|define
name|DMAR_IOTLB_DID
parameter_list|(
name|x
parameter_list|)
value|(((uint64_t)(x)& 0xffff)<< 32)
end_define

begin_comment
comment|/* Domain Id */
end_comment

begin_comment
comment|/* Fault Status register */
end_comment

begin_define
define|#
directive|define
name|DMAR_FSTS_REG
value|0x34
end_define

begin_define
define|#
directive|define
name|DMAR_FSTS_FRI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_comment
comment|/* Fault Record Index */
end_comment

begin_define
define|#
directive|define
name|DMAR_FSTS_ITE
value|(1<< 6)
end_define

begin_comment
comment|/* Invalidation Time-out */
end_comment

begin_define
define|#
directive|define
name|DMAR_FSTS_ICE
value|(1<< 5)
end_define

begin_comment
comment|/* Invalidation Completion */
end_comment

begin_define
define|#
directive|define
name|DMAR_FSTS_IQE
value|(1<< 4)
end_define

begin_comment
comment|/* Invalidation Queue */
end_comment

begin_define
define|#
directive|define
name|DMAR_FSTS_APF
value|(1<< 3)
end_define

begin_comment
comment|/* Advanced Pending Fault */
end_comment

begin_define
define|#
directive|define
name|DMAR_FSTS_AFO
value|(1<< 2)
end_define

begin_comment
comment|/* Advanced Fault Overflow */
end_comment

begin_define
define|#
directive|define
name|DMAR_FSTS_PPF
value|(1<< 1)
end_define

begin_comment
comment|/* Primary Pending Fault */
end_comment

begin_define
define|#
directive|define
name|DMAR_FSTS_PFO
value|1
end_define

begin_comment
comment|/* Fault Overflow */
end_comment

begin_comment
comment|/* Fault Event Control register */
end_comment

begin_define
define|#
directive|define
name|DMAR_FECTL_REG
value|0x38
end_define

begin_define
define|#
directive|define
name|DMAR_FECTL_IM
value|(1U<< 31)
end_define

begin_comment
comment|/* Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|DMAR_FECTL_IP
value|(1<< 30)
end_define

begin_comment
comment|/* Interrupt Pending */
end_comment

begin_comment
comment|/* Fault Event Data register */
end_comment

begin_define
define|#
directive|define
name|DMAR_FEDATA_REG
value|0x3c
end_define

begin_comment
comment|/* Fault Event Address register */
end_comment

begin_define
define|#
directive|define
name|DMAR_FEADDR_REG
value|0x40
end_define

begin_comment
comment|/* Fault Event Upper Address register */
end_comment

begin_define
define|#
directive|define
name|DMAR_FEUADDR_REG
value|0x44
end_define

begin_comment
comment|/* Advanced Fault Log register */
end_comment

begin_define
define|#
directive|define
name|DMAR_AFLOG_REG
value|0x58
end_define

begin_comment
comment|/* Fault Recording Register, also usable for Advanced Fault Log records */
end_comment

begin_define
define|#
directive|define
name|DMAR_FRCD2_F
value|(1ULL<< 63)
end_define

begin_comment
comment|/* Fault */
end_comment

begin_define
define|#
directive|define
name|DMAR_FRCD2_F32
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DMAR_FRCD2_T
parameter_list|(
name|x
parameter_list|)
value|((int)((x>> 62)& 1))
end_define

begin_comment
comment|/* Type */
end_comment

begin_define
define|#
directive|define
name|DMAR_FRCD2_T_W
value|0
end_define

begin_comment
comment|/* Write request */
end_comment

begin_define
define|#
directive|define
name|DMAR_FRCD2_T_R
value|1
end_define

begin_comment
comment|/* Read or AtomicOp */
end_comment

begin_define
define|#
directive|define
name|DMAR_FRCD2_AT
parameter_list|(
name|x
parameter_list|)
value|((int)((x>> 60)& 0x3))
end_define

begin_comment
comment|/* Address Type */
end_comment

begin_define
define|#
directive|define
name|DMAR_FRCD2_FR
parameter_list|(
name|x
parameter_list|)
value|((int)((x>> 32)& 0xff))
end_define

begin_comment
comment|/* Fault Reason */
end_comment

begin_define
define|#
directive|define
name|DMAR_FRCD2_SID
parameter_list|(
name|x
parameter_list|)
value|((int)(x& 0xffff))
end_define

begin_comment
comment|/* Source Identifier */
end_comment

begin_define
define|#
directive|define
name|DMAR_FRCS1_FI_MASK
value|0xffffffffff000
end_define

begin_comment
comment|/* Fault Info, Address Mask */
end_comment

begin_comment
comment|/* Protected Memory Enable register */
end_comment

begin_define
define|#
directive|define
name|DMAR_PMEN_REG
value|0x64
end_define

begin_define
define|#
directive|define
name|DMAR_PMEN_EPM
value|(1U<< 31)
end_define

begin_comment
comment|/* Enable Protected Memory */
end_comment

begin_define
define|#
directive|define
name|DMAR_PMEN_PRS
value|1
end_define

begin_comment
comment|/* Protected Region Status */
end_comment

begin_comment
comment|/* Protected Low-Memory Base register */
end_comment

begin_define
define|#
directive|define
name|DMAR_PLMBASE_REG
value|0x68
end_define

begin_comment
comment|/* Protected Low-Memory Limit register */
end_comment

begin_define
define|#
directive|define
name|DMAR_PLMLIMIT_REG
value|0x6c
end_define

begin_comment
comment|/* Protected High-Memory Base register */
end_comment

begin_define
define|#
directive|define
name|DMAR_PHMBASE_REG
value|0x70
end_define

begin_comment
comment|/* Protected High-Memory Limit register */
end_comment

begin_define
define|#
directive|define
name|DMAR_PHMLIMIT_REG
value|0x78
end_define

begin_comment
comment|/* Queued Invalidation Descriptors */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_SZ_SHIFT
value|4
end_define

begin_comment
comment|/* Shift for descriptor count 					   to ring offset */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_SZ
value|(1<< DMAR_IQ_DESCR_SZ_SHIFT)
end_define

begin_comment
comment|/* Descriptor size */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_CTX_INV
value|0x1
end_define

begin_comment
comment|/* Context-cache Invalidate 					   Descriptor */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_CTX_GLOB
value|(0x1<< 4)
end_define

begin_comment
comment|/* Granularity: Global */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_CTX_DOM
value|(0x2<< 4)
end_define

begin_comment
comment|/* Granularity: Domain */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_CTX_DEV
value|(0x3<< 4)
end_define

begin_comment
comment|/* Granularity: Device */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_CTX_DID
parameter_list|(
name|x
parameter_list|)
value|(((uint32_t)(x))<< 16)
end_define

begin_comment
comment|/* Domain Id */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_CTX_SRC
parameter_list|(
name|x
parameter_list|)
value|(((uint64_t)(x))<< 32)
end_define

begin_comment
comment|/* Source Id */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_CTX_FM
parameter_list|(
name|x
parameter_list|)
value|(((uint64_t)(x))<< 48)
end_define

begin_comment
comment|/* Function Mask */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_IOTLB_INV
value|0x2
end_define

begin_comment
comment|/* IOTLB Invalidate Descriptor */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_IOTLB_GLOB
value|(0x1<< 4)
end_define

begin_comment
comment|/* Granularity: Global */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_IOTLB_DOM
value|(0x2<< 4)
end_define

begin_comment
comment|/* Granularity: Domain */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_IOTLB_PAGE
value|(0x3<< 4)
end_define

begin_comment
comment|/* Granularity: Page */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_IOTLB_DW
value|(1<< 6)
end_define

begin_comment
comment|/* Drain Writes */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_IOTLB_DR
value|(1<< 7)
end_define

begin_comment
comment|/* Drain Reads */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_IOTLB_DID
parameter_list|(
name|x
parameter_list|)
value|(((uint32_t)(x))<< 16)
end_define

begin_comment
comment|/* Domain Id */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_WAIT_ID
value|0x5
end_define

begin_comment
comment|/* Invalidation Wait Descriptor */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_WAIT_IF
value|(1<< 4)
end_define

begin_comment
comment|/* Interrupt Flag */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_WAIT_SW
value|(1<< 5)
end_define

begin_comment
comment|/* Status Write */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_WAIT_FN
value|(1<< 6)
end_define

begin_comment
comment|/* Fence */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQ_DESCR_WAIT_SD
parameter_list|(
name|x
parameter_list|)
value|(((uint64_t)(x))<< 32)
end_define

begin_comment
comment|/* Status Data */
end_comment

begin_comment
comment|/* Invalidation Queue Head register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQH_REG
value|0x80
end_define

begin_define
define|#
directive|define
name|DMAR_IQH_MASK
value|0x7fff0
end_define

begin_comment
comment|/* Next cmd index mask */
end_comment

begin_comment
comment|/* Invalidation Queue Tail register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQT_REG
value|0x88
end_define

begin_define
define|#
directive|define
name|DMAR_IQT_MASK
value|0x7fff0
end_define

begin_comment
comment|/* Invalidation Queue Address register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQA_REG
value|0x90
end_define

begin_define
define|#
directive|define
name|DMAR_IQA_IQA_MASK
value|0xfffffffffffff000
end_define

begin_comment
comment|/* Invalidation Queue 						      Base Address mask */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQA_QS_MASK
value|0x7
end_define

begin_comment
comment|/* Queue Size in pages */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQA_QS_MAX
value|0x7
end_define

begin_comment
comment|/* Max Queue size */
end_comment

begin_define
define|#
directive|define
name|DMAR_IQA_QS_DEF
value|3
end_define

begin_comment
comment|/* Invalidation Completion Status register */
end_comment

begin_define
define|#
directive|define
name|DMAR_ICS_REG
value|0x9c
end_define

begin_define
define|#
directive|define
name|DMAR_ICS_IWC
value|1
end_define

begin_comment
comment|/* Invalidation Wait 						   Descriptor Complete */
end_comment

begin_comment
comment|/* Invalidation Event Control register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IECTL_REG
value|0xa0
end_define

begin_define
define|#
directive|define
name|DMAR_IECTL_IM
value|(1U<< 31)
end_define

begin_comment
comment|/* Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|DMAR_IECTL_IP
value|(1<< 30)
end_define

begin_comment
comment|/* Interrupt Pending */
end_comment

begin_comment
comment|/* Invalidation Event Data register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IEDATA_REG
value|0xa4
end_define

begin_comment
comment|/* Invalidation Event Address register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IEADDR_REG
value|0xa8
end_define

begin_comment
comment|/* Invalidation Event Upper Address register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IEUADDR_REG
value|0xac
end_define

begin_comment
comment|/* Interrupt Remapping Table Address register */
end_comment

begin_define
define|#
directive|define
name|DMAR_IRTA_REG
value|0xb8
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

