begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/LoopDependenceAnalysis.h --------------- -*- C++ -*---===//
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
comment|// LoopDependenceAnalysis is an LLVM pass that analyses dependences in memory
end_comment

begin_comment
comment|// accesses in loops.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Please note that this is work in progress and the interface is subject to
end_comment

begin_comment
comment|// change.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TODO: adapt as interface progresses
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
name|LLVM_ANALYSIS_LOOP_DEPENDENCE_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOP_DEPENDENCE_ANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|LoopDependenceAnalysis
range|:
name|public
name|LoopPass
block|{
name|Loop
operator|*
name|L
block|;
name|AliasAnalysis
operator|*
name|AA
block|;
name|ScalarEvolution
operator|*
name|SE
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Class identification, replacement for typeinfo
name|LoopDependenceAnalysis
argument_list|()
operator|:
name|LoopPass
argument_list|(
argument|&ID
argument_list|)
block|{}
comment|/// TODO: docs
name|bool
name|isDependencePair
argument_list|(
argument|const Value*
argument_list|,
argument|const Value*
argument_list|)
specifier|const
block|;
name|bool
name|depends
argument_list|(
name|Value
operator|*
argument_list|,
name|Value
operator|*
argument_list|)
block|;
name|bool
name|runOnLoop
argument_list|(
name|Loop
operator|*
argument_list|,
name|LPPassManager
operator|&
argument_list|)
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&
argument_list|)
specifier|const
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&
argument_list|,
argument|const Module* =
literal|0
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|print
argument_list|(
argument|std::ostream&
argument_list|,
argument|const Module* =
literal|0
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|// class LoopDependenceAnalysis
comment|// createLoopDependenceAnalysisPass - This creates an instance of the
comment|// LoopDependenceAnalysis pass.
comment|//
name|LoopPass
modifier|*
name|createLoopDependenceAnalysisPass
parameter_list|()
function_decl|;
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
comment|/* LLVM_ANALYSIS_LOOP_DEPENDENCE_ANALYSIS_H */
end_comment

end_unit

