begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FreeBSD platform specific driver option settings, data structures,  * function declarations and includes.  *  * Copyright (c) 1994-2001 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU Public License ("GPL").  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AIC7XXX_FREEBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_AIC7XXX_FREEBSD_H_
end_define

begin_include
include|#
directive|include
file|<opt_aic7xxx.h>
end_include

begin_comment
comment|/* for config options */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NPCI
end_ifndef

begin_include
include|#
directive|include
file|<pci.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/* For device_t */
end_comment

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_if
if|#
directive|if
name|NPCI
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|AHC_PCI_CONFIG
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_ALLOW_MEMIO
end_ifdef

begin_include
include|#
directive|include
file|<machine/bus_memio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/bus_pio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_if
if|#
directive|if
name|NPCI
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_message.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CAM_NEW_TRAN_CODE
end_ifdef

begin_define
define|#
directive|define
name|AHC_NEW_TRAN_SETTINGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CAM_NEW_TRAN_CODE */
end_comment

begin_comment
comment|/****************************** Platform Macros *******************************/
end_comment

begin_define
define|#
directive|define
name|SIM_IS_SCSIBUS_B
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|)
define|\
value|((sim) == ahc->platform_data->sim_b)
end_define

begin_define
define|#
directive|define
name|SIM_CHANNEL
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|)
define|\
value|(((sim) == ahc->platform_data->sim_b) ? 'B' : 'A')
end_define

begin_define
define|#
directive|define
name|SIM_SCSI_ID
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|)
define|\
value|(((sim) == ahc->platform_data->sim_b) ? ahc->our_id_b : ahc->our_id)
end_define

begin_define
define|#
directive|define
name|SIM_PATH
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|)
define|\
value|(((sim) == ahc->platform_data->sim_b) ? ahc->platform_data->path_b \ 					      : ahc->platform_data->path)
end_define

begin_define
define|#
directive|define
name|BUILD_SCSIID
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|,
name|target_id
parameter_list|,
name|our_id
parameter_list|)
define|\
value|((((target_id)<< TID_SHIFT)& TID) | (our_id) \         | (SIM_IS_SCSIBUS_B(ahc, sim) ? TWIN_CHNLB : 0))
end_define

begin_define
define|#
directive|define
name|SCB_GET_SIM
parameter_list|(
name|ahc
parameter_list|,
name|scb
parameter_list|)
define|\
value|(SCB_GET_CHANNEL(ahc, scb) == 'A' ? (ahc)->platform_data->sim \ 					  : (ahc)->platform_data->sim_b)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)(&((type *)0)->member))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************* Forward Declarations *******************************/
end_comment

begin_typedef
typedef|typedef
name|device_t
name|ahc_dev_softc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|ccb
modifier|*
name|ahc_io_ctx_t
typedef|;
end_typedef

begin_comment
comment|/***************************** Bus Space/DMA **********************************/
end_comment

begin_define
define|#
directive|define
name|ahc_dma_tag_create
parameter_list|(
name|ahc
parameter_list|,
name|parent_tag
parameter_list|,
name|alignment
parameter_list|,
name|boundary
parameter_list|,	\
name|lowaddr
parameter_list|,
name|highaddr
parameter_list|,
name|filter
parameter_list|,
name|filterarg
parameter_list|,	\
name|maxsize
parameter_list|,
name|nsegments
parameter_list|,
name|maxsegsz
parameter_list|,
name|flags
parameter_list|,		\
name|dma_tagp
parameter_list|)
define|\
value|bus_dma_tag_create(parent_tag, alignment, boundary,		\ 			   lowaddr, highaddr, filter, filterarg,	\ 			   maxsize, nsegments, maxsegsz, flags,		\ 			   dma_tagp)
end_define

begin_define
define|#
directive|define
name|ahc_dma_tag_destroy
parameter_list|(
name|ahc
parameter_list|,
name|tag
parameter_list|)
define|\
value|bus_dma_tag_destroy(tag)
end_define

