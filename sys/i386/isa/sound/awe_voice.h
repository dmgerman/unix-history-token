begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/awe_voice.h  *  * Voice information definitions for the low level driver for the   * AWE32/Sound Blaster 32 wave table synth.  *   version 0.2.0a; Oct. 30, 1996  *  * (C) 1996 Takashi Iwai  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2.  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AWE_VOICE_H
end_ifndef

begin_define
define|#
directive|define
name|AWE_VOICE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SAMPLE_TYPE_AWE32
end_ifndef

begin_define
define|#
directive|define
name|SAMPLE_TYPE_AWE32
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATCHKEY
end_ifndef

begin_define
define|#
directive|define
name|_PATCHKEY
parameter_list|(
name|id
parameter_list|)
value|((id<<8)|0xfd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*----------------------------------------------------------------  * patch information record  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* patch interface header: 16 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|awe_patch_info
block|{
name|short
name|key
decl_stmt|;
comment|/* use AWE_PATCH here */
define|#
directive|define
name|AWE_PATCH
value|_PATCHKEY(0x07)
name|short
name|device_no
decl_stmt|;
comment|/* synthesizer number */
name|unsigned
name|short
name|sf_id
decl_stmt|;
comment|/* file id (should be zero) */
name|short
name|sf_version
decl_stmt|;
comment|/* patch version (not referred) */
name|long
name|len
decl_stmt|;
comment|/* data length (without this header) */
name|short
name|type
decl_stmt|;
comment|/* following data type */
define|#
directive|define
name|AWE_LOAD_INFO
value|0
define|#
directive|define
name|AWE_LOAD_DATA
value|1
name|short
name|reserved
decl_stmt|;
comment|/* word alignment data */
name|char
name|data
index|[
literal|0
index|]
decl_stmt|;
comment|/* patch data follows here */
block|}
name|awe_patch_info
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------------  * raw voice information record  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* wave table envelope& effect parameters to control EMU8000 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_awe_voice_parm
block|{
name|unsigned
name|short
name|moddelay
decl_stmt|;
comment|/* modulation delay (0x8000) */
name|unsigned
name|short
name|modatkhld
decl_stmt|;
comment|/* modulation attack& hold time (0x7f7f) */
name|unsigned
name|short
name|moddcysus
decl_stmt|;
comment|/* modulation decay& sustain (0x7f7f) */
name|unsigned
name|short
name|modrelease
decl_stmt|;
comment|/* modulation release time (0x807f) */
name|short
name|modkeyhold
decl_stmt|,
name|modkeydecay
decl_stmt|;
comment|/* envelope change per key (not used) */
name|unsigned
name|short
name|voldelay
decl_stmt|;
comment|/* volume delay (0x8000) */
name|unsigned
name|short
name|volatkhld
decl_stmt|;
comment|/* volume attack& hold time (0x7f7f) */
name|unsigned
name|short
name|voldcysus
decl_stmt|;
comment|/* volume decay& sustain (0x7f7f) */
name|unsigned
name|short
name|volrelease
decl_stmt|;
comment|/* volume release time (0x807f) */
name|short
name|volkeyhold
decl_stmt|,
name|volkeydecay
decl_stmt|;
comment|/* envelope change per key (not used) */
name|unsigned
name|short
name|lfo1delay
decl_stmt|;
comment|/* LFO1 delay (0x8000) */
name|unsigned
name|short
name|lfo2delay
decl_stmt|;
comment|/* LFO2 delay (0x8000) */
name|unsigned
name|short
name|pefe
decl_stmt|;
comment|/* modulation pitch& cutoff (0x0000) */
name|unsigned
name|short
name|fmmod
decl_stmt|;
comment|/* LFO1 pitch& cutoff (0x0000) */
name|unsigned
name|short
name|tremfrq
decl_stmt|;
comment|/* LFO1 volume& freq (0x0000) */
name|unsigned
name|short
name|fm2frq2
decl_stmt|;
comment|/* LFO2 pitch& freq (0x0000) */
name|unsigned
name|char
name|cutoff
decl_stmt|;
comment|/* initial cutoff (0xff) */
name|unsigned
name|char
name|filterQ
decl_stmt|;
comment|/* initial filter Q [0-15] (0x0) */
name|unsigned
name|char
name|chorus
decl_stmt|;
comment|/* chorus send (0x00) */
name|unsigned
name|char
name|reverb
decl_stmt|;
comment|/* reverb send (0x00) */
name|unsigned
name|short
name|reserved
index|[
literal|4
index|]
decl_stmt|;
comment|/* not used */
block|}
name|awe_voice_parm
typedef|;
end_typedef

begin_comment
comment|/* wave table parameters: 92 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_awe_voice_info
block|{
name|unsigned
name|short
name|sf_id
decl_stmt|;
comment|/* file id (should be zero) */
name|unsigned
name|short
name|sample
decl_stmt|;
comment|/* sample id */
name|long
name|start
decl_stmt|,
name|end
decl_stmt|;
comment|/* sample offset correction */
name|long
name|loopstart
decl_stmt|,
name|loopend
decl_stmt|;
comment|/* loop offset correction */
name|short
name|rate_offset
decl_stmt|;
comment|/* sample rate pitch offset */
name|unsigned
name|short
name|mode
decl_stmt|;
comment|/* sample mode */
define|#
directive|define
name|AWE_MODE_ROMSOUND
value|0x8000
define|#
directive|define
name|AWE_MODE_STEREO
value|1
define|#
directive|define
name|AWE_MODE_LOOPING
value|2
define|#
directive|define
name|AWE_MODE_NORELEASE
value|4
comment|/* obsolete */
define|#
directive|define
name|AWE_MODE_INIT_PARM
value|8
name|short
name|root
decl_stmt|;
comment|/* midi root key */
name|short
name|tune
decl_stmt|;
comment|/* pitch tuning (in cents) */
name|char
name|low
decl_stmt|,
name|high
decl_stmt|;
comment|/* key note range */
name|char
name|vellow
decl_stmt|,
name|velhigh
decl_stmt|;
comment|/* velocity range */
name|char
name|fixkey
decl_stmt|,
name|fixvel
decl_stmt|;
comment|/* fixed key, velocity */
name|char
name|pan
decl_stmt|,
name|fixpan
decl_stmt|;
comment|/* panning, fixed panning */
name|short
name|exclusiveClass
decl_stmt|;
comment|/* exclusive class (0 = none) */
name|unsigned
name|char
name|amplitude
decl_stmt|;
comment|/* sample volume (127 max) */
name|unsigned
name|char
name|attenuation
decl_stmt|;
comment|/* attenuation (0.375dB) */
name|short
name|scaleTuning
decl_stmt|;
comment|/* pitch scale tuning(%), normally 100 */
name|awe_voice_parm
name|parm
decl_stmt|;
comment|/* voice envelope parameters */
name|short
name|index
decl_stmt|;
comment|/* internal index (set by driver) */
block|}
name|awe_voice_info
typedef|;
end_typedef

