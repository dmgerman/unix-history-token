begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Luoqi Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|aic_transinfo
block|{
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aic_tinfo
block|{
name|u_int16_t
name|lubusy
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|scsirate
decl_stmt|;
name|struct
name|aic_transinfo
name|current
decl_stmt|;
name|struct
name|aic_transinfo
name|goal
decl_stmt|;
name|struct
name|aic_transinfo
name|user
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TINFO_DISC_ENB
value|0x01
end_define

begin_define
define|#
directive|define
name|TINFO_TAG_ENB
value|0x02
end_define

begin_define
define|#
directive|define
name|TINFO_SDTR_NEGO
value|0x04
end_define

begin_define
define|#
directive|define
name|TINFO_SDTR_SENT
value|0x08
end_define

begin_struct
struct|struct
name|aic_scb
block|{
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|tag
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int8_t
name|lun
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|cmd_len
decl_stmt|;
name|u_int8_t
modifier|*
name|cmd_ptr
decl_stmt|;
name|u_int32_t
name|data_len
decl_stmt|;
name|u_int8_t
modifier|*
name|data_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ccb_scb_ptr
value|spriv_ptr0
end_define

begin_define
define|#
directive|define
name|ccb_aic_ptr
value|spriv_ptr1
end_define

begin_define
define|#
directive|define
name|SCB_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCB_DISCONNECTED
value|0x02
end_define

begin_define
define|#
directive|define
name|SCB_DEVICE_RESET
value|0x04
end_define

begin_define
define|#
directive|define
name|SCB_SENSE
value|0x08
end_define

begin_enum
enum|enum
block|{
name|AIC6260
block|,
name|AIC6360
block|,
name|AIC6370
block|,
name|GM82C700
block|}
enum|;
end_enum

begin_struct
struct|struct
name|aic_softc
block|{
name|int
name|unit
decl_stmt|;
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_dma_tag_t
name|dmat
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
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|pending_ccbs
operator|,
name|nexus_ccbs
expr_stmt|;
name|struct
name|aic_scb
modifier|*
name|nexus
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|u_int8_t
name|initiator
decl_stmt|;
name|u_int8_t
name|state
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int8_t
name|lun
decl_stmt|;
name|u_int8_t
name|prev_phase
decl_stmt|;
name|u_int8_t
name|msg_outq
decl_stmt|;
name|u_int8_t
name|msg_sent
decl_stmt|;
name|int
name|msg_len
decl_stmt|;
name|char
name|msg_buf
index|[
literal|8
index|]
decl_stmt|;
name|struct
name|aic_tinfo
name|tinfo
index|[
literal|8
index|]
decl_stmt|;
name|struct
name|aic_scb
name|scbs
index|[
literal|256
index|]
decl_stmt|;
name|int
name|min_period
decl_stmt|;
name|int
name|max_period
decl_stmt|;
name|int
name|chip_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AIC_DISC_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|AIC_DMA_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|AIC_PARITY_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|AIC_DWIO_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|AIC_RESOURCE_SHORTAGE
value|0x10
end_define

begin_define
define|#
directive|define
name|AIC_DROP_MSGIN
value|0x20
end_define

begin_define
define|#
directive|define
name|AIC_BUSFREE_OK
value|0x40
end_define

begin_define
define|#
directive|define
name|AIC_FAST_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|AIC_IDLE
value|0x00
end_define

begin_define
define|#
directive|define
name|AIC_SELECTING
value|0x01
end_define

begin_define
define|#
directive|define
name|AIC_RESELECTED
value|0x02
end_define

begin_define
define|#
directive|define
name|AIC_RECONNECTING
value|0x03
end_define

begin_define
define|#
directive|define
name|AIC_HASNEXUS
value|0x04
end_define

begin_define
define|#
directive|define
name|AIC_MSG_IDENTIFY
value|0x01
end_define

begin_define
define|#
directive|define
name|AIC_MSG_TAG_Q
value|0x02
end_define

begin_define
define|#
directive|define
name|AIC_MSG_SDTR
value|0x04
end_define

begin_define
define|#
directive|define
name|AIC_MSG_WDTR
value|0x08
end_define

begin_define
define|#
directive|define
name|AIC_MSG_MSGBUF
value|0x80
end_define

begin_define
define|#
directive|define
name|AIC_SYNC_PERIOD
value|(200 / 4)
end_define

begin_define
define|#
directive|define
name|AIC_FAST_SYNC_PERIOD
value|(100 / 4)
end_define

begin_define
define|#
directive|define
name|AIC_MIN_SYNC_PERIOD
value|112
end_define

begin_define
define|#
directive|define
name|AIC_SYNC_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|aic_inb
parameter_list|(
name|aic
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((aic)->tag, (aic)->bsh, (port))
end_define

begin_define
define|#
directive|define
name|aic_outb
parameter_list|(
name|aic
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((aic)->tag, (aic)->bsh, (port), (value))
end_define

begin_define
define|#
directive|define
name|aic_insb
parameter_list|(
name|aic
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1((aic)->tag, (aic)->bsh, (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|aic_outsb
parameter_list|(
name|aic
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_1((aic)->tag, (aic)->bsh, (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|aic_insw
parameter_list|(
name|aic
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_2((aic)->tag, (aic)->bsh, (port), \ 		(u_int16_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|aic_outsw
parameter_list|(
name|aic
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_2((aic)->tag, (aic)->bsh, (port), \ 		(u_int16_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|aic_insl
parameter_list|(
name|aic
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_4((aic)->tag, (aic)->bsh, (port), \ 		(u_int32_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|aic_outsl
parameter_list|(
name|aic
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_4((aic)->tag, (aic)->bsh, (port), \ 		(u_int32_t *)(addr), (count))
end_define

begin_decl_stmt
specifier|extern
name|int
name|aic_probe
name|__P
argument_list|(
operator|(
expr|struct
name|aic_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|aic_attach
name|__P
argument_list|(
operator|(
expr|struct
name|aic_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|aic_detach
name|__P
argument_list|(
operator|(
expr|struct
name|aic_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|aic_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

