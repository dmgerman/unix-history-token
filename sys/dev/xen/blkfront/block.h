begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * XenBSD block device driver  *  * Copyright (c) 2010-2013 Spectra Logic Corporation  * Copyright (c) 2009 Scott Long, Yahoo!  * Copyright (c) 2009 Frank Suchomel, Citrix  * Copyright (c) 2009 Doug F. Rabson, Citrix  * Copyright (c) 2005 Kip Macy  * Copyright (c) 2003-2004, Keir Fraser& Steve Hand  * Modifications by Mark A. Williamson are (c) Intel Research Cambridge  *  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_BLKFRONT_BLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_BLKFRONT_BLOCK_H__
end_define

begin_include
include|#
directive|include
file|<xen/blkif.h>
end_include

begin_comment
comment|/**  * Given a number of blkif segments, compute the maximum I/O size supported.  *  * \note This calculation assumes that all but the first and last segments   *       of the I/O are fully utilized.  *  * \note We reserve a segement from the maximum supported by the transport to  *       guarantee we can handle an unaligned transfer without the need to  *       use a bounce buffer.  */
end_comment

begin_define
define|#
directive|define
name|XBD_SEGS_TO_SIZE
parameter_list|(
name|segs
parameter_list|)
define|\
value|(((segs) - 1) * PAGE_SIZE)
end_define

begin_comment
comment|/**  * Compute the maximum number of blkif segments requried to represent  * an I/O of the given size.  *  * \note This calculation assumes that all but the first and last segments  *       of the I/O are fully utilized.  *  * \note We reserve a segement to guarantee we can handle an unaligned  *       transfer without the need to use a bounce buffer.  */
end_comment

begin_define
define|#
directive|define
name|XBD_SIZE_TO_SEGS
parameter_list|(
name|size
parameter_list|)
define|\
value|((size / PAGE_SIZE) + 1)
end_define

begin_comment
comment|/**  * The maximum number of outstanding requests blocks (request headers plus  * additional segment blocks) we will allow in a negotiated block-front/back  * communication channel.  */
end_comment

begin_define
define|#
directive|define
name|XBD_MAX_REQUESTS
value|256
end_define

begin_comment
comment|/**  * The maximum mapped region size per request we will allow in a negotiated  * block-front/back communication channel.  */
end_comment

begin_define
define|#
directive|define
name|XBD_MAX_REQUEST_SIZE
define|\
value|MIN(MAXPHYS, XBD_SEGS_TO_SIZE(BLKIF_MAX_SEGMENTS_PER_REQUEST))
end_define

begin_comment
comment|/**  * The maximum number of segments (within a request header and accompanying  * segment blocks) per request we will allow in a negotiated block-front/back  * communication channel.  */
end_comment

begin_define
define|#
directive|define
name|XBD_MAX_SEGMENTS_PER_REQUEST
define|\
value|(MIN(BLKIF_MAX_SEGMENTS_PER_REQUEST,				\ 	     XBD_SIZE_TO_SEGS(XBD_MAX_REQUEST_SIZE)))
end_define

begin_comment
comment|/**  * The maximum number of shared memory ring pages we will allow in a  * negotiated block-front/back communication channel.  Allow enough  * ring space for all requests to be  XBD_MAX_REQUEST_SIZE'd.  */
end_comment

begin_define
define|#
directive|define
name|XBD_MAX_RING_PAGES
define|\
value|BLKIF_RING_PAGES(BLKIF_SEGS_TO_BLOCKS(XBD_MAX_SEGMENTS_PER_REQUEST) \ 		       * XBD_MAX_REQUESTS)
end_define

