begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/awe_voice.h  *  * Voice information definitions for the low level driver for the   * AWE32/Sound Blaster 32 wave table synth.  *   version 0.4.2c; Oct. 7, 1997  *  * Copyright (C) 1996,1997 Takashi Iwai  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
name|optarg
decl_stmt|;
comment|/* optional argument */
name|int
name|len
decl_stmt|;
comment|/* data length (without this header) */
name|short
name|type
decl_stmt|;
comment|/* patch operation type */
define|#
directive|define
name|AWE_LOAD_INFO
value|0
comment|/* awe_voice_rec */
define|#
directive|define
name|AWE_LOAD_DATA
value|1
comment|/* awe_sample_info */
define|#
directive|define
name|AWE_OPEN_PATCH
value|2
comment|/* awe_open_parm */
define|#
directive|define
name|AWE_CLOSE_PATCH
value|3
comment|/* none */
define|#
directive|define
name|AWE_UNLOAD_PATCH
value|4
comment|/* none */
define|#
directive|define
name|AWE_REPLACE_DATA
value|5
comment|/* awe_sample_info (optarg=#channels)*/
define|#
directive|define
name|AWE_MAP_PRESET
value|6
comment|/* awe_voice_map */
define|#
directive|define
name|AWE_LOAD_CHORUS_FX
value|0x10
comment|/* awe_chorus_fx_rec (optarg=mode) */
define|#
directive|define
name|AWE_LOAD_REVERB_FX
value|0x11
comment|/* awe_reverb_fx_rec (optarg=mode) */
name|short
name|reserved
decl_stmt|;
comment|/* word alignment data */
comment|/* the actual patch data begins after this */
if|#
directive|if
name|defined
argument_list|(
name|AWE_COMPAT_030
argument_list|)
operator|&&
name|AWE_COMPAT_030
name|char
name|data
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|awe_patch_info
typedef|;
end_typedef

begin_comment
comment|/*#define AWE_PATCH_INFO_SIZE	16*/
end_comment

begin_define
define|#
directive|define
name|AWE_PATCH_INFO_SIZE
value|sizeof(awe_patch_info)
end_define

begin_comment
comment|/*----------------------------------------------------------------  * open patch  *----------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|AWE_PATCH_NAME_LEN
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
name|_awe_open_parm
block|{
name|unsigned
name|short
name|type
decl_stmt|;
comment|/* sample type */
define|#
directive|define
name|AWE_PAT_TYPE_MISC
value|0
define|#
directive|define
name|AWE_PAT_TYPE_GM
value|1
define|#
directive|define
name|AWE_PAT_TYPE_GS
value|2
define|#
directive|define
name|AWE_PAT_TYPE_MT32
value|3
define|#
directive|define
name|AWE_PAT_TYPE_XG
value|4
define|#
directive|define
name|AWE_PAT_TYPE_SFX
value|5
define|#
directive|define
name|AWE_PAT_TYPE_GUS
value|6
define|#
directive|define
name|AWE_PAT_TYPE_MAP
value|7
define|#
directive|define
name|AWE_PAT_LOCKED
value|0x100
comment|/* lock the samples */
name|short
name|reserved
decl_stmt|;
name|char
name|name
index|[
name|AWE_PATCH_NAME_LEN
index|]
decl_stmt|;
block|}
name|awe_open_parm
typedef|;
end_typedef

begin_comment
comment|/*#define AWE_OPEN_PARM_SIZE	28*/
end_comment

begin_define
define|#
directive|define
name|AWE_OPEN_PARM_SIZE
value|sizeof(awe_open_parm)
end_define

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

begin_define
define|#
directive|define
name|AWE_VOICE_PARM_SIZE
value|48
end_define

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
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
comment|/* sample offset correction */
name|int
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
comment|/*#define AWE_VOICE_INFO_SIZE	92*/
end_comment

begin_define
define|#
directive|define
name|AWE_VOICE_INFO_SIZE
value|sizeof(awe_voice_info)
end_define

begin_comment
comment|/*----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* The info entry of awe_voice_rec is changed from 0 to 1  * for some compilers refusing zero size array.  * Due to this change, sizeof(awe_voice_rec) becomes different  * from older versions.  * Use AWE_VOICE_REC_SIZE instead.  */
end_comment

