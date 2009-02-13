begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__1284_H
end_ifndef

begin_define
define|#
directive|define
name|__1284_H
end_define

begin_comment
comment|/*  * IEEE1284 signals  */
end_comment

begin_comment
comment|/* host driven signals */
end_comment

begin_define
define|#
directive|define
name|nHostClk
value|STROBE
end_define

begin_define
define|#
directive|define
name|Write
value|STROBE
end_define

begin_define
define|#
directive|define
name|nHostBusy
value|AUTOFEED
end_define

begin_define
define|#
directive|define
name|nHostAck
value|AUTOFEED
end_define

begin_define
define|#
directive|define
name|DStrb
value|AUTOFEED
end_define

begin_define
define|#
directive|define
name|nReveseRequest
value|nINIT
end_define

begin_define
define|#
directive|define
name|nActive1284
value|SELECTIN
end_define

begin_define
define|#
directive|define
name|AStrb
value|SELECTIN
end_define

begin_comment
comment|/* peripheral driven signals */
end_comment

begin_define
define|#
directive|define
name|nDataAvail
value|nFAULT
end_define

begin_define
define|#
directive|define
name|nPeriphRequest
value|nFAULT
end_define

begin_define
define|#
directive|define
name|Xflag
value|SELECT
end_define

begin_define
define|#
directive|define
name|AckDataReq
value|PERROR
end_define

begin_define
define|#
directive|define
name|nAckReverse
value|PERROR
end_define

begin_define
define|#
directive|define
name|nPtrBusy
value|nBUSY
end_define

begin_define
define|#
directive|define
name|nPeriphAck
value|nBUSY
end_define

begin_define
define|#
directive|define
name|Wait
value|nBUSY
end_define

begin_define
define|#
directive|define
name|PtrClk
value|nACK
end_define

begin_define
define|#
directive|define
name|PeriphClk
value|nACK
end_define

begin_define
define|#
directive|define
name|Intr
value|nACK
end_define

begin_comment
comment|/* request mode values */
end_comment

begin_define
define|#
directive|define
name|NIBBLE_1284_NORMAL
value|0x0
end_define

begin_define
define|#
directive|define
name|NIBBLE_1284_REQUEST_ID
value|0x4
end_define

begin_define
define|#
directive|define
name|BYTE_1284_NORMAL
value|0x1
end_define

begin_define
define|#
directive|define
name|BYTE_1284_REQUEST_ID
value|0x5
end_define

begin_define
define|#
directive|define
name|ECP_1284_NORMAL
value|0x10
end_define

begin_define
define|#
directive|define
name|ECP_1284_REQUEST_ID
value|0x14
end_define

begin_define
define|#
directive|define
name|ECP_1284_RLE
value|0x30
end_define

begin_define
define|#
directive|define
name|ECP_1284_RLE_REQUEST_ID
value|0x34
end_define

begin_define
define|#
directive|define
name|EPP_1284_NORMAL
value|0x40
end_define

begin_define
define|#
directive|define
name|EXT_LINK_1284_NORMAL
value|0x80
end_define

begin_comment
comment|/* ieee1284 mode options */
end_comment

begin_define
define|#
directive|define
name|PPB_REQUEST_ID
value|0x1
end_define

begin_define
define|#
directive|define
name|PPB_USE_RLE
value|0x2
end_define

begin_define
define|#
directive|define
name|PPB_EXTENSIBILITY_LINK
value|0x4
end_define

begin_comment
comment|/* ieee1284 errors */
end_comment

begin_define
define|#
directive|define
name|PPB_NO_ERROR
value|0
end_define

begin_define
define|#
directive|define
name|PPB_MODE_UNSUPPORTED
value|1
end_define

begin_comment
comment|/* mode not supported by peripheral */
end_comment

begin_define
define|#
directive|define
name|PPB_NOT_IEEE1284
value|2
end_define

begin_comment
comment|/* not an IEEE1284 compliant periph. */
end_comment

begin_define
define|#
directive|define
name|PPB_TIMEOUT
value|3
end_define

begin_comment
comment|/* timeout */
end_comment

begin_define
define|#
directive|define
name|PPB_INVALID_MODE
value|4
end_define

begin_comment
comment|/* current mode is incorrect */
end_comment

begin_comment
comment|/* ieee1284 host side states */
end_comment

begin_define
define|#
directive|define
name|PPB_ERROR
value|0
end_define

begin_define
define|#
directive|define
name|PPB_FORWARD_IDLE
value|1
end_define

begin_define
define|#
directive|define
name|PPB_NEGOCIATION
value|2
end_define

begin_define
define|#
directive|define
name|PPB_SETUP
value|3
end_define

begin_define
define|#
directive|define
name|PPB_ECP_FORWARD_IDLE
value|4
end_define

begin_define
define|#
directive|define
name|PPB_FWD_TO_REVERSE
value|5
end_define

begin_define
define|#
directive|define
name|PPB_REVERSE_IDLE
value|6
end_define

begin_define
define|#
directive|define
name|PPB_REVERSE_TRANSFER
value|7
end_define

begin_define
define|#
directive|define
name|PPB_REVERSE_TO_FWD
value|8
end_define

begin_define
define|#
directive|define
name|PPB_EPP_IDLE
value|9
end_define

begin_define
define|#
directive|define
name|PPB_TERMINATION
value|10
end_define

begin_comment
comment|/* peripheral side states */
end_comment

begin_define
define|#
directive|define
name|PPB_PERIPHERAL_NEGOCIATION
value|11
end_define

begin_define
define|#
directive|define
name|PPB_PERIPHERAL_IDLE
value|12
end_define

begin_define
define|#
directive|define
name|PPB_PERIPHERAL_TRANSFER
value|13
end_define

begin_define
define|#
directive|define
name|PPB_PERIPHERAL_TERMINATION
value|14
end_define

begin_function_decl
specifier|extern
name|int
name|nibble_1284_inbyte
parameter_list|(
name|device_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|byte_1284_inbyte
parameter_list|(
name|device_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|spp_1284_read
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_1284_negociate
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_1284_terminate
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_1284_read_id
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_1284_read
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_1284_get_state
parameter_list|(
name|device_t
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_1284_set_state
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_peripheral_terminate
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_peripheral_negociate
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|byte_peripheral_write
parameter_list|(
name|device_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

