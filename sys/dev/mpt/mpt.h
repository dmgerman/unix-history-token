begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Generic defines for LSI '909 FC  adapters.  * FreeBSD Version.  *  * Copyright (c)  2000, 2001 by Greg Ansley  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2006 by Matthew Jacob  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the names of the above listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Support from Chris Ellsworth in order to make SAS adapters work  * is gratefully acknowledged.  *  *  * Support from LSI-Logic has also gone a great deal toward making this a  * workable subsystem and is gratefully acknowledged.  */
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
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/rman.h>
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
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/bus.h>
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

begin_define
define|#
directive|define
name|MPT_S64_2_SCALAR
parameter_list|(
name|y
parameter_list|)
value|((((int64_t)y.High)<< 32) | (y.Low))
end_define

begin_define
define|#
directive|define
name|MPT_U64_2_SCALAR
parameter_list|(
name|y
parameter_list|)
value|((((uint64_t)y.High)<< 32) | (y.Low))
end_define

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

begin_define
define|#
directive|define
name|MPT_ROLE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|MPT_ROLE_INITIATOR
value|1
end_define

begin_define
define|#
directive|define
name|MPT_ROLE_TARGET
value|2
end_define

begin_define
define|#
directive|define
name|MPT_ROLE_BOTH
value|3
end_define

begin_define
define|#
directive|define
name|MPT_ROLE_DEFAULT
value|MPT_ROLE_INITIATOR
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
name|mpt_enable_handler_t
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
name|mpt_ready_handler_t
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
name|mpt_enable_handler_t
modifier|*
name|enable
decl_stmt|;
comment|/* enable device */
name|mpt_ready_handler_t
modifier|*
name|ready
decl_stmt|;
comment|/* final open for business */
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

begin_define
define|#
directive|define
name|MPT_2_HOST64
parameter_list|(
name|ptr
parameter_list|,
name|tag
parameter_list|)
value|ptr->tag = le64toh(ptr->tag)
end_define

begin_define
define|#
directive|define
name|MPT_2_HOST32
parameter_list|(
name|ptr
parameter_list|,
name|tag
parameter_list|)
value|ptr->tag = le32toh(ptr->tag)
end_define

begin_define
define|#
directive|define
name|MPT_2_HOST16
parameter_list|(
name|ptr
parameter_list|,
name|tag
parameter_list|)
value|ptr->tag = le16toh(ptr->tag)
end_define

begin_define
define|#
directive|define
name|HOST_2_MPT64
parameter_list|(
name|ptr
parameter_list|,
name|tag
parameter_list|)
value|ptr->tag = htole64(ptr->tag)
end_define

begin_define
define|#
directive|define
name|HOST_2_MPT32
parameter_list|(
name|ptr
parameter_list|,
name|tag
parameter_list|)
value|ptr->tag = htole32(ptr->tag)
end_define

