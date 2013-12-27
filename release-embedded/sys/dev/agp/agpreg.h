begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_AGPREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_AGPREG_H_
end_define

begin_comment
comment|/*  * Offsets for various AGP configuration registers.  */
end_comment

begin_define
define|#
directive|define
name|AGP_APBASE
value|PCIR_BAR(0)
end_define

begin_comment
comment|/*  * Offsets from the AGP Capability pointer.  */
end_comment

begin_define
define|#
directive|define
name|AGP_CAPID
value|0x0
end_define

begin_define
define|#
directive|define
name|AGP_STATUS
value|0x4
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND
value|0x8
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_AGP3
value|0x0008
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_RQ_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_RQ_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_ARQSZ_MASK
value|0xe000
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_ARQSZ_MASK
value|0xe000
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_CAL_MASK
value|0x1c00
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_CAL_MASK
value|0x1c00
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_ISOCH
value|0x10000
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_SBA
value|0x0200
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_ITA_COH
value|0x0100
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_GART64
value|0x0080
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_HTRANS
value|0x0040
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_64BIT
value|0x0020
end_define

begin_define
define|#
directive|define
name|AGP_STATUS_FW
value|0x0010
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_RQ_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_ARQSZ_MASK
value|0xe000
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_CAL_MASK
value|0x1c00
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_SBA
value|0x0200
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_AGP
value|0x0100
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_GART64
value|0x0080
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_64BIT
value|0x0020
end_define

begin_define
define|#
directive|define
name|AGP_COMMAND_FW
value|0x0010
end_define

begin_comment
comment|/*  * Config offsets for Intel AGP chipsets.  */
end_comment

begin_define
define|#
directive|define
name|AGP_INTEL_NBXCFG
value|0x50
end_define

begin_define
define|#
directive|define
name|AGP_INTEL_ERRSTS
value|0x91
end_define

begin_define
define|#
directive|define
name|AGP_INTEL_AGPCTRL
value|0xb0
end_define

begin_define
define|#
directive|define
name|AGP_INTEL_APSIZE
value|0xb4
end_define

begin_define
define|#
directive|define
name|AGP_INTEL_ATTBASE
value|0xb8
end_define

begin_comment
comment|/*  * Config offsets for Intel i8xx/E7xxx AGP chipsets.  */
end_comment

begin_define
define|#
directive|define
name|AGP_INTEL_MCHCFG
value|0x50
end_define

begin_define
define|#
directive|define
name|AGP_INTEL_I820_RDCR
value|0x51
end_define

begin_define
define|#
directive|define
name|AGP_INTEL_I845_AGPM
value|0x51
end_define

begin_define
define|#
directive|define
name|AGP_INTEL_I8XX_ERRSTS
value|0xc8
end_define

begin_comment
comment|/*  * Config offsets for VIA AGP 2.x chipsets.  */
end_comment

begin_define
define|#
directive|define
name|AGP_VIA_GARTCTRL
value|0x80
end_define

begin_define
define|#
directive|define
name|AGP_VIA_APSIZE
value|0x84
end_define

begin_define
define|#
directive|define
name|AGP_VIA_ATTBASE
value|0x88
end_define

begin_comment
comment|/*  * Config offsets for VIA AGP 3.0 chipsets.  */
end_comment

begin_define
define|#
directive|define
name|AGP3_VIA_GARTCTRL
value|0x90
end_define

begin_define
define|#
directive|define
name|AGP3_VIA_APSIZE
value|0x94
end_define

begin_define
define|#
directive|define
name|AGP3_VIA_ATTBASE
value|0x98
end_define

begin_define
define|#
directive|define
name|AGP_VIA_AGPSEL
value|0xfd
end_define

begin_comment
comment|/*  * Config offsets for SiS AGP chipsets.  */
end_comment

begin_define
define|#
directive|define
name|AGP_SIS_ATTBASE
value|0x90
end_define

begin_define
define|#
directive|define
name|AGP_SIS_WINCTRL
value|0x94
end_define

begin_define
define|#
directive|define
name|AGP_SIS_TLBCTRL
value|0x97
end_define

begin_define
define|#
directive|define
name|AGP_SIS_TLBFLUSH
value|0x98
end_define

begin_comment
comment|/*  * Config offsets for Ali AGP chipsets.  */
end_comment