begin_define
define|#
directive|define
name|ahc_dmamem_alloc
parameter_list|(
name|ahc
parameter_list|,
name|dmat
parameter_list|,
name|vaddr
parameter_list|,
name|flags
parameter_list|,
name|mapp
parameter_list|)
define|\
value|bus_dmamem_alloc(dmat, vaddr, flags, mapp)
end_define

begin_define
define|#
directive|define
name|ahc_dmamem_free
parameter_list|(
name|ahc
parameter_list|,
name|dmat
parameter_list|,
name|vaddr
parameter_list|,
name|map
parameter_list|)
define|\
value|bus_dmamem_free(dmat, vaddr, map)
end_define

begin_define
define|#
directive|define
name|ahc_dmamap_create
parameter_list|(
name|ahc
parameter_list|,
name|tag
parameter_list|,
name|flags
parameter_list|,
name|mapp
parameter_list|)
define|\
value|bus_dmamap_create(tag, flags, mapp)
end_define

begin_define
define|#
directive|define
name|ahc_dmamap_destroy
parameter_list|(
name|ahc
parameter_list|,
name|tag
parameter_list|,
name|map
parameter_list|)
define|\
value|bus_dmamap_destroy(tag, map)
end_define

begin_define
define|#
directive|define
name|ahc_dmamap_load
parameter_list|(
name|ahc
parameter_list|,
name|dmat
parameter_list|,
name|map
parameter_list|,
name|addr
parameter_list|,
name|buflen
parameter_list|,
name|callback
parameter_list|,		\
name|callback_arg
parameter_list|,
name|flags
parameter_list|)
define|\
value|bus_dmamap_load(dmat, map, addr, buflen, callback, callback_arg, flags)
end_define

begin_define
define|#
directive|define
name|ahc_dmamap_unload
parameter_list|(
name|ahc
parameter_list|,
name|tag
parameter_list|,
name|map
parameter_list|)
define|\
value|bus_dmamap_unload(tag, map)
end_define

begin_comment
comment|/* XXX Need to update Bus DMA for partial map syncs */
end_comment

begin_define
define|#
directive|define
name|ahc_dmamap_sync
parameter_list|(
name|ahc
parameter_list|,
name|dma_tag
parameter_list|,
name|dmamap
parameter_list|,
name|offset
parameter_list|,
name|len
parameter_list|,
name|op
parameter_list|)
define|\
value|bus_dmamap_sync(dma_tag, dmamap, op)
end_define

begin_comment
comment|/************************ Tunable Driver Parameters  **************************/
end_comment

begin_comment
comment|/*  * The number of dma segments supported.  The sequencer can handle any number  * of physically contiguous S/G entrys.  To reduce the driver's memory  * consumption, we limit the number supported to be sufficient to handle  * the largest mapping supported by the kernel, MAXPHYS.  Assuming the  * transfer is as fragmented as possible and unaligned, this turns out to  * be the number of paged sized transfers in MAXPHYS plus an extra element  * to handle any unaligned residual.  The sequencer fetches SG elements  * in cacheline sized chucks, so make the number per-transaction an even  * multiple of 16 which should align us on even the largest of cacheline  * boundaries.   */
end_comment

begin_define
define|#
directive|define
name|AHC_NSEG
value|(roundup(btoc(MAXPHYS) + 1, 16))
end_define

begin_comment
comment|/* This driver supports target mode */
end_comment

begin_define
define|#
directive|define
name|AHC_TARGET_MODE
value|1
end_define

begin_comment
comment|/************************** Softc/SCB Platform Data ***************************/
end_comment

