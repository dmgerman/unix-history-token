begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * LSI MPT Host Adapter FreeBSD Wrapper Definitions (CAM version)  *  * Copyright (c) 2000, 2001 by Greg Ansley, Adam Prewett  *  * Partially derived from Matty Jacobs ISP driver.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  */
end_comment

begin_comment
comment|/*  * Additional Copyright (c) 2002 by Matthew Jacob under same license.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPT_FREEBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPT_FREEBSD_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_memio.h>
end_include

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
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
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

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_define
define|#
directive|define
name|INLINE
value|__inline
end_define

begin_comment
comment|/* Max MPT Reply we are willing to accept (must be power of 2) */
end_comment

begin_define
define|#
directive|define
name|MPT_REPLY_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|MPT_MAX_REQUESTS
value|256
end_define

begin_comment
comment|/* XXX: should be derived from GlobalCredits */
end_comment

begin_define
define|#
directive|define
name|MPT_REQUEST_AREA
value|512
end_define

begin_define
define|#
directive|define
name|MPT_SENSE_SIZE
value|32
end_define

begin_comment
comment|/* included in MPT_REQUEST_SIZE */
end_comment

begin_define
define|#
directive|define
name|MPT_REQ_MEM_SIZE
value|(MPT_MAX_REQUESTS * MPT_REQUEST_AREA)
end_define

begin_comment
comment|/*  * We cannot tell prior to getting IOC facts how big the IOC's request  * area is. Because of this we cannot tell at compile time how many  * simple SG elements we can fit within an IOC request prior to having  * to put in a chain element.  *   * Experimentally we know that the Ultra4 parts have a 96 byte request  * element size and the Fibre Channel units have a 144 byte request  * element size. Therefore, if we have 512-32 (== 480) bytes of request  * area to play with, we have room for between 3 and 5 request sized  * regions- the first of which is the command  plus a simple SG list,  * the rest of which are chained continuation SG lists. Given that the  * normal request we use is 48 bytes w/o the first SG element, we can  * assume we have 480-48 == 432 bytes to have simple SG elements and/or  * chain elements. If we assume 32 bit addressing, this works out to  * 54 SG or chain elements. If we assume 5 chain elements, then we have  * a maximum of 49 seperate actual SG segments.  */
end_comment

begin_define
define|#
directive|define
name|MPT_SGL_MAX
value|49
end_define

begin_define
define|#
directive|define
name|MPT_RQSL
parameter_list|(
name|mpt
parameter_list|)
value|(mpt->request_frame_size<< 2)
end_define

begin_define
define|#
directive|define
name|MPT_NSGL
parameter_list|(
name|mpt
parameter_list|)
value|(MPT_RQSL(mpt) / sizeof (SGE_SIMPLE32))
end_define

begin_define
define|#
directive|define
name|MPT_NSGL_FIRST
parameter_list|(
name|mpt
parameter_list|)
define|\
value|(((mpt->request_frame_size<< 2) -		\ 	sizeof (MSG_SCSI_IO_REQUEST) -			\ 	sizeof (SGE_IO_UNION)) / sizeof (SGE_SIMPLE32))
end_define

begin_comment
comment|/*  * Convert a physical address returned from IOC to kvm address  * needed to access the data.  */
end_comment

begin_define
define|#
directive|define
name|MPT_REPLY_PTOV
parameter_list|(
name|m
parameter_list|,
name|x
parameter_list|)
define|\
value|((void *)(m->reply + ((x<< 1) - (u_int32_t)(m->reply_phys))))
end_define

begin_define
define|#
directive|define
name|ccb_mpt_ptr
value|sim_priv.entries[0].ptr
end_define

begin_define
define|#
directive|define
name|ccb_req_ptr
value|sim_priv.entries[1].ptr
end_define

