begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Katsurajima Naoto<raven@katsurajima.seya.yokohama.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|PCID_ENVY24
value|0x1712
end_define

begin_comment
comment|/* PCI Registers */
end_comment

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
name|PCIR_DDMA
value|0x14
end_define

begin_comment
comment|/* DDMA I/O Base Address */
end_comment

begin_define
define|#
directive|define
name|PCIR_DS
value|0x18
end_define

begin_comment
comment|/* DMA Path Registers I/O Base Address */
end_comment

begin_define
define|#
directive|define
name|PCIR_MT
value|0x1c
end_define

begin_comment
comment|/* Professional Multi-Track I/O Base Address */
end_comment

begin_define
define|#
directive|define
name|PCIR_LAC
value|0x40
end_define

begin_comment
comment|/* Legacy Audio Control */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_DISABLE
value|0x8000
end_define

begin_comment
comment|/* Legacy Audio Hardware disabled */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_SBDMA0
value|0x0000
end_define

begin_comment
comment|/* SB DMA Channel Select: 0 */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_SBDMA1
value|0x0040
end_define

begin_comment
comment|/* SB DMA Channel Select: 1 */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_SBDMA3
value|0x00c0
end_define

begin_comment
comment|/* SB DMA Channel Select: 3 */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_IOADDR10
value|0x0020
end_define

begin_comment
comment|/* I/O Address Alias Control */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_MPU401
value|0x0008
end_define

begin_comment
comment|/* MPU-401 I/O enable */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_GAME
value|0x0004
end_define

begin_comment
comment|/* Game Port enable (200h) */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_FM
value|0x0002
end_define

begin_comment
comment|/* FM I/O enable (AdLib 388h base) */
end_comment

begin_define
define|#
directive|define
name|PCIM_LAC_SB
value|0x0001
end_define

begin_comment
comment|/* SB I/O enable */
end_comment

begin_define
define|#
directive|define
name|PCIR_LCC
value|0x42
end_define

begin_comment
comment|/* Legacy Configuration Control */
end_comment

begin_define
define|#
directive|define
name|PCIM_LCC_VINT
value|0xff00
end_define

begin_comment
comment|/* Interrupt vector to be snooped */
end_comment

begin_define
define|#
directive|define
name|PCIM_LCC_SVIDRW
value|0x0080
end_define

begin_comment
comment|/* SVID read/write enable */
end_comment

begin_define
define|#
directive|define
name|PCIM_LCC_SNPSB
value|0x0040
end_define

begin_comment
comment|/* snoop SB 22C/24Ch I/O write cycle */
end_comment

begin_define
define|#
directive|define
name|PCIM_LCC_SNPPIC
value|0x0020
end_define

begin_comment
comment|/* snoop PIC I/O R/W cycle */
end_comment

begin_define
define|#
directive|define
name|PCIM_LCC_SNPPCI
value|0x0010
end_define

begin_comment
comment|/* snoop PCI bus interrupt acknowledge cycle */
end_comment

begin_define
define|#
directive|define
name|PCIM_LCC_SBBASE
value|0x0008
end_define

begin_comment
comment|/* SB base 240h(1)/220h(0) */
end_comment

begin_define
define|#
directive|define
name|PCIM_LCC_MPUBASE
value|0x0006
end_define

begin_comment
comment|/* MPU-401 base 300h-330h */
end_comment

begin_define
define|#
directive|define
name|PCIM_LCC_LDMA
value|0x0001
end_define

begin_comment
comment|/* Legacy DMA enable */
end_comment

begin_define
define|#
directive|define
name|PCIR_SCFG
value|0x60
end_define

begin_comment
comment|/* System Configuration Register */
end_comment

begin_define
define|#
directive|define
name|PCIM_SCFG_XIN2
value|0xc0
end_define

begin_comment
comment|/* XIN2 Clock Source Configuration */
end_comment

begin_comment
comment|/* 00: 22.5792MHz(44.1kHz*512) */
end_comment

begin_comment
comment|/* 01: 16.9344MHz(44.1kHz*384) */
end_comment

begin_comment
comment|/* 10: from external clock synthesizer chip */
end_comment

begin_define
define|#
directive|define
name|PCIM_SCFG_MPU
value|0x20
end_define

begin_comment
comment|/* 1(0)/2(1) MPU-401 UART(s) */
end_comment

begin_define
define|#
directive|define
name|PCIM_SCFG_AC97
value|0x10
end_define

begin_comment
comment|/* 0: AC'97 codec exist */
end_comment

