begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * file: sbcard.h  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_sbdev_info
block|{  }
name|sbdev_info
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|sbc_major
decl_stmt|,
name|sbc_minor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * sound blaster registers  */
end_comment

begin_define
define|#
directive|define
name|DSP_RESET
value|(io_base + 0x6)
end_define

begin_define
define|#
directive|define
name|DSP_READ
value|(io_base + 0xA)
end_define

begin_define
define|#
directive|define
name|DSP_WRITE
value|(io_base + 0xC)
end_define

begin_define
define|#
directive|define
name|DSP_COMMAND
value|(io_base + 0xC)
end_define

begin_define
define|#
directive|define
name|DSP_STATUS
value|(io_base + 0xC)
end_define

begin_define
define|#
directive|define
name|DSP_DATA_AVAIL
value|(io_base + 0xE)
end_define

begin_define
define|#
directive|define
name|DSP_DATA_AVL16
value|(io_base + 0xF)
end_define

begin_define
define|#
directive|define
name|MIXER_ADDR
value|(io_base + 0x4)
end_define

begin_define
define|#
directive|define
name|MIXER_DATA
value|(io_base + 0x5)
end_define

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
comment|/*  * in fact, for the SB16, dma commands are as follows:  *  *  cmd, mode, len_low, len_high.  *   * cmd is a combination of DSP_DMA16 or DSP_DMA8 and  */
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
name|BD_F_NOREC
value|0x0200
end_define

begin_comment
comment|/* recording not supported on this board */
end_comment

begin_define
define|#
directive|define
name|BD_F_MIDIBUSY
value|0x0400
end_define

begin_comment
comment|/* midi busy */
end_comment

begin_define
define|#
directive|define
name|BD_F_ESS
value|0x0800
end_define

begin_comment
comment|/* this is an ESS chip */
end_comment

begin_comment
comment|/*  * sound/sb_mixer.h  *   * Definitions for the SB Pro and SB16 mixers  *   * Copyright by Hannu Savolainen 1993  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2.  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * Modified: Hunyue Yau	Jan 6 1994 Added defines for the Sound Galaxy NX Pro  * mixer.  *   */
end_comment

begin_define
define|#
directive|define
name|SBPRO_RECORDING_DEVICES
define|\
value|(SOUND_MASK_LINE | SOUND_MASK_MIC | SOUND_MASK_CD)
end_define

begin_comment
comment|/* Same as SB Pro, unless I find otherwise */
end_comment

begin_define
define|#
directive|define
name|SGNXPRO_RECORDING_DEVICES
value|SBPRO_RECORDING_DEVICES
end_define

begin_define
define|#
directive|define
name|SBPRO_MIXER_DEVICES
define|\
value|(SOUND_MASK_SYNTH | SOUND_MASK_PCM | SOUND_MASK_LINE | SOUND_MASK_MIC | \      SOUND_MASK_CD | SOUND_MASK_VOLUME)
end_define

begin_comment
comment|/*  * SG NX Pro has treble and bass settings on the mixer. The 'speaker' channel  * is the COVOX/DisneySoundSource emulation volume control on the mixer. It  * does NOT control speaker volume. Should have own mask eventually?  */
end_comment

begin_define
define|#
directive|define
name|SGNXPRO_MIXER_DEVICES
define|\
value|(SBPRO_MIXER_DEVICES | SOUND_MASK_BASS | \      SOUND_MASK_TREBLE | SOUND_MASK_SPEAKER )
end_define

begin_define
define|#
directive|define
name|SB16_RECORDING_DEVICES
define|\
value|(SOUND_MASK_SYNTH | SOUND_MASK_LINE | SOUND_MASK_MIC | SOUND_MASK_CD)
end_define

begin_define
define|#
directive|define
name|SB16_MIXER_DEVICES
define|\
value|(SOUND_MASK_SYNTH | SOUND_MASK_PCM | SOUND_MASK_SPEAKER | \      SOUND_MASK_LINE | SOUND_MASK_MIC | SOUND_MASK_CD | \      SOUND_MASK_IGAIN | SOUND_MASK_OGAIN | \      SOUND_MASK_VOLUME | SOUND_MASK_BASS | SOUND_MASK_TREBLE)
end_define

