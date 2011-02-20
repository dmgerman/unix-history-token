begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------ FixedLenDecoderEmitter.h - Decoder Generator --*- C++ -*-===//
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
comment|// It contains the tablegen backend that emits the decoder functions for
end_comment

begin_comment
comment|// targets with fixed length instruction set.
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
name|FixedLenDECODEREMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|FixedLenDECODEREMITTER_H
end_define

begin_include
include|#
directive|include
file|"CodeGenTarget.h"
end_include

begin_include
include|#
directive|include
file|"TableGenBackend.h"
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
struct|struct
name|OperandInfo
block|{
name|unsigned
name|FieldBase
decl_stmt|;
name|unsigned
name|FieldLength
decl_stmt|;
name|std
operator|::
name|string
name|Decoder
expr_stmt|;
name|OperandInfo
argument_list|(
argument|unsigned FB
argument_list|,
argument|unsigned FL
argument_list|,
argument|std::string D
argument_list|)
block|:
name|FieldBase
argument_list|(
name|FB
argument_list|)
operator|,
name|FieldLength
argument_list|(
name|FL
argument_list|)
operator|,
name|Decoder
argument_list|(
argument|D
argument_list|)
block|{ }
block|}
struct|;
name|class
name|FixedLenDecoderEmitter
range|:
name|public
name|TableGenBackend
block|{
name|public
operator|:
name|FixedLenDecoderEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
operator|:
name|Records
argument_list|(
name|R
argument_list|)
block|,
name|Target
argument_list|(
name|R
argument_list|)
block|,
name|NumberedInstructions
argument_list|(
argument|Target.getInstructionsByEnumValue()
argument_list|)
block|{}
comment|// run - Output the code emitter
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|;
name|private
operator|:
name|RecordKeeper
operator|&
name|Records
block|;
name|CodeGenTarget
name|Target
block|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|CodeGenInstruction
operator|*
operator|>
name|NumberedInstructions
block|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|Opcodes
block|;
name|std
operator|::
name|map
operator|<
name|unsigned
block|,
name|std
operator|::
name|vector
operator|<
name|OperandInfo
operator|>
expr|>
name|Operands
block|;
name|bool
name|populateInstruction
argument_list|(
argument|const CodeGenInstruction&CGI
argument_list|,
argument|unsigned Opc
argument_list|)
block|;
name|void
name|populateInstructions
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

