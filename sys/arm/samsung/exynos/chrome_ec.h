begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|EC_CMD_HELLO
value|0x01
end_define

begin_define
define|#
directive|define
name|EC_CMD_GET_VERSION
value|0x02
end_define

begin_define
define|#
directive|define
name|EC_CMD_MKBP_STATE
value|0x60
end_define

begin_define
define|#
directive|define
name|EC_CMD_VERSION0
value|0xdc
end_define

begin_define
define|#
directive|define
name|EC_CMD_RESEND_RESPONSE
value|0xdb
end_define

begin_define
define|#
directive|define
name|EC_CMD_GET_COMMS_STATUS
value|0x09
end_define

begin_function_decl
name|int
name|ec_command
parameter_list|(
name|uint8_t
name|cmd
parameter_list|,
name|uint8_t
modifier|*
name|dout
parameter_list|,
name|uint8_t
name|dout_len
parameter_list|,
name|uint8_t
modifier|*
name|dinp
parameter_list|,
name|uint8_t
name|dinp_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ec_hello
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

