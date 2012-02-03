begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: emuxkireg.h,v 1.8 2008/04/28 20:23:54 martin Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Yannick Montulet.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_PCI_EMUXKIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_PCI_EMUXKIREG_H_
end_define

begin_comment
comment|/*  * Register values for Creative EMU10000. The register values have been  * taken from GPLed SBLive! header file published by Creative. The comments  * have been stripped to avoid GPL pollution in kernel. The Creative version  * including comments is available in Linux 2.4.* kernel as file  *	drivers/sound/emu10k1/8010.h  */
end_comment

begin_comment
comment|/*  * Audigy specific registers contain an '_A_'  * Audigy2 specific registers contain an '_A2_'  */
end_comment

begin_define
define|#
directive|define
name|EMU_MKSUBREG
parameter_list|(
name|sz
parameter_list|,
name|idx
parameter_list|,
name|reg
parameter_list|)
value|(((sz)<< 24) | ((idx)<< 16) | (reg))
end_define

begin_define
define|#
directive|define
name|EMU_PTR
value|0x00
end_define

begin_define
define|#
directive|define
name|EMU_PTR_CHNO_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|EMU_PTR_ADDR_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|EMU_A_PTR_ADDR_MASK
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|EMU_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|EMU_IPR
value|0x08
end_define

begin_define
define|#
directive|define
name|EMU_IPR_RATETRCHANGE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_FXDSP
value|0x00800000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_FORCEINT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EMU_PCIERROR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_VOLINCR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_VOLDECR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_MUTE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_MICBUFFULL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_MICBUFHALFFULL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_ADCBUFFULL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_ADCBUFHALFFULL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_EFXBUFFULL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_EFXBUFHALFFULL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_GPSPDIFSTCHANGE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|EMU_IPR_CDROMSTCHANGE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|EMU_IPR_INTERVALTIMER
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EMU_IPR_MIDITRANSBUFE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EMU_IPR_MIDIRECVBUFE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EMU_IPR_A_MIDITRANSBUFE2
value|0x10000000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_A_MIDIRECBUFE2
value|0x08000000
end_define

begin_define
define|#
directive|define
name|EMU_IPR_CHANNELLOOP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EMU_IPR_CHNOMASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|EMU_INTE
value|0x0c
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VSB_MASK
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VSB_220
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VSB_240
value|0x40000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VSB_260
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VSB_280
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VMPU_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VMPU_300
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VMPU_310
value|0x10000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VMPU_320
value|0x20000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VMPU_330
value|0x30000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_MDMAENABLE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_SDMAENABLE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_MPICENABLE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_SPICENABLE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VSBENABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_ADLIBENABLE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_MPUENABLE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_FORCEINT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_MRHANDENABLE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_SAMPLERATER
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_FXDSPENABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_PCIERRENABLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VOLINCRENABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|EMU_INTE_VOLDECRENABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EMU_INTE_MUTEENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EMU_INTE_MICBUFENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EMU_INTE_ADCBUFENABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EMU_INTE_EFXBUFENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EMU_INTE_GPSPDIFENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EMU_INTE_CDSPDIFENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EMU_INTE_INTERTIMERENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EMU_INTE_MIDITXENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EMU_INTE_MIDIRXENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EMU_INTE_A_MIDITXENABLE2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EMU_INTE_A_MIDIRXENABLE2
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EMU_WC
value|0x10
end_define

begin_define
define|#
directive|define
name|EMU_WC_SAMPLECOUNTER_MASK
value|0x03FFFFC0
end_define

begin_define
define|#
directive|define
name|EMU_WC_SAMPLECOUNTER
value|EMU_MKSUBREG(20, 6, EMU_WC)
end_define

