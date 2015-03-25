begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2002 Hiroyuki Aizu<aizu@navi.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* prototypes from "uaudio.c" used by "uaudio_pcm.c" */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UAUDIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_UAUDIO_H_
end_define

begin_struct_decl
struct_decl|struct
name|uaudio_chan
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uaudio_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|snd_dbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|snd_mixer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pcm_channel
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_attach_sub
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|kobj_class_t
name|mixer_class
parameter_list|,
name|kobj_class_t
name|chan_class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_detach_sub
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|uaudio_chan_init
parameter_list|(
name|struct
name|uaudio_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|snd_dbuf
modifier|*
name|b
parameter_list|,
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_chan_free
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_chan_set_param_blocksize
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|,
name|uint32_t
name|blocksize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_chan_set_param_fragments
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|,
name|uint32_t
name|blocksize
parameter_list|,
name|uint32_t
name|blockcount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_chan_set_param_speed
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|,
name|uint32_t
name|speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_chan_getptr
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|pcmchan_caps
modifier|*
name|uaudio_chan_getcaps
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|pcmchan_matrix
modifier|*
name|uaudio_chan_getmatrix
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|,
name|uint32_t
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_chan_set_param_format
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|,
name|uint32_t
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|uaudio_chan_start
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|uaudio_chan_stop
parameter_list|(
name|struct
name|uaudio_chan
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_mixer_init_sub
parameter_list|(
name|struct
name|uaudio_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uaudio_mixer_uninit_sub
parameter_list|(
name|struct
name|uaudio_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|uaudio_mixer_set
parameter_list|(
name|struct
name|uaudio_softc
modifier|*
name|sc
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
specifier|extern
name|uint32_t
name|uaudio_mixer_setrecsrc
parameter_list|(
name|struct
name|uaudio_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|src
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UAUDIO_H_ */
end_comment

end_unit

