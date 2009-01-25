begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2008 by Marco Trillo. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Apple DAVbus audio controller.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SOUND_DAVBUS_H
end_ifndef

begin_define
define|#
directive|define
name|_SOUND_DAVBUS_H
end_define

begin_comment
comment|/* DAVbus controller registers. */
end_comment

begin_define
define|#
directive|define
name|DAVBUS_SOUND_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|DAVBUS_CODEC_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|DAVBUS_CODEC_STATUS
value|0x20
end_define

begin_define
define|#
directive|define
name|DAVBUS_CLIP_COUNT
value|0x30
end_define

begin_define
define|#
directive|define
name|DAVBUS_BYTE_SWAP
value|0x40
end_define

begin_comment
comment|/*  * The DAVbus uses a serial bus time multiplexed in four subframes,  * but the controller itself uses subframe 0 to communicate with the codec.  * In some machines, the other subframes may be used by external devices  * thorugh the DAV interface.  */
end_comment

begin_comment
comment|/* DAVBUS_SOUND_CTRL bit definitions. */
end_comment

begin_define
define|#
directive|define
name|DAVBUS_INPUT_SUBFRAME0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DAVBUS_INPUT_SUBFRAME1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DAVBUS_INPUT_SUBFRAME2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DAVBUS_INPUT_SUBFRAME3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DAVBUS_OUTPUT_SUBFRAME0
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DAVBUS_OUTPUT_SUBFRAME1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DAVBUS_OUTPUT_SUBFRAME2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DAVBUS_OUTPUT_SUBFRAME3
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_44100
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_29400
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_22050
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_17640
value|0x00000300
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_14700
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_11025
value|0x00000500
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_8820
value|0x00000600
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_7350
value|0x00000700
end_define

begin_define
define|#
directive|define
name|DAVBUS_RATE_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|DAVBUS_ERROR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DAVBUS_PORTCHG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DAVBUS_INTR_ERROR
value|0x00002000
end_define

begin_comment
comment|/* interrupt on error */
end_comment

begin_define
define|#
directive|define
name|DAVBUS_INTR_PORTCHG
value|0x00004000
end_define

begin_comment
comment|/* interrupt on port change */
end_comment

begin_define
define|#
directive|define
name|DAVBUS_STATUS_SUBFRAME
value|0x00018000
end_define

begin_comment
comment|/* mask */
end_comment

begin_comment
comment|/* DAVBUS_CODEC_CTRL bit definitions. */
end_comment

begin_define
define|#
directive|define
name|DAVBUS_CODEC_BUSY
value|0x01000000
end_define

begin_comment
comment|/*  * Burgundy Codec Control Bits  */
end_comment

begin_comment
comment|/* Burgundy transaction bits. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_CTRL_RESET
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_CTRL_WRITE
value|0x00200000
end_define

begin_comment
comment|/* Mute control for each analog output port. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MUTE_REG
value|0x16000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_P13M_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|BURGUNDY_P14L_EN
value|0x02
end_define

begin_define
define|#
directive|define
name|BURGUNDY_P14R_EN
value|0x04
end_define

begin_define
define|#
directive|define
name|BURGUNDY_P15L_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|BURGUNDY_P15R_EN
value|0x10
end_define

begin_define
define|#
directive|define
name|BURGUNDY_P16L_EN
value|0x20
end_define

begin_define
define|#
directive|define
name|BURGUNDY_P16R_EN
value|0x40
end_define

begin_define
define|#
directive|define
name|BURGUNDY_P17M_EN
value|0x80
end_define

begin_comment
comment|/* Attenuation of each analog output port. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_OL13_REG
value|0x16100
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OL14_REG
value|0x16200
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OL15_REG
value|0x16300
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OL16_REG
value|0x16400
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OL17_REG
value|0x16500
end_define

begin_comment
comment|/* Inputs of four digital mixers. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MIX0_REG
value|0x42900
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX1_REG
value|0x42A00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX2_REG
value|0x42B00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX3_REG
value|0x42C00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX_IS0
value|0x00010001
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX_IS1
value|0x00020002
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX_IS2
value|0x00040004
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX_IS3
value|0x00080008
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX_IS4
value|0x00100010
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MIX_ISA
value|0x01000100
end_define

begin_comment
comment|/* Digital stream ISA. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MIX_ISB
value|0x02000200
end_define

begin_comment
comment|/* Digital stream ISB. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MIX_ISC
value|0x04000400
end_define

begin_comment
comment|/* Digital stream ISC. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MIX_ISD
value|0x08000800
end_define

begin_comment
comment|/* Digital stream ISD. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MIX_ISE
value|0x10001000
end_define

begin_comment
comment|/* Digital stream ISE. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MIX_ISF
value|0x20002000
end_define

begin_comment
comment|/* Digital stream ISF. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MIX_ISG
value|0x40004000
end_define

begin_comment
comment|/* Digital stream ISG. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MIX_ISH
value|0x80008000
end_define

begin_comment
comment|/* Digital stream ISH. */
end_comment

