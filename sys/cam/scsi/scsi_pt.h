begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structure and function declarations for Processor type devices.  *  * Copyright (c) 1998 Justin T. Gibbs  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_SCSI_PT_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_SCSI_PT_H
value|1
end_define

begin_struct
struct|struct
name|scsi_send_receive
block|{
name|u_int8_t
name|opcode
decl_stmt|;
name|u_int8_t
name|byte2
decl_stmt|;
name|u_int8_t
name|xfer_len
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Opcodes  */
end_comment

begin_define
define|#
directive|define
name|RECEIVE
value|0x08
end_define

begin_define
define|#
directive|define
name|SEND
value|0x0A
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_SCSI_PT_H */
end_comment

end_unit

