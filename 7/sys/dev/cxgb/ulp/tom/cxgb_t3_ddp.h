begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T3_DDP_H
end_ifndef

begin_define
define|#
directive|define
name|T3_DDP_H
end_define

begin_comment
comment|/* Should be 1 or 2 indicating single or double kernel buffers. */
end_comment

begin_define
define|#
directive|define
name|NUM_DDP_KBUF
value|2
end_define

begin_comment
comment|/* min receive window for a connection to be considered for DDP */
end_comment

begin_define
define|#
directive|define
name|MIN_DDP_RCV_WIN
value|(48<< 10)
end_define

begin_comment
comment|/* amount of Rx window not available to DDP to avoid window exhaustion */
end_comment

begin_define
define|#
directive|define
name|DDP_RSVD_WIN
value|(16<< 10)
end_define

begin_comment
comment|/* # of sentinel invalid page pods at the end of a group of valid page pods */
end_comment

begin_define
define|#
directive|define
name|NUM_SENTINEL_PPODS
value|0
end_define

begin_comment
comment|/* # of pages a pagepod can hold without needing another pagepod */
end_comment

begin_define
define|#
directive|define
name|PPOD_PAGES
value|4
end_define

begin_comment
comment|/* page pods are allocated in groups of this size (must be power of 2) */
end_comment

begin_define
define|#
directive|define
name|PPOD_CLUSTER_SIZE
value|16
end_define

begin_comment
comment|/* for each TID we reserve this many page pods up front */
end_comment

begin_define
define|#
directive|define
name|RSVD_PPODS_PER_TID
value|1
end_define

begin_struct
struct|struct
name|pagepod
block|{
name|uint32_t
name|pp_vld_tid
decl_stmt|;
name|uint32_t
name|pp_pgsz_tag_color
decl_stmt|;
name|uint32_t
name|pp_max_offset
decl_stmt|;
name|uint32_t
name|pp_page_offset
decl_stmt|;
name|uint64_t
name|pp_rsvd
decl_stmt|;
name|uint64_t
name|pp_addr
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PPOD_SIZE
value|sizeof(struct pagepod)
end_define

begin_define
define|#
directive|define
name|S_PPOD_TID
value|0
end_define

begin_define
define|#
directive|define
name|M_PPOD_TID
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_PPOD_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_TID)
end_define

begin_define
define|#
directive|define
name|S_PPOD_VALID
value|24
end_define

begin_define
define|#
directive|define
name|V_PPOD_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_VALID)
end_define

begin_define
define|#
directive|define
name|F_PPOD_VALID
value|V_PPOD_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_PPOD_COLOR
value|0
end_define

begin_define
define|#
directive|define
name|M_PPOD_COLOR
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_PPOD_COLOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_COLOR)
end_define

begin_define
define|#
directive|define
name|S_PPOD_TAG
value|6
end_define

begin_define
define|#
directive|define
name|M_PPOD_TAG
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_PPOD_TAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_TAG)
end_define

begin_define
define|#
directive|define
name|S_PPOD_PGSZ
value|30
end_define

begin_define
define|#
directive|define
name|M_PPOD_PGSZ
value|0x3
end_define

begin_define
define|#
directive|define
name|V_PPOD_PGSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PPOD_PGSZ)
end_define

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/* DDP gather lists can specify an offset only for the first page. */
end_comment