begin_comment
comment|/* 1: AC'97 codec not exist */
end_comment

begin_define
define|#
directive|define
name|PCIM_SCFG_ADC
value|0x0c
end_define

begin_comment
comment|/* 1-4 stereo ADC connected */
end_comment

begin_define
define|#
directive|define
name|PCIM_SCFG_DAC
value|0x03
end_define

begin_comment
comment|/* 1-4 stereo DAC connected */
end_comment

begin_define
define|#
directive|define
name|PCIR_ACL
value|0x61
end_define

begin_comment
comment|/* AC-Link Configuration Register */
end_comment

begin_define
define|#
directive|define
name|PCIM_ACL_MTC
value|0x80
end_define

begin_comment
comment|/* Multi-track converter type: 0:AC'97 1:I2S */
end_comment

begin_define
define|#
directive|define
name|PCIM_ACL_OMODE
value|0x02
end_define

begin_comment
comment|/* AC 97 codec SDATA_OUT 0:split 1:packed */
end_comment

begin_define
define|#
directive|define
name|PCIM_ACL_IMODE
value|0x01
end_define

begin_comment
comment|/* AC 97 codec SDATA_IN 0:split 1:packed */
end_comment

begin_define
define|#
directive|define
name|PCIR_I2S
value|0x62
end_define

begin_comment
comment|/* I2S Converters Features Register */
end_comment

begin_define
define|#
directive|define
name|PCIM_I2S_VOL
value|0x80
end_define

begin_comment
comment|/* I2S codec Volume and mute */
end_comment

begin_define
define|#
directive|define
name|PCIM_I2S_96KHZ
value|0x40
end_define

begin_comment
comment|/* I2S converter 96kHz sampling rate support */
end_comment

begin_define
define|#
directive|define
name|PCIM_I2S_RES
value|0x30
end_define

begin_comment
comment|/* Converter resolution */
end_comment

begin_define
define|#
directive|define
name|PCIM_I2S_16BIT
value|0x00
end_define

begin_comment
comment|/* 16bit */
end_comment

begin_define
define|#
directive|define
name|PCIM_I2S_18BIT
value|0x10
end_define

begin_comment
comment|/* 18bit */
end_comment

begin_define
define|#
directive|define
name|PCIM_I2S_20BIT
value|0x20
end_define

begin_comment
comment|/* 20bit */
end_comment

begin_define
define|#
directive|define
name|PCIM_I2S_24BIT
value|0x30
end_define

begin_comment
comment|/* 24bit */
end_comment

begin_define
define|#
directive|define
name|PCIM_I2S_ID
value|0x0f
end_define

begin_comment
comment|/* Other I2S IDs */
end_comment

begin_define
define|#
directive|define
name|PCIR_SPDIF
value|0x63
end_define

begin_comment
comment|/* S/PDIF Configuration Register */
end_comment

begin_define
define|#
directive|define
name|PCIM_SPDIF_ID
value|0xfc
end_define

begin_comment
comment|/* S/PDIF chip ID */
end_comment

begin_define
define|#
directive|define
name|PCIM_SPDIF_IN
value|0x02
end_define

begin_comment
comment|/* S/PDIF Stereo In is present */
end_comment

begin_define
define|#
directive|define
name|PCIM_SPDIF_OUT
value|0x01
end_define

begin_comment
comment|/* S/PDIF Stereo Out is present */
end_comment

begin_define
define|#
directive|define
name|PCIR_POWER_STAT
value|0x84
end_define

begin_comment
comment|/* Power Management Control and Status */
end_comment

begin_comment
comment|/* Controller Registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CTL
value|0x00
end_define

begin_comment
comment|/* Control/Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CTL_RESET
value|0x80
end_define

begin_comment
comment|/* Entire Chip soft reset */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CTL_DMAINT
value|0x40
end_define

begin_comment
comment|/* DS DMA Channel-C interrupt */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CTL_DOSVOL
value|0x10
end_define

begin_comment
comment|/* set the DOS WT volume control */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CTL_EDGE
value|0x08
end_define

begin_comment
comment|/* SERR# edge (only one PCI clock width) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CTL_SBINT
value|0x02
end_define

begin_comment
comment|/* SERR# assertion for SB interrupt */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CTL_NATIVE
value|0x01
end_define

begin_comment
comment|/* Mode select: 0:SB mode 1:native mode */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK
value|0x01
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK_PMIDI
value|0x80
end_define

begin_comment
comment|/* Primary MIDI */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK_TIMER
value|0x40
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK_SMIDI
value|0x20
end_define