begin_struct_decl
struct_decl|struct
name|xbd_command
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|xbd_cbcf_t
parameter_list|(
name|struct
name|xbd_command
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|xbd_command
block|{
name|TAILQ_ENTRY
argument_list|(
argument|xbd_command
argument_list|)
name|cm_link
expr_stmt|;
name|struct
name|xbd_softc
modifier|*
name|cm_sc
decl_stmt|;
name|u_int
name|cm_flags
decl_stmt|;
define|#
directive|define
name|XBD_CMD_FROZEN
value|(1<<0)
define|#
directive|define
name|XBD_CMD_POLLED
value|(1<<1)
define|#
directive|define
name|XBD_ON_XBDQ_FREE
value|(1<<2)
define|#
directive|define
name|XBD_ON_XBDQ_READY
value|(1<<3)
define|#
directive|define
name|XBD_ON_XBDQ_BUSY
value|(1<<4)
define|#
directive|define
name|XBD_ON_XBDQ_COMPLETE
value|(1<<5)
define|#
directive|define
name|XBD_ON_XBDQ_MASK
value|((1<<2)|(1<<3)|(1<<4)|(1<<5))
name|bus_dmamap_t
name|cm_map
decl_stmt|;
name|uint64_t
name|cm_id
decl_stmt|;
name|grant_ref_t
modifier|*
name|cm_sg_refs
decl_stmt|;
name|struct
name|bio
modifier|*
name|cm_bp
decl_stmt|;
name|grant_ref_t
name|cm_gref_head
decl_stmt|;
name|void
modifier|*
name|cm_data
decl_stmt|;
name|size_t
name|cm_datalen
decl_stmt|;
name|u_int
name|cm_nseg
decl_stmt|;
name|int
name|cm_operation
decl_stmt|;
name|blkif_sector_t
name|cm_sector_number
decl_stmt|;
name|int
name|cm_status
decl_stmt|;
name|xbd_cbcf_t
modifier|*
name|cm_complete
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XBDQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|XBDQ_BIO
value|1
end_define

begin_define
define|#
directive|define
name|XBDQ_READY
value|2
end_define

begin_define
define|#
directive|define
name|XBDQ_BUSY
value|3
end_define

begin_define
define|#
directive|define
name|XBDQ_COMPLETE
value|4
end_define

begin_define
define|#
directive|define
name|XBDQ_COUNT
value|5
end_define

begin_struct
struct|struct
name|xbd_qstat
block|{
name|uint32_t
name|q_length
decl_stmt|;
name|uint32_t
name|q_max
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|xbd_statrequest
block|{
name|uint32_t
name|ms_item
decl_stmt|;
name|struct
name|xbd_qstat
name|ms_qstat
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * We have one of these per vbd, whether ide, scsi or 'other'.  */
end_comment

begin_struct
struct|struct
name|xbd_softc
block|{
name|device_t
name|xbd_dev
decl_stmt|;
name|struct
name|disk
modifier|*
name|xbd_disk
decl_stmt|;
comment|/* disk params */
name|struct
name|bio_queue_head
name|xbd_bioq
decl_stmt|;
comment|/* sort queue */
name|int
name|xbd_unit
decl_stmt|;
name|int
name|xbd_flags
decl_stmt|;
define|#
directive|define
name|XBD_OPEN
value|(1<<0)
comment|/* drive is open (can't shut down) */
define|#
directive|define
name|XBD_BARRIER
value|(1<< 1)
comment|/* backend supports barriers */
define|#
directive|define
name|XBD_READY
value|(1<< 2)
comment|/* Is ready */
define|#
directive|define
name|XBD_FROZEN
value|(1<< 3)
comment|/* Waiting for resources */
name|int
name|xbd_vdevice
decl_stmt|;
name|int
name|xbd_connected
decl_stmt|;
name|u_int
name|xbd_ring_pages
decl_stmt|;
name|uint32_t
name|xbd_max_requests
decl_stmt|;
name|uint32_t
name|xbd_max_request_segments
decl_stmt|;
name|uint32_t
name|xbd_max_request_blocks
decl_stmt|;
name|uint32_t
name|xbd_max_request_size
decl_stmt|;
name|grant_ref_t
name|xbd_ring_ref
index|[
name|XBD_MAX_RING_PAGES
index|]
decl_stmt|;
name|blkif_front_ring_t
name|xbd_ring
decl_stmt|;
name|unsigned
name|int
name|xbd_irq
decl_stmt|;
name|struct
name|gnttab_free_callback
name|xbd_callback
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|xbd_command
argument_list|)
name|xbd_cm_free
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|xbd_command
argument_list|)
name|xbd_cm_ready
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|xbd_command
argument_list|)
name|xbd_cm_busy
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|xbd_command
argument_list|)
name|xbd_cm_complete
expr_stmt|;
name|struct
name|xbd_qstat
name|xbd_qstat
index|[
name|XBDQ_COUNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|xbd_io_dmat
decl_stmt|;
comment|/** 	 * The number of people holding this device open.  We won't allow a 	 * hot-unplug unless this is 0. 	 */
name|int
name|xbd_users
decl_stmt|;
name|struct
name|mtx
name|xbd_io_lock
decl_stmt|;
name|struct
name|xbd_command
modifier|*
name|xbd_shadow
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|xbd_instance_create
parameter_list|(
name|struct
name|xbd_softc
modifier|*
parameter_list|,
name|blkif_sector_t
name|sectors
parameter_list|,
name|int
name|device
parameter_list|,
name|uint16_t
name|vdisk_info
parameter_list|,
name|unsigned
name|long
name|sector_size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XBDQ_ADD
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {							\ 		struct xbd_qstat *qs;				\ 								\ 		qs =&(sc)->xbd_qstat[qname];			\ 		qs->q_length++;					\ 		if (qs->q_length> qs->q_max)			\ 			qs->q_max = qs->q_length;		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|XBDQ_REMOVE
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
value|(sc)->xbd_qstat[qname].q_length--
end_define

begin_define
define|#
directive|define
name|XBDQ_INIT
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {							\ 		sc->xbd_qstat[qname].q_length = 0;		\ 		sc->xbd_qstat[qname].q_max = 0;			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|XBDQ_COMMAND_QUEUE
parameter_list|(
name|name
parameter_list|,
name|index
parameter_list|)
define|\
value|static __inline void						\ 	xbd_initq_ ## name (struct xbd_softc *sc)			\ 	{								\ 		TAILQ_INIT(&sc->xbd_cm_ ## name);			\ 		XBDQ_INIT(sc, index);					\ 	}								\ 	static __inline void						\ 	xbd_enqueue_ ## name (struct xbd_command *cm)			\ 	{								\ 		if ((cm->cm_flags& XBD_ON_XBDQ_MASK) != 0) {		\ 			printf("command %p is on another queue, "	\ 			    "flags = %#x\n", cm, cm->cm_flags);		\ 			panic("command is on another queue");		\ 		}							\ 		TAILQ_INSERT_TAIL(&cm->cm_sc->xbd_cm_ ## name, cm, cm_link); \ 		cm->cm_flags |= XBD_ON_ ## index;			\ 		XBDQ_ADD(cm->cm_sc, index);				\ 	}								\ 	static __inline void						\ 	xbd_requeue_ ## name (struct xbd_command *cm)			\ 	{								\ 		if ((cm->cm_flags& XBD_ON_XBDQ_MASK) != 0) {		\ 			printf("command %p is on another queue, "	\ 			    "flags = %#x\n", cm, cm->cm_flags);		\ 			panic("command is on another queue");		\ 		}							\ 		TAILQ_INSERT_HEAD(&cm->cm_sc->xbd_cm_ ## name, cm, cm_link); \ 		cm->cm_flags |= XBD_ON_ ## index;			\ 		XBDQ_ADD(cm->cm_sc, index);				\ 	}								\ 	static __inline struct xbd_command *				\ 	xbd_dequeue_ ## name (struct xbd_softc *sc)			\ 	{								\ 		struct xbd_command *cm;					\ 									\ 		if ((cm = TAILQ_FIRST(&sc->xbd_cm_ ## name)) != NULL) {	\ 			if ((cm->cm_flags& XBD_ON_XBDQ_MASK) !=		\ 			     XBD_ON_ ## index) {				\ 				printf("command %p not in queue, "	\ 				    "flags = %#x, bit = %#x\n", cm,	\ 				    cm->cm_flags, XBD_ON_ ## index);	\ 				panic("command not in queue");		\ 			}						\ 			TAILQ_REMOVE(&sc->xbd_cm_ ## name, cm, cm_link);\ 			cm->cm_flags&= ~XBD_ON_ ## index;		\ 			XBDQ_REMOVE(sc, index);				\ 		}							\ 		return (cm);						\ 	}								\ 	static __inline void						\ 	xbd_remove_ ## name (struct xbd_command *cm)			\ 	{								\ 		if ((cm->cm_flags& XBD_ON_XBDQ_MASK) != XBD_ON_ ## index){\ 			printf("command %p not in queue, flags = %#x, " \ 			    "bit = %#x\n", cm, cm->cm_flags,		\ 			    XBD_ON_ ## index);				\ 			panic("command not in queue");			\ 		}							\ 		TAILQ_REMOVE(&cm->cm_sc->xbd_cm_ ## name, cm, cm_link);	\ 		cm->cm_flags&= ~XBD_ON_ ## index;			\ 		XBDQ_REMOVE(cm->cm_sc, index);				\ 	}								\ struct hack
end_define

begin_expr_stmt
name|XBDQ_COMMAND_QUEUE
argument_list|(
name|free
argument_list|,
name|XBDQ_FREE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|XBDQ_COMMAND_QUEUE
argument_list|(
name|ready
argument_list|,
name|XBDQ_READY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|XBDQ_COMMAND_QUEUE
argument_list|(
name|busy
argument_list|,
name|XBDQ_BUSY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|XBDQ_COMMAND_QUEUE
argument_list|(
name|complete
argument_list|,
name|XBDQ_COMPLETE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|__inline
name|void
name|xbd_initq_bio
parameter_list|(
name|struct
name|xbd_softc
modifier|*
name|sc
parameter_list|)
block|{
name|bioq_init
argument_list|(
operator|&
name|sc
operator|->
name|xbd_bioq
argument_list|)
expr_stmt|;
name|XBDQ_INIT
argument_list|(
name|sc
argument_list|,
name|XBDQ_BIO
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|xbd_enqueue_bio
parameter_list|(
name|struct
name|xbd_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
block|{
name|bioq_insert_tail
argument_list|(
operator|&
name|sc
operator|->
name|xbd_bioq
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|XBDQ_ADD
argument_list|(
name|sc
argument_list|,
name|XBDQ_BIO
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|xbd_requeue_bio
parameter_list|(
name|struct
name|xbd_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
block|{
name|bioq_insert_head
argument_list|(
operator|&
name|sc
operator|->
name|xbd_bioq
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|XBDQ_ADD
argument_list|(
name|sc
argument_list|,
name|XBDQ_BIO
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|bio
operator|*
name|xbd_dequeue_bio
argument_list|(
argument|struct xbd_softc *sc
argument_list|)
block|{ 	struct
name|bio
operator|*
name|bp
block|;
if|if
condition|(
operator|(
name|bp
operator|=
name|bioq_first
argument_list|(
operator|&
name|sc
operator|->
name|xbd_bioq
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|bioq_remove
argument_list|(
operator|&
name|sc
operator|->
name|xbd_bioq
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|XBDQ_REMOVE
argument_list|(
name|sc
argument_list|,
name|XBDQ_BIO
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|(
name|bp
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_BLKFRONT_BLOCK_H__ */
end_comment

end_unit