begin_define
define|#
directive|define
name|AGP_ALI_AGPCTRL
value|0xb8
end_define

begin_define
define|#
directive|define
name|AGP_ALI_ATTBASE
value|0xbc
end_define

begin_define
define|#
directive|define
name|AGP_ALI_TLBCTRL
value|0xc0
end_define

begin_comment
comment|/*  * Config offsets for the AMD 751 chipset.  */
end_comment

begin_define
define|#
directive|define
name|AGP_AMD751_APBASE
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_REGISTERS
value|0x14
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_APCTRL
value|0xac
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_MODECTRL
value|0xb0
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_MODECTRL_SYNEN
value|0x80
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_MODECTRL2
value|0xb2
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_MODECTRL2_G1LM
value|0x01
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_MODECTRL2_GPDCE
value|0x02
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_MODECTRL2_NGSE
value|0x08
end_define

begin_comment
comment|/*  * Memory mapped register offsets for AMD 751 chipset.  */
end_comment

begin_define
define|#
directive|define
name|AGP_AMD751_CAPS
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_CAPS_EHI
value|0x0800
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_CAPS_P2P
value|0x0400
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_CAPS_MPC
value|0x0200
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_CAPS_VBE
value|0x0100
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_CAPS_REV
value|0x00ff
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_STATUS_P2PS
value|0x0800
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_STATUS_GCS
value|0x0400
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_STATUS_MPS
value|0x0200
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_STATUS_VBES
value|0x0100
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_STATUS_P2PE
value|0x0008
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_STATUS_GCE
value|0x0004
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_STATUS_VBEE
value|0x0001
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_ATTBASE
value|0x04
end_define

begin_define
define|#
directive|define
name|AGP_AMD751_TLBCTRL
value|0x0c
end_define

begin_comment
comment|/*  * Config registers for i810 device 0  */
end_comment

begin_define
define|#
directive|define
name|AGP_I810_SMRAM
value|0x70
end_define

begin_define
define|#
directive|define
name|AGP_I810_SMRAM_GMS
value|0xc0
end_define

begin_define
define|#
directive|define
name|AGP_I810_SMRAM_GMS_DISABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I810_SMRAM_GMS_ENABLED_0
value|0x40
end_define

begin_define
define|#
directive|define
name|AGP_I810_SMRAM_GMS_ENABLED_512
value|0x80
end_define

begin_define
define|#
directive|define
name|AGP_I810_SMRAM_GMS_ENABLED_1024
value|0xc0
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC
value|0x72
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_WINSIZE
value|0x0001
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_WINSIZE_64
value|0x0000
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_WINSIZE_32
value|0x0001
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_PLCK
value|0x0008
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_PLCK_UNLOCKED
value|0x0000
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_PLCK_LOCKED
value|0x0008
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_WPTC
value|0x0030
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_WPTC_NOLIMIT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_WPTC_62
value|0x0010
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_WPTC_50
value|0x0020
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_WPTC_37
value|0x0030
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_RPTC
value|0x00c0
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_RPTC_NOLIMIT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_RPTC_62
value|0x0040
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_RPTC_50
value|0x0080
end_define

begin_define
define|#
directive|define
name|AGP_I810_MISCC_RPTC_37
value|0x00c0
end_define

begin_comment
comment|/*  * Config registers for i810 device 1  */
end_comment

begin_define
define|#
directive|define
name|AGP_I810_GMADR
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_I810_MMADR
value|0x14
end_define

begin_define
define|#
directive|define
name|I810_PTE_VALID
value|0x00000001
end_define

begin_comment
comment|/*  * Cache control  *  * Pre-Sandybridge bits  */
end_comment

begin_define
define|#
directive|define
name|I810_PTE_MAIN_UNCACHED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|I810_PTE_LOCAL
value|0x00000002
end_define

begin_comment
comment|/* Non-snooped main phys memory */
end_comment

begin_define
define|#
directive|define
name|I830_PTE_SYSTEM_CACHED
value|0x00000006
end_define

begin_comment
comment|/* Snooped main phys memory */
end_comment

begin_comment
comment|/*  * Sandybridge  * LLC - Last Level Cache  * MMC - Mid Level Cache  */
end_comment