begin_comment
comment|/*  * Mixer registers  *   * NOTE!	RECORD_SRC == IN_FILTER  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|__SB_MIXER_C__
end_ifndef

begin_decl_stmt
name|mixer_tab
name|sbpro_mix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mixer_tab
name|sb16_mix
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__SGNXPRO__
end_ifdef

begin_decl_stmt
name|mixer_tab
name|sgnxpro_mix
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|u_char
name|sb16_recmasks_L
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_char
name|sb16_recmasks_R
index|[
name|SOUND_MIXER_NRDEVICES
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __SB_MIXER_C__ defined */
end_comment

begin_decl_stmt
name|mixer_tab
name|sbpro_mix
init|=
block|{
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_VOLUME
argument_list|,
literal|0x22
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x22
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_BASS
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_TREBLE
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_SYNTH
argument_list|,
literal|0x26
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x26
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_PCM
argument_list|,
literal|0x04
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x04
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_SPEAKER
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_LINE
argument_list|,
literal|0x2e
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x2e
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_MIC
argument_list|,
literal|0x0a
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_CD
argument_list|,
literal|0x28
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x28
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_IMIX
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_ALTPCM
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
argument|SOUND_MIXER_RECLEV
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__SGNXPRO__
end_ifdef

begin_decl_stmt
name|mixer_tab
name|sgnxpro_mix
init|=
block|{
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_VOLUME
argument_list|,
literal|0x22
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x22
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_BASS
argument_list|,
literal|0x46
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_TREBLE
argument_list|,
literal|0x44
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_SYNTH
argument_list|,
literal|0x26
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x26
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_PCM
argument_list|,
literal|0x04
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x04
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_SPEAKER
argument_list|,
literal|0x42
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_LINE
argument_list|,
literal|0x2e
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x2e
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_MIC
argument_list|,
literal|0x0a
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_CD
argument_list|,
literal|0x28
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x28
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_IMIX
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_ALTPCM
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_RECLEV
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_IGAIN
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
argument|SOUND_MIXER_OGAIN
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|mixer_tab
name|sb16_mix
init|=
block|{
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_VOLUME
argument_list|,
literal|0x30
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|,
literal|0x31
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_BASS
argument_list|,
literal|0x46
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
literal|0x47
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_TREBLE
argument_list|,
literal|0x44
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
literal|0x45
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_SYNTH
argument_list|,
literal|0x34
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|,
literal|0x35
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_PCM
argument_list|,
literal|0x32
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|,
literal|0x33
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_SPEAKER
argument_list|,
literal|0x3b
argument_list|,
literal|6
argument_list|,
literal|2
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_LINE
argument_list|,
literal|0x38
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|,
literal|0x39
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_MIC
argument_list|,
literal|0x3a
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_CD
argument_list|,
literal|0x36
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|,
literal|0x37
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_IMIX
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_ALTPCM
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0x00
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_RECLEV
argument_list|,
literal|0x3f
argument_list|,
literal|6
argument_list|,
literal|2
argument_list|,
literal|0x40
argument_list|,
literal|6
argument_list|,
literal|2
argument_list|)
block|,
comment|/* Obsol,Use IGAIN*/
name|PMIX_ENT
argument_list|(
name|SOUND_MIXER_IGAIN
argument_list|,
literal|0x3f
argument_list|,
literal|6
argument_list|,
literal|2
argument_list|,
literal|0x40
argument_list|,
literal|6
argument_list|,
literal|2
argument_list|)
block|,
name|PMIX_ENT
argument_list|(
argument|SOUND_MIXER_OGAIN
argument_list|,
literal|0x41
argument_list|,
literal|6
argument_list|,
literal|2
argument_list|,
literal|0x42
argument_list|,
literal|6
argument_list|,
literal|2
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SM_GAMES
end_ifdef

begin_comment
comment|/* Master volume is lower and PCM& FM 				 * volumes higher than with SB Pro. This 				 * improves the sound quality */
end_comment

begin_decl_stmt
specifier|static
name|u_short
name|levels
index|[
name|SOUND_MIXER_NRDEVICES
index|]
init|=
block|{
literal|0x2020
block|,
comment|/* Master Volume */
literal|0x4b4b
block|,
comment|/* Bass */
literal|0x4b4b
block|,
comment|/* Treble */
literal|0x6464
block|,
comment|/* FM */
literal|0x6464
block|,
comment|/* PCM */
literal|0x4b4b
block|,
comment|/* PC Speaker */
literal|0x4b4b
block|,
comment|/* Ext Line */
literal|0x0000
block|,
comment|/* Mic */
literal|0x4b4b
block|,
comment|/* CD */
literal|0x4b4b
block|,
comment|/* Recording monitor */
literal|0x4b4b
block|,
comment|/* SB PCM */
literal|0x4b4b
block|,
comment|/* Recording level */
literal|0x4b4b
block|,
comment|/* Input gain */
literal|0x4b4b
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output gain */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If the user selected just plain SB Pro */
end_comment

begin_decl_stmt
specifier|static
name|u_short
name|levels
index|[
name|SOUND_MIXER_NRDEVICES
index|]
init|=
block|{
literal|0x5a5a
block|,
comment|/* Master Volume */
literal|0x4b4b
block|,
comment|/* Bass */
literal|0x4b4b
block|,
comment|/* Treble */
literal|0x4b4b
block|,
comment|/* FM */
literal|0x4b4b
block|,
comment|/* PCM */
literal|0x4b4b
block|,
comment|/* PC Speaker */
literal|0x4b4b
block|,
comment|/* Ext Line */
literal|0x1010
block|,
comment|/* Mic */
literal|0x4b4b
block|,
comment|/* CD */
literal|0x4b4b
block|,
comment|/* Recording monitor */
literal|0x4b4b
block|,
comment|/* SB PCM */
literal|0x4b4b
block|,
comment|/* Recording level */
literal|0x4b4b
block|,
comment|/* Input gain */
literal|0x4b4b
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output gain */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_GAMES */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|sb16_recmasks_L
index|[
name|SOUND_MIXER_NRDEVICES
index|]
init|=
block|{
literal|0x00
block|,
comment|/* SOUND_MIXER_VOLUME	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_BASS	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_TREBLE	 */
literal|0x40
block|,
comment|/* SOUND_MIXER_SYNTH	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_PCM	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_SPEAKER	 */
literal|0x10
block|,
comment|/* SOUND_MIXER_LINE	 */
literal|0x01
block|,
comment|/* SOUND_MIXER_MIC	 */
literal|0x04
block|,
comment|/* SOUND_MIXER_CD	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_IMIX	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_ALTPCM	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_RECLEV	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_IGAIN	 */
literal|0x00
comment|/* SOUND_MIXER_OGAIN	 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_char
name|sb16_recmasks_R
index|[
name|SOUND_MIXER_NRDEVICES
index|]
init|=
block|{
literal|0x00
block|,
comment|/* SOUND_MIXER_VOLUME	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_BASS	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_TREBLE	 */
literal|0x20
block|,
comment|/* SOUND_MIXER_SYNTH	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_PCM	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_SPEAKER	 */
literal|0x08
block|,
comment|/* SOUND_MIXER_LINE	 */
literal|0x01
block|,
comment|/* SOUND_MIXER_MIC	 */
literal|0x02
block|,
comment|/* SOUND_MIXER_CD	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_IMIX	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_ALTPCM	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_RECLEV	 */
literal|0x00
block|,
comment|/* SOUND_MIXER_IGAIN	 */
literal|0x00
comment|/* SOUND_MIXER_OGAIN	 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Recording sources (SB Pro)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SB_MIXER_C__ */
end_comment

begin_define
define|#
directive|define
name|SRC_MIC
value|1
end_define

begin_comment
comment|/* Select Microphone recording source */
end_comment

begin_define
define|#
directive|define
name|SRC_CD
value|3
end_define

begin_comment
comment|/* Select CD recording source */
end_comment

begin_define
define|#
directive|define
name|SRC_LINE
value|7
end_define

begin_comment
comment|/* Use Line-in for recording source */
end_comment

end_unit

