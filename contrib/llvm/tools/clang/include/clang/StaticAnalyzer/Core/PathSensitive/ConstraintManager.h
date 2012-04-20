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
name|LLVM_CLANG_GR_CONSTRAINT_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_CONSTRAINT_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SymbolManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.h"
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
name|std
operator|::
name|pair
operator|<
name|ProgramStateRef
operator|,
name|ProgramStateRef
operator|>
name|assumeDual
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|DefinedSVal Cond
argument_list|)
block|{
name|std
operator|::
name|pair
operator|<
name|ProgramStateRef
block|,
name|ProgramStateRef
operator|>
name|res
operator|=
name|std
operator|::
name|make_pair
argument_list|(
name|assume
argument_list|(
name|state
argument_list|,
name|Cond
argument_list|,
name|true
argument_list|)
argument_list|,
name|assume
argument_list|(
name|state
argument_list|,
name|Cond
argument_list|,
name|false
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
operator|!
operator|(
operator|!
name|res
operator|.
name|first
operator|&&
operator|!
name|res
operator|.
name|second
operator|)
operator|&&
literal|"System is over constrained."
argument_list|)
block|;
return|return
name|res
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
argument|ProgramStateRef state
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
name|ProgramStateRef
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
name|protected
label|:
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
block|}
empty_stmt|;
name|ConstraintManager
modifier|*
name|CreateBasicConstraintManager
parameter_list|(
name|ProgramStateManager
modifier|&
name|statemgr
parameter_list|,
name|SubEngine
modifier|&
name|subengine
parameter_list|)
function_decl|;
name|ConstraintManager
modifier|*
name|CreateRangeConstraintManager
parameter_list|(
name|ProgramStateManager
modifier|&
name|statemgr
parameter_list|,
name|SubEngine
modifier|&
name|subengine
parameter_list|)
function_decl|;
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

