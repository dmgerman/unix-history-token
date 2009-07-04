begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DAGISelEmitter.h - Generate an instruction selector ------*- C++ -*-===//
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
comment|// This tablegen backend emits a DAG instruction selector.
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
name|DAGISEL_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|DAGISEL_EMITTER_H
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
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// DAGISelEmitter - The top-level class which coordinates construction
comment|/// and emission of the instruction selector.
comment|///
name|class
name|DAGISelEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|CodeGenDAGPatterns
name|CGP
block|;
name|public
operator|:
name|explicit
name|DAGISelEmitter
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
name|CGP
argument_list|(
argument|R
argument_list|)
block|{}
comment|// run - Output the isel, returning true on failure.
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
name|void
name|EmitNodeTransforms
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|EmitPredicateFunctions
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|GenerateCodeForPattern
argument_list|(
specifier|const
name|PatternToMatch
operator|&
name|Pattern
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|std
operator|::
name|string
operator|>
expr|>
operator|&
name|GeneratedCode
argument_list|,
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|GeneratedDecl
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|TargetOpcodes
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|TargetVTs
argument_list|,
name|bool
operator|&
name|OutputIsVariadic
argument_list|,
name|unsigned
operator|&
name|NumInputRootOps
argument_list|)
block|;
name|void
name|EmitPatterns
argument_list|(
argument|std::vector<std::pair<const PatternToMatch*
argument_list|,
argument|std::vector<std::pair<unsigned
argument_list|,
argument|std::string>>>>&Patterns
argument_list|,
argument|unsigned Indent
argument_list|,
argument|raw_ostream&OS
argument_list|)
block|;
name|void
name|EmitInstructionSelector
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

