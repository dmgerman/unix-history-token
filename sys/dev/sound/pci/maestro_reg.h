begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2000 Taku YAMAMOTO<taku@cent.saitama-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: maestro_reg.h,v 1.10 2000/08/29 17:27:29 taku Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAESTRO_REG_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|MAESTRO_REG_H_INCLUDED
end_define

begin_comment
comment|/* -----------------------------  * PCI config registers  */
end_comment

begin_comment
comment|/* Legacy emulation */
end_comment

begin_define
define|#
directive|define
name|CONF_LEGACY
value|0x40
end_define

begin_define
define|#
directive|define
name|LEGACY_DISABLED
value|0x8000
end_define

begin_comment
comment|/* Chip configurations */
end_comment

begin_define
define|#
directive|define
name|CONF_MAESTRO
value|0x50
end_define

begin_define
define|#
directive|define
name|MAESTRO_CHIBUS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MAESTRO_POSTEDWRITE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MAESTRO_DMA_PCITIMING
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MAESTRO_SWAP_LR
value|0x00000010
end_define

begin_comment
comment|/* ACPI configurations */
end_comment

begin_define
define|#
directive|define
name|CONF_ACPI_STOPCLOCK
value|0x54
end_define

begin_define
define|#
directive|define
name|ACPI_PART_2ndC_CLOCK
value|15
end_define

begin_define
define|#
directive|define
name|ACPI_PART_CODEC_CLOCK
value|14
end_define

begin_define
define|#
directive|define
name|ACPI_PART_978
value|13
end_define

begin_comment
comment|/* Docking station or something */
end_comment

begin_define
define|#
directive|define
name|ACPI_PART_SPDIF
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_PART_GLUE
value|11
end_define

begin_comment
comment|/* What? */
end_comment

begin_define
define|#
directive|define
name|ACPI_PART_DAA
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_PART_PCI_IF
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_PART_HW_VOL
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_PART_GPIO
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_PART_ASSP
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_PART_SB
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_PART_FM
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_PART_RINGBUS
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_PART_MIDI
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_PART_GAME_PORT
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_PART_WP
value|0
end_define

begin_comment
comment|/* Power management */
end_comment

begin_define
define|#
directive|define
name|CONF_PM_PTR
value|0x34
end_define

begin_comment
comment|/* BYTE R */
end_comment

begin_define
define|#
directive|define
name|PM_CID
value|0
end_define

begin_comment
comment|/* BYTE R */
end_comment

begin_define
define|#
directive|define
name|PPMI_CID
value|1
end_define

begin_define
define|#
directive|define
name|PM_CTRL
value|4
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|PPMI_D0
value|0
end_define

begin_comment
comment|/* Full power */
end_comment

begin_define
define|#
directive|define
name|PPMI_D1
value|1
end_define

begin_comment
comment|/* Medium power */
end_comment

begin_define
define|#
directive|define
name|PPMI_D2
value|2
end_define

begin_comment
comment|/* Low power */
end_comment

begin_define
define|#
directive|define
name|PPMI_D3
value|3
end_define

begin_comment
comment|/* Turned off */
end_comment

begin_comment
comment|/* -----------------------------  * I/O ports  */
end_comment

begin_comment
comment|/* Direct Sound Processor (aka WP) */
end_comment

begin_define
define|#
directive|define
name|PORT_DSP_DATA
value|0x00
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|PORT_DSP_INDEX
value|0x02
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|PORT_INT_STAT
value|0x04
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|PORT_SAMPLE_CNT
value|0x06
end_define

begin_comment
comment|/* WORD RO */
end_comment

begin_comment
comment|/* WaveCache */
end_comment

begin_define
define|#
directive|define
name|PORT_WAVCACHE_INDEX
value|0x10
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|PORT_WAVCACHE_DATA
value|0x12
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|WAVCACHE_PCMBAR
value|0x1fc
end_define

begin_define
define|#
directive|define
name|WAVCACHE_WTBAR
value|0x1f0
end_define

begin_define
define|#
directive|define
name|WAVCACHE_BASEADDR_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|WAVCACHE_CHCTL_ADDRTAG_MASK
value|0xfff8
end_define

begin_define
define|#
directive|define
name|WAVCACHE_CHCTL_U8
value|0x0004
end_define

begin_define
define|#
directive|define
name|WAVCACHE_CHCTL_STEREO
value|0x0002
end_define