begin_comment
comment|/* Secondary MIDI */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK_PMT
value|0x10
end_define

begin_comment
comment|/* Professional Multi-track */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK_FM
value|0x08
end_define

begin_comment
comment|/* FM/MIDI trapping */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK_PDMA
value|0x04
end_define

begin_comment
comment|/* Playback DS DMA */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK_RDMA
value|0x02
end_define

begin_comment
comment|/* Consumer record DMA */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_IMASK_SB
value|0x01
end_define

begin_comment
comment|/* Consumer/SB mode playback */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT
value|0x02
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT_PMIDI
value|0x80
end_define

begin_comment
comment|/* Primary MIDI */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT_TIMER
value|0x40
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT_SMIDI
value|0x20
end_define

begin_comment
comment|/* Secondary MIDI */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT_PMT
value|0x10
end_define

begin_comment
comment|/* Professional Multi-track */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT_FM
value|0x08
end_define

begin_comment
comment|/* FM/MIDI trapping */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT_PDMA
value|0x04
end_define

begin_comment
comment|/* Playback DS DMA */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT_RDMA
value|0x02
end_define

begin_comment
comment|/* Consumer record DMA */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_ISTAT_SB
value|0x01
end_define

begin_comment
comment|/* Consumer/SB mode playback */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_INDEX
value|0x03
end_define

begin_comment
comment|/* Envy24 Index Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_DATA
value|0x04
end_define

begin_comment
comment|/* Envy24 Data Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI1
value|0x05
end_define

begin_comment
comment|/* NMI Status Register 1 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI1_PCI
value|0x80
end_define

begin_comment
comment|/* PCI I/O read/write cycle */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI1_SB
value|0x40
end_define

begin_comment
comment|/* SB 22C/24C write */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI1_SBDMA
value|0x10
end_define

begin_comment
comment|/* SB interrupt (SB DMA/SB F2 command) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI1_DSDMA
value|0x08
end_define

begin_comment
comment|/* DS channel C DMA interrupt */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI1_MIDI
value|0x04
end_define

begin_comment
comment|/* MIDI 330h or [PCI_10]h+Ch write */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI1_FM
value|0x01
end_define

begin_comment
comment|/* FM data register write */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMIDAT
value|0x06
end_define

begin_comment
comment|/* NMI Data Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMIIDX
value|0x07
end_define

begin_comment
comment|/* NMI Index Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97IDX
value|0x08
end_define

begin_comment
comment|/* Consumer AC'97 Index Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97CMD
value|0x09
end_define

begin_comment
comment|/* Consumer AC'97 Command/Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97CMD_COLD
value|0x80
end_define

begin_comment
comment|/* Cold reset */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97CMD_WARM
value|0x40
end_define

begin_comment
comment|/* Warm reset */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97CMD_WRCODEC
value|0x20
end_define

begin_comment
comment|/* Write to AC'97 codec registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97CMD_RDCODEC
value|0x10
end_define

begin_comment
comment|/* Read from AC'97 codec registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97CMD_READY
value|0x08
end_define

begin_comment
comment|/* AC'97 codec ready status bit */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97CMD_PVSR
value|0x02
end_define

begin_comment
comment|/* VSR for Playback */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97CMD_RVSR
value|0x01
end_define

begin_comment
comment|/* VSR for Record */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_AC97DAT
value|0x0a
end_define

begin_comment
comment|/* Consumer AC'97 Data Port Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_PMIDIDAT
value|0x0c
end_define

begin_comment
comment|/* Primary MIDI UART Data Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_PMIDICMD
value|0x0d
end_define

begin_comment
comment|/* Primary MIDI UART Command/Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2
value|0x0e
end_define

begin_comment
comment|/* NMI Status Register 2 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_FMBANK
value|0x30
end_define

begin_comment
comment|/* FM bank indicator */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_FM0
value|0x10
end_define

begin_comment
comment|/* FM bank 0 (388h/220h/228h) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_FM1
value|0x20
end_define

begin_comment
comment|/* FM bank 1 (38ah/222h) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PICIO
value|0x0f
end_define

begin_comment
comment|/* PIC I/O cycle */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PIC20W
value|0x01
end_define

begin_comment
comment|/* 20h write */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PICA0W
value|0x02
end_define

begin_comment
comment|/* a0h write */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PIC21W
value|0x05
end_define

begin_comment
comment|/* 21h write */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PICA1W
value|0x06
end_define

begin_comment
comment|/* a1h write */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PIC20R
value|0x09
end_define

