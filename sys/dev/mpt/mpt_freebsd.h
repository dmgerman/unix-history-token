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

begin_comment
comment|/* #define RELENG_4	1 */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|RELENG_4
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
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
file|<sys/condvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|"dev/mpt/mpilib/mpi_type.h"
end_include

begin_include
include|#
directive|include
file|"dev/mpt/mpilib/mpi.h"
end_include

begin_include
include|#
directive|include
file|"dev/mpt/mpilib/mpi_cnfg.h"
end_include

begin_include
include|#
directive|include
file|"dev/mpt/mpilib/mpi_fc.h"
end_include

begin_include
include|#
directive|include
file|"dev/mpt/mpilib/mpi_init.h"
end_include

begin_include
include|#
directive|include
file|"dev/mpt/mpilib/mpi_ioc.h"
end_include

begin_include
include|#
directive|include
file|"dev/mpt/mpilib/mpi_lan.h"
end_include

begin_include
include|#
directive|include
file|"dev/mpt/mpilib/mpi_targ.h"
end_include

begin_define
define|#
directive|define
name|INLINE
value|__inline
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RELENG_4
end_ifdef

begin_define
define|#
directive|define
name|MPT_IFLAGS
value|INTR_TYPE_CAM
end_define

begin_define
define|#
directive|define
name|MPT_LOCK
parameter_list|(
name|mpt
parameter_list|)
value|mpt_lockspl(mpt)
end_define

begin_define
define|#
directive|define
name|MPT_UNLOCK
parameter_list|(
name|mpt
parameter_list|)
value|mpt_unlockspl(mpt)
end_define

begin_define
define|#
directive|define
name|MPTLOCK_2_CAMLOCK
value|MPT_UNLOCK
end_define

begin_define
define|#
directive|define
name|CAMLOCK_2_MPTLOCK
value|MPT_LOCK
end_define

