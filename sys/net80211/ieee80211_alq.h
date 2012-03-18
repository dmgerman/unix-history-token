begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Adrian Chadd, Xenion Lty Ltd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IEEE80211_ALQ_H__
end_ifndef

begin_define
define|#
directive|define
name|__IEEE80211_ALQ_H__
end_define

begin_comment
comment|/*  * 64 byte ieee80211_alq_rec size.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ALQ_PAYLOAD_SIZE
value|52
end_define

begin_comment
comment|/*  * timestamp  * wlan interface  * operation  * sub-operation  * rest of structure - operation specific  */
end_comment

begin_struct
struct|struct
name|ieee80211_alq_rec
block|{
name|uint32_t
name|r_timestamp
decl_stmt|;
comment|/* XXX may wrap! */
name|uint32_t
name|r_threadid
decl_stmt|;
comment|/* current thread id */
name|uint16_t
name|r_wlan
decl_stmt|;
comment|/* wlan interface number */
name|uint8_t
name|r_version
decl_stmt|;
comment|/* version */
name|uint8_t
name|r_op
decl_stmt|;
comment|/* top-level operation id */
name|u_char
name|r_payload
index|[
name|IEEE80211_ALQ_PAYLOAD_SIZE
index|]
decl_stmt|;
comment|/* operation-specific payload */
block|}
struct|;
end_struct

begin_comment
comment|/* General logging function */
end_comment

begin_function_decl
specifier|extern
name|void
name|ieee80211_alq_log
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|uint8_t
name|op
parameter_list|,
name|u_char
modifier|*
name|p
parameter_list|,
name|int
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Debugging entry points  */
end_comment

begin_comment
comment|/*  * This should be called by the driver on each RX frame.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ALQ_OP_RXFRAME
value|0x1
end_define

begin_define
define|#
directive|define
name|IEEE80211_ALQ_OP_TXFRAME
value|0x2
end_define

begin_define
define|#
directive|define
name|IEEE80211_ALQ_OP_TXCOMPLETE
value|0x3
end_define

begin_define
define|#
directive|define
name|IEEE80211_ALQ_OP_TX_BAW
value|0x4
end_define

begin_comment
comment|/* Driver-specific - for descriptor contents, etc */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ALQ_OP_RX_DESC
value|0x81
end_define

begin_define
define|#
directive|define
name|IEEE80211_ALQ_OP_TX_DESC
value|0x82
end_define

begin_define
define|#
directive|define
name|IEEE80211_ALQ_OP_TX_DESCCOMP
value|0x83
end_define

