begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Orion Hodson<O.Hodson@cs.ucl.ac.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CS4281_H_
end_ifndef

begin_define
define|#
directive|define
name|_CS4281_H_
end_define

begin_define
define|#
directive|define
name|CS4281_PCI_ID
value|0x60051013
end_define

begin_comment
comment|/* Ball Parks */
end_comment

begin_define
define|#
directive|define
name|CS4281PCI_BA0_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|CS4281PCI_BA1_SIZE
value|65536
end_define

begin_comment
comment|/* Register values */
end_comment

begin_define
define|#
directive|define
name|CS4281PCI_HISR
value|0x000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HISR_DMAI
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HISR_DMA
parameter_list|(
name|x
parameter_list|)
value|(0x0100<< (x))
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HICR
value|0x008
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HICR_EOI
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HIMR
value|0x00c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HIMR_DMAI
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HIMR_DMA
parameter_list|(
name|x
parameter_list|)
value|(0x0100<< (x))
end_define

begin_define
define|#
directive|define
name|CS4281PCI_IIER
value|0x010
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HDSR
parameter_list|(
name|x
parameter_list|)
value|(0x0f0 + (x)*0x004)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HDSR_CH1P
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HDSR_CH2P
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HDSR_HDTC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HDSR_DTC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HDSR_DRUN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_HDSR_RQ
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DCA
parameter_list|(
name|x
parameter_list|)
value|(0x110 + (x) * 0x010)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DCC
parameter_list|(
name|x
parameter_list|)
value|(0x114 + (x) * 0x010)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DBA
parameter_list|(
name|x
parameter_list|)
value|(0x118 + (x) * 0x010)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DBC
parameter_list|(
name|x
parameter_list|)
value|(0x11c + (x) * 0x010)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR
parameter_list|(
name|x
parameter_list|)
value|(0x150 + (x) * 0x008)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_DMA
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_POLL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_TBC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_CBC
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_SWAPC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_SIZE20
value|0x00100000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_USIGN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_BEND
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_MONO
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_SIZE8
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_TYPE_DEMAND
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_TYPE_SINGLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_TYPE_BLOCK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_TYPE_CASCADE
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_DEC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_AUTO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_TR_PLAY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DMR_TR_REC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DCR
parameter_list|(
name|x
parameter_list|)
value|(0x154 + (x) * 0x008)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DCR_HTCIE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DCR_TCIE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DCR_MSK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCR
parameter_list|(
name|x
parameter_list|)
value|(0x180 + (x) * 0x004)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCR_FEN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCR_DACZ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCR_PSH
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCR_RS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCR_LS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCR_SZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCR_OF
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FPDR
parameter_list|(
name|x
parameter_list|)
value|(0x190 + (x) * 0x004)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FCHS
value|0x20c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FSIC
parameter_list|(
name|x
parameter_list|)
value|(0x210 + (x) * 0x004)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_PMCS
value|0x344
end_define

begin_define
define|#
directive|define
name|CS4281PCI_PMCS_PS_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CS4281PCI_PMCS_OFFSET
value|(CS4281PCI_PMCS - 0x300)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CWPR
value|0x3e0
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CWPR_MAGIC
value|0x00004281
end_define

begin_define
define|#
directive|define
name|CS4281PCI_EPPMC
value|0x3e4
end_define

begin_define
define|#
directive|define
name|CS4281PCI_EPPMC_FPDN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_GPIOR
value|0x3e8
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC
value|0x3ec
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_RSTN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_ASYN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_WUP1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_WUP2
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_ASDO
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_ASDI2E
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_EESPD
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_GISPEN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SPMC_GIPPEN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CFLR
value|0x3f0
end_define

begin_define
define|#
directive|define
name|CS4281PCI_IISR
value|0x3f4
end_define

begin_define
define|#
directive|define
name|CS4281PCI_TMS
value|0x3f8
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSVID
value|0x3fc
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CLKCR1
value|0x400
end_define

begin_define
define|#
directive|define
name|CS_4281PCI_CLKCR1_DLLSS_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|CS_4281PCI_CLKCR1_DLLSS_AC97
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CLKCR1_DLLP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CLKCR1_SWCE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CLKCR1_DLLOS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CLKCR1_CKRA
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CLKCR1_DLLRDY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_CLKCR1_CLKON
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_FRR
value|0x410
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SLT12O
value|0x41c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SERMC
value|0x420
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SERMC_PTC_AC97
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SERMC_PTC_MASK
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SERMC_ODSEN1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SERMC_ODSEN2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SERC1
value|0x428
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SERC2
value|0x42c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SLT12M
value|0x45c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACCTL
value|0x460
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACCTL_ESYN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACCTL_VFRM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACCTL_DCV
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACCTL_CRW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACCTL_TC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACSTS
value|0x464
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACSTS_CRDY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACSTS_VSTS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACOSV
value|0x468
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACOSV_SLV
parameter_list|(
name|x
parameter_list|)
value|(1<< (x - 3))
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACCAD
value|0x46c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACCDA
value|0x470
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACISV
value|0x474
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACISV_ISV
parameter_list|(
name|x
parameter_list|)
value|(1<< (x - 3))
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACSAD
value|0x478
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ACSDA
value|0x47c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_JSPT
value|0x480
end_define

begin_define
define|#
directive|define
name|CS4281PCI_JSCTL
value|0x484
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSPM
value|0x740
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSPM_MIXEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSPM_CSRCEN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSPM_PSRCEN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSPM_JSEN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSPM_ACLEN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSPM_FMEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DACSR
value|0x744
end_define

begin_define
define|#
directive|define
name|CS4281PCI_ADCSR
value|0x748
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SSCR
value|0x74c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SRCSA
value|0x75c
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SRCSA_PLSS
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SRCSA_PRSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SRCSA_CLSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_SRCSA_CRSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|CS4281PCI_PPLVC
value|0x760
end_define

begin_define
define|#
directive|define
name|CS4281PCI_PPRVC
value|0x764
end_define

begin_comment
comment|/* Slot definitions (minimal) */
end_comment

begin_define
define|#
directive|define
name|CS4281PCI_LPCM_PLAY_SLOT
value|0x00
end_define

begin_define
define|#
directive|define
name|CS4281PCI_RPCM_PLAY_SLOT
value|0x01
end_define

begin_define
define|#
directive|define
name|CS4281PCI_LPCM_REC_SLOT
value|0x0a
end_define

begin_define
define|#
directive|define
name|CS4281PCI_RPCM_REC_SLOT
value|0x0b
end_define

begin_define
define|#
directive|define
name|CS4281PCI_DISABLED_SLOT
value|0x1f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CS4281_H_ */
end_comment

end_unit

