begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * We could actually use all 33 segments, but using only 32 means that  * each scatter/gather map is 256 bytes in size, and thus we don't have to worry about  * maps crossing page boundaries.  */
end_comment

begin_define
define|#
directive|define
name|MLX_NSEG
value|32
end_define

begin_comment
comment|/* max scatter/gather segments we use */
end_comment

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
name|struct
name|resource
modifier|*
name|mlx_mem
decl_stmt|;
comment|/* mailbox interface window */
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
name|int
name|mlx_hwid
decl_stmt|;
comment|/* hardware identifier */
name|int
name|mlx_maxiop
decl_stmt|;
comment|/* maximum number of I/O operations */
name|int
name|mlx_nchan
decl_stmt|;
comment|/* number of active channels */
name|int
name|mlx_maxiosize
decl_stmt|;
comment|/* largest I/O for this controller */
name|int
name|mlx_maxtarg
decl_stmt|;
comment|/* maximum number of targets per channel */
name|int
name|mlx_maxtags
decl_stmt|;
comment|/* maximum number of tags per device */
name|int
name|mlx_scsicap
decl_stmt|;
comment|/* SCSI capabilities */
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
name|struct
name|buf_queue_head
name|mlx_bufq
decl_stmt|;
comment|/* outstanding I/O operations */
name|int
name|mlx_waitbufs
decl_stmt|;
comment|/* number of bufs awaiting commands */
comment|/* controller status */
name|u_int8_t
name|mlx_fwminor
decl_stmt|;
comment|/* firmware revision */
name|u_int8_t
name|mlx_fwmajor
decl_stmt|;
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
name|u_int16_t
name|mlx_currevent
decl_stmt|;
comment|/* sequence number last time we looked */
name|int
name|mlx_polling
decl_stmt|;
comment|/* if> 0, polling operations still running */
name|int
name|mlx_rebuild
decl_stmt|;
comment|/* if>= 0, drive is being rebuilt */
name|u_int32_t
name|mlx_rebuildstat
decl_stmt|;
comment|/* blocks left to rebuild if active */
name|int
name|mlx_check
decl_stmt|;
comment|/* if>= 0, drive is being checked */
name|struct
name|mlx_pause
name|mlx_pause
decl_stmt|;
comment|/* pending pause operation details */
comment|/* interface-specific accessor functions */
name|int
name|mlx_iftype
decl_stmt|;
comment|/* interface protocol */
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
name|struct
name|buf
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

