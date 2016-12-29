begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|CODEC_RGADW
value|0x00
end_define

begin_comment
comment|/* Address, data in and write command */
end_comment

begin_define
define|#
directive|define
name|RGADW_ICRST
value|(1<< 31)
end_define

begin_comment
comment|/* Reset internal CODEC */
end_comment

begin_define
define|#
directive|define
name|RGADW_RGWR
value|(1<< 16)
end_define

begin_comment
comment|/* Issue a write command to CODEC */
end_comment

begin_define
define|#
directive|define
name|RGADW_RGADDR_S
value|8
end_define

begin_comment
comment|/* CODEC register's address. */
end_comment

begin_define
define|#
directive|define
name|RGADW_RGADDR_M
value|(0x7f<< RGADW_RGADDR_S)
end_define

begin_define
define|#
directive|define
name|RGADW_RGDIN_S
value|0
end_define

begin_comment
comment|/* CODEC register data to write */
end_comment

begin_define
define|#
directive|define
name|RGADW_RGDIN_M
value|(0xff<< RGADW_RGDIN_S)
end_define

begin_define
define|#
directive|define
name|CODEC_RGDATA
value|0x04
end_define

begin_comment
comment|/* The data read out */
end_comment

begin_define
define|#
directive|define
name|SR
value|0x00
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|SR2
value|0x01
end_define

begin_comment
comment|/* Status Register 2 */
end_comment

begin_define
define|#
directive|define
name|MR
value|0x07
end_define

begin_comment
comment|/* Mode status register */
end_comment

begin_define
define|#
directive|define
name|AICR_DAC
value|0x08
end_define

begin_comment
comment|/* DAC Audio Interface Control Register */
end_comment

begin_define
define|#
directive|define
name|DAC_ADWL_S
value|6
end_define

begin_comment
comment|/* Audio Data Word Length for DAC path. */
end_comment

begin_define
define|#
directive|define
name|DAC_ADWL_M
value|(0x3<< DAC_ADWL_S)
end_define

begin_define
define|#
directive|define
name|DAC_ADWL_16
value|(0<< DAC_ADWL_S)
end_define

begin_define
define|#
directive|define
name|AICR_DAC_SB
value|(1<< 4)
end_define

begin_comment
comment|/* DAC audio interface in power-down mode */
end_comment

begin_define
define|#
directive|define
name|AUDIOIF_S
value|0
end_define

begin_define
define|#
directive|define
name|AUDIOIF_M
value|(0x3<< AUDIOIF_S)
end_define

begin_define
define|#
directive|define
name|AUDIOIF_I2S
value|0x3
end_define

begin_comment
comment|/* I2S interface */
end_comment

begin_define
define|#
directive|define
name|AUDIOIF_DSP
value|0x2
end_define

begin_comment
comment|/* DSP interface */
end_comment

begin_define
define|#
directive|define
name|AUDIOIF_LJ
value|0x1
end_define

begin_comment
comment|/* Left-justified interface */
end_comment

begin_define
define|#
directive|define
name|AUDIOIF_P
value|0x0
end_define

begin_comment
comment|/* Parallel interface */
end_comment

begin_define
define|#
directive|define
name|AICR_ADC
value|0x09
end_define

begin_comment
comment|/* ADC Audio Interface Control Register */
end_comment

begin_define
define|#
directive|define
name|CR_LO
value|0x0B
end_define

begin_comment
comment|/* Differential line-out Control Register */
end_comment

begin_define
define|#
directive|define
name|CR_HP
value|0x0D
end_define

begin_comment
comment|/* HeadPhone Control Register */
end_comment

begin_define
define|#
directive|define
name|HP_MUTE
value|(1<< 7)
end_define

begin_comment
comment|/* no signal on headphone outputs */
end_comment

begin_define
define|#
directive|define
name|HP_SB
value|(1<< 4)
end_define

begin_comment
comment|/* power-down */
end_comment

begin_define
define|#
directive|define
name|CR_DMIC
value|0x10
end_define

begin_comment
comment|/* Digital Microphone register */
end_comment

begin_define
define|#
directive|define
name|CR_MIC1
value|0x11
end_define

begin_comment
comment|/* Microphone1 Control register */
end_comment

begin_define
define|#
directive|define
name|CR_MIC2
value|0x12
end_define

begin_comment
comment|/* Microphone2 Control register */
end_comment

begin_define
define|#
directive|define
name|CR_LI1
value|0x13
end_define

begin_comment
comment|/* Control Register for line1 inputs */
end_comment

begin_define
define|#
directive|define
name|CR_LI2
value|0x14
end_define

begin_comment
comment|/* Control Register for line2 inputs */
end_comment

begin_define
define|#
directive|define
name|CR_DAC
value|0x17
end_define

begin_comment
comment|/* DAC Control Register */
end_comment

begin_define
define|#
directive|define
name|DAC_MUTE
value|(1<< 7)
end_define

begin_comment
comment|/* puts the DAC in soft mute mode */
end_comment