begin_define
define|#
directive|define
name|WAVCACHE_CHCTL_DECREMENTAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|PORT_WAVCACHE_CTRL
value|0x14
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|WAVCACHE_EXTRA_CH_ENABLED
value|0x0200
end_define

begin_define
define|#
directive|define
name|WAVCACHE_ENABLED
value|0x0100
end_define

begin_define
define|#
directive|define
name|WAVCACHE_CH_60_ENABLED
value|0x0080
end_define

begin_define
define|#
directive|define
name|WAVCACHE_WTSIZE_MASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|WAVCACHE_WTSIZE_1MB
value|0x0000
end_define

begin_define
define|#
directive|define
name|WAVCACHE_WTSIZE_2MB
value|0x0020
end_define

begin_define
define|#
directive|define
name|WAVCACHE_WTSIZE_4MB
value|0x0040
end_define

begin_define
define|#
directive|define
name|WAVCACHE_WTSIZE_8MB
value|0x0060
end_define

begin_define
define|#
directive|define
name|WAVCACHE_SGC_MASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|WAVCACHE_SGC_DISABLED
value|0x0000
end_define

begin_define
define|#
directive|define
name|WAVCACHE_SGC_40_47
value|0x0004
end_define

begin_define
define|#
directive|define
name|WAVCACHE_SGC_32_47
value|0x0008
end_define

begin_define
define|#
directive|define
name|WAVCACHE_TESTMODE
value|0x0001
end_define

begin_comment
comment|/* Host Interruption */
end_comment

begin_define
define|#
directive|define
name|PORT_HOSTINT_CTRL
value|0x18
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|HOSTINT_CTRL_SOFT_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_DSOUND_RESET
value|0x4000
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_HW_VOL_TO_PME
value|0x0400
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_CLKRUN_ENABLED
value|0x0100
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_HWVOL_ENABLED
value|0x0040
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_ASSP_INT_ENABLED
value|0x0010
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_ISDN_INT_ENABLED
value|0x0008
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_DSOUND_INT_ENABLED
value|0x0004
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_MPU401_INT_ENABLED
value|0x0002
end_define

begin_define
define|#
directive|define
name|HOSTINT_CTRL_SB_INT_ENABLED
value|0x0001
end_define

begin_define
define|#
directive|define
name|PORT_HOSTINT_STAT
value|0x1a
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|HOSTINT_STAT_HWVOL
value|0x40
end_define

begin_define
define|#
directive|define
name|HOSTINT_STAT_ASSP
value|0x10
end_define

begin_define
define|#
directive|define
name|HOSTINT_STAT_ISDN
value|0x08
end_define

begin_define
define|#
directive|define
name|HOSTINT_STAT_DSOUND
value|0x04
end_define

begin_define
define|#
directive|define
name|HOSTINT_STAT_MPU401
value|0x02
end_define

begin_define
define|#
directive|define
name|HOSTINT_STAT_SB
value|0x01
end_define

begin_comment
comment|/* Hardware volume */
end_comment

begin_define
define|#
directive|define
name|PORT_HWVOL_VOICE_SHADOW
value|0x1c
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|PORT_HWVOL_VOICE
value|0x1d
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|PORT_HWVOL_MASTER_SHADOW
value|0x1e
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|PORT_HWVOL_MASTER
value|0x1f
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|HWVOL_NOP
value|0x88
end_define

begin_define
define|#
directive|define
name|HWVOL_MUTE
value|0x99
end_define

begin_define
define|#
directive|define
name|HWVOL_UP
value|0xaa
end_define

begin_define
define|#
directive|define
name|HWVOL_DOWN
value|0x66
end_define

begin_comment
comment|/* CODEC */
end_comment

begin_define
define|#
directive|define
name|PORT_CODEC_CMD
value|0x30
end_define

begin_comment
comment|/* BYTE W */
end_comment

begin_define
define|#
directive|define
name|CODEC_CMD_READ
value|0x80
end_define

begin_define
define|#
directive|define
name|CODEC_CMD_WRITE
value|0x00
end_define

begin_define
define|#
directive|define
name|CODEC_CMD_ADDR_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|PORT_CODEC_STAT
value|0x30
end_define

begin_comment
comment|/* BYTE R */
end_comment

begin_define
define|#
directive|define
name|CODEC_STAT_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|CODEC_STAT_RW_DONE
value|0x00
end_define

begin_define
define|#
directive|define
name|CODEC_STAT_PROGLESS
value|0x01
end_define

