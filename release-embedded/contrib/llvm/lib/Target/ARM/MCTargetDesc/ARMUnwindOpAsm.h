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
literal|32
operator|>
name|Ops
expr_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|unsigned
operator|,
literal|8
operator|>
name|OpBegins
expr_stmt|;
name|bool
name|HasPersonality
decl_stmt|;
name|public
label|:
name|UnwindOpcodeAssembler
argument_list|()
operator|:
name|HasPersonality
argument_list|(
literal|0
argument_list|)
block|{
name|OpBegins
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
block|;   }
comment|/// Reset the unwind opcode assembler.
name|void
name|Reset
argument_list|()
block|{
name|Ops
operator|.
name|clear
argument_list|()
block|;
name|OpBegins
operator|.
name|clear
argument_list|()
block|;
name|OpBegins
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
block|;
name|HasPersonality
operator|=
literal|0
block|;   }
comment|/// Set the personality index
name|void
name|setPersonality
argument_list|(
argument|const MCSymbol *Per
argument_list|)
block|{
name|HasPersonality
operator|=
literal|1
block|;   }
comment|/// Emit unwind opcodes for .save directives
name|void
name|EmitRegSave
argument_list|(
argument|uint32_t RegSave
argument_list|)
expr_stmt|;
comment|/// Emit unwind opcodes for .vsave directives
name|void
name|EmitVFPRegSave
parameter_list|(
name|uint32_t
name|VFPRegSave
parameter_list|)
function_decl|;
comment|/// Emit unwind opcodes to copy address from source register to $sp.
name|void
name|EmitSetSP
parameter_list|(
name|uint16_t
name|Reg
parameter_list|)
function_decl|;
comment|/// Emit unwind opcodes to add $sp with an offset.
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
argument_list|(
name|unsigned
operator|&
name|PersonalityIndex
argument_list|,
name|SmallVectorImpl
operator|<
name|uint8_t
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|EmitInt8
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
name|Ops
operator|.
name|push_back
argument_list|(
name|Opcode
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|OpBegins
operator|.
name|push_back
argument_list|(
name|OpBegins
operator|.
name|back
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
name|void
name|EmitInt16
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
name|Ops
operator|.
name|push_back
argument_list|(
operator|(
name|Opcode
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Opcode
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|OpBegins
operator|.
name|push_back
argument_list|(
name|OpBegins
operator|.
name|back
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
block|}
name|void
name|EmitBytes
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Opcode
parameter_list|,
name|size_t
name|Size
parameter_list|)
block|{
name|Ops
operator|.
name|insert
argument_list|(
name|Ops
operator|.
name|end
argument_list|()
argument_list|,
name|Opcode
argument_list|,
name|Opcode
operator|+
name|Size
argument_list|)
expr_stmt|;
name|OpBegins
operator|.
name|push_back
argument_list|(
name|OpBegins
operator|.
name|back
argument_list|()
operator|+
name|Size
argument_list|)
expr_stmt|;
block|}
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

