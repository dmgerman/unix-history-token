begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Data structures and definitions for dealing with the   * Common Access Method Transport (xpt) layer from peripheral  * drivers.  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_XPT_PERIPH_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_XPT_PERIPH_H
value|1
end_define

begin_include
include|#
directive|include
file|<cam/cam_xpt.h>
end_include

begin_comment
comment|/* Functions accessed by the peripheral drivers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|xpt_polled_action
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|ccb
modifier|*
name|xpt_alloc_ccb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|ccb
modifier|*
name|xpt_alloc_ccb_nowait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_free_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|free_ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_release_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|released_ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_schedule
parameter_list|(
name|struct
name|cam_periph
modifier|*
name|perph
parameter_list|,
name|u_int32_t
name|new_priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|xpt_add_periph
parameter_list|(
name|struct
name|cam_periph
modifier|*
name|periph
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_remove_periph
parameter_list|(
name|struct
name|cam_periph
modifier|*
name|periph
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_announce_periph
parameter_list|(
name|struct
name|cam_periph
modifier|*
name|periph
parameter_list|,
name|char
modifier|*
name|announce_string
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
comment|/* _CAM_CAM_XPT_PERIPH_H */
end_comment

end_unit