begin_comment
comment|/* instrument info header: 4 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_awe_voice_rec_hdr
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
name|char
name|nvoices
decl_stmt|;
comment|/* number of voices */
name|char
name|write_mode
decl_stmt|;
comment|/* write mode; normally 0 */
define|#
directive|define
name|AWE_WR_APPEND
value|0
comment|/* append anyway */
define|#
directive|define
name|AWE_WR_EXCLUSIVE
value|1
comment|/* skip if already exists */
define|#
directive|define
name|AWE_WR_REPLACE
value|2
comment|/* replace if already exists */
block|}
name|awe_voice_rec_hdr
typedef|;
end_typedef

begin_comment
comment|/*#define AWE_VOICE_REC_SIZE	4*/
end_comment

begin_define
define|#
directive|define
name|AWE_VOICE_REC_SIZE
value|sizeof(awe_voice_rec_hdr)
end_define

begin_comment
comment|/* the standard patch structure for one sample */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_awe_voice_rec_patch
block|{
name|awe_patch_info
name|patch
decl_stmt|;
name|awe_voice_rec_hdr
name|hdr
decl_stmt|;
name|awe_voice_info
name|info
decl_stmt|;
block|}
name|awe_voice_rec_patch
typedef|;
end_typedef

begin_comment
comment|/* obsolete data type */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AWE_COMPAT_030
argument_list|)
operator|&&
name|AWE_COMPAT_030
end_if

begin_define
define|#
directive|define
name|AWE_INFOARRAY_SIZE
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AWE_INFOARRAY_SIZE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* voice information follows here */
name|awe_voice_info
name|info
index|[
name|AWE_INFOARRAY_SIZE
index|]
decl_stmt|;
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
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
comment|/* start& end offset */
name|int
name|loopstart
decl_stmt|,
name|loopend
decl_stmt|;
comment|/* loop start& end offset */
name|int
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
define|#
directive|define
name|AWE_SAMPLE_REVERSE_LOOP
value|128
comment|/* reverse looping */
name|unsigned
name|int
name|checksum
decl_stmt|;
comment|/* check sum */
if|#
directive|if
name|defined
argument_list|(
name|AWE_COMPAT_030
argument_list|)
operator|&&
name|AWE_COMPAT_030
name|unsigned
name|short
name|data
index|[
literal|0
index|]
decl_stmt|;
comment|/* sample data follows here */
endif|#
directive|endif
block|}
name|awe_sample_info
typedef|;
end_typedef

begin_comment
comment|/*#define AWE_SAMPLE_INFO_SIZE	32*/
end_comment

begin_define
define|#
directive|define
name|AWE_SAMPLE_INFO_SIZE
value|sizeof(awe_sample_info)
end_define

begin_comment
comment|/*----------------------------------------------------------------  * voice preset mapping  *----------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|awe_voice_map
block|{
name|int
name|map_bank
decl_stmt|,
name|map_instr
decl_stmt|,
name|map_key
decl_stmt|;
comment|/* key = -1 means all keys */
name|int
name|src_bank
decl_stmt|,
name|src_instr
decl_stmt|,
name|src_key
decl_stmt|;
block|}
name|awe_voice_map
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AWE_VOICE_MAP_SIZE
value|sizeof(awe_voice_map)
end_define

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
name|_AWE_INITIAL_ATTEN
value|_AWE_INITIAL_VOLUME
end_define

begin_define
define|#
directive|define
name|_AWE_RESET_CHANNEL
value|0x09
end_define

begin_define
define|#
directive|define
name|_AWE_CHANNEL_MODE
value|0x0a
end_define

begin_define
define|#
directive|define
name|_AWE_DRUM_CHANNELS
value|0x0b
end_define

begin_define
define|#
directive|define
name|_AWE_MISC_MODE
value|0x0c
end_define

begin_define
define|#
directive|define
name|_AWE_RELEASE_ALL
value|0x0d
end_define

begin_define
define|#
directive|define
name|_AWE_NOTEOFF_ALL
value|0x0e
end_define

begin_define
define|#
directive|define
name|_AWE_CHN_PRESSURE
value|0x0f
end_define

begin_comment
comment|/*#define _AWE_GET_CURRENT_MODE		0x10*/
end_comment

begin_define
define|#
directive|define
name|_AWE_EQUALIZER
value|0x11
end_define

begin_comment
comment|/*#define _AWE_GET_MISC_MODE		0x12*/
end_comment

begin_comment
comment|/*#define _AWE_GET_FONTINFO		0x13*/
end_comment

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

