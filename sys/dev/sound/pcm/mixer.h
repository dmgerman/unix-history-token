begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|mixer_init
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|kobj_class_t
name|cls
parameter_list|,
name|void
modifier|*
name|devinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mixer_uninit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mixer_reinit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mixer_ioctl
parameter_list|(
name|dev_t
name|i_dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|arg
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mixer_hwvol_init
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mixer_hwvol_mute
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mixer_hwvol_step
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|left_step
parameter_list|,
name|int
name|right_step
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mix_setdevs
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mix_setrecdevs
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|mix_getdevs
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|mix_getrecdevs
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mix_getdevinfo
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * this is a kludge to allow hiding of the struct snd_mixer definition  * 512 should be enough for all architectures  */
end_comment

begin_define
define|#
directive|define
name|MIXER_SIZE
value|(512 + sizeof(struct kobj))
end_define

begin_define
define|#
directive|define
name|MIXER_DECLARE
parameter_list|(
name|name
parameter_list|)
value|DEFINE_CLASS(name, name ## _methods, MIXER_SIZE)
end_define

end_unit

