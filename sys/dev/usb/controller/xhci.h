begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XHCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_XHCI_H_
end_define

begin_define
define|#
directive|define
name|XHCI_MAX_DEVICES
value|MIN(USB_MAX_DEVICES, 128)
end_define

begin_define
define|#
directive|define
name|XHCI_MAX_ENDPOINTS
value|32
end_define

begin_comment
comment|/* hardcoded - do not change */
end_comment

begin_define
define|#
directive|define
name|XHCI_MAX_SCRATCHPADS
value|32
end_define

begin_define
define|#
directive|define
name|XHCI_MAX_EVENTS
value|(16 * 13)
end_define

begin_define
define|#
directive|define
name|XHCI_MAX_COMMANDS
value|(16 * 1)
end_define

begin_define
define|#
directive|define
name|XHCI_MAX_RSEG
value|1
end_define

begin_define
define|#
directive|define
name|XHCI_MAX_TRANSFERS
value|4
end_define

begin_if
if|#
directive|if
name|USB_MAX_EP_STREAMS
operator|==
literal|8
end_if

begin_define
define|#
directive|define
name|XHCI_MAX_STREAMS
value|8
end_define

begin_define
define|#
directive|define
name|XHCI_MAX_STREAMS_LOG
value|3
end_define

begin_elif
elif|#
directive|elif
name|USB_MAX_EP_STREAMS
operator|==
literal|1
end_elif

begin_define
define|#
directive|define
name|XHCI_MAX_STREAMS
value|1
end_define

begin_define
define|#
directive|define
name|XHCI_MAX_STREAMS_LOG
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"The USB_MAX_EP_STREAMS value is not supported."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XHCI_DEV_CTX_ADDR_ALIGN
value|64
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_DEV_CTX_ALIGN
value|64
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_INPUT_CTX_ALIGN
value|64
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_SLOT_CTX_ALIGN
value|32
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_ENDP_CTX_ALIGN
value|32
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_STREAM_CTX_ALIGN
value|16
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_TRANS_RING_SEG_ALIGN
value|16
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_RING_SEG_ALIGN
value|64
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_EVENT_RING_SEG_ALIGN
value|64
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_SCRATCH_BUF_ARRAY_ALIGN
value|64
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_SCRATCH_BUFFER_ALIGN
value|USB_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|XHCI_TRB_ALIGN
value|16
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_TD_ALIGN
value|64
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_PAGE_SIZE
value|4096
end_define

begin_comment
comment|/* bytes */
end_comment

begin_struct
struct|struct
name|xhci_dev_ctx_addr
block|{
specifier|volatile
name|uint64_t
name|qwBaaDevCtxAddr
index|[
name|USB_MAX_DEVICES
operator|+
literal|1
index|]
decl_stmt|;
struct|struct
block|{
specifier|volatile
name|uint64_t
name|dummy
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|64
argument_list|)
name|padding
struct|;
specifier|volatile
name|uint64_t
name|qwSpBufPtr
index|[
name|XHCI_MAX_SCRATCHPADS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XHCI_EPNO2EPID
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)& UE_DIR_IN) ? 1 : 0) | (2 * ((x)& UE_ADDR)))
end_define

