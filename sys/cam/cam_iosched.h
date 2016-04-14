begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * CAM IO Scheduler Interface  *  * Copyright (c) 2015 Netflix, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_IOSCHED_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_IOSCHED_H
end_define

begin_comment
comment|/* No user-servicable parts in here. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Forward declare all structs to keep interface thin */
end_comment

begin_struct_decl
struct_decl|struct
name|cam_iosched_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_ctx_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_oid
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|ccb
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|cam_iosched_init
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
modifier|*
parameter_list|,
name|struct
name|cam_periph
modifier|*
name|periph
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_fini
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_sysctl_init
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
parameter_list|,
name|struct
name|sysctl_ctx_list
modifier|*
parameter_list|,
name|struct
name|sysctl_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bio
modifier|*
name|cam_iosched_next_trim
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bio
modifier|*
name|cam_iosched_get_trim
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bio
modifier|*
name|cam_iosched_next_bio
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_queue_work
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_flush
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|struct
name|devstat
modifier|*
name|stp
parameter_list|,
name|int
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_schedule
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|struct
name|cam_periph
modifier|*
name|periph
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_finish_trim
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_submit_trim
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_put_back_trim
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_set_sort_queue
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cam_iosched_has_work_flags
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_set_work_flags
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_clr_work_flags
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cam_iosched_trim_done
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cam_iosched_bio_complete
parameter_list|(
name|struct
name|cam_iosched_softc
modifier|*
name|isc
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
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

end_unit

