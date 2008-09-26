begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * blkif.h  *   * Unified block-device I/O interface for Xen guest OSes.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2003-2004, Keir Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_BLKIF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_BLKIF_H__
end_define

begin_include
include|#
directive|include
file|<xen/interface/io/ring.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/grant_table.h>
end_include

begin_comment
comment|/*  * Front->back notifications: When enqueuing a new request, sending a  * notification can be made conditional on req_event (i.e., the generic  * hold-off mechanism provided by the ring macros). Backends must set  * req_event appropriately (e.g., using RING_FINAL_CHECK_FOR_REQUESTS()).  *   * Back->front notifications: When enqueuing a new response, sending a  * notification can be made conditional on rsp_event (i.e., the generic  * hold-off mechanism provided by the ring macros). Frontends must set  * rsp_event appropriately (e.g., using RING_FINAL_CHECK_FOR_RESPONSES()).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|blkif_vdev_t
end_ifndef

begin_define
define|#
directive|define
name|blkif_vdev_t
value|uint16_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|blkif_sector_t
value|uint64_t
end_define

begin_comment
comment|/*  * REQUEST CODES.  */
end_comment

begin_define
define|#
directive|define
name|BLKIF_OP_READ
value|0
end_define

begin_define
define|#
directive|define
name|BLKIF_OP_WRITE
value|1
end_define

begin_comment
comment|/*  * Recognised only if "feature-barrier" is present in backend xenbus info.  * The "feature-barrier" node contains a boolean indicating whether barrier  * requests are likely to succeed or fail. Either way, a barrier request  * may fail at any time with BLKIF_RSP_EOPNOTSUPP if it is unsupported by  * the underlying block-device hardware. The boolean simply indicates whether  * or not it is worthwhile for the frontend to attempt barrier requests.  * If a backend does not recognise BLKIF_OP_WRITE_BARRIER, it should *not*  * create the "feature-barrier" node!  */
end_comment

begin_define
define|#
directive|define
name|BLKIF_OP_WRITE_BARRIER
value|2
end_define

begin_comment
comment|/*  * Recognised if "feature-flush-cache" is present in backend xenbus  * info.  A flush will ask the underlying storage hardware to flush its  * non-volatile caches as appropriate.  The "feature-flush-cache" node  * contains a boolean indicating whether flush requests are likely to  * succeed or fail. Either way, a flush request may fail at any time  * with BLKIF_RSP_EOPNOTSUPP if it is unsupported by the underlying  * block-device hardware. The boolean simply indicates whether or not it  * is worthwhile for the frontend to attempt flushes.  If a backend does  * not recognise BLKIF_OP_WRITE_FLUSH_CACHE, it should *not* create the  * "feature-flush-cache" node!  */
end_comment

begin_define
define|#
directive|define
name|BLKIF_OP_FLUSH_DISKCACHE
value|3
end_define

begin_comment
comment|/*  * Maximum scatter/gather segments per request.  * This is carefully chosen so that sizeof(blkif_ring_t)<= PAGE_SIZE.  * NB. This could be 12 if the ring indexes weren't stored in the same page.  */
end_comment

begin_define
define|#
directive|define
name|BLKIF_MAX_SEGMENTS_PER_REQUEST
value|11
end_define

begin_struct
struct|struct
name|blkif_request_segment
block|{
name|grant_ref_t
name|gref
decl_stmt|;
comment|/* reference to I/O buffer frame        */
comment|/* @first_sect: first sector in frame to transfer (inclusive).   */
comment|/* @last_sect: last sector in frame to transfer (inclusive).     */
name|uint8_t
name|first_sect
decl_stmt|,
name|last_sect
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|blkif_request
block|{
name|uint8_t
name|operation
decl_stmt|;
comment|/* BLKIF_OP_???                         */
name|uint8_t
name|nr_segments
decl_stmt|;
comment|/* number of segments                   */
name|blkif_vdev_t
name|handle
decl_stmt|;
comment|/* only for read/write requests         */
name|uint64_t
name|id
decl_stmt|;
comment|/* private guest value, echoed in resp  */
name|blkif_sector_t
name|sector_number
decl_stmt|;
comment|/* start sector idx on disk (r/w only)  */
name|struct
name|blkif_request_segment
name|seg
index|[
name|BLKIF_MAX_SEGMENTS_PER_REQUEST
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|blkif_request
name|blkif_request_t
typedef|;
end_typedef

begin_struct
struct|struct
name|blkif_response
block|{
name|uint64_t
name|id
decl_stmt|;
comment|/* copied from request */
name|uint8_t
name|operation
decl_stmt|;
comment|/* copied from request */
name|int16_t
name|status
decl_stmt|;
comment|/* BLKIF_RSP_???       */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|blkif_response
name|blkif_response_t
typedef|;
end_typedef

begin_comment
comment|/*  * STATUS RETURN CODES.  */
end_comment

begin_comment
comment|/* Operation not supported (only happens on barrier writes). */
end_comment

begin_define
define|#
directive|define
name|BLKIF_RSP_EOPNOTSUPP
value|-2
end_define

begin_comment
comment|/* Operation failed for some unspecified reason (-EIO). */
end_comment

begin_define
define|#
directive|define
name|BLKIF_RSP_ERROR
value|-1
end_define

begin_comment
comment|/* Operation completed successfully. */
end_comment

begin_define
define|#
directive|define
name|BLKIF_RSP_OKAY
value|0
end_define

begin_comment
comment|/*  * Generate blkif ring structures and types.  */
end_comment

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|blkif
argument_list|,
expr|struct
name|blkif_request
argument_list|,
expr|struct
name|blkif_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VDISK_CDROM
value|0x1
end_define

begin_define
define|#
directive|define
name|VDISK_REMOVABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|VDISK_READONLY
value|0x4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_IO_BLKIF_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