begin_struct
struct|struct
name|xhci_slot_ctx
block|{
specifier|volatile
name|uint32_t
name|dwSctx0
decl_stmt|;
define|#
directive|define
name|XHCI_SCTX_0_ROUTE_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFFF)
define|#
directive|define
name|XHCI_SCTX_0_ROUTE_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFFF)
define|#
directive|define
name|XHCI_SCTX_0_SPEED_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 20)
define|#
directive|define
name|XHCI_SCTX_0_SPEED_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0xF)
define|#
directive|define
name|XHCI_SCTX_0_MTT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
define|#
directive|define
name|XHCI_SCTX_0_MTT_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
define|#
directive|define
name|XHCI_SCTX_0_HUB_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
define|#
directive|define
name|XHCI_SCTX_0_HUB_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
define|#
directive|define
name|XHCI_SCTX_0_CTX_NUM_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1F)<< 27)
define|#
directive|define
name|XHCI_SCTX_0_CTX_NUM_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1F)
specifier|volatile
name|uint32_t
name|dwSctx1
decl_stmt|;
define|#
directive|define
name|XHCI_SCTX_1_MAX_EL_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
define|#
directive|define
name|XHCI_SCTX_1_MAX_EL_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
define|#
directive|define
name|XHCI_SCTX_1_RH_PORT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 16)
define|#
directive|define
name|XHCI_SCTX_1_RH_PORT_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFF)
define|#
directive|define
name|XHCI_SCTX_1_NUM_PORTS_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 24)
define|#
directive|define
name|XHCI_SCTX_1_NUM_PORTS_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
specifier|volatile
name|uint32_t
name|dwSctx2
decl_stmt|;
define|#
directive|define
name|XHCI_SCTX_2_TT_HUB_SID_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
define|#
directive|define
name|XHCI_SCTX_2_TT_HUB_SID_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
define|#
directive|define
name|XHCI_SCTX_2_TT_PORT_NUM_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 8)
define|#
directive|define
name|XHCI_SCTX_2_TT_PORT_NUM_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
define|#
directive|define
name|XHCI_SCTX_2_TT_THINK_TIME_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
define|#
directive|define
name|XHCI_SCTX_2_TT_THINK_TIME_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
define|#
directive|define
name|XHCI_SCTX_2_IRQ_TARGET_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3FF)<< 22)
define|#
directive|define
name|XHCI_SCTX_2_IRQ_TARGET_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x3FF)
specifier|volatile
name|uint32_t
name|dwSctx3
decl_stmt|;
define|#
directive|define
name|XHCI_SCTX_3_DEV_ADDR_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
define|#
directive|define
name|XHCI_SCTX_3_DEV_ADDR_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
define|#
directive|define
name|XHCI_SCTX_3_SLOT_STATE_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1F)<< 27)
define|#
directive|define
name|XHCI_SCTX_3_SLOT_STATE_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1F)
specifier|volatile
name|uint32_t
name|dwSctx4
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwSctx5
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwSctx6
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwSctx7
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_endp_ctx
block|{
specifier|volatile
name|uint32_t
name|dwEpCtx0
decl_stmt|;
define|#
directive|define
name|XHCI_EPCTX_0_EPSTATE_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
define|#
directive|define
name|XHCI_EPCTX_0_EPSTATE_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
define|#
directive|define
name|XHCI_EPCTX_0_MULT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
define|#
directive|define
name|XHCI_EPCTX_0_MULT_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3)
define|#
directive|define
name|XHCI_EPCTX_0_MAXP_STREAMS_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1F)<< 10)
define|#
directive|define
name|XHCI_EPCTX_0_MAXP_STREAMS_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1F)
define|#
directive|define
name|XHCI_EPCTX_0_LSA_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
define|#
directive|define
name|XHCI_EPCTX_0_LSA_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
define|#
directive|define
name|XHCI_EPCTX_0_IVAL_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 16)
define|#
directive|define
name|XHCI_EPCTX_0_IVAL_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFF)
specifier|volatile
name|uint32_t
name|dwEpCtx1
decl_stmt|;
define|#
directive|define
name|XHCI_EPCTX_1_CERR_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 1)
define|#
directive|define
name|XHCI_EPCTX_1_CERR_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x3)
define|#
directive|define
name|XHCI_EPCTX_1_EPTYPE_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 3)
define|#
directive|define
name|XHCI_EPCTX_1_EPTYPE_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x7)
define|#
directive|define
name|XHCI_EPCTX_1_HID_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
define|#
directive|define
name|XHCI_EPCTX_1_HID_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
define|#
directive|define
name|XHCI_EPCTX_1_MAXB_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 8)
define|#
directive|define
name|XHCI_EPCTX_1_MAXB_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
define|#
directive|define
name|XHCI_EPCTX_1_MAXP_SIZE_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
define|#
directive|define
name|XHCI_EPCTX_1_MAXP_SIZE_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
specifier|volatile
name|uint64_t
name|qwEpCtx2
decl_stmt|;
define|#
directive|define
name|XHCI_EPCTX_2_DCS_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1)
define|#
directive|define
name|XHCI_EPCTX_2_DCS_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1)
define|#
directive|define
name|XHCI_EPCTX_2_TR_DQ_PTR_MASK
value|0xFFFFFFFFFFFFFFF0U
specifier|volatile
name|uint32_t
name|dwEpCtx4
decl_stmt|;
define|#
directive|define
name|XHCI_EPCTX_4_AVG_TRB_LEN_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
define|#
directive|define
name|XHCI_EPCTX_4_AVG_TRB_LEN_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
define|#
directive|define
name|XHCI_EPCTX_4_MAX_ESIT_PAYLOAD_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
define|#
directive|define
name|XHCI_EPCTX_4_MAX_ESIT_PAYLOAD_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
specifier|volatile
name|uint32_t
name|dwEpCtx5
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwEpCtx6
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwEpCtx7
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_input_ctx
block|{
define|#
directive|define
name|XHCI_INCTX_NON_CTRL_MASK
value|0xFFFFFFFCU
specifier|volatile
name|uint32_t
name|dwInCtx0
decl_stmt|;
define|#
directive|define
name|XHCI_INCTX_0_DROP_MASK
parameter_list|(
name|n
parameter_list|)
value|(1U<< (n))
specifier|volatile
name|uint32_t
name|dwInCtx1
decl_stmt|;
define|#
directive|define
name|XHCI_INCTX_1_ADD_MASK
parameter_list|(
name|n
parameter_list|)
value|(1U<< (n))
specifier|volatile
name|uint32_t
name|dwInCtx2
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwInCtx3
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwInCtx4
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwInCtx5
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwInCtx6
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwInCtx7
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_input_dev_ctx
block|{
name|struct
name|xhci_input_ctx
name|ctx_input
decl_stmt|;
name|struct
name|xhci_slot_ctx
name|ctx_slot
decl_stmt|;
name|struct
name|xhci_endp_ctx
name|ctx_ep
index|[
name|XHCI_MAX_ENDPOINTS
operator|-
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_dev_ctx
block|{
name|struct
name|xhci_slot_ctx
name|ctx_slot
decl_stmt|;
name|struct
name|xhci_endp_ctx
name|ctx_ep
index|[
name|XHCI_MAX_ENDPOINTS
operator|-
literal|1
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|XHCI_DEV_CTX_ALIGN
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|xhci_stream_ctx
block|{
specifier|volatile
name|uint64_t
name|qwSctx0
decl_stmt|;
define|#
directive|define
name|XHCI_SCTX_0_DCS_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1)
define|#
directive|define
name|XHCI_SCTX_0_DCS_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1)
define|#
directive|define
name|XHCI_SCTX_0_SCT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 1)
define|#
directive|define
name|XHCI_SCTX_0_SCT_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x7)
define|#
directive|define
name|XHCI_SCTX_0_SCT_SEC_TR_RING
value|0x0
define|#
directive|define
name|XHCI_SCTX_0_SCT_PRIM_TR_RING
value|0x1
define|#
directive|define
name|XHCI_SCTX_0_SCT_PRIM_SSA_8
value|0x2
define|#
directive|define
name|XHCI_SCTX_0_SCT_PRIM_SSA_16
value|0x3
define|#
directive|define
name|XHCI_SCTX_0_SCT_PRIM_SSA_32
value|0x4
define|#
directive|define
name|XHCI_SCTX_0_SCT_PRIM_SSA_64
value|0x5
define|#
directive|define
name|XHCI_SCTX_0_SCT_PRIM_SSA_128
value|0x6
define|#
directive|define
name|XHCI_SCTX_0_SCT_PRIM_SSA_256
value|0x7
define|#
directive|define
name|XHCI_SCTX_0_TR_DQ_PTR_MASK
value|0xFFFFFFFFFFFFFFF0U
specifier|volatile
name|uint32_t
name|dwSctx2
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwSctx3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_trb
block|{
specifier|volatile
name|uint64_t
name|qwTrb0
decl_stmt|;
define|#
directive|define
name|XHCI_TRB_0_DIR_IN_MASK
value|(0x80ULL<< 0)
define|#
directive|define
name|XHCI_TRB_0_WLENGTH_MASK
value|(0xFFFFULL<< 48)
specifier|volatile
name|uint32_t
name|dwTrb2
decl_stmt|;
define|#
directive|define
name|XHCI_TRB_2_ERROR_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
define|#
directive|define
name|XHCI_TRB_2_ERROR_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 24)
define|#
directive|define
name|XHCI_TRB_2_TDSZ_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1F)
define|#
directive|define
name|XHCI_TRB_2_TDSZ_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1F)<< 17)
define|#
directive|define
name|XHCI_TRB_2_REM_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFFFF)
define|#
directive|define
name|XHCI_TRB_2_REM_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFFFF)
define|#
directive|define
name|XHCI_TRB_2_BYTES_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1FFFF)
define|#
directive|define
name|XHCI_TRB_2_BYTES_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1FFFF)
define|#
directive|define
name|XHCI_TRB_2_IRQ_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x3FF)
define|#
directive|define
name|XHCI_TRB_2_IRQ_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3FF)<< 22)
define|#
directive|define
name|XHCI_TRB_2_STREAM_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
define|#
directive|define
name|XHCI_TRB_2_STREAM_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
specifier|volatile
name|uint32_t
name|dwTrb3
decl_stmt|;
define|#
directive|define
name|XHCI_TRB_3_TYPE_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x3F)
define|#
directive|define
name|XHCI_TRB_3_TYPE_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 10)
define|#
directive|define
name|XHCI_TRB_3_CYCLE_BIT
value|(1U<< 0)
define|#
directive|define
name|XHCI_TRB_3_TC_BIT
value|(1U<< 1)
comment|/* command ring only */
define|#
directive|define
name|XHCI_TRB_3_ENT_BIT
value|(1U<< 1)
comment|/* transfer ring only */
define|#
directive|define
name|XHCI_TRB_3_ISP_BIT
value|(1U<< 2)
define|#
directive|define
name|XHCI_TRB_3_NSNOOP_BIT
value|(1U<< 3)
define|#
directive|define
name|XHCI_TRB_3_CHAIN_BIT
value|(1U<< 4)
define|#
directive|define
name|XHCI_TRB_3_IOC_BIT
value|(1U<< 5)
define|#
directive|define
name|XHCI_TRB_3_IDT_BIT
value|(1U<< 6)
define|#
directive|define
name|XHCI_TRB_3_TBC_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 3)
define|#
directive|define
name|XHCI_TRB_3_TBC_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< 7)
define|#
directive|define
name|XHCI_TRB_3_BEI_BIT
value|(1U<< 9)
define|#
directive|define
name|XHCI_TRB_3_DCEP_BIT
value|(1U<< 9)
define|#
directive|define
name|XHCI_TRB_3_PRSV_BIT
value|(1U<< 9)
define|#
directive|define
name|XHCI_TRB_3_BSR_BIT
value|(1U<< 9)
define|#
directive|define
name|XHCI_TRB_3_TRT_MASK
value|(3U<< 16)
define|#
directive|define
name|XHCI_TRB_3_TRT_NONE
value|(0U<< 16)
define|#
directive|define
name|XHCI_TRB_3_TRT_OUT
value|(2U<< 16)
define|#
directive|define
name|XHCI_TRB_3_TRT_IN
value|(3U<< 16)
define|#
directive|define
name|XHCI_TRB_3_DIR_IN
value|(1U<< 16)
define|#
directive|define
name|XHCI_TRB_3_TLBPC_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xF)
define|#
directive|define
name|XHCI_TRB_3_TLBPC_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 16)
define|#
directive|define
name|XHCI_TRB_3_EP_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1F)
define|#
directive|define
name|XHCI_TRB_3_EP_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1F)<< 16)
define|#
directive|define
name|XHCI_TRB_3_FRID_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x7FF)
define|#
directive|define
name|XHCI_TRB_3_FRID_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 20)
define|#
directive|define
name|XHCI_TRB_3_ISO_SIA_BIT
value|(1U<< 31)
define|#
directive|define
name|XHCI_TRB_3_SUSP_EP_BIT
value|(1U<< 23)
define|#
directive|define
name|XHCI_TRB_3_SLOT_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
define|#
directive|define
name|XHCI_TRB_3_SLOT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 24)
comment|/* Commands */
define|#
directive|define
name|XHCI_TRB_TYPE_RESERVED
value|0x00
define|#
directive|define
name|XHCI_TRB_TYPE_NORMAL
value|0x01
define|#
directive|define
name|XHCI_TRB_TYPE_SETUP_STAGE
value|0x02
define|#
directive|define
name|XHCI_TRB_TYPE_DATA_STAGE
value|0x03
define|#
directive|define
name|XHCI_TRB_TYPE_STATUS_STAGE
value|0x04
define|#
directive|define
name|XHCI_TRB_TYPE_ISOCH
value|0x05
define|#
directive|define
name|XHCI_TRB_TYPE_LINK
value|0x06
define|#
directive|define
name|XHCI_TRB_TYPE_EVENT_DATA
value|0x07
define|#
directive|define
name|XHCI_TRB_TYPE_NOOP
value|0x08
define|#
directive|define
name|XHCI_TRB_TYPE_ENABLE_SLOT
value|0x09
define|#
directive|define
name|XHCI_TRB_TYPE_DISABLE_SLOT
value|0x0A
define|#
directive|define
name|XHCI_TRB_TYPE_ADDRESS_DEVICE
value|0x0B
define|#
directive|define
name|XHCI_TRB_TYPE_CONFIGURE_EP
value|0x0C
define|#
directive|define
name|XHCI_TRB_TYPE_EVALUATE_CTX
value|0x0D
define|#
directive|define
name|XHCI_TRB_TYPE_RESET_EP
value|0x0E
define|#
directive|define
name|XHCI_TRB_TYPE_STOP_EP
value|0x0F
define|#
directive|define
name|XHCI_TRB_TYPE_SET_TR_DEQUEUE
value|0x10
define|#
directive|define
name|XHCI_TRB_TYPE_RESET_DEVICE
value|0x11
define|#
directive|define
name|XHCI_TRB_TYPE_FORCE_EVENT
value|0x12
define|#
directive|define
name|XHCI_TRB_TYPE_NEGOTIATE_BW
value|0x13
define|#
directive|define
name|XHCI_TRB_TYPE_SET_LATENCY_TOL
value|0x14
define|#
directive|define
name|XHCI_TRB_TYPE_GET_PORT_BW
value|0x15
define|#
directive|define
name|XHCI_TRB_TYPE_FORCE_HEADER
value|0x16
define|#
directive|define
name|XHCI_TRB_TYPE_NOOP_CMD
value|0x17
comment|/* Events */
define|#
directive|define
name|XHCI_TRB_EVENT_TRANSFER
value|0x20
define|#
directive|define
name|XHCI_TRB_EVENT_CMD_COMPLETE
value|0x21
define|#
directive|define
name|XHCI_TRB_EVENT_PORT_STS_CHANGE
value|0x22
define|#
directive|define
name|XHCI_TRB_EVENT_BW_REQUEST
value|0x23
define|#
directive|define
name|XHCI_TRB_EVENT_DOORBELL
value|0x24
define|#
directive|define
name|XHCI_TRB_EVENT_HOST_CTRL
value|0x25
define|#
directive|define
name|XHCI_TRB_EVENT_DEVICE_NOTIFY
value|0x26
define|#
directive|define
name|XHCI_TRB_EVENT_MFINDEX_WRAP
value|0x27
comment|/* Error codes */
define|#
directive|define
name|XHCI_TRB_ERROR_INVALID
value|0x00
define|#
directive|define
name|XHCI_TRB_ERROR_SUCCESS
value|0x01
define|#
directive|define
name|XHCI_TRB_ERROR_DATA_BUF
value|0x02
define|#
directive|define
name|XHCI_TRB_ERROR_BABBLE
value|0x03
define|#
directive|define
name|XHCI_TRB_ERROR_XACT
value|0x04
define|#
directive|define
name|XHCI_TRB_ERROR_TRB
value|0x05
define|#
directive|define
name|XHCI_TRB_ERROR_STALL
value|0x06
define|#
directive|define
name|XHCI_TRB_ERROR_RESOURCE
value|0x07
define|#
directive|define
name|XHCI_TRB_ERROR_BANDWIDTH
value|0x08
define|#
directive|define
name|XHCI_TRB_ERROR_NO_SLOTS
value|0x09
define|#
directive|define
name|XHCI_TRB_ERROR_STREAM_TYPE
value|0x0A
define|#
directive|define
name|XHCI_TRB_ERROR_SLOT_NOT_ON
value|0x0B
define|#
directive|define
name|XHCI_TRB_ERROR_ENDP_NOT_ON
value|0x0C
define|#
directive|define
name|XHCI_TRB_ERROR_SHORT_PKT
value|0x0D
define|#
directive|define
name|XHCI_TRB_ERROR_RING_UNDERRUN
value|0x0E
define|#
directive|define
name|XHCI_TRB_ERROR_RING_OVERRUN
value|0x0F
define|#
directive|define
name|XHCI_TRB_ERROR_VF_RING_FULL
value|0x10
define|#
directive|define
name|XHCI_TRB_ERROR_PARAMETER
value|0x11
define|#
directive|define
name|XHCI_TRB_ERROR_BW_OVERRUN
value|0x12
define|#
directive|define
name|XHCI_TRB_ERROR_CONTEXT_STATE
value|0x13
define|#
directive|define
name|XHCI_TRB_ERROR_NO_PING_RESP
value|0x14
define|#
directive|define
name|XHCI_TRB_ERROR_EV_RING_FULL
value|0x15
define|#
directive|define
name|XHCI_TRB_ERROR_INCOMPAT_DEV
value|0x16
define|#
directive|define
name|XHCI_TRB_ERROR_MISSED_SERVICE
value|0x17
define|#
directive|define
name|XHCI_TRB_ERROR_CMD_RING_STOP
value|0x18
define|#
directive|define
name|XHCI_TRB_ERROR_CMD_ABORTED
value|0x19
define|#
directive|define
name|XHCI_TRB_ERROR_STOPPED
value|0x1A
define|#
directive|define
name|XHCI_TRB_ERROR_LENGTH
value|0x1B
define|#
directive|define
name|XHCI_TRB_ERROR_BAD_MELAT
value|0x1D
define|#
directive|define
name|XHCI_TRB_ERROR_ISOC_OVERRUN
value|0x1F
define|#
directive|define
name|XHCI_TRB_ERROR_EVENT_LOST
value|0x20
define|#
directive|define
name|XHCI_TRB_ERROR_UNDEFINED
value|0x21
define|#
directive|define
name|XHCI_TRB_ERROR_INVALID_SID
value|0x22
define|#
directive|define
name|XHCI_TRB_ERROR_SEC_BW
value|0x23
define|#
directive|define
name|XHCI_TRB_ERROR_SPLIT_XACT
value|0x24
block|}
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|xhci_dev_endpoint_trbs
block|{
name|struct
name|xhci_trb
name|trb
index|[
operator|(
name|XHCI_MAX_STREAMS
operator|*
name|XHCI_MAX_TRANSFERS
operator|)
operator|+
name|XHCI_MAX_STREAMS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XHCI_TD_PAGE_NBUF
value|17
end_define

begin_comment
comment|/* units, room enough for 64Kbytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_TD_PAGE_SIZE
value|4096
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|XHCI_TD_PAYLOAD_MAX
value|(XHCI_TD_PAGE_SIZE * (XHCI_TD_PAGE_NBUF - 1))
end_define

begin_struct
struct|struct
name|xhci_td
block|{
name|struct
name|xhci_trb
name|td_trb
index|[
name|XHCI_TD_PAGE_NBUF
operator|+
literal|1
index|]
decl_stmt|;
comment|/*  * Extra information needed:  */
name|uint64_t
name|td_self
decl_stmt|;
name|struct
name|xhci_td
modifier|*
name|next
decl_stmt|;
name|struct
name|xhci_td
modifier|*
name|alt_next
decl_stmt|;
name|struct
name|xhci_td
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|page_cache
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|remainder
decl_stmt|;
name|uint8_t
name|ntrb
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|XHCI_TRB_ALIGN
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|xhci_command
block|{
name|struct
name|xhci_trb
name|trb
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|xhci_command
argument_list|)
name|entry
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_event_ring_seg
block|{
specifier|volatile
name|uint64_t
name|qwEvrsTablePtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwEvrsTableSize
decl_stmt|;
specifier|volatile
name|uint32_t
name|dwEvrsReserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_hw_root
block|{
name|struct
name|xhci_event_ring_seg
name|hwr_ring_seg
index|[
name|XHCI_MAX_RSEG
index|]
decl_stmt|;
struct|struct
block|{
specifier|volatile
name|uint64_t
name|dummy
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|64
argument_list|)
name|padding
struct|;
name|struct
name|xhci_trb
name|hwr_events
index|[
name|XHCI_MAX_EVENTS
index|]
decl_stmt|;
name|struct
name|xhci_trb
name|hwr_commands
index|[
name|XHCI_MAX_COMMANDS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_endpoint_ext
block|{
name|struct
name|xhci_trb
modifier|*
name|trb
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|xfer
index|[
name|XHCI_MAX_TRANSFERS
operator|*
name|XHCI_MAX_STREAMS
index|]
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|page_cache
decl_stmt|;
name|uint64_t
name|physaddr
decl_stmt|;
name|uint8_t
name|trb_used
index|[
name|XHCI_MAX_STREAMS
index|]
decl_stmt|;
name|uint8_t
name|trb_index
index|[
name|XHCI_MAX_STREAMS
index|]
decl_stmt|;
name|uint8_t
name|trb_halted
decl_stmt|;
name|uint8_t
name|trb_running
decl_stmt|;
name|uint8_t
name|trb_ep_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|XHCI_ST_DISABLED
block|,
name|XHCI_ST_ENABLED
block|,
name|XHCI_ST_DEFAULT
block|,
name|XHCI_ST_ADDRESSED
block|,
name|XHCI_ST_CONFIGURED
block|,
name|XHCI_ST_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|xhci_hw_dev
block|{
name|struct
name|usb_page_cache
name|device_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|input_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|endpoint_pc
index|[
name|XHCI_MAX_ENDPOINTS
index|]
decl_stmt|;
name|struct
name|usb_page
name|device_pg
decl_stmt|;
name|struct
name|usb_page
name|input_pg
decl_stmt|;
name|struct
name|usb_page
name|endpoint_pg
index|[
name|XHCI_MAX_ENDPOINTS
index|]
decl_stmt|;
name|struct
name|xhci_endpoint_ext
name|endp
index|[
name|XHCI_MAX_ENDPOINTS
index|]
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|nports
decl_stmt|;
name|uint8_t
name|tt
decl_stmt|;
name|uint8_t
name|context_num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_hw_softc
block|{
name|struct
name|usb_page_cache
name|root_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|ctx_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|scratch_pc
index|[
name|XHCI_MAX_SCRATCHPADS
index|]
decl_stmt|;
name|struct
name|usb_page
name|root_pg
decl_stmt|;
name|struct
name|usb_page
name|ctx_pg
decl_stmt|;
name|struct
name|usb_page
name|scratch_pg
index|[
name|XHCI_MAX_SCRATCHPADS
index|]
decl_stmt|;
name|struct
name|xhci_hw_dev
name|devs
index|[
name|XHCI_MAX_DEVICES
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xhci_config_desc
block|{
name|struct
name|usb_config_descriptor
name|confd
decl_stmt|;
name|struct
name|usb_interface_descriptor
name|ifcd
decl_stmt|;
name|struct
name|usb_endpoint_descriptor
name|endpd
decl_stmt|;
name|struct
name|usb_endpoint_ss_comp_descriptor
name|endpcd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|xhci_bos_desc
block|{
name|struct
name|usb_bos_descriptor
name|bosd
decl_stmt|;
name|struct
name|usb_devcap_usb2ext_descriptor
name|usb2extd
decl_stmt|;
name|struct
name|usb_devcap_ss_descriptor
name|usbdcd
decl_stmt|;
name|struct
name|usb_devcap_container_id_descriptor
name|cidd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|xhci_hub_desc
block|{
name|struct
name|usb_status
name|stat
decl_stmt|;
name|struct
name|usb_port_status
name|ps
decl_stmt|;
name|struct
name|usb_hub_ss_descriptor
name|hubd
decl_stmt|;
name|uint8_t
name|temp
index|[
literal|128
index|]
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|int
function_decl|(
name|xhci_port_route_t
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|xhci_softc
block|{
name|struct
name|xhci_hw_softc
name|sc_hw
decl_stmt|;
comment|/* base device */
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
comment|/* configure message */
name|struct
name|usb_bus_msg
name|sc_config_msg
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|usb_callout
name|sc_callout
decl_stmt|;
name|xhci_port_route_t
modifier|*
name|sc_port_route
decl_stmt|;
name|union
name|xhci_hub_desc
name|sc_hub_desc
decl_stmt|;
name|struct
name|cv
name|sc_cmd_cv
decl_stmt|;
name|struct
name|sx
name|sc_cmd_sx
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|XHCI_MAX_DEVICES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_io_res
decl_stmt|;
name|int
name|sc_irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|void
modifier|*
name|sc_intr_hdl
decl_stmt|;
name|bus_size_t
name|sc_io_size
decl_stmt|;
name|bus_space_tag_t
name|sc_io_tag
decl_stmt|;
name|bus_space_handle_t
name|sc_io_hdl
decl_stmt|;
comment|/* last pending command address */
name|uint64_t
name|sc_cmd_addr
decl_stmt|;
comment|/* result of command */
name|uint32_t
name|sc_cmd_result
index|[
literal|2
index|]
decl_stmt|;
comment|/* copy of cmd register */
name|uint32_t
name|sc_cmd
decl_stmt|;
comment|/* worst case exit latency */
name|uint32_t
name|sc_exit_lat_max
decl_stmt|;
comment|/* offset to operational registers */
name|uint32_t
name|sc_oper_off
decl_stmt|;
comment|/* offset to capability registers */
name|uint32_t
name|sc_capa_off
decl_stmt|;
comment|/* offset to runtime registers */
name|uint32_t
name|sc_runt_off
decl_stmt|;
comment|/* offset to doorbell registers */
name|uint32_t
name|sc_door_off
decl_stmt|;
comment|/* chip specific */
name|uint16_t
name|sc_erst_max
decl_stmt|;
name|uint16_t
name|sc_event_idx
decl_stmt|;
name|uint16_t
name|sc_command_idx
decl_stmt|;
name|uint16_t
name|sc_imod_default
decl_stmt|;
name|uint8_t
name|sc_event_ccs
decl_stmt|;
name|uint8_t
name|sc_command_ccs
decl_stmt|;
comment|/* number of XHCI device slots */
name|uint8_t
name|sc_noslot
decl_stmt|;
comment|/* number of ports on root HUB */
name|uint8_t
name|sc_noport
decl_stmt|;
comment|/* number of scratch pages */
name|uint8_t
name|sc_noscratch
decl_stmt|;
comment|/* root HUB device configuration */
name|uint8_t
name|sc_conf
decl_stmt|;
comment|/* root HUB port event bitmap, max 256 ports */
name|uint8_t
name|sc_hub_idata
index|[
literal|32
index|]
decl_stmt|;
comment|/* size of context */
name|uint8_t
name|sc_ctx_is_64_byte
decl_stmt|;
comment|/* vendor string for root HUB */
name|char
name|sc_vendor
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XHCI_CMD_LOCK
parameter_list|(
name|sc
parameter_list|)
value|sx_xlock(&(sc)->sc_cmd_sx)
end_define

begin_define
define|#
directive|define
name|XHCI_CMD_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|sx_xunlock(&(sc)->sc_cmd_sx)
end_define

begin_define
define|#
directive|define
name|XHCI_CMD_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|sx_assert(&(sc)->sc_cmd_sx, SA_LOCKED)
end_define

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|uint8_t
name|xhci_use_polling
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|xhci_halt_controller
parameter_list|(
name|struct
name|xhci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|xhci_init
parameter_list|(
name|struct
name|xhci_softc
modifier|*
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|xhci_start_controller
parameter_list|(
name|struct
name|xhci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xhci_interrupt
parameter_list|(
name|struct
name|xhci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xhci_uninit
parameter_list|(
name|struct
name|xhci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XHCI_H_ */
end_comment

end_unit