begin_define
define|#
directive|define
name|PORT_CODEC_REG
value|0x32
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_comment
comment|/* Ring bus control */
end_comment

begin_define
define|#
directive|define
name|PORT_RINGBUS_CTRL
value|0x34
end_define

begin_comment
comment|/* DWORD RW */
end_comment

begin_define
define|#
directive|define
name|RINGBUS_CTRL_I2S_ENABLED
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RINGBUS_CTRL_RINGBUS_ENABLED
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RINGBUS_CTRL_ACLINK_ENABLED
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RINGBUS_CTRL_AC97_SWRESET
value|0x08000000
end_define

begin_define
define|#
directive|define
name|RINGBUS_CTRL_IODMA_PLAYBACK_ENABLED
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RINGBUS_CTRL_IODMA_RECORD_ENABLED
value|0x02000000
end_define

begin_define
define|#
directive|define
name|RINGBUS_SRC_MIC
value|20
end_define

begin_define
define|#
directive|define
name|RINGBUS_SRC_I2S
value|16
end_define

begin_define
define|#
directive|define
name|RINGBUS_SRC_ADC
value|12
end_define

begin_define
define|#
directive|define
name|RINGBUS_SRC_MODEM
value|8
end_define

begin_define
define|#
directive|define
name|RINGBUS_SRC_DSOUND
value|4
end_define

begin_define
define|#
directive|define
name|RINGBUS_SRC_ASSP
value|0
end_define

begin_define
define|#
directive|define
name|RINGBUS_DEST_MONORAL
value|000
end_define

begin_define
define|#
directive|define
name|RINGBUS_DEST_STEREO
value|010
end_define

begin_define
define|#
directive|define
name|RINGBUS_DEST_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RINGBUS_DEST_DAC
value|1
end_define

begin_define
define|#
directive|define
name|RINGBUS_DEST_MODEM_IN
value|2
end_define

begin_define
define|#
directive|define
name|RINGBUS_DEST_RESERVED3
value|3
end_define

begin_define
define|#
directive|define
name|RINGBUS_DEST_DSOUND_IN
value|4
end_define

begin_define
define|#
directive|define
name|RINGBUS_DEST_ASSP_IN
value|5
end_define

begin_comment
comment|/* General Purpose I/O */
end_comment

begin_define
define|#
directive|define
name|PORT_GPIO_DATA
value|0x60
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|PORT_GPIO_MASK
value|0x64
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|PORT_GPIO_DIR
value|0x68
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_comment
comment|/* Application Specific Signal Processor */
end_comment

begin_define
define|#
directive|define
name|PORT_ASSP_MEM_INDEX
value|0x80
end_define

begin_comment
comment|/* DWORD RW */
end_comment

begin_define
define|#
directive|define
name|PORT_ASSP_MEM_DATA
value|0x84
end_define

begin_comment
comment|/* WORD RW */
end_comment

begin_define
define|#
directive|define
name|PORT_ASSP_CTRL_A
value|0xa2
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|PORT_ASSP_CTRL_B
value|0xa4
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|PORT_ASSP_CTRL_C
value|0xa6
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|PORT_ASSP_HOST_WR_INDEX
value|0xa8
end_define

begin_comment
comment|/* BYTE W */
end_comment

begin_define
define|#
directive|define
name|PORT_ASSP_HOST_WR_DATA
value|0xaa
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_define
define|#
directive|define
name|PORT_ASSP_INT_STAT
value|0xac
end_define

begin_comment
comment|/* BYTE RW */
end_comment

begin_comment
comment|/* -----------------------------  * Wave Processor Indexed Data Registers.  */
end_comment

begin_define
define|#
directive|define
name|WPREG_DATA_PORT
value|0
end_define

begin_define
define|#
directive|define
name|WPREG_CRAM_PTR
value|1
end_define

begin_define
define|#
directive|define
name|WPREG_CRAM_DATA
value|2
end_define

begin_define
define|#
directive|define
name|WPREG_WAVE_DATA
value|3
end_define

begin_define
define|#
directive|define
name|WPREG_WAVE_PTR_LOW
value|4
end_define

begin_define
define|#
directive|define
name|WPREG_WAVE_PTR_HIGH
value|5
end_define

begin_define
define|#
directive|define
name|WPREG_TIMER_FREQ
value|6
end_define

