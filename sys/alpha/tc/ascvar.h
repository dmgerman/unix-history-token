begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: ascvar.h,v 1.4 1997/11/28 18:23:40 mhitch Exp $	*/
end_comment

begin_comment
comment|/*  * State kept for each active SCSI device.  */
end_comment

begin_struct_decl
struct_decl|struct
name|script
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|scsi_state
block|{
name|struct
name|script
modifier|*
name|script
decl_stmt|;
comment|/* saved script while processing error */
name|int
name|statusByte
decl_stmt|;
comment|/* status byte returned during STATUS_PHASE */
name|int
name|error
decl_stmt|;
comment|/* errno to pass back to device driver */
name|u_char
modifier|*
name|dmaBufAddr
decl_stmt|;
comment|/* DMA buffer address */
name|int
name|dmalen
decl_stmt|;
comment|/* amount to transfer in this chunk */
name|int
name|dmaresid
decl_stmt|;
comment|/* amount not transfered if chunk suspended */
name|int
name|buflen
decl_stmt|;
comment|/* total remaining amount of data to transfer */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* current pointer within scsicmd->buf */
name|int
name|flags
decl_stmt|;
comment|/* see below */
name|int
name|msglen
decl_stmt|;
comment|/* number of message bytes to read */
name|int
name|msgcnt
decl_stmt|;
comment|/* number of message bytes received */
name|u_char
name|sync_period
decl_stmt|;
comment|/* DMA synchronous period */
name|u_char
name|sync_offset
decl_stmt|;
comment|/* DMA synchronous xfer offset or 0 if async */
name|u_char
name|msg_out
decl_stmt|;
comment|/* next MSG_OUT byte to send */
name|u_char
name|msg_in
index|[
literal|16
index|]
decl_stmt|;
comment|/* buffer for multibyte messages */
block|}
name|State
typedef|;
end_typedef

begin_comment
comment|/* state flags */
end_comment

begin_define
define|#
directive|define
name|DISCONN
value|0x001
end_define

begin_comment
comment|/* true if currently disconnected from bus */
end_comment

begin_define
define|#
directive|define
name|DMA_IN_PROGRESS
value|0x002
end_define

begin_comment
comment|/* true if data DMA started */
end_comment

begin_define
define|#
directive|define
name|DMA_IN
value|0x004
end_define

begin_comment
comment|/* true if reading from SCSI device */
end_comment

begin_define
define|#
directive|define
name|DMA_RESUME
value|0x08
end_define

begin_comment
comment|/* true if DMA was interrupted by disc. */
end_comment

begin_define
define|#
directive|define
name|DMA_OUT
value|0x010
end_define

begin_comment
comment|/* true if writing to SCSI device */
end_comment

begin_define
define|#
directive|define
name|DID_SYNC
value|0x020
end_define

begin_comment
comment|/* true if synchronous offset was negotiated */
end_comment

begin_define
define|#
directive|define
name|TRY_SYNC
value|0x040
end_define

begin_comment
comment|/* true if try neg. synchronous offset */
end_comment

begin_define
define|#
directive|define
name|PARITY_ERR
value|0x080
end_define

begin_comment
comment|/* true if parity error seen */
end_comment

begin_define
define|#
directive|define
name|CHECK_SENSE
value|0x100
end_define

begin_comment
comment|/* true if doing sense command */
end_comment

begin_comment
comment|/*  * State kept for each active SCSI host interface (53C94).  */
end_comment

begin_struct
struct|struct
name|asc_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* us as a device */
name|asc_regmap_t
modifier|*
name|regs
decl_stmt|;
comment|/* chip address */
specifier|volatile
name|int
modifier|*
name|dmar
decl_stmt|;
comment|/* DMA address register address */
name|int
name|sc_id
decl_stmt|;
comment|/* SCSI ID of this interface */
name|int
name|myidmask
decl_stmt|;
comment|/* ~(1<< myid) */
name|int
name|state
decl_stmt|;
comment|/* current SCSI connection state */
name|int
name|target
decl_stmt|;
comment|/* target SCSI ID if busy */
name|struct
name|script
modifier|*
name|script
decl_stmt|;
comment|/* next expected interrupt& action */
name|ScsiCmd
modifier|*
name|cmd
index|[
name|ASC_NCMD
index|]
decl_stmt|;
comment|/* active command indexed by SCSI ID */
name|State
name|st
index|[
name|ASC_NCMD
index|]
decl_stmt|;
comment|/* state info for each active command */
comment|/* Start dma routine */
name|int
argument_list|(
argument|*dma_start
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|asc_softc
operator|*
name|asc
operator|,
expr|struct
name|scsi_state
operator|*
name|state
operator|,
name|caddr_t
name|cp
operator|,
name|int
name|flag
operator|,
name|int
name|len
operator|,
name|int
name|off
operator|)
argument_list|)
expr_stmt|;
comment|/* End dma routine */
name|void
argument_list|(
argument|*dma_end
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|asc_softc
operator|*
name|asc
operator|,
expr|struct
name|scsi_state
operator|*
name|state
operator|,
name|int
name|flag
operator|)
argument_list|)
expr_stmt|;
name|u_char
modifier|*
name|dma_next
decl_stmt|;
name|int
name|dma_xfer
decl_stmt|;
comment|/* Dma len still to go */
name|int
name|min_period
decl_stmt|;
comment|/* Min transfer period clk/byte */
name|int
name|max_period
decl_stmt|;
comment|/* Max transfer period clk/byte */
name|int
name|ccf
decl_stmt|;
comment|/* CCF, whatever that really is? */
name|int
name|timeout_250
decl_stmt|;
comment|/* 250ms timeout */
name|int
name|tb_ticks
decl_stmt|;
comment|/* 4ns. ticks/tb channel ticks */
ifdef|#
directive|ifdef
name|USE_NEW_SCSI
name|struct
name|scsipi_link
name|sc_link
decl_stmt|;
comment|/* scsipi link struct */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|asc_softc
modifier|*
name|asc_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ASC_STATE_IDLE
value|0
end_define

begin_comment
comment|/* idle state */
end_comment

begin_define
define|#
directive|define
name|ASC_STATE_BUSY
value|1
end_define

begin_comment
comment|/* selecting or currently connected */
end_comment

begin_define
define|#
directive|define
name|ASC_STATE_TARGET
value|2
end_define

begin_comment
comment|/* currently selected as target */
end_comment

begin_define
define|#
directive|define
name|ASC_STATE_RESEL
value|3
end_define

begin_comment
comment|/* currently waiting for reselect */
end_comment

begin_define
define|#
directive|define
name|ASC_SPEED_25_MHZ
value|250
end_define

begin_define
define|#
directive|define
name|ASC_SPEED_12_5_MHZ
value|125
end_define

begin_decl_stmt
name|void
name|ascattach
name|__P
argument_list|(
operator|(
expr|struct
name|asc_softc
operator|*
name|asc
operator|,
name|int
name|bus_speed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|asc_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|asc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Dma operations.  */
end_comment

begin_define
define|#
directive|define
name|ASCDMA_READ
value|1
end_define

begin_define
define|#
directive|define
name|ASCDMA_WRITE
value|2
end_define

end_unit