begin_define
define|#
directive|define
name|EMU_WC_CURRENTCHANNEL
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|EMU_HCFG
value|0x14
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYFUNC_MASK
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYFUNC_MPU
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYFUNC_SB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYFUNC_AD
value|0x60000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYFUNC_MPIC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYFUNC_MDMA
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYFUNC_SPCI
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYFUNC_SDMA
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_IOCAPTUREADDR
value|0x1f000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYWRITE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYWORD
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LEGACYINT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_CODECFMT_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_CODECFMT_AC97
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_CODECFMT_I2S
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_GPINPUT0
value|0x00004000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_GPINPUT1
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_GPOUTPUT_MASK
value|0x00001c00
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_JOYENABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_PHASETRACKENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_AC3ENABLE_MASK
value|0x000000e0
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_AC3ENABLE_ZVIDEO
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_AC3ENABLE_CDSPDIF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_AC3ENABLE_GPSPDIF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_AUTOMUTE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LOCKSOUNDCACHE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LOCKTANKCACHE_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_LOCKTANKCACHE
value|EMU_MKSUBREG(1, 2, EMU_HCFG)
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_MUTEBUTTONENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EMU_HCFG_AUDIOENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EMU_MUDATA
value|0x18
end_define

begin_define
define|#
directive|define
name|EMU_MUCMD
value|0x19
end_define

begin_define
define|#
directive|define
name|EMU_MUCMD_RESET
value|0xff
end_define

begin_define
define|#
directive|define
name|EMU_MUCMD_ENTERUARTMODE
value|0x3f
end_define

begin_define
define|#
directive|define
name|EMU_MUSTAT
value|EMU_MUCMD
end_define

begin_define
define|#
directive|define
name|EMU_MUSTAT_IRDYN
value|0x80
end_define

begin_define
define|#
directive|define
name|EMU_MUSTAT_ORDYN
value|0x40
end_define

begin_define
define|#
directive|define
name|EMU_A_IOCFG
value|0x18
end_define

begin_define
define|#
directive|define
name|EMU_A_GPINPUT_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|EMU_A_GPOUTPUT_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|EMU_A_IOCFG_GPOUT0
value|0x0044
end_define

begin_define
define|#
directive|define
name|EMU_A_IOCFG_GPOUT1
value|0x0002
end_define

begin_define
define|#
directive|define
name|EMU_TIMER
value|0x1a
end_define

begin_define
define|#
directive|define
name|EMU_TIMER_RATE_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|EMU_TIMER_RATE
value|EMU_MKSUBREG(10, 0, EMU_TIMER)
end_define

begin_define
define|#
directive|define
name|EMU_AC97DATA
value|0x1c
end_define

begin_define
define|#
directive|define
name|EMU_AC97ADDR
value|0x1e
end_define

begin_define
define|#
directive|define
name|EMU_AC97ADDR_RDY
value|0x80
end_define

begin_define
define|#
directive|define
name|EMU_AC97ADDR_ADDR
value|0x7f
end_define

begin_define
define|#
directive|define
name|EMU_A2_PTR
value|0x20
end_define

begin_define
define|#
directive|define
name|EMU_A2_DATA
value|0x24
end_define

begin_define
define|#
directive|define
name|EMU_A2_SRCSEL
value|0x600000
end_define

begin_define
define|#
directive|define
name|EMU_A2_SRCSEL_ENABLE_SPDIF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EMU_A2_SRCSEL_ENABLE_SRCMULTI
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EMU_A2_SRCMULTI
value|0x6e0000
end_define

begin_define
define|#
directive|define
name|EMU_A2_SRCMULTI_ENABLE_INPUT
value|0xff00ff00
end_define

begin_comment
comment|/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
end_comment

