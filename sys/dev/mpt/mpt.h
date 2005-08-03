begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Generic defines for LSI '909 FC  adapters.  * FreeBSD Version.  *  * Copyright (c)  2000, 2001 by Greg Ansley  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Additional Copyright (c) 2002 by Matthew Jacob under same license.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004, Avid Technology, Inc. and its contributors.  * Copyright (c) 2004, 2005 Justin T. Gibbs  * Copyright (c) 2005, WHEEL Sp. z o.o.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the names of the above listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPT_H_
end_define

begin_comment
comment|/********************************* OS Includes ********************************/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

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
file|<sys/module.h>
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
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_comment
comment|/**************************** Register Definitions ****************************/
end_comment

begin_include
include|#
directive|include
file|<dev/mpt/mpt_reg.h>
end_include

begin_comment
comment|/******************************* MPI Definitions ******************************/
end_comment

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi_type.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi_cnfg.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi_ioc.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi_raid.h>
end_include

begin_comment
comment|/* XXX For mpt_debug.c */
end_comment

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi_init.h>
end_include

begin_comment
comment|/****************************** Misc Definitions ******************************/
end_comment

begin_define
define|#
directive|define
name|MPT_OK
value|(0)
end_define

begin_define
define|#
directive|define
name|MPT_FAIL
value|(0x10000)
end_define

begin_define
define|#
directive|define
name|NUM_ELEMENTS
parameter_list|(
name|array
parameter_list|)
value|(sizeof(array) / sizeof(*array))
end_define

begin_comment
comment|/**************************** Forward Declarations ****************************/
end_comment

begin_struct_decl
struct_decl|struct
name|mpt_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mpt_personality
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|req_entry
name|request_t
typedef|;
end_typedef

begin_comment
comment|/************************* Personality Module Support *************************/
end_comment

