begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Generic driver definitions and exported functions for the Advanced  * Systems Inc. SCSI controllers  *   * Copyright (c) 1996-1997 Justin Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * All rights reserved.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ADVANSYS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ADVANSYS_H_
end_define

begin_include
include|#
directive|include
file|<dev/advansys/advlib.h>
end_include

begin_function_decl
name|struct
name|adv_softc
modifier|*
name|adv_alloc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|adv_name
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_map
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nseg
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_free
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_init
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|adv_attach
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|adv_done
parameter_list|(
name|struct
name|adv_softc
modifier|*
name|adv
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|u_int
name|done_stat
parameter_list|,
name|u_int
name|host_stat
parameter_list|,
name|u_int
name|scsi_stat
parameter_list|,
name|u_int
name|q_no
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|timeout_t
name|adv_timeout
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ADVANSYS_H_ */
end_comment

end_unit