begin_comment
comment|/* A digital scalar at the output of each mixer. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_MXS0L_REG
value|0x12D00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MXS0R_REG
value|0x12D01
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MXS1L_REG
value|0x12D02
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MXS1R_REG
value|0x12D03
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MXS2L_REG
value|0x12E00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MXS2R_REG
value|0x12E01
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MXS3L_REG
value|0x12E02
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MXS3R_REG
value|0x12E03
end_define

begin_define
define|#
directive|define
name|BURGUNDY_MXS_UNITY
value|0xDF
end_define

begin_comment
comment|/* Demultiplexer. Routes the mixer 0-3 (see above) to output sources.    Output sources 0-2 can be converted to analog. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_OS_REG
value|0x42F00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS0_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS0_MIX1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS0_MIX2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS0_MIX3
value|0x00000003
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS1_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS1_MIX1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS1_MIX2
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS1_MIX3
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS2_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS2_MIX1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS2_MIX2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS2_MIX3
value|0x00000030
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS3_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS3_MIX1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS3_MIX2
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OS3_MIX3
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSA_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSA_MIX1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSA_MIX2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSA_MIX3
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSB_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSB_MIX1
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSB_MIX2
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSB_MIX3
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSC_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSC_MIX1
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSC_MIX2
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSC_MIX3
value|0x00300000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSD_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSD_MIX1
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSD_MIX2
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSD_MIX3
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSE_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSE_MIX1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSE_MIX2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSE_MIX3
value|0x03000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSF_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSF_MIX1
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSF_MIX2
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSF_MIX3
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSG_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSG_MIX1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSG_MIX2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSG_MIX3
value|0x30000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSH_MIX0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSH_MIX1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSH_MIX2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSH_MIX3
value|0xC0000000
end_define

begin_comment
comment|/* A digital scalar for output sources 0 to 3. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_OSS0L_REG
value|0x13000
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSS0R_REG
value|0x13001
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSS1L_REG
value|0x13002
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSS1R_REG
value|0x13003
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSS2L_REG
value|0x13100
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSS2R_REG
value|0x13101
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSS3L_REG
value|0x13102
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSS3R_REG
value|0x13103
end_define

begin_define
define|#
directive|define
name|BURGUNDY_OSS_UNITY
value|0xDF
end_define

begin_comment
comment|/* Digital input streams ISA-ISC. A stream may be derived from data coming     from the controller in subframes 0 to 3 as well as from internal     output sources OSA-OSD. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_SDIN_REG
value|0x17800
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISA_SF0
value|0x00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISA_OSA
value|0x02
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISB_SF1
value|0x00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISB_OSB
value|0x08
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISC_SF2
value|0x00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISC_OSC
value|0x20
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISD_SF3
value|0x00
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISD_OSD
value|0x80
end_define

begin_comment
comment|/* A digital scaler for input streams 0-4 A-H. */
end_comment

begin_define
define|#
directive|define
name|BURGUNDY_ISSAL_REG
value|0x12500
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISSAR_REG
value|0x12501
end_define

begin_define
define|#
directive|define
name|BURGUNDY_ISS_UNITY
value|0xDF
end_define

begin_comment
comment|/*  * Screamer codec control bits   * This codec has the following 12-bit control registers:  *	cc0 cc1 cc2 cc4 cc5 cc6 cc7  */
end_comment

begin_comment
comment|/* screamer transaction bits. */
end_comment

begin_define
define|#
directive|define
name|SCREAMER_CODEC_ADDR0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_ADDR1
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_ADDR2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_ADDR4
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_ADDR5
value|0x00005000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_ADDR6
value|0x00006000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_ADDR7
value|0x00007000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_EMSEL0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_EMSEL1
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_EMSEL2
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SCREAMER_CODEC_EMSEL4
value|0x00c00000
end_define

begin_comment
comment|/* cc0 */
end_comment

begin_comment
comment|/*  * Bits 7-4 specify the left ADC input gain;  * bits 3-0 specify the right ADC input gain.  *  * The gain is a 4-bit value expressed in units of 1.5 dB,   * ranging from 0 dB (0) to +22.5 dB (15).  */
end_comment

begin_define
define|#
directive|define
name|SCREAMER_DEFAULT_CD_GAIN
value|0x000000bb
end_define

begin_comment
comment|/* +16.5 dB */
end_comment

begin_define
define|#
directive|define
name|SCREAMER_INPUT_CD
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCREAMER_INPUT_LINE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SCREAMER_INPUT_MICROPHONE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SCREAMER_INPUT_MASK
value|0x00000e00
end_define

begin_comment
comment|/* cc1 */
end_comment

begin_define
define|#
directive|define
name|SCREAMER_LOOP_THROUGH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SCREAMER_MUTE_SPEAKER
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SCREAMER_MUTE_HEADPHONES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCREAMER_PARALLEL_OUTPUT
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|SCREAMER_PROG_OUTPUT0
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SCREAMER_PROG_OUTPUT1
value|0x00000800
end_define

begin_comment
comment|/* cc2: headphones/external port attenuation */
end_comment

begin_comment
comment|/* cc4: internal speaker attenuation */
end_comment

begin_comment
comment|/*  * Bits 9-6 specify left DAC output attenuation.  * Bits 3-0 specify right DAC output attenuation.  *  * The attenuation is a 4-bit value expressed in units of -1.5 dB,  * ranging from 0 dB (0) to -22.5 dB (15).  */
end_comment

begin_comment
comment|/* screamer codec status bits. */
end_comment

begin_define
define|#
directive|define
name|SCREAMER_STATUS_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_SENSEMASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_SENSE0
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_SENSE1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_SENSE2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_SENSE3
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_PARTMASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_PARTSHFT
value|8
end_define

begin_define
define|#
directive|define
name|SCREAMER_PART_CRYSTAL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SCREAMER_PART_NATIONAL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCREAMER_PART_TI
value|0x00000300
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_REVMASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|SCREAMER_STATUS_REVSHFT
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SOUND_DAVBUS_H */
end_comment

end_unit

