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
value|0x10
end_define

begin_define
define|#
directive|define
name|AGP_CAPPTR
value|0x34
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
name|AGP_CAPID_GET_MAJOR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x00f00000U)>> 20)
end_define

begin_define
define|#
directive|define
name|AGP_CAPID_GET_MINOR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x000f0000U)>> 16)
end_define

begin_define
define|#
directive|define
name|AGP_CAPID_GET_NEXT_PTR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0000ff00U)>> 8)
end_define

begin_define
define|#
directive|define
name|AGP_CAPID_GET_CAP_ID
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x000000ffU)>> 0)
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
comment|/*  * Config offsets for VIA AGP chipsets.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PCI_AGPREG_H_ */
end_comment

end_unit

