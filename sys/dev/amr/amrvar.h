begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_comment
comment|/*  * We could actually use all 17 segments, but using only 16 means that  * each scatter/gather map is 128 bytes in size, and thus we don't have to worry about  * maps crossing page boundaries.  */
end_comment

begin_define
define|#
directive|define
name|AMR_NSEG
value|16
end_define

begin_define
define|#
directive|define
name|AMR_CFG_BASE
value|0x10
end_define

begin_define
define|#
directive|define
name|AMR_CFG_SIG
value|0xa0
end_define

begin_define
define|#
directive|define
name|AMR_SIGNATURE
value|0x3344
end_define

begin_define
define|#
directive|define
name|AMR_MAXCMD
value|255
end_define

begin_comment
comment|/* ident = 0 not allowed */
end_comment

begin_define
define|#
directive|define
name|AMR_MAXLD
value|40
end_define

begin_define
define|#
directive|define
name|AMR_BLKSIZE
value|512
end_define

begin_struct_decl
struct_decl|struct
name|amr_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Per-logical-drive datastructure  */
end_comment

begin_struct
struct|struct
name|amr_logdrive
block|{
name|u_int32_t
name|al_size
decl_stmt|;
name|int
name|al_state
decl_stmt|;
name|int
name|al_properties
decl_stmt|;
comment|/* synthetic geometry */
name|int
name|al_cylinders
decl_stmt|;
name|int
name|al_heads
decl_stmt|;
name|int
name|al_sectors
decl_stmt|;
comment|/* driver */
name|device_t
name|al_disk
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-command control structure.  */
end_comment

begin_struct
struct|struct
name|amr_command
block|{
name|TAILQ_ENTRY
argument_list|(
argument|amr_command
argument_list|)
name|ac_link
expr_stmt|;
name|struct
name|amr_softc
modifier|*
name|ac_sc
decl_stmt|;
name|u_int8_t
name|ac_slot
decl_stmt|;
name|int
name|ac_status
decl_stmt|;
define|#
directive|define
name|AMR_STATUS_BUSY
value|0xffff
define|#
directive|define
name|AMR_STATUS_WEDGED
value|0xdead
name|struct
name|amr_mailbox
name|ac_mailbox
decl_stmt|;
name|u_int32_t
name|ac_sgphys
decl_stmt|;
name|int
name|ac_nsgent
decl_stmt|;
name|int
name|ac_flags
decl_stmt|;
define|#
directive|define
name|AMR_CMD_DATAIN
value|(1<<0)
define|#
directive|define
name|AMR_CMD_DATAOUT
value|(1<<1)
define|#
directive|define
name|AMR_CMD_PRIORITY
value|(1<<2)
name|time_t
name|ac_stamp
decl_stmt|;
name|void
modifier|*
name|ac_data
decl_stmt|;
name|size_t
name|ac_length
decl_stmt|;
name|bus_dmamap_t
name|ac_dmamap
decl_stmt|;
name|u_int32_t
name|ac_dataphys
decl_stmt|;
name|void
function_decl|(
modifier|*
name|ac_complete
function_decl|)
parameter_list|(
name|struct
name|amr_command
modifier|*
name|ac
parameter_list|)
function_decl|;
name|void
modifier|*
name|ac_private
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|amr_softc
block|{
comment|/* bus attachments */
name|device_t
name|amr_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|amr_reg
decl_stmt|;
comment|/* control registers */
name|bus_space_handle_t
name|amr_bhandle
decl_stmt|;
name|bus_space_tag_t
name|amr_btag
decl_stmt|;
name|bus_dma_tag_t
name|amr_parent_dmat
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|amr_buffer_dmat
decl_stmt|;
comment|/* data buffer DMA tag */
name|struct
name|resource
modifier|*
name|amr_irq
decl_stmt|;
comment|/* interrupt */
name|void
modifier|*
name|amr_intr
decl_stmt|;
comment|/* mailbox */
name|struct
name|amr_mailbox
modifier|*
name|amr_mailbox
decl_stmt|;
name|struct
name|amr_mailbox64
modifier|*
name|amr_mailbox64
decl_stmt|;
name|u_int32_t
name|amr_mailboxphys
decl_stmt|;
name|bus_dma_tag_t
name|amr_mailbox_dmat
decl_stmt|;
name|bus_dmamap_t
name|amr_mailbox_dmamap
decl_stmt|;
comment|/* scatter/gather lists and their controller-visible mappings */
name|struct
name|amr_sgentry
modifier|*
name|amr_sgtable
decl_stmt|;
comment|/* s/g lists */
name|u_int32_t
name|amr_sgbusaddr
decl_stmt|;
comment|/* s/g table base address in bus space */
name|bus_dma_tag_t
name|amr_sg_dmat
decl_stmt|;
comment|/* s/g buffer DMA tag */
name|bus_dmamap_t
name|amr_sg_dmamap
decl_stmt|;
comment|/* map for s/g buffers */
comment|/* controller limits and features */
name|int
name|amr_maxio
decl_stmt|;
comment|/* maximum number of I/O transactions */
name|int
name|amr_maxdrives
decl_stmt|;
comment|/* max number of logical drives */
comment|/* connected logical drives */
name|struct
name|amr_logdrive
name|amr_drive
index|[
name|AMR_MAXLD
index|]
decl_stmt|;
comment|/* controller status */
name|int
name|amr_state
decl_stmt|;
define|#
directive|define
name|AMR_STATE_OPEN
value|(1<<0)
define|#
directive|define
name|AMR_STATE_SUSPEND
value|(1<<1)
define|#
directive|define
name|AMR_STATE_INTEN
value|(1<<2)
define|#
directive|define
name|AMR_STATE_SHUTDOWN
value|(1<<3)
comment|/* per-controller queues */
name|struct
name|buf_queue_head
name|amr_bufq
decl_stmt|;
comment|/* pending I/O */
name|int
name|amr_waitbufs
decl_stmt|;
name|struct
name|amr_command
modifier|*
name|amr_busycmd
index|[
name|AMR_MAXCMD
index|]
decl_stmt|;
name|int
name|amr_busycmdcount
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|amr_command
argument_list|)
name|amr_donecmds
expr_stmt|;
name|int
name|amr_donecmdcount
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|amr_command
argument_list|)
name|amr_freecmds
expr_stmt|;
comment|/* controller type-specific support */
name|int
name|amr_type
decl_stmt|;
define|#
directive|define
name|AMR_TYPE_STD
value|0
define|#
directive|define
name|AMR_TYPE_QUARTZ
value|1
name|void
function_decl|(
modifier|*
name|amr_submit_command
function_decl|)
parameter_list|(
name|struct
name|amr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|amr_get_work
function_decl|)
parameter_list|(
name|struct
name|amr_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|amr_mailbox
modifier|*
name|mbsave
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|amr_attach_mailbox
function_decl|)
parameter_list|(
name|struct
name|amr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * I/O primitives  */
end_comment

begin_comment
comment|/* Quartz */
end_comment

begin_define
define|#
directive|define
name|AMR_QPUT_IDB
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->amr_btag, sc->amr_bhandle, AMR_QIDB, val)
end_define

begin_define
define|#
directive|define
name|AMR_QGET_IDB
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_4 (sc->amr_btag, sc->amr_bhandle, AMR_QIDB)
end_define

begin_define
define|#
directive|define
name|AMR_QPUT_ODB
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->amr_btag, sc->amr_bhandle, AMR_QODB, val)
end_define

