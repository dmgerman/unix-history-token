begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Data structures and definitions for linking CAM into the autoconf system.  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_CONF_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_CONF_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CAMCONF_UNSPEC
value|255
end_define

begin_define
define|#
directive|define
name|CAMCONF_ANY
value|254
end_define

begin_comment
comment|/*  * Macro that lets us know something is specified.  */
end_comment

begin_define
define|#
directive|define
name|IS_SPECIFIED
parameter_list|(
name|ARG
parameter_list|)
value|(ARG != CAMCONF_UNSPEC&& ARG != CAMCONF_ANY)
end_define

begin_struct
struct|struct
name|cam_sim_config
block|{
name|int
name|pathid
decl_stmt|;
name|char
modifier|*
name|sim_name
decl_stmt|;
name|int
name|sim_unit
decl_stmt|;
name|int
name|sim_bus
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cam_periph_config
block|{
name|char
modifier|*
name|periph_name
decl_stmt|;
name|int
name|periph_unit
decl_stmt|;
comment|/* desired device unit */
name|int
name|pathid
decl_stmt|;
comment|/* Controller unit */
name|int
name|target
decl_stmt|;
name|int
name|lun
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* Flags from config */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|cam_sim_config
name|cam_sinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cam_periph_config
name|cam_pinit
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_CAM_CONF_H */
end_comment

end_unit

