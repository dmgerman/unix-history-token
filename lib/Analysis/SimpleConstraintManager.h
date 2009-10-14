begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== SimpleConstraintManager.h ----------------------------------*- C++ -*--==//
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
comment|//  Code shared between BasicConstraintManager and RangeConstraintManager.
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
name|LLVM_CLANG_ANALYSIS_SIMPLE_CONSTRAINT_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_SIMPLE_CONSTRAINT_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/ConstraintManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRState.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SimpleConstraintManager
range|:
name|public
name|ConstraintManager
block|{
name|public
operator|:
name|SimpleConstraintManager
argument_list|()
block|{}
name|virtual
operator|~
name|SimpleConstraintManager
argument_list|()
block|;
comment|//===------------------------------------------------------------------===//
comment|// Common implementation for the interface provided by ConstraintManager.
comment|//===------------------------------------------------------------------===//
name|bool
name|canReasonAbout
argument_list|(
argument|SVal X
argument_list|)
specifier|const
block|;
specifier|const
name|GRState
operator|*
name|Assume
argument_list|(
argument|const GRState *state
argument_list|,
argument|DefinedSVal Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|;
specifier|const
name|GRState
operator|*
name|Assume
argument_list|(
argument|const GRState *state
argument_list|,
argument|Loc Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|;
specifier|const
name|GRState
operator|*
name|Assume
argument_list|(
argument|const GRState *state
argument_list|,
argument|NonLoc Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|;
specifier|const
name|GRState
operator|*
name|AssumeSymInt
argument_list|(
argument|const GRState *state
argument_list|,
argument|bool Assumption
argument_list|,
argument|const SymIntExpr *SE
argument_list|)
block|;
specifier|const
name|GRState
operator|*
name|AssumeInBound
argument_list|(
argument|const GRState *state
argument_list|,
argument|DefinedSVal Idx
argument_list|,
argument|DefinedSVal UpperBound
argument_list|,
argument|bool Assumption
argument_list|)
block|;
name|protected
operator|:
comment|//===------------------------------------------------------------------===//
comment|// Interface that subclasses must implement.
comment|//===------------------------------------------------------------------===//
name|virtual
specifier|const
name|GRState
operator|*
name|AssumeSymNE
argument_list|(
argument|const GRState *state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|)
operator|=
literal|0
block|;
name|virtual
specifier|const
name|GRState
operator|*
name|AssumeSymEQ
argument_list|(
argument|const GRState *state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|)
operator|=
literal|0
block|;
name|virtual
specifier|const
name|GRState
operator|*
name|AssumeSymLT
argument_list|(
argument|const GRState *state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|)
operator|=
literal|0
block|;
name|virtual
specifier|const
name|GRState
operator|*
name|AssumeSymGT
argument_list|(
argument|const GRState *state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|)
operator|=
literal|0
block|;
name|virtual
specifier|const
name|GRState
operator|*
name|AssumeSymLE
argument_list|(
argument|const GRState *state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|)
operator|=
literal|0
block|;
name|virtual
specifier|const
name|GRState
operator|*
name|AssumeSymGE
argument_list|(
argument|const GRState *state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|)
operator|=
literal|0
block|;
comment|//===------------------------------------------------------------------===//
comment|// Internal implementation.
comment|//===------------------------------------------------------------------===//
specifier|const
name|GRState
operator|*
name|AssumeAux
argument_list|(
argument|const GRState *state
argument_list|,
argument|Loc Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|;
specifier|const
name|GRState
operator|*
name|AssumeAux
argument_list|(
argument|const GRState *state
argument_list|,
argument|NonLoc Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

