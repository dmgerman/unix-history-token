begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Data structures and definitions for dealing with the   * Common Access Method Transport (xpt) layer.  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_XPT_SIM_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_XPT_SIM_H
value|1
end_define

begin_include
include|#
directive|include
file|<cam/cam_xpt.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_queue.h>
end_include

begin_comment
comment|/* Functions accessed by SIM drivers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int32_t
name|xpt_bus_register
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|,
name|u_int32_t
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|xpt_bus_deregister
parameter_list|(
name|path_id_t
name|path_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|xpt_freeze_simq
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|,
name|u_int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_release_simq
parameter_list|(
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|,
name|int
name|run_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|xpt_freeze_devq
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
name|u_int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_release_devq
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
name|u_int
name|count
parameter_list|,
name|int
name|run_queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_done
parameter_list|(
name|union
name|ccb
modifier|*
name|done_ccb
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_CAM_XPT_SIM_H */
end_comment

end_unit