begin_define
define|#
directive|define
name|EMU_CHAN_CPF
value|0x00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CPF_PITCH_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CPF_PITCH
value|EMU_MKSUBREG(16, 16, EMU_CHAN_CPF)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CPF_STEREO_MASK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CPF_STEREO
value|EMU_MKSUBREG(1, 15, EMU_CHAN_CPF)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CPF_STOP_MASK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CPF_FRACADDRESS_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PTRX
value|0x01
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PTRX_PITCHTARGET_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PTRX_PITCHTARGET
value|EMU_MKSUBREG(16, 16, EMU_CHAN_PTRX)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PTRX_FXSENDAMOUNT_A_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PTRX_FXSENDAMOUNT_A
value|EMU_MKSUBREG(8, 8, EMU_CHAN_PTRX)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PTRX_FXSENDAMOUNT_B_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PTRX_FXSENDAMOUNT_B
value|EMU_MKSUBREG(8, 0, EMU_CHAN_PTRX)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CVCF
value|0x02
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CVCF_CURRVOL_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CVCF_CURRVOL
value|EMU_MKSUBREG(16, 16, EMU_CHAN_CVCF)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CVCF_CURRFILTER_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CVCF_CURRFILTER
value|EMU_MKSUBREG(16, 0, EMU_CHAN_CVCF)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_VTFT
value|0x03
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_VTFT_VOLUMETARGET_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_VTFT_VOLUMETARGET
value|EMU_MKSUBREG(16, 16, EMU_CHAN_VTFT)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_VTFT_FILTERTARGET_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_VTFT_FILTERTARGET
value|EMU_MKSUBREG(16, 0, EMU_CHAN_VTFT)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_Z1
value|0x05
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_Z2
value|0x04
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PSST
value|0x06
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PSST_FXSENDAMOUNT_C_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PSST_FXSENDAMOUNT_C
value|EMU_MKSUBREG(8, 24, EMU_CHAN_PSST)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PSST_LOOPSTARTADDR_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PSST_LOOPSTARTADDR
value|EMU_MKSUBREG(24, 0, EMU_CHAN_PSST)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DSL
value|0x07
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DSL_FXSENDAMOUNT_D_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DSL_FXSENDAMOUNT_D
value|EMU_MKSUBREG(8, 24, EMU_CHAN_DSL)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DSL_LOOPENDADDR_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DSL_LOOPENDADDR
value|EMU_MKSUBREG(24, 0, EMU_CHAN_DSL)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA
value|0x08
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_RESONANCE
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROMMASK
value|0x0e000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROM_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROM_1
value|0x02000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROM_2
value|0x04000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROM_3
value|0x06000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROM_4
value|0x08000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROM_5
value|0x0a000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROM_6
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_INTERPROM_7
value|0x0e000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_8BITSELECT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_CURRADDR_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCCA_CURRADDR
value|EMU_MKSUBREG(24, 0, EMU_CHAN_CCCA)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR
value|0x09
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_CACHEINVALIDSIZE_MASK
value|0xfe000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_CACHEINVALIDSIZE
value|EMU_MKSUBREG(7, 25, EMU_CHAN_CCR)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_CACHELOOPFLAG
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_INTERLEAVEDSAMPLES
value|0x00800000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_WORDSIZEDSAMPLES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_READADDRESS_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_READADDRESS
value|EMU_MKSUBREG(6, 16, EMU_CHAN_CCR)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_LOOPINVALSIZE
value|0x0000fe00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_LOOPFLAG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CCR_CACHELOOPADDRHI
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CLP
value|0x0a
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CLP_CACHELOOPADDR
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FXRT
value|0x0b
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FXRT_CHANNELA
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FXRT_CHANNELB
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FXRT_CHANNELC
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FXRT_CHANNELD
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_MAPA
value|0x0c
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_MAPB
value|0x0d
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_MAP_PTE_MASK
value|0xffffe000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_MAP_PTI_MASK
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ENVVOL
value|0x10
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ENVVOL_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ATKHLDV
value|0x11
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ATKHLDV_PHASE0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ATKHLDV_HOLDTIME_MASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ATKHLDV_ATTACKTIME_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSV
value|0x12
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSV_PHASE1_MASK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSV_SUSTAINLEVEL_MASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSV_CHANNELENABLE_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSV_DECAYTIME_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_LFOVAL1
value|0x13
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_LFOVAL_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ENVVAL
value|0x14
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ENVVAL_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ATKHLDM
value|0x15
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ATKHLDM_PHASE0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ATKHLDM_HOLDTIME
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_ATKHLDM_ATTACKTIME
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSM
value|0x16
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSM_PHASE1_MASK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSM_SUSTAINLEVEL_MASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_DCYSUSM_DECAYTIME_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_LFOVAL2
value|0x17
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_LFOVAL2_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_IP
value|0x18
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_IP_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_IP_UNITY
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_IFATN
value|0x19
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_IFATN_FILTERCUTOFF_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_IFATN_FILTERCUTOFF
value|EMU_MKSUBREG(8, 8,	EMU_CHAN_IFATN)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_IFATN_ATTENUATION_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_IFATN_ATTENUATION
value|EMU_MKSUBREG(8, 0, EMU_CHAN_IFATN)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PEFE
value|0x1a
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PEFE_PITCHAMOUNT_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PEFE_PITCHAMOUNT
value|EMU_MKSUBREG(8, 8, EMU_CHAN_PEFE)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PEFE_FILTERAMOUNT_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_PEFE_FILTERAMOUNT
value|EMU_MKSUBREG(8, 0, EMU_CHAN_PEFE)
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FMMOD
value|0x1b
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FMMOD_MODVIBRATO
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FMMOD_MOFILTER
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_TREMFRQ
value|0x1c
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_TREMFRQ_DEPTH
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FM2FRQ2
value|0x1d
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FM2FRQ2_DEPTH
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_FM2FRQ2_FREQUENCY
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_TEMPENV
value|0x1e
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_TEMPENV_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD0
value|0x20
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD1
value|0x21
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD2
value|0x22
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD3
value|0x23
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD4
value|0x24
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD5
value|0x25
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD6
value|0x26
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD7
value|0x27
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD8
value|0x28
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CD9
value|0x29
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CDA
value|0x2a
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CDB
value|0x2b
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CDC
value|0x2c
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CDD
value|0x2d
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CDE
value|0x2e
end_define