begin_comment
comment|/* 20h read */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PICA0R
value|0x0a
end_define

begin_comment
comment|/* a0h read */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PIC21R
value|0x0d
end_define

begin_comment
comment|/* 21h read */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_NMI2_PICA1R
value|0x0e
end_define

begin_comment
comment|/* a1h read */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_JOY
value|0x0f
end_define

begin_comment
comment|/* Game port register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CDEV
value|0x10
end_define

begin_comment
comment|/* I2C Port Device Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CDEV_ADDR
value|0xfe
end_define

begin_comment
comment|/* I2C device address */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CDEV_ROM
value|0xa0
end_define

begin_comment
comment|/* reserved for the external I2C E2PROM */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CDEV_WR
value|0x01
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CDEV_RD
value|0x00
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CADDR
value|0x11
end_define

begin_comment
comment|/* I2C Port Byte Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CDATA
value|0x12
end_define

begin_comment
comment|/* I2C Port Read/Write Data Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CSTAT
value|0x13
end_define

begin_comment
comment|/* I2C Port Control and Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CSTAT_ROM
value|0x80
end_define

begin_comment
comment|/* external E2PROM exists */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_I2CSTAT_BSY
value|0x01
end_define

begin_comment
comment|/* I2C port read/write status busy */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CDMABASE
value|0x14
end_define

begin_comment
comment|/* Consumer Record DMA Current/Base Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_CDMACNT
value|0x18
end_define

begin_comment
comment|/* Consumer Record DMA Current/Base Count Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_SERR
value|0x1b
end_define

begin_comment
comment|/* PCI Configuration SERR# Shadow Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_SMIDIDAT
value|0x1c
end_define

begin_comment
comment|/* Secondary MIDI UART Data Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_SMIDICMD
value|0x1d
end_define

begin_comment
comment|/* Secondary MIDI UART Command/Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_TIMER
value|0x1e
end_define

begin_comment
comment|/* Timer Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_TIMER_EN
value|0x8000
end_define

begin_comment
comment|/* Timer count enable */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCS_TIMER_MASK
value|0x7fff
end_define

begin_comment
comment|/* Timer counter mask */
end_comment

begin_comment
comment|/* Controller Indexed Registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PTCHIGH
value|0x00
end_define

begin_comment
comment|/* Playback Terminal Count Register (High Byte) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PTCLOW
value|0x01
end_define

begin_comment
comment|/* Playback Terminal Count Register (Low Byte) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL
value|0x02
end_define

begin_comment
comment|/* Playback Control Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL_TURBO
value|0x80
end_define

begin_comment
comment|/* 4x up sampling in the host by software */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL_U8
value|0x10
end_define

begin_comment
comment|/* 8 bits unsigned */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL_S16
value|0x00
end_define

begin_comment
comment|/* 16 bits signed */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL_STEREO
value|0x08
end_define

begin_comment
comment|/* stereo */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL_MONO
value|0x00
end_define

begin_comment
comment|/* mono */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL_FLUSH
value|0x04
end_define

begin_comment
comment|/* FIFO flush (sticky bit. Requires toggling) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL_PAUSE
value|0x02
end_define

begin_comment
comment|/* Pause */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PCTL_ENABLE
value|0x01
end_define

begin_comment
comment|/* Playback enable */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PLVOL
value|0x03
end_define

begin_comment
comment|/* Playback Left Volume/Pan Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PRVOL
value|0x04
end_define

begin_comment
comment|/* Playback Right Volume/Pan Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_VOL_MASK
value|0x3f
end_define

begin_comment
comment|/* Volume value mask */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_SOFTVOL
value|0x05
end_define

begin_comment
comment|/* Soft Volume/Mute Control Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PSRLOW
value|0x06
end_define

begin_comment
comment|/* Playback Sampling Rate Register (Low Byte) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PSRMID
value|0x07
end_define

begin_comment
comment|/* Playback Sampling Rate Register (Middle Byte) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_PSRHIGH
value|0x08
end_define

begin_comment
comment|/* Playback Sampling Rate Register (High Byte) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RTCHIGH
value|0x10
end_define

begin_comment
comment|/* Record Terminal Count Register (High Byte) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RTCLOW
value|0x11
end_define

begin_comment
comment|/* Record Terminal Count Register (Low Byte) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RCTL
value|0x12
end_define

begin_comment
comment|/* Record Control Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RCTL_DRTN
value|0x80
end_define

begin_comment
comment|/* Digital return enable */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RCTL_U8
value|0x04
end_define

begin_comment
comment|/* 8 bits unsigned */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RCTL_S16
value|0x00
end_define

