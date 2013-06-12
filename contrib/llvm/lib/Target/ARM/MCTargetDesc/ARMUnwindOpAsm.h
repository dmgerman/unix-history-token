begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMUnwindOpAsm.h - ARM Unwind Opcodes Assembler ---------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares the unwind opcode assmebler for ARM exception handling
end_comment

begin_comment
comment|// table.
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
name|ARM_UNWIND_OP_ASM_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_UNWIND_OP_ASM_H
end_define

begin_include
include|#
directive|include
file|"ARMUnwindOp.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbol
decl_stmt|;
name|class
name|UnwindOpcodeAssembler
block|{
name|private
label|:
name|llvm
operator|::
name|SmallVector
operator|<
name|uint8_t
operator|,
literal|8
operator|>
name|Ops
expr_stmt|;
name|unsigned
name|Offset
decl_stmt|;
name|unsigned
name|PersonalityIndex
decl_stmt|;
name|bool
name|HasPersonality
decl_stmt|;
enum|enum
block|{
comment|// The number of bytes to be preserved for the size and personality index
comment|// prefix of unwind opcodes.
name|NUM_PRESERVED_PREFIX_BUF
init|=
literal|2
block|}
enum|;
name|public
label|:
name|UnwindOpcodeAssembler
argument_list|()
operator|:
name|Ops
argument_list|(
name|NUM_PRESERVED_PREFIX_BUF
argument_list|)
operator|,
name|Offset
argument_list|(
name|NUM_PRESERVED_PREFIX_BUF
argument_list|)
operator|,
name|PersonalityIndex
argument_list|(
name|NUM_PERSONALITY_INDEX
argument_list|)
operator|,
name|HasPersonality
argument_list|(
literal|0
argument_list|)
block|{   }
comment|/// Reset the unwind opcode assembler.
name|void
name|Reset
argument_list|()
block|{
name|Ops
operator|.
name|resize
argument_list|(
name|NUM_PRESERVED_PREFIX_BUF
argument_list|)
block|;
name|Offset
operator|=
name|NUM_PRESERVED_PREFIX_BUF
block|;
name|PersonalityIndex
operator|=
name|NUM_PERSONALITY_INDEX
block|;
name|HasPersonality
operator|=
literal|0
block|;   }
comment|/// Get the size of the payload (including the size byte)
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Ops
operator|.
name|size
argument_list|()
operator|-
name|Offset
return|;
block|}
comment|/// Get the beginning of the payload
specifier|const
name|uint8_t
operator|*
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Ops
operator|.
name|begin
argument_list|()
operator|+
name|Offset
return|;
block|}
comment|/// Get the payload
name|StringRef
name|data
argument_list|()
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|begin
argument_list|()
operator|)
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|/// Set the personality index
name|void
name|setPersonality
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Per
parameter_list|)
block|{
name|HasPersonality
operator|=
literal|1
expr_stmt|;
block|}
comment|/// Get the personality index
name|unsigned
name|getPersonalityIndex
argument_list|()
specifier|const
block|{
return|return
name|PersonalityIndex
return|;
block|}
comment|/// Emit unwind opcodes for .save directives
name|void
name|EmitRegSave
parameter_list|(
name|uint32_t
name|RegSave
parameter_list|)
function_decl|;
comment|/// Emit unwind opcodes for .vsave directives
name|void
name|EmitVFPRegSave
parameter_list|(
name|uint32_t
name|VFPRegSave
parameter_list|)
function_decl|;
comment|/// Emit unwind opcodes for .setfp directives
name|void
name|EmitSetFP
parameter_list|(
name|uint16_t
name|FPReg
parameter_list|)
function_decl|;
comment|/// Emit unwind opcodes to update stack pointer
name|void
name|EmitSPOffset
parameter_list|(
name|int64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// Finalize the unwind opcode sequence for EmitBytes()
name|void
name|Finalize
parameter_list|()
function_decl|;
name|private
label|:
comment|/// Get the size of the opcodes in bytes.
name|size_t
name|getOpcodeSize
argument_list|()
specifier|const
block|{
return|return
name|Ops
operator|.
name|size
argument_list|()
operator|-
name|NUM_PRESERVED_PREFIX_BUF
return|;
block|}
comment|/// Add the length prefix to the payload
name|void
name|AddOpcodeSizePrefix
parameter_list|(
name|size_t
name|Pos
parameter_list|)
function_decl|;
comment|/// Add personality index prefix in some compact format
name|void
name|AddPersonalityIndexPrefix
parameter_list|(
name|size_t
name|Pos
parameter_list|,
name|unsigned
name|PersonalityIndex
parameter_list|)
function_decl|;
comment|/// Fill the words with finish opcode if it is not aligned
name|void
name|EmitFinishOpcodes
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ARM_UNWIND_OP_ASM_H
end_comment

end_unit

