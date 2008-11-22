begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Data structures and definitions for dealing with the   * Common Access Method Transport (xpt) layer.  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_XPT_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_XPT_H
value|1
end_define

begin_comment
comment|/* Forward Declarations */
end_comment

begin_union_decl
union_decl|union
name|ccb
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|cam_periph
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cam_sim
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Definition of a CAM path.  Paths are created from bus, target, and lun ids  * via xpt_create_path and allow for reference to devices without recurring  * lookups in the edt.  */
end_comment

begin_struct_decl
struct_decl|struct
name|cam_path
struct_decl|;
end_struct_decl

begin_comment
comment|/* Path functions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|xpt_action
parameter_list|(
name|union
name|ccb
modifier|*
name|new_ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_setup_ccb
parameter_list|(
name|struct
name|ccb_hdr
modifier|*
name|ccb_h
parameter_list|,
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
name|u_int32_t
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_merge_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|master_ccb
parameter_list|,
name|union
name|ccb
modifier|*
name|slave_ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cam_status
name|xpt_create_path
parameter_list|(
name|struct
name|cam_path
modifier|*
modifier|*
name|new_path_ptr
parameter_list|,
name|struct
name|cam_periph
modifier|*
name|perph
parameter_list|,
name|path_id_t
name|path_id
parameter_list|,
name|target_id_t
name|target_id
parameter_list|,
name|lun_id_t
name|lun_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_free_path
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xpt_path_comp
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path1
parameter_list|,
name|struct
name|cam_path
modifier|*
name|path2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_print_path
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_print
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xpt_path_string
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|path_id_t
name|xpt_path_path_id
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|target_id_t
name|xpt_path_target_id
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lun_id_t
name|xpt_path_lun_id
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cam_sim
modifier|*
name|xpt_path_sim
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cam_periph
modifier|*
name|xpt_path_periph
parameter_list|(
name|struct
name|cam_path
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_async
parameter_list|(
name|u_int32_t
name|async_code
parameter_list|,
name|struct
name|cam_path
modifier|*
name|path
parameter_list|,
name|void
modifier|*
name|async_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpt_rescan
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_CAM_XPT_H */
end_comment

end_unit