begin_define
define|#
directive|define
name|AMR_QGET_ODB
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_4 (sc->amr_btag, sc->amr_bhandle, AMR_QODB)
end_define

begin_comment
comment|/* Standard */
end_comment

begin_define
define|#
directive|define
name|AMR_SPUT_ISTAT
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_SINTR, val)
end_define

begin_define
define|#
directive|define
name|AMR_SGET_ISTAT
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_1 (sc->amr_btag, sc->amr_bhandle, AMR_SINTR)
end_define

begin_define
define|#
directive|define
name|AMR_SACK_INTERRUPT
parameter_list|(
name|sc
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_SCMD, AMR_SCMD_ACKINTR)
end_define

begin_define
define|#
directive|define
name|AMR_SPOST_COMMAND
parameter_list|(
name|sc
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_SCMD, AMR_SCMD_POST)
end_define

begin_define
define|#
directive|define
name|AMR_SGET_MBSTAT
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_1 (sc->amr_btag, sc->amr_bhandle, AMR_SMBOX_BUSY)
end_define

begin_define
define|#
directive|define
name|AMR_SENABLE_INTR
parameter_list|(
name|sc
parameter_list|)
define|\
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_STOGGLE, 						\ 			  bus_space_read_1(sc->amr_btag, sc->amr_bhandle, AMR_STOGGLE) | AMR_STOGL_IENABLE)
end_define

begin_define
define|#
directive|define
name|AMR_SDISABLE_INTR
parameter_list|(
name|sc
parameter_list|)
define|\
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_STOGGLE, 						\ 			  bus_space_read_1(sc->amr_btag, sc->amr_bhandle, AMR_STOGGLE)& ~AMR_STOGL_IENABLE)
end_define

begin_define
define|#
directive|define
name|AMR_SBYTE_SET
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, reg, val)
end_define

begin_comment
comment|/*  * Interface between bus connections and driver core.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|amr_free
parameter_list|(
name|struct
name|amr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amr_attach
parameter_list|(
name|struct
name|amr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amr_startup
parameter_list|(
name|struct
name|amr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|amr_intr
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
name|amr_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amr_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amr_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|amr_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|d_open_t
name|amr_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|d_close_t
name|amr_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|d_ioctl_t
name|amr_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|amr_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * MegaRAID logical disk driver  */
end_comment

begin_struct
struct|struct
name|amrd_softc
block|{
name|device_t
name|amrd_dev
decl_stmt|;
name|struct
name|amr_softc
modifier|*
name|amrd_controller
decl_stmt|;
name|struct
name|amr_logdrive
modifier|*
name|amrd_drive
decl_stmt|;
name|struct
name|disk
name|amrd_disk
decl_stmt|;
name|struct
name|devstat
name|amrd_stats
decl_stmt|;
name|struct
name|disklabel
name|amrd_label
decl_stmt|;
name|int
name|amrd_unit
decl_stmt|;
name|int
name|amrd_flags
decl_stmt|;
define|#
directive|define
name|AMRD_OPEN
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
name|amr_submit_buf
parameter_list|(
name|struct
name|amr_softc
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
name|amr_submit_ioctl
parameter_list|(
name|struct
name|amr_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|amr_logdrive
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
name|amrd_intr
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

end_unit

