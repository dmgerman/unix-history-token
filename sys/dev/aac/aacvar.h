begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                      Driver Parameter Definitions  ********************************************************************************  ********************************************************************************/
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
comment|/*  * FIBs are allocated in clusters as we need them; each cluster must be physically  * contiguous.  Set the number of FIBs to try to allocate in a cluster.  * Setting this value too high may result in FIBs not being available in conditions  * of high load with fragmented physical memory.  The value must be a multiple of  * (PAGE_SIZE / 512).  */
end_comment

begin_define
define|#
directive|define
name|AAC_CLUSTER_COUNT
value|64
end_define

begin_comment
comment|/*  * The controller reports status events in AIFs.  We hang on to a number of these  * in order to pass them out to user-space management tools.  */
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
comment|/*  * We wait this many seconds for the adapter to come ready if it is still booting  */
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
comment|/*  * Character device major numbers.  */
end_comment

begin_define
define|#
directive|define
name|AAC_DISK_MAJOR
value|200
end_define

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
name|dev_t
name|ad_dev_t
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
name|ad_disk
decl_stmt|;
name|struct
name|devstat
name|ad_stats
decl_stmt|;
name|struct
name|disklabel
name|ad_label
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
comment|/* FIB associated with this command */
name|u_int32_t
name|cm_fibphys
decl_stmt|;
comment|/* bus address of the FIB */
name|struct
name|bio
modifier|*
name|cm_data
decl_stmt|;
comment|/* pointer to data in kernel space */
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
comment|/* pointer to s/g table in command */
name|int
name|cm_flags
decl_stmt|;
define|#
directive|define
name|AAC_CMD_MAPPED
value|(1<<0)
comment|/* command has had its data mapped */
define|#
directive|define
name|AAC_CMD_DATAIN
value|(1<<1)
comment|/* command involves data moving from controller to host */
define|#
directive|define
name|AAC_CMD_DATAOUT
value|(1<<2)
comment|/* command involves data moving from host to controller */
define|#
directive|define
name|AAC_CMD_COMPLETED
value|(1<<3)
comment|/* command has been completed */
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command/command packet cluster.  *  * Due to the difficulty of using the zone allocator to create a new  * zone from within a module, we use our own clustering to reduce   * memory wastage due to allocating lots of these small structures.  */
end_comment