begin_comment
comment|/* instrument info header: 4 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_awe_voice_rec
block|{
name|unsigned
name|char
name|bank
decl_stmt|;
comment|/* midi bank number */
name|unsigned
name|char
name|instr
decl_stmt|;
comment|/* midi preset number */
name|short
name|nvoices
decl_stmt|;
comment|/* number of voices */
name|awe_voice_info
name|info
index|[
literal|0
index|]
decl_stmt|;
comment|/* voice information follows here */
block|}
name|awe_voice_rec
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------------  * sample wave information  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* wave table sample header: 32 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|awe_sample_info
block|{
name|unsigned
name|short
name|sf_id
decl_stmt|;
comment|/* file id (should be zero) */
name|unsigned
name|short
name|sample
decl_stmt|;
comment|/* sample id */
name|long
name|start
decl_stmt|,
name|end
decl_stmt|;
comment|/* start& end offset */
name|long
name|loopstart
decl_stmt|,
name|loopend
decl_stmt|;
comment|/* loop start& end offset */
name|long
name|size
decl_stmt|;
comment|/* size (0 = ROM) */
name|short
name|checksum_flag
decl_stmt|;
comment|/* use check sum = 1 */
name|unsigned
name|short
name|mode_flags
decl_stmt|;
comment|/* mode flags */
define|#
directive|define
name|AWE_SAMPLE_8BITS
value|1
comment|/* wave data is 8bits */
define|#
directive|define
name|AWE_SAMPLE_UNSIGNED
value|2
comment|/* wave data is unsigned */
define|#
directive|define
name|AWE_SAMPLE_NO_BLANK
value|4
comment|/* no blank loop is attached */
define|#
directive|define
name|AWE_SAMPLE_SINGLESHOT
value|8
comment|/* single-shot w/o loop */
define|#
directive|define
name|AWE_SAMPLE_BIDIR_LOOP
value|16
comment|/* bidirectional looping */
define|#
directive|define
name|AWE_SAMPLE_STEREO_LEFT
value|32
comment|/* stereo left sound */
define|#
directive|define
name|AWE_SAMPLE_STEREO_RIGHT
value|64
comment|/* stereo right sound */
name|unsigned
name|long
name|checksum
decl_stmt|;
comment|/* check sum */
name|unsigned
name|short
name|data
index|[
literal|0
index|]
decl_stmt|;
comment|/* sample data follows here */
block|}
name|awe_sample_info
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------------  * awe hardware controls  *----------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|_AWE_DEBUG_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|_AWE_REVERB_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|_AWE_CHORUS_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|_AWE_REMOVE_LAST_SAMPLES
value|0x03
end_define