begin_comment
comment|/* 16 bits signed */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RCTL_STEREO
value|0x00
end_define

begin_comment
comment|/* stereo */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RCTL_MONO
value|0x02
end_define

begin_comment
comment|/* mono */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_RCTL_ENABLE
value|0x01
end_define

begin_comment
comment|/* Record enable */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_GPIODAT
value|0x20
end_define

begin_comment
comment|/* GPIO Data Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_GPIOMASK
value|0x21
end_define

begin_comment
comment|/* GPIO Write Mask Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_GPIOCTL
value|0x22
end_define

begin_comment
comment|/* GPIO Direction Control Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_GPIO_OUT
value|1
end_define

begin_comment
comment|/* output */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_GPIO_IN
value|0
end_define

begin_comment
comment|/* input */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_CPDWN
value|0x30
end_define

begin_comment
comment|/* Consumer Section Power Down Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_CPDWN_XTAL
value|0x80
end_define

begin_comment
comment|/* Crystal clock generation power down for XTAL_1 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_CPDWN_GAME
value|0x40
end_define

begin_comment
comment|/* Game port analog power down */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_CPDWN_I2C
value|0x10
end_define

begin_comment
comment|/* I2C port clock */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_CPDWN_MIDI
value|0x08
end_define

begin_comment
comment|/* MIDI clock */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_CPDWN_AC97
value|0x04
end_define

begin_comment
comment|/* AC'97 clock */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_CPDWN_DS
value|0x02
end_define

begin_comment
comment|/* DS Block clock */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_CPDWN_PCI
value|0x01
end_define

begin_comment
comment|/* PCI clock for SB, DMA controller */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_MTPDWN
value|0x31
end_define

begin_comment
comment|/* Multi-Track Section Power Down Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_MTPDWN_XTAL
value|0x80
end_define

begin_comment
comment|/* Crystal clock generation power down for XTAL_2 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_MTPDWN_SPDIF
value|0x04
end_define

begin_comment
comment|/* S/PDIF clock */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_MTPDWN_MIX
value|0x02
end_define

begin_comment
comment|/* Professional digital mixer clock */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CCI_MTPDWN_I2S
value|0x01
end_define

begin_comment
comment|/* Multi-track I2S serial interface clock */
end_comment

begin_comment
comment|/* DDMA Registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_ADDR0
value|0x00
end_define

begin_comment
comment|/* DMA Base and Current Address bit 0-7 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_ADDR8
value|0x01
end_define

begin_comment
comment|/* DMA Base and Current Address bit 8-15 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_ADDR16
value|0x02
end_define

begin_comment
comment|/* DMA Base and Current Address bit 16-23 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_ADDR24
value|0x03
end_define

begin_comment
comment|/* DMA Base and Current Address bit 24-31 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_CNT0
value|0x04
end_define

begin_comment
comment|/* DMA Base and Current Count 0-7 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_CNT8
value|0x05
end_define

begin_comment
comment|/* DMA Base and Current Count 8-15 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_CNT16
value|0x06
end_define

begin_comment
comment|/* (not supported) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_CMD
value|0x08
end_define

begin_comment
comment|/* Status and Command */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_MODE
value|0x0b
end_define

begin_comment
comment|/* Mode */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_RESET
value|0x0c
end_define

begin_comment
comment|/* Master reset */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DDMA_CHAN
value|0x0f
end_define

begin_comment
comment|/* Channel Mask */
end_comment

begin_comment
comment|/* Consumer Section DMA Channel Registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_INTMASK
value|0x00
end_define

begin_comment
comment|/* DirectSound DMA Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_INTSTAT
value|0x02
end_define

begin_comment
comment|/* DirectSound DMA Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHDAT
value|0x04
end_define

begin_comment
comment|/* Channel Data register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX
value|0x08
end_define

begin_comment
comment|/* Channel Index Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX_NUM
value|0xf0
end_define

begin_comment
comment|/* Channel number */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX_ADDR0
value|0x00
end_define

begin_comment
comment|/* Buffer_0 DMA base address */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX_CNT0
value|0x01
end_define

begin_comment
comment|/* Buffer_0 DMA base count */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX_ADDR1
value|0x02
end_define

begin_comment
comment|/* Buffer_1 DMA base address */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX_CNT1
value|0x03
end_define

begin_comment
comment|/* Buffer_1 DMA base count */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX_CTL
value|0x04
end_define

begin_comment
comment|/* Channel Control and Status register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX_RATE
value|0x05
end_define

begin_comment
comment|/* Channel Sampling Rate */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CHIDX_VOL
value|0x06
end_define

