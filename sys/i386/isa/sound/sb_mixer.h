begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/sb_mixer.h  *   * Definitions for the SB Pro and SB16 mixers  *   * Copyright by Hannu Savolainen 1993  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2.  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * Modified: Hunyue Yau	Jan 6 1994 Added defines for the Sound Galaxy NX Pro  * mixer.  *   */
end_comment

begin_define
define|#
directive|define
name|SBPRO_RECORDING_DEVICES
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
value|(SOUND_MASK_SYNTH | SOUND_MASK_PCM | SOUND_MASK_LINE | SOUND_MASK_MIC | \ 					 SOUND_MASK_CD | SOUND_MASK_VOLUME)
end_define

begin_comment
comment|/*  * SG NX Pro has treble and bass settings on the mixer. The 'speaker' channel  * is the COVOX/DisneySoundSource emulation volume control on the mixer. It  * does NOT control speaker volume. Should have own mask eventually?  */
end_comment

begin_define
define|#
directive|define
name|SGNXPRO_MIXER_DEVICES
value|(SBPRO_MIXER_DEVICES|SOUND_MASK_BASS| \ 				 SOUND_MASK_TREBLE|SOUND_MASK_SPEAKER )
end_define

begin_define
define|#
directive|define
name|SB16_RECORDING_DEVICES
value|(SOUND_MASK_SYNTH | SOUND_MASK_LINE | SOUND_MASK_MIC | \ 					 SOUND_MASK_CD)
end_define

begin_define
define|#
directive|define
name|SB16_MIXER_DEVICES
value|(SOUND_MASK_SYNTH | SOUND_MASK_PCM | SOUND_MASK_SPEAKER | SOUND_MASK_LINE | SOUND_MASK_MIC | \ 					 SOUND_MASK_CD | \ 					 SOUND_MASK_IGAIN | SOUND_MASK_OGAIN | \ 					 SOUND_MASK_VOLUME | SOUND_MASK_BASS | SOUND_MASK_TREBLE)
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

begin_define
define|#
directive|define
name|OPSW
value|0x3c
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
name|LEFT_CHN
value|0
end_define

begin_define
define|#
directive|define
name|RIGHT_CHN
value|1
end_define

begin_struct
struct|struct
name|mixer_def
block|{
name|unsigned
name|int
name|regno
range|:
literal|8
decl_stmt|;
name|unsigned
name|int
name|bitoffs
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|nbits
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mixer_def
name|mixer_tab
index|[
literal|32
index|]
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mixer_def
name|mixer_ent
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MIX_ENT
parameter_list|(
name|name
parameter_list|,
name|reg_l
parameter_list|,
name|bit_l
parameter_list|,
name|len_l
parameter_list|,
name|reg_r
parameter_list|,
name|bit_r
parameter_list|,
name|len_r
parameter_list|)
define|\
value|{{reg_l, bit_l, len_l}, {reg_r, bit_r, len_r}}
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__SB_MIXER_C__
end_ifdef

begin_decl_stmt
name|mixer_tab
name|sbpro_mix
init|=
block|{
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_VOLUME
argument_list|,
literal|0x30
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|,
literal|0x31
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_BASS
argument_list|,
literal|0x46
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x47
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_TREBLE
argument_list|,
literal|0x44
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|,
literal|0x45
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_SYNTH
argument_list|,
literal|0x34
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|,
literal|0x35
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_PCM
argument_list|,
literal|0x32
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|,
literal|0x33
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_SPEAKER
argument_list|,
literal|0x3b
argument_list|,
literal|7
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
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_LINE
argument_list|,
literal|0x38
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|,
literal|0x39
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_MIC
argument_list|,
literal|0x3a
argument_list|,
literal|7
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
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_CD
argument_list|,
literal|0x36
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|,
literal|0x37
argument_list|,
literal|7
argument_list|,
literal|5
argument_list|)
block|,
name|MIX_ENT
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
name|MIX_ENT
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
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_RECLEV
argument_list|,
literal|0x3f
argument_list|,
literal|7
argument_list|,
literal|2
argument_list|,
literal|0x40
argument_list|,
literal|7
argument_list|,
literal|2
argument_list|)
block|,
comment|/* Obsolete. Use IGAIN */
name|MIX_ENT
argument_list|(
name|SOUND_MIXER_IGAIN
argument_list|,
literal|0x3f
argument_list|,
literal|7
argument_list|,
literal|2
argument_list|,
literal|0x40
argument_list|,
literal|7
argument_list|,
literal|2
argument_list|)
block|,
name|MIX_ENT
argument_list|(
argument|SOUND_MIXER_OGAIN
argument_list|,
literal|0x41
argument_list|,
literal|7
argument_list|,
literal|2
argument_list|,
literal|0x42
argument_list|,
literal|7
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
name|unsigned
name|short
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
name|unsigned
name|short
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
name|unsigned
name|char
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
name|unsigned
name|char
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

