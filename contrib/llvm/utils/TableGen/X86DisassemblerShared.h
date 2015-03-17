begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86DisassemblerShared.h - Emitter shared header ----------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_UTILS_TABLEGEN_X86DISASSEMBLERSHARED_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_X86DISASSEMBLERSHARED_H
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"../../lib/Target/X86/Disassembler/X86DisassemblerDecoderCommon.h"
end_include

begin_struct
struct|struct
name|InstructionSpecifier
block|{
name|llvm
operator|::
name|X86Disassembler
operator|::
name|OperandSpecifier
name|operands
index|[
name|llvm
operator|::
name|X86Disassembler
operator|::
name|X86_MAX_OPERANDS
index|]
expr_stmt|;
name|llvm
operator|::
name|X86Disassembler
operator|::
name|InstructionContext
name|insnContext
expr_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
name|InstructionSpecifier
argument_list|()
block|{
name|insnContext
operator|=
name|llvm
operator|::
name|X86Disassembler
operator|::
name|IC
expr_stmt|;
name|name
operator|=
literal|""
expr_stmt|;
name|memset
argument_list|(
name|operands
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|operands
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// Specifies whether a ModR/M byte is needed and (if so) which
end_comment

begin_comment
comment|/// instruction each possible value of the ModR/M byte corresponds to. Once
end_comment

begin_comment
comment|/// this information is known, we have narrowed down to a single instruction.
end_comment

begin_struct
struct|struct
name|ModRMDecision
block|{
name|uint8_t
name|modrm_type
decl_stmt|;
name|llvm
operator|::
name|X86Disassembler
operator|::
name|InstrUID
name|instructionIDs
index|[
literal|256
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Specifies which set of ModR/M->instruction tables to look at
end_comment

begin_comment
comment|/// given a particular opcode.
end_comment

begin_struct
struct|struct
name|OpcodeDecision
block|{
name|ModRMDecision
name|modRMDecisions
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Specifies which opcode->instruction tables to look at given
end_comment

begin_comment
comment|/// a particular context (set of attributes).  Since there are many possible
end_comment

begin_comment
comment|/// contexts, the decoder first uses CONTEXTS_SYM to determine which context
end_comment

begin_comment
comment|/// applies given a specific set of attributes.  Hence there are only IC_max
end_comment

begin_comment
comment|/// entries in this table, rather than 2^(ATTR_max).
end_comment

begin_struct
struct|struct
name|ContextDecision
block|{
name|OpcodeDecision
name|opcodeDecisions
index|[
name|llvm
operator|::
name|X86Disassembler
operator|::
name|IC_max
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