begin_define
define|#
directive|define
name|_AWE_INITIALIZE_CHIP
value|0x04
end_define

begin_define
define|#
directive|define
name|_AWE_SEND_EFFECT
value|0x05
end_define

begin_define
define|#
directive|define
name|_AWE_TERMINATE_CHANNEL
value|0x06
end_define

begin_define
define|#
directive|define
name|_AWE_TERMINATE_ALL
value|0x07
end_define

begin_define
define|#
directive|define
name|_AWE_INITIAL_VOLUME
value|0x08
end_define

begin_define
define|#
directive|define
name|_AWE_SET_GUS_BANK
value|0x09
end_define

begin_define
define|#
directive|define
name|_AWE_MODE_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|_AWE_COOKED_FLAG
value|0x40
end_define

begin_comment
comment|/* not supported */
end_comment

begin_define
define|#
directive|define
name|_AWE_MODE_VALUE_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|_AWE_CMD
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|cmd
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|{_SEQ_NEEDBUF(8); _seqbuf[_seqbufptr] = SEQ_PRIVATE;\  _seqbuf[_seqbufptr+1] = chn;\  _seqbuf[_seqbufptr+2] = _AWE_MODE_FLAG|(cmd);\  _seqbuf[_seqbufptr+3] = voice;\  *(unsigned short*)&_seqbuf[_seqbufptr+4] = p1;\  *(unsigned short*)&_seqbuf[_seqbufptr+6] = p2;\  _SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|AWE_DEBUG_MODE
parameter_list|(
name|dev
parameter_list|,
name|p1
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_DEBUG_MODE, p1, 0)
end_define

begin_define
define|#
directive|define
name|AWE_REVERB_MODE
parameter_list|(
name|dev
parameter_list|,
name|p1
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_REVERB_MODE, p1, 0)
end_define

begin_define
define|#
directive|define
name|AWE_CHORUS_MODE
parameter_list|(
name|dev
parameter_list|,
name|p1
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_CHORUS_MODE, p1, 0)
end_define

begin_define
define|#
directive|define
name|AWE_REMOVE_LAST_SAMPLES
parameter_list|(
name|dev
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_REMOVE_LAST_SAMPLES, 0, 0)
end_define

begin_define
define|#
directive|define
name|AWE_INITIALIZE_CHIP
parameter_list|(
name|dev
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_INITIALIZE_CHIP, 0, 0)
end_define

begin_define
define|#
directive|define
name|AWE_SEND_EFFECT
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|type
parameter_list|,
name|value
parameter_list|)
value|_AWE_CMD(dev,voice,_AWE_SEND_EFFECT,type,value)
end_define

