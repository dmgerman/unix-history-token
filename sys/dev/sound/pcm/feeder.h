begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2009 Ariff Abdullah<ariff@FreeBSD.org>  * Copyright (c) 1999 Cameron Grant<cg@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|pcm_feederdesc
block|{
name|u_int32_t
name|type
decl_stmt|;
name|u_int32_t
name|in
decl_stmt|,
name|out
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|int
name|idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|feeder_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
name|struct
name|pcm_feederdesc
modifier|*
name|desc
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcm_feeder
block|{
name|KOBJ_FIELDS
expr_stmt|;
name|int
name|align
decl_stmt|;
name|struct
name|pcm_feederdesc
modifier|*
name|desc
decl_stmt|,
name|desc_static
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|struct
name|feeder_class
modifier|*
name|class
decl_stmt|;
name|struct
name|pcm_feeder
modifier|*
name|source
decl_stmt|,
modifier|*
name|parent
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|feeder_register
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|feeder_class
modifier|*
name|feeder_getclass
parameter_list|(
name|struct
name|pcm_feederdesc
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|snd_fmtscore
parameter_list|(
name|u_int32_t
name|fmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|snd_fmtbestbit
parameter_list|(
name|u_int32_t
name|fmt
parameter_list|,
name|u_int32_t
modifier|*
name|fmts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|snd_fmtbestchannel
parameter_list|(
name|u_int32_t
name|fmt
parameter_list|,
name|u_int32_t
modifier|*
name|fmts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|snd_fmtbest
parameter_list|(
name|u_int32_t
name|fmt
parameter_list|,
name|u_int32_t
modifier|*
name|fmts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_addfeeder
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|struct
name|feeder_class
modifier|*
name|fc
parameter_list|,
name|struct
name|pcm_feederdesc
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chn_removefeeder
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcm_feeder
modifier|*
name|chn_findfeeder
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|u_int32_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|feeder_printchain
parameter_list|(
name|struct
name|pcm_feeder
modifier|*
name|head
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feeder_chain
parameter_list|(
name|struct
name|pcm_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FEEDER_DECLARE
parameter_list|(
name|feeder
parameter_list|,
name|pdata
parameter_list|)
define|\
value|static struct feeder_class feeder ## _class = {				\ 	.name =		#feeder,					\ 	.methods =	feeder ## _methods,				\ 	.size =		sizeof(struct pcm_feeder),			\ 	.desc =		feeder ## _desc,				\ 	.data =		pdata,						\ };									\ SYSINIT(feeder, SI_SUB_DRIVERS, SI_ORDER_ANY, feeder_register,		\&feeder ## _class)
end_define

begin_enum
enum|enum
block|{
name|FEEDER_ROOT
block|,
name|FEEDER_FORMAT
block|,
name|FEEDER_MIXER
block|,
name|FEEDER_RATE
block|,
name|FEEDER_EQ
block|,
name|FEEDER_VOLUME
block|,
name|FEEDER_MATRIX
block|,
name|FEEDER_LAST
block|, }
enum|;
end_enum

begin_comment
comment|/* feeder_format */
end_comment

begin_enum
enum|enum
block|{
name|FEEDFORMAT_CHANNELS
block|}
enum|;
end_enum

begin_comment
comment|/* feeder_mixer */
end_comment

begin_enum
enum|enum
block|{
name|FEEDMIXER_CHANNELS
block|}
enum|;
end_enum

begin_comment
comment|/* feeder_rate */
end_comment

begin_enum
enum|enum
block|{
name|FEEDRATE_SRC
block|,
name|FEEDRATE_DST
block|,
name|FEEDRATE_QUALITY
block|,
name|FEEDRATE_CHANNELS
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FEEDRATE_RATEMIN
value|1
end_define

begin_define
define|#
directive|define
name|FEEDRATE_RATEMAX
value|2016000
end_define

begin_comment
comment|/* 48000 * 42 */
end_comment

begin_define
define|#
directive|define
name|FEEDRATE_MIN
value|1
end_define

begin_define
define|#
directive|define
name|FEEDRATE_MAX
value|0x7fffff
end_define

begin_comment
comment|/* sign 24bit ~ 8ghz ! */
end_comment

begin_define
define|#
directive|define
name|FEEDRATE_ROUNDHZ
value|25
end_define

begin_define
define|#
directive|define
name|FEEDRATE_ROUNDHZ_MIN
value|0
end_define

begin_define
define|#
directive|define
name|FEEDRATE_ROUNDHZ_MAX
value|500
end_define

begin_decl_stmt
specifier|extern
name|int
name|feeder_rate_min
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|feeder_rate_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|feeder_rate_round
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|feeder_rate_quality
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* feeder_eq */
end_comment

begin_enum
enum|enum
block|{
name|FEEDEQ_CHANNELS
block|,
name|FEEDEQ_RATE
block|,
name|FEEDEQ_TREBLE
block|,
name|FEEDEQ_BASS
block|,
name|FEEDEQ_PREAMP
block|,
name|FEEDEQ_STATE
block|,
name|FEEDEQ_DISABLE
block|,
name|FEEDEQ_ENABLE
block|,
name|FEEDEQ_BYPASS
block|,
name|FEEDEQ_UNKNOWN
block|}
enum|;
end_enum

begin_function_decl
name|int
name|feeder_eq_validrate
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|feeder_eq_initsys
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* feeder_volume */
end_comment

begin_enum
enum|enum
block|{
name|FEEDVOLUME_CLASS
block|,
name|FEEDVOLUME_CHANNELS
block|,
name|FEEDVOLUME_STATE
block|,
name|FEEDVOLUME_ENABLE
block|,
name|FEEDVOLUME_BYPASS
block|}
enum|;
end_enum

begin_function_decl
name|int
name|feeder_volume_apply_matrix
parameter_list|(
name|struct
name|pcm_feeder
modifier|*
parameter_list|,
name|struct
name|pcmchan_matrix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* feeder_matrix */
end_comment

begin_function_decl
name|int
name|feeder_matrix_default_id
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcmchan_matrix
modifier|*
name|feeder_matrix_default_channel_map
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|feeder_matrix_default_format
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feeder_matrix_format_id
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcmchan_matrix
modifier|*
name|feeder_matrix_format_map
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcmchan_matrix
modifier|*
name|feeder_matrix_id_map
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feeder_matrix_setup
parameter_list|(
name|struct
name|pcm_feeder
modifier|*
parameter_list|,
name|struct
name|pcmchan_matrix
modifier|*
parameter_list|,
name|struct
name|pcmchan_matrix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feeder_matrix_compare
parameter_list|(
name|struct
name|pcmchan_matrix
modifier|*
parameter_list|,
name|struct
name|pcmchan_matrix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 4Front OSS stuffs */
end_comment

begin_function_decl
name|int
name|feeder_matrix_oss_get_channel_order
parameter_list|(
name|struct
name|pcmchan_matrix
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feeder_matrix_oss_set_channel_order
parameter_list|(
name|struct
name|pcmchan_matrix
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* feeder_matrix */
end_comment

begin_define
unit|enum { 	FEEDMATRIX_TYPE, 	FEEDMATRIX_RESET, 	FEEDMATRIX_CHANNELS_IN, 	FEEDMATRIX_CHANNELS_OUT, 	FEEDMATRIX_SET_MAP };  enum { 	FEEDMATRIX_TYPE_NONE, 	FEEDMATRIX_TYPE_AUTO, 	FEEDMATRIX_TYPE_2X1, 	FEEDMATRIX_TYPE_1X2, 	FEEDMATRIX_TYPE_2X2 };
define|#
directive|define
name|FEEDMATRIX_TYPE_STEREO_TO_MONO
value|FEEDMATRIX_TYPE_2X1
end_define

begin_define
define|#
directive|define
name|FEEDMATRIX_TYPE_MONO_TO_STEREO
value|FEEDMATRIX_TYPE_1X2
end_define

begin_define
define|#
directive|define
name|FEEDMATRIX_TYPE_SWAP_STEREO
value|FEEDMATRIX_TYPE_2X2
end_define

begin_define
define|#
directive|define
name|FEEDMATRIX_MAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x)& 0x3f)<< 6) | ((y)& 0x3f))
end_define

begin_define
define|#
directive|define
name|FEEDMATRIX_MAP_SRC
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3f)
end_define

begin_define
define|#
directive|define
name|FEEDMATRIX_MAP_DST
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x3f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * By default, various feeders only deal with sign 16/32 bit native-endian  * since it should provide the fastest processing path. Processing 8bit samples  * is too noisy due to limited dynamic range, while 24bit is quite slow due to  * unnatural per-byte read/write. However, for debugging purposes, ensuring  * implementation correctness and torture test, the following can be defined:  *  *      SND_FEEDER_MULTIFORMAT - Compile all type of converters, but force  *                               8bit samples to be converted to 16bit  *                               native-endian for better dynamic range.  *                               Process 24bit samples natively.  * SND_FEEDER_FULL_MULTIFORMAT - Ditto, but process 8bit samples natively.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SND_FEEDER_FULL_MULTIFORMAT
end_ifdef

begin_undef
undef|#
directive|undef
name|SND_FEEDER_MULTIFORMAT
end_undef

begin_define
define|#
directive|define
name|SND_FEEDER_MULTIFORMAT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

