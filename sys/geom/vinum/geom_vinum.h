begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Lukas Ertl  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEOM_VINUM_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEOM_VINUM_H_
end_define

begin_define
define|#
directive|define
name|ERRBUFSIZ
value|1024
end_define

begin_comment
comment|/* geom_vinum_drive.c */
end_comment

begin_function_decl
name|void
name|gv_save_config_all
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_save_config
parameter_list|(
name|struct
name|g_consumer
modifier|*
parameter_list|,
name|struct
name|gv_drive
modifier|*
parameter_list|,
name|struct
name|gv_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* geom_vinum_init.c */
end_comment

begin_function_decl
name|void
name|gv_start_obj
parameter_list|(
name|struct
name|g_geom
modifier|*
parameter_list|,
name|struct
name|gctl_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* geom_vinum_list.c */
end_comment

begin_function_decl
name|void
name|gv_ld
parameter_list|(
name|struct
name|g_geom
modifier|*
parameter_list|,
name|struct
name|gctl_req
modifier|*
parameter_list|,
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_lp
parameter_list|(
name|struct
name|g_geom
modifier|*
parameter_list|,
name|struct
name|gctl_req
modifier|*
parameter_list|,
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_ls
parameter_list|(
name|struct
name|g_geom
modifier|*
parameter_list|,
name|struct
name|gctl_req
modifier|*
parameter_list|,
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_lv
parameter_list|(
name|struct
name|g_geom
modifier|*
parameter_list|,
name|struct
name|gctl_req
modifier|*
parameter_list|,
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_list
parameter_list|(
name|struct
name|g_geom
modifier|*
parameter_list|,
name|struct
name|gctl_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* geom_vinum_rm.c */
end_comment

begin_function_decl
name|void
name|gv_remove
parameter_list|(
name|struct
name|g_geom
modifier|*
parameter_list|,
name|struct
name|gctl_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* geom_vinum_state.c */
end_comment

begin_function_decl
name|int
name|gv_sdstatemap
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_set_drive_state
parameter_list|(
name|struct
name|gv_drive
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_set_sd_state
parameter_list|(
name|struct
name|gv_sd
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_update_sd_state
parameter_list|(
name|struct
name|gv_sd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_update_plex_state
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_update_vol_state
parameter_list|(
name|struct
name|gv_volume
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* geom_vinum_subr.c */
end_comment

begin_function_decl
name|void
name|gv_adjust_freespace
parameter_list|(
name|struct
name|gv_sd
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|g_geom
modifier|*
name|find_vinum_geom
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gv_drive
modifier|*
name|gv_find_drive
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gv_plex
modifier|*
name|gv_find_plex
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gv_sd
modifier|*
name|gv_find_sd
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gv_volume
modifier|*
name|gv_find_vol
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_format_config
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|,
name|struct
name|sbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_is_striped
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_is_open
parameter_list|(
name|struct
name|g_geom
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_kill_thread
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_object_type
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_parse_config
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|gv_roughlength
parameter_list|(
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_sd_to_drive
parameter_list|(
name|struct
name|gv_softc
modifier|*
parameter_list|,
name|struct
name|gv_drive
modifier|*
parameter_list|,
name|struct
name|gv_sd
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gv_sd_to_plex
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|,
name|struct
name|gv_sd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_update_plex_config
parameter_list|(
name|struct
name|gv_plex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gv_update_vol_size
parameter_list|(
name|struct
name|gv_volume
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GEOM_VINUM_H_ */
end_comment

end_unit

