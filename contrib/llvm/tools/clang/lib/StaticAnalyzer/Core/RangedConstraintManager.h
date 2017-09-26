begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== RangedConstraintManager.h ----------------------------------*- C++ -*--==//
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
comment|//  Ranged constraint manager, built on SimpleConstraintManager.
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
name|LLVM_CLANG_LIB_STATICANALYZER_CORE_RANGEDCONSTRAINTMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_STATICANALYZER_CORE_RANGEDCONSTRAINTMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramState.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SimpleConstraintManager.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|RangedConstraintManager
range|:
name|public
name|SimpleConstraintManager
block|{
name|public
operator|:
name|RangedConstraintManager
argument_list|(
name|SubEngine
operator|*
name|SE
argument_list|,
name|SValBuilder
operator|&
name|SB
argument_list|)
operator|:
name|SimpleConstraintManager
argument_list|(
argument|SE
argument_list|,
argument|SB
argument_list|)
block|{}
operator|~
name|RangedConstraintManager
argument_list|()
name|override
block|;
comment|//===------------------------------------------------------------------===//
comment|// Implementation for interface from SimpleConstraintManager.
comment|//===------------------------------------------------------------------===//
name|ProgramStateRef
name|assumeSym
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|bool Assumption
argument_list|)
name|override
block|;
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
name|override
block|;
name|ProgramStateRef
name|assumeSymUnsupported
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|bool Assumption
argument_list|)
name|override
block|;
name|protected
operator|:
comment|/// Assume a constraint between a symbolic expression and a concrete integer.
name|virtual
name|ProgramStateRef
name|assumeSymRel
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|BinaryOperator::Opcode op
argument_list|,
argument|const llvm::APSInt&Int
argument_list|)
block|;
comment|//===------------------------------------------------------------------===//
comment|// Interface that subclasses must implement.
comment|//===------------------------------------------------------------------===//
comment|// Each of these is of the form "$Sym+Adj<> V", where "<>" is the comparison
comment|// operation for the method being invoked.
name|virtual
name|ProgramStateRef
name|assumeSymNE
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&V
argument_list|,
argument|const llvm::APSInt&Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymEQ
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&V
argument_list|,
argument|const llvm::APSInt&Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymLT
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&V
argument_list|,
argument|const llvm::APSInt&Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymGT
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&V
argument_list|,
argument|const llvm::APSInt&Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymLE
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&V
argument_list|,
argument|const llvm::APSInt&Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymGE
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&V
argument_list|,
argument|const llvm::APSInt&Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymWithinInclusiveRange
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&From
argument_list|,
argument|const llvm::APSInt&To
argument_list|,
argument|const llvm::APSInt&Adjustment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ProgramStateRef
name|assumeSymOutsideInclusiveRange
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|SymbolRef Sym
argument_list|,
argument|const llvm::APSInt&From
argument_list|,
argument|const llvm::APSInt&To
argument_list|,
argument|const llvm::APSInt&Adjustment
argument_list|)
operator|=
literal|0
block|;
comment|//===------------------------------------------------------------------===//
comment|// Internal implementation.
comment|//===------------------------------------------------------------------===//
name|private
operator|:
specifier|static
name|void
name|computeAdjustment
argument_list|(
name|SymbolRef
operator|&
name|Sym
argument_list|,
name|llvm
operator|::
name|APSInt
operator|&
name|Adjustment
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