begin_define
define|#
directive|define
name|EMU_CHAN_CDF
value|0x2f
end_define

begin_comment
comment|/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
end_comment

begin_define
define|#
directive|define
name|EMU_PTB
value|0x40
end_define

begin_define
define|#
directive|define
name|EMU_PTB_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|EMU_TCB
value|0x41
end_define

begin_define
define|#
directive|define
name|EMU_TCB_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR
value|0x42
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_RCHANENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EMU_A_ADCCR_RCHANENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_LCHANENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EMU_A_ADCCR_LCHANENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EMU_A_ADCCR_SAMPLERATE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_48
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_44
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_32
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_24
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_22
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_16
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EMU_A_ADCCR_SAMPLERATE_12
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_11
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EMU_A_ADCCR_SAMPLERATE_11
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EMU_ADCCR_SAMPLERATE_8
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EMU_A_ADCCR_SAMPLERATE_8
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EMU_FXWC
value|0x43
end_define

begin_define
define|#
directive|define
name|EMU_TCBS
value|0x44
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_BUFFSIZE_16K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_BUFFSIZE_32K
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_BUFFSIZE_64K
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_BUFFSIZE_128K
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_BUFFSIZE_256K
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_BUFFSIZE_512K
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_BUFFSIZE_1024K
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EMU_TCBS_BUFFSIZE_2048K
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EMU_MICBA
value|0x45
end_define

begin_define
define|#
directive|define
name|EMU_ADCBA
value|0x46
end_define

begin_define
define|#
directive|define
name|EMU_FXBA
value|0x47
end_define

begin_define
define|#
directive|define
name|EMU_RECBA_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|EMU_MICBS
value|0x49
end_define

begin_define
define|#
directive|define
name|EMU_ADCBS
value|0x4a
end_define

begin_define
define|#
directive|define
name|EMU_FXBS
value|0x4b
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_384
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_448
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_512
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_640
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_768
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_896
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_1024
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_1280
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_1536
value|0x00000009
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_1792
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_2048
value|0x0000000b
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_2560
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_3072
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_3584
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_4096
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_5120
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_6144
value|0x00000011
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_7168
value|0x00000012
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_8192
value|0x00000013
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_10240
value|0x00000014
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_12288
value|0x00000015
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_14366
value|0x00000016
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_16384
value|0x00000017
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_20480
value|0x00000018
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_24576
value|0x00000019
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_28672
value|0x0000001a
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_32768
value|0x0000001b
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_40960
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_49152
value|0x0000001d
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_57344
value|0x0000001e
end_define

begin_define
define|#
directive|define
name|EMU_RECBS_BUFSIZE_65536
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|EMU_CDCS
value|0x50
end_define

begin_define
define|#
directive|define
name|EMU_GPSCS
value|0x51
end_define

begin_define
define|#
directive|define
name|EMU_DBG
value|0x52
end_define

begin_define
define|#
directive|define
name|EMU_DBG_ZC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EMU_DBG_SATURATION_OCCURRED
value|0x02000000
end_define

