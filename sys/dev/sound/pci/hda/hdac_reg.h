begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Stephane E. Potvin<sepotvin@videotron.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HDAC_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_HDAC_REG_H_
end_define

begin_comment
comment|/****************************************************************************  * HDA Controller Register Set  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HDAC_GCAP
value|0x00
end_define

begin_comment
comment|/* 2 - Global Capabilities*/
end_comment

begin_define
define|#
directive|define
name|HDAC_VMIN
value|0x02
end_define

begin_comment
comment|/* 1 - Minor Version */
end_comment

begin_define
define|#
directive|define
name|HDAC_VMAJ
value|0x03
end_define

begin_comment
comment|/* 1 - Major Version */
end_comment

begin_define
define|#
directive|define
name|HDAC_OUTPAY
value|0x04
end_define

begin_comment
comment|/* 2 - Output Payload Capability */
end_comment

begin_define
define|#
directive|define
name|HDAC_INPAY
value|0x06
end_define

begin_comment
comment|/* 2 - Input Payload Capability */
end_comment

begin_define
define|#
directive|define
name|HDAC_GCTL
value|0x08
end_define

begin_comment
comment|/* 4 - Global Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_WAKEEN
value|0x0c
end_define

begin_comment
comment|/* 2 - Wake Enable */
end_comment

begin_define
define|#
directive|define
name|HDAC_STATESTS
value|0x0e
end_define

begin_comment
comment|/* 2 - State Change Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_GSTS
value|0x10
end_define

begin_comment
comment|/* 2 - Global Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_OUTSTRMPAY
value|0x18
end_define

begin_comment
comment|/* 2 - Output Stream Payload Capability */
end_comment

begin_define
define|#
directive|define
name|HDAC_INSTRMPAY
value|0x1a
end_define

begin_comment
comment|/* 2 - Input Stream Payload Capability */
end_comment

begin_define
define|#
directive|define
name|HDAC_INTCTL
value|0x20
end_define

begin_comment
comment|/* 4 - Interrupt Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_INTSTS
value|0x24
end_define

begin_comment
comment|/* 4 - Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_WALCLK
value|0x30
end_define

begin_comment
comment|/* 4 - Wall Clock Counter */
end_comment

begin_define
define|#
directive|define
name|HDAC_SSYNC
value|0x38
end_define

begin_comment
comment|/* 4 - Stream Synchronization */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBLBASE
value|0x40
end_define

begin_comment
comment|/* 4 - CORB Lower Base Address */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBUBASE
value|0x44
end_define

begin_comment
comment|/* 4 - CORB Upper Base Address */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBWP
value|0x48
end_define

begin_comment
comment|/* 2 - CORB Write Pointer */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBRP
value|0x4a
end_define

begin_comment
comment|/* 2 - CORB Read Pointer */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBCTL
value|0x4c
end_define

begin_comment
comment|/* 1 - CORB Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBSTS
value|0x4d
end_define

begin_comment
comment|/* 1 - CORB Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBSIZE
value|0x4e
end_define

begin_comment
comment|/* 1 - CORB Size */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBLBASE
value|0x50
end_define

begin_comment
comment|/* 4 - RIRB Lower Base Address */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBUBASE
value|0x54
end_define

begin_comment
comment|/* 4 - RIRB Upper Base Address */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBWP
value|0x58
end_define

begin_comment
comment|/* 2 - RIRB Write Pointer */
end_comment

begin_define
define|#
directive|define
name|HDAC_RINTCNT
value|0x5a
end_define

begin_comment
comment|/* 2 - Response Interrupt Count */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBCTL
value|0x5c
end_define

begin_comment
comment|/* 1 - RIRB Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBSTS
value|0x5d
end_define

begin_comment
comment|/* 1 - RIRB Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE
value|0x5e
end_define

begin_comment
comment|/* 1 - RIRB Size */
end_comment

begin_define
define|#
directive|define
name|HDAC_ICOI
value|0x60
end_define

begin_comment
comment|/* 4 - Immediate Command Output Interface */
end_comment

begin_define
define|#
directive|define
name|HDAC_ICII
value|0x64
end_define

begin_comment
comment|/* 4 - Immediate Command Input Interface */
end_comment

begin_define
define|#
directive|define
name|HDAC_ICIS
value|0x68
end_define

begin_comment
comment|/* 2 - Immediate Command Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_DPIBLBASE
value|0x70
end_define

begin_comment
comment|/* 4 - DMA Position Buffer Lower Base */
end_comment

begin_define
define|#
directive|define
name|HDAC_DPIBUBASE
value|0x74
end_define

begin_comment
comment|/* 4 - DMA Position Buffer Upper Base */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDCTL0
value|0x80
end_define

