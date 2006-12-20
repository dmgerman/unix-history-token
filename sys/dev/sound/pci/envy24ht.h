begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Konstantin Dimitrov<kosio.dimitrov@gmail.com>  * Copyright (c) 2001 Katsurajima Naoto<raven@katsurajima.seya.yokohama.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* PCI device ID */
end_comment

begin_define
define|#
directive|define
name|PCIV_ENVY24
value|0x1412
end_define

begin_define
define|#
directive|define
name|PCID_ENVY24HT
value|0x1724
end_define

begin_define
define|#
directive|define
name|PCIR_CCS
value|0x10
end_define

begin_comment
comment|/* Controller I/O Base Address */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_PCIR_MT
value|0x14
end_define

begin_comment
comment|/* Multi-Track I/O Base Address */
end_comment

begin_comment
comment|/* Controller Registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_CTL
value|0x00
end_define

begin_comment
comment|/* Control/Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_CTL_RESET
value|0x80
end_define

begin_comment
comment|/* Entire Chip soft reset */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_IMASK
value|0x01
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_IMASK_PMT
value|0x10
end_define

begin_comment
comment|/* Professional Multi-track */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CDEV
value|0x10
end_define

begin_comment
comment|/* I2C Port Device Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CDEV_ADDR
value|0xfe
end_define

begin_comment
comment|/* I2C device address */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CDEV_ROM
value|0xa0
end_define

begin_comment
comment|/* reserved for the external I2C E2PROM */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CDEV_WR
value|0x01
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CDEV_RD
value|0x00
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CADDR
value|0x11
end_define

begin_comment
comment|/* I2C Port Byte Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CDATA
value|0x12
end_define

begin_comment
comment|/* I2C Port Read/Write Data Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CSTAT
value|0x13
end_define

begin_comment
comment|/* I2C Port Control and Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CSTAT_ROM
value|0x80
end_define

begin_comment
comment|/* external E2PROM exists */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2CSTAT_BSY
value|0x01
end_define

begin_comment
comment|/* I2C port read/write status busy */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_SCFG
value|0x04
end_define

begin_comment
comment|/* System Configuration Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SCFG_XIN2
value|0xc0
end_define

begin_comment
comment|/* XIN2 Clock Source Configuration */
end_comment

begin_comment
comment|/* 00: 24.576MHz(96kHz*256) */
end_comment

begin_comment
comment|/* 01: 49.152MHz(192kHz*256) */
end_comment

begin_comment
comment|/* 1x: Reserved */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SCFG_MPU
value|0x20
end_define

begin_comment
comment|/* 0(not implemented)/1(1) MPU-401 UART */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SCFG_ADC
value|0x0c
end_define

begin_comment
comment|/* 1-2 stereo ADC connected, S/PDIF receiver connected */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SCFG_DAC
value|0x03
end_define

begin_comment
comment|/* 1-4 stereo DAC connected */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_ACL
value|0x05
end_define

begin_comment
comment|/* AC-Link Configuration Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_ACL_MTC
value|0x80
end_define

begin_comment
comment|/* Multi-track converter type: 0:AC'97 1:I2S */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_ACL_OMODE
value|0x02
end_define

begin_comment
comment|/* AC 97 codec SDATA_OUT 0:split 1:packed */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_I2S
value|0x06
end_define

begin_comment
comment|/* I2S Converters Features Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_VOL
value|0x80
end_define

begin_comment
comment|/* I2S codec Volume and mute */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_96KHZ
value|0x40
end_define

begin_comment
comment|/* I2S converter 96kHz sampling rate support */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_192KHZ
value|0x08
end_define

begin_comment
comment|/* I2S converter 192kHz sampling rate support */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_RES
value|0x30
end_define

begin_comment
comment|/* Converter resolution */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_16BIT
value|0x00
end_define

begin_comment
comment|/* 16bit */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_18BIT
value|0x10
end_define

begin_comment
comment|/* 18bit */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_20BIT
value|0x20
end_define

begin_comment
comment|/* 20bit */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_24BIT
value|0x30
end_define

begin_comment
comment|/* 24bit */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_I2S_ID
value|0x07
end_define

begin_comment
comment|/* Other I2S IDs */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_SPDIF
value|0x07
end_define

begin_comment
comment|/* S/PDIF Configuration Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SPDIF_INT_EN
value|0x80
end_define

begin_comment
comment|/* Enable integrated S/PDIF transmitter */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SPDIF_INT_OUT
value|0x40
end_define

begin_comment
comment|/* Internal S/PDIF Out implemented */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SPDIF_ID
value|0x3c
end_define

begin_comment
comment|/* S/PDIF chip ID */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SPDIF_IN
value|0x02
end_define

begin_comment
comment|/* S/PDIF Stereo In is present */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCSM_SPDIF_OUT
value|0x01
end_define

begin_comment
comment|/* External S/PDIF Out implemented */
end_comment

