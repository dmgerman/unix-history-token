begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                      Driver Parameter Definitions  ********************************************************************************  ********************************************************************************/
end_comment

begin_comment
comment|/*  * The firmware interface allows for a 16-bit command identifier.  A lookup  * table this size (256k) would be too expensive, so we cap ourselves at a  * reasonable limit.  */
end_comment

begin_define
define|#
directive|define
name|MLY_MAXCOMMANDS
value|256
end_define

begin_comment
comment|/* max outstanding commands per controller, limit 65535 */
end_comment

begin_comment
comment|/*  * The firmware interface allows for a 16-bit s/g list length.  We limit   * ourselves to a reasonable maximum and ensure alignment.  */
end_comment

begin_define
define|#
directive|define
name|MLY_MAXSGENTRIES
value|64
end_define

begin_comment
comment|/* max S/G entries, limit 65535 */
end_comment

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                       Driver Variable Definitions  ********************************************************************************  ********************************************************************************/
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500005
end_if

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Debugging levels:  *  0 - quiet, only emit warnings  *  1 - noisy, emit major function points and things done  *  2 - extremely noisy, emit trace items in loops, etc.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MLY_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do { if (level<= MLY_DEBUG) printf("%s: " fmt "\n", __FUNCTION__ , ##args); } while(0)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
value|do { if (level<= MLY_DEBUG) printf(__FUNCTION__ ": called\n"); } while(0)
end_define

begin_define
define|#
directive|define
name|debug_struct
parameter_list|(
name|s
parameter_list|)
value|printf("  SIZE %s: %d\n", #s, sizeof(struct s))
end_define

begin_define
define|#
directive|define
name|debug_union
parameter_list|(
name|s
parameter_list|)
value|printf("  SIZE %s: %d\n", #s, sizeof(union s))
end_define

begin_define
define|#
directive|define
name|debug_field
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|printf("  OFFSET %s.%s: %d\n", #s, #f, ((int)&(((struct s *)0)->f)))
end_define

begin_function_decl
specifier|extern
name|void
name|mly_printstate0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|mly_softc
modifier|*
name|mly_softc0
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_struct
parameter_list|(
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mly_printf
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|device_printf(sc->mly_dev, fmt , ##args)
end_define

begin_comment
comment|/*  * Per-device structure, used to save persistent state on devices.  *  * Note that this isn't really Bus/Target/Lun since we don't support  * lun != 0 at this time.  */
end_comment

begin_struct
struct|struct
name|mly_btl
block|{
name|int
name|mb_flags
decl_stmt|;
define|#
directive|define
name|MLY_BTL_PHYSICAL
value|(1<<0)
comment|/* physical device */
define|#
directive|define
name|MLY_BTL_LOGICAL
value|(1<<1)
comment|/* logical device */
define|#
directive|define
name|MLY_BTL_PROTECTED
value|(1<<2)
comment|/* device is protected - I/O not allowed */
define|#
directive|define
name|MLY_BTL_RESCAN
value|(1<<3)
comment|/* device needs to be rescanned */
name|char
name|mb_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* peripheral attached to this device */
name|int
name|mb_state
decl_stmt|;
comment|/* see 8.1 */
name|int
name|mb_type
decl_stmt|;
comment|/* see 8.2 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-command control structure.  */
end_comment

begin_struct
struct|struct
name|mly_command
block|{
name|TAILQ_ENTRY
argument_list|(
argument|mly_command
argument_list|)
name|mc_link
expr_stmt|;
comment|/* list linkage */
name|struct
name|mly_softc
modifier|*
name|mc_sc
decl_stmt|;
comment|/* controller that owns us */
name|u_int16_t
name|mc_slot
decl_stmt|;
comment|/* command slot we occupy */
name|int
name|mc_flags
decl_stmt|;
define|#
directive|define
name|MLY_CMD_STATEMASK
value|((1<<8)-1)
define|#
directive|define
name|MLY_CMD_STATE
parameter_list|(
name|mc
parameter_list|)
value|((mc)->mc_flags& MLY_CMD_STATEMASK)
define|#
directive|define
name|MLY_CMD_SETSTATE
parameter_list|(
name|mc
parameter_list|,
name|s
parameter_list|)
value|((mc)->mc_flags = ((mc)->mc_flags&= ~MLY_CMD_STATEMASK) | (s))
define|#
directive|define
name|MLY_CMD_FREE
value|0
comment|/* command is on the free list */
define|#
directive|define
name|MLY_CMD_SETUP
value|1
comment|/* command is being built */
define|#
directive|define
name|MLY_CMD_BUSY
value|2
comment|/* command is being run, or ready to run, or not completed */
define|#
directive|define
name|MLY_CMD_COMPLETE
value|3
comment|/* command has been completed */
define|#
directive|define
name|MLY_CMD_SLOTTED
value|(1<<8)
comment|/* command has a slot number */
define|#
directive|define
name|MLY_CMD_MAPPED
value|(1<<9)
comment|/* command has had its data mapped */
define|#
directive|define
name|MLY_CMD_PRIORITY
value|(1<<10)
comment|/* allow use of "priority" slots */
define|#
directive|define
name|MLY_CMD_DATAIN
value|(1<<11)
comment|/* data moves controller->system */
define|#
directive|define
name|MLY_CMD_DATAOUT
value|(1<<12)
comment|/* data moves system->controller */
name|u_int16_t
name|mc_status
decl_stmt|;
comment|/* command completion status */
name|u_int8_t
name|mc_sense
decl_stmt|;
comment|/* sense data length */
name|int32_t
name|mc_resid
decl_stmt|;
comment|/* I/O residual count */
name|union
name|mly_command_packet
modifier|*
name|mc_packet
decl_stmt|;
comment|/* our controller command */
name|u_int64_t
name|mc_packetphys
decl_stmt|;
comment|/* physical address of the mapped packet */
name|void
modifier|*
name|mc_data
decl_stmt|;
comment|/* data buffer */
name|size_t
name|mc_length
decl_stmt|;
comment|/* data length */
name|bus_dmamap_t
name|mc_datamap
decl_stmt|;
comment|/* DMA map for data */
name|void
function_decl|(
modifier|*
name|mc_complete
function_decl|)
parameter_list|(
name|struct
name|mly_command
modifier|*
name|mc
parameter_list|)
function_decl|;
comment|/* completion handler */
name|void
modifier|*
name|mc_private
decl_stmt|;
comment|/* caller-private data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command slot regulation.  *  * We can't use slot 0 due to the memory mailbox implementation.  */
end_comment

begin_define
define|#
directive|define
name|MLY_SLOT_START
value|1
end_define

begin_define
define|#
directive|define
name|MLY_SLOT_MAX
value|(MLY_SLOT_START + MLY_MAXCOMMANDS)
end_define

begin_comment
comment|/*  * Command/command packet cluster.  *  * Due to the difficulty of using the zone allocator to create a new  * zone from within a module, we use our own clustering to reduce   * memory wastage caused by allocating lots of these small structures.  *  * Note that it is possible to require more than MLY_MAXCOMMANDS   * command structures.  *  * Since we may need to allocate extra clusters at any time, and since this  * process needs to allocate a physically contiguous slab of controller  * addressible memory in which to place the command packets, do not allow more  * command packets in a cluster than will fit in a page.  */
end_comment

begin_define
define|#
directive|define
name|MLY_CMD_CLUSTERCOUNT
value|(PAGE_SIZE / sizeof(union mly_command_packet))
end_define

begin_struct
struct|struct
name|mly_command_cluster
block|{
name|TAILQ_ENTRY
argument_list|(
argument|mly_command_cluster
argument_list|)
name|mcc_link
expr_stmt|;
name|union
name|mly_command_packet
modifier|*
name|mcc_packet
decl_stmt|;
name|bus_dmamap_t
name|mcc_packetmap
decl_stmt|;
name|u_int64_t
name|mcc_packetphys
decl_stmt|;
name|struct
name|mly_command
name|mcc_command
index|[
name|MLY_CMD_CLUSTERCOUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-controller structure.  */
end_comment

begin_struct
struct|struct
name|mly_softc
block|{
comment|/* bus connections */
name|device_t
name|mly_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|mly_regs_resource
decl_stmt|;
comment|/* register interface window */
name|int
name|mly_regs_rid
decl_stmt|;
comment|/* resource ID */
name|bus_space_handle_t
name|mly_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|mly_btag
decl_stmt|;
comment|/* bus space tag */
name|bus_dma_tag_t
name|mly_parent_dmat
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|mly_buffer_dmat
decl_stmt|;
comment|/* data buffer/command DMA tag */
name|struct
name|resource
modifier|*
name|mly_irq
decl_stmt|;
comment|/* interrupt */
name|int
name|mly_irq_rid
decl_stmt|;
name|void
modifier|*
name|mly_intr
decl_stmt|;
comment|/* interrupt handle */
comment|/* scatter/gather lists and their controller-visible mappings */
name|struct
name|mly_sg_entry
modifier|*
name|mly_sg_table
decl_stmt|;
comment|/* s/g lists */
name|u_int32_t
name|mly_sg_busaddr
decl_stmt|;
comment|/* s/g table base address in bus space */
name|bus_dma_tag_t
name|mly_sg_dmat
decl_stmt|;
comment|/* s/g buffer DMA tag */
name|bus_dmamap_t
name|mly_sg_dmamap
decl_stmt|;
comment|/* map for s/g buffers */
comment|/* controller hardware interface */
name|int
name|mly_hwif
decl_stmt|;
define|#
directive|define
name|MLY_HWIF_I960RX
value|0
define|#
directive|define
name|MLY_HWIF_STRONGARM
value|1
name|u_int8_t
name|mly_doorbell_true
decl_stmt|;
comment|/* xor map to make hardware doorbell 'true' bits into 1s */
name|u_int8_t
name|mly_command_mailbox
decl_stmt|;
comment|/* register offsets */
name|u_int8_t
name|mly_status_mailbox
decl_stmt|;
name|u_int8_t
name|mly_idbr
decl_stmt|;
name|u_int8_t
name|mly_odbr
decl_stmt|;
name|u_int8_t
name|mly_error_status
decl_stmt|;
name|u_int8_t
name|mly_interrupt_status
decl_stmt|;
name|u_int8_t
name|mly_interrupt_mask
decl_stmt|;
name|struct
name|mly_mmbox
modifier|*
name|mly_mmbox
decl_stmt|;
comment|/* kernel-space address of memory mailbox */
name|u_int64_t
name|mly_mmbox_busaddr
decl_stmt|;
comment|/* bus-space address of memory mailbox */
name|bus_dma_tag_t
name|mly_mmbox_dmat
decl_stmt|;
comment|/* memory mailbox DMA tag */
name|bus_dmamap_t
name|mly_mmbox_dmamap
decl_stmt|;
comment|/* memory mailbox DMA map */
name|u_int32_t
name|mly_mmbox_command_index
decl_stmt|;
comment|/* next slot to use */
name|u_int32_t
name|mly_mmbox_status_index
decl_stmt|;
comment|/* slot we next expect status in */
comment|/* controller features, limits and status */
name|int
name|mly_state
decl_stmt|;
define|#
directive|define
name|MLY_STATE_SUSPEND
value|(1<<0)
define|#
directive|define
name|MLY_STATE_OPEN
value|(1<<1)
define|#
directive|define
name|MLY_STATE_INTERRUPTS_ON
value|(1<<2)
define|#
directive|define
name|MLY_STATE_MMBOX_ACTIVE
value|(1<<3)
name|int
name|mly_max_commands
decl_stmt|;
comment|/* max parallel commands we allow */
name|struct
name|mly_ioctl_getcontrollerinfo
modifier|*
name|mly_controllerinfo
decl_stmt|;
name|struct
name|mly_param_controller
modifier|*
name|mly_controllerparam
decl_stmt|;
name|struct
name|mly_btl
name|mly_btl
index|[
name|MLY_MAX_CHANNELS
index|]
index|[
name|MLY_MAX_TARGETS
index|]
decl_stmt|;
comment|/* command management */
name|struct
name|mly_command
modifier|*
name|mly_busycmds
index|[
name|MLY_SLOT_MAX
index|]
decl_stmt|;
comment|/* busy commands */
name|int
name|mly_busy_count
decl_stmt|;
name|int
name|mly_last_slot
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|mly_command
argument_list|)
name|mly_freecmds
expr_stmt|;
comment|/* commands available for reuse */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|mly_command
argument_list|)
name|mly_ready
expr_stmt|;
comment|/* commands ready to be submitted */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|mly_command
argument_list|)
name|mly_completed
expr_stmt|;
comment|/* commands which have been returned by the controller */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|mly_command_cluster
argument_list|)
name|mly_clusters
expr_stmt|;
comment|/* command memory blocks */
name|bus_dma_tag_t
name|mly_packet_dmat
decl_stmt|;
comment|/* command packet DMA tag */
comment|/* health monitoring */
name|u_int32_t
name|mly_event_change
decl_stmt|;
comment|/* event status change indicator */
name|u_int32_t
name|mly_event_counter
decl_stmt|;
comment|/* next event for which we anticpiate status */
name|u_int32_t
name|mly_event_waiting
decl_stmt|;
comment|/* next event the controller will post status for */
name|struct
name|callout_handle
name|mly_periodic
decl_stmt|;
comment|/* periodic event handling */
comment|/* CAM connection */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|mly_cam_ccbq
expr_stmt|;
comment|/* outstanding I/O from CAM */
name|struct
name|cam_sim
modifier|*
name|mly_cam_sim
index|[
name|MLY_MAX_CHANNELS
index|]
decl_stmt|;
name|int
name|mly_cam_lowbus
decl_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500005
comment|/* command-completion task */
name|struct
name|task
name|mly_task_complete
decl_stmt|;
comment|/* deferred-completion task */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register access helpers.  */
end_comment

begin_define
define|#
directive|define
name|MLY_SET_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_1(sc->mly_btag, sc->mly_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|MLY_GET_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_space_read_1 (sc->mly_btag, sc->mly_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|MLY_GET_REG2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_space_read_2 (sc->mly_btag, sc->mly_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|MLY_GET_REG4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_space_read_4 (sc->mly_btag, sc->mly_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|MLY_SET_MBOX
parameter_list|(
name|sc
parameter_list|,
name|mbox
parameter_list|,
name|ptr
parameter_list|)
define|\
value|do {												\ 	    bus_space_write_4(sc->mly_btag, sc->mly_bhandle, mbox,      *((u_int32_t *)ptr));		\ 	    bus_space_write_4(sc->mly_btag, sc->mly_bhandle, mbox +  4, *((u_int32_t *)ptr + 1));	\ 	    bus_space_write_4(sc->mly_btag, sc->mly_bhandle, mbox +  8, *((u_int32_t *)ptr + 2));	\ 	    bus_space_write_4(sc->mly_btag, sc->mly_bhandle, mbox + 12, *((u_int32_t *)ptr + 3));	\ 	} while(0);
end_define

begin_define
define|#
directive|define
name|MLY_GET_MBOX
parameter_list|(
name|sc
parameter_list|,
name|mbox
parameter_list|,
name|ptr
parameter_list|)
define|\
value|do {												\ 	    *((u_int32_t *)ptr) = bus_space_read_4(sc->mly_btag, sc->mly_bhandle, mbox);		\ 	    *((u_int32_t *)ptr + 1) = bus_space_read_4(sc->mly_btag, sc->mly_bhandle, mbox + 4);	\ 	    *((u_int32_t *)ptr + 2) = bus_space_read_4(sc->mly_btag, sc->mly_bhandle, mbox + 8);	\ 	    *((u_int32_t *)ptr + 3) = bus_space_read_4(sc->mly_btag, sc->mly_bhandle, mbox + 12);	\ 	} while(0);
end_define

begin_define
define|#
directive|define
name|MLY_IDBR_TRUE
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|)
define|\
value|((((MLY_GET_REG((sc), (sc)->mly_idbr)) ^ (sc)->mly_doorbell_true)& (mask)) == (mask))
end_define

begin_define
define|#
directive|define
name|MLY_ODBR_TRUE
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|)
define|\
value|((MLY_GET_REG((sc), (sc)->mly_odbr)& (mask)) == (mask))
end_define

begin_define
define|#
directive|define
name|MLY_ERROR_VALID
parameter_list|(
name|sc
parameter_list|)
define|\
value|((((MLY_GET_REG((sc), (sc)->mly_error_status)) ^ (sc)->mly_doorbell_true)& (MLY_MSG_EMPTY)) == 0)
end_define

begin_define
define|#
directive|define
name|MLY_MASK_INTERRUPTS
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {										\ 	    MLY_SET_REG((sc), (sc)->mly_interrupt_mask, MLY_INTERRUPT_MASK_DISABLE);	\ 	    sc->mly_state&= ~MLY_STATE_INTERRUPTS_ON;					\ 	} while(0);
end_define

begin_define
define|#
directive|define
name|MLY_UNMASK_INTERRUPTS
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {										\ 	    MLY_SET_REG((sc), (sc)->mly_interrupt_mask, MLY_INTERRUPT_MASK_ENABLE);	\ 	    sc->mly_state |= MLY_STATE_INTERRUPTS_ON;					\ 	} while(0);
end_define

begin_comment
comment|/*  * Logical device number -> bus/target translation  */
end_comment

begin_define
define|#
directive|define
name|MLY_LOGDEV_BUS
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|(((x) / MLY_MAX_TARGETS) + (sc)->mly_controllerinfo->physical_channels_present)
end_define

begin_define
define|#
directive|define
name|MLY_LOGDEV_TARGET
parameter_list|(
name|x
parameter_list|)
value|((x) % MLY_MAX_TARGETS)
end_define

begin_comment
comment|/*  * Public functions/variables  */
end_comment

begin_comment
comment|/* mly.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|mly_attach
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mly_detach
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mly_free
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mly_startio
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mly_done
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mly_alloc_command
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mly_command
modifier|*
modifier|*
name|mcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mly_release_command
parameter_list|(
name|struct
name|mly_command
modifier|*
name|mc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mly_cam.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|mly_cam_attach
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mly_cam_detach
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mly_cam_command
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mly_command
modifier|*
modifier|*
name|mcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mly_name_device
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|,
name|int
name|bus
parameter_list|,
name|int
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/********************************************************************************  * Queue primitives  *  * These are broken out individually to make statistics gathering easier.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mly_enqueue_ready
parameter_list|(
name|struct
name|mly_command
modifier|*
name|mc
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
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|mc
operator|->
name|mc_sc
operator|->
name|mly_ready
argument_list|,
name|mc
argument_list|,
name|mc_link
argument_list|)
expr_stmt|;
name|MLY_CMD_SETSTATE
argument_list|(
name|mc
argument_list|,
name|MLY_CMD_BUSY
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mly_requeue_ready
parameter_list|(
name|struct
name|mly_command
modifier|*
name|mc
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
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|mc
operator|->
name|mc_sc
operator|->
name|mly_ready
argument_list|,
name|mc
argument_list|,
name|mc_link
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mly_command
operator|*
name|mly_dequeue_ready
argument_list|(
argument|struct mly_softc *sc
argument_list|)
block|{     struct
name|mly_command
operator|*
name|mc
block|;
name|int
name|s
block|;
name|s
operator|=
name|splcam
argument_list|()
block|;
if|if
condition|(
operator|(
name|mc
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|sc
operator|->
name|mly_ready
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|TAILQ_REMOVE
argument_list|(
operator|&
name|sc
operator|->
name|mly_ready
argument_list|,
name|mc
argument_list|,
name|mc_link
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|mc
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|mly_enqueue_completed
parameter_list|(
name|struct
name|mly_command
modifier|*
name|mc
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
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|mc
operator|->
name|mc_sc
operator|->
name|mly_completed
argument_list|,
name|mc
argument_list|,
name|mc_link
argument_list|)
expr_stmt|;
comment|/* don't set MLY_CMD_COMPLETE here to avoid wakeup race */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mly_command
operator|*
name|mly_dequeue_completed
argument_list|(
argument|struct mly_softc *sc
argument_list|)
block|{     struct
name|mly_command
operator|*
name|mc
block|;
name|int
name|s
block|;
name|s
operator|=
name|splcam
argument_list|()
block|;
if|if
condition|(
operator|(
name|mc
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|sc
operator|->
name|mly_completed
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|TAILQ_REMOVE
argument_list|(
operator|&
name|sc
operator|->
name|mly_completed
argument_list|,
name|mc
argument_list|,
name|mc_link
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|mc
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|mly_enqueue_free
parameter_list|(
name|struct
name|mly_command
modifier|*
name|mc
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
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|mc
operator|->
name|mc_sc
operator|->
name|mly_freecmds
argument_list|,
name|mc
argument_list|,
name|mc_link
argument_list|)
expr_stmt|;
name|MLY_CMD_SETSTATE
argument_list|(
name|mc
argument_list|,
name|MLY_CMD_FREE
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mly_command
operator|*
name|mly_dequeue_free
argument_list|(
argument|struct mly_softc *sc
argument_list|)
block|{     struct
name|mly_command
operator|*
name|mc
block|;
name|int
name|s
block|;
name|s
operator|=
name|splcam
argument_list|()
block|;
if|if
condition|(
operator|(
name|mc
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|sc
operator|->
name|mly_freecmds
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|TAILQ_REMOVE
argument_list|(
operator|&
name|sc
operator|->
name|mly_freecmds
argument_list|,
name|mc
argument_list|,
name|mc_link
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|mc
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|mly_enqueue_cluster
parameter_list|(
name|struct
name|mly_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mly_command_cluster
modifier|*
name|mcc
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
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|sc
operator|->
name|mly_clusters
argument_list|,
name|mcc
argument_list|,
name|mcc_link
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mly_command_cluster
operator|*
name|mly_dequeue_cluster
argument_list|(
argument|struct mly_softc *sc
argument_list|)
block|{     struct
name|mly_command_cluster
operator|*
name|mcc
block|;
name|int
name|s
block|;
name|s
operator|=
name|splcam
argument_list|()
block|;
if|if
condition|(
operator|(
name|mcc
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|sc
operator|->
name|mly_clusters
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|TAILQ_REMOVE
argument_list|(
operator|&
name|sc
operator|->
name|mly_clusters
argument_list|,
name|mcc
argument_list|,
name|mcc_link
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|mcc
operator|)
return|;
end_return

unit|}
end_unit

