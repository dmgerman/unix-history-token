begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ppb_1284.h,v 1.2 1998/08/03 19:14:31 msmith Exp $  *  */
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
value|0
end_define

begin_define
define|#
directive|define
name|NIBBLE_1284_REQUEST_ID
value|4
end_define

begin_comment
comment|/* how to terminate */
end_comment

begin_define
define|#
directive|define
name|VALID_STATE
value|0
end_define

begin_define
define|#
directive|define
name|IMMEDIATE
value|1
end_define

begin_function_decl
specifier|extern
name|int
name|do_1284_wait
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|,
name|char
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nibble_1284_inbyte
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nibble_1284_sync
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nibble_1284_mode
parameter_list|(
name|struct
name|ppb_device
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppb_1284_negociate
parameter_list|(
name|struct
name|ppb_device
modifier|*
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
name|struct
name|ppb_device
modifier|*
parameter_list|,
name|int
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

