begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Cameron Grant<cg@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|int
name|align
decl_stmt|;
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
name|chn_fmtscore
parameter_list|(
name|u_int32_t
name|fmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|chn_fmtbestbit
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
name|chn_fmtbeststereo
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
name|chn_fmtbest
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
name|chn_fmtchain
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|u_int32_t
modifier|*
name|to
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

begin_define
define|#
directive|define
name|FEEDER_DECLARE
parameter_list|(
name|feeder
parameter_list|,
name|palign
parameter_list|,
name|pdata
parameter_list|)
define|\
value|static struct feeder_class feeder ## _class = { \ 	.name =		#feeder, \ 	.methods =	feeder ## _methods, \ 	.size =		sizeof(struct pcm_feeder), \ 	.align =	palign, \ 	.desc =		feeder ## _desc, \ 	.data =		pdata, \ }; \ SYSINIT(feeder, SI_SUB_DRIVERS, SI_ORDER_ANY, feeder_register,&feeder ## _class);
end_define

begin_define
define|#
directive|define
name|FEEDER_ROOT
value|0
end_define

begin_define
define|#
directive|define
name|FEEDER_FMT
value|1
end_define

begin_define
define|#
directive|define
name|FEEDER_MIXER
value|2
end_define

begin_define
define|#
directive|define
name|FEEDER_RATE
value|3
end_define

begin_define
define|#
directive|define
name|FEEDER_FILTER
value|4
end_define

begin_define
define|#
directive|define
name|FEEDER_VOLUME
value|5
end_define

begin_define
define|#
directive|define
name|FEEDER_SWAPLR
value|6
end_define

begin_define
define|#
directive|define
name|FEEDER_LAST
value|32
end_define

begin_define
define|#
directive|define
name|FEEDRATE_SRC
value|1
end_define

begin_define
define|#
directive|define
name|FEEDRATE_DST
value|2
end_define

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

begin_comment
comment|/*  * Default buffer size for feeder processing.  *  * Big   = less sndbuf_feed(), more memory usage.  * Small = aggresive sndbuf_feed() (perhaps too much), less memory usage.  */
end_comment

begin_define
define|#
directive|define
name|FEEDBUFSZ
value|16384
end_define

begin_define
define|#
directive|define
name|FEEDBUFSZ_MIN
value|2048
end_define

begin_define
define|#
directive|define
name|FEEDBUFSZ_MAX
value|131072
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
name|feeder_buffersize
decl_stmt|;
end_decl_stmt

end_unit

