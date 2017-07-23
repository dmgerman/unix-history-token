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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_CONSTRAINTMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_CONSTRAINTMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SymbolManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SaveAndRestore.h"
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
name|namespace
name|ento
block|{
name|class
name|SubEngine
decl_stmt|;
name|class
name|ConditionTruthVal
block|{
name|Optional
operator|<
name|bool
operator|>
name|Val
expr_stmt|;
name|public
label|:
comment|/// Construct a ConditionTruthVal indicating the constraint is constrained
comment|/// to either true or false, depending on the boolean value provided.
name|ConditionTruthVal
argument_list|(
argument|bool constraint
argument_list|)
block|:
name|Val
argument_list|(
argument|constraint
argument_list|)
block|{}
comment|/// Construct a ConstraintVal indicating the constraint is underconstrained.
name|ConditionTruthVal
argument_list|()
block|{}
comment|/// Return true if the constraint is perfectly constrained to 'true'.
name|bool
name|isConstrainedTrue
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|hasValue
argument_list|()
operator|&&
name|Val
operator|.
name|getValue
argument_list|()
return|;
block|}
comment|/// Return true if the constraint is perfectly constrained to 'false'.
name|bool
name|isConstrainedFalse
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|hasValue
argument_list|()
operator|&&
operator|!
name|Val
operator|.
name|getValue
argument_list|()
return|;
block|}
comment|/// Return true if the constrained is perfectly constrained.
name|bool
name|isConstrained
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|hasValue
argument_list|()
return|;
block|}
comment|/// Return true if the constrained is underconstrained and we do not know
comment|/// if the constraint is true of value.
name|bool
name|isUnderconstrained
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Val
operator|.
name|hasValue
argument_list|()
return|;
block|}
block|}
empty_stmt|;
name|class
name|ConstraintManager
block|{
name|public
label|:
name|ConstraintManager
argument_list|()
operator|:
name|NotifyAssumeClients
argument_list|(
argument|true
argument_list|)
block|{}
name|virtual
operator|~
name|ConstraintManager
argument_list|()
expr_stmt|;
name|virtual
name|ProgramStateRef
name|assume
parameter_list|(
name|ProgramStateRef
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
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ProgramStateRef
operator|,
name|ProgramStateRef
operator|>
name|ProgramStatePair
expr_stmt|;
comment|/// Returns a pair of states (StTrue, StFalse) where the given condition is
comment|/// assumed to be true or false, respectively.
name|ProgramStatePair
name|assumeDual
parameter_list|(
name|ProgramStateRef
name|State
parameter_list|,
name|DefinedSVal
name|Cond
parameter_list|)
block|{
name|ProgramStateRef
name|StTrue
init|=
name|assume
argument_list|(
name|State
argument_list|,
name|Cond
argument_list|,
name|true
argument_list|)
decl_stmt|;
comment|// If StTrue is infeasible, asserting the falseness of Cond is unnecessary
comment|// because the existing constraints already establish this.
if|if
condition|(
operator|!
name|StTrue
condition|)
block|{
ifndef|#
directive|ifndef
name|__OPTIMIZE__
comment|// This check is expensive and should be disabled even in Release+Asserts
comment|// builds.
comment|// FIXME: __OPTIMIZE__ is a GNU extension that Clang implements but MSVC
comment|// does not. Is there a good equivalent there?
name|assert
argument_list|(
name|assume
argument_list|(
name|State
argument_list|,
name|Cond
argument_list|,
name|false
argument_list|)
operator|&&
literal|"System is over constrained."
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|ProgramStatePair
argument_list|(
operator|(
name|ProgramStateRef
operator|)
name|nullptr
argument_list|,
name|State
argument_list|)
return|;
block|}
name|ProgramStateRef
name|StFalse
init|=
name|assume
argument_list|(
name|State
argument_list|,
name|Cond
argument_list|,
name|false
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|StFalse
condition|)
block|{
comment|// We are careful to return the original state, /not/ StTrue,
comment|// because we want to avoid having callers generate a new node
comment|// in the ExplodedGraph.
return|return
name|ProgramStatePair
argument_list|(
name|State
argument_list|,
operator|(
name|ProgramStateRef
operator|)
name|nullptr
argument_list|)
return|;
block|}
return|return
name|ProgramStatePair
argument_list|(
name|StTrue
argument_list|,
name|StFalse
argument_list|)
return|;
block|}
name|virtual
name|ProgramStateRef
name|assumeInclusiveRange
argument_list|(
name|ProgramStateRef
name|State
argument_list|,
name|NonLoc
name|Value
argument_list|,
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|From
argument_list|,
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|To
argument_list|,
name|bool
name|InBound
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|ProgramStatePair
name|assumeInclusiveRangeDual
argument_list|(
name|ProgramStateRef
name|State
argument_list|,
name|NonLoc
name|Value
argument_list|,
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|From
argument_list|,
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|To
argument_list|)
block|{
name|ProgramStateRef
name|StInRange
init|=
name|assumeInclusiveRange
argument_list|(
name|State
argument_list|,
name|Value
argument_list|,
name|From
argument_list|,
name|To
argument_list|,
name|true
argument_list|)
decl_stmt|;
comment|// If StTrue is infeasible, asserting the falseness of Cond is unnecessary
comment|// because the existing constraints already establish this.
if|if
condition|(
operator|!
name|StInRange
condition|)
return|return
name|ProgramStatePair
argument_list|(
operator|(
name|ProgramStateRef
operator|)
name|nullptr
argument_list|,
name|State
argument_list|)
return|;
name|ProgramStateRef
name|StOutOfRange
init|=
name|assumeInclusiveRange
argument_list|(
name|State
argument_list|,
name|Value
argument_list|,
name|From
argument_list|,
name|To
argument_list|,
name|false
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|StOutOfRange
condition|)
block|{
comment|// We are careful to return the original state, /not/ StTrue,
comment|// because we want to avoid having callers generate a new node
comment|// in the ExplodedGraph.
return|return
name|ProgramStatePair
argument_list|(
name|State
argument_list|,
operator|(
name|ProgramStateRef
operator|)
name|nullptr
argument_list|)
return|;
block|}
return|return
name|ProgramStatePair
argument_list|(
name|StInRange
argument_list|,
name|StOutOfRange
argument_list|)
return|;
block|}
comment|/// \brief If a symbol is perfectly constrained to a constant, attempt
comment|/// to return the concrete value.
comment|///
comment|/// Note that a ConstraintManager is not obligated to return a concretized
comment|/// value for a symbol, even if it is perfectly constrained.
name|virtual
specifier|const
name|llvm
operator|::
name|APSInt
operator|*
name|getSymVal
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|SymbolRef sym
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// Scan all symbols referenced by the constraints. If the symbol is not
comment|/// alive, remove it.
name|virtual
name|ProgramStateRef
name|removeDeadBindings
parameter_list|(
name|ProgramStateRef
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
parameter_list|(
name|ProgramStateRef
name|state
parameter_list|,
name|raw_ostream
modifier|&
name|Out
parameter_list|,
specifier|const
name|char
modifier|*
name|nl
parameter_list|,
specifier|const
name|char
modifier|*
name|sep
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|EndPath
parameter_list|(
name|ProgramStateRef
name|state
parameter_list|)
block|{}
comment|/// Convenience method to query the state to see if a symbol is null or
comment|/// not null, or if neither assumption can be made.
name|ConditionTruthVal
name|isNull
parameter_list|(
name|ProgramStateRef
name|State
parameter_list|,
name|SymbolRef
name|Sym
parameter_list|)
block|{
name|SaveAndRestore
operator|<
name|bool
operator|>
name|DisableNotify
argument_list|(
name|NotifyAssumeClients
argument_list|,
name|false
argument_list|)
expr_stmt|;
return|return
name|checkNull
argument_list|(
name|State
argument_list|,
name|Sym
argument_list|)
return|;
block|}
name|protected
label|:
comment|/// A flag to indicate that clients should be notified of assumptions.
comment|/// By default this is the case, but sometimes this needs to be restricted
comment|/// to avoid infinite recursions within the ConstraintManager.
comment|///
comment|/// Note that this flag allows the ConstraintManager to be re-entrant,
comment|/// but not thread-safe.
name|bool
name|NotifyAssumeClients
decl_stmt|;
comment|/// canReasonAbout - Not all ConstraintManagers can accurately reason about
comment|///  all SVal values.  This method returns true if the ConstraintManager can
comment|///  reasonably handle a given SVal value.  This is typically queried by
comment|///  ExprEngine to determine if the value should be replaced with a
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
comment|/// Returns whether or not a symbol is known to be null ("true"), known to be
comment|/// non-null ("false"), or may be either ("underconstrained").
name|virtual
name|ConditionTruthVal
name|checkNull
parameter_list|(
name|ProgramStateRef
name|State
parameter_list|,
name|SymbolRef
name|Sym
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ConstraintManager
operator|>
name|CreateRangeConstraintManager
argument_list|(
name|ProgramStateManager
operator|&
name|statemgr
argument_list|,
name|SubEngine
operator|*
name|subengine
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ConstraintManager
operator|>
name|CreateZ3ConstraintManager
argument_list|(
name|ProgramStateManager
operator|&
name|statemgr
argument_list|,
name|SubEngine
operator|*
name|subengine
argument_list|)
expr_stmt|;
block|}
comment|// end GR namespace
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

