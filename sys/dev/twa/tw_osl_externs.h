begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_OSL_EXTERNS_H
end_ifndef

begin_define
define|#
directive|define
name|TW_OSL_EXTERNS_H
end_define

begin_comment
comment|/*  * Data structures and functions global to the OS Layer.  */
end_comment

begin_comment
comment|/* External data structures. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mp_ncpus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in tw_osl_freebsd.c */
end_comment

begin_comment
comment|/* Build a firmware passthru cmd pkt, and submit it to CL. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osli_fw_passthru
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|,
name|TW_INT8
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get an OSL internal request context packet. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|tw_osli_req_context
modifier|*
name|tw_osli_get_request
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map data to DMA'able memory. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osli_map_request
parameter_list|(
name|struct
name|tw_osli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Undo mapping. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osli_unmap_request
parameter_list|(
name|struct
name|tw_osli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in tw_osl_cam.c */
end_comment

begin_comment
comment|/* Attach to CAM. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osli_cam_attach
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Detach from CAM. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osli_cam_detach
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Request CAM for a bus scan. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_osli_request_bus_scan
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Unfreeze ccb flow from CAM. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osli_allow_new_requests
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|,
name|TW_VOID
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Freeze ccb flow from CAM. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osli_disallow_new_requests
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* OSL's completion routine for SCSI I/O's. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_complete_io
parameter_list|(
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* OSL's completion routine for passthru requests. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_osl_complete_passthru
parameter_list|(
name|struct
name|tw_cl_req_handle
modifier|*
name|req_handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_EXTERNS_H */
end_comment

end_unit