begin_comment
comment|/* Channel left and right volume/pan control */
end_comment

begin_comment
comment|/* Channel Control and Status Register at Index 4h */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CTL_BUF
value|0x80
end_define

begin_comment
comment|/* indicating that the current active buffer */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CTL_AUTO1
value|0x40
end_define

begin_comment
comment|/* Buffer_1 auto init. enable */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CTL_AUTO0
value|0x20
end_define

begin_comment
comment|/* Buffer_0 auto init. enable */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CTL_FLUSH
value|0x10
end_define

begin_comment
comment|/* Flush FIFO */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CTL_STEREO
value|0x08
end_define

begin_comment
comment|/* stereo(or mono) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CTL_U8
value|0x04
end_define

begin_comment
comment|/* 8-bit unsigned(or 16-bit signed) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CTL_PAUSE
value|0x02
end_define

begin_comment
comment|/* DMA request 1:pause */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_CTL_START
value|0x01
end_define

begin_comment
comment|/* DMA request 1: start, 0:stop */
end_comment

begin_comment
comment|/* Consumer mode Left/Right Volume Register at Index 06h */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS_VOL_RIGHT
value|0x3f00
end_define

begin_define
define|#
directive|define
name|ENVY24_CS_VOL_LEFT
value|0x003f
end_define

begin_comment
comment|/* Professional Multi-Track Control Registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_INT
value|0x00
end_define

begin_comment
comment|/* DMA Interrupt Mask and Status Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_INT_RMASK
value|0x80
end_define

begin_comment
comment|/* Multi-track record interrupt mask */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_INT_PMASK
value|0x40
end_define

begin_comment
comment|/* Multi-track playback interrupt mask */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_INT_RSTAT
value|0x02
end_define

begin_comment
comment|/* Multi-track record interrupt status */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_INT_PSTAT
value|0x01
end_define

begin_comment
comment|/* Multi-track playback interrupt status */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RATE
value|0x01
end_define

begin_comment
comment|/* Sampling Rate Select Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_SPDIF
value|0x10
end_define

begin_comment
comment|/* S/PDIF input clock as the master */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_48000
value|0x00
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_24000
value|0x01
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_12000
value|0x02
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_9600
value|0x03
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_32000
value|0x04
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_16000
value|0x05
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_8000
value|0x06
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_96000
value|0x07
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_64000
value|0x0f
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_44100
value|0x08
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_22050
value|0x09
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_11025
value|0x0a
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_88200
value|0x0b
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_RATE_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|ENVY24_MT_I2S
value|0x02
end_define

begin_comment
comment|/* I2S Data Format Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_I2S_MLR128
value|0x08
end_define

begin_comment
comment|/* MCLK/LRCLK ratio 128x(or 256x) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_I2S_SLR48
value|0x04
end_define

begin_comment
comment|/* SCLK/LRCLK ratio 48bpf(or 64bpf) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_I2S_FORM
value|0x00
end_define

begin_comment
comment|/* I2S data format */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97IDX
value|0x04
end_define

begin_comment
comment|/* Index Register for AC'97 Codecs */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97CMD
value|0x05
end_define

begin_comment
comment|/* Command and Status Register for AC'97 Codecs */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97CMD_CLD
value|0x80
end_define

begin_comment
comment|/* Cold reset */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97CMD_WRM
value|0x40
end_define

begin_comment
comment|/* Warm reset */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97CMD_WR
value|0x20
end_define

begin_comment
comment|/* write to AC'97 codec register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97CMD_RD
value|0x10
end_define

begin_comment
comment|/* read AC'97 CODEC register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97CMD_RDY
value|0x08
end_define

begin_comment
comment|/* AC'97 codec ready status bit */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97CMD_ID
value|0x03
end_define

begin_comment
comment|/* ID(0-3) for external AC 97 registers */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97DLO
value|0x06
end_define

begin_comment
comment|/* AC'97 codec register data low byte */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_AC97DHI
value|0x07
end_define

begin_comment
comment|/* AC'97 codec register data high byte */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PADDR
value|0x10
end_define

begin_comment
comment|/* Playback DMA Current/Base Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PCNT
value|0x14
end_define

begin_comment
comment|/* Playback DMA Current/Base Count Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PTERM
value|0x16
end_define

begin_comment
comment|/* Playback Current/Base Terminal Count Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PCTL
value|0x18
end_define

begin_comment
comment|/* Playback and Record Control Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PCTL_RSTART
value|0x04
end_define

begin_comment
comment|/* 1: Record start; 0: Record stop */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PCTL_PAUSE
value|0x02
end_define