begin_define
define|#
directive|define
name|MPT_LOCK_SETUP
parameter_list|(
name|mpt
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MPT_LOCK_DESTROY
parameter_list|(
name|mpt
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LOCKING_WORKED_AS_IT_SHOULD
end_if

begin_define
define|#
directive|define
name|MPT_IFLAGS
value|INTR_TYPE_CAM | INTR_ENTROPY | INTR_MPSAFE
end_define

begin_define
define|#
directive|define
name|MPT_LOCK_SETUP
parameter_list|(
name|mpt
parameter_list|)
define|\
value|mtx_init(&mpt->mpt_lock, "mpt", NULL, MTX_DEF);		\ 		mpt->mpt_locksetup = 1
end_define

begin_define
define|#
directive|define
name|MPT_LOCK_DESTROY
parameter_list|(
name|mpt
parameter_list|)
define|\
value|if (mpt->mpt_locksetup) {					\ 		mtx_destroy(&mpt->mpt_lock);				\ 		mpt->mpt_locksetup = 0;					\ 	}
end_define

begin_define
define|#
directive|define
name|MPT_LOCK
parameter_list|(
name|mpt
parameter_list|)
value|mtx_lock(&(mpt)->mpt_lock)
end_define

begin_define
define|#
directive|define
name|MPT_UNLOCK
parameter_list|(
name|mpt
parameter_list|)
value|mtx_unlock(&(mpt)->mpt_lock)
end_define

begin_define
define|#
directive|define
name|MPTLOCK_2_CAMLOCK
parameter_list|(
name|mpt
parameter_list|)
define|\
value|mtx_unlock(&(mpt)->mpt_lock); mtx_lock(&Giant)
end_define

begin_define
define|#
directive|define
name|CAMLOCK_2_MPTLOCK
parameter_list|(
name|mpt
parameter_list|)
define|\
value|mtx_unlock(&Giant); mtx_lock(&(mpt)->mpt_lock)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MPT_IFLAGS
value|INTR_TYPE_CAM | INTR_ENTROPY
end_define

begin_define
define|#
directive|define
name|MPT_LOCK_SETUP
parameter_list|(
name|mpt
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|MPT_LOCK_DESTROY
parameter_list|(
name|mpt
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|MPT_LOCK
parameter_list|(
name|mpt
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|MPT_UNLOCK
parameter_list|(
name|mpt
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|MPTLOCK_2_CAMLOCK
parameter_list|(
name|mpt
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|CAMLOCK_2_MPTLOCK
parameter_list|(
name|mpt
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
parameter_list|(
name|mpt
parameter_list|)
value|((mpt)->is_fc? 1024 : 256)
end_define

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
parameter_list|(
name|mpt
parameter_list|)
value|(MPT_MAX_REQUESTS(mpt) * MPT_REQUEST_AREA)
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
value|((void *)(&m->reply[((x<< 1) - m->reply_phys)]))
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
comment|/* CAM request */
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
name|bus_addr_t
name|req_pbuf
decl_stmt|;
comment|/* Physical Address of Entry */
name|bus_addr_t
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
comment|/* Debugging */
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

begin_typedef
typedef|typedef
struct|struct
name|mpt_softc
block|{
name|device_t
name|dev
decl_stmt|;
ifdef|#
directive|ifdef
name|RELENG_4
name|int
name|mpt_splsaved
decl_stmt|;
name|u_int32_t
name|mpt_islocked
decl_stmt|;
else|#
directive|else
name|struct
name|mtx
name|mpt_lock
decl_stmt|;
endif|#
directive|endif
name|u_int32_t
label|:
literal|16
operator|,
name|unit
operator|:
literal|8
operator|,
name|verbose
operator|:
literal|3
operator|,
name|outofbeer
operator|:
literal|1
operator|,
name|mpt_locksetup
operator|:
literal|1
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
comment|/* 	 * IOC Facts 	 */
name|u_int16_t
name|mpt_global_credits
decl_stmt|;
name|u_int16_t
name|request_frame_size
decl_stmt|;
name|u_int8_t
name|mpt_max_devices
decl_stmt|;
name|u_int8_t
name|mpt_max_buses
decl_stmt|;
comment|/* 	 * Port Facts 	 */
name|u_int16_t
name|mpt_ini_id
decl_stmt|;
comment|/* 	 * Device Configuration Information 	 */
union|union
block|{
struct|struct
name|mpt_spi_cfg
block|{
name|CONFIG_PAGE_SCSI_PORT_0
name|_port_page0
decl_stmt|;
name|CONFIG_PAGE_SCSI_PORT_1
name|_port_page1
decl_stmt|;
name|CONFIG_PAGE_SCSI_PORT_2
name|_port_page2
decl_stmt|;
name|CONFIG_PAGE_SCSI_DEVICE_0
name|_dev_page0
index|[
literal|16
index|]
decl_stmt|;
name|CONFIG_PAGE_SCSI_DEVICE_1
name|_dev_page1
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|_tag_enable
decl_stmt|;
name|uint16_t
name|_disc_enable
decl_stmt|;
name|uint16_t
name|_update_params0
decl_stmt|;
name|uint16_t
name|_update_params1
decl_stmt|;
block|}
name|spi
struct|;
define|#
directive|define
name|mpt_port_page0
value|cfg.spi._port_page0
define|#
directive|define
name|mpt_port_page1
value|cfg.spi._port_page1
define|#
directive|define
name|mpt_port_page2
value|cfg.spi._port_page2
define|#
directive|define
name|mpt_dev_page0
value|cfg.spi._dev_page0
define|#
directive|define
name|mpt_dev_page1
value|cfg.spi._dev_page1
define|#
directive|define
name|mpt_tag_enable
value|cfg.spi._tag_enable
define|#
directive|define
name|mpt_disc_enable
value|cfg.spi._disc_enable
define|#
directive|define
name|mpt_update_params0
value|cfg.spi._update_params0
define|#
directive|define
name|mpt_update_params1
value|cfg.spi._update_params1
struct|struct
name|mpi_fc_cfg
block|{
name|u_int8_t
name|nada
decl_stmt|;
block|}
name|fc
struct|;
block|}
name|cfg
union|;
comment|/* 	 * PCI Hardware info 	 */
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
name|struct
name|mpt_pci_cfg
name|pci_cfg
decl_stmt|;
comment|/* saved PCI conf registers */
comment|/* 	 * DMA Mapping Stuff 	 */
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
comment|/* KVA of reply memory */
name|bus_addr_t
name|reply_phys
decl_stmt|;
comment|/* BusAddr of reply memory */
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
comment|/* DMA tag for buffers */
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
comment|/* KVA of Request memory */
name|bus_addr_t
name|request_phys
decl_stmt|;
comment|/* BusADdr of request memory */
comment|/* 	 * CAM&& Software Management 	 */
name|request_t
modifier|*
name|request_pool
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
comment|/* successes afer timeout */
comment|/* Opposing port in a 929 or 1030, or NULL */
name|struct
name|mpt_softc
modifier|*
name|mpt2
decl_stmt|;
block|}
name|mpt_softc_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<dev/mpt/mpt.h>
end_include

begin_function_decl
specifier|static
name|INLINE
name|void
name|mpt_write
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|INLINE
name|u_int32_t
name|mpt_read
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|INLINE
name|void
name|mpt_write
parameter_list|(
name|mpt_softc_t
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
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|,
name|int
name|offset
parameter_list|)
block|{
return|return
operator|(
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
operator|)
return|;
block|}
end_function

begin_function_decl
name|void
name|mpt_cam_attach
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_cam_detach
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_done
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_prt
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_set_config_regs
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|RELENG_4
end_ifdef

begin_function_decl
specifier|static
name|INLINE
name|void
name|mpt_lockspl
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|INLINE
name|void
name|mpt_unlockspl
parameter_list|(
name|mpt_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|INLINE
name|void
name|mpt_lockspl
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
block|{
name|int
name|s
init|=
name|splcam
argument_list|()
decl_stmt|;
if|if
condition|(
name|mpt
operator|->
name|mpt_islocked
operator|++
operator|==
literal|0
condition|)
block|{
name|mpt
operator|->
name|mpt_splsaved
operator|=
name|s
expr_stmt|;
block|}
else|else
block|{
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|INLINE
name|void
name|mpt_unlockspl
parameter_list|(
name|mpt_softc_t
modifier|*
name|mpt
parameter_list|)
block|{
if|if
condition|(
name|mpt
operator|->
name|mpt_islocked
condition|)
block|{
if|if
condition|(
operator|--
name|mpt
operator|->
name|mpt_islocked
operator|==
literal|0
condition|)
block|{
name|splx
argument_list|(
name|mpt
operator|->
name|mpt_splsaved
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MPT_FREEBSD_H */
end_comment

end_unit