begin_comment
comment|/* Professional Multi-Track Control Registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_INT_STAT
value|0x00
end_define

begin_comment
comment|/* DMA Interrupt Mask and Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_INT_RSTAT
value|0x02
end_define

begin_comment
comment|/* Multi-track record interrupt status */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_INT_PSTAT
value|0x01
end_define

begin_comment
comment|/* Multi-track playback interrupt status */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_INT_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_INT_RMASK
value|0x02
end_define

begin_comment
comment|/* Multi-track record interrupt mask */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_INT_PMASK
value|0x01
end_define

begin_comment
comment|/* Multi-track playback interrupt mask */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE
value|0x01
end_define

begin_comment
comment|/* Sampling Rate Select Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_SPDIF
value|0x10
end_define

begin_comment
comment|/* S/PDIF input clock as the master */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_48000
value|0x00
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_24000
value|0x01
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_12000
value|0x02
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_9600
value|0x03
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_32000
value|0x04
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_16000
value|0x05
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_8000
value|0x06
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_96000
value|0x07
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_64000
value|0x0f
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_44100
value|0x08
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_22050
value|0x09
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_11025
value|0x0a
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_88200
value|0x0b
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_RATE_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MT_PADDR
value|0x10
end_define

begin_comment
comment|/* Playback DMA Current/Base Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_PCNT
value|0x14
end_define

begin_comment
comment|/* Playback DMA Current/Base Count Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_PTERM
value|0x1C
end_define

begin_comment
comment|/* Playback Current/Base Terminal Count Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_PCTL
value|0x18
end_define

begin_comment
comment|/* Global Playback and Record DMA Start/Stop Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_PCTL_RSTART
value|0x02
end_define

begin_comment
comment|/* 1: Record start; 0: Record stop */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_PCTL_PSTART
value|0x01
end_define

begin_comment
comment|/* 1: Playback start; 0: Playback stop */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_RADDR
value|0x20
end_define

begin_comment
comment|/* Record DMA Current/Base Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_RCNT
value|0x24
end_define

begin_comment
comment|/* Record DMA Current/Base Count Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_MT_RTERM
value|0x26
end_define

begin_comment
comment|/* Record Current/Base Terminal Count Register */
end_comment

begin_comment
comment|/*   These map values are refferd from ALSA sound driver. */
end_comment

begin_comment
comment|/* ENVY24 configuration E2PROM map */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_SUBVENDOR
value|0x02
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_SUBDEVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_SIZE
value|0x04
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_VERSION
value|0x05
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_SCFG
value|0x06
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_ACL
value|0x07
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_I2S
value|0x08
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_SPDIF
value|0x09
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_GPIOMASK
value|0x0d
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_GPIOSTATE
value|0x10
end_define

begin_define
define|#
directive|define
name|ENVY24HT_E2PROM_GPIODIR
value|0x0a
end_define

begin_comment
comment|/* ENVY24 mixer channel defines */
end_comment

begin_comment
comment|/*   ENVY24 mixer has original line matrix. So, general mixer command is not   able to use for this. If system has consumer AC'97 output, AC'97 line is   used as master mixer, and it is able to control. */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_NUM
value|11
end_define

begin_comment
comment|/* Play * 5 + Record * 5 + Mix * 1 */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_PLAY_DAC1
value|0
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_PLAY_DAC2
value|1
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_PLAY_DAC3
value|2
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_PLAY_DAC4
value|3
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_PLAY_SPDIF
value|4
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_REC_ADC1
value|5
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_REC_ADC2
value|6
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_REC_ADC3
value|7
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_REC_ADC4
value|8
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_REC_SPDIF
value|9
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CHAN_REC_MIX
value|10
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MIX_MASK
value|0x3fd
end_define

begin_define
define|#
directive|define
name|ENVY24HT_MIX_REC_MASK
value|0x3e0
end_define

begin_comment
comment|/* volume value constants */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_VOL_MAX
value|0
end_define

begin_comment
comment|/* 0db(negate) */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_VOL_MIN
value|96
end_define

begin_comment
comment|/* -144db(negate) */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_VOL_MUTE
value|127
end_define

begin_comment
comment|/* mute */
end_comment

begin_define
define|#
directive|define
name|BUS_SPACE_MAXADDR_ENVY24
value|0x0fffffff
end_define

begin_comment
comment|/* Address space beyond 256MB is not  supported */
end_comment

begin_define
define|#
directive|define
name|BUS_SPACE_MAXSIZE_ENVY24
value|0x3fffc
end_define

begin_comment
comment|/* 64k x 4byte(1dword) */
end_comment

begin_define
define|#
directive|define
name|ENVY24HT_CCS_GPIO_HDATA
value|0x1E
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CCS_GPIO_LDATA
value|0x14
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CCS_GPIO_LMASK
value|0x16
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CCS_GPIO_HMASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|ENVY24HT_CCS_GPIO_CTLDIR
value|0x18
end_define

end_unit