begin_define
define|#
directive|define
name|EMU_DBG_SATURATION_ADDR
value|0x01ff0000
end_define

begin_define
define|#
directive|define
name|EMU_DBG_SINGLE_STEP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EMU_DBG_STEP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|EMU_DBG_CONDITION_CODE
value|0x00003e00
end_define

begin_define
define|#
directive|define
name|EMU_DBG_SINGLE_STEP_ADDR
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|EMU_A_DBG
value|0x53
end_define

begin_define
define|#
directive|define
name|EMU_A_DBG_SINGLE_STEP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EMU_A_DBG_ZC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|EMU_A_DBG_STEP_ADDR
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|EMU_A_DBG_SATURATION_OCCRD
value|0x20000000
end_define

begin_define
define|#
directive|define
name|EMU_A_DBG_SATURATION_ADDR
value|0x0ffc0000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS0
value|0x54
end_define

begin_define
define|#
directive|define
name|EMU_SPCS1
value|0x55
end_define

begin_define
define|#
directive|define
name|EMU_SPCS2
value|0x56
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CLKACCYMASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CLKACCY_1000PPM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CLKACCY_50PPM
value|0x10000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CLKACCY_VARIABLE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_SAMPLERATEMASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_SAMPLERATE_44
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_SAMPLERATE_48
value|0x02000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_SAMPLERATE_32
value|0x03000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CHANNELNUMMASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CHANNELNUM_UNSPEC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CHANNELNUM_LEFT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CHANNELNUM_RIGHT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_SOURCENUMMASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_SOURCENUM_UNSPEC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_GENERATIONSTATUS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_CATEGORYCODEMASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_MODEMASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_EMPHASISMASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_EMPHASIS_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_EMPHASIS_50_15
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_COPYRIGHT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_NOTAUDIODATA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EMU_SPCS_PROFESSIONAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EMU_CLIEL
value|0x58
end_define

begin_define
define|#
directive|define
name|EMU_CLIEH
value|0x59
end_define

begin_define
define|#
directive|define
name|EMU_CLIPL
value|0x5a
end_define

begin_define
define|#
directive|define
name|EMU_CLIPH
value|0x5b
end_define

begin_define
define|#
directive|define
name|EMU_SOLEL
value|0x5c
end_define

begin_define
define|#
directive|define
name|EMU_SOLEH
value|0x5d
end_define

begin_define
define|#
directive|define
name|EMU_SPBYPASS
value|0x5e
end_define

begin_define
define|#
directive|define
name|EMU_SPBYPASS_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EMU_SPBYPASS_24_BITS
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|EMU_AC97SLOT
value|0x5f
end_define

begin_define
define|#
directive|define
name|EMU_AC97SLOT_CENTER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EMU_AC97SLOT_LFE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EMU_CDSRCS
value|0x60
end_define

begin_define
define|#
directive|define
name|EMU_GPSRCS
value|0x61
end_define

begin_define
define|#
directive|define
name|EMU_ZVSRCS
value|0x62
end_define

begin_define
define|#
directive|define
name|EMU_SRCS_SPDIFLOCKED
value|0x02000000
end_define

begin_define
define|#
directive|define
name|EMU_SRCS_RATELOCKED
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EMU_SRCS_ESTSAMPLERATE
value|0x0007ffff
end_define

begin_define
define|#
directive|define
name|EMU_MICIDX
value|0x63
end_define

begin_define
define|#
directive|define
name|EMU_A_MICIDX
value|0x64
end_define

begin_define
define|#
directive|define
name|EMU_ADCIDX
value|0x64
end_define

begin_define
define|#
directive|define
name|EMU_A_ADCIDX
value|0x63
end_define

begin_define
define|#
directive|define
name|EMU_FXIDX
value|0x65
end_define

begin_define
define|#
directive|define
name|EMU_RECIDX_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EMU_RECIDX
parameter_list|(
name|idxreg
parameter_list|)
value|(0x10000000|(idxreg))
end_define

begin_comment
comment|/* #define  EMU_MICIDX_IDX			0x10000063 #define  EMU_ADCIDX_IDX			0x10000064 #define  EMU_FXIDX_IDX			0x10000065 */
end_comment

