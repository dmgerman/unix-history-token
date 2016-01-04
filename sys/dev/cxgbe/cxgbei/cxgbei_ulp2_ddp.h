begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Chelsio Communications, Inc.  * All rights reserved.  *  * Chelsio T5xx iSCSI driver  * cxgbei_ulp2_ddp.c: Chelsio iSCSI DDP Manager.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CXGBEI_ULP2_DDP_H__
end_ifndef

begin_define
define|#
directive|define
name|__CXGBEI_ULP2_DDP_H__
end_define

begin_define
define|#
directive|define
name|CXGBEI_PAGE_MASK
value|(~(PAGE_SIZE-1))
end_define

begin_define
define|#
directive|define
name|DDP_THRESHOLD
value|2048
end_define

begin_comment
comment|/*  * cxgbei ddp tag are 32 bits, it consists of reserved bits used by h/w and  * non-reserved bits that can be used by the iscsi s/w.  * The reserved bits are identified by the rsvd_bits and rsvd_shift fields  * in struct cxgbei_ulp2_tag_format.  *  * The upper most reserved bit can be used to check if a tag is ddp tag or not:  * 	if the bit is 0, the tag is a valid ddp tag  */
end_comment

begin_comment
comment|/*  * cxgbei_ulp2_is_ddp_tag - check if a given tag is a hw/ddp tag  * @tformat: tag format information  * @tag: tag to be checked  *  * return true if the tag is a ddp tag, false otherwise.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|cxgbei_ulp2_is_ddp_tag
parameter_list|(
name|struct
name|cxgbei_ulp2_tag_format
modifier|*
name|tformat
parameter_list|,
name|uint32_t
name|tag
parameter_list|)
block|{
return|return
operator|(
operator|!
operator|(
name|tag
operator|&
operator|(
literal|1
operator|<<
operator|(
name|tformat
operator|->
name|rsvd_bits
operator|+
name|tformat
operator|->
name|rsvd_shift
operator|-
literal|1
operator|)
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * cxgbei_ulp2_sw_tag_usable - check if s/w tag has enough bits left for hw bits  * @tformat: tag format information  * @sw_tag: s/w tag to be checked  *  * return true if the tag can be used for hw ddp tag, false otherwise.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|cxgbei_ulp2_sw_tag_usable
parameter_list|(
name|struct
name|cxgbei_ulp2_tag_format
modifier|*
name|tformat
parameter_list|,
name|uint32_t
name|sw_tag
parameter_list|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
comment|/* XXXNP: huh? */
name|sw_tag
operator|>>=
operator|(
literal|32
operator|-
name|tformat
operator|->
name|rsvd_bits
operator|+
name|tformat
operator|->
name|rsvd_shift
operator|)
expr_stmt|;
return|return
operator|!
name|sw_tag
return|;
block|}
end_function

begin_comment
comment|/*  * cxgbei_ulp2_set_non_ddp_tag - mark a given s/w tag as an invalid ddp tag  * @tformat: tag format information  * @sw_tag: s/w tag to be checked  *  * insert 1 at the upper most reserved bit to mark it as an invalid ddp tag.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|cxgbei_ulp2_set_non_ddp_tag
parameter_list|(
name|struct
name|cxgbei_ulp2_tag_format
modifier|*
name|tformat
parameter_list|,
name|uint32_t
name|sw_tag
parameter_list|)
block|{
name|uint32_t
name|rsvd_bits
init|=
name|tformat
operator|->
name|rsvd_bits
operator|+
name|tformat
operator|->
name|rsvd_shift
decl_stmt|;
if|if
condition|(
name|sw_tag
condition|)
block|{
name|u32
name|v1
init|=
name|sw_tag
operator|&
operator|(
operator|(
literal|1
operator|<<
operator|(
name|rsvd_bits
operator|-
literal|1
operator|)
operator|)
operator|-
literal|1
operator|)
decl_stmt|;
name|u32
name|v2
init|=
operator|(
name|sw_tag
operator|>>
operator|(
name|rsvd_bits
operator|-
literal|1
operator|)
operator|)
operator|<<
name|rsvd_bits
decl_stmt|;
return|return
name|v2
operator||
operator|(
literal|1
operator|<<
operator|(
name|rsvd_bits
operator|-
literal|1
operator|)
operator|)
operator||
name|v1
return|;
block|}
return|return
name|sw_tag
operator||
operator|(
literal|1
operator|<<
operator|(
name|rsvd_bits
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|dma_segments
block|{
name|bus_dmamap_t
name|bus_map
decl_stmt|;
name|bus_addr_t
name|phys_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct cxgbei_ulp2_gather_list - cxgbei direct data placement memory  *  * @tag:	ddp tag  * @length:	total data buffer length  * @offset:	initial offset to the 1st page  * @nelem:	# of pages  * @pages:	page pointers  * @phys_addr:	physical address  */
end_comment

begin_struct
struct|struct
name|cxgbei_ulp2_gather_list
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|tid
decl_stmt|;
name|uint32_t
name|port_id
decl_stmt|;
name|void
modifier|*
name|egress_dev
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|nelem
decl_stmt|;
name|bus_size_t
name|mapsize
decl_stmt|;
name|bus_dmamap_t
name|bus_map
decl_stmt|;
name|bus_dma_segment_t
modifier|*
name|segments
decl_stmt|;
name|void
modifier|*
modifier|*
name|pages
decl_stmt|;
name|struct
name|dma_segments
name|dma_sg
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPPOD_SIZE
value|sizeof(struct cxgbei_ulp2_pagepod)
end_define

begin_comment
comment|/* 64 */
end_comment

