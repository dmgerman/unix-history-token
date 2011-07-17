begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PseudoLoweringEmitter.h - PseudoLowering Generator -------*- C++ -*-===//
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
name|PSEUDOLOWERINGEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|PSEUDOLOWERINGEMITTER_H
end_define

begin_include
include|#
directive|include
file|"CodeGenInstruction.h"
end_include

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
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PseudoLoweringEmitter
range|:
name|public
name|TableGenBackend
block|{   struct
name|OpData
block|{     enum
name|MapKind
block|{
name|Operand
block|,
name|Imm
block|,
name|Reg
block|}
block|;
name|MapKind
name|Kind
block|;
expr|union
block|{
name|unsigned
name|Operand
block|;
comment|// Operand number mapped to.
name|uint64_t
name|Imm
block|;
comment|// Integer immedate value.
name|Record
operator|*
name|Reg
block|;
comment|// Physical register.
block|}
name|Data
block|;   }
block|;   struct
name|PseudoExpansion
block|{
name|CodeGenInstruction
name|Source
block|;
comment|// The source pseudo instruction definition.
name|CodeGenInstruction
name|Dest
block|;
comment|// The destination instruction to lower to.
name|IndexedMap
operator|<
name|OpData
operator|>
name|OperandMap
block|;
name|PseudoExpansion
argument_list|(
name|CodeGenInstruction
operator|&
name|s
argument_list|,
name|CodeGenInstruction
operator|&
name|d
argument_list|,
name|IndexedMap
operator|<
name|OpData
operator|>
operator|&
name|m
argument_list|)
operator|:
name|Source
argument_list|(
name|s
argument_list|)
block|,
name|Dest
argument_list|(
name|d
argument_list|)
block|,
name|OperandMap
argument_list|(
argument|m
argument_list|)
block|{}
block|}
block|;
name|RecordKeeper
operator|&
name|Records
block|;
comment|// It's overkill to have an instance of the full CodeGenTarget object,
comment|// but it loads everything on demand, not in the constructor, so it's
comment|// lightweight in performance, so it works out OK.
name|CodeGenTarget
name|Target
block|;
name|SmallVector
operator|<
name|PseudoExpansion
block|,
literal|64
operator|>
name|Expansions
block|;
name|unsigned
name|addDagOperandMapping
argument_list|(
argument|Record *Rec
argument_list|,
argument|DagInit *Dag
argument_list|,
argument|CodeGenInstruction&Insn
argument_list|,
argument|IndexedMap<OpData>&OperandMap
argument_list|,
argument|unsigned BaseIdx
argument_list|)
block|;
name|void
name|evaluateExpansion
argument_list|(
name|Record
operator|*
name|Pseudo
argument_list|)
block|;
name|void
name|emitLoweringEmitter
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|;
name|public
operator|:
name|PseudoLoweringEmitter
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
argument|R
argument_list|)
block|{}
comment|/// run - Output the pseudo-lowerings.
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
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