begin_comment
comment|/*----------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|_AWE_SET_CMD
parameter_list|(
name|p
parameter_list|,
name|dev
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
value|{((char*)(p))[0] = SEQ_PRIVATE;\  ((char*)(p))[1] = dev;\  ((char*)(p))[2] = _AWE_MODE_FLAG|(cmd);\  ((char*)(p))[3] = voice;\  ((unsigned short*)(p))[2] = p1;\  ((unsigned short*)(p))[3] = p2;}
end_define

begin_comment
comment|/* buffered access */
end_comment

begin_define
define|#
directive|define
name|_AWE_CMD
parameter_list|(
name|dev
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
value|{_SEQ_NEEDBUF(8);\  _AWE_SET_CMD(_seqbuf + _seqbufptr, dev, voice, cmd, p1, p2);\  _SEQ_ADVBUF(8);}
end_define

begin_comment
comment|/* direct access */
end_comment

begin_define
define|#
directive|define
name|_AWE_CMD_NOW
parameter_list|(
name|seqfd
parameter_list|,
name|dev
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
value|{struct seq_event_rec tmp;\  _AWE_SET_CMD(&tmp, dev, voice, cmd, p1, p2);\  ioctl(seqfd, SNDCTL_SEQ_OUTOFBAND,&tmp);}
end_define

begin_comment
comment|/*----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* set debugging mode */
end_comment

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

begin_comment
comment|/* set reverb mode; from 0 to 7 */
end_comment

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

begin_comment
comment|/* set chorus mode; from 0 to 7 */
end_comment

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

begin_comment
comment|/* reset channel */
end_comment

begin_define
define|#
directive|define
name|AWE_RESET_CHANNEL
parameter_list|(
name|dev
parameter_list|,
name|ch
parameter_list|)
value|_AWE_CMD(dev, ch, _AWE_RESET_CHANNEL, 0, 0)
end_define

begin_define
define|#
directive|define
name|AWE_RESET_CONTROL
parameter_list|(
name|dev
parameter_list|,
name|ch
parameter_list|)
value|_AWE_CMD(dev, ch, _AWE_RESET_CHANNEL, 1, 0)
end_define

begin_comment
comment|/* send an effect to all layers */
end_comment

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
name|AWE_ADD_EFFECT
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|type
parameter_list|,
name|value
parameter_list|)
value|_AWE_CMD(dev,voice,_AWE_SEND_EFFECT,((type)|0x80),value)
end_define

begin_define
define|#
directive|define
name|AWE_UNSET_EFFECT
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|type
parameter_list|)
value|_AWE_CMD(dev,voice,_AWE_SEND_EFFECT,((type)|0x40),0)
end_define

begin_comment
comment|/* send an effect to a layer */
end_comment

begin_define
define|#
directive|define
name|AWE_SEND_LAYER_EFFECT
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|layer
parameter_list|,
name|type
parameter_list|,
name|value
parameter_list|)
value|_AWE_CMD(dev,voice,_AWE_SEND_EFFECT,((layer+1)<<8|(type)),value)
end_define

begin_define
define|#
directive|define
name|AWE_ADD_LAYER_EFFECT
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|layer
parameter_list|,
name|type
parameter_list|,
name|value
parameter_list|)
value|_AWE_CMD(dev,voice,_AWE_SEND_EFFECT,((layer+1)<<8|(type)|0x80),value)
end_define

begin_define
define|#
directive|define
name|AWE_UNSET_LAYER_EFFECT
parameter_list|(
name|dev
parameter_list|,
name|voice
parameter_list|,
name|layer
parameter_list|,
name|type
parameter_list|)
value|_AWE_CMD(dev,voice,_AWE_SEND_EFFECT,((layer+1)<<8|(type)|0x40),0)
end_define

begin_comment
comment|/* terminate sound on the channel/voice */
end_comment

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

begin_comment
comment|/* terminate all sounds */
end_comment

begin_define
define|#
directive|define
name|AWE_TERMINATE_ALL
parameter_list|(
name|dev
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_TERMINATE_ALL, 0, 0)
end_define

begin_comment
comment|/* release all sounds (w/o sustain effect) */
end_comment

begin_define
define|#
directive|define
name|AWE_RELEASE_ALL
parameter_list|(
name|dev
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_RELEASE_ALL, 0, 0)
end_define

begin_comment
comment|/* note off all sounds (w sustain effect) */
end_comment

