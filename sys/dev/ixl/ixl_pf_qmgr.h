begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_include
include|#
directive|include
file|"ixl_pf.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_IXL_PF_QMGR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXL_PF_QMGR_H_
end_define

begin_comment
comment|/*  * Primarily manages the queues that need to be allocated to VSIs.  *   * Cardinality: There should only be one of these in a PF.  * Lifetime: Created and initialized in attach(); destroyed in detach().  */
end_comment

begin_define
define|#
directive|define
name|IXL_MAX_SCATTERED_QUEUES
value|16
end_define

begin_define
define|#
directive|define
name|IXL_MAX_CONTIGUOUS_QUEUES_XL710
value|64
end_define

begin_define
define|#
directive|define
name|IXL_MAX_CONTIGUOUS_QUEUES_X722
value|128
end_define

begin_comment
comment|/* Structures */
end_comment

begin_comment
comment|/* Manager */
end_comment

begin_struct
struct|struct
name|ixl_pf_qmgr_qinfo
block|{
name|bool
name|allocated
decl_stmt|;
name|bool
name|tx_enabled
decl_stmt|;
name|bool
name|rx_enabled
decl_stmt|;
name|bool
name|tx_configured
decl_stmt|;
name|bool
name|rx_configured
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixl_pf_qmgr
block|{
name|u16
name|num_queues
decl_stmt|;
name|struct
name|ixl_pf_qmgr_qinfo
modifier|*
name|qinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Tag */
end_comment

begin_enum
enum|enum
name|ixl_pf_qmgr_qalloc_type
block|{
name|IXL_PF_QALLOC_CONTIGUOUS
block|,
name|IXL_PF_QALLOC_SCATTERED
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ixl_pf_qtag
block|{
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
decl_stmt|;
name|enum
name|ixl_pf_qmgr_qalloc_type
name|type
decl_stmt|;
name|u16
name|qidx
index|[
name|IXL_MAX_SCATTERED_QUEUES
index|]
decl_stmt|;
name|u16
name|num_allocated
decl_stmt|;
name|u16
name|num_active
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Public manager functions */
end_comment

begin_function_decl
name|int
name|ixl_pf_qmgr_init
parameter_list|(
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
parameter_list|,
name|u16
name|num_queues
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_pf_qmgr_destroy
parameter_list|(
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_pf_qmgr_get_num_queues
parameter_list|(
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_pf_qmgr_get_first_free
parameter_list|(
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
parameter_list|,
name|u16
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_pf_qmgr_get_num_free
parameter_list|(
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate queues for a VF VSI */
end_comment

begin_function_decl
name|int
name|ixl_pf_qmgr_alloc_scattered
parameter_list|(
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
parameter_list|,
name|u16
name|num
parameter_list|,
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate queues for the LAN VSIs, or X722 VF VSIs */
end_comment

begin_function_decl
name|int
name|ixl_pf_qmgr_alloc_contiguous
parameter_list|(
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
parameter_list|,
name|u16
name|num
parameter_list|,
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Release a queue allocation */
end_comment

begin_function_decl
name|int
name|ixl_pf_qmgr_release
parameter_list|(
name|struct
name|ixl_pf_qmgr
modifier|*
name|qmgr
parameter_list|,
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Help manage queues used in VFs */
end_comment

begin_comment
comment|/* Typically hardware refers to RX as 0 and TX as 1, so continue that convention here */
end_comment

begin_function_decl
name|void
name|ixl_pf_qmgr_mark_queue_enabled
parameter_list|(
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|,
name|u16
name|vsi_qidx
parameter_list|,
name|bool
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_pf_qmgr_mark_queue_disabled
parameter_list|(
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|,
name|u16
name|vsi_qidx
parameter_list|,
name|bool
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_pf_qmgr_mark_queue_configured
parameter_list|(
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|,
name|u16
name|vsi_qidx
parameter_list|,
name|bool
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ixl_pf_qmgr_is_queue_enabled
parameter_list|(
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|,
name|u16
name|vsi_qidx
parameter_list|,
name|bool
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ixl_pf_qmgr_is_queue_configured
parameter_list|(
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|,
name|u16
name|vsi_qidx
parameter_list|,
name|bool
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Public tag functions */
end_comment

begin_function_decl
name|u16
name|ixl_pf_qidx_from_vsi_qidx
parameter_list|(
name|struct
name|ixl_pf_qtag
modifier|*
name|qtag
parameter_list|,
name|u16
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXL_PF_QMGR_H_ */
end_comment

end_unit