begin_typedef
typedef|typedef
name|int
name|mpt_load_handler_t
parameter_list|(
name|struct
name|mpt_personality
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mpt_probe_handler_t
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mpt_attach_handler_t
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mpt_event_handler_t
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|request_t
modifier|*
parameter_list|,
name|MSG_EVENT_NOTIFY_REPLY
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|mpt_reset_handler_t
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|int
comment|/*type*/
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* XXX Add return value and use for veto? */
end_comment

begin_typedef
typedef|typedef
name|void
name|mpt_shutdown_handler_t
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|mpt_detach_handler_t
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mpt_unload_handler_t
parameter_list|(
name|struct
name|mpt_personality
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|mpt_personality
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
comment|/* Assigned identifier. */
name|u_int
name|use_count
decl_stmt|;
comment|/* Instances using personality*/
name|mpt_load_handler_t
modifier|*
name|load
decl_stmt|;
comment|/* configure personailty */
define|#
directive|define
name|MPT_PERS_FIRST_HANDLER
parameter_list|(
name|pers
parameter_list|)
value|(&(pers)->load)
name|mpt_probe_handler_t
modifier|*
name|probe
decl_stmt|;
comment|/* configure personailty */
name|mpt_attach_handler_t
modifier|*
name|attach
decl_stmt|;
comment|/* initialize device instance */
name|mpt_event_handler_t
modifier|*
name|event
decl_stmt|;
comment|/* Handle MPI event. */
name|mpt_reset_handler_t
modifier|*
name|reset
decl_stmt|;
comment|/* Re-init after reset. */
name|mpt_shutdown_handler_t
modifier|*
name|shutdown
decl_stmt|;
comment|/* Shutdown instance. */
name|mpt_detach_handler_t
modifier|*
name|detach
decl_stmt|;
comment|/* release device instance */
name|mpt_unload_handler_t
modifier|*
name|unload
decl_stmt|;
comment|/* Shutdown personality */
define|#
directive|define
name|MPT_PERS_LAST_HANDLER
parameter_list|(
name|pers
parameter_list|)
value|(&(pers)->unload)
block|}
struct|;
end_struct

begin_function_decl
name|int
name|mpt_modevent
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Maximum supported number of personalities. */
end_comment

begin_define
define|#
directive|define
name|MPT_MAX_PERSONALITIES
value|(15)
end_define

begin_define
define|#
directive|define
name|MPT_PERSONALITY_DEPEND
parameter_list|(
name|name
parameter_list|,
name|dep
parameter_list|,
name|vmin
parameter_list|,
name|vpref
parameter_list|,
name|vmax
parameter_list|)
define|\
value|MODULE_DEPEND(name, dep, vmin, vpref, vmax)
end_define

begin_define
define|#
directive|define
name|DECLARE_MPT_PERSONALITY
parameter_list|(
name|name
parameter_list|,
name|order
parameter_list|)
define|\
value|static moduledata_t name##_mod = {				  \ 		#name, mpt_modevent,&name##_personality		  \ 	};								  \ 	DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, order);	  \ 	MODULE_VERSION(name, 1);					  \ 	MPT_PERSONALITY_DEPEND(name, mpt_core, 1, 1, 1)
end_define

begin_comment
comment|/******************************* Bus DMA Support ******************************/
end_comment

begin_comment
comment|/* XXX Need to update bus_dmamap_sync to take a range argument. */
end_comment

begin_define
define|#
directive|define
name|bus_dmamap_sync_range
parameter_list|(
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|501102
end_if

begin_define
define|#
directive|define
name|mpt_dma_tag_create
parameter_list|(
name|mpt
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
value|bus_dma_tag_create(parent_tag, alignment, boundary,		\ 			   lowaddr, highaddr, filter, filterarg,	\ 			   maxsize, nsegments, maxsegsz, flags,		\ 			   busdma_lock_mutex,&Giant,			\ 			   dma_tagp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mpt_dma_tag_create
parameter_list|(
name|mpt
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

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|mpt_map_info
block|{
name|struct
name|mpt_softc
modifier|*
name|mpt
decl_stmt|;
name|int
name|error
decl_stmt|;
name|uint32_t
name|phys
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|mpt_map_rquest
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************** Kernel Thread Support ***************************/
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|500005
end_if

begin_define
define|#
directive|define
name|mpt_kthread_create
parameter_list|(
name|func
parameter_list|,
name|farg
parameter_list|,
name|proc_ptr
parameter_list|,
name|flags
parameter_list|,
name|stackpgs
parameter_list|,
name|fmtstr
parameter_list|,
name|arg
parameter_list|)
define|\
value|kthread_create(func, farg, proc_ptr, flags, stackpgs, fmtstr, arg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mpt_kthread_create
parameter_list|(
name|func
parameter_list|,
name|farg
parameter_list|,
name|proc_ptr
parameter_list|,
name|flags
parameter_list|,
name|stackpgs
parameter_list|,
name|fmtstr
parameter_list|,
name|arg
parameter_list|)
define|\
value|kthread_create(func, farg, proc_ptr, fmtstr, arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************** Timer Facilities ******************************/
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|500000
end_if

begin_define
define|#
directive|define
name|mpt_callout_init
parameter_list|(
name|c
parameter_list|)
value|callout_init(c,
comment|/*mpsafe*/
value|0);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mpt_callout_init
parameter_list|(
name|c
parameter_list|)
value|callout_init(c);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************************** Endianess *********************************/
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|u64toh
parameter_list|(
name|U64
name|s
parameter_list|)
block|{
name|uint64_t
name|result
decl_stmt|;
name|result
operator|=
name|le32toh
argument_list|(
name|s
operator|.
name|Low
argument_list|)
expr_stmt|;
name|result
operator||=
operator|(
operator|(
name|uint64_t
operator|)
name|le32toh
argument_list|(
name|s
operator|.
name|High
argument_list|)
operator|)
operator|<<
literal|32
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_comment
comment|/**************************** MPI Transaction State ***************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|REQ_STATE_FREE
init|=
literal|0x00
block|,
name|REQ_STATE_ALLOCATED
init|=
literal|0x01
block|,
name|REQ_STATE_QUEUED
init|=
literal|0x02
block|,
name|REQ_STATE_DONE
init|=
literal|0x04
block|,
name|REQ_STATE_TIMEDOUT
init|=
literal|0x08
block|,
name|REQ_STATE_NEED_WAKEUP
init|=
literal|0x10
block|,
name|REQ_STATE_MASK
init|=
literal|0xFF
block|}
name|mpt_req_state_t
typedef|;
end_typedef

begin_struct
struct|struct
name|req_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|req_entry
argument_list|)
name|links
expr_stmt|;
comment|/* Pointer to next in list */
name|mpt_req_state_t
name|state
decl_stmt|;
comment|/* Request State Information */
name|uint16_t
name|index
decl_stmt|;
comment|/* Index of this entry */
name|uint16_t
name|IOCStatus
decl_stmt|;
comment|/* Completion status */
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
block|}
struct|;
end_struct

begin_comment
comment|/**************************** Handler Registration ****************************/
end_comment

begin_comment
comment|/*  * Global table of registered reply handlers.  The  * handler is indicated by byte 3 of the request  * index submitted to the IOC.  This allows the  * driver core to perform generic processing without  * any knowledge of per-personality behavior.  *  * MPT_NUM_REPLY_HANDLERS must be a power of 2  * to allow the easy generation of a mask.  *  * The handler offsets used by the core are hard coded  * allowing faster code generation when assigning a handler  * to a request.  All "personalities" must use the  * the handler registration mechanism.  *  * The IOC handlers that are rarely executed are placed  * at the tail of the table to make it more likely that  * all commonly executed handlers fit in a single cache  * line.  */
end_comment

begin_define
define|#
directive|define
name|MPT_NUM_REPLY_HANDLERS
value|(16)
end_define

begin_define
define|#
directive|define
name|MPT_REPLY_HANDLER_EVENTS
value|MPT_CBI_TO_HID(0)
end_define

begin_define
define|#
directive|define
name|MPT_REPLY_HANDLER_CONFIG
value|MPT_CBI_TO_HID(MPT_NUM_REPLY_HANDLERS-1)
end_define

begin_define
define|#
directive|define
name|MPT_REPLY_HANDLER_HANDSHAKE
value|MPT_CBI_TO_HID(MPT_NUM_REPLY_HANDLERS-2)
end_define

begin_typedef
typedef|typedef
name|int
name|mpt_reply_handler_t
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|request_t
modifier|*
name|request
parameter_list|,
name|MSG_DEFAULT_REPLY
modifier|*
name|reply_frame
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|mpt_reply_handler_t
modifier|*
name|reply_handler
decl_stmt|;
block|}
name|mpt_handler_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|MPT_HANDLER_REPLY
block|,
name|MPT_HANDLER_EVENT
block|,
name|MPT_HANDLER_RESET
block|,
name|MPT_HANDLER_SHUTDOWN
block|}
name|mpt_handler_type
typedef|;
end_typedef

begin_struct
struct|struct
name|mpt_handler_record
block|{
name|LIST_ENTRY
argument_list|(
argument|mpt_handler_record
argument_list|)
name|links
expr_stmt|;
name|mpt_handler_t
name|handler
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|mpt_handler_list
argument_list|,
name|mpt_handler_record
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The handler_id is currently unused but would contain the  * handler ID used in the MsgContext field to allow direction  * of replies to the handler.  Registrations that don't require  * a handler id can pass in NULL for the handler_id.  *  * Deregistrations for handlers without a handler id should  * pass in MPT_HANDLER_ID_NONE.  */
end_comment

begin_define
define|#
directive|define
name|MPT_HANDLER_ID_NONE
value|(0xFFFFFFFF)
end_define

begin_function_decl
name|int
name|mpt_register_handler
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|mpt_handler_type
parameter_list|,
name|mpt_handler_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_deregister_handler
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|mpt_handler_type
parameter_list|,
name|mpt_handler_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************* Per-Controller Instance Data Structures ******************/
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|req_queue
argument_list|,
name|req_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Structure for saving proper values for modifyable PCI config registers */
end_comment

begin_struct
struct|struct
name|mpt_pci_cfg
block|{
name|uint16_t
name|Command
decl_stmt|;
name|uint16_t
name|LatencyTimer_LineSize
decl_stmt|;
name|uint32_t
name|IO_BAR
decl_stmt|;
name|uint32_t
name|Mem0_BAR
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|Mem1_BAR
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|ROM_BAR
decl_stmt|;
name|uint8_t
name|IntLine
decl_stmt|;
name|uint32_t
name|PMCSR
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|MPT_RVF_NONE
init|=
literal|0x0
block|,
name|MPT_RVF_ACTIVE
init|=
literal|0x1
block|,
name|MPT_RVF_ANNOUNCED
init|=
literal|0x2
block|,
name|MPT_RVF_UP2DATE
init|=
literal|0x4
block|,
name|MPT_RVF_REFERENCED
init|=
literal|0x8
block|,
name|MPT_RVF_WCE_CHANGED
init|=
literal|0x10
block|}
name|mpt_raid_volume_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|mpt_raid_volume
block|{
name|CONFIG_PAGE_RAID_VOL_0
modifier|*
name|config_page
decl_stmt|;
name|MPI_RAID_VOL_INDICATOR
name|sync_progress
decl_stmt|;
name|mpt_raid_volume_flags
name|flags
decl_stmt|;
name|u_int
name|quieced_disks
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|MPT_RDF_NONE
init|=
literal|0x00
block|,
name|MPT_RDF_ACTIVE
init|=
literal|0x01
block|,
name|MPT_RDF_ANNOUNCED
init|=
literal|0x02
block|,
name|MPT_RDF_UP2DATE
init|=
literal|0x04
block|,
name|MPT_RDF_REFERENCED
init|=
literal|0x08
block|,
name|MPT_RDF_QUIESCING
init|=
literal|0x10
block|,
name|MPT_RDF_QUIESCED
init|=
literal|0x20
block|}
name|mpt_raid_disk_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|mpt_raid_disk
block|{
name|CONFIG_PAGE_RAID_PHYS_DISK_0
name|config_page
decl_stmt|;
name|struct
name|mpt_raid_volume
modifier|*
name|volume
decl_stmt|;
name|u_int
name|member_number
decl_stmt|;
name|u_int
name|pass_thru_active
decl_stmt|;
name|mpt_raid_disk_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpt_evtf_record
block|{
name|MSG_EVENT_NOTIFY_REPLY
name|reply
decl_stmt|;
name|uint32_t
name|context
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|mpt_evtf_record
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|mpt_evtf_list
argument_list|,
name|mpt_evtf_record
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|mpt_softc
block|{
name|device_t
name|dev
decl_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
name|int
name|mpt_splsaved
decl_stmt|;
name|uint32_t
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
name|uint32_t
name|mpt_pers_mask
decl_stmt|;
name|uint32_t
label|:
literal|15
operator|,
name|raid_mwce_set
operator|:
literal|1
operator|,
name|getreqwaiter
operator|:
literal|1
operator|,
name|shutdwn_raid
operator|:
literal|1
operator|,
name|shutdwn_recovery
operator|:
literal|1
operator|,
name|unit
operator|:
literal|8
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
name|u_int
name|verbose
decl_stmt|;
comment|/* 	 * IOC Facts 	 */
name|uint16_t
name|mpt_global_credits
decl_stmt|;
name|uint16_t
name|request_frame_size
decl_stmt|;
name|uint8_t
name|mpt_max_devices
decl_stmt|;
name|uint8_t
name|mpt_max_buses
decl_stmt|;
comment|/* 	 * Port Facts 	 * XXX - Add multi-port support!. 	 */
name|uint16_t
name|mpt_ini_id
decl_stmt|;
name|uint16_t
name|mpt_port_type
decl_stmt|;
name|uint16_t
name|mpt_proto_flags
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
name|uint8_t
name|nada
decl_stmt|;
block|}
name|fc
struct|;
block|}
name|cfg
union|;
comment|/* Controller Info */
name|CONFIG_PAGE_IOC_2
modifier|*
name|ioc_page2
decl_stmt|;
name|CONFIG_PAGE_IOC_3
modifier|*
name|ioc_page3
decl_stmt|;
comment|/* Raid Data */
name|struct
name|mpt_raid_volume
modifier|*
name|raid_volumes
decl_stmt|;
name|struct
name|mpt_raid_disk
modifier|*
name|raid_disks
decl_stmt|;
name|u_int
name|raid_max_volumes
decl_stmt|;
name|u_int
name|raid_max_disks
decl_stmt|;
name|u_int
name|raid_page0_len
decl_stmt|;
name|u_int
name|raid_wakeup
decl_stmt|;
name|u_int
name|raid_rescan
decl_stmt|;
name|u_int
name|raid_resync_rate
decl_stmt|;
name|u_int
name|raid_mwce_setting
decl_stmt|;
name|u_int
name|raid_queue_depth
decl_stmt|;
name|struct
name|proc
modifier|*
name|raid_thread
decl_stmt|;
name|struct
name|callout
name|raid_timer
decl_stmt|;
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
name|pci_mem_rid
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
comment|/* PIO versions of above. */
name|int
name|pci_pio_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|pci_pio_reg
decl_stmt|;
name|bus_space_tag_t
name|pci_pio_st
decl_stmt|;
name|bus_space_handle_t
name|pci_pio_sh
decl_stmt|;
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
name|uint8_t
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
name|uint8_t
modifier|*
name|request
decl_stmt|;
comment|/* KVA of Request memory */
name|bus_addr_t
name|request_phys
decl_stmt|;
comment|/* BusADdr of request memory */
name|u_int
name|reset_cnt
decl_stmt|;
comment|/* 	 * CAM&& Software Management 	 */
name|request_t
modifier|*
name|request_pool
decl_stmt|;
name|struct
name|req_queue
name|request_free_list
decl_stmt|;
name|struct
name|req_queue
name|request_pending_list
decl_stmt|;
name|struct
name|req_queue
name|request_timeout_list
decl_stmt|;
comment|/* 	 * Deferred frame acks due to resource shortage. 	 */
name|struct
name|mpt_evtf_list
name|ack_frames
decl_stmt|;
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
name|struct
name|cam_sim
modifier|*
name|phydisk_sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|phydisk_path
decl_stmt|;
name|struct
name|proc
modifier|*
name|recovery_thread
decl_stmt|;
name|request_t
modifier|*
name|tmf_req
decl_stmt|;
name|uint32_t
name|sequence
decl_stmt|;
comment|/* Sequence Number */
name|uint32_t
name|timeouts
decl_stmt|;
comment|/* timeout count */
name|uint32_t
name|success
decl_stmt|;
comment|/* successes afer timeout */
comment|/* Opposing port in a 929 or 1030, or NULL */
name|struct
name|mpt_softc
modifier|*
name|mpt2
decl_stmt|;
comment|/* FW Image management */
name|uint32_t
name|fw_image_size
decl_stmt|;
name|uint8_t
modifier|*
name|fw_image
decl_stmt|;
name|bus_dma_tag_t
name|fw_dmat
decl_stmt|;
comment|/* DMA tag for firmware image */
name|bus_dmamap_t
name|fw_dmap
decl_stmt|;
comment|/* DMA map for firmware image */
name|bus_addr_t
name|fw_phys
decl_stmt|;
comment|/* BusAddr of request memory */
comment|/* Shutdown Event Handler. */
name|eventhandler_tag
name|eh
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|mpt_softc
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***************************** Locking Primatives *****************************/
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

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

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_lockspl
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_unlockspl
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|mpt_lockspl
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splcam
argument_list|()
expr_stmt|;
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
name|panic
argument_list|(
literal|"Recursed lock with mask: 0x%x\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mpt_unlockspl
parameter_list|(
name|struct
name|mpt_softc
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
else|else
name|panic
argument_list|(
literal|"Negative lock count\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|mpt_sleep
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|void
modifier|*
name|ident
parameter_list|,
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|timo
parameter_list|)
block|{
name|int
name|saved_cnt
decl_stmt|;
name|int
name|saved_spl
decl_stmt|;
name|int
name|error
decl_stmt|;
name|KASSERT
argument_list|(
name|mpt
operator|->
name|mpt_islocked
operator|<=
literal|1
argument_list|,
operator|(
literal|"Invalid lock count on tsleep"
operator|)
argument_list|)
expr_stmt|;
name|saved_cnt
operator|=
name|mpt
operator|->
name|mpt_islocked
expr_stmt|;
name|saved_spl
operator|=
name|mpt
operator|->
name|mpt_splsaved
expr_stmt|;
name|mpt
operator|->
name|mpt_islocked
operator|=
literal|0
expr_stmt|;
name|error
operator|=
name|tsleep
argument_list|(
name|ident
argument_list|,
name|priority
argument_list|,
name|wmesg
argument_list|,
name|timo
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|mpt
operator|->
name|mpt_islocked
operator|=
literal|0
argument_list|,
operator|(
literal|"Invalid lock count on wakeup"
operator|)
argument_list|)
expr_stmt|;
name|mpt
operator|->
name|mpt_islocked
operator|=
name|saved_cnt
expr_stmt|;
name|mpt
operator|->
name|mpt_splsaved
operator|=
name|saved_spl
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LOCKING_WORKED_AS_IT_SHOULD
end_if

begin_error
error|#
directive|error
literal|"Shouldn't Be Here!"
end_error

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

begin_define
define|#
directive|define
name|mpt_sleep
parameter_list|(
name|mpt
parameter_list|,
name|ident
parameter_list|,
name|priority
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|msleep(ident,&(mpt)->mpt_lock, priority, wmesg, timo)
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

begin_define
define|#
directive|define
name|mpt_sleep
parameter_list|(
name|mpt
parameter_list|,
name|ident
parameter_list|,
name|priority
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|tsleep(ident, priority, wmesg, timo)
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
comment|/******************************* Register Access ******************************/
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_write
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|uint32_t
name|mpt_read
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_pio_write
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|uint32_t
name|mpt_pio_read
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
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
name|uint32_t
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
name|__inline
name|uint32_t
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

begin_comment
comment|/*  * Some operations (e.g. diagnostic register writes while the ARM proccessor  * is disabled), must be performed using "PCI pio" operations.  On non-PCI  * busses, these operations likely map to normal register accesses.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mpt_pio_write
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|bus_space_write_4
argument_list|(
name|mpt
operator|->
name|pci_pio_st
argument_list|,
name|mpt
operator|->
name|pci_pio_sh
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
name|__inline
name|uint32_t
name|mpt_pio_read
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
operator|(
name|bus_space_read_4
argument_list|(
name|mpt
operator|->
name|pci_pio_st
argument_list|,
name|mpt
operator|->
name|pci_pio_sh
argument_list|,
name|offset
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*********************** Reply Frame/Request Management ***********************/
end_comment

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
value|((mpt)->is_fc ? 1024 : 256)
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

begin_define
define|#
directive|define
name|MPT_CONTEXT_CB_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|MPT_CBI
parameter_list|(
name|handle
parameter_list|)
value|(handle>> MPT_CONTEXT_CB_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPT_CBI_TO_HID
parameter_list|(
name|cbi
parameter_list|)
value|((cbi)<< MPT_CONTEXT_CB_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPT_CONTEXT_TO_CBI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> MPT_CONTEXT_CB_SHIFT)& (MPT_NUM_REPLY_HANDLERS - 1))
end_define

begin_define
define|#
directive|define
name|MPT_CONTEXT_REQI_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|MPT_CONTEXT_TO_REQI
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& MPT_CONTEXT_REQI_MASK)
end_define

begin_comment
comment|/*  * Convert a 32bit physical address returned from IOC to an  * offset into our reply frame memory or the kvm address needed  * to access the data.  The returned address is only the low  * 32 bits, so mask our base physical address accordingly.  */
end_comment

begin_define
define|#
directive|define
name|MPT_REPLY_BADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(x<< 1)
end_define

begin_define
define|#
directive|define
name|MPT_REPLY_OTOV
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|)
define|\
value|((void *)(&m->reply[i]))
end_define

begin_define
define|#
directive|define
name|MPT_DUMP_REPLY_FRAME
parameter_list|(
name|mpt
parameter_list|,
name|reply_frame
parameter_list|)
define|\
value|do {							\ 	if (mpt->verbose>= MPT_PRT_DEBUG)		\ 		mpt_dump_reply_frame(mpt, reply_frame);	\ } while(0)
end_define

begin_function_decl
specifier|static
name|__inline
name|uint32_t
name|mpt_pop_reply_queue
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_free_reply
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|uint32_t
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Give the reply buffer back to the IOC after we have  * finished processing it.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mpt_free_reply
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|uint32_t
name|ptr
parameter_list|)
block|{
name|mpt_write
argument_list|(
name|mpt
argument_list|,
name|MPT_OFFSET_REPLY_Q
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Get a reply from the IOC */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|mpt_pop_reply_queue
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
block|{
return|return
name|mpt_read
argument_list|(
name|mpt
argument_list|,
name|MPT_OFFSET_REPLY_Q
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|void
name|mpt_complete_request_chain
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|struct
name|req_queue
modifier|*
name|chain
parameter_list|,
name|u_int
name|iocstatus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** Scatter Gather Managment **************************/
end_comment

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
comment|/***************************** IOC Initialization *****************************/
end_comment

begin_function_decl
name|int
name|mpt_reset
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|int
comment|/*reinit*/
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************** Debugging/Logging *****************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mpt_decode_entry
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|u_int
name|value
decl_stmt|;
name|u_int
name|mask
decl_stmt|;
block|}
name|mpt_decode_entry_t
typedef|;
end_typedef

begin_function_decl
name|int
name|mpt_decode_value
parameter_list|(
name|mpt_decode_entry_t
modifier|*
name|table
parameter_list|,
name|u_int
name|num_entries
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|u_int
name|value
parameter_list|,
name|u_int
modifier|*
name|cur_column
parameter_list|,
name|u_int
name|wrap_point
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|MPT_PRT_ALWAYS
block|,
name|MPT_PRT_FATAL
block|,
name|MPT_PRT_ERROR
block|,
name|MPT_PRT_WARN
block|,
name|MPT_PRT_INFO
block|,
name|MPT_PRT_DEBUG
block|,
name|MPT_PRT_TRACE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|mpt_lprt
parameter_list|(
name|mpt
parameter_list|,
name|level
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {						\ 	if (level<= (mpt)->verbose)		\ 		mpt_prt(mpt, __VA_ARGS__);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|mpt_lprtc
parameter_list|(
name|mpt
parameter_list|,
name|level
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {						 \ 	if (level<= (mpt)->debug_level)	 \ 		mpt_prtc(mpt, __VA_ARGS__);	 \ } while (0)
end_define

begin_function_decl
name|void
name|mpt_prt
parameter_list|(
name|struct
name|mpt_softc
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
name|mpt_prtc
parameter_list|(
name|struct
name|mpt_softc
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

begin_comment
comment|/**************************** Unclassified Routines ***************************/
end_comment

begin_function_decl
name|void
name|mpt_send_cmd
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|request_t
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_recv_handshake_reply
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|size_t
name|reply_len
parameter_list|,
name|void
modifier|*
name|reply
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_wait_req
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|request_t
modifier|*
name|req
parameter_list|,
name|mpt_req_state_t
name|state
parameter_list|,
name|mpt_req_state_t
name|mask
parameter_list|,
name|int
name|sleep_ok
parameter_list|,
name|int
name|time_ms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_enable_ints
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
name|mpt_disable_ints
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_attach
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_shutdown
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_detach
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_send_handshake_cmd
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|size_t
name|len
parameter_list|,
name|void
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|request_t
modifier|*
name|mpt_get_request
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|int
name|sleep_ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_free_request
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|request_t
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_check_doorbell
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
name|mpt_dump_reply_frame
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|MSG_DEFAULT_REPLY
modifier|*
name|reply_frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_set_config_regs
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_issue_cfg_req
parameter_list|(
name|struct
name|mpt_softc
modifier|*
comment|/*mpt*/
parameter_list|,
name|request_t
modifier|*
comment|/*req*/
parameter_list|,
name|u_int
comment|/*Action*/
parameter_list|,
name|u_int
comment|/*PageVersion*/
parameter_list|,
name|u_int
comment|/*PageLength*/
parameter_list|,
name|u_int
comment|/*PageNumber*/
parameter_list|,
name|u_int
comment|/*PageType*/
parameter_list|,
name|uint32_t
comment|/*PageAddress*/
parameter_list|,
name|bus_addr_t
comment|/*addr*/
parameter_list|,
name|bus_size_t
comment|/*len*/
parameter_list|,
name|int
comment|/*sleep_ok*/
parameter_list|,
name|int
comment|/*timeout_ms*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_read_cfg_header
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|int
comment|/*PageType*/
parameter_list|,
name|int
comment|/*PageNumber*/
parameter_list|,
name|uint32_t
comment|/*PageAddress*/
parameter_list|,
name|CONFIG_PAGE_HEADER
modifier|*
parameter_list|,
name|int
comment|/*sleep_ok*/
parameter_list|,
name|int
comment|/*timeout_ms*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_read_cfg_page
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|t
parameter_list|,
name|int
comment|/*Action*/
parameter_list|,
name|uint32_t
comment|/*PageAddress*/
parameter_list|,
name|CONFIG_PAGE_HEADER
modifier|*
parameter_list|,
name|size_t
comment|/*len*/
parameter_list|,
name|int
comment|/*sleep_ok*/
parameter_list|,
name|int
comment|/*timeout_ms*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpt_write_cfg_page
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|int
comment|/*Action*/
parameter_list|,
name|uint32_t
comment|/*PageAddress*/
parameter_list|,
name|CONFIG_PAGE_HEADER
modifier|*
parameter_list|,
name|size_t
comment|/*len*/
parameter_list|,
name|int
comment|/*sleep_ok*/
parameter_list|,
name|int
comment|/*timeout_ms*/
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|mpt_read_cur_cfg_page
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|uint32_t
name|PageAddress
parameter_list|,
name|CONFIG_PAGE_HEADER
modifier|*
name|hdr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|sleep_ok
parameter_list|,
name|int
name|timeout_ms
parameter_list|)
block|{
return|return
operator|(
name|mpt_read_cfg_page
argument_list|(
name|mpt
argument_list|,
name|MPI_CONFIG_ACTION_PAGE_READ_CURRENT
argument_list|,
name|PageAddress
argument_list|,
name|hdr
argument_list|,
name|len
argument_list|,
name|sleep_ok
argument_list|,
name|timeout_ms
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|mpt_write_cur_cfg_page
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|uint32_t
name|PageAddress
parameter_list|,
name|CONFIG_PAGE_HEADER
modifier|*
name|hdr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|sleep_ok
parameter_list|,
name|int
name|timeout_ms
parameter_list|)
block|{
return|return
operator|(
name|mpt_write_cfg_page
argument_list|(
name|mpt
argument_list|,
name|MPI_CONFIG_ACTION_PAGE_WRITE_CURRENT
argument_list|,
name|PageAddress
argument_list|,
name|hdr
argument_list|,
name|len
argument_list|,
name|sleep_ok
argument_list|,
name|timeout_ms
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* mpt_debug.c functions */
end_comment

begin_function_decl
name|void
name|mpt_print_reply
parameter_list|(
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_db
parameter_list|(
name|uint32_t
name|mb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_config_reply
parameter_list|(
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mpt_ioc_diag
parameter_list|(
name|uint32_t
name|diag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_req_state
parameter_list|(
name|mpt_req_state_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_config_request
parameter_list|(
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_request
parameter_list|(
name|void
modifier|*
name|vmsg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_print_scsi_io_request
parameter_list|(
name|MSG_SCSI_IO_REQUEST
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MPT_H_ */
end_comment

end_unit

