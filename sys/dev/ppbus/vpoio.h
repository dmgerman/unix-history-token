begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__VP0IO_H
end_ifndef

begin_define
define|#
directive|define
name|__VP0IO_H
end_define

begin_comment
comment|/*  * The ZIP drive cannot act as an initiator.  */
end_comment

begin_define
define|#
directive|define
name|VP0_INITIATOR
value|0x7
end_define

begin_define
define|#
directive|define
name|VP0_ESELECT_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|VP0_ECMD_TIMEOUT
value|2
end_define

begin_define
define|#
directive|define
name|VP0_ECONNECT
value|3
end_define

begin_define
define|#
directive|define
name|VP0_ESTATUS_TIMEOUT
value|4
end_define

begin_define
define|#
directive|define
name|VP0_EDATA_OVERFLOW
value|5
end_define

begin_define
define|#
directive|define
name|VP0_EDISCONNECT
value|6
end_define

begin_define
define|#
directive|define
name|VP0_EPPDATA_TIMEOUT
value|7
end_define

begin_define
define|#
directive|define
name|VP0_ENEGOCIATE
value|8
end_define

begin_define
define|#
directive|define
name|VP0_ENOPORT
value|9
end_define

begin_define
define|#
directive|define
name|VP0_EINITFAILED
value|10
end_define

begin_define
define|#
directive|define
name|VP0_EINTR
value|12
end_define

begin_define
define|#
directive|define
name|VP0_EOTHER
value|13
end_define

begin_define
define|#
directive|define
name|VP0_OPENNINGS
value|1
end_define

begin_comment
comment|/*  * Data structure used during microsequence execution  * when characters are received in nibble mode  */
end_comment

begin_struct
struct|struct
name|vpo_nibble
block|{
name|char
name|h
decl_stmt|;
comment|/* most significant nibble */
name|char
name|l
decl_stmt|;
comment|/* less significant nibble */
block|}
struct|;
end_struct

begin_comment
comment|/* Mode found during initialisation */
end_comment

begin_define
define|#
directive|define
name|VP0_MODE_UNDEFINED
value|0x0
end_define

begin_define
define|#
directive|define
name|VP0_MODE_NIBBLE
value|0x1
end_define

begin_define
define|#
directive|define
name|VP0_MODE_PS2
value|0x2
end_define

begin_define
define|#
directive|define
name|VP0_MODE_EPP
value|0x3
end_define

begin_struct
struct|struct
name|vpoio_data
block|{
name|unsigned
name|short
name|int
name|vpo_unit
decl_stmt|;
name|int
name|vpo_mode_found
decl_stmt|;
comment|/* Mode found during init */
name|struct
name|vpo_nibble
name|vpo_nibble
decl_stmt|;
comment|/* each device must have its own nibble inbyte microsequence */
name|struct
name|ppb_microseq
modifier|*
name|vpo_nibble_inbyte_msq
decl_stmt|;
name|device_t
name|vpo_dev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|vpoio_set_unit
parameter_list|(
name|vpo
parameter_list|,
name|unit
parameter_list|)
value|((vpo)->vpo_unit = unit)
end_define

begin_function_decl
name|int
name|vpoio_probe
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|vpoio_data
modifier|*
name|vpo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vpoio_attach
parameter_list|(
name|struct
name|vpoio_data
modifier|*
name|vpo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vpoio_reset_bus
parameter_list|(
name|struct
name|vpoio_data
modifier|*
name|vpo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vpoio_do_scsi
parameter_list|(
name|struct
name|vpoio_data
modifier|*
name|vpo
parameter_list|,
name|int
name|host
parameter_list|,
name|int
name|target
parameter_list|,
name|char
modifier|*
name|command
parameter_list|,
name|int
name|clen
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|blen
parameter_list|,
name|int
modifier|*
name|result
parameter_list|,
name|int
modifier|*
name|count
parameter_list|,
name|int
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|imm_probe
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|vpoio_data
modifier|*
name|vpo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|imm_attach
parameter_list|(
name|struct
name|vpoio_data
modifier|*
name|vpo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|imm_reset_bus
parameter_list|(
name|struct
name|vpoio_data
modifier|*
name|vpo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|imm_do_scsi
parameter_list|(
name|struct
name|vpoio_data
modifier|*
name|vpo
parameter_list|,
name|int
name|host
parameter_list|,
name|int
name|target
parameter_list|,
name|char
modifier|*
name|command
parameter_list|,
name|int
name|clen
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|blen
parameter_list|,
name|int
modifier|*
name|result
parameter_list|,
name|int
modifier|*
name|count
parameter_list|,
name|int
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

