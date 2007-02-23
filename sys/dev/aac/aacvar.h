begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2001 Scott Long  * Copyright (c) 2000 BSDi  * Copyright (c) 2001 Adaptec, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<geom/geom_disk.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|AAC_DRIVER_BUILD
end_ifndef

begin_define
define|#
directive|define
name|AAC_DRIVER_BUILD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Driver Parameter Definitions  */
end_comment

begin_comment
comment|/*  * The firmware interface allows for a 16-bit s/g list length.  We limit   * ourselves to a reasonable maximum and ensure alignment.  */
end_comment

begin_define
define|#
directive|define
name|AAC_MAXSGENTRIES
value|64
end_define

begin_comment
comment|/* max S/G entries, limit 65535 */
end_comment

begin_comment
comment|/*  * We allocate a small set of FIBs for the adapter to use to send us messages.  */
end_comment

begin_define
define|#
directive|define
name|AAC_ADAPTER_FIBS
value|8
end_define

begin_comment
comment|/*  * FIBs are allocated in page-size chunks and can grow up to the 512  * limit imposed by the hardware.  */
end_comment

begin_define
define|#
directive|define
name|AAC_PREALLOCATE_FIBS
value|128
end_define

begin_define
define|#
directive|define
name|AAC_NUM_MGT_FIB
value|8
end_define

begin_comment
comment|/*  * The controller reports status events in AIFs.  We hang on to a number of  * these in order to pass them out to user-space management tools.  */
end_comment

begin_define
define|#
directive|define
name|AAC_AIFQ_LENGTH
value|64
end_define

begin_comment
comment|/*  * Firmware messages are passed in the printf buffer.  */
end_comment

begin_define
define|#
directive|define
name|AAC_PRINTF_BUFSIZE
value|256
end_define

begin_comment
comment|/*  * We wait this many seconds for the adapter to come ready if it is still   * booting  */
end_comment

begin_define
define|#
directive|define
name|AAC_BOOT_TIMEOUT
value|(3 * 60)
end_define

begin_comment
comment|/*  * Timeout for immediate commands.  */
end_comment

begin_define
define|#
directive|define
name|AAC_IMMEDIATE_TIMEOUT
value|30
end_define

begin_comment
comment|/* seconds */
end_comment

begin_comment
comment|/*  * Timeout for normal commands  */
end_comment

begin_define
define|#
directive|define
name|AAC_CMD_TIMEOUT
value|30
end_define

begin_comment
comment|/* seconds */
end_comment

begin_comment
comment|/*  * Rate at which we periodically check for timed out commands and kick the  * controller.  */
end_comment

begin_define
define|#
directive|define
name|AAC_PERIODIC_INTERVAL
value|20
end_define

begin_comment
comment|/* seconds */
end_comment

begin_comment
comment|/*  * Per-container data structure  */
end_comment

begin_struct
struct|struct
name|aac_container
block|{
name|struct
name|aac_mntobj
name|co_mntobj
decl_stmt|;
name|device_t
name|co_disk
decl_stmt|;
name|int
name|co_found
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|aac_container
argument_list|)
name|co_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-SIM data structure  */
end_comment

begin_struct
struct|struct
name|aac_sim
block|{
name|device_t
name|sim_dev
decl_stmt|;
name|int
name|TargetsPerBus
decl_stmt|;
name|int
name|BusNumber
decl_stmt|;
name|int
name|InitiatorBusId
decl_stmt|;
name|struct
name|aac_softc
modifier|*
name|aac_sc
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|aac_sim
argument_list|)
name|sim_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-disk structure  */
end_comment