begin_define
define|#
directive|define
name|IPPOD_SIZE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|IPPOD_COLOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IPPOD_COLOR_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|IPPOD_COLOR_MASK
value|((1<< IPPOD_COLOR_SIZE) - 1)
end_define

begin_define
define|#
directive|define
name|IPPOD_IDX_SHIFT
value|IPPOD_COLOR_SIZE
end_define

begin_define
define|#
directive|define
name|IPPOD_IDX_MAX_SIZE
value|24
end_define

begin_define
define|#
directive|define
name|S_IPPOD_TID
value|0
end_define

begin_define
define|#
directive|define
name|M_IPPOD_TID
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_IPPOD_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_IPPOD_TID)
end_define

begin_define
define|#
directive|define
name|S_IPPOD_VALID
value|24
end_define

begin_define
define|#
directive|define
name|V_IPPOD_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_IPPOD_VALID)
end_define

begin_define
define|#
directive|define
name|F_IPPOD_VALID
value|V_IPPOD_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_IPPOD_COLOR
value|0
end_define

begin_define
define|#
directive|define
name|M_IPPOD_COLOR
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_IPPOD_COLOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_IPPOD_COLOR)
end_define

begin_define
define|#
directive|define
name|S_IPPOD_TAG
value|6
end_define

begin_define
define|#
directive|define
name|M_IPPOD_TAG
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_IPPOD_TAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_IPPOD_TAG)
end_define

begin_define
define|#
directive|define
name|S_IPPOD_PGSZ
value|30
end_define

begin_define
define|#
directive|define
name|M_IPPOD_PGSZ
value|0x3
end_define

begin_define
define|#
directive|define
name|V_IPPOD_PGSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_IPPOD_PGSZ)
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|cxgbei_ulp2_ddp_tag_base
parameter_list|(
name|u_int
name|idx
parameter_list|,
name|u_char
modifier|*
name|colors
parameter_list|,
name|struct
name|cxgbei_ulp2_tag_format
modifier|*
name|tformat
parameter_list|,
name|uint32_t
name|sw_tag
parameter_list|)
block|{
if|if
condition|(
name|__predict_false
argument_list|(
operator|++
name|colors
index|[
name|idx
index|]
operator|==
literal|1
operator|<<
name|IPPOD_IDX_SHIFT
argument_list|)
condition|)
name|colors
index|[
name|idx
index|]
operator|=
literal|0
expr_stmt|;
name|sw_tag
operator|<<=
name|tformat
operator|->
name|rsvd_bits
operator|+
name|tformat
operator|->
name|rsvd_shift
expr_stmt|;
return|return
operator|(
name|sw_tag
operator||
name|idx
operator|<<
name|IPPOD_IDX_SHIFT
operator||
name|colors
index|[
name|idx
index|]
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ISCSI_PDU_NONPAYLOAD_LEN
value|312
end_define

begin_comment
comment|/* bhs(48) + ahs(256) + digest(8) */
end_comment

begin_comment
comment|/*  * align pdu size to multiple of 512 for better performance  */
end_comment

begin_define
define|#
directive|define
name|cxgbei_align_pdu_size
parameter_list|(
name|n
parameter_list|)
value|do { n = (n)& (~511); } while (0)
end_define

begin_define
define|#
directive|define
name|ULP2_MAX_PKT_SIZE
value|16224
end_define

begin_define
define|#
directive|define
name|ULP2_MAX_PDU_PAYLOAD
value|(ULP2_MAX_PKT_SIZE - ISCSI_PDU_NONPAYLOAD_LEN)
end_define

begin_define
define|#
directive|define
name|IPPOD_PAGES_MAX
value|4
end_define

begin_define
define|#
directive|define
name|IPPOD_PAGES_SHIFT
value|2
end_define

begin_comment
comment|/* 4 pages per pod */
end_comment

begin_comment
comment|/*  * struct pagepod_hdr, pagepod - pagepod format  */
end_comment

begin_struct
struct|struct
name|cxgbei_ulp2_pagepod_hdr
block|{
name|uint32_t
name|vld_tid
decl_stmt|;
name|uint32_t
name|pgsz_tag_clr
decl_stmt|;
name|uint32_t
name|maxoffset
decl_stmt|;
name|uint32_t
name|pgoffset
decl_stmt|;
name|uint64_t
name|rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cxgbei_ulp2_pagepod
block|{
name|struct
name|cxgbei_ulp2_pagepod_hdr
name|hdr
decl_stmt|;
name|uint64_t
name|addr
index|[
name|IPPOD_PAGES_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|cxgbei_ulp2_ddp_tag_reserve
parameter_list|(
name|struct
name|cxgbei_data
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|struct
name|cxgbei_ulp2_tag_format
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|struct
name|cxgbei_ulp2_gather_list
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
name|cxgbei_ulp2_ddp_tag_release
parameter_list|(
name|struct
name|cxgbei_data
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|icl_cxgbei_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cxgbei_ulp2_gather_list
modifier|*
name|cxgbei_ulp2_ddp_make_gl_from_iscsi_sgvec
parameter_list|(
name|u_int
parameter_list|,
name|struct
name|cxgbei_sgl
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|cxgbei_data
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cxgbei_ulp2_ddp_release_gl
parameter_list|(
name|struct
name|cxgbei_data
modifier|*
parameter_list|,
name|struct
name|cxgbei_ulp2_gather_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cxgbei_ulp2_ddp_find_page_index
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cxgbei_ulp2_adapter_ddp_info
parameter_list|(
name|struct
name|cxgbei_data
modifier|*
parameter_list|,
name|struct
name|cxgbei_ulp2_tag_format
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cxgbei_ddp_cleanup
parameter_list|(
name|struct
name|cxgbei_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