begin_comment
comment|/* 1: Pause; 0: Resume */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PCTL_PSTART
value|0x01
end_define

begin_comment
comment|/* 1: Playback start; 0: Playback stop */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RADDR
value|0x20
end_define

begin_comment
comment|/* Record DMA Current/Base Address Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RCNT
value|0x24
end_define

begin_comment
comment|/* Record DMA Current/Base Count Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RTERM
value|0x26
end_define

begin_comment
comment|/* Record Current/Base Terminal Count Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RCTL
value|0x28
end_define

begin_comment
comment|/* Record Control Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RCTL_RSTART
value|0x01
end_define

begin_comment
comment|/* 1: Record start; 0: Record stop */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PSDOUT
value|0x30
end_define

begin_comment
comment|/* Routing Control Register for Data to PSDOUT[0:3] */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_SPDOUT
value|0x32
end_define

begin_comment
comment|/* Routing Control Register for SPDOUT */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_RECORD
value|0x34
end_define

begin_comment
comment|/* Captured (Recorded) data Routing Selection Register */
end_comment

begin_define
define|#
directive|define
name|BUS_SPACE_MAXADDR_ENVY24
value|0x0fffffff
end_define

begin_comment
comment|/* Address space beyond 256MB is not supported */
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
name|ENVY24_MT_VOLUME
value|0x38
end_define

begin_comment
comment|/* Left/Right Volume Control Data Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_VOLUME_L
value|0x007f
end_define

begin_comment
comment|/* Left Volume Mask */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_VOLUME_R
value|0x7f00
end_define

begin_comment
comment|/* Right Volume Mask */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_VOLIDX
value|0x3a
end_define

begin_comment
comment|/* Volume Control Stream Index Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_VOLRATE
value|0x3b
end_define

begin_comment
comment|/* Volume Control Rate Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_MONAC97
value|0x3c
end_define

begin_comment
comment|/* Digital Mixer Monitor Routing Control Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PEAKIDX
value|0x3e
end_define

begin_comment
comment|/* Peak Meter Index Register */
end_comment

begin_define
define|#
directive|define
name|ENVY24_MT_PEAKDAT
value|0x3f
end_define

begin_comment
comment|/* Peak Meter Data Register */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* ENVY24 mixer channel defines */
end_comment

begin_comment
comment|/*   ENVY24 mixer has original line matrix. So, general mixer command is not   able to use for this. If system has consumer AC'97 output, AC'97 line is   used as master mixer, and it is able to control. */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CHAN_NUM
value|11
end_define

begin_comment
comment|/* Play * 5 + Record * 5 + Mix * 1 */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CHAN_PLAY_DAC1
value|0
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_PLAY_DAC2
value|1
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_PLAY_DAC3
value|2
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_PLAY_DAC4
value|3
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_PLAY_SPDIF
value|4
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_REC_ADC1
value|5
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_REC_ADC2
value|6
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_REC_ADC3
value|7
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_REC_ADC4
value|8
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_REC_SPDIF
value|9
end_define

begin_define
define|#
directive|define
name|ENVY24_CHAN_REC_MIX
value|10
end_define

begin_define
define|#
directive|define
name|ENVY24_MIX_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|ENVY24_MIX_REC_MASK
value|0x3e0
end_define

begin_comment
comment|/* volume value constants */
end_comment

begin_define
define|#
directive|define
name|ENVY24_VOL_MAX
value|0
end_define

begin_comment
comment|/* 0db(negate) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_VOL_MIN
value|96
end_define

begin_comment
comment|/* -144db(negate) */
end_comment

begin_define
define|#
directive|define
name|ENVY24_VOL_MUTE
value|127
end_define

begin_comment
comment|/* mute */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* ENVY24 routing control defines */
end_comment

begin_comment
comment|/*   ENVY24 has input->output data routing matrix switch. But original ENVY24   matrix control is so complex. So, in this driver, matrix control is   defined 4 parameters.    1: output DAC channels (include S/PDIF output)   2: output data classes      a. direct output from DMA      b. MIXER output which mixed the DMA outputs and input channels         (NOTICE: this class is able to set only DAC-1 and S/PDIF output)      c. direct input from ADC      d. direct input from S/PDIF   3: input ADC channel selection(when 2:c. is selected)   4: left/right reverse    These parameters matrix is bit reduced from original ENVY24 matrix   pattern(ex. route different ADC input to one DAC). But almost case   this is enough to use. */
end_comment