begin_struct
struct|struct
name|aac_disk
block|{
name|device_t
name|ad_dev
decl_stmt|;
name|struct
name|aac_softc
modifier|*
name|ad_controller
decl_stmt|;
name|struct
name|aac_container
modifier|*
name|ad_container
decl_stmt|;
name|struct
name|disk
modifier|*
name|ad_disk
decl_stmt|;
name|int
name|ad_flags
decl_stmt|;
define|#
directive|define
name|AAC_DISK_OPEN
value|(1<<0)
name|int
name|ad_cylinders
decl_stmt|;
name|int
name|ad_heads
decl_stmt|;
name|int
name|ad_sectors
decl_stmt|;
name|u_int32_t
name|ad_size
decl_stmt|;
name|int
name|unit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-command control structure.  */
end_comment

begin_struct
struct|struct
name|aac_command
block|{
name|TAILQ_ENTRY
argument_list|(
argument|aac_command
argument_list|)
name|cm_link
expr_stmt|;
comment|/* list linkage */
name|struct
name|aac_softc
modifier|*
name|cm_sc
decl_stmt|;
comment|/* controller that owns us */
name|struct
name|aac_fib
modifier|*
name|cm_fib
decl_stmt|;
comment|/* FIB associated with this 						 * command */
name|u_int64_t
name|cm_fibphys
decl_stmt|;
comment|/* bus address of the FIB */
name|struct
name|bio
modifier|*
name|cm_data
decl_stmt|;
comment|/* pointer to data in kernel 						 * space */
name|u_int32_t
name|cm_datalen
decl_stmt|;
comment|/* data length */
name|bus_dmamap_t
name|cm_datamap
decl_stmt|;
comment|/* DMA map for bio data */
name|struct
name|aac_sg_table
modifier|*
name|cm_sgtable
decl_stmt|;
comment|/* pointer to s/g table in 						 * command */
name|int
name|cm_flags
decl_stmt|;
define|#
directive|define
name|AAC_CMD_MAPPED
value|(1<<0)
comment|/* command has had its data 						 * mapped */
define|#
directive|define
name|AAC_CMD_DATAIN
value|(1<<1)
comment|/* command involves data moving 						 * from controller to host */
define|#
directive|define
name|AAC_CMD_DATAOUT
value|(1<<2)
comment|/* command involves data moving 						 * from host to controller */
define|#
directive|define
name|AAC_CMD_COMPLETED
value|(1<<3)
comment|/* command has been completed */
define|#
directive|define
name|AAC_CMD_TIMEDOUT
value|(1<<4)
comment|/* command taken too long */
define|#
directive|define
name|AAC_ON_AACQ_FREE
value|(1<<5)
define|#
directive|define
name|AAC_ON_AACQ_READY
value|(1<<6)
define|#
directive|define
name|AAC_ON_AACQ_BUSY
value|(1<<7)
define|#
directive|define
name|AAC_ON_AACQ_AIF
value|(1<<8)
define|#
directive|define
name|AAC_ON_AACQ_NORM
value|(1<<10)
define|#
directive|define
name|AAC_ON_AACQ_MASK
value|((1<<5)|(1<<6)|(1<<7)|(1<<8)|(1<<10))
define|#
directive|define
name|AAC_QUEUE_FRZN
value|(1<<9)
comment|/* Freeze the processing of 						 * commands on the queue. */
name|void
function_decl|(
modifier|*
name|cm_complete
function_decl|)
parameter_list|(
name|struct
name|aac_command
modifier|*
name|cm
parameter_list|)
function_decl|;
name|void
modifier|*
name|cm_private
decl_stmt|;
name|time_t
name|cm_timestamp
decl_stmt|;
comment|/* command creation time */
name|int
name|cm_queue
decl_stmt|;
name|int
name|cm_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aac_fibmap
block|{
name|TAILQ_ENTRY
argument_list|(
argument|aac_fibmap
argument_list|)
name|fm_link
expr_stmt|;
comment|/* list linkage */
name|struct
name|aac_fib
modifier|*
name|aac_fibs
decl_stmt|;
name|bus_dmamap_t
name|aac_fibmap
decl_stmt|;
name|struct
name|aac_command
modifier|*
name|aac_commands
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * We gather a number of adapter-visible items into a single structure.  *  * The ordering of this strucure may be important; we copy the Linux driver:  *  * Adapter FIBs  * Init struct  * Queue headers (Comm Area)  * Printf buffer  *  * In addition, we add:  * Sync Fib  */
end_comment

begin_struct
struct|struct
name|aac_common
block|{
comment|/* fibs for the controller to send us messages */
name|struct
name|aac_fib
name|ac_fibs
index|[
name|AAC_ADAPTER_FIBS
index|]
decl_stmt|;
comment|/* the init structure */
name|struct
name|aac_adapter_init
name|ac_init
decl_stmt|;
comment|/* arena within which the queue structures are kept */
name|u_int8_t
name|ac_qbuf
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|aac_queue_table
argument_list|)
operator|+
name|AAC_QUEUE_ALIGN
index|]
decl_stmt|;
comment|/* buffer for text messages from the controller */
name|char
name|ac_printf
index|[
name|AAC_PRINTF_BUFSIZE
index|]
decl_stmt|;
comment|/* fib for synchronous commands */
name|struct
name|aac_fib
name|ac_sync_fib
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface operations  */
end_comment

begin_struct
struct|struct
name|aac_interface
block|{
name|int
function_decl|(
modifier|*
name|aif_get_fwstatus
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|aif_qnotify
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|int
name|qbit
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|aif_get_istatus
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|aif_clr_istatus
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|int
name|mask
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|aif_set_mailbox
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|u_int32_t
name|command
parameter_list|,
name|u_int32_t
name|arg0
parameter_list|,
name|u_int32_t
name|arg1
parameter_list|,
name|u_int32_t
name|arg2
parameter_list|,
name|u_int32_t
name|arg3
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|aif_get_mailbox
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|int
name|mb
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|aif_set_interrupts
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|aif_send_command
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|aac_command
modifier|*
name|cm
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|aif_get_outb_queue
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|aif_set_outb_queue
function_decl|)
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|aac_interface
name|aac_rx_interface
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|aac_interface
name|aac_sa_interface
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|aac_interface
name|aac_fa_interface
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|aac_interface
name|aac_rkt_interface
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AAC_GET_FWSTATUS
parameter_list|(
name|sc
parameter_list|)
value|((sc)->aac_if.aif_get_fwstatus((sc)))
end_define

begin_define
define|#
directive|define
name|AAC_QNOTIFY
parameter_list|(
name|sc
parameter_list|,
name|qbit
parameter_list|)
value|((sc)->aac_if.aif_qnotify((sc), (qbit)))
end_define

begin_define
define|#
directive|define
name|AAC_GET_ISTATUS
parameter_list|(
name|sc
parameter_list|)
value|((sc)->aac_if.aif_get_istatus((sc)))
end_define

begin_define
define|#
directive|define
name|AAC_CLEAR_ISTATUS
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|)
value|((sc)->aac_if.aif_clr_istatus((sc), \ 					(mask)))
end_define

begin_define
define|#
directive|define
name|AAC_SET_MAILBOX
parameter_list|(
name|sc
parameter_list|,
name|command
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|((sc)->aac_if.aif_set_mailbox((sc), (command), (arg0), (arg1), (arg2), \ 	(arg3)))
end_define

begin_define
define|#
directive|define
name|AAC_GET_MAILBOX
parameter_list|(
name|sc
parameter_list|,
name|mb
parameter_list|)
value|((sc)->aac_if.aif_get_mailbox((sc), \ 					(mb)))
end_define

begin_define
define|#
directive|define
name|AAC_MASK_INTERRUPTS
parameter_list|(
name|sc
parameter_list|)
value|((sc)->aac_if.aif_set_interrupts((sc), \ 					0))
end_define

begin_define
define|#
directive|define
name|AAC_UNMASK_INTERRUPTS
parameter_list|(
name|sc
parameter_list|)
value|((sc)->aac_if.aif_set_interrupts((sc), \ 					1))
end_define

begin_define
define|#
directive|define
name|AAC_SEND_COMMAND
parameter_list|(
name|sc
parameter_list|,
name|cm
parameter_list|)
value|((sc)->aac_if.aif_send_command((sc), (cm)))
end_define

begin_define
define|#
directive|define
name|AAC_GET_OUTB_QUEUE
parameter_list|(
name|sc
parameter_list|)
value|((sc)->aac_if.aif_get_outb_queue((sc)))
end_define

begin_define
define|#
directive|define
name|AAC_SET_OUTB_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|idx
parameter_list|)
value|((sc)->aac_if.aif_set_outb_queue((sc), (idx)))
end_define

begin_define
define|#
directive|define
name|AAC_SETREG4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->aac_btag, \ 					sc->aac_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|AAC_GETREG4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_space_read_4 (sc->aac_btag, \ 					sc->aac_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|AAC_SETREG2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_2(sc->aac_btag, \ 					sc->aac_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|AAC_GETREG2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_space_read_2 (sc->aac_btag, \ 					sc->aac_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|AAC_SETREG1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_1(sc->aac_btag, \ 					sc->aac_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|AAC_GETREG1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_space_read_1 (sc->aac_btag, \ 					sc->aac_bhandle, reg)
end_define

begin_comment
comment|/*  * Per-controller structure.  */
end_comment

begin_struct
struct|struct
name|aac_softc
block|{
comment|/* bus connections */
name|device_t
name|aac_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|aac_regs_resource
decl_stmt|;
comment|/* register interface 							 * window */
name|int
name|aac_regs_rid
decl_stmt|;
comment|/* resource ID */
name|bus_space_handle_t
name|aac_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|aac_btag
decl_stmt|;
comment|/* bus space tag */
name|bus_dma_tag_t
name|aac_parent_dmat
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|aac_buffer_dmat
decl_stmt|;
comment|/* data buffer/command 							 * DMA tag */
name|struct
name|resource
modifier|*
name|aac_irq
decl_stmt|;
comment|/* interrupt */
name|int
name|aac_irq_rid
decl_stmt|;
name|void
modifier|*
name|aac_intr
decl_stmt|;
comment|/* interrupt handle */
name|eventhandler_tag
name|eh
decl_stmt|;
comment|/* controller features, limits and status */
name|int
name|aac_state
decl_stmt|;
define|#
directive|define
name|AAC_STATE_SUSPEND
value|(1<<0)
define|#
directive|define
name|AAC_STATE_OPEN
value|(1<<1)
define|#
directive|define
name|AAC_STATE_INTERRUPTS_ON
value|(1<<2)
define|#
directive|define
name|AAC_STATE_AIF_SLEEPER
value|(1<<3)
name|struct
name|FsaRevision
name|aac_revision
decl_stmt|;
comment|/* controller hardware interface */
name|int
name|aac_hwif
decl_stmt|;
define|#
directive|define
name|AAC_HWIF_I960RX
value|0
define|#
directive|define
name|AAC_HWIF_STRONGARM
value|1
define|#
directive|define
name|AAC_HWIF_FALCON
value|2
define|#
directive|define
name|AAC_HWIF_RKT
value|3
define|#
directive|define
name|AAC_HWIF_UNKNOWN
value|-1
name|bus_dma_tag_t
name|aac_common_dmat
decl_stmt|;
comment|/* common structure 							 * DMA tag */
name|bus_dmamap_t
name|aac_common_dmamap
decl_stmt|;
comment|/* common structure 							 * DMA map */
name|struct
name|aac_common
modifier|*
name|aac_common
decl_stmt|;
name|u_int32_t
name|aac_common_busaddr
decl_stmt|;
name|struct
name|aac_interface
name|aac_if
decl_stmt|;
comment|/* command/fib resources */
name|bus_dma_tag_t
name|aac_fib_dmat
decl_stmt|;
comment|/* DMA tag for allocing FIBs */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_fibmap
argument_list|)
name|aac_fibmap_tqh
expr_stmt|;
name|u_int
name|total_fibs
decl_stmt|;
name|struct
name|aac_command
modifier|*
name|aac_commands
decl_stmt|;
comment|/* command management */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_command
argument_list|)
name|aac_free
expr_stmt|;
comment|/* command structures  						 * available for reuse */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_command
argument_list|)
name|aac_ready
expr_stmt|;
comment|/* commands on hold for 						 * controller resources */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_command
argument_list|)
name|aac_busy
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_command
argument_list|)
name|aac_aif
expr_stmt|;
if|#
directive|if
literal|0
block|TAILQ_HEAD(,aac_command) aac_norm;
endif|#
directive|endif
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_event
argument_list|)
name|aac_ev_cmfree
expr_stmt|;
name|struct
name|bio_queue_head
name|aac_bioq
decl_stmt|;
name|struct
name|aac_queue_table
modifier|*
name|aac_queues
decl_stmt|;
name|struct
name|aac_queue_entry
modifier|*
name|aac_qentries
index|[
name|AAC_QUEUE_COUNT
index|]
decl_stmt|;
name|struct
name|aac_qstat
name|aac_qstat
index|[
name|AACQ_COUNT
index|]
decl_stmt|;
comment|/* queue statistics */
comment|/* connected containters */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_container
argument_list|)
name|aac_container_tqh
expr_stmt|;
name|struct
name|mtx
name|aac_container_lock
decl_stmt|;
comment|/* 	 * The general I/O lock.  This protects the sync fib, the lists, the 	 * queues, and the registers. 	 */
name|struct
name|mtx
name|aac_io_lock
decl_stmt|;
comment|/* delayed activity infrastructure */
name|struct
name|task
name|aac_task_complete
decl_stmt|;
comment|/* deferred-completion 							 * task */
name|struct
name|intr_config_hook
name|aac_ich
decl_stmt|;
comment|/* management interface */
name|struct
name|cdev
modifier|*
name|aac_dev_t
decl_stmt|;
name|struct
name|mtx
name|aac_aifq_lock
decl_stmt|;
name|struct
name|aac_aif_command
name|aac_aifq
index|[
name|AAC_AIFQ_LENGTH
index|]
decl_stmt|;
name|int
name|aac_aifq_head
decl_stmt|;
name|int
name|aac_aifq_tail
decl_stmt|;
name|struct
name|selinfo
name|rcv_select
decl_stmt|;
name|struct
name|proc
modifier|*
name|aifthread
decl_stmt|;
name|int
name|aifflags
decl_stmt|;
define|#
directive|define
name|AAC_AIFFLAGS_RUNNING
value|(1<< 0)
define|#
directive|define
name|AAC_AIFFLAGS_AIF
value|(1<< 1)
define|#
directive|define
name|AAC_AIFFLAGS_EXIT
value|(1<< 2)
define|#
directive|define
name|AAC_AIFFLAGS_EXITED
value|(1<< 3)
define|#
directive|define
name|AAC_AIFFLAGS_PRINTF
value|(1<< 4)
define|#
directive|define
name|AAC_AIFFLAGS_ALLOCFIBS
value|(1<< 5)
define|#
directive|define
name|AAC_AIFFLAGS_PENDING
value|(AAC_AIFFLAGS_AIF | AAC_AIFFLAGS_PRINTF | \ 				 AAC_AIFFLAGS_ALLOCFIBS)
name|u_int32_t
name|flags
decl_stmt|;
define|#
directive|define
name|AAC_FLAGS_PERC2QC
value|(1<< 0)
define|#
directive|define
name|AAC_FLAGS_ENABLE_CAM
value|(1<< 1)
comment|/* No SCSI passthrough */
define|#
directive|define
name|AAC_FLAGS_CAM_NORESET
value|(1<< 2)
comment|/* Fake SCSI resets */
define|#
directive|define
name|AAC_FLAGS_CAM_PASSONLY
value|(1<< 3)
comment|/* Only create pass devices */
define|#
directive|define
name|AAC_FLAGS_SG_64BIT
value|(1<< 4)
comment|/* Use 64-bit S/G addresses */
define|#
directive|define
name|AAC_FLAGS_4GB_WINDOW
value|(1<< 5)
comment|/* Device can access host mem 						 * 2GB-4GB range */
define|#
directive|define
name|AAC_FLAGS_NO4GB
value|(1<< 6)
comment|/* Can't access host mem>2GB */
define|#
directive|define
name|AAC_FLAGS_256FIBS
value|(1<< 7)
comment|/* Can only do 256 commands */
define|#
directive|define
name|AAC_FLAGS_BROKEN_MEMMAP
value|(1<< 8)
comment|/* Broken HostPhysMemPages */
define|#
directive|define
name|AAC_FLAGS_SLAVE
value|(1<< 9)
define|#
directive|define
name|AAC_FLAGS_MASTER
value|(1<< 10)
define|#
directive|define
name|AAC_FLAGS_NEW_COMM
value|(1<< 11)
comment|/* New comm. interface supported */
define|#
directive|define
name|AAC_FLAGS_RAW_IO
value|(1<< 12)
comment|/* Raw I/O interface */
define|#
directive|define
name|AAC_FLAGS_ARRAY_64BIT
value|(1<< 13)
comment|/* 64-bit array size */
name|u_int32_t
name|supported_options
decl_stmt|;
name|u_int32_t
name|scsi_method_id
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_sim
argument_list|)
name|aac_sim_tqh
expr_stmt|;
name|u_int32_t
name|aac_max_fibs
decl_stmt|;
comment|/* max. FIB count */
name|u_int32_t
name|aac_max_fibs_alloc
decl_stmt|;
comment|/* max. alloc. per alloc_commands() */
name|u_int32_t
name|aac_max_fib_size
decl_stmt|;
comment|/* max. FIB size */
name|u_int32_t
name|aac_sg_tablesize
decl_stmt|;
comment|/* max. sg count from host */
name|u_int32_t
name|aac_max_sectors
decl_stmt|;
comment|/* max. I/O size from host (blocks) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Event callback mechanism for the driver  */
end_comment