begin_enum
enum|enum
name|mpt_req_state
block|{
name|REQ_FREE
block|,
name|REQ_IN_PROGRESS
block|,
name|REQ_TIMEOUT
block|,
name|REQ_ON_CHIP
block|,
name|REQ_DONE
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|req_entry
block|{
name|u_int16_t
name|index
decl_stmt|;
comment|/* Index of this entry */
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
comment|/* Request that generated this command */
name|void
modifier|*
name|req_vbuf
decl_stmt|;
comment|/* Virtual Address of Entry */
name|void
modifier|*
name|sense_vbuf
decl_stmt|;
comment|/* Virtual Address of sense data */
name|u_int32_t
name|req_pbuf
decl_stmt|;
comment|/* Physical Address of Entry */
name|u_int32_t
name|sense_pbuf
decl_stmt|;
comment|/* Physical Address of sense data */
name|bus_dmamap_t
name|dmap
decl_stmt|;
comment|/* DMA map for data buffer */
name|SLIST_ENTRY
argument_list|(
argument|req_entry
argument_list|)
name|link
expr_stmt|;
comment|/* Pointer to next in list */
name|enum
name|mpt_req_state
name|debug
decl_stmt|;
comment|/* Debuging */
name|u_int32_t
name|sequence
decl_stmt|;
comment|/* Sequence Number */
block|}
name|request_t
typedef|;
end_typedef

begin_comment
comment|/* Structure for saving proper values for modifyable PCI configuration registers */
end_comment

begin_struct
struct|struct
name|mpt_pci_cfg
block|{
name|u_int16_t
name|Command
decl_stmt|;
name|u_int16_t
name|LatencyTimer_LineSize
decl_stmt|;
name|u_int32_t
name|IO_BAR
decl_stmt|;
name|u_int32_t
name|Mem0_BAR
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|Mem1_BAR
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|ROM_BAR
decl_stmt|;
name|u_int8_t
name|IntLine
decl_stmt|;
name|u_int32_t
name|PMCSR
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpt_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/* Operational flags, set during initialization */
name|int
name|verbose
decl_stmt|;
comment|/* print debug messages */
name|struct
name|resource
modifier|*
name|pci_irq
decl_stmt|;
comment|/* Interrupt map for chip */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* Interupt handle */
comment|/* First Memory Region (Device MEM) */
name|struct
name|resource
modifier|*
name|pci_reg
decl_stmt|;
comment|/* Register map for chip */
name|int
name|pci_reg_id
decl_stmt|;
comment|/* Resource ID */
name|bus_space_tag_t
name|pci_st
decl_stmt|;
comment|/* Bus tag for registers */
name|bus_space_handle_t
name|pci_sh
decl_stmt|;
comment|/* Bus handle for registers */
name|vm_offset_t
name|pci_pa
decl_stmt|;
comment|/* Physical Address */
comment|/* Second Memory Region (Diagnostic memory window) */
comment|/* (only used for diagnostic purposes) */
name|struct
name|resource
modifier|*
name|pci_mem
decl_stmt|;
comment|/* Register map for chip */
name|int
name|pci_mem_id
decl_stmt|;
comment|/* Resource ID */
name|bus_space_tag_t
name|pci_mst
decl_stmt|;
comment|/* Bus tag for registers */
name|bus_space_handle_t
name|pci_msh
decl_stmt|;
comment|/* Bus handle for registers */
comment|/* DMA Memory for IOCTLs */
name|void
modifier|*
name|ioctl_mem_va
decl_stmt|;
comment|/* Virtual Addr */
name|u_int32_t
name|ioctl_mem_pa
decl_stmt|;
comment|/* Physical Addr */
name|bus_dmamap_t
name|ioctl_mem_map
decl_stmt|;
comment|/* DMA map for buffer */
name|bus_dma_tag_t
name|ioctl_mem_tag
decl_stmt|;
comment|/* DMA tag for memory alloc */
name|int
name|open
decl_stmt|;
comment|/* only allow one open at a time */
name|bus_dma_tag_t
name|parent_dmat
decl_stmt|;
comment|/* DMA tag for parent PCI bus */
name|bus_dma_tag_t
name|reply_dmat
decl_stmt|;
comment|/* DMA tag for reply memory */
name|bus_dmamap_t
name|reply_dmap
decl_stmt|;
comment|/* DMA map for reply memory */
name|char
modifier|*
name|reply
decl_stmt|;
comment|/* Virtual address of reply memory */
name|u_int32_t
name|reply_phys
decl_stmt|;
comment|/* Physical address of reply memory */
name|u_int32_t
label|:
literal|29
operator|,
name|disabled
operator|:
literal|1
operator|,
name|is_fc
operator|:
literal|1
operator|,
name|bus
operator|:
literal|1
expr_stmt|;
comment|/* FC929/1030 have two busses */
name|u_int32_t
name|blk_size
decl_stmt|;
comment|/* Block size transfers to IOC */
name|u_int16_t
name|mpt_global_credits
decl_stmt|;
name|u_int16_t
name|request_frame_size
decl_stmt|;
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
comment|/* DMA tag for mapping data buffers */
name|bus_dma_tag_t
name|request_dmat
decl_stmt|;
comment|/* DMA tag for request memroy */
name|bus_dmamap_t
name|request_dmap
decl_stmt|;
comment|/* DMA map for request memroy */
name|char
modifier|*
name|request
decl_stmt|;
comment|/* Virtual address of Request memory */
name|u_int32_t
name|request_phys
decl_stmt|;
comment|/* Physical address of Request memory */
name|request_t
name|requests
index|[
name|MPT_MAX_REQUESTS
index|]
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument|req_queue
argument_list|,
argument|req_entry
argument_list|)
name|request_free_list
expr_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|u_int32_t
name|sequence
decl_stmt|;
comment|/* Sequence Number */
name|u_int32_t
name|timeouts
decl_stmt|;
comment|/* timeout count */
name|u_int32_t
name|success
decl_stmt|;
comment|/* timeout  successes afer timeout */
comment|/* Opposing port in a 929, or NULL */
name|struct
name|mpt_softc
modifier|*
name|mpt2
decl_stmt|;
comment|/* Saved values for the PCI configuration registers */
name|struct
name|mpt_pci_cfg
name|pci_cfg
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|INLINE
name|void
name|mpt_write
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|u_int32_t
name|val
parameter_list|)
block|{
name|bus_space_write_4
argument_list|(
name|mpt
operator|->
name|pci_st
argument_list|,
name|mpt
operator|->
name|pci_sh
argument_list|,
name|offset
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|INLINE
name|u_int32_t
name|mpt_read
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|int
name|offset
parameter_list|)
block|{
return|return
name|bus_space_read_4
argument_list|(
name|mpt
operator|->
name|pci_st
argument_list|,
name|mpt
operator|->
name|pci_sh
argument_list|,
name|offset
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|void
name|mpt_cam_attach
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_cam_detach
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_done
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|u_int32_t
name|reply
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_notify
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mpt_pci.c declarations */
end_comment

begin_function_decl
name|void
name|mpt_set_config_regs
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MPT_FREEBSD_H */
end_comment

end_unit

