begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Orion Hodson<O.Hodson@cs.ucl.ac.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* PCI Configuration Register Offsets */
end_comment

begin_define
define|#
directive|define
name|SV_PCI_COMPAT
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_PCI_ENHANCED
value|0x14
end_define

begin_define
define|#
directive|define
name|SV_PCI_FMSYNTH
value|0x18
end_define

begin_define
define|#
directive|define
name|SV_PCI_MIDI
value|0x1c
end_define

begin_define
define|#
directive|define
name|SV_PCI_GAMES
value|0x20
end_define

begin_define
define|#
directive|define
name|SV_PCI_DMAA
value|0x40
end_define

begin_define
define|#
directive|define
name|SV_PCI_DMAC
value|0x48
end_define

begin_define
define|#
directive|define
name|SV_PCI_DMAA_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_PCI_DMAA_ALIGN
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_PCI_DMAC_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_PCI_DMAC_ALIGN
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_PCI_ENHANCED_SIZE
value|0x08
end_define

begin_define
define|#
directive|define
name|SV_PCI_DMA_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SV_PCI_DMA_EXTENDED
value|0x00000008
end_define

begin_comment
comment|/* ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* DMA Configuration Registers */
end_comment

begin_define
define|#
directive|define
name|SV_DMA_ADDR
value|0x00
end_define

begin_define
define|#
directive|define
name|SV_DMA_COUNT
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_DMA_MODE
value|0x0B
end_define

begin_define
define|#
directive|define
name|SV_DMA_MODE_AUTO
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_DMA_MODE_RD
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_DMA_MODE_WR
value|0x08
end_define

begin_comment
comment|/* ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* Enhanced Mode Configuration Registers */
end_comment

begin_define
define|#
directive|define
name|SV_CM_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|SV_CM_CONTROL_ENHANCED
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_CM_CONTROL_TEST
value|0x02
end_define

begin_define
define|#
directive|define
name|SV_CM_CONTROL_REVERB
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_CM_CONTROL_PWS
value|0x08
end_define

begin_define
define|#
directive|define
name|SV_CM_CONTROL_INTA
value|0x20
end_define

begin_define
define|#
directive|define
name|SV_CM_CONTROL_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|SV_CM_IMR
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_CM_IMR_AMSK
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_CM_IMR_CMSK
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_CM_IMR_SMSK
value|0x08
end_define

begin_define
define|#
directive|define
name|SV_CM_IMR_UDM
value|0x40
end_define

begin_define
define|#
directive|define
name|SV_CM_IMR_MIDM
value|0x80
end_define

begin_define
define|#
directive|define
name|SV_CM_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|SV_CM_STATUS_AINT
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_CM_STATUS_CINT
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_CM_STATUS_SINT
value|0x08
end_define

begin_define
define|#
directive|define
name|SV_CM_STATUS_UDI
value|0x40
end_define

begin_define
define|#
directive|define
name|SV_CM_STATUS_MI
value|0x80
end_define

begin_define
define|#
directive|define
name|SV_CM_INDEX
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_CM_INDEX_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|SV_CM_INDEX_MCE
value|0x40
end_define

begin_define
define|#
directive|define
name|SV_CM_INDEX_TRD
value|0x80
end_define

begin_define
define|#
directive|define
name|SV_CM_DATA
value|0x05
end_define

begin_comment
comment|/* ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* Indexed Codec/Mixer Registers (left channels were applicable) */
end_comment

begin_define
define|#
directive|define
name|SV_REG_ADC_INPUT
value|0x00
end_define

begin_define
define|#
directive|define
name|SV_INPUT_GAIN_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|SV_INPUT_MICGAIN
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_INPUT_CD
value|0x20
end_define

begin_define
define|#
directive|define
name|SV_INPUT_DAC
value|0x40
end_define

begin_define
define|#
directive|define
name|SV_INPUT_AUX2
value|0x60
end_define

begin_define
define|#
directive|define
name|SV_INPUT_LINE
value|0x80
end_define

begin_define
define|#
directive|define
name|SV_INPUT_AUX1
value|0xa0
end_define

begin_define
define|#
directive|define
name|SV_INPUT_MIC
value|0xc0
end_define

begin_define
define|#
directive|define
name|SV_INPUT_MIXOUT
value|0xe0
end_define

begin_define
define|#
directive|define
name|SV_REG_AUX1
value|0x02
end_define

begin_define
define|#
directive|define
name|SV_REG_CD
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_REG_LINE
value|0x06
end_define

begin_define
define|#
directive|define
name|SV_REG_MIC
value|0x08
end_define

begin_define
define|#
directive|define
name|SV_REG_SYNTH
value|0x0a
end_define

begin_define
define|#
directive|define
name|SV_REG_AUX2
value|0x0c
end_define

begin_define
define|#
directive|define
name|SV_REG_MIX
value|0x0e
end_define

begin_define
define|#
directive|define
name|SV_REG_PCM
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_DEFAULT_MAX
value|0x1f
end_define

begin_define
define|#
directive|define
name|SV_ADC_MAX
value|0x0f
end_define

begin_define
define|#
directive|define
name|SV_MIC_MAX
value|0x0f
end_define

begin_define
define|#
directive|define
name|SV_PCM_MAX
value|0x3f
end_define

begin_define
define|#
directive|define
name|SV_MUTE
value|0x80
end_define

begin_define
define|#
directive|define
name|SV_REG_FORMAT
value|0x12
end_define

begin_define
define|#
directive|define
name|SV_AFMT_MONO
value|0x00
end_define

begin_define
define|#
directive|define
name|SV_AFMT_STEREO
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_AFMT_S16
value|0x02
end_define