begin_define
define|#
directive|define
name|ENVY24_ROUTE_DAC_1
value|0
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_DAC_2
value|1
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_DAC_3
value|2
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_DAC_4
value|3
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_DAC_SPDIF
value|4
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_CLASS_DMA
value|0
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_CLASS_MIX
value|1
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_CLASS_ADC
value|2
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_CLASS_SPDIF
value|3
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_ADC_1
value|0
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_ADC_2
value|1
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_ADC_3
value|2
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_ADC_4
value|3
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_REVERSE
value|1
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_LEFT
value|0
end_define

begin_define
define|#
directive|define
name|ENVY24_ROUTE_RIGHT
value|1
end_define

begin_comment
comment|/* -------------------------------------------------------------------- */
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
name|ENVY24_E2PROM_SUBVENDOR
value|0x00
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_SUBDEVICE
value|0x02
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_SIZE
value|0x04
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_VERSION
value|0x05
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_SCFG
value|0x06
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_ACL
value|0x07
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_I2S
value|0x08
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_SPDIF
value|0x09
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_GPIOMASK
value|0x0a
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_GPIOSTATE
value|0x0b
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_GPIODIR
value|0x0c
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_AC97MAIN
value|0x0d
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_AC97PCM
value|0x0f
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_AC97REC
value|0x11
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_AC97RECSRC
value|0x13
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_DACID
value|0x14
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_ADCID
value|0x18
end_define

begin_define
define|#
directive|define
name|ENVY24_E2PROM_EXTRA
value|0x1c
end_define

begin_comment
comment|/* GPIO connect map of M-Audio Delta series */
end_comment

begin_define
define|#
directive|define
name|ENVY24_GPIO_CS84X4_PRO
value|0x01
end_define

begin_define
define|#
directive|define
name|ENVY24_GPIO_CS8414_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|ENVY24_GPIO_CS84X4_CLK
value|0x04
end_define

begin_define
define|#
directive|define
name|ENVY24_GPIO_CS84X4_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|ENVY24_GPIO_AK4524_CDTI
value|0x10
end_define

begin_comment
comment|/* this value is duplicated to input select */
end_comment

begin_define
define|#
directive|define
name|ENVY24_GPIO_AK4524_CCLK
value|0x20
end_define

begin_define
define|#
directive|define
name|ENVY24_GPIO_AK4524_CS0
value|0x40
end_define

begin_define
define|#
directive|define
name|ENVY24_GPIO_AK4524_CS1
value|0x80
end_define

begin_comment
comment|/* M-Audio Delta series S/PDIF(CS84[01]4) control pin values */
end_comment

begin_define
define|#
directive|define
name|ENVY24_CS8404_PRO_RATE
value|0x18
end_define

begin_define
define|#
directive|define
name|ENVY24_CS8404_PRO_RATE32
value|0x00
end_define

begin_define
define|#
directive|define
name|ENVY24_CS8404_PRO_RATE441
value|0x10
end_define

begin_define
define|#
directive|define
name|ENVY24_CS8404_PRO_RATE48
value|0x08
end_define

begin_comment
comment|/* M-Audio Delta series parameter */
end_comment

begin_define
define|#
directive|define
name|ENVY24_DELTA_AK4524_CIF
value|0
end_define

begin_define
define|#
directive|define
name|I2C_DELAY
value|1000
end_define

begin_comment
comment|/* PCA9554 registers */
end_comment

begin_define
define|#
directive|define
name|PCA9554_I2CDEV
value|0x40
end_define

begin_comment
comment|/* I2C device address */
end_comment

begin_define
define|#
directive|define
name|PCA9554_IN
value|0x00
end_define

begin_comment
comment|/* input port */
end_comment

begin_define
define|#
directive|define
name|PCA9554_OUT
value|0x01
end_define

begin_comment
comment|/* output port */
end_comment

begin_define
define|#
directive|define
name|PCA9554_INVERT
value|0x02
end_define

begin_comment
comment|/* polarity invert */
end_comment

begin_define
define|#
directive|define
name|PCA9554_DIR
value|0x03
end_define

begin_comment
comment|/* port directions */
end_comment

begin_comment
comment|/* PCF8574 registers */
end_comment

begin_define
define|#
directive|define
name|PCF8574_I2CDEV_DAC
value|0x48
end_define

begin_define
define|#
directive|define
name|PCF8574_SENSE_MASK
value|0x40
end_define

begin_comment
comment|/* end of file */
end_comment

end_unit

