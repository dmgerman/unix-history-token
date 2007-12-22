begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Cameron Grant<cg@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_function_decl
name|struct
name|snd_mixer
modifier|*
name|mixer_create
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
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mixer_delete
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

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
name|mixer_ioctl_cmd
parameter_list|(
name|struct
name|cdev
modifier|*
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
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mixer_oss_mixerinfo
parameter_list|(
name|struct
name|cdev
modifier|*
name|i_dev
parameter_list|,
name|oss_mixerinfo
modifier|*
name|mi
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
name|int
name|mixer_busy
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mix_set
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int
name|dev
parameter_list|,
name|u_int
name|left
parameter_list|,
name|u_int
name|right
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mix_get
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mix_setrecsrc
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int32_t
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|mix_getrecsrc
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mix_get_type
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
name|mix_setparentchild
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int32_t
name|parent
parameter_list|,
name|u_int32_t
name|childs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mix_setrealdev
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int32_t
name|dev
parameter_list|,
name|u_int32_t
name|realdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|mix_getparent
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int32_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|mix_getchild
parameter_list|(
name|struct
name|snd_mixer
modifier|*
name|m
parameter_list|,
name|u_int32_t
name|dev
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

begin_decl_stmt
specifier|extern
name|int
name|mixer_count
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MIXER_CMD_DIRECT
value|0
end_define

begin_comment
comment|/* send command within driver   */
end_comment

begin_define
define|#
directive|define
name|MIXER_CMD_CDEV
value|1
end_define

begin_comment
comment|/* send command from cdev/ioctl */
end_comment

begin_define
define|#
directive|define
name|MIXER_TYPE_PRIMARY
value|0
end_define

begin_comment
comment|/* mixer_init()   */
end_comment

begin_define
define|#
directive|define
name|MIXER_TYPE_SECONDARY
value|1
end_define

begin_comment
comment|/* mixer_create() */
end_comment

begin_comment
comment|/*  * this is a kludge to allow hiding of the struct snd_mixer definition  * 512 should be enough for all architectures  */
end_comment

begin_define
define|#
directive|define
name|MIXER_SIZE
value|(512 + sizeof(struct kobj) +		\ 			    sizeof(oss_mixer_enuminfo))
end_define

begin_define
define|#
directive|define
name|MIXER_DECLARE
parameter_list|(
name|name
parameter_list|)
value|static DEFINE_CLASS(name, name ## _methods, MIXER_SIZE)
end_define

end_unit