begin_comment
comment|/* 3 - Stream Descriptor Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDCTL1
value|0x81
end_define

begin_comment
comment|/* 3 - Stream Descriptor Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDCTL2
value|0x82
end_define

begin_comment
comment|/* 3 - Stream Descriptor Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDSTS
value|0x83
end_define

begin_comment
comment|/* 1 - Stream Descriptor Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDLPIB
value|0x84
end_define

begin_comment
comment|/* 4 - Link Position in Buffer */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDCBL
value|0x88
end_define

begin_comment
comment|/* 4 - Cyclic Buffer Length */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDLVI
value|0x8C
end_define

begin_comment
comment|/* 2 - Last Valid Index */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDFIFOS
value|0x90
end_define

begin_comment
comment|/* 2 - FIFOS */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDFMT
value|0x92
end_define

begin_comment
comment|/* 2 - fmt */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDBDPL
value|0x98
end_define

begin_comment
comment|/* 4 - Buffer Descriptor Pointer Lower Base */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDBDPU
value|0x9C
end_define

begin_comment
comment|/* 4 - Buffer Descriptor Pointer Upper Base */
end_comment

begin_define
define|#
directive|define
name|_HDAC_ISDOFFSET
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x80 + ((n) * 0x20))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDCTL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x00 + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDSTS
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x03 + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDPICB
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x04 + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDCBL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x08 + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDLVI
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x0c + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDFIFOD
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x10 + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDFMT
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x12 + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDBDPL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x18 + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_ISDBDPU
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x1c + _HDAC_ISDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDOFFSET
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x80 + ((iss) * 0x20) + ((n) * 0x20))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDCTL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x00 + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDSTS
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x03 + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDPICB
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x04 + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDCBL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x08 + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDLVI
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x0c + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDFIFOD
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x10 + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDFMT
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x12 + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDBDPL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x18 + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_OSDBDPU
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x1c + _HDAC_OSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDOFFSET
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x80 + ((iss) * 0x20) + ((oss) * 0x20) + ((n) * 0x20))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDCTL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x00 + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDSTS
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x03 + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDPICB
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x04 + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDCBL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x08 + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDLVI
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x0c + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDFIFOD
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x10 + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDFMT
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x12 + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDBDPL
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x18 + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_define
define|#
directive|define
name|_HDAC_BSDBDBU
parameter_list|(
name|n
parameter_list|,
name|iss
parameter_list|,
name|oss
parameter_list|)
value|(0x1c + _HDAC_BSDOFFSET(n, iss, oss))
end_define

begin_comment
comment|/****************************************************************************  * HDA Controller Register Fields  ****************************************************************************/
end_comment

begin_comment
comment|/* GCAP - Global Capabilities */
end_comment

