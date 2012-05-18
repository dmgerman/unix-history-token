begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DFAPacketizerEmitter.h - Packetization DFA for a VLIW machine-------===//
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
comment|// This class parses the Schedule.td file and produces an API that can be used
end_comment

begin_comment
comment|// to reason about whether an instruction can be added to a packet on a VLIW
end_comment

begin_comment
comment|// architecture. The class internally generates a deterministic finite
end_comment

begin_comment
comment|// automaton (DFA) that models all possible mappings of machine instructions
end_comment

begin_comment
comment|// to functional units as instructions are added to a packet.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/TableGen/TableGenBackend.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//
comment|// class DFAGen: class that generates and prints out the DFA for resource
comment|// tracking.
comment|//
name|class
name|DFAGen
range|:
name|public
name|TableGenBackend
block|{
name|private
operator|:
name|std
operator|::
name|string
name|TargetName
block|;
comment|//
comment|// allInsnClasses is the set of all possible resources consumed by an
comment|// InstrStage.
comment|//
name|DenseSet
operator|<
name|unsigned
operator|>
name|allInsnClasses
block|;
name|RecordKeeper
operator|&
name|Records
block|;
name|public
operator|:
name|DFAGen
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
block|;
comment|//
comment|// collectAllInsnClasses: Populate allInsnClasses which is a set of units
comment|// used in each stage.
comment|//
name|void
name|collectAllInsnClasses
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|Record
operator|*
name|ItinData
argument_list|,
name|unsigned
operator|&
name|NStages
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

end_unit

