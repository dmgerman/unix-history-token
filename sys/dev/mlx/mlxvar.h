begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Debugging levels:  *  0 - quiet, only emit warnings  *  1 - noisy, emit major function points and things done  *  2 - extremely noisy, emit trace items in loops, etc.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MLX_DEBUG
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
value|do { if (level<= MLX_DEBUG) printf("%s: " fmt "\n", __FUNCTION__ , ##args); } while(0)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
value|do { if (level<= MLX_DEBUG) printf(__FUNCTION__ ": called\n"); } while(0)
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
comment|/*  * Regardless of the actual capacity of the controller, we will allocate space  * for 64 s/g entries.  Typically controllers support 17 or 33 entries (64k or  * 128k maximum transfer assuming 4k page size and non-optimal alignment), but  * making that fit cleanly without crossing page boundaries requires rounding up  * to the next power of two.  */
end_comment

begin_define
define|#
directive|define
name|MLX_NSEG
value|64
end_define

begin_define
define|#
directive|define
name|MLX_NSLOTS
value|256
end_define

begin_comment
comment|/* max number of command slots */
end_comment

begin_define
define|#
directive|define
name|MLX_MAXDRIVES
value|32
end_define

begin_comment
comment|/* max number of system drives */
end_comment

begin_comment
comment|/*  * Structure describing a System Drive as attached to the controller.  */
end_comment

begin_struct
struct|struct
name|mlx_sysdrive
block|{
comment|/* from MLX_CMD_ENQSYSDRIVE */
name|u_int32_t
name|ms_size
decl_stmt|;
name|int
name|ms_state
decl_stmt|;
name|int
name|ms_raidlevel
decl_stmt|;
comment|/* synthetic geometry */
name|int
name|ms_cylinders
decl_stmt|;
name|int
name|ms_heads
decl_stmt|;
name|int
name|ms_sectors
decl_stmt|;
comment|/* handle for attached driver */
name|device_t
name|ms_disk
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-command control structure.  */
end_comment

begin_struct
struct|struct
name|mlx_command
block|{
name|TAILQ_ENTRY
argument_list|(
argument|mlx_command
argument_list|)
name|mc_link
expr_stmt|;
comment|/* list linkage */
name|struct
name|mlx_softc
modifier|*
name|mc_sc
decl_stmt|;
comment|/* controller that owns us */
name|u_int8_t
name|mc_slot
decl_stmt|;
comment|/* command slot we occupy */
name|u_int16_t
name|mc_status
decl_stmt|;
comment|/* command completion status */
name|time_t
name|mc_timeout
decl_stmt|;
comment|/* when this command expires */
name|u_int8_t
name|mc_mailbox
index|[
literal|16
index|]
decl_stmt|;
comment|/* command mailbox */
name|u_int32_t
name|mc_sgphys
decl_stmt|;
comment|/* physical address of s/g array in controller space */
name|int
name|mc_nsgent
decl_stmt|;
comment|/* number of entries in s/g map */
name|int
name|mc_flags
decl_stmt|;
define|#
directive|define
name|MLX_CMD_DATAIN
value|(1<<0)
define|#
directive|define
name|MLX_CMD_DATAOUT
value|(1<<1)
define|#
directive|define
name|MLX_CMD_PRIORITY
value|(1<<2)
comment|/* high-priority command */
name|void
modifier|*
name|mc_data
decl_stmt|;
comment|/* data buffer */
name|size_t
name|mc_length
decl_stmt|;
name|bus_dmamap_t
name|mc_dmamap
decl_stmt|;
comment|/* DMA map for data */
name|u_int32_t
name|mc_dataphys
decl_stmt|;
comment|/* data buffer base address controller space */
name|void
function_decl|(
modifier|*
name|mc_complete
function_decl|)
parameter_list|(
name|struct
name|mlx_command
modifier|*
name|mc
parameter_list|)
function_decl|;
comment|/* completion handler */
name|void
modifier|*
name|mc_private
decl_stmt|;
comment|/* submitter-private data or wait channel */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-controller structure.  */
end_comment

begin_struct
struct|struct
name|mlx_softc
block|{
comment|/* bus connections */
name|device_t
name|mlx_dev
decl_stmt|;
name|dev_t
name|mlx_dev_t
decl_stmt|;
name|struct
name|resource
modifier|*
name|mlx_mem
decl_stmt|;
comment|/* mailbox interface window */
name|int
name|mlx_mem_rid
decl_stmt|;
name|int
name|mlx_mem_type
decl_stmt|;
name|bus_space_handle_t
name|mlx_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|mlx_btag
decl_stmt|;
comment|/* bus space tag */
name|bus_dma_tag_t
name|mlx_parent_dmat
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|mlx_buffer_dmat
decl_stmt|;
comment|/* data buffer DMA tag */
name|struct
name|resource
modifier|*
name|mlx_irq
decl_stmt|;
comment|/* interrupt */
name|void
modifier|*
name|mlx_intr
decl_stmt|;
comment|/* interrupt handle */
comment|/* scatter/gather lists and their controller-visible mappings */
name|struct
name|mlx_sgentry
modifier|*
name|mlx_sgtable
decl_stmt|;
comment|/* s/g lists */
name|u_int32_t
name|mlx_sgbusaddr
decl_stmt|;
comment|/* s/g table base address in bus space */
name|bus_dma_tag_t
name|mlx_sg_dmat
decl_stmt|;
comment|/* s/g buffer DMA tag */
name|bus_dmamap_t
name|mlx_sg_dmamap
decl_stmt|;
comment|/* map for s/g buffers */
comment|/* controller limits and features */
name|struct
name|mlx_enquiry2
modifier|*
name|mlx_enq2
decl_stmt|;
name|int
name|mlx_feature
decl_stmt|;
comment|/* controller features/quirks */
define|#
directive|define
name|MLX_FEAT_PAUSEWORKS
value|(1<<0)
comment|/* channel pause works as expected */
comment|/* controller queues and arrays */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|mlx_command
argument_list|)
name|mlx_freecmds
expr_stmt|;
comment|/* command structures available for reuse */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|mlx_command
argument_list|)
name|mlx_work
expr_stmt|;
comment|/* active commands */
name|struct
name|mlx_command
modifier|*
name|mlx_busycmd
index|[
name|MLX_NSLOTS
index|]
decl_stmt|;
comment|/* busy commands */
name|int
name|mlx_busycmds
decl_stmt|;
comment|/* count of busy commands */
name|struct
name|mlx_sysdrive
name|mlx_sysdrive
index|[
name|MLX_MAXDRIVES
index|]
decl_stmt|;
comment|/* system drives */
name|mlx_bioq
name|mlx_bioq
decl_stmt|;
comment|/* outstanding I/O operations */
name|int
name|mlx_waitbufs
decl_stmt|;
comment|/* number of bufs awaiting commands */
comment|/* controller status */
name|int
name|mlx_geom
decl_stmt|;
define|#
directive|define
name|MLX_GEOM_128_32
value|0
comment|/* geoemetry translation modes */
define|#
directive|define
name|MLX_GEOM_256_63
value|1
name|int
name|mlx_state
decl_stmt|;
define|#
directive|define
name|MLX_STATE_INTEN
value|(1<<0)
comment|/* interrupts have been enabled */
define|#
directive|define
name|MLX_STATE_SHUTDOWN
value|(1<<1)
comment|/* controller is shut down */
define|#
directive|define
name|MLX_STATE_OPEN
value|(1<<2)
comment|/* control device is open */
define|#
directive|define
name|MLX_STATE_SUSPEND
value|(1<<3)
comment|/* controller is suspended */
name|struct
name|callout_handle
name|mlx_timeout
decl_stmt|;
comment|/* periodic status monitor */
name|time_t
name|mlx_lastpoll
decl_stmt|;
comment|/* last time_second we polled for status */
name|u_int16_t
name|mlx_lastevent
decl_stmt|;
comment|/* sequence number of the last event we recorded */
name|int
name|mlx_currevent
decl_stmt|;
comment|/* sequence number last time we looked */
name|int
name|mlx_background
decl_stmt|;
comment|/* if != 0 rebuild or check is in progress */
define|#
directive|define
name|MLX_BACKGROUND_CHECK
value|1
comment|/* we started a check */
define|#
directive|define
name|MLX_BACKGROUND_REBUILD
value|2
comment|/* we started a rebuild */
define|#
directive|define
name|MLX_BACKGROUND_SPONTANEOUS
value|3
comment|/* it just happened somehow */
name|struct
name|mlx_rebuild_status
name|mlx_rebuildstat
decl_stmt|;
comment|/* last rebuild status */
name|struct
name|mlx_pause
name|mlx_pause
decl_stmt|;
comment|/* pending pause operation details */
name|int
name|mlx_locks
decl_stmt|;
comment|/* reentrancy avoidance */
name|int
name|mlx_flags
decl_stmt|;
define|#
directive|define
name|MLX_SPINUP_REPORTED
value|(1<<0)
comment|/* "spinning up drives" message displayed */
define|#
directive|define
name|MLX_EVENTLOG_BUSY
value|(1<<1)
comment|/* currently reading event log */
comment|/* interface-specific accessor functions */
name|int
name|mlx_iftype
decl_stmt|;
comment|/* interface protocol */
define|#
directive|define
name|MLX_IFTYPE_2
value|2
define|#
directive|define
name|MLX_IFTYPE_3
value|3
define|#
directive|define
name|MLX_IFTYPE_4
value|4
define|#
directive|define
name|MLX_IFTYPE_5
value|5
name|int
function_decl|(
modifier|*
name|mlx_tryqueue
function_decl|)
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mlx_command
modifier|*
name|mc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mlx_findcomplete
function_decl|)
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|,
name|u_int8_t
modifier|*
name|slot
parameter_list|,
name|u_int16_t
modifier|*
name|status
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mlx_intaction
function_decl|)
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|,
name|int
name|action
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mlx_fw_handshake
function_decl|)
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|,
name|int
modifier|*
name|error
parameter_list|,
name|int
modifier|*
name|param1
parameter_list|,
name|int
modifier|*
name|param2
parameter_list|)
function_decl|;
define|#
directive|define
name|MLX_INTACTION_DISABLE
value|0
define|#
directive|define
name|MLX_INTACTION_ENABLE
value|1
block|}
struct|;
end_struct

