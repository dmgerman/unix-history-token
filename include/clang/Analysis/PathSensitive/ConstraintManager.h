begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== ConstraintManager.h - Constraints on symbolic values.-------*- C++ -*--==//
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
comment|//  This file defined the interface to manage constraints on symbolic values.
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
name|LLVM_CLANG_ANALYSIS_CONSTRAINT_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_CONSTRAINT_MANAGER_H
end_define

begin_comment
comment|// FIXME: Typedef LiveSymbolsTy/DeadSymbolsTy at a more appropriate place.
end_comment

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/Store.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APSInt
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GRState
decl_stmt|;
name|class
name|GRStateManager
decl_stmt|;
name|class
name|GRSubEngine
decl_stmt|;
name|class
name|SVal
decl_stmt|;
name|class
name|ConstraintManager
block|{
name|public
label|:
name|virtual
operator|~
name|ConstraintManager
argument_list|()
expr_stmt|;
name|virtual
specifier|const
name|GRState
modifier|*
name|Assume
parameter_list|(
specifier|const
name|GRState
modifier|*
name|state
parameter_list|,
name|DefinedSVal
name|Cond
parameter_list|,
name|bool
name|Assumption
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
specifier|const
name|GRState
modifier|*
name|AssumeInBound
parameter_list|(
specifier|const
name|GRState
modifier|*
name|state
parameter_list|,
name|DefinedSVal
name|Idx
parameter_list|,
name|DefinedSVal
name|UpperBound
parameter_list|,
name|bool
name|Assumption
parameter_list|)
init|=
literal|0
function_decl|;
name|std
operator|::
name|pair
operator|<
specifier|const
name|GRState
operator|*
operator|,
specifier|const
name|GRState
operator|*
operator|>
name|AssumeDual
argument_list|(
argument|const GRState *state
argument_list|,
argument|DefinedSVal Cond
argument_list|)
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Assume
argument_list|(
name|state
argument_list|,
name|Cond
argument_list|,
name|true
argument_list|)
argument_list|,
name|Assume
argument_list|(
name|state
argument_list|,
name|Cond
argument_list|,
name|false
argument_list|)
argument_list|)
return|;
block|}
name|virtual
specifier|const
name|llvm
operator|::
name|APSInt
operator|*
name|getSymVal
argument_list|(
argument|const GRState *state
argument_list|,
argument|SymbolRef sym
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|isEqual
argument_list|(
specifier|const
name|GRState
operator|*
name|state
argument_list|,
name|SymbolRef
name|sym
argument_list|,
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|V
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
specifier|const
name|GRState
modifier|*
name|RemoveDeadBindings
parameter_list|(
specifier|const
name|GRState
modifier|*
name|state
parameter_list|,
name|SymbolReaper
modifier|&
name|SymReaper
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|print
argument_list|(
specifier|const
name|GRState
operator|*
name|state
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
argument_list|,
specifier|const
name|char
operator|*
name|nl
argument_list|,
specifier|const
name|char
operator|*
name|sep
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|EndPath
parameter_list|(
specifier|const
name|GRState
modifier|*
name|state
parameter_list|)
block|{}
comment|/// canReasonAbout - Not all ConstraintManagers can accurately reason about
comment|///  all SVal values.  This method returns true if the ConstraintManager can
comment|///  reasonably handle a given SVal value.  This is typically queried by
comment|///  GRExprEngine to determine if the value should be replaced with a
comment|///  conjured symbolic value in order to recover some precision.
name|virtual
name|bool
name|canReasonAbout
argument_list|(
name|SVal
name|X
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|ConstraintManager
modifier|*
name|CreateBasicConstraintManager
parameter_list|(
name|GRStateManager
modifier|&
name|statemgr
parameter_list|,
name|GRSubEngine
modifier|&
name|subengine
parameter_list|)
function_decl|;
name|ConstraintManager
modifier|*
name|CreateRangeConstraintManager
parameter_list|(
name|GRStateManager
modifier|&
name|statemgr
parameter_list|,
name|GRSubEngine
modifier|&
name|subengine
parameter_list|)
function_decl|;
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