begin_struct
struct|struct
name|ddp_gather_list
block|{
name|unsigned
name|int
name|dgl_length
decl_stmt|;
name|unsigned
name|int
name|dgl_offset
decl_stmt|;
name|unsigned
name|int
name|dgl_nelem
decl_stmt|;
name|vm_page_t
name|dgl_pages
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ddp_buf_state
block|{
name|unsigned
name|int
name|cur_offset
decl_stmt|;
comment|/* offset of latest DDP notification */
name|unsigned
name|int
name|flags
decl_stmt|;
name|struct
name|ddp_gather_list
modifier|*
name|gl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ddp_state
block|{
name|struct
name|ddp_buf_state
name|buf_state
index|[
literal|2
index|]
decl_stmt|;
comment|/* per buffer state */
name|int
name|cur_buf
decl_stmt|;
name|unsigned
name|short
name|kbuf_noinval
decl_stmt|;
name|unsigned
name|short
name|kbuf_idx
decl_stmt|;
comment|/* which HW buffer is used for kbuf */
name|struct
name|ddp_gather_list
modifier|*
name|ubuf
decl_stmt|;
name|int
name|user_ddp_pending
decl_stmt|;
name|unsigned
name|int
name|ubuf_nppods
decl_stmt|;
comment|/* # of page pods for buffer 1 */
name|unsigned
name|int
name|ubuf_tag
decl_stmt|;
name|unsigned
name|int
name|ubuf_ddp_ready
decl_stmt|;
name|int
name|cancel_ubuf
decl_stmt|;
name|int
name|get_tcb_count
decl_stmt|;
name|unsigned
name|int
name|kbuf_posted
decl_stmt|;
name|unsigned
name|int
name|kbuf_nppods
index|[
name|NUM_DDP_KBUF
index|]
decl_stmt|;
name|unsigned
name|int
name|kbuf_tag
index|[
name|NUM_DDP_KBUF
index|]
decl_stmt|;
name|struct
name|ddp_gather_list
modifier|*
name|kbuf
index|[
name|NUM_DDP_KBUF
index|]
decl_stmt|;
comment|/* kernel buffer for DDP prefetch */
block|}
struct|;
end_struct

begin_comment
comment|/* buf_state flags */
end_comment

begin_enum
enum|enum
block|{
name|DDP_BF_NOINVAL
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* buffer is set to NO_INVALIDATE */
name|DDP_BF_NOCOPY
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* DDP to final dest, no copy needed */
name|DDP_BF_NOFLIP
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* buffer flips after GET_TCB_RPL */
name|DDP_BF_PSH
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* set in skb->flags if the a DDP was  	                              completed with a segment having the 				      PSH flag set */
name|DDP_BF_NODATA
init|=
literal|1
operator|<<
literal|4
block|,
comment|/* buffer completed before filling */
block|}
enum|;
end_enum

begin_include
include|#
directive|include
file|<dev/cxgb/ulp/tom/cxgb_toepcb.h>
end_include

begin_struct_decl
struct_decl|struct
name|sockbuf
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Returns 1 if a UBUF DMA buffer might be active.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|t3_ddp_ubuf_pending
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|)
block|{
name|struct
name|ddp_state
modifier|*
name|p
init|=
operator|&
name|toep
operator|->
name|tp_ddp_state
decl_stmt|;
comment|/* When the TOM_TUNABLE(ddp) is enabled, we're always in ULP_MODE DDP, 	 * but DDP_STATE() is only valid if the connection actually enabled 	 * DDP. 	 */
if|if
condition|(
name|p
operator|->
name|kbuf
index|[
literal|0
index|]
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|p
operator|->
name|buf_state
index|[
literal|0
index|]
operator|.
name|flags
operator|&
operator|(
name|DDP_BF_NOFLIP
operator||
name|DDP_BF_NOCOPY
operator|)
operator|)
operator|||
operator|(
name|p
operator|->
name|buf_state
index|[
literal|1
index|]
operator|.
name|flags
operator|&
operator|(
name|DDP_BF_NOFLIP
operator||
name|DDP_BF_NOCOPY
operator|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|int
name|t3_setup_ppods
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|,
specifier|const
name|struct
name|ddp_gather_list
modifier|*
name|gl
parameter_list|,
name|unsigned
name|int
name|nppods
parameter_list|,
name|unsigned
name|int
name|tag
parameter_list|,
name|unsigned
name|int
name|maxoff
parameter_list|,
name|unsigned
name|int
name|pg_off
parameter_list|,
name|unsigned
name|int
name|color
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_alloc_ppods
parameter_list|(
name|struct
name|tom_data
modifier|*
name|td
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|,
name|int
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_free_ppods
parameter_list|(
name|struct
name|tom_data
modifier|*
name|td
parameter_list|,
name|unsigned
name|int
name|tag
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_free_ddp_gl
parameter_list|(
name|struct
name|ddp_gather_list
modifier|*
name|gl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_ddp_copy
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|offset
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//void t3_repost_kbuf(struct socket *so, int modulate, int activate);
end_comment

begin_function_decl
name|void
name|t3_post_kbuf
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|,
name|int
name|modulate
parameter_list|,
name|int
name|nonblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_post_ubuf
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|,
specifier|const
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|nonblock
parameter_list|,
name|int
name|rcv_flags
parameter_list|,
name|int
name|modulate
parameter_list|,
name|int
name|post_kbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_cancel_ubuf
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|,
name|struct
name|sockbuf
modifier|*
name|rcv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_overlay_ubuf
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|,
name|struct
name|sockbuf
modifier|*
name|rcv
parameter_list|,
specifier|const
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|nonblock
parameter_list|,
name|int
name|rcv_flags
parameter_list|,
name|int
name|modulate
parameter_list|,
name|int
name|post_kbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_enter_ddp
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|,
name|unsigned
name|int
name|kbuf_size
parameter_list|,
name|unsigned
name|int
name|waitall
parameter_list|,
name|int
name|nonblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_cleanup_ddp
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_release_ddp_resources
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_cancel_ddpbuf
parameter_list|(
name|struct
name|toepcb
modifier|*
parameter_list|,
name|unsigned
name|int
name|bufidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_overlay_ddpbuf
parameter_list|(
name|struct
name|toepcb
modifier|*
parameter_list|,
name|unsigned
name|int
name|bufidx
parameter_list|,
name|unsigned
name|int
name|tag0
parameter_list|,
name|unsigned
name|int
name|tag1
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_setup_ddpbufs
parameter_list|(
name|struct
name|toepcb
modifier|*
parameter_list|,
name|unsigned
name|int
name|len0
parameter_list|,
name|unsigned
name|int
name|offset0
parameter_list|,
name|unsigned
name|int
name|len1
parameter_list|,
name|unsigned
name|int
name|offset1
parameter_list|,
name|uint64_t
name|ddp_flags
parameter_list|,
name|uint64_t
name|flag_mask
parameter_list|,
name|int
name|modulate
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T3_DDP_H */
end_comment

end_unit