begin_define
define|#
directive|define
name|AWE_NOTEOFF_ALL
parameter_list|(
name|dev
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_NOTEOFF_ALL, 0, 0)
end_define

begin_comment
comment|/* set initial attenuation */
end_comment

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
name|AWE_INITIAL_ATTEN
value|AWE_INITIAL_VOLUME
end_define

begin_comment
comment|/* relative attenuation */
end_comment

begin_define
define|#
directive|define
name|AWE_SET_ATTEN
parameter_list|(
name|dev
parameter_list|,
name|atten
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_INITIAL_VOLUME, atten, 1)
end_define

begin_comment
comment|/* set channel playing mode; mode=0/1/2 */
end_comment

begin_define
define|#
directive|define
name|AWE_SET_CHANNEL_MODE
parameter_list|(
name|dev
parameter_list|,
name|mode
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_CHANNEL_MODE, mode, 0)
end_define

begin_define
define|#
directive|define
name|AWE_PLAY_INDIRECT
value|0
end_define

begin_comment
comment|/* indirect voice mode (default) */
end_comment

begin_define
define|#
directive|define
name|AWE_PLAY_MULTI
value|1
end_define

begin_comment
comment|/* multi note voice mode */
end_comment

begin_define
define|#
directive|define
name|AWE_PLAY_DIRECT
value|2
end_define

begin_comment
comment|/* direct single voice mode */
end_comment

begin_define
define|#
directive|define
name|AWE_PLAY_MULTI2
value|3
end_define

begin_comment
comment|/* sequencer2 mode; used internally */
end_comment

begin_comment
comment|/* set drum channel mask; channels is 32bit long value */
end_comment

begin_define
define|#
directive|define
name|AWE_DRUM_CHANNELS
parameter_list|(
name|dev
parameter_list|,
name|channels
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_DRUM_CHANNELS, ((channels)& 0xffff), ((channels)>> 16))
end_define

begin_comment
comment|/* set bass and treble control; values are from 0 to 11 */
end_comment

begin_define
define|#
directive|define
name|AWE_EQUALIZER
parameter_list|(
name|dev
parameter_list|,
name|bass
parameter_list|,
name|treble
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_EQUALIZER, bass, treble)
end_define

begin_comment
comment|/* remove last loaded samples */
end_comment

begin_define
define|#
directive|define
name|AWE_REMOVE_LAST_SAMPLES
parameter_list|(
name|seqfd
parameter_list|,
name|dev
parameter_list|)
value|_AWE_CMD_NOW(seqfd, dev, 0, _AWE_REMOVE_LAST_SAMPLES, 0, 0)
end_define

begin_comment
comment|/* initialize emu8000 chip */
end_comment

begin_define
define|#
directive|define
name|AWE_INITIALIZE_CHIP
parameter_list|(
name|seqfd
parameter_list|,
name|dev
parameter_list|)
value|_AWE_CMD_NOW(seqfd, dev, 0, _AWE_INITIALIZE_CHIP, 0, 0)
end_define

begin_comment
comment|/* set miscellaneous modes; meta command */
end_comment

begin_define
define|#
directive|define
name|AWE_MISC_MODE
parameter_list|(
name|dev
parameter_list|,
name|mode
parameter_list|,
name|value
parameter_list|)
value|_AWE_CMD(dev, 0, _AWE_MISC_MODE, mode, value)
end_define

begin_comment
comment|/* exclusive sound off; 1=off */
end_comment

begin_define
define|#
directive|define
name|AWE_EXCLUSIVE_SOUND
parameter_list|(
name|dev
parameter_list|,
name|mode
parameter_list|)
value|AWE_MISC_MODE(dev,AWE_MD_EXCLUSIVE_SOUND,mode)
end_define

begin_comment
comment|/* default GUS bank number */
end_comment

begin_define
define|#
directive|define
name|AWE_SET_GUS_BANK
parameter_list|(
name|dev
parameter_list|,
name|bank
parameter_list|)
value|AWE_MISC_MODE(dev,AWE_MD_GUS_BANK,bank)
end_define

begin_comment
comment|/* change panning position in realtime; 0=don't 1=do */
end_comment

begin_define
define|#
directive|define
name|AWE_REALTIME_PAN
parameter_list|(
name|dev
parameter_list|,
name|mode
parameter_list|)
value|AWE_MISC_MODE(dev,AWE_MD_REALTIME_PAN,mode)
end_define

begin_comment
comment|/* extended pressure controls; not portable with other sound drivers */
end_comment