begin_define
define|#
directive|define
name|AAC_EVENT_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|AAC_EVENT_CMFREE
value|0x01
end_define

begin_define
define|#
directive|define
name|AAC_EVENT_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|AAC_EVENT_REPEAT
value|0x100
end_define

begin_typedef
typedef|typedef
name|void
name|aac_event_cb_t
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|aac_event
modifier|*
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|aac_event
block|{
name|TAILQ_ENTRY
argument_list|(
argument|aac_event
argument_list|)
name|ev_links
expr_stmt|;
name|int
name|ev_type
decl_stmt|;
name|aac_event_cb_t
modifier|*
name|ev_callback
decl_stmt|;
name|void
modifier|*
name|ev_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Public functions  */
end_comment

begin_function_decl
specifier|extern
name|void
name|aac_free
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aac_attach
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aac_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aac_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aac_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aac_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_new_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aac_fast_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_submit_bio
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_biodone
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_startio
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aac_alloc_command
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|aac_command
modifier|*
modifier|*
name|cmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_release_command
parameter_list|(
name|struct
name|aac_command
modifier|*
name|cm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|aac_sync_fib
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|u_int32_t
name|command
parameter_list|,
name|u_int32_t
name|xferstate
parameter_list|,
name|struct
name|aac_fib
modifier|*
name|fib
parameter_list|,
name|u_int16_t
name|datasize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_add_event
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|aac_event
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Debugging levels:  *  0 - quiet, only emit warnings  *  1 - noisy, emit major function points and things done  *  2 - extremely noisy, emit trace items in loops, etc.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AAC_DEBUG
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
define|\
value|do {								\ 	if (level<=AAC_DEBUG) printf("%s: " fmt "\n", __func__ , ##args); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
define|\
value|do {								\ 	if (level<= AAC_DEBUG) printf("%s: called\n", __func__);	\ 	} while (0)
end_define

begin_function_decl
specifier|extern
name|void
name|aac_print_queues
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_panic
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_print_fib
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|aac_fib
modifier|*
name|fib
parameter_list|,
specifier|const
name|char
modifier|*
name|caller
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|aac_print_aif
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|aac_aif_command
modifier|*
name|aif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AAC_PRINT_FIB
parameter_list|(
name|sc
parameter_list|,
name|fib
parameter_list|)
value|aac_print_fib(sc, fib, __func__)
end_define

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
name|aac_print_queues
parameter_list|(
name|sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|aac_panic
parameter_list|(
name|sc
parameter_list|,
name|reason
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AAC_PRINT_FIB
parameter_list|(
name|sc
parameter_list|,
name|fib
parameter_list|)
end_define

begin_define
define|#
directive|define
name|aac_print_aif
parameter_list|(
name|sc
parameter_list|,
name|aac_aif_command
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|aac_code_lookup
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|u_int32_t
name|code
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Queue primitives for driver queues.  */
end_comment

begin_define
define|#
directive|define
name|AACQ_ADD
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {							\ 		struct aac_qstat *qs;				\ 								\ 		qs =&(sc)->aac_qstat[qname];			\ 								\ 		qs->q_length++;					\ 		if (qs->q_length> qs->q_max)			\ 			qs->q_max = qs->q_length;		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|AACQ_REMOVE
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
value|(sc)->aac_qstat[qname].q_length--
end_define

begin_define
define|#
directive|define
name|AACQ_INIT
parameter_list|(
name|sc
parameter_list|,
name|qname
parameter_list|)
define|\
value|do {						\ 		sc->aac_qstat[qname].q_length = 0;	\ 		sc->aac_qstat[qname].q_max = 0;		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|AACQ_COMMAND_QUEUE
parameter_list|(
name|name
parameter_list|,
name|index
parameter_list|)
define|\
value|static __inline void							\ aac_initq_ ## name (struct aac_softc *sc)				\ {									\ 	TAILQ_INIT(&sc->aac_ ## name);					\ 	AACQ_INIT(sc, index);						\ }									\ static __inline void							\ aac_enqueue_ ## name (struct aac_command *cm)				\ {									\ 	if ((cm->cm_flags& AAC_ON_AACQ_MASK) != 0) {			\ 		printf("command %p is on another queue, flags = %#x\n",	\ 		       cm, cm->cm_flags);				\ 		panic("command is on another queue");			\ 	}								\ 	TAILQ_INSERT_TAIL(&cm->cm_sc->aac_ ## name, cm, cm_link);	\ 	cm->cm_flags |= AAC_ON_ ## index;				\ 	AACQ_ADD(cm->cm_sc, index);					\ }									\ static __inline void							\ aac_requeue_ ## name (struct aac_command *cm)				\ {									\ 	if ((cm->cm_flags& AAC_ON_AACQ_MASK) != 0) {			\ 		printf("command %p is on another queue, flags = %#x\n",	\ 		       cm, cm->cm_flags);				\ 		panic("command is on another queue");			\ 	}								\ 	TAILQ_INSERT_HEAD(&cm->cm_sc->aac_ ## name, cm, cm_link);	\ 	cm->cm_flags |= AAC_ON_ ## index;				\ 	AACQ_ADD(cm->cm_sc, index);					\ }									\ static __inline struct aac_command *					\ aac_dequeue_ ## name (struct aac_softc *sc)				\ {									\ 	struct aac_command *cm;						\ 									\ 	if ((cm = TAILQ_FIRST(&sc->aac_ ## name)) != NULL) {		\ 		if ((cm->cm_flags& AAC_ON_ ## index) == 0) {		\ 			printf("command %p not in queue, flags = %#x, "	\ 		       	       "bit = %#x\n", cm, cm->cm_flags,		\ 			       AAC_ON_ ## index);			\ 			panic("command not in queue");			\ 		}							\ 		TAILQ_REMOVE(&sc->aac_ ## name, cm, cm_link);		\ 		cm->cm_flags&= ~AAC_ON_ ## index;			\ 		AACQ_REMOVE(sc, index);					\ 	}								\ 	return(cm);							\ }									\ static __inline void							\ aac_remove_ ## name (struct aac_command *cm)				\ {									\ 	if ((cm->cm_flags& AAC_ON_ ## index) == 0) {			\ 		printf("command %p not in queue, flags = %#x, "		\ 		       "bit = %#x\n", cm, cm->cm_flags, 		\ 		       AAC_ON_ ## index);				\ 		panic("command not in queue");				\ 	}								\ 	TAILQ_REMOVE(&cm->cm_sc->aac_ ## name, cm, cm_link);		\ 	cm->cm_flags&= ~AAC_ON_ ## index;				\ 	AACQ_REMOVE(cm->cm_sc, index);					\ }									\ struct hack
end_define

begin_expr_stmt
name|AACQ_COMMAND_QUEUE
argument_list|(
name|free
argument_list|,
name|AACQ_FREE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|AACQ_COMMAND_QUEUE
argument_list|(
name|ready
argument_list|,
name|AACQ_READY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|AACQ_COMMAND_QUEUE
argument_list|(
name|busy
argument_list|,
name|AACQ_BUSY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * outstanding bio queue  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|aac_initq_bio
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
block|{
name|bioq_init
argument_list|(
operator|&
name|sc
operator|->
name|aac_bioq
argument_list|)
expr_stmt|;
name|AACQ_INIT
argument_list|(
name|sc
argument_list|,
name|AACQ_BIO
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|aac_enqueue_bio
parameter_list|(
name|struct
name|aac_softc
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
name|aac_bioq
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|AACQ_ADD
argument_list|(
name|sc
argument_list|,
name|AACQ_BIO
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
name|aac_dequeue_bio
argument_list|(
argument|struct aac_softc *sc
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
name|aac_bioq
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
name|aac_bioq
argument_list|,
name|bp
argument_list|)
expr_stmt|;
name|AACQ_REMOVE
argument_list|(
name|sc
argument_list|,
name|AACQ_BIO
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

begin_function
unit|}  static
name|__inline
name|void
name|aac_print_printf
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* 	 * XXX We have the ability to read the length of the printf string 	 * from out of the mailboxes. 	 */
name|device_printf
argument_list|(
name|sc
operator|->
name|aac_dev
argument_list|,
literal|"**Monitor** %.*s"
argument_list|,
name|AAC_PRINTF_BUFSIZE
argument_list|,
name|sc
operator|->
name|aac_common
operator|->
name|ac_printf
argument_list|)
expr_stmt|;
name|sc
operator|->
name|aac_common
operator|->
name|ac_printf
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|AAC_QNOTIFY
argument_list|(
name|sc
argument_list|,
name|AAC_DB_PRINTF
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|aac_alloc_sync_fib
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|aac_fib
modifier|*
modifier|*
name|fib
parameter_list|)
block|{
name|mtx_assert
argument_list|(
operator|&
name|sc
operator|->
name|aac_io_lock
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
operator|*
name|fib
operator|=
operator|&
name|sc
operator|->
name|aac_common
operator|->
name|ac_sync_fib
expr_stmt|;
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
name|aac_release_sync_fib
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|)
block|{
name|mtx_assert
argument_list|(
operator|&
name|sc
operator|->
name|aac_io_lock
argument_list|,
name|MA_OWNED
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

