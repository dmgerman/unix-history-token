begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Seigo Tanimura  * All rights reserved.  *  * Portions of this source are based on hwdefs.h in cwcealdr1.zip, the  * sample source by Crystal Semiconductor.  * Copyright (c) 1996-1998 Crystal Semiconductor Corp.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CSA_REG_H
end_ifndef

begin_define
define|#
directive|define
name|_CSA_REG_H
end_define

begin_comment
comment|/*  * The following constats are orginally in the sample by Crystal Semiconductor.  * Copyright (c) 1996-1998 Crystal Semiconductor Corp.  */
end_comment

begin_comment
comment|/*****************************************************************************  *  * The following define the offsets of the registers accessed via base address  * register zero on the CS461x part.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BA0_HISR
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|BA0_HSR0
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|BA0_HICR
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|BA0_DMSR
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|BA0_HSAR
value|0x00000110L
end_define

begin_define
define|#
directive|define
name|BA0_HDAR
value|0x00000114L
end_define

begin_define
define|#
directive|define
name|BA0_HDMR
value|0x00000118L
end_define

begin_define
define|#
directive|define
name|BA0_HDCR
value|0x0000011CL
end_define

begin_define
define|#
directive|define
name|BA0_PFMC
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|BA0_PFCV1
value|0x00000204L
end_define

begin_define
define|#
directive|define
name|BA0_PFCV2
value|0x00000208L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG00
value|0x00000300L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG04
value|0x00000304L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG08
value|0x00000308L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG0C
value|0x0000030CL
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG10
value|0x00000310L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG14
value|0x00000314L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG18
value|0x00000318L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG1C
value|0x0000031CL
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG20
value|0x00000320L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG24
value|0x00000324L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG28
value|0x00000328L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG2C
value|0x0000032CL
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG30
value|0x00000330L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG34
value|0x00000334L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG38
value|0x00000338L
end_define

begin_define
define|#
directive|define
name|BA0_PCICFG3C
value|0x0000033CL
end_define

begin_define
define|#
directive|define
name|BA0_CLKCR1
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|BA0_CLKCR2
value|0x00000404L
end_define

begin_define
define|#
directive|define
name|BA0_PLLM
value|0x00000408L
end_define

begin_define
define|#
directive|define
name|BA0_PLLCC
value|0x0000040CL
end_define

begin_define
define|#
directive|define
name|BA0_FRR
value|0x00000410L
end_define

begin_define
define|#
directive|define
name|BA0_CFL1
value|0x00000414L
end_define

begin_define
define|#
directive|define
name|BA0_CFL2
value|0x00000418L
end_define

begin_define
define|#
directive|define
name|BA0_SERMC1
value|0x00000420L
end_define

begin_define
define|#
directive|define
name|BA0_SERMC2
value|0x00000424L
end_define

begin_define
define|#
directive|define
name|BA0_SERC1
value|0x00000428L
end_define

begin_define
define|#
directive|define
name|BA0_SERC2
value|0x0000042CL
end_define

begin_define
define|#
directive|define
name|BA0_SERC3
value|0x00000430L
end_define

begin_define
define|#
directive|define
name|BA0_SERC4
value|0x00000434L
end_define

begin_define
define|#
directive|define
name|BA0_SERC5
value|0x00000438L
end_define

begin_define
define|#
directive|define
name|BA0_SERBSP
value|0x0000043CL
end_define

begin_define
define|#
directive|define
name|BA0_SERBST
value|0x00000440L
end_define

begin_define
define|#
directive|define
name|BA0_SERBCM
value|0x00000444L
end_define

begin_define
define|#
directive|define
name|BA0_SERBAD
value|0x00000448L
end_define

begin_define
define|#
directive|define
name|BA0_SERBCF
value|0x0000044CL
end_define

begin_define
define|#
directive|define
name|BA0_SERBWP
value|0x00000450L
end_define

begin_define
define|#
directive|define
name|BA0_SERBRP
value|0x00000454L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|BA0_ASER_FADDR
value|0x00000458L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BA0_ACCTL
value|0x00000460L
end_define

begin_define
define|#
directive|define
name|BA0_ACSTS
value|0x00000464L
end_define

begin_define
define|#
directive|define
name|BA0_ACOSV
value|0x00000468L
end_define

begin_define
define|#
directive|define
name|BA0_ACCAD
value|0x0000046CL
end_define

begin_define
define|#
directive|define
name|BA0_ACCDA
value|0x00000470L
end_define

begin_define
define|#
directive|define
name|BA0_ACISV
value|0x00000474L
end_define

begin_define
define|#
directive|define
name|BA0_ACSAD
value|0x00000478L
end_define

begin_define
define|#
directive|define
name|BA0_ACSDA
value|0x0000047CL
end_define

begin_define
define|#
directive|define
name|BA0_JSPT
value|0x00000480L
end_define

begin_define
define|#
directive|define
name|BA0_JSCTL
value|0x00000484L
end_define

begin_define
define|#
directive|define
name|BA0_JSC1
value|0x00000488L
end_define

begin_define
define|#
directive|define
name|BA0_JSC2
value|0x0000048CL
end_define

begin_define
define|#
directive|define
name|BA0_MIDCR
value|0x00000490L
end_define

begin_define
define|#
directive|define
name|BA0_MIDSR
value|0x00000494L
end_define

begin_define
define|#
directive|define
name|BA0_MIDWP
value|0x00000498L
end_define

begin_define
define|#
directive|define
name|BA0_MIDRP
value|0x0000049CL
end_define

begin_define
define|#
directive|define
name|BA0_JSIO
value|0x000004A0L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|BA0_ASER_MASTER
value|0x000004A4L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BA0_CFGI
value|0x000004B0L
end_define

begin_define
define|#
directive|define
name|BA0_SSVID
value|0x000004B4L
end_define

begin_define
define|#
directive|define
name|BA0_GPIOR
value|0x000004B8L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|BA0_EGPIODR
value|0x000004BCL
end_define

begin_define
define|#
directive|define
name|BA0_EGPIOPTR
value|0x000004C0L
end_define

begin_define
define|#
directive|define
name|BA0_EGPIOTR
value|0x000004C4L
end_define

begin_define
define|#
directive|define
name|BA0_EGPIOWR
value|0x000004C8L
end_define

begin_define
define|#
directive|define
name|BA0_EGPIOSR
value|0x000004CCL
end_define

begin_define
define|#
directive|define
name|BA0_SERC6
value|0x000004D0L
end_define

begin_define
define|#
directive|define
name|BA0_SERC7
value|0x000004D4L
end_define

begin_define
define|#
directive|define
name|BA0_SERACC
value|0x000004D8L
end_define

begin_define
define|#
directive|define
name|BA0_ACCTL2
value|0x000004E0L
end_define

begin_define
define|#
directive|define
name|BA0_ACSTS2
value|0x000004E4L
end_define

begin_define
define|#
directive|define
name|BA0_ACOSV2
value|0x000004E8L
end_define

begin_define
define|#
directive|define
name|BA0_ACCAD2
value|0x000004ECL
end_define

begin_define
define|#
directive|define
name|BA0_ACCDA2
value|0x000004F0L
end_define

begin_define
define|#
directive|define
name|BA0_ACISV2
value|0x000004F4L
end_define

begin_define
define|#
directive|define
name|BA0_ACSAD2
value|0x000004F8L
end_define

begin_define
define|#
directive|define
name|BA0_ACSDA2
value|0x000004FCL
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC0
value|0x00000500L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC1
value|0x00000504L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC2
value|0x00000508L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC3
value|0x0000050CL
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC4
value|0x00000510L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC5
value|0x00000514L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC6
value|0x00000518L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC7
value|0x0000051CL
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC8
value|0x00000520L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC9
value|0x00000524L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC10
value|0x00000528L
end_define

begin_define
define|#
directive|define
name|BA0_IOTAC11
value|0x0000052CL
end_define

begin_define
define|#
directive|define
name|BA0_IOTFR0
value|0x00000540L
end_define

begin_define
define|#
directive|define
name|BA0_IOTFR1
value|0x00000544L
end_define

begin_define
define|#
directive|define
name|BA0_IOTFR2
value|0x00000548L
end_define

begin_define
define|#
directive|define
name|BA0_IOTFR3
value|0x0000054CL
end_define

begin_define
define|#
directive|define
name|BA0_IOTFR4
value|0x00000550L
end_define

begin_define
define|#
directive|define
name|BA0_IOTFR5
value|0x00000554L
end_define

begin_define
define|#
directive|define
name|BA0_IOTFR6
value|0x00000558L
end_define

begin_define
define|#
directive|define
name|BA0_IOTFR7
value|0x0000055CL
end_define

begin_define
define|#
directive|define
name|BA0_IOTFIFO
value|0x00000580L
end_define

begin_define
define|#
directive|define
name|BA0_IOTRRD
value|0x00000584L
end_define

begin_define
define|#
directive|define
name|BA0_IOTFP
value|0x00000588L
end_define

begin_define
define|#
directive|define
name|BA0_IOTCR
value|0x0000058CL
end_define

begin_define
define|#
directive|define
name|BA0_DPCID
value|0x00000590L
end_define

begin_define
define|#
directive|define
name|BA0_DPCIA
value|0x00000594L
end_define

begin_define
define|#
directive|define
name|BA0_DPCIC
value|0x00000598L
end_define

begin_define
define|#
directive|define
name|BA0_PCPCIR
value|0x00000600L
end_define

begin_define
define|#
directive|define
name|BA0_PCPCIG
value|0x00000604L
end_define

begin_define
define|#
directive|define
name|BA0_PCPCIEN
value|0x00000608L
end_define

begin_define
define|#
directive|define
name|BA0_EPCIPMC
value|0x00000610L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following define the offsets of the AC97 shadow registers, which appear  * as a virtual extension to the base address register zero memory range.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BA0_AC97_RESET
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_MASTER_VOLUME
value|0x00001002L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_HEADPHONE_VOLUME
value|0x00001004L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_MASTER_VOLUME_MONO
value|0x00001006L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_MASTER_TONE
value|0x00001008L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_PC_BEEP_VOLUME
value|0x0000100AL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_PHONE_VOLUME
value|0x0000100CL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_MIC_VOLUME
value|0x0000100EL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_LINE_IN_VOLUME
value|0x00001010L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_CD_VOLUME
value|0x00001012L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VIDEO_VOLUME
value|0x00001014L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_AUX_VOLUME
value|0x00001016L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_PCM_OUT_VOLUME
value|0x00001018L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RECORD_SELECT
value|0x0000101AL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RECORD_GAIN
value|0x0000101CL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RECORD_GAIN_MIC
value|0x0000101EL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_GENERAL_PURPOSE
value|0x00001020L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_3D_CONTROL
value|0x00001022L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_MODEM_RATE
value|0x00001024L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_POWERDOWN
value|0x00001026L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_28
value|0x00001028L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_2A
value|0x0000102AL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_2C
value|0x0000102CL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_2E
value|0x0000102EL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_30
value|0x00001030L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_32
value|0x00001032L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_34
value|0x00001034L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_36
value|0x00001036L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_38
value|0x00001038L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_3A
value|0x0000103AL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_3C
value|0x0000103CL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_3E
value|0x0000103EL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_40
value|0x00001040L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_42
value|0x00001042L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_44
value|0x00001044L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_46
value|0x00001046L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_48
value|0x00001048L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_4A
value|0x0000104AL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_4C
value|0x0000104CL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_4E
value|0x0000104EL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_50
value|0x00001050L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_52
value|0x00001052L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_54
value|0x00001054L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_56
value|0x00001056L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_RESERVED_58
value|0x00001058L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_5A
value|0x0000105AL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_5C
value|0x0000105CL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_5E
value|0x0000105EL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_60
value|0x00001060L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_62
value|0x00001062L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_64
value|0x00001064L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_66
value|0x00001066L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_68
value|0x00001068L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_6A
value|0x0000106AL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_6C
value|0x0000106CL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_6E
value|0x0000106EL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_70
value|0x00001070L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_72
value|0x00001072L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_74
value|0x00001074L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_76
value|0x00001076L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_78
value|0x00001078L
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_RESERVED_7A
value|0x0000107AL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_ID1
value|0x0000107CL
end_define

begin_define
define|#
directive|define
name|BA0_AC97_VENDOR_ID2
value|0x0000107EL
end_define

begin_comment
comment|/*****************************************************************************  *  * The following define the offsets of the registers and memories accessed via  * base address register one on the CS461x part.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BA1_SP_DMEM0
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|BA1_SP_DMEM1
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|BA1_SP_PMEM
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|BA1_SPCR
value|0x00030000L
end_define

begin_define
define|#
directive|define
name|BA1_DREG
value|0x00030004L
end_define

begin_define
define|#
directive|define
name|BA1_DSRWP
value|0x00030008L
end_define

begin_define
define|#
directive|define
name|BA1_TWPR
value|0x0003000CL
end_define

begin_define
define|#
directive|define
name|BA1_SPWR
value|0x00030010L
end_define

begin_define
define|#
directive|define
name|BA1_SPIR
value|0x00030014L
end_define

begin_define
define|#
directive|define
name|BA1_FGR1
value|0x00030020L
end_define

begin_define
define|#
directive|define
name|BA1_SPCS
value|0x00030028L
end_define

begin_define
define|#
directive|define
name|BA1_SDSR
value|0x0003002CL
end_define

begin_define
define|#
directive|define
name|BA1_FRMT
value|0x00030030L
end_define

begin_define
define|#
directive|define
name|BA1_FRCC
value|0x00030034L
end_define

begin_define
define|#
directive|define
name|BA1_FRSC
value|0x00030038L
end_define

begin_define
define|#
directive|define
name|BA1_OMNI_MEM
value|0x000E0000L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the PCI interrupt register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PI_LINE_MASK
value|0x000000FFL
end_define

begin_define
define|#
directive|define
name|PI_PIN_MASK
value|0x0000FF00L
end_define

begin_define
define|#
directive|define
name|PI_MIN_GRANT_MASK
value|0x00FF0000L
end_define

begin_define
define|#
directive|define
name|PI_MAX_LATENCY_MASK
value|0xFF000000L
end_define

begin_define
define|#
directive|define
name|PI_LINE_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|PI_PIN_SHIFT
value|8L
end_define

begin_define
define|#
directive|define
name|PI_MIN_GRANT_SHIFT
value|16L
end_define

begin_define
define|#
directive|define
name|PI_MAX_LATENCY_SHIFT
value|24L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the host interrupt status  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HISR_VC_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|HISR_VC0
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|HISR_VC1
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|HISR_VC2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|HISR_VC3
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|HISR_VC4
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|HISR_VC5
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|HISR_VC6
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|HISR_VC7
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|HISR_VC8
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|HISR_VC9
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|HISR_VC10
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|HISR_VC11
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|HISR_VC12
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|HISR_VC13
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|HISR_VC14
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|HISR_VC15
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|HISR_INT0
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|HISR_INT1
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|HISR_DMAI
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|HISR_FROVR
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|HISR_MIDI
value|0x00100000L
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NO_CS4612
end_ifdef

begin_define
define|#
directive|define
name|HISR_RESERVED
value|0x0FE00000L
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HISR_SBINT
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|HISR_RESERVED
value|0x0FC00000L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HISR_H0P
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|HISR_INTENA
value|0x80000000L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the host signal register 0.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HSR0_VC_MASK
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|HSR0_VC16
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|HSR0_VC17
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|HSR0_VC18
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|HSR0_VC19
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|HSR0_VC20
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|HSR0_VC21
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|HSR0_VC22
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|HSR0_VC23
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|HSR0_VC24
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|HSR0_VC25
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|HSR0_VC26
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|HSR0_VC27
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|HSR0_VC28
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC29
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC30
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC31
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC32
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC33
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC34
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC35
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC36
value|0x00100000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC37
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC38
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC39
value|0x00800000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC40
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC41
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC42
value|0x04000000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC43
value|0x08000000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC44
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC45
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC46
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|HSR0_VC47
value|0x80000000L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the host interrupt control  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HICR_IEV
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|HICR_CHGM
value|0x00000002L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the DMA status register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DMSR_HP
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|DMSR_HR
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|DMSR_SP
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|DMSR_SR
value|0x00000008L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the host DMA source address  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HSAR_HOST_ADDR_MASK
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|HSAR_DSP_ADDR_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|HSAR_MEMID_MASK
value|0x000F0000L
end_define

begin_define
define|#
directive|define
name|HSAR_MEMID_SP_DMEM0
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|HSAR_MEMID_SP_DMEM1
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|HSAR_MEMID_SP_PMEM
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|HSAR_MEMID_SP_DEBUG
value|0x00030000L
end_define

begin_define
define|#
directive|define
name|HSAR_MEMID_OMNI_MEM
value|0x000E0000L
end_define

begin_define
define|#
directive|define
name|HSAR_END
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|HSAR_ERR
value|0x80000000L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the host DMA destination address  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HDAR_HOST_ADDR_MASK
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|HDAR_DSP_ADDR_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|HDAR_MEMID_MASK
value|0x000F0000L
end_define

begin_define
define|#
directive|define
name|HDAR_MEMID_SP_DMEM0
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|HDAR_MEMID_SP_DMEM1
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|HDAR_MEMID_SP_PMEM
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|HDAR_MEMID_SP_DEBUG
value|0x00030000L
end_define

begin_define
define|#
directive|define
name|HDAR_MEMID_OMNI_MEM
value|0x000E0000L
end_define

begin_define
define|#
directive|define
name|HDAR_END
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|HDAR_ERR
value|0x80000000L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the host DMA control register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HDMR_AC_MASK
value|0x0000F000L
end_define

begin_define
define|#
directive|define
name|HDMR_AC_8_16
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|HDMR_AC_M_S
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|HDMR_AC_B_L
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|HDMR_AC_S_U
value|0x00008000L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the host DMA control register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HDCR_COUNT_MASK
value|0x000003FFL
end_define

begin_define
define|#
directive|define
name|HDCR_DONE
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|HDCR_OPT
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|HDCR_WBD
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|HDCR_WBS
value|0x00800000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_MASK
value|0x07000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_LINEAR
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_16_DWORDS
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_32_DWORDS
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_64_DWORDS
value|0x03000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_128_DWORDS
value|0x04000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_256_DWORDS
value|0x05000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_512_DWORDS
value|0x06000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DMS_1024_DWORDS
value|0x07000000L
end_define

begin_define
define|#
directive|define
name|HDCR_DH
value|0x08000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_MASK
value|0x70000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_LINEAR
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_16_DWORDS
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_32_DWORDS
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_64_DWORDS
value|0x30000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_128_DWORDS
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_256_DWORDS
value|0x50000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_512_DWORDS
value|0x60000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SMS_1024_DWORDS
value|0x70000000L
end_define

begin_define
define|#
directive|define
name|HDCR_SH
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|HDCR_COUNT_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the performance monitor control  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PFMC_C1SS_MASK
value|0x0000001FL
end_define

begin_define
define|#
directive|define
name|PFMC_C1EV
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|PFMC_C1RS
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|PFMC_C2SS_MASK
value|0x001F0000L
end_define

begin_define
define|#
directive|define
name|PFMC_C2EV
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|PFMC_C2RS
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|PFMC_C1SS_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|PFMC_C2SS_SHIFT
value|16L
end_define

begin_define
define|#
directive|define
name|PFMC_BUS_GRANT
value|0L
end_define

begin_define
define|#
directive|define
name|PFMC_GRANT_AFTER_REQ
value|1L
end_define

begin_define
define|#
directive|define
name|PFMC_TRANSACTION
value|2L
end_define

begin_define
define|#
directive|define
name|PFMC_DWORD_TRANSFER
value|3L
end_define

begin_define
define|#
directive|define
name|PFMC_SLAVE_READ
value|4L
end_define

begin_define
define|#
directive|define
name|PFMC_SLAVE_WRITE
value|5L
end_define

begin_define
define|#
directive|define
name|PFMC_PREEMPTION
value|6L
end_define

begin_define
define|#
directive|define
name|PFMC_DISCONNECT_RETRY
value|7L
end_define

begin_define
define|#
directive|define
name|PFMC_INTERRUPT
value|8L
end_define

begin_define
define|#
directive|define
name|PFMC_BUS_OWNERSHIP
value|9L
end_define

begin_define
define|#
directive|define
name|PFMC_TRANSACTION_LAG
value|10L
end_define

begin_define
define|#
directive|define
name|PFMC_PCI_CLOCK
value|11L
end_define

begin_define
define|#
directive|define
name|PFMC_SERIAL_CLOCK
value|12L
end_define

begin_define
define|#
directive|define
name|PFMC_SP_CLOCK
value|13L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the performance counter value 1  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PFCV1_PC1V_MASK
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|PFCV1_PC1V_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the performance counter value 2  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PFCV2_PC2V_MASK
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|PFCV2_PC2V_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the clock control register 1.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CLKCR1_OSCS
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|CLKCR1_OSCP
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|CLKCR1_PLLSS_MASK
value|0x0000000CL
end_define

begin_define
define|#
directive|define
name|CLKCR1_PLLSS_SERIAL
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|CLKCR1_PLLSS_CRYSTAL
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|CLKCR1_PLLSS_PCI
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|CLKCR1_PLLSS_RESERVED
value|0x0000000CL
end_define

begin_define
define|#
directive|define
name|CLKCR1_PLLP
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|CLKCR1_SWCE
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|CLKCR1_PLLOS
value|0x00000040L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the clock control register 2.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CLKCR2_PDIVS_MASK
value|0x0000000FL
end_define

begin_define
define|#
directive|define
name|CLKCR2_PDIVS_1
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|CLKCR2_PDIVS_2
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|CLKCR2_PDIVS_4
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|CLKCR2_PDIVS_7
value|0x00000007L
end_define

begin_define
define|#
directive|define
name|CLKCR2_PDIVS_8
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|CLKCR2_PDIVS_16
value|0x00000000L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the PLL multiplier register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PLLM_MASK
value|0x000000FFL
end_define

begin_define
define|#
directive|define
name|PLLM_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the PLL capacitor coefficient  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PLLCC_CDR_MASK
value|0x00000007L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4610
end_ifndef

begin_define
define|#
directive|define
name|PLLCC_CDR_240_350_MHZ
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_184_265_MHZ
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_144_205_MHZ
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_111_160_MHZ
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_87_123_MHZ
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_67_96_MHZ
value|0x00000005L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_52_74_MHZ
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_45_58_MHZ
value|0x00000007L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|PLLCC_CDR_271_398_MHZ
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_227_330_MHZ
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_167_239_MHZ
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_150_215_MHZ
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_107_154_MHZ
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_98_140_MHZ
value|0x00000005L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_73_104_MHZ
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|PLLCC_CDR_63_90_MHZ
value|0x00000007L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PLLCC_LPF_MASK
value|0x000000F8L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4610
end_ifndef

begin_define
define|#
directive|define
name|PLLCC_LPF_23850_60000_KHZ
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_7960_26290_KHZ
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_4160_10980_KHZ
value|0x00000018L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_1740_4580_KHZ
value|0x00000038L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_724_1910_KHZ
value|0x00000078L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_317_798_KHZ
value|0x000000F8L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|PLLCC_LPF_25580_64530_KHZ
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_14360_37270_KHZ
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_6100_16020_KHZ
value|0x00000018L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_2540_6690_KHZ
value|0x00000038L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_1050_2780_KHZ
value|0x00000078L
end_define

begin_define
define|#
directive|define
name|PLLCC_LPF_450_1160_KHZ
value|0x000000F8L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the feature reporting register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FRR_FAB_MASK
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|FRR_MASK_MASK
value|0x0000001CL
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NO_CS4612
end_ifdef

begin_define
define|#
directive|define
name|FRR_CFOP_MASK
value|0x000000E0L
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FRR_CFOP_MASK
value|0x00000FE0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FRR_CFOP_NOT_DVD
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|FRR_CFOP_A3D
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|FRR_CFOP_128_PIN
value|0x00000080L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|FRR_CFOP_CS4280
value|0x00000800L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FRR_FAB_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|FRR_MASK_SHIFT
value|2L
end_define

begin_define
define|#
directive|define
name|FRR_CFOP_SHIFT
value|5L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the configuration load 1  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CFL1_CLOCK_SOURCE_MASK
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|CFL1_CLOCK_SOURCE_CS423X
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|CFL1_CLOCK_SOURCE_AC97
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|CFL1_CLOCK_SOURCE_CRYSTAL
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|CFL1_CLOCK_SOURCE_DUAL_AC97
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|CFL1_VALID_DATA_MASK
value|0x000000FFL
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the configuration load 2  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CFL2_VALID_DATA_MASK
value|0x000000FFL
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port master control  * register 1.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERMC1_MSPE
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERMC1_PTC_MASK
value|0x0000000EL
end_define

begin_define
define|#
directive|define
name|SERMC1_PTC_CS423X
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|SERMC1_PTC_AC97
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SERMC1_PTC_DAC
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SERMC1_PLB
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|SERMC1_XLB
value|0x00000020L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port master control  * register 2.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERMC2_LROE
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERMC2_MCOE
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SERMC2_MCDIV
value|0x00000004L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port 1 configuration  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERC1_SO1EN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERC1_SO1F_MASK
value|0x0000000EL
end_define

begin_define
define|#
directive|define
name|SERC1_SO1F_CS423X
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|SERC1_SO1F_AC97
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SERC1_SO1F_DAC
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SERC1_SO1F_SPDIF
value|0x00000006L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port 2 configuration  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERC2_SI1EN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERC2_SI1F_MASK
value|0x0000000EL
end_define

begin_define
define|#
directive|define
name|SERC2_SI1F_CS423X
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|SERC2_SI1F_AC97
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SERC2_SI1F_ADC
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SERC2_SI1F_SPDIF
value|0x00000006L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port 3 configuration  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERC3_SO2EN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERC3_SO2F_MASK
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|SERC3_SO2F_DAC
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|SERC3_SO2F_SPDIF
value|0x00000002L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port 4 configuration  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERC4_SO3EN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERC4_SO3F_MASK
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|SERC4_SO3F_DAC
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|SERC4_SO3F_SPDIF
value|0x00000002L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port 5 configuration  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERC5_SI2EN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERC5_SI2F_MASK
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|SERC5_SI2F_ADC
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|SERC5_SI2F_SPDIF
value|0x00000002L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port backdoor sample  * pointer register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERBSP_FSP_MASK
value|0x0000000FL
end_define

begin_define
define|#
directive|define
name|SERBSP_FSP_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port backdoor status  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERBST_RRDY
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERBST_WBSY
value|0x00000002L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port backdoor command  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERBCM_RDC
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERBCM_WRC
value|0x00000002L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port backdoor address  * register.  *  *****************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_CS4612
end_ifdef

begin_define
define|#
directive|define
name|SERBAD_FAD_MASK
value|0x000000FFL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SERBAD_FAD_MASK
value|0x000001FFL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SERBAD_FAD_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port backdoor  * configuration register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERBCF_HBP
value|0x00000001L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port backdoor write  * port register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERBWP_FWD_MASK
value|0x000FFFFFL
end_define

begin_define
define|#
directive|define
name|SERBWP_FWD_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port backdoor read  * port register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SERBRP_FRD_MASK
value|0x000FFFFFL
end_define

begin_define
define|#
directive|define
name|SERBRP_FRD_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the async FIFO address register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ASER_FADDR_A1_MASK
value|0x000001FFL
end_define

begin_define
define|#
directive|define
name|ASER_FADDR_EN1
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|ASER_FADDR_A2_MASK
value|0x01FF0000L
end_define

begin_define
define|#
directive|define
name|ASER_FADDR_EN2
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|ASER_FADDR_A1_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|ASER_FADDR_A2_SHIFT
value|16L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 control register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACCTL_RSTN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ACCTL_ESYN
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ACCTL_VFRM
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ACCTL_DCV
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ACCTL_CRW
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ACCTL_ASYN
value|0x00000020L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACCTL_TC
value|0x00000040L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 status register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACSTS_CRDY
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ACSTS_VSTS
value|0x00000002L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACSTS_WKUP
value|0x00000004L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 output slot valid  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACOSV_SLV3
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV4
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV5
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV6
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV7
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV8
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV9
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV10
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV11
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ACOSV_SLV12
value|0x00000200L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 command address  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACCAD_CI_MASK
value|0x0000007FL
end_define

begin_define
define|#
directive|define
name|ACCAD_CI_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 command data register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACCDA_CD_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|ACCDA_CD_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 input slot valid  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACISV_ISV3
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV4
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV5
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV6
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV7
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV8
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV9
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV10
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV11
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ACISV_ISV12
value|0x00000200L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 status address  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACSAD_SI_MASK
value|0x0000007FL
end_define

begin_define
define|#
directive|define
name|ACSAD_SI_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 status data register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACSDA_SD_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|ACSDA_SD_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the joystick poll/trigger  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JSPT_CAX
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|JSPT_CAY
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|JSPT_CBX
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|JSPT_CBY
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|JSPT_BA1
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|JSPT_BA2
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|JSPT_BB1
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|JSPT_BB2
value|0x00000080L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the joystick control register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JSCTL_SP_MASK
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|JSCTL_SP_SLOW
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|JSCTL_SP_MEDIUM_SLOW
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|JSCTL_SP_MEDIUM_FAST
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|JSCTL_SP_FAST
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|JSCTL_ARE
value|0x00000004L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the joystick coordinate pair 1  * readback register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JSC1_Y1V_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|JSC1_X1V_MASK
value|0xFFFF0000L
end_define

begin_define
define|#
directive|define
name|JSC1_Y1V_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|JSC1_X1V_SHIFT
value|16L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the joystick coordinate pair 2  * readback register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JSC2_Y2V_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|JSC2_X2V_MASK
value|0xFFFF0000L
end_define

begin_define
define|#
directive|define
name|JSC2_Y2V_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|JSC2_X2V_SHIFT
value|16L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the MIDI control register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MIDCR_TXE
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|MIDCR_RXE
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|MIDCR_RIE
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|MIDCR_TIE
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|MIDCR_MLB
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|MIDCR_MRST
value|0x00000020L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the MIDI status register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MIDSR_TBF
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|MIDSR_RBE
value|0x00000002L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the MIDI write port register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MIDWP_MWD_MASK
value|0x000000FFL
end_define

begin_define
define|#
directive|define
name|MIDWP_MWD_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the MIDI read port register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MIDRP_MRD_MASK
value|0x000000FFL
end_define

begin_define
define|#
directive|define
name|MIDRP_MRD_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the joystick GPIO register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JSIO_DAX
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|JSIO_DAY
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|JSIO_DBX
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|JSIO_DBY
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|JSIO_AXOE
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|JSIO_AYOE
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|JSIO_BXOE
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|JSIO_BYOE
value|0x00000080L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the master async/sync serial  * port enable register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ASER_MASTER_ME
value|0x00000001L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the configuration interface  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CFGI_CLK
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|CFGI_DOUT
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|CFGI_DIN_EEN
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|CFGI_EELD
value|0x00000008L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the subsystem ID and vendor ID  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SSVID_VID_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|SSVID_SID_MASK
value|0xFFFF0000L
end_define

begin_define
define|#
directive|define
name|SSVID_VID_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|SSVID_SID_SHIFT
value|16L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the GPIO pin interface register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|GPIOR_VOLDN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|GPIOR_VOLUP
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|GPIOR_SI2D
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|GPIOR_SI2OE
value|0x00000008L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the extended GPIO pin direction  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|EGPIODR_GPOE0
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|EGPIODR_GPOE1
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|EGPIODR_GPOE2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|EGPIODR_GPOE3
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|EGPIODR_GPOE4
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|EGPIODR_GPOE5
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|EGPIODR_GPOE6
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|EGPIODR_GPOE7
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|EGPIODR_GPOE8
value|0x00000100L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the extended GPIO pin polarity/  * type register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT0
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT1
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT3
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT4
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT5
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT6
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT7
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|EGPIOPTR_GPPT8
value|0x00000100L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the extended GPIO pin sticky  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|EGPIOTR_GPS0
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|EGPIOTR_GPS1
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|EGPIOTR_GPS2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|EGPIOTR_GPS3
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|EGPIOTR_GPS4
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|EGPIOTR_GPS5
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|EGPIOTR_GPS6
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|EGPIOTR_GPS7
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|EGPIOTR_GPS8
value|0x00000100L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the extended GPIO ping wakeup  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|EGPIOWR_GPW0
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|EGPIOWR_GPW1
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|EGPIOWR_GPW2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|EGPIOWR_GPW3
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|EGPIOWR_GPW4
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|EGPIOWR_GPW5
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|EGPIOWR_GPW6
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|EGPIOWR_GPW7
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|EGPIOWR_GPW8
value|0x00000100L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the extended GPIO pin status  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|EGPIOSR_GPS0
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|EGPIOSR_GPS1
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|EGPIOSR_GPS2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|EGPIOSR_GPS3
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|EGPIOSR_GPS4
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|EGPIOSR_GPS5
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|EGPIOSR_GPS6
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|EGPIOSR_GPS7
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|EGPIOSR_GPS8
value|0x00000100L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port 6 configuration  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|SERC6_ASDO2EN
value|0x00000001L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port 7 configuration  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|SERC7_ASDI2EN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERC7_POSILB
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SERC7_SIPOLB
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SERC7_SOSILB
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|SERC7_SISOLB
value|0x00000010L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the serial port AC link  * configuration register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|SERACC_CODEC_TYPE_MASK
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERACC_CODEC_TYPE_1_03
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|SERACC_CODEC_TYPE_2_0
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SERACC_TWO_CODECS
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SERACC_MDM
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SERACC_HSP
value|0x00000008L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 control register 2.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACCTL2_RSTN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ACCTL2_ESYN
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ACCTL2_VFRM
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ACCTL2_DCV
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ACCTL2_CRW
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ACCTL2_ASYN
value|0x00000020L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 status register 2.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACSTS2_CRDY
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ACSTS2_VSTS
value|0x00000002L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 output slot valid  * register 2.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACOSV2_SLV3
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV4
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV5
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV6
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV7
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV8
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV9
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV10
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV11
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ACOSV2_SLV12
value|0x00000200L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 command address  * register 2.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACCAD2_CI_MASK
value|0x0000007FL
end_define

begin_define
define|#
directive|define
name|ACCAD2_CI_SHIFT
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 command data register  * 2.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACCDA2_CD_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|ACCDA2_CD_SHIFT
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 input slot valid  * register 2.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACISV2_ISV3
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV4
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV5
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV6
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV7
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV8
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV9
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV10
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV11
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|ACISV2_ISV12
value|0x00000200L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 status address  * register 2.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACSAD2_SI_MASK
value|0x0000007FL
end_define

begin_define
define|#
directive|define
name|ACSAD2_SI_SHIFT
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the AC97 status data register 2.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|ACSDA2_SD_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|ACSDA2_SD_SHIFT
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the I/O trap address and control  * registers (all 12).  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|IOTAC_SA_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|IOTAC_MSK_MASK
value|0x000F0000L
end_define

begin_define
define|#
directive|define
name|IOTAC_IODC_MASK
value|0x06000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_IODC_16_BIT
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_IODC_10_BIT
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_IODC_12_BIT
value|0x04000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_WSPI
value|0x08000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_RSPI
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_WSE
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_WE
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_RE
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|IOTAC_SA_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|IOTAC_MSK_SHIFT
value|16L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the I/O trap fast read registers  * (all 8).  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|IOTFR_D_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|IOTFR_A_MASK
value|0x000F0000L
end_define

begin_define
define|#
directive|define
name|IOTFR_R_MASK
value|0x0F000000L
end_define

begin_define
define|#
directive|define
name|IOTFR_ALL
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|IOTFR_VL
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|IOTFR_D_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|IOTFR_A_SHIFT
value|16L
end_define

begin_define
define|#
directive|define
name|IOTFR_R_SHIFT
value|24L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the I/O trap FIFO register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|IOTFIFO_BA_MASK
value|0x00003FFFL
end_define

begin_define
define|#
directive|define
name|IOTFIFO_S_MASK
value|0x00FF0000L
end_define

begin_define
define|#
directive|define
name|IOTFIFO_OF
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|IOTFIFO_SPIOF
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|IOTFIFO_BA_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|IOTFIFO_S_SHIFT
value|16L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the I/O trap retry read data  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|IOTRRD_D_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|IOTRRD_RDV
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|IOTRRD_D_SHIFT
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the I/O trap FIFO pointer  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|IOTFP_CA_MASK
value|0x00003FFFL
end_define

begin_define
define|#
directive|define
name|IOTFP_PA_MASK
value|0x3FFF0000L
end_define

begin_define
define|#
directive|define
name|IOTFP_CA_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|IOTFP_PA_SHIFT
value|16L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the I/O trap control register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|IOTCR_ITD
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|IOTCR_HRV
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|IOTCR_SRV
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|IOTCR_DTI
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|IOTCR_DFI
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|IOTCR_DDP
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|IOTCR_JTE
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|IOTCR_PPE
value|0x00000080L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the direct PCI data register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|DPCID_D_MASK
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|DPCID_D_SHIFT
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the direct PCI address register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|DPCIA_A_MASK
value|0xFFFFFFFFL
end_define

begin_define
define|#
directive|define
name|DPCIA_A_SHIFT
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the direct PCI command register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|DPCIC_C_MASK
value|0x0000000FL
end_define

begin_define
define|#
directive|define
name|DPCIC_C_IOREAD
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|DPCIC_C_IOWRITE
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|DPCIC_BE_MASK
value|0x000000F0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the PC/PCI request register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|PCPCIR_RDC_MASK
value|0x00000007L
end_define

begin_define
define|#
directive|define
name|PCPCIR_C_MASK
value|0x00007000L
end_define

begin_define
define|#
directive|define
name|PCPCIR_REQ
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|PCPCIR_RDC_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|PCPCIR_C_SHIFT
value|12L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the PC/PCI grant register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|PCPCIG_GDC_MASK
value|0x00000007L
end_define

begin_define
define|#
directive|define
name|PCPCIG_VL
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|PCPCIG_GDC_SHIFT
value|0L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the PC/PCI master enable  * register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|PCPCIEN_EN
value|0x00000001L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the extended PCI power  * management control register.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|EPCIPMC_GWU
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|EPCIPMC_FSPC
value|0x00000002L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the SP control register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SPCR_RUN
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SPCR_STPFR
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SPCR_RUNFR
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SPCR_TICK
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|SPCR_DRQEN
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|SPCR_RSTSP
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|SPCR_OREN
value|0x00000080L
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CS4612
end_ifndef

begin_define
define|#
directive|define
name|SPCR_PCIINT
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|SPCR_OINTD
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|SPCR_CRE
value|0x00008000L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the debug index register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DREG_REGID_MASK
value|0x0000007FL
end_define

begin_define
define|#
directive|define
name|DREG_DEBUG
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|DREG_RGBK_MASK
value|0x00000700L
end_define

begin_define
define|#
directive|define
name|DREG_TRAP
value|0x00000800L
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_CS4612
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_CS4615
argument_list|)
end_if

begin_define
define|#
directive|define
name|DREG_TRAPX
value|0x00001000L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DREG_REGID_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|DREG_RGBK_SHIFT
value|8L
end_define

begin_define
define|#
directive|define
name|DREG_RGBK_REGID_MASK
value|0x0000077FL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R0
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R1
value|0x00000011L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R2
value|0x00000012L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R3
value|0x00000013L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R4
value|0x00000014L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R5
value|0x00000015L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R6
value|0x00000016L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R7
value|0x00000017L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R8
value|0x00000018L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_R9
value|0x00000019L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RA
value|0x0000001AL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RB
value|0x0000001BL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RC
value|0x0000001CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RD
value|0x0000001DL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RE
value|0x0000001EL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RF
value|0x0000001FL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RA_BUS_LOW
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RA_BUS_HIGH
value|0x00000038L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_YBUS_LOW
value|0x00000050L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_YBUS_HIGH
value|0x00000058L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_0
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_1
value|0x00000101L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_2
value|0x00000102L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_3
value|0x00000103L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_4
value|0x00000104L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_5
value|0x00000105L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_6
value|0x00000106L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_7
value|0x00000107L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_INDIRECT_ADDRESS
value|0x0000010EL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TOP_OF_STACK
value|0x0000010FL
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_CS4612
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_CS4615
argument_list|)
end_if

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_8
value|0x00000110L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_9
value|0x00000111L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_10
value|0x00000112L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_11
value|0x00000113L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_12
value|0x00000114L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_13
value|0x00000115L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_14
value|0x00000116L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_15
value|0x00000117L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_16
value|0x00000118L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_17
value|0x00000119L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_18
value|0x0000011AL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_19
value|0x0000011BL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_20
value|0x0000011CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_21
value|0x0000011DL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_22
value|0x0000011EL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_23
value|0x0000011FL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DREG_REGID_RSA0_LOW
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSA0_HIGH
value|0x00000201L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSA1_LOW
value|0x00000202L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSA1_HIGH
value|0x00000203L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSA2
value|0x00000204L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSA3
value|0x00000205L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSI0_LOW
value|0x00000206L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSI0_HIGH
value|0x00000207L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSI1
value|0x00000208L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSI2
value|0x00000209L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_SAGUSTATUS
value|0x0000020AL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSCONFIG01_LOW
value|0x0000020BL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSCONFIG01_HIGH
value|0x0000020CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSCONFIG23_LOW
value|0x0000020DL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSCONFIG23_HIGH
value|0x0000020EL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSDMA01E
value|0x0000020FL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSDMA23E
value|0x00000210L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSD0_LOW
value|0x00000211L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSD0_HIGH
value|0x00000212L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSD1_LOW
value|0x00000213L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSD1_HIGH
value|0x00000214L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSD2_LOW
value|0x00000215L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSD2_HIGH
value|0x00000216L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSD3_LOW
value|0x00000217L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSD3_HIGH
value|0x00000218L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_SRAR_HIGH
value|0x0000021AL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_SRAR_LOW
value|0x0000021BL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE
value|0x0000021CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_CURRENT_DMA_STREAM
value|0x0000021DL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_NEXT_DMA_STREAM
value|0x0000021EL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_CPU_STATUS
value|0x00000300L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC_MODE
value|0x00000301L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_STACK_AND_REPEAT
value|0x00000302L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_INDEX0
value|0x00000304L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_INDEX1
value|0x00000305L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_0_3
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_4_7
value|0x00000404L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_8_11
value|0x00000408L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_12_15
value|0x0000040CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_16_19
value|0x00000410L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_20_23
value|0x00000414L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_24_27
value|0x00000418L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_28_31
value|0x0000041CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_32_35
value|0x00000420L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_36_39
value|0x00000424L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_40_43
value|0x00000428L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_44_47
value|0x0000042CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_48_51
value|0x00000430L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_52_55
value|0x00000434L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_56_59
value|0x00000438L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_60_63
value|0x0000043CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_64_67
value|0x00000440L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_68_71
value|0x00000444L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_72_75
value|0x00000448L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_76_79
value|0x0000044CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_80_83
value|0x00000450L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_84_87
value|0x00000454L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_88_91
value|0x00000458L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_DMA_STATE_92_95
value|0x0000045CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_SELECT
value|0x00000500L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_0
value|0x00000500L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_1
value|0x00000501L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_2
value|0x00000502L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_3
value|0x00000503L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_4
value|0x00000504L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_5
value|0x00000505L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_6
value|0x00000506L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_7
value|0x00000507L
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_CS4612
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_CS4615
argument_list|)
end_if

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_8
value|0x00000510L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_9
value|0x00000511L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_10
value|0x00000512L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_11
value|0x00000513L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_12
value|0x00000514L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_13
value|0x00000515L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_14
value|0x00000516L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_15
value|0x00000517L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_16
value|0x00000518L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_17
value|0x00000519L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_18
value|0x0000051AL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_19
value|0x0000051BL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_20
value|0x0000051CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_21
value|0x0000051DL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_22
value|0x0000051EL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_TRAP_WRITE_23
value|0x0000051FL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC0_LOW
value|0x00000600L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC1_LOW
value|0x00000601L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC2_LOW
value|0x00000602L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC3_LOW
value|0x00000603L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC0_LOW
value|0x00000604L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC1_LOW
value|0x00000605L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC2_LOW
value|0x00000606L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC3_LOW
value|0x00000607L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC0_MID
value|0x00000608L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC1_MID
value|0x00000609L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC2_MID
value|0x0000060AL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC3_MID
value|0x0000060BL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC0_MID
value|0x0000060CL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC1_MID
value|0x0000060DL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC2_MID
value|0x0000060EL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC3_MID
value|0x0000060FL
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC0_HIGH
value|0x00000610L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC1_HIGH
value|0x00000611L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC2_HIGH
value|0x00000612L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC0_ACC3_HIGH
value|0x00000613L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC0_HIGH
value|0x00000614L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC1_HIGH
value|0x00000615L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC2_HIGH
value|0x00000616L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_MAC1_ACC3_HIGH
value|0x00000617L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSHOUT_LOW
value|0x00000620L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSHOUT_MID
value|0x00000628L
end_define

begin_define
define|#
directive|define
name|DREG_REGID_RSHOUT_HIGH
value|0x00000630L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the DMA stream requestor write  * port register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DSRWP_DSR_MASK
value|0x0000000FL
end_define

begin_define
define|#
directive|define
name|DSRWP_DSR_BG_RQ
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|DSRWP_DSR_PRIORITY_MASK
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|DSRWP_DSR_PRIORITY_0
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DSRWP_DSR_PRIORITY_1
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|DSRWP_DSR_PRIORITY_2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|DSRWP_DSR_PRIORITY_3
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|DSRWP_DSR_RQ_PENDING
value|0x00000008L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the trap write port register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|TWPR_TW_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|TWPR_TW_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the stack pointer write  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SPWR_STKP_MASK
value|0x0000000FL
end_define

begin_define
define|#
directive|define
name|SPWR_STKP_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the SP interrupt register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SPIR_FRI
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SPIR_DOI
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SPIR_GPI2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SPIR_GPI3
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|SPIR_IP0
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|SPIR_IP1
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|SPIR_IP2
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|SPIR_IP3
value|0x00000080L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the functional group 1 register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FGR1_F1S_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|FGR1_F1S_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the SP clock status register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SPCS_FRI
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SPCS_DOI
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SPCS_GPI2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SPCS_GPI3
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|SPCS_IP0
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|SPCS_IP1
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|SPCS_IP2
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|SPCS_IP3
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|SPCS_SPRUN
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|SPCS_SLEEP
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|SPCS_FG
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|SPCS_ORUN
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|SPCS_IRQ
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|SPCS_FGN_MASK
value|0x0000E000L
end_define

begin_define
define|#
directive|define
name|SPCS_FGN_SHIFT
value|13L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the SP DMA requestor status  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SDSR_DCS_MASK
value|0x000000FFL
end_define

begin_define
define|#
directive|define
name|SDSR_DCS_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|SDSR_DCS_NONE
value|0x00000007L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the frame timer register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FRMT_FTV_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|FRMT_FTV_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the frame timer current count  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FRCC_FCC_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|FRCC_FCC_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the frame timer save count  * register.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FRSC_FCS_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|FRSC_FCS_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following define the various flags stored in the scatter/gather  * descriptors.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DMA_SG_NEXT_ENTRY_MASK
value|0x00000FF8L
end_define

begin_define
define|#
directive|define
name|DMA_SG_SAMPLE_END_MASK
value|0x0FFF0000L
end_define

begin_define
define|#
directive|define
name|DMA_SG_SAMPLE_END_FLAG
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|DMA_SG_LOOP_END_FLAG
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|DMA_SG_SIGNAL_END_FLAG
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|DMA_SG_SIGNAL_PAGE_FLAG
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|DMA_SG_NEXT_ENTRY_SHIFT
value|3L
end_define

begin_define
define|#
directive|define
name|DMA_SG_SAMPLE_END_SHIFT
value|16L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following define the offsets of the fields within the on-chip generic  * DMA requestor.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DMA_RQ_CONTROL1
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_CONTROL2
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SOURCE_ADDR
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_DESTINATION_ADDR
value|0x0000000CL
end_define

begin_define
define|#
directive|define
name|DMA_RQ_NEXT_PAGE_ADDR
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_NEXT_PAGE_SGDESC
value|0x00000014L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_LOOP_START_ADDR
value|0x00000018L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_POST_LOOP_ADDR
value|0x0000001CL
end_define

begin_define
define|#
directive|define
name|DMA_RQ_PAGE_MAP_ADDR
value|0x00000020L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the first control word of the  * on-chip generic DMA requestor.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DMA_RQ_C1_COUNT_MASK
value|0x000003FFL
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DESTINATION_SCATTER
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_GATHER
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DONE_FLAG
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_OPTIMIZE_STATE
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SAMPLE_END_STATE_MASK
value|0x00030000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_FULL_PAGE
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_BEFORE_SAMPLE_END
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_PAGE_MAP_ERROR
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_AT_SAMPLE_END
value|0x00030000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_LOOP_END_STATE_MASK
value|0x000C0000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_NOT_LOOP_END
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_BEFORE_LOOP_END
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_2PAGE_LOOP_BEGIN
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_LOOP_BEGIN
value|0x000C0000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_PAGE_MAP_MASK
value|0x00300000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_PM_NONE_PENDING
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_PM_NEXT_PENDING
value|0x00100000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_PM_RESERVED
value|0x00200000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_PM_LOOP_NEXT_PENDING
value|0x00300000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_WRITEBACK_DEST_FLAG
value|0x00400000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_WRITEBACK_SRC_FLAG
value|0x00800000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_SIZE_MASK
value|0x07000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_LINEAR
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_MOD16
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_MOD32
value|0x02000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_MOD64
value|0x03000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_MOD128
value|0x04000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_MOD256
value|0x05000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_MOD512
value|0x06000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_MOD1024
value|0x07000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_DEST_ON_HOST
value|0x08000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_SIZE_MASK
value|0x70000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_LINEAR
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_MOD16
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_MOD32
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_MOD64
value|0x30000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_MOD128
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_MOD256
value|0x50000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_MOD512
value|0x60000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_MOD1024
value|0x70000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_SOURCE_ON_HOST
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C1_COUNT_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the second control word of the  * on-chip generic DMA requestor.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DMA_RQ_C2_VIRTUAL_CHANNEL_MASK
value|0x0000003FL
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_VIRTUAL_SIGNAL_MASK
value|0x00000300L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_NO_VIRTUAL_SIGNAL
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_SIGNAL_EVERY_DMA
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_SIGNAL_SOURCE_PINGPONG
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_SIGNAL_DEST_PINGPONG
value|0x00000300L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_AUDIO_CONVERT_MASK
value|0x0000F000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_AC_NONE
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_AC_8_TO_16_BIT
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_AC_MONO_TO_STEREO
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_AC_ENDIAN_CONVERT
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_AC_SIGNED_CONVERT
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_LOOP_END_MASK
value|0x0FFF0000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_LOOP_MASK
value|0x30000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_NO_LOOP
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_ONE_PAGE_LOOP
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_TWO_PAGE_LOOP
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_MULTI_PAGE_LOOP
value|0x30000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_SIGNAL_LOOP_BACK
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_SIGNAL_POST_BEGIN_PAGE
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_VIRTUAL_CHANNEL_SHIFT
value|0L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_C2_LOOP_END_SHIFT
value|16L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the source and destination words  * of the on-chip generic DMA requestor.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DMA_RQ_SD_ADDRESS_MASK
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_MEMORY_ID_MASK
value|0x000F0000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_SP_PARAM_ADDR
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_SP_SAMPLE_ADDR
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_SP_PROGRAM_ADDR
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_SP_DEBUG_ADDR
value|0x00030000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_OMNIMEM_ADDR
value|0x000E0000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_END_FLAG
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_ERROR_FLAG
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_SD_ADDRESS_SHIFT
value|0L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the page map address word of the  * on-chip generic DMA requestor.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DMA_RQ_PMA_LOOP_THIRD_PAGE_ENTRY_MASK
value|0x00000FF8L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_PMA_PAGE_TABLE_MASK
value|0xFFFFF000L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_PMA_LOOP_THIRD_PAGE_ENTRY_SHIFT
value|3L
end_define

begin_define
define|#
directive|define
name|DMA_RQ_PMA_PAGE_TABLE_SHIFT
value|12L
end_define

begin_comment
comment|/*****************************************************************************  *  * The following defines are for the flags in the rsConfig01/23 registers of  * the SP.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_SIZE_MASK
value|0x0000000FL
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_16
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_32
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_64
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_128
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_256
value|0x00000005L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_512
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_1024
value|0x00000007L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_4
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MODULO_8
value|0x00000009L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_SAMPLE_SIZE_MASK
value|0x000000C0L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_SAMPLE_8MONO
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_SAMPLE_8STEREO
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_SAMPLE_16MONO
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_SAMPLE_16STEREO
value|0x000000C0L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_UNDERRUN_ZERO
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_DMA_TO_HOST
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_STREAM_NUM_MASK
value|0x00FF0000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MAX_DMA_SIZE_MASK
value|0x1F000000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_DMA_ENABLE
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_PRIORITY_MASK
value|0xC0000000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_PRIORITY_HIGH
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_PRIORITY_MEDIUM_HIGH
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_PRIORITY_MEDIUM_LOW
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_PRIORITY_LOW
value|0xC0000000L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_STREAM_NUM_SHIFT
value|16L
end_define

begin_define
define|#
directive|define
name|RSCONFIG_MAX_DMA_SIZE_SHIFT
value|24L
end_define

begin_define
define|#
directive|define
name|BA1_VARIDEC_BUF_1
value|0x000
end_define

begin_define
define|#
directive|define
name|BA1_PDTC
value|0x0c0
end_define

begin_comment
comment|/* BA1_PLAY_DMA_TRANSACTION_COUNT_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_PFIE
value|0x0c4
end_define

begin_comment
comment|/* BA1_PLAY_FORMAT_&_INTERRUPT_ENABLE_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_PBA
value|0x0c8
end_define

begin_comment
comment|/* BA1_PLAY_BUFFER_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|BA1_PVOL
value|0x0f8
end_define

begin_comment
comment|/* BA1_PLAY_VOLUME_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_PSRC
value|0x288
end_define

begin_comment
comment|/* BA1_PLAY_SAMPLE_RATE_CORRECTION_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_PCTL
value|0x2a4
end_define

begin_comment
comment|/* BA1_PLAY_CONTROL_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_PPI
value|0x2b4
end_define

begin_comment
comment|/* BA1_PLAY_PHASE_INCREMENT_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CCTL
value|0x064
end_define

begin_comment
comment|/* BA1_CAPTURE_CONTROL_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CIE
value|0x104
end_define

begin_comment
comment|/* BA1_CAPTURE_INTERRUPT_ENABLE_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CBA
value|0x10c
end_define

begin_comment
comment|/* BA1_CAPTURE_BUFFER_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|BA1_CSRC
value|0x2c8
end_define

begin_comment
comment|/* BA1_CAPTURE_SAMPLE_RATE_CORRECTION_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CCI
value|0x2d8
end_define

begin_comment
comment|/* BA1_CAPTURE_COEFFICIENT_INCREMENT_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CD
value|0x2e0
end_define

begin_comment
comment|/* BA1_CAPTURE_DELAY_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CPI
value|0x2f4
end_define

begin_comment
comment|/* BA1_CAPTURE_PHASE_INCREMENT_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CVOL
value|0x2f8
end_define

begin_comment
comment|/* BA1_CAPTURE_VOLUME_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CFG1
value|0x134
end_define

begin_comment
comment|/* BA1_CAPTURE_FRAME_GROUP_1_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CFG2
value|0x138
end_define

begin_comment
comment|/* BA1_CAPTURE_FRAME_GROUP_2_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CCST
value|0x13c
end_define

begin_comment
comment|/* BA1_CAPTURE_CONSTANT_REG */
end_comment

begin_define
define|#
directive|define
name|BA1_CSPB
value|0x340
end_define

begin_comment
comment|/* BA1_CAPTURE_SPB_ADDRESS */
end_comment

begin_comment
comment|/* The following struct holds the initialization array. */
end_comment

begin_comment
comment|/*  * this is 3*1024 for parameter, 3.5*1024 for sample and 2*3.5*1024 for code since   * each instruction is 40 bits and takes two dwords   */
end_comment

begin_define
define|#
directive|define
name|INKY_BA1_DWORD_SIZE
value|(13 * 1024 + 512)
end_define

begin_define
define|#
directive|define
name|INKY_MEMORY_COUNT
value|3
end_define

begin_struct
struct|struct
name|BA1struct
block|{
struct|struct
block|{
name|u_long
name|ulDestByteOffset
decl_stmt|,
name|ulSourceByteSize
decl_stmt|;
block|}
name|MemoryStat
index|[
name|INKY_MEMORY_COUNT
index|]
struct|;
name|u_long
name|BA1Array
index|[
name|INKY_BA1_DWORD_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CSA_REG_H */
end_comment

end_unit