begin_define
define|#
directive|define
name|AWE_KEY_PRESSURE
parameter_list|(
name|dev
parameter_list|,
name|ch
parameter_list|,
name|note
parameter_list|,
name|vel
parameter_list|)
value|SEQ_START_NOTE(dev,ch,(note)+128,vel)
end_define

begin_define
define|#
directive|define
name|AWE_CHN_PRESSURE
parameter_list|(
name|dev
parameter_list|,
name|ch
parameter_list|,
name|vel
parameter_list|)
value|_AWE_CMD(dev,ch,_AWE_CHN_PRESSURE,vel,0)
end_define

begin_comment
comment|/*----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* reverb mode parameters */
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

begin_define
define|#
directive|define
name|AWE_REVERB_PREDEFINED
value|8
end_define

begin_comment
comment|/* user can define reverb modes up to 32 */
end_comment

begin_define
define|#
directive|define
name|AWE_REVERB_NUMBERS
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
name|awe_reverb_fx_rec
block|{
name|unsigned
name|short
name|parms
index|[
literal|28
index|]
decl_stmt|;
block|}
name|awe_reverb_fx_rec
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* chorus mode parameters */
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

begin_define
define|#
directive|define
name|AWE_CHORUS_PREDEFINED
value|8
end_define

begin_comment
comment|/* user can define chorus modes up to 32 */
end_comment

begin_define
define|#
directive|define
name|AWE_CHORUS_NUMBERS
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
name|awe_chorus_fx_rec
block|{
name|unsigned
name|short
name|feedback
decl_stmt|;
comment|/* feedback level (0xE600-0xE6FF) */
name|unsigned
name|short
name|delay_offset
decl_stmt|;
comment|/* delay (0-0x0DA3) [1/44100 sec] */
name|unsigned
name|short
name|lfo_depth
decl_stmt|;
comment|/* LFO depth (0xBC00-0xBCFF) */
name|unsigned
name|int
name|delay
decl_stmt|;
comment|/* right delay (0-0xFFFFFFFF) [1/256/44100 sec] */
name|unsigned
name|int
name|lfo_freq
decl_stmt|;
comment|/* LFO freq LFO freq (0-0xFFFFFFFF) */
block|}
name|awe_chorus_fx_rec
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* misc mode types */
end_comment

begin_enum
enum|enum
block|{
comment|/* 0*/
name|AWE_MD_EXCLUSIVE_OFF
block|,
comment|/* obsolete */
comment|/* 1*/
name|AWE_MD_EXCLUSIVE_ON
block|,
comment|/* obsolete */
comment|/* 2*/
name|AWE_MD_VERSION
block|,
comment|/* read only */
comment|/* 3*/
name|AWE_MD_EXCLUSIVE_SOUND
block|,
comment|/* ignored */
comment|/* 4*/
name|AWE_MD_REALTIME_PAN
block|,
comment|/* 0/1: do realtime pan change (default=1) */
comment|/* 5*/
name|AWE_MD_GUS_BANK
block|,
comment|/* bank number for GUS patches (default=0) */
comment|/* 6*/
name|AWE_MD_KEEP_EFFECT
block|,
comment|/* 0/1: keep effect values, (default=0) */
comment|/* 7*/
name|AWE_MD_ZERO_ATTEN
block|,
comment|/* attenuation of max volume (default=32) */
comment|/* 8*/
name|AWE_MD_CHN_PRIOR
block|,
comment|/* 0/1: set MIDI channel priority mode (default=1) */
comment|/* 9*/
name|AWE_MD_MOD_SENSE
block|,
comment|/* integer: modwheel sensitivity (def=18) */
comment|/*10*/
name|AWE_MD_DEF_PRESET
block|,
comment|/* integer: default preset number (def=0) */
comment|/*11*/
name|AWE_MD_DEF_BANK
block|,
comment|/* integer: default bank number (def=0) */
comment|/*12*/
name|AWE_MD_DEF_DRUM
block|,
comment|/* integer: default drumset number (def=0) */
comment|/*13*/
name|AWE_MD_TOGGLE_DRUM_BANK
block|,
comment|/* 0/1: toggle drum flag with bank# (def=0) */
name|AWE_MD_END
block|, }
enum|;
end_enum

begin_comment
comment|/*----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* effect parameters */
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
comment|/*33*/
name|AWE_FX_ATTEN
block|,
comment|/* BYTE: lo IFATN */
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