begin_struct
struct|struct
name|ieee80211_alq_rx_frame_struct
block|{
name|uint64_t
name|tsf
decl_stmt|;
comment|/* Network order */
name|uintptr_t
name|bf
decl_stmt|;
comment|/* Driver-specific buffer ptr */
name|uint8_t
name|rxq
decl_stmt|;
comment|/* Driver-specific RX queue */
name|uint8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* Pad alignment */
name|struct
name|ieee80211_qosframe
name|wh
decl_stmt|;
comment|/* XXX 4 bytes, QoS? */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_alq_tx_frame
block|{
name|uint64_t
name|tsf
decl_stmt|;
comment|/* Network order */
name|uintptr_t
name|bf
decl_stmt|;
comment|/* Driver-specific buffer ptr */
name|uint32_t
name|tx_flags
decl_stmt|;
comment|/* Driver-specific TX flags */
name|uint8_t
name|txq
decl_stmt|;
comment|/* Driver-specific TX queue */
name|uint8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* Pad alignment */
name|struct
name|ieee80211_qosframe
name|wh
decl_stmt|;
comment|/* XXX 4 bytes, QoS? */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_alq_tx_frame_complete
block|{
name|uint64_t
name|tsf
decl_stmt|;
comment|/* Network order */
name|uintptr_t
name|bf
decl_stmt|;
comment|/* Driver-specific buffer ptr */
name|uint8_t
name|txq
decl_stmt|;
comment|/* Driver-specific TX queue */
name|uint8_t
name|txstatus
decl_stmt|;
comment|/* driver-specific TX status */
name|uint8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad alignment */
name|struct
name|ieee80211_qosframe
name|wh
decl_stmt|;
comment|/* XXX 4 bytes, QoS? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is used for frame RX.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ieee80211_alq_rx_frame
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|struct
name|ieee80211_frame
modifier|*
name|wh
parameter_list|,
name|uint64_t
name|tsf
parameter_list|,
name|void
modifier|*
name|bf
parameter_list|,
name|uint8_t
name|rxq
parameter_list|)
block|{
name|struct
name|ieee80211_alq_rx_frame_struct
name|rf
decl_stmt|;
name|memset
argument_list|(
operator|&
name|rf
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|rf
argument_list|)
argument_list|)
expr_stmt|;
name|rf
operator|.
name|tsf
operator|=
name|htole64
argument_list|(
name|tsf
argument_list|)
expr_stmt|;
name|rf
operator|.
name|bf
operator|=
operator|(
name|uintptr_t
operator|)
name|bf
expr_stmt|;
name|rf
operator|.
name|rxq
operator|=
name|rxq
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|rf
operator|.
name|wh
argument_list|,
name|wh
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ieee80211_qosframe
argument_list|)
argument_list|)
expr_stmt|;
name|ieee80211_alq_log
argument_list|(
name|vap
argument_list|,
name|IEEE80211_ALQ_OP_RXFRAME
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|rf
argument_list|,
sizeof|sizeof
argument_list|(
name|rf
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Frame TX scheduling  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ieee80211_alq_tx_frame
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|struct
name|ieee80211_frame
modifier|*
name|wh
parameter_list|,
name|uint64_t
name|tsf
parameter_list|,
name|void
modifier|*
name|bf
parameter_list|,
name|uint8_t
name|txq
parameter_list|,
name|uint32_t
name|tx_flags
parameter_list|)
block|{  }
end_function

begin_comment
comment|/*  * Frame TX completion  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ieee80211_alq_tx_frame_comp
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|struct
name|ieee80211_frame
modifier|*
name|wh
parameter_list|,
name|uint64_t
name|tsf
parameter_list|,
name|void
modifier|*
name|bf
parameter_list|,
name|uint8_t
name|txq
parameter_list|,
name|uint8_t
name|tx_status
parameter_list|)
block|{  }
end_function

begin_struct
struct|struct
name|ieee80211_alq_tx_baw_note_struct
block|{
name|uintptr_t
name|bf
decl_stmt|;
name|uint8_t
name|tid
decl_stmt|;
name|uint8_t
name|what
decl_stmt|;
name|uint16_t
name|baw
decl_stmt|;
name|uint16_t
name|wnd
decl_stmt|;
name|uint16_t
name|new_baw
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TX BAW noting - add, remove, etc  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ALQ_TX_BAW_ADD
value|0x1
end_define

begin_define
define|#
directive|define
name|IEEE80211_ALQ_TX_BAW_COMPLETE
value|0x2
end_define

begin_function
specifier|static
specifier|inline
name|void
name|ieee80211_alq_tx_baw_note
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|struct
name|ieee80211_frame
modifier|*
name|wh
parameter_list|,
name|void
modifier|*
name|bf
parameter_list|,
name|uint8_t
name|tid
parameter_list|,
name|uint8_t
name|what
parameter_list|,
name|uint16_t
name|baw
parameter_list|,
name|uint16_t
name|wnd
parameter_list|,
name|uint16_t
name|new_baw
parameter_list|)
block|{
name|struct
name|ieee80211_alq_tx_baw_note_struct
name|tb
decl_stmt|;
name|memset
argument_list|(
operator|&
name|tb
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|tb
argument_list|)
argument_list|)
expr_stmt|;
name|tb
operator|.
name|bf
operator|=
operator|(
name|uintptr_t
operator|)
name|bf
expr_stmt|;
name|tb
operator|.
name|tid
operator|=
name|tid
expr_stmt|;
name|tb
operator|.
name|what
operator|=
name|what
expr_stmt|;
name|tb
operator|.
name|baw
operator|=
name|htons
argument_list|(
name|baw
argument_list|)
expr_stmt|;
name|tb
operator|.
name|wnd
operator|=
name|htons
argument_list|(
name|wnd
argument_list|)
expr_stmt|;
name|tb
operator|.
name|new_baw
operator|=
name|htons
argument_list|(
name|new_baw
argument_list|)
expr_stmt|;
name|ieee80211_alq_log
argument_list|(
name|vap
argument_list|,
name|IEEE80211_ALQ_OP_TX_BAW
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|tb
argument_list|,
sizeof|sizeof
argument_list|(
name|tb
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IEEE80211_ALQ_H__ */
end_comment

end_unit