begin_define
define|#
directive|define
name|GEN6_PTE_RESERVED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GEN6_PTE_UNCACHED
value|0x00000002
end_define

begin_comment
comment|/* Do not cache */
end_comment

begin_define
define|#
directive|define
name|GEN6_PTE_LLC
value|0x00000004
end_define

begin_comment
comment|/* Cache in LLC */
end_comment

begin_define
define|#
directive|define
name|GEN6_PTE_LLC_MLC
value|0x00000006
end_define

begin_comment
comment|/* Cache in LLC and MLC */
end_comment

begin_define
define|#
directive|define
name|GEN6_PTE_GFDT
value|0x00000008
end_define

begin_comment
comment|/* Graphics Data Type */
end_comment

begin_comment
comment|/*  * Memory mapped register offsets for i810 chipset.  */
end_comment

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_CTL
value|0x2020
end_define

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_ENABLED
value|0x00000001
end_define

begin_comment
comment|/**  * This field determines the actual size of the global GTT on the 965  * and G33  */
end_comment

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_SIZE_MASK
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_SIZE_512KB
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_SIZE_256KB
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_SIZE_128KB
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_SIZE_1MB
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_SIZE_2MB
value|(4<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_I810_PGTBL_SIZE_1_5MB
value|(5<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_G33_GCC1_SIZE_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G33_GCC1_SIZE_1M
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G33_GCC1_SIZE_2M
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G4x_GCC1_SIZE_MASK
value|(0xf<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G4x_GCC1_SIZE_1M
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G4x_GCC1_SIZE_2M
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G4x_GCC1_SIZE_VT_EN
value|(0x8<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G4x_GCC1_SIZE_VT_1M
define|\
value|(AGP_G4x_GCC1_SIZE_1M | AGP_G4x_GCC1_SIZE_VT_EN)
end_define

begin_define
define|#
directive|define
name|AGP_G4x_GCC1_SIZE_VT_1_5M
value|((0x2<< 8) | AGP_G4x_GCC1_SIZE_VT_EN)
end_define

begin_define
define|#
directive|define
name|AGP_G4x_GCC1_SIZE_VT_2M
define|\
value|(AGP_G4x_GCC1_SIZE_2M | AGP_G4x_GCC1_SIZE_VT_EN)
end_define

begin_define
define|#
directive|define
name|AGP_I810_DRT
value|0x3000
end_define

begin_define
define|#
directive|define
name|AGP_I810_DRT_UNPOPULATED
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I810_DRT_POPULATED
value|0x01
end_define

begin_define
define|#
directive|define
name|AGP_I810_GTT
value|0x10000
end_define

begin_comment
comment|/*  * Config registers for i830MG device 0  */
end_comment

begin_define
define|#
directive|define
name|AGP_I830_GCC1
value|0x52
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_DEV2
value|0x08
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_DEV2_ENABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_DEV2_DISABLED
value|0x08
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_GMS
value|0xf0
end_define

begin_comment
comment|/* Top bit reserved pre-G33 */
end_comment

begin_define
define|#
directive|define
name|AGP_I830_GCC1_GMS_STOLEN_512
value|0x20
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_GMS_STOLEN_1024
value|0x30
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_GMS_STOLEN_8192
value|0x40
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_GMASIZE
value|0x01
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_GMASIZE_64
value|0x01
end_define

begin_define
define|#
directive|define
name|AGP_I830_GCC1_GMASIZE_128
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I830_HIC
value|0x70
end_define

begin_comment
comment|/*  * Config registers for 852GM/855GM/865G device 0  */
end_comment

begin_define
define|#
directive|define
name|AGP_I855_GCC1
value|0x52
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_DEV2
value|0x08
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_DEV2_ENABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_DEV2_DISABLED
value|0x08
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_GMS
value|0xf0
end_define

begin_comment
comment|/* Top bit reserved pre-G33 */
end_comment

begin_define
define|#
directive|define
name|AGP_I855_GCC1_GMS_STOLEN_0M
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_GMS_STOLEN_1M
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_GMS_STOLEN_4M
value|0x20
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_GMS_STOLEN_8M
value|0x30
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_GMS_STOLEN_16M
value|0x40
end_define

begin_define
define|#
directive|define
name|AGP_I855_GCC1_GMS_STOLEN_32M
value|0x50
end_define

begin_comment
comment|/*  * 852GM/855GM variant identification  */
end_comment

begin_define
define|#
directive|define
name|AGP_I85X_CAPID
value|0x44
end_define

begin_define
define|#
directive|define
name|AGP_I85X_VARIANT_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|AGP_I85X_VARIANT_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|AGP_I855_GME
value|0x0
end_define

begin_define
define|#
directive|define
name|AGP_I855_GM
value|0x4
end_define

begin_define
define|#
directive|define
name|AGP_I852_GME
value|0x2
end_define

begin_define
define|#
directive|define
name|AGP_I852_GM
value|0x5
end_define

begin_comment
comment|/*  * 915G registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_I915_GMADR
value|0x18
end_define

begin_define
define|#
directive|define
name|AGP_I915_MMADR
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_I915_GTTADR
value|0x1C
end_define

begin_define
define|#
directive|define
name|AGP_I915_GCC1_GMS_STOLEN_48M
value|0x60
end_define

begin_define
define|#
directive|define
name|AGP_I915_GCC1_GMS_STOLEN_64M
value|0x70
end_define

begin_define
define|#
directive|define
name|AGP_I915_DEVEN
value|0x54
end_define

begin_define
define|#
directive|define
name|AGP_SB_DEVEN_D2EN
value|0x10
end_define

begin_comment
comment|/* SB+ has IGD enabled bit */
end_comment

begin_define
define|#
directive|define
name|AGP_SB_DEVEN_D2EN_ENABLED
value|0x10
end_define

begin_comment
comment|/* in different place */
end_comment

begin_define
define|#
directive|define
name|AGP_SB_DEVEN_D2EN_DISABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I915_DEVEN_D2F0
value|0x08
end_define

begin_define
define|#
directive|define
name|AGP_I915_DEVEN_D2F0_ENABLED
value|0x08
end_define

begin_define
define|#
directive|define
name|AGP_I915_DEVEN_D2F0_DISABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I915_MSAC
value|0x62
end_define

begin_define
define|#
directive|define
name|AGP_I915_MSAC_GMASIZE
value|0x02
end_define

begin_define
define|#
directive|define
name|AGP_I915_MSAC_GMASIZE_128
value|0x02
end_define

begin_define
define|#
directive|define
name|AGP_I915_MSAC_GMASIZE_256
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I915_IFPADDR
value|0x60
end_define

begin_comment
comment|/*  * G965 registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_I965_GTTMMADR
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_I965_MSAC
value|0x62
end_define

begin_define
define|#
directive|define
name|AGP_I965_MSAC_GMASIZE_128
value|0x00
end_define

begin_define
define|#
directive|define
name|AGP_I965_MSAC_GMASIZE_256
value|0x02
end_define

begin_define
define|#
directive|define
name|AGP_I965_MSAC_GMASIZE_512
value|0x06
end_define

begin_define
define|#
directive|define
name|AGP_I965_PGTBL_SIZE_1MB
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_I965_PGTBL_SIZE_2MB
value|(4<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_I965_PGTBL_SIZE_1_5MB
value|(5<< 1)
end_define

begin_define
define|#
directive|define
name|AGP_I965_PGTBL_CTL2
value|0x20c4
end_define

begin_define
define|#
directive|define
name|AGP_I965_IFPADDR
value|0x70
end_define

begin_comment
comment|/*  * G33 registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_G33_MGGC_GGMS_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G33_MGGC_GGMS_SIZE_1M
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G33_MGGC_GGMS_SIZE_2M
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_G33_GCC1_GMS_STOLEN_128M
value|0x80
end_define

begin_define
define|#
directive|define
name|AGP_G33_GCC1_GMS_STOLEN_256M
value|0x90
end_define

begin_comment
comment|/*  * G4X registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_G4X_GMADR
value|0x20
end_define

begin_define
define|#
directive|define
name|AGP_G4X_MMADR
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_G4X_GTTADR
value|0x18
end_define

begin_define
define|#
directive|define
name|AGP_G4X_GCC1_GMS_STOLEN_96M
value|0xa0
end_define

begin_define
define|#
directive|define
name|AGP_G4X_GCC1_GMS_STOLEN_160M
value|0xb0
end_define

begin_define
define|#
directive|define
name|AGP_G4X_GCC1_GMS_STOLEN_224M
value|0xc0
end_define

begin_define
define|#
directive|define
name|AGP_G4X_GCC1_GMS_STOLEN_352M
value|0xd0
end_define

begin_comment
comment|/*  * SandyBridge/IvyBridge registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_SNB_GCC1
value|0x50
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_MASK
value|0xF8
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_32M
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_64M
value|(2<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_96M
value|(3<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_128M
value|(4<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_160M
value|(5<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_192M
value|(6<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_224M
value|(7<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_256M
value|(8<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_288M
value|(9<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_320M
value|(0xa<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_352M
value|(0xb<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_384M
value|(0xc<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_416M
value|(0xd<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_448M
value|(0xe<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_480M
value|(0xf<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GMCH_GMS_STOLEN_512M
value|(0x10<< 3)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GTT_SIZE_0M
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GTT_SIZE_1M
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GTT_SIZE_2M
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GTT_SIZE_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|AGP_SNB_GFX_MODE
value|0x02520
end_define

begin_comment
comment|/*  * NVIDIA nForce/nForce2 registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_NVIDIA_0_APBASE
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_NVIDIA_0_APSIZE
value|0x80
end_define

begin_define
define|#
directive|define
name|AGP_NVIDIA_1_WBC
value|0xf0
end_define

begin_define
define|#
directive|define
name|AGP_NVIDIA_2_GARTCTRL
value|0xd0
end_define

begin_define
define|#
directive|define
name|AGP_NVIDIA_2_APBASE
value|0xd8
end_define

begin_define
define|#
directive|define
name|AGP_NVIDIA_2_APLIMIT
value|0xdc
end_define

begin_define
define|#
directive|define
name|AGP_NVIDIA_2_ATTBASE
parameter_list|(
name|i
parameter_list|)
value|(0xe0 + (i) * 4)
end_define

begin_define
define|#
directive|define
name|AGP_NVIDIA_3_APBASE
value|0x50
end_define

begin_define
define|#
directive|define
name|AGP_NVIDIA_3_APLIMIT
value|0x54
end_define

begin_comment
comment|/*  * AMD64 GART registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_AMD64_APCTRL
value|0x90
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_APBASE
value|0x94
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_ATTBASE
value|0x98
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_CACHECTRL
value|0x9c
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_APCTRL_GARTEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_APCTRL_SIZE_MASK
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_APCTRL_DISGARTCPU
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_APCTRL_DISGARTIO
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_APCTRL_DISWLKPRB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_APBASE_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_ATTBASE_MASK
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_CACHECTRL_INVGART
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_CACHECTRL_PTEERR
value|0x00000002
end_define

begin_comment
comment|/*  * NVIDIA nForce3 registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_AMD64_NVIDIA_0_APBASE
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_NVIDIA_1_APBASE1
value|0x50
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_NVIDIA_1_APLIMIT1
value|0x54
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_NVIDIA_1_APSIZE
value|0xa8
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_NVIDIA_1_APBASE2
value|0xd8
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_NVIDIA_1_APLIMIT2
value|0xdc
end_define

begin_comment
comment|/*  * ULi M1689 registers  */
end_comment

begin_define
define|#
directive|define
name|AGP_AMD64_ULI_APBASE
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_ULI_HTT_FEATURE
value|0x50
end_define

begin_define
define|#
directive|define
name|AGP_AMD64_ULI_ENU_SCR
value|0x54
end_define

begin_comment
comment|/*  * ATI IGP registers  */
end_comment

begin_define
define|#
directive|define
name|ATI_GART_MMADDR
value|0x14
end_define

begin_define
define|#
directive|define
name|ATI_RS100_APSIZE
value|0xac
end_define

begin_define
define|#
directive|define
name|ATI_RS100_IG_AGPMODE
value|0xb0
end_define

begin_define
define|#
directive|define
name|ATI_RS300_APSIZE
value|0xf8
end_define

begin_define
define|#
directive|define
name|ATI_RS300_IG_AGPMODE
value|0xfc
end_define

begin_define
define|#
directive|define
name|ATI_GART_FEATURE_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|ATI_GART_BASE
value|0x04
end_define

begin_define
define|#
directive|define
name|ATI_GART_CACHE_CNTRL
value|0x0c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PCI_AGPREG_H_ */
end_comment

end_unit