begin_define
define|#
directive|define
name|WP_TIMER_FREQ_PRESCALE_MASK
value|0x00e0
end_define

begin_comment
comment|/* actual - 9 */
end_comment

begin_define
define|#
directive|define
name|WP_TIMER_FREQ_PRESCALE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|WP_TIMER_FREQ_DIVIDE_MASK
value|0x001f
end_define

begin_define
define|#
directive|define
name|WP_TIMER_FREQ_DIVIDE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|WPREG_WAVE_ROMRAM
value|7
end_define

begin_define
define|#
directive|define
name|WP_WAVE_VIRTUAL_ENABLED
value|0x0400
end_define

begin_define
define|#
directive|define
name|WP_WAVE_8BITRAM_ENABLED
value|0x0200
end_define

begin_define
define|#
directive|define
name|WP_WAVE_DRAM_ENABLED
value|0x0100
end_define

begin_define
define|#
directive|define
name|WP_WAVE_RAMSPLIT_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|WP_WAVE_RAMSPLIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|WPREG_BASE
value|12
end_define

begin_define
define|#
directive|define
name|WP_PARAOUT_BASE_MASK
value|0xf000
end_define

begin_define
define|#
directive|define
name|WP_PARAOUT_BASE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|WP_PARAIN_BASE_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|WP_PARAIN_BASE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|WP_SERIAL0_BASE_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|WP_SERIAL0_BASE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|WP_SERIAL1_BASE_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|WP_SERIAL1_BASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|WPREG_TIMER_ENABLE
value|17
end_define

begin_define
define|#
directive|define
name|WPREG_TIMER_START
value|23
end_define

begin_comment
comment|/* -----------------------------  * Audio Processing Unit.  */
end_comment

begin_define
define|#
directive|define
name|APUREG_APUTYPE
value|0
end_define

begin_define
define|#
directive|define
name|APU_DMA_ENABLED
value|0x4000
end_define

begin_define
define|#
directive|define
name|APU_INT_ON_LOOP
value|0x2000
end_define

begin_define
define|#
directive|define
name|APU_ENDCURVE
value|0x1000
end_define

begin_define
define|#
directive|define
name|APU_APUTYPE_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|APU_FILTERTYPE_MASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|APU_FILTERQ_MASK
value|0x0003
end_define

begin_comment
comment|/* APU types */
end_comment

begin_define
define|#
directive|define
name|APU_APUTYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|APUTYPE_INACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|APUTYPE_16BITLINEAR
value|1
end_define

begin_define
define|#
directive|define
name|APUTYPE_16BITSTEREO
value|2
end_define

begin_define
define|#
directive|define
name|APUTYPE_8BITLINEAR
value|3
end_define

begin_define
define|#
directive|define
name|APUTYPE_8BITSTEREO
value|4
end_define

begin_define
define|#
directive|define
name|APUTYPE_8BITDIFF
value|5
end_define

begin_define
define|#
directive|define
name|APUTYPE_DIGITALDELAY
value|6
end_define

begin_define
define|#
directive|define
name|APUTYPE_DUALTAP_READER
value|7
end_define

begin_define
define|#
directive|define
name|APUTYPE_CORRELATOR
value|8
end_define

begin_define
define|#
directive|define
name|APUTYPE_INPUTMIXER
value|9
end_define

begin_define
define|#
directive|define
name|APUTYPE_WAVETABLE
value|10
end_define

begin_define
define|#
directive|define
name|APUTYPE_RATECONV
value|11
end_define

begin_define
define|#
directive|define
name|APUTYPE_16BITPINGPONG
value|12
end_define

begin_comment
comment|/* APU type 13 through 15 are reserved. */
end_comment

begin_comment
comment|/* Filter types */
end_comment

begin_define
define|#
directive|define
name|APU_FILTERTYPE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|FILTERTYPE_2POLE_LOPASS
value|0
end_define

begin_define
define|#
directive|define
name|FILTERTYPE_2POLE_BANDPASS
value|1
end_define

begin_define
define|#
directive|define
name|FILTERTYPE_2POLE_HIPASS
value|2
end_define

begin_define
define|#
directive|define
name|FILTERTYPE_1POLE_LOPASS
value|3
end_define

begin_define
define|#
directive|define
name|FILTERTYPE_1POLE_HIPASS
value|4
end_define

begin_define
define|#
directive|define
name|FILTERTYPE_PASSTHROUGH
value|5
end_define

begin_comment
comment|/* Filter Q */
end_comment