begin_define
define|#
directive|define
name|SV_AFMT_U8
value|0x00
end_define

begin_define
define|#
directive|define
name|SV_AFMT_DMAA
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|SV_AFMT_DMAA_MSK
value|0x03
end_define

begin_define
define|#
directive|define
name|SV_AFMT_DMAC
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|SV_AFMT_DMAC_MSK
value|0x30
end_define

begin_define
define|#
directive|define
name|SV_REG_ENABLE
value|0x13
end_define

begin_define
define|#
directive|define
name|SV_PLAY_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_RECORD_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|SV_PLAYBACK_PAUSE
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_REG_REVISION
value|0x15
end_define

begin_define
define|#
directive|define
name|SV_REG_LOOPBACK
value|0x16
end_define

begin_define
define|#
directive|define
name|SV_LOOPBACK_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_LOOPBACK_MAX
value|0x3f
end_define

begin_define
define|#
directive|define
name|SV_LOOPBACK_LEVEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 2)
end_define

begin_define
define|#
directive|define
name|SV_REG_DMAA_COUNT_HI
value|0x18
end_define

begin_define
define|#
directive|define
name|SV_REG_DMAA_COUNT_LO
value|0x19
end_define

begin_define
define|#
directive|define
name|SV_REG_DMAC_COUNT_HI
value|0x1c
end_define

begin_define
define|#
directive|define
name|SV_REG_DMAC_COUNT_LO
value|0x1d
end_define

begin_define
define|#
directive|define
name|SV_REG_PCM_SAMPLING_LO
value|0x1e
end_define

begin_define
define|#
directive|define
name|SV_REG_PCM_SAMPLING_HI
value|0x1f
end_define

begin_define
define|#
directive|define
name|SV_REG_SYN_SAMPLING_LO
value|0x20
end_define

begin_define
define|#
directive|define
name|SV_REG_SYN_SAMPLING_HI
value|0x21
end_define

begin_define
define|#
directive|define
name|SV_REG_CLOCK_SOURCE
value|0x22
end_define

begin_define
define|#
directive|define
name|SV_CLOCK_ALTERNATE
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_REG_ALT_RATE
value|0x23
end_define

begin_define
define|#
directive|define
name|SV_REG_ADC_PLLM
value|0x24
end_define

begin_define
define|#
directive|define
name|SV_REG_ADC_PLLN
value|0x25
end_define

begin_define
define|#
directive|define
name|SV_ADC_PLLN
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1f)
end_define

begin_define
define|#
directive|define
name|SV_ADC_PLLR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|SV_REG_SYNTH_PLLM
value|0x26
end_define

begin_define
define|#
directive|define
name|SV_REG_SYNTH_PLLN
value|0x27
end_define

begin_define
define|#
directive|define
name|SV_SYNTH_PLLN
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1f)
end_define

begin_define
define|#
directive|define
name|SV_SYNTH_PLLR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|SV_REG_SRS_SPACE
value|0x2c
end_define

begin_define
define|#
directive|define
name|SV_SRS_SPACE_100
value|0x00
end_define

begin_define
define|#
directive|define
name|SV_SRS_SPACE_75
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_SRS_SPACE_50
value|0x02
end_define

begin_define
define|#
directive|define
name|SV_SRS_SPACE_25
value|0x03
end_define

begin_define
define|#
directive|define
name|SV_SRS_SPACE_0
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_SRS_DISABLED
value|0x80
end_define

begin_define
define|#
directive|define
name|SV_REG_SRS_CENTER
value|0x2d
end_define

begin_define
define|#
directive|define
name|SV_SRS_CENTER_100
value|0x00
end_define

begin_define
define|#
directive|define
name|SV_SRS_CENTER_75
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_SRS_CENTER_50
value|0x02
end_define

begin_define
define|#
directive|define
name|SV_SRS_CENTER_25
value|0x03
end_define

begin_define
define|#
directive|define
name|SV_SRS_CENTER_0
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_REG_ANALOG_PWR
value|0x30
end_define

begin_define
define|#
directive|define
name|SV_ANALOG_OFF_DAC
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_ANALOG_OFF_ADC
value|0x08
end_define

begin_define
define|#
directive|define
name|SV_ANALOG_OFF_MIX
value|0x10
end_define

begin_define
define|#
directive|define
name|SV_ANALOG_OFF_SRS
value|0x20
end_define

begin_define
define|#
directive|define
name|SV_ANALOG_OFF_SPLL
value|0x40
end_define

begin_define
define|#
directive|define
name|SV_ANALOG_OFF_APLL
value|0x80
end_define

begin_define
define|#
directive|define
name|SV_ANALOG_OFF
value|0xf9
end_define

begin_define
define|#
directive|define
name|SV_REG_DIGITAL_PWR
value|0x31
end_define

begin_define
define|#
directive|define
name|SV_DIGITAL_OFF_SYN
value|0x01
end_define

begin_define
define|#
directive|define
name|SV_DIGITAL_OFF_MU
value|0x02
end_define

begin_define
define|#
directive|define
name|SV_DIGITAL_OFF_GP
value|0x04
end_define

begin_define
define|#
directive|define
name|SV_DIGITAL_OFF_BI
value|0x08
end_define

begin_define
define|#
directive|define
name|SV_DIGITAL_OFF
value|0x0f
end_define

begin_comment
comment|/* ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* ADC PLL constants */
end_comment

begin_define
define|#
directive|define
name|SV_F_SCALE
value|512
end_define

begin_define
define|#
directive|define
name|SV_F_REF
value|24576000
end_define

end_unit

