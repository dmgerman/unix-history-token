begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Instruction formats for the sequencer program downloaded to  * Aic7xxx SCSI host adapters  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $Id: sequencer.h,v 1.1 1997/03/16 07:08:18 gibbs Exp $  */
end_comment

begin_struct
struct|struct
name|ins_format1
block|{
name|u_int8_t
name|immediate
decl_stmt|;
name|u_int8_t
name|source
decl_stmt|;
name|u_int8_t
name|destination
decl_stmt|;
name|u_int8_t
name|opcode_ret
decl_stmt|;
define|#
directive|define
name|DOWNLOAD_CONST_IMMEDIATE
value|0x80
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ins_format2
block|{
name|u_int8_t
name|shift_control
decl_stmt|;
name|u_int8_t
name|source
decl_stmt|;
name|u_int8_t
name|destination
decl_stmt|;
name|u_int8_t
name|opcode_ret
decl_stmt|;
define|#
directive|define
name|RETURN_BIT
value|0x01
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ins_format3
block|{
name|u_int8_t
name|immediate
decl_stmt|;
name|u_int8_t
name|source
decl_stmt|;
name|u_int8_t
name|address
decl_stmt|;
name|u_int8_t
name|opcode_addr
decl_stmt|;
define|#
directive|define
name|ADDR_HIGH_BIT
value|0x01
block|}
struct|;
end_struct

begin_struct
struct|struct
name|instruction
block|{
union|union
block|{
name|struct
name|ins_format1
name|format1
decl_stmt|;
name|struct
name|ins_format2
name|format2
decl_stmt|;
name|struct
name|ins_format3
name|format3
decl_stmt|;
name|u_int8_t
name|bytes
index|[
literal|4
index|]
decl_stmt|;
block|}
name|format
union|;
name|u_int
name|srcline
decl_stmt|;
name|struct
name|symbol
modifier|*
name|patch_label
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|instruction
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AIC_OP_OR
value|0x0
end_define

begin_define
define|#
directive|define
name|AIC_OP_AND
value|0x1
end_define

begin_define
define|#
directive|define
name|AIC_OP_XOR
value|0x2
end_define

begin_define
define|#
directive|define
name|AIC_OP_ADD
value|0x3
end_define

begin_define
define|#
directive|define
name|AIC_OP_ADC
value|0x4
end_define

begin_define
define|#
directive|define
name|AIC_OP_ROL
value|0x5
end_define

begin_define
define|#
directive|define
name|AIC_OP_JMP
value|0x8
end_define

begin_define
define|#
directive|define
name|AIC_OP_JC
value|0x9
end_define

begin_define
define|#
directive|define
name|AIC_OP_JNC
value|0xa
end_define

begin_define
define|#
directive|define
name|AIC_OP_CALL
value|0xb
end_define

begin_define
define|#
directive|define
name|AIC_OP_JNE
value|0xc
end_define

begin_define
define|#
directive|define
name|AIC_OP_JNZ
value|0xd
end_define

begin_define
define|#
directive|define
name|AIC_OP_JE
value|0xe
end_define

begin_define
define|#
directive|define
name|AIC_OP_JZ
value|0xf
end_define

begin_comment
comment|/* Pseudo Ops */
end_comment

begin_define
define|#
directive|define
name|AIC_OP_SHL
value|0x10
end_define

begin_define
define|#
directive|define
name|AIC_OP_SHR
value|0x20
end_define

begin_define
define|#
directive|define
name|AIC_OP_ROR
value|0x30
end_define

end_unit

