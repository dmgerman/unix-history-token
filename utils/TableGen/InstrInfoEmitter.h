begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstrInfoEmitter.h - Generate a Instruction Set Desc. ----*- C++ -*-===//
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
comment|// This tablegen backend is responsible for emitting a description of the target
end_comment

begin_comment
comment|// instruction set for the code generator.
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
name|INSTRINFO_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|INSTRINFO_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenDAGPatterns.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringInit
decl_stmt|;
name|class
name|IntInit
decl_stmt|;
name|class
name|ListInit
decl_stmt|;
name|class
name|CodeGenInstruction
decl_stmt|;
name|class
name|InstrInfoEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|CodeGenDAGPatterns
name|CDP
block|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|unsigned
operator|>
name|ItinClassMap
block|;
name|public
operator|:
name|InstrInfoEmitter
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
name|CDP
argument_list|(
argument|R
argument_list|)
block|{ }
comment|// run - Output the instruction set description, returning true on failure.
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|,
name|unsigned
operator|>
name|OperandInfoMapTy
expr_stmt|;
name|void
name|emitRecord
argument_list|(
argument|const CodeGenInstruction&Inst
argument_list|,
argument|unsigned Num
argument_list|,
argument|Record *InstrInfo
argument_list|,
argument|std::map<std::vector<Record*>
argument_list|,
argument|unsigned>&EL
argument_list|,
argument|std::map<Record*
argument_list|,
argument|unsigned>&BM
argument_list|,
argument|const OperandInfoMapTy&OpInfo
argument_list|,
argument|raw_ostream&OS
argument_list|)
decl_stmt|;
comment|// Itinerary information.
name|void
name|GatherItinClasses
parameter_list|()
function_decl|;
name|unsigned
name|getItinClassNumber
parameter_list|(
specifier|const
name|Record
modifier|*
name|InstRec
parameter_list|)
function_decl|;
comment|// Operand information.
name|void
name|EmitOperandInfo
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|OperandInfoMapTy
modifier|&
name|OperandInfoIDs
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|GetOperandInfo
argument_list|(
specifier|const
name|CodeGenInstruction
operator|&
name|Inst
argument_list|)
expr_stmt|;
name|void
name|DetectRegisterClassBarriers
argument_list|(
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
operator|&
name|Defs
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|CodeGenRegisterClass
operator|>
operator|&
name|RCs
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
operator|&
name|Barriers
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

