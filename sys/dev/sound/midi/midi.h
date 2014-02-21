begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Mathew Kanner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIDI_H
end_ifndef

begin_define
define|#
directive|define
name|MIDI_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_MIDI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|M_RX
value|0x01
end_define

begin_define
define|#
directive|define
name|M_TX
value|0x02
end_define

begin_define
define|#
directive|define
name|M_RXEN
value|0x04
end_define

begin_define
define|#
directive|define
name|M_TXEN
value|0x08
end_define

begin_define
define|#
directive|define
name|MIDI_TYPE
value|unsigned char
end_define

begin_struct_decl
struct_decl|struct
name|snd_midi
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|snd_midi
modifier|*
name|midi_init
parameter_list|(
name|kobj_class_t
name|_mpu_cls
parameter_list|,
name|int
name|_unit
parameter_list|,
name|int
name|_channel
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|midi_uninit
parameter_list|(
name|struct
name|snd_midi
modifier|*
name|_m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|midi_out
parameter_list|(
name|struct
name|snd_midi
modifier|*
name|_m
parameter_list|,
name|MIDI_TYPE
modifier|*
name|_buf
parameter_list|,
name|int
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|midi_in
parameter_list|(
name|struct
name|snd_midi
modifier|*
name|_m
parameter_list|,
name|MIDI_TYPE
modifier|*
name|_buf
parameter_list|,
name|int
name|_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kobj_t
name|midimapper_addseq
parameter_list|(
name|void
modifier|*
name|arg1
parameter_list|,
name|int
modifier|*
name|unit
parameter_list|,
name|void
modifier|*
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|midimapper_open
parameter_list|(
name|void
modifier|*
name|arg1
parameter_list|,
name|void
modifier|*
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|midimapper_close
parameter_list|(
name|void
modifier|*
name|arg1
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kobj_t
name|midimapper_fetch_synth
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

