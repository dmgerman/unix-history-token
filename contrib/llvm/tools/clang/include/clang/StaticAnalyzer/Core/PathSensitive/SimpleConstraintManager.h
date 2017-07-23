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
comment|//  Simplified constraint manager backend.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_SIMPLECONSTRAINTMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_SIMPLECONSTRAINTMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ConstraintManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramState.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|SimpleConstraintManager
range|:
name|public
name|ConstraintManager
block|{
name|SubEngine
operator|*
name|SU
block|;
name|SValBuilder
operator|&
name|SVB
block|;
name|public
operator|:
name|SimpleConstraintManager
argument_list|(
name|SubEngine
operator|*
name|subengine
argument_list|,
name|SValBuilder
operator|&
name|SB
argument_list|)
operator|:
name|SU
argument_list|(
name|subengine
argument_list|)
block|,
name|SVB
argument_list|(
argument|SB
argument_list|)
block|{}
operator|~
name|SimpleConstraintManager
argument_list|()
name|override
block|;
comment|//===------------------------------------------------------------------===//
comment|// Implementation for interface from ConstraintManager.
comment|//===------------------------------------------------------------------===//
comment|/// Ensures that the DefinedSVal conditional is expressed as a NonLoc by
comment|/// creating boolean casts to handle Loc's.
name|ProgramStateRef
name|assume
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|DefinedSVal Cond
argument_list|,
argument|bool Assumption
argument_list|)
name|override
block|;
name|ProgramStateRef
name|assumeInclusiveRange
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|NonLoc Value
argument_list|,
argument|const llvm::APSInt&From
argument_list|,
argument|const llvm::APSInt&To
argument_list|,
argument|bool InRange
argument_list|)
name|override
block|;
name|protected
operator|:
comment|//===------------------------------------------------------------------===//
comment|// Interface that subclasses must implement.
comment|//===------------------------------------------------------------------===//
comment|/// Given a symbolic expression that can be reasoned about, assume that it is
comment|/// true/false and generate the new program state.
name|virtual
name|ProgramStateRef
name|assumeSym
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|bool Assumption
argument_list|)
operator|=
literal|0
block|;
comment|/// Given a symbolic expression within the range [From, To], assume that it is
comment|/// true/false and generate the new program state.
comment|/// This function is used to handle case ranges produced by a language
comment|/// extension for switch case statements.
name|virtual
name|ProgramStateRef
name|assumeSymInclusiveRange
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&From
argument_list|,
argument|const llvm::APSInt&To
argument_list|,
argument|bool InRange
argument_list|)
operator|=
literal|0
block|;
comment|/// Given a symbolic expression that cannot be reasoned about, assume that
comment|/// it is zero/nonzero and add it directly to the solver state.
name|virtual
name|ProgramStateRef
name|assumeSymUnsupported
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|bool Assumption
argument_list|)
operator|=
literal|0
block|;
comment|//===------------------------------------------------------------------===//
comment|// Internal implementation.
comment|//===------------------------------------------------------------------===//
name|BasicValueFactory
operator|&
name|getBasicVals
argument_list|()
specifier|const
block|{
return|return
name|SVB
operator|.
name|getBasicValueFactory
argument_list|()
return|;
block|}
name|SymbolManager
operator|&
name|getSymbolManager
argument_list|()
specifier|const
block|{
return|return
name|SVB
operator|.
name|getSymbolManager
argument_list|()
return|;
block|}
name|private
operator|:
name|ProgramStateRef
name|assume
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|NonLoc Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|;
name|ProgramStateRef
name|assumeAux
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|NonLoc Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|; }
decl_stmt|;
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