begin_comment
comment|/*  * Simple (stupid) locks.  *  * Note that these are designed to avoid reentrancy, not concurrency, and will  * need to be replaced with something better.  */
end_comment

begin_define
define|#
directive|define
name|MLX_LOCK_COMPLETING
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MLX_LOCK_STARTING
value|(1<<1)
end_define

begin_function
specifier|static
name|__inline
name|int
name|mlx_lock_tas
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|,
name|int
name|lock
parameter_list|)
block|{
if|if
condition|(
operator|(
name|sc
operator|)
operator|->
name|mlx_locks
operator|&
operator|(
name|lock
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|atomic_set_int
argument_list|(
operator|&
name|sc
operator|->
name|mlx_locks
argument_list|,
name|lock
argument_list|)
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
name|mlx_lock_clr
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|,
name|int
name|lock
parameter_list|)
block|{
name|atomic_clear_int
argument_list|(
operator|&
name|sc
operator|->
name|mlx_locks
argument_list|,
name|lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Interface between bus connections and driver core.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|mlx_free
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mlx_attach
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mlx_startup
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mlx_intr
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mlx_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mlx_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mlx_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mlx_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|d_open_t
name|mlx_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|d_close_t
name|mlx_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|d_ioctl_t
name|mlx_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|mlx_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|mlxd_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Mylex System Disk driver  */
end_comment

begin_struct
struct|struct
name|mlxd_softc
block|{
name|device_t
name|mlxd_dev
decl_stmt|;
name|dev_t
name|mlxd_dev_t
decl_stmt|;
name|struct
name|mlx_softc
modifier|*
name|mlxd_controller
decl_stmt|;
name|struct
name|mlx_sysdrive
modifier|*
name|mlxd_drive
decl_stmt|;
name|struct
name|disk
name|mlxd_disk
decl_stmt|;
name|struct
name|devstat
name|mlxd_stats
decl_stmt|;
name|struct
name|disklabel
name|mlxd_label
decl_stmt|;
name|int
name|mlxd_unit
decl_stmt|;
name|int
name|mlxd_flags
decl_stmt|;
define|#
directive|define
name|MLXD_OPEN
value|(1<<0)
comment|/* drive is open (can't shut down) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface between driver core and disk driver (should be using a bus?)  */
end_comment

begin_function_decl
specifier|extern
name|int
name|mlx_submit_buf
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|,
name|mlx_bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mlx_submit_ioctl
parameter_list|(
name|struct
name|mlx_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mlx_sysdrive
modifier|*
name|drive
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|int32_t
name|flag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mlxd_intr
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

end_unit

