begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997,1998 Luigi Rizzo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SB_H
end_ifndef

begin_define
define|#
directive|define
name|SB_H
end_define

begin_struct_decl
struct_decl|struct
name|sbc_softc
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|sbc_lock
parameter_list|(
name|struct
name|sbc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbc_lockassert
parameter_list|(
name|struct
name|sbc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbc_unlock
parameter_list|(
name|struct
name|sbc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * sound blaster registers  */
end_comment

begin_define
define|#
directive|define
name|SBDSP_RST
value|0x6
end_define

begin_define
define|#
directive|define
name|DSP_READ
value|0xA
end_define

begin_define
define|#
directive|define
name|DSP_WRITE
value|0xC
end_define

begin_define
define|#
directive|define
name|SBDSP_CMD
value|0xC
end_define

begin_define
define|#
directive|define
name|SBDSP_STATUS
value|0xC
end_define

begin_define
define|#
directive|define
name|DSP_DATA_AVAIL
value|0xE
end_define

begin_define
define|#
directive|define
name|DSP_DATA_AVL16
value|0xF
end_define

begin_define
define|#
directive|define
name|SB_MIX_ADDR
value|0x4
end_define

begin_define
define|#
directive|define
name|SB_MIX_DATA
value|0x5
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|OPL3_LEFT
value|(io_base + 0x0)
end_define

begin_define
define|#
directive|define
name|OPL3_RIGHT
value|(io_base + 0x2)
end_define

begin_define
define|#
directive|define
name|OPL3_BOTH
value|(io_base + 0x8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DSP Commands. There are many, and in many cases they are used explicitly  */
end_comment

begin_comment
comment|/* these are not used except for programmed I/O (not in this driver) */
end_comment

begin_define
define|#
directive|define
name|DSP_DAC8
value|0x10
end_define

begin_comment
comment|/* direct DAC output */
end_comment

begin_define
define|#
directive|define
name|DSP_ADC8
value|0x20
end_define

begin_comment
comment|/* direct ADC input */
end_comment

begin_comment
comment|/* these should be used in the SB 1.0 */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_DAC8
value|0x14
end_define

begin_comment
comment|/* single cycle 8-bit dma out */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_ADC8
value|0x24
end_define

begin_comment
comment|/* single cycle 8-bit dma in */
end_comment

begin_comment
comment|/* these should be used in the SB 2.0 and 2.01 */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_DAC8_AUTO
value|0x1c
end_define

begin_comment
comment|/* auto 8-bit dma out */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_ADC8_AUTO
value|0x2c
end_define

begin_comment
comment|/* auto 8-bit dma out */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_HSSIZE
value|0x48
end_define

begin_comment
comment|/* high speed dma count */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_HSDAC_AUTO
value|0x90
end_define

begin_comment
comment|/* high speed dac, auto */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_HSADC_AUTO
value|0x98
end_define

begin_comment
comment|/* high speed adc, auto */
end_comment

begin_comment
comment|/* SBPro commands. Some cards (JAZZ, SMW) also support 16 bits */
end_comment

begin_comment
comment|/* prepare for dma input */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_DMAMODE
parameter_list|(
name|stereo
parameter_list|,
name|bit16
parameter_list|)
value|(0xA0 | (stereo ? 8:0) | (bit16 ? 4:0))
end_define

begin_define
define|#
directive|define
name|DSP_CMD_DAC2
value|0x16
end_define

begin_comment
comment|/* 2-bit adpcm dma out (cont) */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_DAC2S
value|0x17
end_define

begin_comment
comment|/* 2-bit adpcm dma out (start) */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_DAC2S_AUTO
value|0x1f
end_define

begin_comment
comment|/* auto 2-bit adpcm dma out (start) */
end_comment

begin_comment
comment|/* SB16 commands */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_O16
value|0xb0
end_define

begin_define
define|#
directive|define
name|DSP_CMD_I16
value|0xb8
end_define

begin_define
define|#
directive|define
name|DSP_CMD_O8
value|0xc0
end_define

begin_define
define|#
directive|define
name|DSP_CMD_I8
value|0xc8
end_define

begin_define
define|#
directive|define
name|DSP_MODE_U8MONO
value|0x00
end_define

begin_define
define|#
directive|define
name|DSP_MODE_U8STEREO
value|0x20
end_define

begin_define
define|#
directive|define
name|DSP_MODE_S16MONO
value|0x10
end_define

begin_define
define|#
directive|define
name|DSP_MODE_S16STEREO
value|0x30
end_define

begin_define
define|#
directive|define
name|DSP_CMD_SPKON
value|0xD1
end_define

begin_define
define|#
directive|define
name|DSP_CMD_SPKOFF
value|0xD3
end_define

begin_define
define|#
directive|define
name|DSP_CMD_SPKR
parameter_list|(
name|on
parameter_list|)
value|(0xD1 | (on ? 0:2))
end_define

begin_define
define|#
directive|define
name|DSP_CMD_DMAPAUSE_8
value|0xD0
end_define

begin_define
define|#
directive|define
name|DSP_CMD_DMAPAUSE_16
value|0xD5
end_define

begin_define
define|#
directive|define
name|DSP_CMD_DMAEXIT_8
value|0xDA
end_define

begin_define
define|#
directive|define
name|DSP_CMD_DMAEXIT_16
value|0xD9
end_define

begin_define
define|#
directive|define
name|DSP_CMD_TCONST
value|0x40
end_define

begin_comment
comment|/* set time constant */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_HSDAC
value|0x91
end_define

begin_comment
comment|/* high speed dac */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_HSADC
value|0x99
end_define

begin_comment
comment|/* high speed adc */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_GETVER
value|0xE1
end_define

begin_define
define|#
directive|define
name|DSP_CMD_GETID
value|0xE7
end_define

begin_comment
comment|/* return id bytes */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_OUT16
value|0x41
end_define

begin_comment
comment|/* send parms for dma out on sb16 */
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_IN16
value|0x42
end_define

begin_comment
comment|/* send parms for dma in on sb16 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*** unknown ***/
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_FA
value|0xFA
end_define

begin_comment
comment|/* get version from prosonic*/
end_comment

begin_define
define|#
directive|define
name|DSP_CMD_FB
value|0xFB
end_define

begin_comment
comment|/* set irq/dma for prosonic*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * in fact, for the SB16, dma commands are as follows:  *  *  cmd, mode, len_low, len_high.  *  * cmd is a combination of DSP_DMA16 or DSP_DMA8 and  */
end_comment

begin_define
define|#
directive|define
name|DSP_DMA16
value|0xb0
end_define

begin_define
define|#
directive|define
name|DSP_DMA8
value|0xc0
end_define

begin_define
define|#
directive|define
name|DSP_F16_DAC
value|0x00
end_define

begin_define
define|#
directive|define
name|DSP_F16_ADC
value|0x08
end_define

begin_define
define|#
directive|define
name|DSP_F16_AUTO
value|0x04
end_define

begin_define
define|#
directive|define
name|DSP_F16_FIFO_ON
value|0x02
end_define

begin_comment
comment|/*  * mode is a combination of the following:  */
end_comment

begin_define
define|#
directive|define
name|DSP_F16_STEREO
value|0x20
end_define

begin_define
define|#
directive|define
name|DSP_F16_SIGNED
value|0x10
end_define

begin_define
define|#
directive|define
name|IMODE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IMODE_OUTPUT
value|PCM_ENABLE_OUTPUT
end_define

begin_define
define|#
directive|define
name|IMODE_INPUT
value|PCM_ENABLE_INPUT
end_define

begin_define
define|#
directive|define
name|IMODE_INIT
value|3
end_define

begin_define
define|#
directive|define
name|IMODE_MIDI
value|4
end_define

begin_define
define|#
directive|define
name|NORMAL_MIDI
value|0
end_define

begin_define
define|#
directive|define
name|UART_MIDI
value|1
end_define

begin_comment
comment|/*  * values used for bd_flags in SoundBlaster driver  */
end_comment

begin_define
define|#
directive|define
name|BD_F_HISPEED
value|0x0001
end_define

begin_comment
comment|/* doing high speed ... */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|BD_F_JAZZ16
value|0x0002
end_define

begin_comment
comment|/* jazz16 detected */
end_comment

begin_define
define|#
directive|define
name|BD_F_JAZZ16_2
value|0x0004
end_define

begin_comment
comment|/* jazz16 type 2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BD_F_DUP_MIDI
value|0x0008
end_define

begin_comment
comment|/* duplex midi */
end_comment

begin_define
define|#
directive|define
name|BD_F_MIX_MASK
value|0x0070
end_define

begin_comment
comment|/* up to 8 mixers (I know of 3) */
end_comment

begin_define
define|#
directive|define
name|BD_F_MIX_CT1335
value|0x0010
end_define

begin_comment
comment|/* CT1335		*/
end_comment

begin_define
define|#
directive|define
name|BD_F_MIX_CT1345
value|0x0020
end_define

begin_comment
comment|/* CT1345		*/
end_comment

begin_define
define|#
directive|define
name|BD_F_MIX_CT1745
value|0x0030
end_define

begin_comment
comment|/* CT1745		*/
end_comment

begin_define
define|#
directive|define
name|BD_F_SB16
value|0x0100
end_define

begin_comment
comment|/* this is a SB16 */
end_comment

begin_define
define|#
directive|define
name|BD_F_SB16X
value|0x0200
end_define

begin_comment
comment|/* this is a vibra16X or clone */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|BD_F_MIDIBUSY
value|0x0400
end_define

begin_comment
comment|/* midi busy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BD_F_ESS
value|0x0800
end_define

begin_comment
comment|/* this is an ESS chip */
end_comment

begin_define
define|#
directive|define
name|BD_F_DMARUN
value|0x2000
end_define

begin_define
define|#
directive|define
name|BD_F_DMARUN2
value|0x4000
end_define

begin_comment
comment|/*  * Mixer registers of SB Pro  */
end_comment

begin_define
define|#
directive|define
name|VOC_VOL
value|0x04
end_define

begin_define
define|#
directive|define
name|MIC_VOL
value|0x0A
end_define

begin_define
define|#
directive|define
name|MIC_MIX
value|0x0A
end_define

begin_define
define|#
directive|define
name|RECORD_SRC
value|0x0C
end_define

begin_define
define|#
directive|define
name|IN_FILTER
value|0x0C
end_define

begin_define
define|#
directive|define
name|OUT_FILTER
value|0x0E
end_define

begin_define
define|#
directive|define
name|MASTER_VOL
value|0x22
end_define

begin_define
define|#
directive|define
name|FM_VOL
value|0x26
end_define

begin_define
define|#
directive|define
name|CD_VOL
value|0x28
end_define

begin_define
define|#
directive|define
name|LINE_VOL
value|0x2E
end_define

begin_define
define|#
directive|define
name|IRQ_NR
value|0x80
end_define

begin_define
define|#
directive|define
name|DMA_NR
value|0x81
end_define

begin_define
define|#
directive|define
name|IRQ_STAT
value|0x82
end_define

begin_comment
comment|/*  * Additional registers on the SG NX Pro  */
end_comment

begin_define
define|#
directive|define
name|COVOX_VOL
value|0x42
end_define

begin_define
define|#
directive|define
name|TREBLE_LVL
value|0x44
end_define

begin_define
define|#
directive|define
name|BASS_LVL
value|0x46
end_define

begin_define
define|#
directive|define
name|FREQ_HI
value|(1<< 3)
end_define

begin_comment
comment|/* Use High-frequency ANFI filters */
end_comment

begin_define
define|#
directive|define
name|FREQ_LOW
value|0
end_define

begin_comment
comment|/* Use Low-frequency ANFI filters */
end_comment

begin_define
define|#
directive|define
name|FILT_ON
value|0
end_define

begin_comment
comment|/* Yes, 0 to turn it on, 1 for off */
end_comment

begin_define
define|#
directive|define
name|FILT_OFF
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MONO_DAC
value|0x00
end_define

begin_define
define|#
directive|define
name|STEREO_DAC
value|0x02
end_define

begin_comment
comment|/*  * Mixer registers of SB16  */
end_comment

begin_define
define|#
directive|define
name|SB16_IMASK_L
value|0x3d
end_define

begin_define
define|#
directive|define
name|SB16_IMASK_R
value|0x3e
end_define

begin_define
define|#
directive|define
name|SB16_OMASK
value|0x3c
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