begin_define
define|#
directive|define
name|AWE_TERMINATE_CHANNEL
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|)
value|_AWE_CMD(dev,voice,_AWE_TERMINATE_CHANNEL,0,0)
end_define

begin_define
define|#
directive|define
name|AWE_TERMINATE_ALL
parameter_list|(
name|dev
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_TERMINATE_ALL, 0, 0)
end_define

begin_define
define|#
directive|define
name|AWE_INITIAL_VOLUME
parameter_list|(
name|dev
parameter_list|,
name|atten
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_INITIAL_VOLUME, atten, 0)
end_define

begin_define
define|#
directive|define
name|AWE_SET_GUS_BANK
parameter_list|(
name|dev
parameter_list|,
name|bank
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_SET_GUS_BANK, bank, 0)
end_define

begin_comment
comment|/* reverb mode */
end_comment

begin_define
define|#
directive|define
name|AWE_REVERB_ROOM1
value|0
end_define

begin_define
define|#
directive|define
name|AWE_REVERB_ROOM2
value|1
end_define

begin_define
define|#
directive|define
name|AWE_REVERB_ROOM3
value|2
end_define

begin_define
define|#
directive|define
name|AWE_REVERB_HALL1
value|3
end_define

begin_define
define|#
directive|define
name|AWE_REVERB_HALL2
value|4
end_define

begin_define
define|#
directive|define
name|AWE_REVERB_PLATE
value|5
end_define

begin_define
define|#
directive|define
name|AWE_REVERB_DELAY
value|6
end_define

begin_define
define|#
directive|define
name|AWE_REVERB_PANNINGDELAY
value|7
end_define

begin_comment
comment|/* chorus mode */
end_comment

begin_define
define|#
directive|define
name|AWE_CHORUS_1
value|0
end_define

begin_define
define|#
directive|define
name|AWE_CHORUS_2
value|1
end_define

begin_define
define|#
directive|define
name|AWE_CHORUS_3
value|2
end_define

begin_define
define|#
directive|define
name|AWE_CHORUS_4
value|3
end_define

begin_define
define|#
directive|define
name|AWE_CHORUS_FEEDBACK
value|4
end_define

begin_define
define|#
directive|define
name|AWE_CHORUS_FLANGER
value|5
end_define

begin_define
define|#
directive|define
name|AWE_CHORUS_SHORTDELAY
value|6
end_define

begin_define
define|#
directive|define
name|AWE_CHORUS_SHORTDELAY2
value|7
end_define

begin_comment
comment|/* effects */
end_comment