begin_struct
struct|struct
name|ahc_platform_data
block|{
comment|/* 	 * Hooks into the XPT. 	 */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim_b
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path_b
decl_stmt|;
name|int
name|regs_res_type
decl_stmt|;
name|int
name|regs_res_id
decl_stmt|;
name|int
name|irq_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|regs
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|eventhandler_tag
name|eh
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scb_platform_data
block|{ }
struct|;
end_struct

begin_comment
comment|/********************************* Byte Order *********************************/
end_comment

begin_comment
comment|/*  * XXX Waiting for FreeBSD byte swapping functions.  * For now assume host is Little Endian.  */
end_comment

begin_define
define|#
directive|define
name|ahc_htobe16
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_htobe32
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_htobe64
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_htole16
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_htole32
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_htole64
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_be16toh
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_be32toh
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_be64toh
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_le16toh
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_le32toh
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ahc_le64toh
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|/***************************** Core Includes **********************************/
end_comment

begin_include
include|#
directive|include
file|<dev/aic7xxx/aic7xxx.h>
end_include

begin_comment
comment|/*************************** Device Access ************************************/
end_comment

begin_define
define|#
directive|define
name|ahc_inb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((ahc)->tag, (ahc)->bsh, port)
end_define

begin_define
define|#
directive|define
name|ahc_outb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((ahc)->tag, (ahc)->bsh, port, value)
end_define

begin_define
define|#
directive|define
name|ahc_outsb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_1((ahc)->tag, (ahc)->bsh, port, valp, count)
end_define

begin_define
define|#
directive|define
name|ahc_insb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1((ahc)->tag, (ahc)->bsh, port, valp, count)
end_define

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_flush_device_writes
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_flush_device_writes
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
comment|/* XXX Is this sufficient for all architectures??? */
name|ahc_inb
argument_list|(
name|ahc
argument_list|,
name|INTSTAT
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************** Locking Primitives ******************************/
end_comment

begin_comment
comment|/* Lock protecting internal data structures */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_lockinit
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_lock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_unlock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lock held during command compeletion to the upper layer */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_done_lockinit
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_done_lock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_done_unlock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_lockinit
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_lock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|unsigned
name|long
modifier|*
name|flags
parameter_list|)
block|{
operator|*
name|flags
operator|=
name|splcam
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_unlock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|unsigned
name|long
modifier|*
name|flags
parameter_list|)
block|{
name|splx
argument_list|(
operator|*
name|flags
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Lock held during command compeletion to the upper layer */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ahc_done_lockinit
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_done_lock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|unsigned
name|long
modifier|*
name|flags
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_done_unlock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|unsigned
name|long
modifier|*
name|flags
parameter_list|)
block|{ }
end_function

begin_comment
comment|/****************************** OS Primitives *********************************/
end_comment

begin_define
define|#
directive|define
name|ahc_delay
value|DELAY
end_define

begin_comment
comment|/************************** Transaction Operations ****************************/
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_set_transaction_status
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_set_scsi_status
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|uint32_t
name|ahc_get_transaction_status
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|uint32_t
name|ahc_get_scsi_status
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_set_transaction_tag
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_long
name|ahc_get_transfer_length
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|ahc_get_transfer_dir
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_set_residual
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_set_sense_residual
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|u_long
name|ahc_get_residual
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|ahc_perform_autosense
parameter_list|(
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|uint32_t
name|ahc_get_sense_bufsize
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_freeze_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_freeze_scb
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_platform_freeze_devq
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|ahc_platform_abort_scbs
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|int
name|target
parameter_list|,
name|char
name|channel
parameter_list|,
name|int
name|lun
parameter_list|,
name|u_int
name|tag
parameter_list|,
name|role_t
name|role
parameter_list|,
name|uint32_t
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_set_transaction_status
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|,
name|uint32_t
name|status
parameter_list|)
block|{
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|status
operator|&=
operator|~
name|CAM_STATUS_MASK
expr_stmt|;
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|status
operator||=
name|status
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_set_scsi_status
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|,
name|uint32_t
name|status
parameter_list|)
block|{
name|scb
operator|->
name|io_ctx
operator|->
name|csio
operator|.
name|scsi_status
operator|=
name|status
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|ahc_get_transaction_status
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
return|return
operator|(
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|status
operator|&
name|CAM_STATUS_MASK
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|ahc_get_scsi_status
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
return|return
operator|(
name|scb
operator|->
name|io_ctx
operator|->
name|csio
operator|.
name|scsi_status
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_set_transaction_tag
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|,
name|int
name|enabled
parameter_list|,
name|u_int
name|type
parameter_list|)
block|{
name|scb
operator|->
name|io_ctx
operator|->
name|csio
operator|.
name|tag_action
operator|=
name|type
expr_stmt|;
if|if
condition|(
name|enabled
condition|)
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|flags
operator||=
name|CAM_TAG_ACTION_VALID
expr_stmt|;
else|else
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|flags
operator|&=
operator|~
name|CAM_TAG_ACTION_VALID
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_long
name|ahc_get_transfer_length
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
return|return
operator|(
name|scb
operator|->
name|io_ctx
operator|->
name|csio
operator|.
name|dxfer_len
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|ahc_get_transfer_dir
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
return|return
operator|(
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|flags
operator|&
name|CAM_DIR_MASK
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_set_residual
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|,
name|u_long
name|resid
parameter_list|)
block|{
name|scb
operator|->
name|io_ctx
operator|->
name|csio
operator|.
name|resid
operator|=
name|resid
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_set_sense_residual
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|,
name|u_long
name|resid
parameter_list|)
block|{
name|scb
operator|->
name|io_ctx
operator|->
name|csio
operator|.
name|sense_resid
operator|=
name|resid
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_long
name|ahc_get_residual
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
return|return
operator|(
name|scb
operator|->
name|io_ctx
operator|->
name|csio
operator|.
name|resid
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|ahc_perform_autosense
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
return|return
operator|(
operator|!
operator|(
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|flags
operator|&
name|CAM_DIS_AUTOSENSE
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|ahc_get_sense_bufsize
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|scsi_sense_data
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_freeze_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
block|{
if|if
condition|(
operator|(
name|ccb
operator|->
name|ccb_h
operator|.
name|status
operator|&
name|CAM_DEV_QFRZN
operator|)
operator|==
literal|0
condition|)
block|{
name|ccb
operator|->
name|ccb_h
operator|.
name|status
operator||=
name|CAM_DEV_QFRZN
expr_stmt|;
name|xpt_freeze_devq
argument_list|(
name|ccb
operator|->
name|ccb_h
operator|.
name|path
argument_list|,
comment|/*count*/
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_freeze_scb
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
name|ahc_freeze_ccb
argument_list|(
name|scb
operator|->
name|io_ctx
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_platform_freeze_devq
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
comment|/* Nothing to do here for FreeBSD */
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|ahc_platform_abort_scbs
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|int
name|target
parameter_list|,
name|char
name|channel
parameter_list|,
name|int
name|lun
parameter_list|,
name|u_int
name|tag
parameter_list|,
name|role_t
name|role
parameter_list|,
name|uint32_t
name|status
parameter_list|)
block|{
comment|/* Nothing to do here for FreeBSD */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_platform_scb_free
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
comment|/* What do we do to generically handle driver resource shortages??? */
if|if
condition|(
operator|(
name|ahc
operator|->
name|flags
operator|&
name|AHC_RESOURCE_SHORTAGE
operator|)
operator|!=
literal|0
operator|&&
name|scb
operator|->
name|io_ctx
operator|!=
name|NULL
operator|&&
operator|(
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|status
operator|&
name|CAM_RELEASE_SIMQ
operator|)
operator|==
literal|0
condition|)
block|{
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|status
operator||=
name|CAM_RELEASE_SIMQ
expr_stmt|;
name|ahc
operator|->
name|flags
operator|&=
operator|~
name|AHC_RESOURCE_SHORTAGE
expr_stmt|;
block|}
name|scb
operator|->
name|io_ctx
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/********************************** PCI ***************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_PCI_CONFIG
end_ifdef

begin_function_decl
specifier|static
name|__inline
name|uint32_t
name|ahc_pci_read_config
parameter_list|(
name|ahc_dev_softc_t
name|pci
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_pci_write_config
parameter_list|(
name|ahc_dev_softc_t
name|pci
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|ahc_get_pci_function
parameter_list|(
name|ahc_dev_softc_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|ahc_get_pci_slot
parameter_list|(
name|ahc_dev_softc_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|ahc_get_pci_bus
parameter_list|(
name|ahc_dev_softc_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_pci_map_registers
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_pci_map_int
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|uint32_t
name|ahc_pci_read_config
parameter_list|(
name|ahc_dev_softc_t
name|pci
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|width
parameter_list|)
block|{
return|return
operator|(
name|pci_read_config
argument_list|(
name|pci
argument_list|,
name|reg
argument_list|,
name|width
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_pci_write_config
parameter_list|(
name|ahc_dev_softc_t
name|pci
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|,
name|int
name|width
parameter_list|)
block|{
name|pci_write_config
argument_list|(
name|pci
argument_list|,
name|reg
argument_list|,
name|value
argument_list|,
name|width
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|ahc_get_pci_function
parameter_list|(
name|ahc_dev_softc_t
name|pci
parameter_list|)
block|{
return|return
operator|(
name|pci_get_function
argument_list|(
name|pci
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|ahc_get_pci_slot
parameter_list|(
name|ahc_dev_softc_t
name|pci
parameter_list|)
block|{
return|return
operator|(
name|pci_get_slot
argument_list|(
name|pci
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|ahc_get_pci_bus
parameter_list|(
name|ahc_dev_softc_t
name|pci
parameter_list|)
block|{
return|return
operator|(
name|pci_get_bus
argument_list|(
name|pci
argument_list|)
operator|)
return|;
block|}
end_function

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHC_POWER_STATE_D0
block|,
name|AHC_POWER_STATE_D1
block|,
name|AHC_POWER_STATE_D2
block|,
name|AHC_POWER_STATE_D3
block|}
name|ahc_power_state
typedef|;
end_typedef

begin_function_decl
name|void
name|ahc_power_state_change
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|ahc_power_state
name|new_state
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************** VL/EISA *************************************/
end_comment

begin_function_decl
name|int
name|aic7770_map_registers
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aic7770_map_int
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/********************************* Debug **************************************/
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_print_path
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_platform_dump_card_state
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_print_path
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
name|xpt_print_path
argument_list|(
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|path
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_platform_dump_card_state
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
comment|/* Nothing to do here for FreeBSD */
block|}
end_function

begin_comment
comment|/**************************** Transfer Settings *******************************/
end_comment

begin_function_decl
name|void
name|ahc_notify_xfer_settings_change
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|ahc_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_platform_set_tags
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|ahc_devinfo
modifier|*
parameter_list|,
name|int
comment|/*enable*/
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************* Initialization/Teardown ****************************/
end_comment

begin_function_decl
name|int
name|ahc_platform_alloc
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|void
modifier|*
name|platform_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_platform_free
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_attach
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_softc_comp
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|lahc
parameter_list|,
name|struct
name|ahc_softc
modifier|*
name|rahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************** Interrupts ************************************/
end_comment

begin_function_decl
name|void
name|ahc_platform_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_platform_flushwork
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_platform_flushwork
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{ }
end_function

begin_comment
comment|/************************ Misc Function Declarations **************************/
end_comment

begin_decl_stmt
name|timeout_t
name|ahc_timeout
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ahc_done
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_send_async
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|char
comment|/*channel*/
parameter_list|,
name|u_int
comment|/*target*/
parameter_list|,
name|u_int
comment|/*lun*/
parameter_list|,
name|ac_code
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIC7XXX_FREEBSD_H_ */
end_comment

end_unit