begin_define
define|#
directive|define
name|DAC_SB
value|(1<< 4)
end_define

begin_comment
comment|/* power-down */
end_comment

begin_define
define|#
directive|define
name|CR_ADC
value|0x18
end_define

begin_comment
comment|/* ADC Control Register */
end_comment

begin_define
define|#
directive|define
name|CR_MIX
value|0x19
end_define

begin_comment
comment|/* Digital Mixer Control Register */
end_comment

begin_define
define|#
directive|define
name|DR_MIX
value|0x1A
end_define

begin_comment
comment|/* Digital Mixer Data Register */
end_comment

begin_define
define|#
directive|define
name|CR_VIC
value|0x1B
end_define

begin_comment
comment|/* Control Register for the ViC */
end_comment

begin_define
define|#
directive|define
name|VIC_SB_SLEEP
value|(1<< 1)
end_define

begin_comment
comment|/* sleep mode */
end_comment

begin_define
define|#
directive|define
name|VIC_SB
value|(1<< 0)
end_define

begin_comment
comment|/* complete power-down */
end_comment

begin_define
define|#
directive|define
name|CR_CK
value|0x1C
end_define

begin_comment
comment|/* Clock Control Register */
end_comment

begin_define
define|#
directive|define
name|FCR_DAC
value|0x1D
end_define

begin_comment
comment|/* DAC Frequency Control Register */
end_comment

begin_define
define|#
directive|define
name|FCR_DAC_48
value|8
end_define

begin_comment
comment|/* 48 kHz. */
end_comment

begin_define
define|#
directive|define
name|FCR_DAC_96
value|10
end_define

begin_comment
comment|/* 96 kHz. */
end_comment

begin_define
define|#
directive|define
name|FCR_ADC
value|0x20
end_define

begin_comment
comment|/* ADC Frequency Control Register */
end_comment

begin_define
define|#
directive|define
name|CR_TIMER_MSB
value|0x21
end_define

begin_comment
comment|/* MSB of programmable counter */
end_comment

begin_define
define|#
directive|define
name|CR_TIMER_LSB
value|0x22
end_define

begin_comment
comment|/* LSB of programmable counter */
end_comment

begin_define
define|#
directive|define
name|ICR
value|0x23
end_define

begin_comment
comment|/* Interrupt Control Register */
end_comment

begin_define
define|#
directive|define
name|IMR
value|0x24
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|IFR
value|0x25
end_define

begin_comment
comment|/* Interrupt Flag Register */
end_comment

begin_define
define|#
directive|define
name|IMR2
value|0x26
end_define

begin_comment
comment|/* Interrupt Mask Register 2 */
end_comment

begin_define
define|#
directive|define
name|IFR2
value|0x27
end_define

begin_comment
comment|/* Interrupt Flag Register 2 */
end_comment

begin_define
define|#
directive|define
name|GCR_HPL
value|0x28
end_define

begin_comment
comment|/* Left channel headphone Control Gain Register */
end_comment

begin_define
define|#
directive|define
name|GCR_HPR
value|0x29
end_define

begin_comment
comment|/* Right channel headphone Control Gain Register */
end_comment

begin_define
define|#
directive|define
name|GCR_LIBYL
value|0x2A
end_define

begin_comment
comment|/* Left channel bypass line Control Gain Register */
end_comment

begin_define
define|#
directive|define
name|GCR_LIBYR
value|0x2B
end_define

begin_comment
comment|/* Right channel bypass line Control Gain Register */
end_comment

begin_define
define|#
directive|define
name|GCR_DACL
value|0x2C
end_define

begin_comment
comment|/* Left channel DAC Gain Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_DACR
value|0x2D
end_define

begin_comment
comment|/* Right channel DAC Gain Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_MIC1
value|0x2E
end_define

begin_comment
comment|/* Microphone 1 Gain Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_MIC2
value|0x2F
end_define

begin_comment
comment|/* Microphone 2 Gain Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_ADCL
value|0x30
end_define

begin_comment
comment|/* Left ADC Gain Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_ADCR
value|0x31
end_define

begin_comment
comment|/* Right ADC Gain Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_MIXDACL
value|0x34
end_define

begin_comment
comment|/* DAC Digital Mixer Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_MIXDACR
value|0x35
end_define

begin_comment
comment|/* DAC Digital Mixer Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_MIXADCL
value|0x36
end_define

begin_comment
comment|/* ADC Digital Mixer Control Register */
end_comment

begin_define
define|#
directive|define
name|GCR_MIXADCR
value|0x37
end_define

begin_comment
comment|/* ADC Digital Mixer Control Register */
end_comment

begin_define
define|#
directive|define
name|CR_ADC_AGC
value|0x3A
end_define

begin_comment
comment|/* Automatic Gain Control Register */
end_comment

begin_define
define|#
directive|define
name|DR_ADC_AGC
value|0x3B
end_define

begin_comment
comment|/* Automatic Gain Control Data Register */
end_comment

end_unit