begin_define
define|#
directive|define
name|EMU_A_MUDATA1
value|0x70
end_define

begin_define
define|#
directive|define
name|EMU_A_MUCMD1
value|0x71
end_define

begin_define
define|#
directive|define
name|EMU_A_MUSTAT1
value|EMU_A_MUCMD1
end_define

begin_define
define|#
directive|define
name|EMU_A_MUDATA2
value|0x72
end_define

begin_define
define|#
directive|define
name|EMU_A_MUCMD2
value|0x73
end_define

begin_define
define|#
directive|define
name|EMU_A_MUSTAT2
value|EMU_A_MUCMD2
end_define

begin_define
define|#
directive|define
name|EMU_A_FXWC1
value|0x74
end_define

begin_define
define|#
directive|define
name|EMU_A_FXWC2
value|0x75
end_define

begin_define
define|#
directive|define
name|EMU_A_SPDIF_SAMPLERATE
value|0x76
end_define

begin_define
define|#
directive|define
name|EMU_A_SPDIF_44100
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EMU_A_SPDIF_48000
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU_A_SPDIF_96000
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EMU_A2_SPDIF_SAMPLERATE
value|EMU_MKSUBREG(3, 9, EMU_A_SPDIF_SAMPLERATE)
end_define

begin_define
define|#
directive|define
name|EMU_A2_SPDIF_MASK
value|0x00000e00
end_define

begin_define
define|#
directive|define
name|EMU_A2_SPDIF_UNKNOWN
value|0x2
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT2
value|0x7c
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT_CHANNELE
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT_CHANNELF
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT_CHANNELG
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT_CHANNELH
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_SENDAMOUNTS
value|0x7d
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXSENDAMOUNTS_E_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXSENDAMOUNTS_F_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXSENDAMOUNTS_G_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXSENDAMOUNTS_H_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT1
value|0x7e
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT_CHANNELA
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT_CHANNELB
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT_CHANNELC
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|EMU_A_CHAN_FXRT_CHANNELD
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|EMU_FXGPREGBASE
value|0x100
end_define

begin_define
define|#
directive|define
name|EMU_A_FXGPREGBASE
value|0x400
end_define

begin_define
define|#
directive|define
name|EMU_TANKMEMDATAREGBASE
value|0x200
end_define

begin_define
define|#
directive|define
name|EMU_TANKMEMDATAREG_MASK
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|EMU_TANKMEMADDRREGBASE
value|0x300
end_define

begin_define
define|#
directive|define
name|EMU_TANKMEMADDRREG_ADDR_MASK
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|EMU_TANKMEMADDRREG_CLEAR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|EMU_TANKMEMADDRREG_ALIGN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EMU_TANKMEMADDRREG_WRITE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|EMU_TANKMEMADDRREG_READ
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EMU_MICROCODEBASE
value|0x400
end_define

begin_define
define|#
directive|define
name|EMU_A_MICROCODEBASE
value|0x600
end_define

begin_define
define|#
directive|define
name|EMU_DSP_LOWORD_OPX_MASK
value|0x000ffc00
end_define

begin_define
define|#
directive|define
name|EMU_DSP_LOWORD_OPY_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HIWORD_OPCODE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HIWORD_RESULT_MASK
value|0x000ffc00
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HIWORD_OPA_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_LOWORD_OPX_MASK
value|0x007ff000
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_LOWORD_OPY_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_HIWORD_OPCODE_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_HIWORD_RESULT_MASK
value|0x007ff000
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_HIWORD_OPA_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_MACS
value|0x0
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_MACS1
value|0x1
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_MACW
value|0x2
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_MACW1
value|0x3
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_MACINTS
value|0x4
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_MACINTW
value|0x5
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_ACC3
value|0x6
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_MACMV
value|0x7
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_ANDXOR
value|0x8
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_TSTNEG
value|0x9
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_LIMIT
value|0xA
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_LIMIT1
value|0xB
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_LOG
value|0xC
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_EXP
value|0xD
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_INTERP
value|0xE
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OP_SKIP
value|0xF
end_define

