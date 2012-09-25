begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMM_INSTRUCTION_EMUL_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMM_INSTRUCTION_EMUL_H_
end_define

begin_enum
enum|enum
name|vie_op_size
block|{
name|VIE_OP_SIZE_32BIT
block|,
comment|/* default */
name|VIE_OP_SIZE_64BIT
block|,
name|VIE_OP_SIZE_8BIT
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|VIE_INST_SIZE
value|15
end_define

begin_struct
struct|struct
name|vie
block|{
name|uint8_t
name|inst
index|[
name|VIE_INST_SIZE
index|]
decl_stmt|;
name|uint8_t
name|rex_w
range|:
literal|1
decl_stmt|,
name|rex_r
range|:
literal|1
decl_stmt|,
name|rex_x
range|:
literal|1
decl_stmt|,
name|rex_b
range|:
literal|1
decl_stmt|;
name|uint8_t
name|mod
range|:
literal|2
decl_stmt|,
name|reg
range|:
literal|4
decl_stmt|,
name|rm
range|:
literal|4
decl_stmt|;
name|uint8_t
name|opcode_byte
decl_stmt|;
name|uint16_t
name|opcode_flags
decl_stmt|;
name|uint8_t
name|disp_bytes
decl_stmt|;
name|uint8_t
name|imm_bytes
decl_stmt|;
name|int
name|num_valid
decl_stmt|;
name|int
name|num_processed
decl_stmt|;
name|enum
name|vm_reg_name
name|base_register
decl_stmt|;
name|enum
name|vm_reg_name
name|index_register
decl_stmt|;
name|enum
name|vm_reg_name
name|operand_register
decl_stmt|;
name|int
name|op_size
decl_stmt|;
name|int64_t
name|displacement
decl_stmt|;
name|int64_t
name|immediate
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIE_F_HAS_MODRM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VIE_F_FROM_RM
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VIE_F_FROM_REG
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|VIE_F_TO_RM
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|VIE_F_TO_REG
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|VIE_F_FROM_IMM
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|VIE_MOD_INDIRECT
value|0
end_define

begin_define
define|#
directive|define
name|VIE_MOD_INDIRECT_DISP8
value|1
end_define

begin_define
define|#
directive|define
name|VIE_MOD_INDIRECT_DISP32
value|2
end_define

begin_define
define|#
directive|define
name|VIE_MOD_DIRECT
value|3
end_define

begin_define
define|#
directive|define
name|VIE_RM_SIB
value|4
end_define

begin_define
define|#
directive|define
name|VIE_RM_DISP32
value|5
end_define

begin_struct_decl
struct_decl|struct
name|vm
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|vmm_fetch_instruction
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|uint64_t
name|rip
parameter_list|,
name|uint64_t
name|cr3
parameter_list|,
name|struct
name|vie
modifier|*
name|vie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmm_decode_instruction
parameter_list|(
name|struct
name|vie
modifier|*
name|vie
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

