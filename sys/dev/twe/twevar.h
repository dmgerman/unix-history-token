begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TWE_DEBUG
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
value|do { if (level<= TWE_DEBUG) printf("%s: " fmt "\n", __FUNCTION__ , ##args); } while(0)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
value|do { if (level<= TWE_DEBUG) printf(__FUNCTION__ ": called\n"); } while(0)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure describing a logical unit as attached to the controller  */
end_comment

begin_struct
struct|struct
name|twe_drive
block|{
comment|/* unit properties */
name|u_int32_t
name|td_size
decl_stmt|;
name|int
name|td_cylinders
decl_stmt|;
name|int
name|td_heads
decl_stmt|;
name|int
name|td_sectors
decl_stmt|;
name|int
name|td_unit
decl_stmt|;
comment|/* unit state */
name|int
name|td_state
decl_stmt|;
define|#
directive|define
name|TWE_DRIVE_READY
value|0
define|#
directive|define
name|TWE_DRIVE_DEGRADED
value|1
define|#
directive|define
name|TWE_DRIVE_OFFLINE
value|2
name|int
name|td_raidlevel
decl_stmt|;
define|#
directive|define
name|TWE_DRIVE_RAID0
value|0
define|#
directive|define
name|TWE_DRIVE_RAID1
value|1
define|#
directive|define
name|TWE_DRIVE_UNKNOWN
value|0xff
comment|/* handle for attached driver */
name|device_t
name|td_disk
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-command control structure.  *  * Note that due to alignment constraints on the tc_command field, this *must* be 64-byte aligned.  * We achieve this by placing the command at the beginning of the structure, and using malloc()  * to allocate each structure.  */
end_comment

begin_struct
struct|struct
name|twe_request
block|{
comment|/* controller command */
name|TWE_Command
name|tr_command
decl_stmt|;
comment|/* command as submitted to controller */
name|bus_dmamap_t
name|tr_cmdmap
decl_stmt|;
comment|/* DMA map for command */
name|u_int32_t
name|tr_cmdphys
decl_stmt|;
comment|/* address of command in controller space */
comment|/* command payload */
name|void
modifier|*
name|tr_data
decl_stmt|;
comment|/* data buffer */
name|void
modifier|*
name|tr_realdata
decl_stmt|;
comment|/* copy of real data buffer pointer for alignment fixup */
name|size_t
name|tr_length
decl_stmt|;
name|bus_dmamap_t
name|tr_dmamap
decl_stmt|;
comment|/* DMA map for data */
name|u_int32_t
name|tr_dataphys
decl_stmt|;
comment|/* data buffer base address in controller space */
name|TAILQ_ENTRY
argument_list|(
argument|twe_request
argument_list|)
name|tr_link
expr_stmt|;
comment|/* list linkage */
name|struct
name|twe_softc
modifier|*
name|tr_sc
decl_stmt|;
comment|/* controller that owns us */
name|int
name|tr_status
decl_stmt|;
comment|/* command status */
define|#
directive|define
name|TWE_CMD_SETUP
value|0
comment|/* being assembled */
define|#
directive|define
name|TWE_CMD_BUSY
value|1
comment|/* submitted to controller */
define|#
directive|define
name|TWE_CMD_COMPLETE
value|2
comment|/* completed by controller (maybe with error) */
define|#
directive|define
name|TWE_CMD_FAILED
value|3
comment|/* failed submission to controller */
name|int
name|tr_flags
decl_stmt|;
define|#
directive|define
name|TWE_CMD_DATAIN
value|(1<<0)
define|#
directive|define
name|TWE_CMD_DATAOUT
value|(1<<1)
define|#
directive|define
name|TWE_CMD_ALIGNBUF
value|(1<<2)
comment|/* data in bio is misaligned, have to copy to/from private buffer */
name|void
function_decl|(
modifier|*
name|tr_complete
function_decl|)
parameter_list|(
name|struct
name|twe_request
modifier|*
name|tr
parameter_list|)
function_decl|;
comment|/* completion handler */
name|void
modifier|*
name|tr_private
decl_stmt|;
comment|/* submitter-private data or wait channel */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-controller state.  */
end_comment

begin_struct
struct|struct
name|twe_softc
block|{
comment|/* bus connections */
name|device_t
name|twe_dev
decl_stmt|;
name|dev_t
name|twe_dev_t
decl_stmt|;
name|struct
name|resource
modifier|*
name|twe_io
decl_stmt|;
comment|/* register interface window */
name|bus_space_handle_t
name|twe_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|twe_btag
decl_stmt|;
comment|/* bus space tag */
name|bus_dma_tag_t
name|twe_parent_dmat
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|twe_buffer_dmat
decl_stmt|;
comment|/* data buffer DMA tag */
name|struct
name|resource
modifier|*
name|twe_irq
decl_stmt|;
comment|/* interrupt */
name|void
modifier|*
name|twe_intr
decl_stmt|;
comment|/* interrupt handle */
comment|/* controller queues and arrays */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twe_request
argument_list|)
name|twe_freecmds
expr_stmt|;
comment|/* command structures available for reuse */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|twe_request
argument_list|)
name|twe_work
expr_stmt|;
comment|/* active commands (busy or waiting for completion) */
name|struct
name|twe_request
modifier|*
name|twe_cmdlookup
index|[
name|TWE_Q_LENGTH
index|]
decl_stmt|;
comment|/* busy commands indexed by request ID */
name|int
name|twe_busycmds
decl_stmt|;
comment|/* count of busy commands */
name|struct
name|twe_drive
name|twe_drive
index|[
name|TWE_MAX_UNITS
index|]
decl_stmt|;
comment|/* attached drives */
name|struct
name|bio_queue_head
name|twe_bioq
decl_stmt|;
comment|/* outstanding I/O operations */
name|struct
name|twe_request
modifier|*
name|twe_deferred
decl_stmt|;
comment|/* request that the controller wouldn't take */
name|u_int16_t
name|twe_aen_queue
index|[
name|TWE_Q_LENGTH
index|]
decl_stmt|;
comment|/* AENs queued for userland tool(s) */
name|int
name|twe_aen_head
decl_stmt|,
name|twe_aen_tail
decl_stmt|;
comment|/* ringbuffer pointers for AEN queue */
comment|/* controller status */
name|int
name|twe_state
decl_stmt|;
define|#
directive|define
name|TWE_STATE_INTEN
value|(1<<0)
comment|/* interrupts have been enabled */
define|#
directive|define
name|TWE_STATE_SHUTDOWN
value|(1<<1)
comment|/* controller is shut down */
define|#
directive|define
name|TWE_STATE_OPEN
value|(1<<2)
comment|/* control device is open */
define|#
directive|define
name|TWE_STATE_SUSPEND
value|(1<<3)
comment|/* controller is suspended */
comment|/* delayed configuration hook */
name|struct
name|intr_config_hook
name|twe_ich
decl_stmt|;
comment|/* wait-for-aen notification */
name|int
name|twe_wait_aen
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Virtual disk driver.  */
end_comment

begin_struct
struct|struct
name|twed_softc
block|{
name|device_t
name|twed_dev
decl_stmt|;
name|dev_t
name|twed_dev_t
decl_stmt|;
name|struct
name|twe_softc
modifier|*
name|twed_controller
decl_stmt|;
comment|/* parent device softc */
name|struct
name|twe_drive
modifier|*
name|twed_drive
decl_stmt|;
comment|/* drive data in parent softc */
name|struct
name|disk
name|twed_disk
decl_stmt|;
comment|/* generic disk handle */
name|struct
name|devstat
name|twed_stats
decl_stmt|;
comment|/* accounting */
name|struct
name|disklabel
name|twed_label
decl_stmt|;
comment|/* synthetic label */
name|int
name|twed_flags
decl_stmt|;
define|#
directive|define
name|TWED_OPEN
value|(1<<0)
comment|/* drive is open (can't shut down) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface betwen driver core and disk driver (should be using a bus?)  */
end_comment

begin_function_decl
specifier|extern
name|int
name|twe_submit_buf
parameter_list|(
name|struct
name|twe_softc
modifier|*
name|sc
parameter_list|,
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
name|twed_intr
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

end_unit