begin_struct
struct|struct
name|aac_command_cluster
block|{
name|TAILQ_ENTRY
argument_list|(
argument|aac_command_cluster
argument_list|)
name|cmc_link
expr_stmt|;
name|struct
name|aac_fib
modifier|*
name|cmc_fibs
decl_stmt|;
name|bus_dmamap_t
name|cmc_fibmap
decl_stmt|;
name|u_int32_t
name|cmc_fibphys
decl_stmt|;
name|struct
name|aac_command
name|cmc_command
index|[
name|AAC_CLUSTER_COUNT
index|]
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
name|aif_set_istatus
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
name|aif_get_mailboxstatus
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
value|((sc)->aac_if.aif_set_istatus((sc), (mask)))
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
value|((sc)->aac_if.aif_set_mailbox((sc), (command), (arg0), (arg1), (arg2), (arg3)))
end_define

begin_define
define|#
directive|define
name|AAC_GET_MAILBOXSTATUS
parameter_list|(
name|sc
parameter_list|)
value|((sc)->aac_if.aif_get_mailboxstatus((sc)))
end_define

begin_define
define|#
directive|define
name|AAC_MASK_INTERRUPTS
parameter_list|(
name|sc
parameter_list|)
value|((sc)->aac_if.aif_set_interrupts((sc), 0))
end_define

begin_define
define|#
directive|define
name|AAC_UNMASK_INTERRUPTS
parameter_list|(
name|sc
parameter_list|)
value|((sc)->aac_if.aif_set_interrupts((sc), 1))
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
value|bus_space_write_4(sc->aac_btag, sc->aac_bhandle, reg, val)
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
value|bus_space_read_4 (sc->aac_btag, sc->aac_bhandle, reg)
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
value|bus_space_write_2(sc->aac_btag, sc->aac_bhandle, reg, val)
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
value|bus_space_read_2 (sc->aac_btag, sc->aac_bhandle, reg)
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
value|bus_space_write_1(sc->aac_btag, sc->aac_bhandle, reg, val)
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
value|bus_space_read_1 (sc->aac_btag, sc->aac_bhandle, reg)
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
comment|/* register interface window */
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
comment|/* data buffer/command DMA tag */
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
name|bus_dma_tag_t
name|aac_common_dmat
decl_stmt|;
comment|/* common structure DMA tag */
name|bus_dmamap_t
name|aac_common_dmamap
decl_stmt|;
comment|/* common structure DMA map */
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
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_command_cluster
argument_list|)
name|aac_clusters
expr_stmt|;
comment|/* command memory blocks */
name|bus_dma_tag_t
name|aac_fib_dmat
decl_stmt|;
comment|/* DMA tag for allocating FIBs */
comment|/* command management */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_command
argument_list|)
name|aac_freecmds
expr_stmt|;
comment|/* command structures available for reuse */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_command
argument_list|)
name|aac_ready
expr_stmt|;
comment|/* commands on hold for controller resources */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aac_command
argument_list|)
name|aac_completed
expr_stmt|;
comment|/* commands which have been returned by the controller */
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
comment|/* connected containters */
name|struct
name|aac_container
name|aac_container
index|[
name|AAC_MAX_CONTAINERS
index|]
decl_stmt|;
comment|/* delayed activity infrastructure */
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500005
name|struct
name|task
name|aac_task_complete
decl_stmt|;
comment|/* deferred-completion task */
endif|#
directive|endif
name|struct
name|intr_config_hook
name|aac_ich
decl_stmt|;
comment|/* management interface */
name|dev_t
name|aac_dev_t
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
name|aac_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|aac_devclass
decl_stmt|;
end_decl_stmt

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
name|aac_complete_bio
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
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
value|do { if (level<= AAC_DEBUG) printf("%s: " fmt "\n", __FUNCTION__ , ##args); } while(0)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
value|do { if (level<= AAC_DEBUG) printf(__FUNCTION__ ": called\n"); } while(0)
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
value|aac_print_fib(sc, fib, __FUNCTION__)
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
name|aac_print_aif
parameter_list|(
name|sc
parameter_list|,
name|aif
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
comment|/*  * Borrowed from<struct.h>  */
end_comment

begin_comment
comment|/* Offset of the field in the structure. */
end_comment

begin_define
define|#
directive|define
name|fldoff
parameter_list|(
name|name
parameter_list|,
name|field
parameter_list|)
define|\
value|((int)&(((struct name *)0)->field))
end_define

begin_comment
comment|/********************************************************************************  * Queue primitives  *  * These are broken out individually to make statistics gathering easier.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|aac_enqueue_ready
parameter_list|(
name|struct
name|aac_command
modifier|*
name|cm
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|cm
operator|->
name|cm_sc
operator|->
name|aac_ready
argument_list|,
name|cm
argument_list|,
name|cm_link
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
name|aac_requeue_ready
parameter_list|(
name|struct
name|aac_command
modifier|*
name|cm
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|cm
operator|->
name|cm_sc
operator|->
name|aac_ready
argument_list|,
name|cm
argument_list|,
name|cm_link
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
name|aac_command
operator|*
name|aac_dequeue_ready
argument_list|(
argument|struct aac_softc *sc
argument_list|)
block|{     struct
name|aac_command
operator|*
name|cm
block|;
name|int
name|s
block|;
name|s
operator|=
name|splbio
argument_list|()
block|;
if|if
condition|(
operator|(
name|cm
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|sc
operator|->
name|aac_ready
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
name|aac_ready
argument_list|,
name|cm
argument_list|,
name|cm_link
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
name|cm
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|aac_enqueue_completed
parameter_list|(
name|struct
name|aac_command
modifier|*
name|cm
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|cm
operator|->
name|cm_sc
operator|->
name|aac_completed
argument_list|,
name|cm
argument_list|,
name|cm_link
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
name|aac_command
operator|*
name|aac_dequeue_completed
argument_list|(
argument|struct aac_softc *sc
argument_list|)
block|{     struct
name|aac_command
operator|*
name|cm
block|;
name|int
name|s
block|;
name|s
operator|=
name|splbio
argument_list|()
block|;
if|if
condition|(
operator|(
name|cm
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|sc
operator|->
name|aac_completed
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
name|aac_completed
argument_list|,
name|cm
argument_list|,
name|cm_link
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
name|cm
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|aac_enqueue_free
parameter_list|(
name|struct
name|aac_command
modifier|*
name|cm
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|cm
operator|->
name|cm_sc
operator|->
name|aac_freecmds
argument_list|,
name|cm
argument_list|,
name|cm_link
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
name|aac_command
operator|*
name|aac_dequeue_free
argument_list|(
argument|struct aac_softc *sc
argument_list|)
block|{     struct
name|aac_command
operator|*
name|cm
block|;
name|int
name|s
block|;
name|s
operator|=
name|splbio
argument_list|()
block|;
if|if
condition|(
operator|(
name|cm
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|sc
operator|->
name|aac_freecmds
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
name|aac_freecmds
argument_list|,
name|cm
argument_list|,
name|cm_link
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
name|cm
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|aac_enqueue_cluster
parameter_list|(
name|struct
name|aac_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|aac_command_cluster
modifier|*
name|cmc
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|sc
operator|->
name|aac_clusters
argument_list|,
name|cmc
argument_list|,
name|cmc_link
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
name|aac_command_cluster
operator|*
name|aac_dequeue_cluster
argument_list|(
argument|struct aac_softc *sc
argument_list|)
block|{     struct
name|aac_command_cluster
operator|*
name|cmc
block|;
name|int
name|s
block|;
name|s
operator|=
name|splbio
argument_list|()
block|;
if|if
condition|(
operator|(
name|cmc
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|sc
operator|->
name|aac_clusters
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
name|aac_clusters
argument_list|,
name|cmc
argument_list|,
name|cmc_link
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
name|cmc
operator|)
return|;
end_return

unit|}
end_unit

