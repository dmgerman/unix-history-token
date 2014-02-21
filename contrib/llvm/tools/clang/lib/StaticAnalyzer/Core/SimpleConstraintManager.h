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
name|LLVM_CLANG_GR_SIMPLE_CONSTRAINT_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_SIMPLE_CONSTRAINT_MANAGER_H
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
name|virtual
operator|~
name|SimpleConstraintManager
argument_list|()
block|;
comment|//===------------------------------------------------------------------===//
comment|// Common implementation for the interface provided by ConstraintManager.
comment|//===------------------------------------------------------------------===//
name|ProgramStateRef
name|assume
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|DefinedSVal Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|;
name|ProgramStateRef
name|assume
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|NonLoc Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|;
name|ProgramStateRef
name|assumeSymRel
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|const SymExpr *LHS
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const llvm::APSInt& Int
argument_list|)
block|;
name|protected
operator|:
comment|//===------------------------------------------------------------------===//
comment|// Interface that subclasses must implement.
comment|//===------------------------------------------------------------------===//
comment|// Each of these is of the form "$sym+Adj<> V", where "<>" is the comparison
comment|// operation for the method being invoked.
name|virtual
name|ProgramStateRef
name|assumeSymNE
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|,
argument|const llvm::APSInt& Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymEQ
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|,
argument|const llvm::APSInt& Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymLT
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|,
argument|const llvm::APSInt& Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymGT
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|,
argument|const llvm::APSInt& Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymLE
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|,
argument|const llvm::APSInt& Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymGE
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|SymbolRef sym
argument_list|,
argument|const llvm::APSInt& V
argument_list|,
argument|const llvm::APSInt& Adjustment
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
name|bool
name|canReasonAbout
argument_list|(
argument|SVal X
argument_list|)
specifier|const
block|;
name|ProgramStateRef
name|assumeAux
argument_list|(
argument|ProgramStateRef state
argument_list|,
argument|NonLoc Cond
argument_list|,
argument|bool Assumption
argument_list|)
block|;
name|ProgramStateRef
name|assumeAuxForSymbol
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
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