begin_enum
enum|enum
block|{
comment|/* modulation envelope parameters */
comment|/* 0*/
name|AWE_FX_ENV1_DELAY
block|,
comment|/* WORD: ENVVAL */
comment|/* 1*/
name|AWE_FX_ENV1_ATTACK
block|,
comment|/* BYTE: up ATKHLD */
comment|/* 2*/
name|AWE_FX_ENV1_HOLD
block|,
comment|/* BYTE: lw ATKHLD */
comment|/* 3*/
name|AWE_FX_ENV1_DECAY
block|,
comment|/* BYTE: lw DCYSUS */
comment|/* 4*/
name|AWE_FX_ENV1_RELEASE
block|,
comment|/* BYTE: lw DCYSUS */
comment|/* 5*/
name|AWE_FX_ENV1_SUSTAIN
block|,
comment|/* BYTE: up DCYSUS */
comment|/* 6*/
name|AWE_FX_ENV1_PITCH
block|,
comment|/* BYTE: up PEFE */
comment|/* 7*/
name|AWE_FX_ENV1_CUTOFF
block|,
comment|/* BYTE: lw PEFE */
comment|/* volume envelope parameters */
comment|/* 8*/
name|AWE_FX_ENV2_DELAY
block|,
comment|/* WORD: ENVVOL */
comment|/* 9*/
name|AWE_FX_ENV2_ATTACK
block|,
comment|/* BYTE: up ATKHLDV */
comment|/*10*/
name|AWE_FX_ENV2_HOLD
block|,
comment|/* BYTE: lw ATKHLDV */
comment|/*11*/
name|AWE_FX_ENV2_DECAY
block|,
comment|/* BYTE: lw DCYSUSV */
comment|/*12*/
name|AWE_FX_ENV2_RELEASE
block|,
comment|/* BYTE: lw DCYSUSV */
comment|/*13*/
name|AWE_FX_ENV2_SUSTAIN
block|,
comment|/* BYTE: up DCYSUSV */
comment|/* LFO1 (tremolo& vibrato) parameters */
comment|/*14*/
name|AWE_FX_LFO1_DELAY
block|,
comment|/* WORD: LFO1VAL */
comment|/*15*/
name|AWE_FX_LFO1_FREQ
block|,
comment|/* BYTE: lo TREMFRQ */
comment|/*16*/
name|AWE_FX_LFO1_VOLUME
block|,
comment|/* BYTE: up TREMFRQ */
comment|/*17*/
name|AWE_FX_LFO1_PITCH
block|,
comment|/* BYTE: up FMMOD */
comment|/*18*/
name|AWE_FX_LFO1_CUTOFF
block|,
comment|/* BYTE: lo FMMOD */
comment|/* LFO2 (vibrato) parameters */
comment|/*19*/
name|AWE_FX_LFO2_DELAY
block|,
comment|/* WORD: LFO2VAL */
comment|/*20*/
name|AWE_FX_LFO2_FREQ
block|,
comment|/* BYTE: lo FM2FRQ2 */
comment|/*21*/
name|AWE_FX_LFO2_PITCH
block|,
comment|/* BYTE: up FM2FRQ2 */
comment|/* Other overall effect parameters */
comment|/*22*/
name|AWE_FX_INIT_PITCH
block|,
comment|/* SHORT: pitch offset */
comment|/*23*/
name|AWE_FX_CHORUS
block|,
comment|/* BYTE: chorus effects send (0-255) */
comment|/*24*/
name|AWE_FX_REVERB
block|,
comment|/* BYTE: reverb effects send (0-255) */
comment|/*25*/
name|AWE_FX_CUTOFF
block|,
comment|/* BYTE: up IFATN */
comment|/*26*/
name|AWE_FX_FILTERQ
block|,
comment|/* BYTE: up CCCA */
comment|/* Sample / loop offset changes */
comment|/*27*/
name|AWE_FX_SAMPLE_START
block|,
comment|/* SHORT: offset */
comment|/*28*/
name|AWE_FX_LOOP_START
block|,
comment|/* SHORT: offset */
comment|/*29*/
name|AWE_FX_LOOP_END
block|,
comment|/* SHORT: offset */
comment|/*30*/
name|AWE_FX_COARSE_SAMPLE_START
block|,
comment|/* SHORT: upper word offset */
comment|/*31*/
name|AWE_FX_COARSE_LOOP_START
block|,
comment|/* SHORT: upper word offset */
comment|/*32*/
name|AWE_FX_COARSE_LOOP_END
block|,
comment|/* SHORT: upper word offset */
name|AWE_FX_END
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AWE_VOICE_H */
end_comment

end_unit