begin_define
define|#
directive|define
name|HDAC_GCAP_64OK
value|0x0001
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_NSDO_MASK
value|0x0006
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_NSDO_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_BSS_MASK
value|0x00f8
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_BSS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_ISS_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_ISS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_OSS_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_OSS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_NSDO_1SDO
value|0x00
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_NSDO_2SDO
value|0x02
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_NSDO_4SDO
value|0x04
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_BSS
parameter_list|(
name|gcap
parameter_list|)
define|\
value|(((gcap)& HDAC_GCAP_BSS_MASK)>> HDAC_GCAP_BSS_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_ISS
parameter_list|(
name|gcap
parameter_list|)
define|\
value|(((gcap)& HDAC_GCAP_ISS_MASK)>> HDAC_GCAP_ISS_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_OSS
parameter_list|(
name|gcap
parameter_list|)
define|\
value|(((gcap)& HDAC_GCAP_OSS_MASK)>> HDAC_GCAP_OSS_SHIFT)
end_define

begin_define
define|#
directive|define
name|HDAC_GCAP_NSDO
parameter_list|(
name|gcap
parameter_list|)
define|\
value|(((gcap)& HDAC_GCAP_NSDO_MASK)>> HDAC_GCAP_NSDO_SHIFT)
end_define

begin_comment
comment|/* GCTL - Global Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_GCTL_CRST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDAC_GCTL_FCNTRL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HDAC_GCTL_UNSOL
value|0x00000100
end_define

begin_comment
comment|/* WAKEEN - Wake Enable */
end_comment

begin_define
define|#
directive|define
name|HDAC_WAKEEN_SDIWEN_MASK
value|0x7fff
end_define

begin_define
define|#
directive|define
name|HDAC_WAKEEN_SDIWEN_SHIFT
value|0
end_define

begin_comment
comment|/* STATESTS - State Change Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_STATESTS_SDIWAKE_MASK
value|0x7fff
end_define

begin_define
define|#
directive|define
name|HDAC_STATESTS_SDIWAKE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDAC_STATESTS_SDIWAKE
parameter_list|(
name|statests
parameter_list|,
name|n
parameter_list|)
define|\
value|(((((statests)& HDAC_STATESTS_SDIWAKE_MASK)>>			\     HDAC_STATESTS_SDIWAKE_SHIFT)>> (n))& 0x0001)
end_define

begin_comment
comment|/* GSTS - Global Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_GSTS_FSTS
value|0x0002
end_define

begin_comment
comment|/* INTCTL - Interrut Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_INTCTL_SIE_MASK
value|0x3fffffff
end_define

begin_define
define|#
directive|define
name|HDAC_INTCTL_SIE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDAC_INTCTL_CIE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|HDAC_INTCTL_GIE
value|0x80000000
end_define

begin_comment
comment|/* INTSTS - Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_INTSTS_SIS_MASK
value|0x3fffffff
end_define

begin_define
define|#
directive|define
name|HDAC_INTSTS_SIS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDAC_INTSTS_CIS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|HDAC_INTSTS_GIS
value|0x80000000
end_define

begin_comment
comment|/* SSYNC - Stream Synchronization */
end_comment

begin_define
define|#
directive|define
name|HDAC_SSYNC_SSYNC_MASK
value|0x3fffffff
end_define

begin_define
define|#
directive|define
name|HDAC_SSYNC_SSYNC_SHIFT
value|0
end_define

begin_comment
comment|/* CORBWP - CORB Write Pointer */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBWP_CORBWP_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|HDAC_CORBWP_CORBWP_SHIFT
value|0
end_define

begin_comment
comment|/* CORBRP - CORB Read Pointer */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBRP_CORBRP_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|HDAC_CORBRP_CORBRP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDAC_CORBRP_CORBRPRST
value|0x8000
end_define

begin_comment
comment|/* CORBCTL - CORB Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBCTL_CMEIE
value|0x01
end_define

begin_define
define|#
directive|define
name|HDAC_CORBCTL_CORBRUN
value|0x02
end_define

begin_comment
comment|/* CORBSTS - CORB Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBSTS_CMEI
value|0x01
end_define

begin_comment
comment|/* CORBSIZE - CORB Size */
end_comment

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSIZE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSZCAP_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSZCAP_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSIZE_2
value|0x00
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSIZE_16
value|0x01
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSIZE_256
value|0x02
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSZCAP_2
value|0x10
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSZCAP_16
value|0x20
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSZCAP_256
value|0x40
end_define

begin_define
define|#
directive|define
name|HDAC_CORBSIZE_CORBSIZE
parameter_list|(
name|corbsize
parameter_list|)
define|\
value|(((corbsize)& HDAC_CORBSIZE_CORBSIZE_MASK)>> HDAC_CORBSIZE_CORBSIZE_SHIFT)
end_define

begin_comment
comment|/* RIRBWP - RIRB Write Pointer */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBWP_RIRBWP_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBWP_RIRBWP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBWP_RIRBWPRST
value|0x8000
end_define

begin_comment
comment|/* RINTCTN - Response Interrupt Count */
end_comment

begin_define
define|#
directive|define
name|HDAC_RINTCNT_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|HDAC_RINTCNT_SHIFT
value|0
end_define

begin_comment
comment|/* RIRBCTL - RIRB Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBCTL_RINTCTL
value|0x01
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBCTL_RIRBDMAEN
value|0x02
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBCTL_RIRBOIC
value|0x04
end_define

begin_comment
comment|/* RIRBSTS - RIRB Status */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBSTS_RINTFL
value|0x01
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSTS_RIRBOIS
value|0x04
end_define

begin_comment
comment|/* RIRBSIZE - RIRB Size */
end_comment

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSIZE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSZCAP_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSZCAP_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSIZE_2
value|0x00
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSIZE_16
value|0x01
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSIZE_256
value|0x02
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSZCAP_2
value|0x10
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSZCAP_16
value|0x20
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSZCAP_256
value|0x40
end_define

begin_define
define|#
directive|define
name|HDAC_RIRBSIZE_RIRBSIZE
parameter_list|(
name|rirbsize
parameter_list|)
define|\
value|(((rirbsize)& HDAC_RIRBSIZE_RIRBSIZE_MASK)>> HDAC_RIRBSIZE_RIRBSIZE_SHIFT)
end_define

begin_comment
comment|/* DPLBASE - DMA Position Lower Base Address */
end_comment

begin_define
define|#
directive|define
name|HDAC_DPLBASE_DPLBASE_MASK
value|0xffffff80
end_define

begin_define
define|#
directive|define
name|HDAC_DPLBASE_DPLBASE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HDAC_DPLBASE_DPLBASE_DMAPBE
value|0x00000001
end_define

begin_comment
comment|/* SDCTL - Stream Descriptor Control */
end_comment

begin_define
define|#
directive|define
name|HDAC_SDCTL_SRST
value|0x000001
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL_RUN
value|0x000002
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL_IOCE
value|0x000004
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL_FEIE
value|0x000008
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL_DEIE
value|0x000010
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL_STRIPE_MASK
value|0x030000
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL_STRIPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL_TP
value|0x040000
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL_DIR
value|0x080000
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL2_STRM_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|HDAC_SDCTL2_STRM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HDAC_SDSTS_DESE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HDAC_SDSTS_FIFOE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|HDAC_SDSTS_BCIS
value|(1<< 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

