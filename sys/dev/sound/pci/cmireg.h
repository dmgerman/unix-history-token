begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Takuya SHIOZAKI<AoiMoe@imou.to> .  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* C-Media CMI8x38 Audio Chip Support */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_PCI_CMPCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_PCI_CMPCIREG_H_
value|(1)
end_define

begin_comment
comment|/*  * PCI Configuration Registers  */
end_comment

begin_define
define|#
directive|define
name|CMPCI_PCI_IOBASEREG
value|(PCI_MAPREG_START)
end_define

begin_comment
comment|/*  * I/O Space  */
end_comment

begin_define
define|#
directive|define
name|CMPCI_REG_FUNC_0
value|0x00
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_DIR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_DIR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_PAUSE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_PAUSE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_ENABLE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_ENABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_RESET
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_RESET
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FUNC_1
value|0x04
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_JOY_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_UART_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_LEGACY_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_BREQ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_MCBINTR_ENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_SPDIFOUT_DAC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_SPDIF_LOOP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_SPDIF0_ENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_SPDIF1_ENABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DAC_FS_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DAC_FS_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_ADC_FS_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_ADC_FS_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CHANNEL_FORMAT
value|0x08
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_FORMAT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_FORMAT_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_FORMAT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_FORMAT_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FORMAT_MONO
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FORMAT_STEREO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FORMAT_8BIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FORMAT_16BIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_INTR_CTRL
value|0x0c
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_INTR_ENABLE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_INTR_ENABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_TDMA_INTR_ENABLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_INTR_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_INTR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_INTR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH0_BUSY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_CH1_BUSY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_LEGACY_STEREO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_LEGACY_HDMA
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DMASTAT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_XDO46
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_HTDMA_INTR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_LTDMA_INTR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_UART_INTR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_MCB_INTR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_VCO
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_ANY_INTR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_LEGACY_CTRL
value|0x14
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_LEGACY_SPDIF_ENABLE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_SPDIF_COPYRIGHT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_XSPDIF_ENABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FMSEL_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FMSEL_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_VSBSEL_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_VSBSEL_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_VMPUSEL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_VMPUSEL_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_MISC
value|0x18
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_POWER_DOWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_BUS_AND_DSP_RESET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_N4SPK3D
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_W_SPDIF_48L
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_XCHGDAC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FM_ENABLE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_SPDIF_48K
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_SBDATA
value|0x22
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_SBADDR
value|0x23
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_MASTER_L
value|0x30
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_MASTER_R
value|0x31
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_VOICE_L
value|0x32
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_VOICE_R
value|0x33
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_FM_L
value|0x34
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_FM_R
value|0x35
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_CDDA_L
value|0x36
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_CDDA_R
value|0x37
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_LINE_L
value|0x38
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_LINE_R
value|0x39
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_MIC
value|0x3A
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_SPEAKER
value|0x3B
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_OUTMIX
value|0x3C
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_MIC
value|0x01
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_CD_R
value|0x02
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_CD_L
value|0x04
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_CD
value|(CMPCI_SB16_SW_CD_L|CMPCI_SB16_SW_CD_R)
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_LINE_R
value|0x08
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_LINE_L
value|0x10
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_LINE
value|(CMPCI_SB16_SW_LINE_L|CMPCI_SB16_SW_LINE_R)
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_FM_R
value|0x20
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_FM_L
value|0x40
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_SW_FM
value|(CMPCI_SB16_SW_FM_L|CMPCI_SB16_SW_FM_R)
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_ADCMIX_L
value|0x3D
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_ADCMIX_R
value|0x3E
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_FM_SRC_R
value|0x20
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_LINE_SRC_R
value|0x08
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_CD_SRC_R
value|0x02
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_MIC_SRC
value|0x01
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_SRC_R_TO_L
parameter_list|(
name|v
parameter_list|)
value|((v)<< 1)
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_INGAIN_L
value|0x3F
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_INGAIN_R
value|0x40
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_OUTGAIN_L
value|0x41
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_OUTGAIN_R
value|0x42
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_AGC
value|0x43
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_TREBLE_L
value|0x44
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_TREBLE_R
value|0x45
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_BASS_L
value|0x46
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_BASS_R
value|0x47
end_define

begin_define
define|#
directive|define
name|CMPCI_SB16_MIXER_L_TO_R
parameter_list|(
name|addr
parameter_list|)
value|((addr)+1)
end_define

begin_define
define|#
directive|define
name|CMPCI_ADJUST_MIC_GAIN
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|cmpci_adjust((x), 0xf8)
end_define

begin_define
define|#
directive|define
name|CMPCI_ADJUST_GAIN
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|cmpci_adjust((x), 0xf8)
end_define

begin_define
define|#
directive|define
name|CMPCI_ADJUST_2_GAIN
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|cmpci_adjust((x), 0xc0)
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_MIXER1
value|0x24
end_define

begin_define
define|#
directive|define
name|CMPCI_SPK4
value|0x20
end_define

begin_define
define|#
directive|define
name|CMPCI_REAR2FRONT
value|0x10
end_define

begin_define
define|#
directive|define
name|CMPCI_X3DEN
value|0x02
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_MPU_BASE
value|0x40
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_MPU_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FM_BASE
value|0x50
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_FM_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_AUX_MIC
value|0x25
end_define

begin_define
define|#
directive|define
name|CMPCI_AUX_SELECT_R
value|0x80
end_define

begin_define
define|#
directive|define
name|CMPCI_AUX_SELECT_L
value|0x40
end_define

begin_define
define|#
directive|define
name|CMPCI_AUX_MUTE_R
value|0x20
end_define

begin_define
define|#
directive|define
name|CMPCI_AUX_MUTE_L
value|0x10
end_define

begin_define
define|#
directive|define
name|CMPCI_VAD_MIC
value|0x0e
end_define

begin_define
define|#
directive|define
name|CMPCI_MIC_QUIET
value|0x01
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DMA0_BASE
value|0x80
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DMA0_BYTES
value|0x84
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DMA0_SAMPLES
value|0x86
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DMA1_BASE
value|0x88
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DMA1_BYTES
value|0x8C
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_DMA1_SAMPLES
value|0x8E
end_define

begin_comment
comment|/* sample rate */
end_comment

begin_define
define|#
directive|define
name|CMPCI_REG_RATE_5512
value|0
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_RATE_11025
value|1
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_RATE_22050
value|2
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_RATE_44100
value|3
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_RATE_8000
value|4
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_RATE_16000
value|5
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_RATE_32000
value|6
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_RATE_48000
value|7
end_define

begin_define
define|#
directive|define
name|CMPCI_REG_NUMRATE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_PCI_CMPCIREG_H_ */
end_comment

begin_comment
comment|/* end of file */
end_comment

end_unit

