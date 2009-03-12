begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2002 Hiroyuki Aizu<aizu@navi.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|NO_RECORDING
end_define

begin_comment
comment|/* XXX: some routines missing from uaudio.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Defined in uaudio.c, used in uaudio_pcm,c */
end_comment

begin_function_decl
name|void
name|uaudio_chan_set_param_pcm_dma_buff
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
modifier|*
name|start
parameter_list|,
name|u_char
modifier|*
name|end
parameter_list|,
name|struct
name|pcm_channel
modifier|*
name|pc
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uaudio_trigger_output
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uaudio_halt_out_dma
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NO_RECORDING
end_ifndef

begin_function_decl
name|int
name|uaudio_trigger_input
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uaudio_halt_in_dma
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|uaudio_chan_set_param
parameter_list|(
name|device_t
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uaudio_chan_set_param_blocksize
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int32_t
name|blocksize
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uaudio_chan_set_param_speed
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int32_t
name|speed
parameter_list|,
name|int
name|reqdir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uaudio_chan_set_param_format
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int32_t
name|format
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uaudio_chan_getptr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uaudio_mixer_set
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|unsigned
name|type
parameter_list|,
name|unsigned
name|left
parameter_list|,
name|unsigned
name|right
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|uaudio_mixer_setrecsrc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int32_t
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|uaudio_query_mix_info
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|uaudio_query_recsrc_info
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|uaudio_query_formats
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|dir
parameter_list|,
name|unsigned
name|maxfmt
parameter_list|,
name|struct
name|pcmchan_caps
modifier|*
name|fmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uaudio_sndstat_register
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uaudio_get_vendor
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uaudio_get_product
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uaudio_get_release
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

end_unit