begin_define
define|#
directive|define
name|HOST_2_MPT16
parameter_list|(
name|ptr
parameter_list|,
name|tag
parameter_list|)
value|ptr->tag = htole16(ptr->tag)
end_define

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_function_decl
name|void
name|mpt2host_sge_simple_union
parameter_list|(
name|SGE_SIMPLE_UNION
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt2host_iocfacts_reply
parameter_list|(
name|MSG_IOC_FACTS_REPLY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt2host_portfacts_reply
parameter_list|(
name|MSG_PORT_FACTS_REPLY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt2host_config_page_ioc2
parameter_list|(
name|CONFIG_PAGE_IOC_2
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt2host_config_page_raid_vol_0
parameter_list|(
name|CONFIG_PAGE_RAID_VOL_0
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt2host_mpi_raid_vol_indicator
parameter_list|(
name|MPI_RAID_VOL_INDICATOR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mpt2host_sge_simple_union
parameter_list|(
name|x
parameter_list|)
value|do { ; } while (0)
end_define

begin_define
define|#
directive|define
name|mpt2host_iocfacts_reply
parameter_list|(
name|x
parameter_list|)
value|do { ; } while (0)
end_define

begin_define
define|#
directive|define
name|mpt2host_portfacts_reply
parameter_list|(
name|x
parameter_list|)
value|do { ; } while (0)
end_define

begin_define
define|#
directive|define
name|mpt2host_config_page_ioc2
parameter_list|(
name|x
parameter_list|)
value|do { ; } while (0)
end_define

begin_define
define|#
directive|define
name|mpt2host_config_page_raid_vol_0
parameter_list|(
name|x
parameter_list|)
value|do { ; } while (0)
end_define

begin_define
define|#
directive|define
name|mpt2host_mpi_raid_vol_indicator
parameter_list|(
name|x
parameter_list|)
value|do { ; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**************************** MPI Transaction State ***************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|REQ_STATE_NIL
init|=
literal|0x00
block|,
name|REQ_STATE_FREE
init|=
literal|0x01
block|,
name|REQ_STATE_ALLOCATED
init|=
literal|0x02
block|,
name|REQ_STATE_QUEUED
init|=
literal|0x04
block|,
name|REQ_STATE_DONE
init|=
literal|0x08
block|,
name|REQ_STATE_TIMEDOUT
init|=
literal|0x10
block|,
name|REQ_STATE_NEED_WAKEUP
init|=
literal|0x20
block|,
name|REQ_STATE_LOCKED
init|=
literal|0x80
block|,
comment|/* can't be freed */
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
name|uint16_t
name|ResponseCode
decl_stmt|;
comment|/* TMF Reponse Code */
name|uint16_t
name|serno
decl_stmt|;
comment|/* serial number */
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
comment|/* DMA map for data buffers */
name|struct
name|req_entry
modifier|*
name|chain
decl_stmt|;
comment|/* for SGE overallocations */
block|}
struct|;
end_struct

begin_comment
comment|/**************************** MPI Target State Info ***************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|reply_desc
decl_stmt|;
comment|/* current reply descriptor */
name|uint32_t
name|resid
decl_stmt|;
comment|/* current data residual */
name|uint32_t
name|bytes_xfered
decl_stmt|;
comment|/* current relative offset */
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
comment|/* pointer to currently active ccb */
name|request_t
modifier|*
name|req
decl_stmt|;
comment|/* pointer to currently active assist request */
name|uint32_t
name|is_local
range|:
literal|1
decl_stmt|,
name|nxfers
range|:
literal|31
decl_stmt|;
name|uint32_t
name|tag_id
decl_stmt|;
enum|enum
block|{
name|TGT_STATE_NIL
block|,
name|TGT_STATE_LOADING
block|,
name|TGT_STATE_LOADED
block|,
name|TGT_STATE_IN_CAM
block|,
name|TGT_STATE_SETTING_UP_FOR_DATA
block|,
name|TGT_STATE_MOVING_DATA
block|,
name|TGT_STATE_MOVING_DATA_AND_STATUS
block|,
name|TGT_STATE_SENDING_STATUS
block|}
name|state
enum|;
block|}
name|mpt_tgt_state_t
typedef|;
end_typedef

begin_comment
comment|/*  * When we get an incoming command it has its own tag which is called the  * IoIndex. This is the value we gave that particular command buffer when  * we originally assigned it. It's just a number, really. The FC card uses  * it as an RX_ID. We can use it to index into mpt->tgt_cmd_ptrs, which  * contains pointers the request_t structures related to that IoIndex.  *  * What *we* do is construct a tag out of the index for the target command  * which owns the incoming ATIO plus a rolling sequence number.  */
end_comment

begin_define
define|#
directive|define
name|MPT_MAKE_TAGID
parameter_list|(
name|mpt
parameter_list|,
name|req
parameter_list|,
name|ioindex
parameter_list|)
define|\
value|((ioindex<< 18) | (((mpt->sequence++)& 0x3f)<< 12) | (req->index& 0xfff))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|MPT_TAG_2_REQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|mpt_tag_2_req(a, (uint32_t) b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MPT_TAG_2_REQ
parameter_list|(
name|mpt
parameter_list|,
name|tag
parameter_list|)
value|mpt->tgt_cmd_ptrs[tag>> 18]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MPT_TGT_STATE
parameter_list|(
name|mpt
parameter_list|,
name|req
parameter_list|)
value|((mpt_tgt_state_t *) \     (&((uint8_t *)req->req_vbuf)[MPT_RQSL(mpt) - sizeof (mpt_tgt_state_t)]))
end_define

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|mpt_hdr_stailq
argument_list|,
name|ccb_hdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MPT_MAX_LUNS
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|mpt_hdr_stailq
name|atios
decl_stmt|;
name|struct
name|mpt_hdr_stailq
name|inots
decl_stmt|;
name|int
name|enabled
decl_stmt|;
block|}
name|tgt_resource_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPT_MAX_ELS
value|64
end_define

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
value|(32)
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
name|uint32_t
name|reply_desc
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
name|quiesced_disks
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
name|uint32_t
name|mpt_islocked
decl_stmt|;
name|int
name|mpt_splsaved
decl_stmt|;
else|#
directive|else
name|struct
name|mtx
name|mpt_lock
decl_stmt|;
name|int
name|mpt_locksetup
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|mpt_pers_mask
decl_stmt|;
name|uint32_t
label|:
literal|8
operator|,
name|unit
operator|:
literal|8
operator|,
operator|:
literal|1
operator|,
name|fw_uploaded
operator|:
literal|1
operator|,
name|msi_enable
operator|:
literal|1
operator|,
name|twildcard
operator|:
literal|1
operator|,
name|tenabled
operator|:
literal|1
operator|,
name|do_cfg_role
operator|:
literal|1
operator|,
name|raid_enabled
operator|:
literal|1
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
name|outofbeer
operator|:
literal|1
operator|,
name|disabled
operator|:
literal|1
operator|,
name|is_spi
operator|:
literal|1
operator|,
name|is_sas
operator|:
literal|1
operator|,
name|is_fc
operator|:
literal|1
expr_stmt|;
name|u_int
name|cfg_role
decl_stmt|;
name|u_int
name|role
decl_stmt|;
comment|/* role: none, ini, target, both */
name|u_int
name|verbose
decl_stmt|;
comment|/* 	 * IOC Facts 	 */
name|MSG_IOC_FACTS_REPLY
name|ioc_facts
decl_stmt|;
comment|/* 	 * Port Facts 	 */
name|MSG_PORT_FACTS_REPLY
modifier|*
name|port_facts
decl_stmt|;
define|#
directive|define
name|mpt_ini_id
value|port_facts[0].PortSCSIID
define|#
directive|define
name|mpt_max_tgtcmds
value|port_facts[0].MaxPostedCmdBuffers
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
struct|struct
name|mpi_fc_cfg
block|{
name|CONFIG_PAGE_FC_PORT_0
name|_port_page0
decl_stmt|;
name|uint32_t
name|_port_speed
decl_stmt|;
define|#
directive|define
name|mpt_fcport_page0
value|cfg.fc._port_page0
define|#
directive|define
name|mpt_fcport_speed
value|cfg.fc._port_speed
block|}
name|fc
struct|;
block|}
name|cfg
union|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
comment|/* 	 * Device config information stored up for sysctl to access 	 */
union|union
block|{
struct|struct
block|{
name|unsigned
name|int
name|initiator_id
decl_stmt|;
block|}
name|spi
struct|;
struct|struct
block|{
name|char
name|wwnn
index|[
literal|19
index|]
decl_stmt|;
name|char
name|wwpn
index|[
literal|19
index|]
decl_stmt|;
block|}
name|fc
struct|;
block|}
name|scinfo
union|;
endif|#
directive|endif
comment|/* Controller Info for RAID information */
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
name|u_int
name|raid_nonopt_volumes
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
name|int
name|pci_msi_count
decl_stmt|;
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
comment|/* BusAddr of request memory */
name|uint32_t
name|max_seg_cnt
decl_stmt|;
comment|/* calculated after IOC facts */
comment|/* 	 * Hardware management 	 */
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
comment|/* 	 * Deferred frame acks due to resource shortage. 	 */
name|struct
name|mpt_evtf_list
name|ack_frames
decl_stmt|;
comment|/* 	 * Target Mode Support 	 */
name|uint32_t
name|scsi_tgt_handler_id
decl_stmt|;
name|request_t
modifier|*
modifier|*
name|tgt_cmd_ptrs
decl_stmt|;
name|request_t
modifier|*
modifier|*
name|els_cmd_ptrs
decl_stmt|;
comment|/* FC only */
comment|/* 	 * *snork*- this is chosen to be here *just in case* somebody 	 * forgets to point to it exactly and we index off of trt with 	 * CAM_LUN_WILDCARD. 	 */
name|tgt_resource_t
name|trt_wildcard
decl_stmt|;
comment|/* wildcard luns */
name|tgt_resource_t
name|trt
index|[
name|MPT_MAX_LUNS
index|]
decl_stmt|;
name|uint16_t
name|tgt_cmds_allocated
decl_stmt|;
name|uint16_t
name|els_cmds_allocated
decl_stmt|;
comment|/* FC only */
name|uint16_t
name|timeouts
decl_stmt|;
comment|/* timeout count */
name|uint16_t
name|success
decl_stmt|;
comment|/* successes afer timeout */
name|uint16_t
name|sequence
decl_stmt|;
comment|/* Sequence Number */
name|uint16_t
name|pad3
decl_stmt|;
comment|/* Paired port in some dual adapters configurations */
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
comment|/* BusAddr of firmware image */
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

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_assign_serno
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|request_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|mpt_assign_serno
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
block|{
if|if
condition|(
operator|(
name|req
operator|->
name|serno
operator|=
name|mpt
operator|->
name|sequence
operator|++
operator|)
operator|==
literal|0
condition|)
block|{
name|req
operator|->
name|serno
operator|=
name|mpt
operator|->
name|sequence
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/***************************** Locking Primitives *****************************/
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
name|MPT_OWNED
parameter_list|(
name|mpt
parameter_list|)
value|mpt->mpt_islocked
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
operator|==
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

begin_ifdef
ifdef|#
directive|ifdef
name|LOCKING_WORKED_AS_IT_SHOULD
end_ifdef

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
name|MPT_OWNED
parameter_list|(
name|mpt
parameter_list|)
value|mtx_owned(&(mpt)->mpt_lock)
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

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MPT_LOCK
parameter_list|(
name|mpt
parameter_list|)
define|\
value|device_printf(mpt->dev, "LOCK %s:%d\n", __FILE__, __LINE__); 	\ 	KASSERT(mpt->mpt_locksetup == 0,				\ 	    ("recursive lock acquire at %s:%d", __FILE__, __LINE__));	\ 	mpt->mpt_locksetup = 1
end_define

begin_define
define|#
directive|define
name|MPT_UNLOCK
parameter_list|(
name|mpt
parameter_list|)
define|\
value|device_printf(mpt->dev, "UNLK %s:%d\n", __FILE__, __LINE__); 	\ 	KASSERT(mpt->mpt_locksetup == 1,				\ 	    ("release unowned lock at %s:%d", __FILE__, __LINE__));	\ 	mpt->mpt_locksetup = 0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MPT_LOCK
parameter_list|(
name|mpt
parameter_list|)
define|\
value|KASSERT(mpt->mpt_locksetup == 0,				\ 	    ("recursive lock acquire at %s:%d", __FILE__, __LINE__));	\ 	mpt->mpt_locksetup = 1
end_define

begin_define
define|#
directive|define
name|MPT_UNLOCK
parameter_list|(
name|mpt
parameter_list|)
define|\
value|KASSERT(mpt->mpt_locksetup == 1,				\ 	    ("release unowned lock at %s:%d", __FILE__, __LINE__));	\ 	mpt->mpt_locksetup = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MPT_OWNED
parameter_list|(
name|mpt
parameter_list|)
value|mpt->mpt_locksetup
end_define

begin_define
define|#
directive|define
name|MPTLOCK_2_CAMLOCK
parameter_list|(
name|mpt
parameter_list|)
value|MPT_UNLOCK(mpt)
end_define

begin_define
define|#
directive|define
name|CAMLOCK_2_MPTLOCK
parameter_list|(
name|mpt
parameter_list|)
value|MPT_LOCK(mpt)
end_define

begin_function_decl
specifier|static
name|__inline
name|int
name|mpt_sleep
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|i
parameter_list|,
name|int
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|w
parameter_list|,
name|int
name|t
parameter_list|)
block|{
name|int
name|r
decl_stmt|;
name|MPT_UNLOCK
argument_list|(
name|mpt
argument_list|)
expr_stmt|;
name|r
operator|=
name|tsleep
argument_list|(
name|i
argument_list|,
name|p
argument_list|,
name|w
argument_list|,
name|t
argument_list|)
expr_stmt|;
name|MPT_LOCK
argument_list|(
name|mpt
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
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
value|256
end_define

begin_comment
comment|/*  * Must be less than 16384 in order for target mode to work  */
end_comment

begin_define
define|#
directive|define
name|MPT_MAX_REQUESTS
parameter_list|(
name|mpt
parameter_list|)
value|512
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
comment|/* included in MPT_REQUEST_AREA */
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
value|do {							\ 	if (mpt->verbose> MPT_PRT_DEBUG)		\ 		mpt_dump_reply_frame(mpt, reply_frame);	\ } while(0)
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
parameter_list|,
name|struct
name|req_queue
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** Scatter Gather Managment **************************/
end_comment

begin_comment
comment|/* MPT_RQSL- size of request frame, in bytes */
end_comment

begin_define
define|#
directive|define
name|MPT_RQSL
parameter_list|(
name|mpt
parameter_list|)
value|(mpt->ioc_facts.RequestFrameSize<< 2)
end_define

begin_comment
comment|/* MPT_NSGL- how many SG entries can fit in a request frame size */
end_comment

begin_define
define|#
directive|define
name|MPT_NSGL
parameter_list|(
name|mpt
parameter_list|)
value|(MPT_RQSL(mpt) / sizeof (SGE_IO_UNION))
end_define

begin_comment
comment|/* MPT_NRFM- how many request frames can fit in each request alloc we make */
end_comment

begin_define
define|#
directive|define
name|MPT_NRFM
parameter_list|(
name|mpt
parameter_list|)
value|(MPT_REQUEST_AREA / MPT_RQSL(mpt))
end_define

begin_comment
comment|/*  * MPT_NSGL_FIRST- # of SG elements that can fit after  * an I/O request but still within the request frame.  * Do this safely based upon SGE_IO_UNION.  *  * Note that the first element is *within* the SCSI request.  */
end_comment

begin_define
define|#
directive|define
name|MPT_NSGL_FIRST
parameter_list|(
name|mpt
parameter_list|)
define|\
value|((MPT_RQSL(mpt) - sizeof (MSG_SCSI_IO_REQUEST) + sizeof (SGE_IO_UNION)) / \     sizeof (SGE_IO_UNION))
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
comment|/****************************** Debugging ************************************/
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

begin_function_decl
name|void
name|mpt_dump_data
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpt_dump_request
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|request_t
modifier|*
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
name|MPT_PRT_NEGOTIATION
block|,
name|MPT_PRT_DEBUG
block|,
name|MPT_PRT_DEBUG1
block|,
name|MPT_PRT_DEBUG2
block|,
name|MPT_PRT_DEBUG3
block|,
name|MPT_PRT_TRACE
block|,
name|MPT_PRT_NONE
init|=
literal|100
block|}
enum|;
end_enum

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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|mpt_lprt
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|mpt_lprtc
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

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
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**************************** Target Mode Related ***************************/
end_comment

begin_function_decl
specifier|static
name|__inline
name|int
name|mpt_cdblen
parameter_list|(
name|uint8_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|mpt_cdblen
parameter_list|(
name|uint8_t
name|cdb0
parameter_list|,
name|int
name|maxlen
parameter_list|)
block|{
name|int
name|group
init|=
name|cdb0
operator|>>
literal|5
decl_stmt|;
switch|switch
condition|(
name|group
condition|)
block|{
case|case
literal|0
case|:
return|return
operator|(
literal|6
operator|)
return|;
case|case
literal|1
case|:
return|return
operator|(
literal|10
operator|)
return|;
case|case
literal|4
case|:
case|case
literal|5
case|:
return|return
operator|(
literal|12
operator|)
return|;
default|default:
return|return
operator|(
literal|16
operator|)
return|;
block|}
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_function_decl
specifier|static
name|__inline
name|request_t
modifier|*
name|mpt_tag_2_req
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|request_t
modifier|*
name|mpt_tag_2_req
parameter_list|(
name|struct
name|mpt_softc
modifier|*
name|mpt
parameter_list|,
name|uint32_t
name|tag
parameter_list|)
block|{
name|uint16_t
name|rtg
init|=
operator|(
name|tag
operator|>>
literal|18
operator|)
decl_stmt|;
name|KASSERT
argument_list|(
name|rtg
operator|<
name|mpt
operator|->
name|tgt_cmds_allocated
argument_list|,
operator|(
literal|"bad tag %d\n"
operator|,
name|tag
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|mpt
operator|->
name|tgt_cmd_ptrs
argument_list|,
operator|(
literal|"no cmd backpointer array"
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|mpt
operator|->
name|tgt_cmd_ptrs
index|[
name|rtg
index|]
argument_list|,
operator|(
literal|"no cmd backpointer"
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|mpt
operator|->
name|tgt_cmd_ptrs
index|[
name|rtg
index|]
operator|)
return|;
block|}
end_function

begin_function_decl
specifier|static
name|__inline
name|int
name|mpt_req_on_free_list
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|request_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|mpt_req_on_pending_list
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|request_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|mpt_req_spcl
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|request_t
modifier|*
parameter_list|,
specifier|const
name|char
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
name|mpt_req_not_spcl
parameter_list|(
name|struct
name|mpt_softc
modifier|*
parameter_list|,
name|request_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Is request on freelist?  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|mpt_req_on_free_list
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
block|{
name|request_t
modifier|*
name|lrq
decl_stmt|;
name|TAILQ_FOREACH
argument_list|(
argument|lrq
argument_list|,
argument|&mpt->request_free_list
argument_list|,
argument|links
argument_list|)
block|{
if|if
condition|(
name|lrq
operator|==
name|req
condition|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Is request on pending list?  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|mpt_req_on_pending_list
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
block|{
name|request_t
modifier|*
name|lrq
decl_stmt|;
name|TAILQ_FOREACH
argument_list|(
argument|lrq
argument_list|,
argument|&mpt->request_pending_list
argument_list|,
argument|links
argument_list|)
block|{
if|if
condition|(
name|lrq
operator|==
name|req
condition|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Make sure that req *is* part of one of the special lists  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mpt_req_spcl
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
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|mpt
operator|->
name|els_cmds_allocated
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|req
operator|==
name|mpt
operator|->
name|els_cmd_ptrs
index|[
name|i
index|]
condition|)
block|{
return|return;
block|}
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|mpt
operator|->
name|tgt_cmds_allocated
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|req
operator|==
name|mpt
operator|->
name|tgt_cmd_ptrs
index|[
name|i
index|]
condition|)
block|{
return|return;
block|}
block|}
name|panic
argument_list|(
literal|"%s(%d): req %p:%u function %x not in els or tgt ptrs\n"
argument_list|,
name|s
argument_list|,
name|line
argument_list|,
name|req
argument_list|,
name|req
operator|->
name|serno
argument_list|,
operator|(
operator|(
name|PTR_MSG_REQUEST_HEADER
operator|)
name|req
operator|->
name|req_vbuf
operator|)
operator|->
name|Function
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Make sure that req is *not* part of one of the special lists.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mpt_req_not_spcl
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
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|mpt
operator|->
name|els_cmds_allocated
condition|;
name|i
operator|++
control|)
block|{
name|KASSERT
argument_list|(
name|req
operator|!=
name|mpt
operator|->
name|els_cmd_ptrs
index|[
name|i
index|]
argument_list|,
operator|(
literal|"%s(%d): req %p:%u func %x in els ptrs at ioindex %d\n"
operator|,
name|s
operator|,
name|line
operator|,
name|req
operator|,
name|req
operator|->
name|serno
operator|,
operator|(
operator|(
name|PTR_MSG_REQUEST_HEADER
operator|)
name|req
operator|->
name|req_vbuf
operator|)
operator|->
name|Function
operator|,
name|i
operator|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|mpt
operator|->
name|tgt_cmds_allocated
condition|;
name|i
operator|++
control|)
block|{
name|KASSERT
argument_list|(
name|req
operator|!=
name|mpt
operator|->
name|tgt_cmd_ptrs
index|[
name|i
index|]
argument_list|,
operator|(
literal|"%s(%d): req %p:%u func %x in tgt ptrs at ioindex %d\n"
operator|,
name|s
operator|,
name|line
operator|,
name|req
operator|,
name|req
operator|->
name|serno
operator|,
operator|(
operator|(
name|PTR_MSG_REQUEST_HEADER
operator|)
name|req
operator|->
name|req_vbuf
operator|)
operator|->
name|Function
operator|,
name|i
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Task Management Types, purely for internal consumption  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MPT_ABORT_TASK_SET
init|=
literal|1234
block|,
name|MPT_CLEAR_TASK_SET
block|,
name|MPT_TARGET_RESET
block|,
name|MPT_CLEAR_ACA
block|,
name|MPT_TERMINATE_TASK
block|,
name|MPT_NIL_TMT_VALUE
init|=
literal|5678
block|}
name|mpt_task_mgmt_t
typedef|;
end_typedef

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

begin_function_decl
name|void
name|mpt_dump_sgl
parameter_list|(
name|SGE_IO_UNION
modifier|*
name|se
parameter_list|,
name|int
name|offset
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