begin_define
define|#
directive|define
name|APU_FILTERQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FILTERQ_LESSQ
value|0
end_define

begin_define
define|#
directive|define
name|FILTERQ_MOREQ
value|3
end_define

begin_comment
comment|/* APU register 2 */
end_comment

begin_define
define|#
directive|define
name|APUREG_FREQ_LOBYTE
value|2
end_define

begin_define
define|#
directive|define
name|APU_FREQ_LOBYTE_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|APU_plus6dB
value|0x0010
end_define

begin_comment
comment|/* APU register 3 */
end_comment

begin_define
define|#
directive|define
name|APUREG_FREQ_HIWORD
value|3
end_define

begin_define
define|#
directive|define
name|APU_FREQ_HIWORD_MASK
value|0x0fff
end_define

begin_comment
comment|/* Frequency */
end_comment

begin_define
define|#
directive|define
name|APU_FREQ_LOBYTE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|APU_FREQ_HIWORD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FREQ_Hz2DIV
parameter_list|(
name|freq
parameter_list|)
value|(((u_int64_t)(freq)<< 16) / 48000)
end_define

begin_comment
comment|/* APU register 4 */
end_comment

begin_define
define|#
directive|define
name|APUREG_WAVESPACE
value|4
end_define

begin_define
define|#
directive|define
name|APU_STEREO
value|0x8000
end_define

begin_define
define|#
directive|define
name|APU_USE_SYSMEM
value|0x4000
end_define

begin_define
define|#
directive|define
name|APU_PCMBAR_MASK
value|0x6000
end_define

begin_define
define|#
directive|define
name|APU_64KPAGE_MASK
value|0xff00
end_define

begin_comment
comment|/* PCM Base Address Register selection */
end_comment

begin_define
define|#
directive|define
name|APU_PCMBAR_SHIFT
value|13
end_define

begin_comment
comment|/* 64KW (==128KB) Page */
end_comment

begin_define
define|#
directive|define
name|APU_64KPAGE_SHIFT
value|8
end_define

begin_comment
comment|/* APU register 5 - 7 */
end_comment

begin_define
define|#
directive|define
name|APUREG_CURPTR
value|5
end_define

begin_define
define|#
directive|define
name|APUREG_ENDPTR
value|6
end_define

begin_define
define|#
directive|define
name|APUREG_LOOPLEN
value|7
end_define

begin_comment
comment|/* APU register 9 */
end_comment

begin_define
define|#
directive|define
name|APUREG_AMPLITUDE
value|9
end_define

begin_define
define|#
directive|define
name|APU_AMPLITUDE_NOW_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|APU_AMPLITUDE_DEST_MASK
value|0x00ff
end_define

begin_comment
comment|/* Amplitude now? */
end_comment

begin_define
define|#
directive|define
name|APU_AMPLITUDE_NOW_SHIFT
value|8
end_define

begin_comment
comment|/* APU register 10 */
end_comment

begin_define
define|#
directive|define
name|APUREG_POSITION
value|10
end_define

begin_define
define|#
directive|define
name|APU_RADIUS_MASK
value|0x00c0
end_define

begin_define
define|#
directive|define
name|APU_PAN_MASK
value|0x003f
end_define

begin_comment
comment|/* Radius control. */
end_comment

begin_define
define|#
directive|define
name|APU_RADIUS_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|RADIUS_CENTERCIRCLE
value|0
end_define

begin_define
define|#
directive|define
name|RADIUS_MIDDLE
value|1
end_define

begin_define
define|#
directive|define
name|RADIUS_OUTSIDE
value|2
end_define

begin_comment
comment|/* Polar pan. */
end_comment

begin_define
define|#
directive|define
name|APU_PAN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAN_RIGHT
value|0x00
end_define

begin_define
define|#
directive|define
name|PAN_FRONT
value|0x08
end_define

begin_define
define|#
directive|define
name|PAN_LEFT
value|0x10
end_define

begin_comment
comment|/* -----------------------------  * Limits.  */
end_comment

begin_define
define|#
directive|define
name|WPWA_MAX
value|((1<< 22) - 1)
end_define

begin_define
define|#
directive|define
name|WPWA_MAXADDR
value|((1<< 23) - 1)
end_define

begin_define
define|#
directive|define
name|MAESTRO_MAXADDR
value|((1<< 28) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAESTRO_REG_H_INCLUDED */
end_comment

end_unit