begin_define
define|#
directive|define
name|EMU_DSP_FX
parameter_list|(
name|num
parameter_list|)
value|(num)
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IOL
parameter_list|(
name|base
parameter_list|,
name|num
parameter_list|)
value|(base + (num<< 1))
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IOR
parameter_list|(
name|base
parameter_list|,
name|num
parameter_list|)
value|(EMU_DSP_IOL(base, num) + 1)
end_define

begin_define
define|#
directive|define
name|EMU_DSP_INL_BASE
value|0x010
end_define

begin_define
define|#
directive|define
name|EMU_DSP_INL
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_IOL(EMU_DSP_INL_BASE, num))
end_define

begin_define
define|#
directive|define
name|EMU_DSP_INR
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_IOR(EMU_DSP_INL_BASE, num))
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_INL_BASE
value|0x040
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_INL
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_IOL(EMU_A_DSP_INL_BASE, num))
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_INR
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_IOR(EMU_A_DSP_INL_BASE, num))
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IN_AC97
value|0
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IN_CDSPDIF
value|1
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IN_ZOOM
value|2
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IN_TOSOPT
value|3
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IN_LVDLM1
value|4
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IN_LVDCOS
value|5
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IN_LVDLM2
value|6
end_define

begin_define
define|#
directive|define
name|EMU_DSP_IN_UNKNOWN
value|7
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUTL_BASE
value|0x020
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUTL
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_IOL(EMU_DSP_OUTL_BASE, num))
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUTR
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_IOR(EMU_DSP_OUTL_BASE, num))
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUT_A_FRONT
value|0
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUT_D_FRONT
value|1
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUT_D_CENTER
value|2
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUT_DRIVE_HP
value|3
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUT_AD_REAR
value|4
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUT_ADC
value|5
end_define

begin_define
define|#
directive|define
name|EMU_DSP_OUTL_MIC
value|6
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUTL_BASE
value|0x060
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUTL
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_IOL(EMU_A_DSP_OUTL_BASE, num))
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUTR
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_IOR(EMU_A_DSP_OUTL_BASE, num))
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUT_D_FRONT
value|0
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUT_D_CENTER
value|1
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUT_DRIVE_HP
value|2
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUT_DREAR
value|3
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUT_A_FRONT
value|4
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUT_A_CENTER
value|5
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUT_A_REAR
value|7
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_OUT_ADC
value|11
end_define

begin_define
define|#
directive|define
name|EMU_DSP_CST_BASE
value|0x40
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_CST_BASE
value|0xc0
end_define

begin_define
define|#
directive|define
name|EMU_DSP_CST
parameter_list|(
name|num
parameter_list|)
value|(EMU_DSP_CST_BASE + num)
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_CST
parameter_list|(
name|num
parameter_list|)
value|(EMU_A_DSP_CST_BASE + num)
end_define

begin_comment
comment|/* 00	= 0x00000000 01	= 0x00000001 02	= 0x00000002 03	= 0x00000003 04	= 0x00000004 05	= 0x00000008 06	= 0x00000010 07	= 0x00000020 08	= 0x00000100 09	= 0x00010000 0A	= 0x00080000 0B	= 0x10000000 0C	= 0x20000000 0D	= 0x40000000 0E	= 0x80000000 0F	= 0x7FFFFFFF 10	= 0xFFFFFFFF 11	= 0xFFFFFFFE 12	= 0xC0000000 13	= 0x4F1BBCDC 14	= 0x5A7EF9DB 15	= 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|EMU_DSP_HWR_ACC
value|0x056
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_CCR
value|0x057
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_CCR_S
value|0x04
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_CCR_Z
value|0x03
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_CCR_M
value|0x02
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_CCR_N
value|0x01
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_CCR_B
value|0x00
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_NOISE0
value|0x058
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_NOISE1
value|0x059
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_INTR
value|0x05A
end_define

begin_define
define|#
directive|define
name|EMU_DSP_HWR_DBAC
value|0x05B
end_define

begin_define
define|#
directive|define
name|EMU_DSP_GPR
parameter_list|(
name|num
parameter_list|)
value|(EMU_FXGPREGBASE + num)
end_define

begin_define
define|#
directive|define
name|EMU_A_DSP_GPR
parameter_list|(
name|num
parameter_list|)
value|(EMU_A_FXGPREGBASE + num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_PCI_EMUXKIREG_H_ */
end_comment

end_unit

