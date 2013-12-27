begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCPredicates.h - PPC Branch Predicate Information ------*- C++ -*-===//
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
comment|// This file describes the PowerPC branch predicates.
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
name|LLVM_TARGET_POWERPC_PPCPREDICATES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_POWERPC_PPCPREDICATES_H
end_define

begin_comment
comment|// GCC #defines PPC on Linux but we use it as our namespace name
end_comment

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_comment
comment|// Generated files will use "namespace PPC". To avoid symbol clash,
end_comment

begin_comment
comment|// undefine PPC here. PPC may be predefined on some hosts.
end_comment

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|PPC
block|{
comment|/// Predicate - These are "(BI<< 5) | BO"  for various predicates.
enum|enum
name|Predicate
block|{
name|PRED_LT
init|=
operator|(
literal|0
operator|<<
literal|5
operator|)
operator||
literal|12
block|,
name|PRED_LE
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
operator||
literal|4
block|,
name|PRED_EQ
init|=
operator|(
literal|2
operator|<<
literal|5
operator|)
operator||
literal|12
block|,
name|PRED_GE
init|=
operator|(
literal|0
operator|<<
literal|5
operator|)
operator||
literal|4
block|,
name|PRED_GT
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
operator||
literal|12
block|,
name|PRED_NE
init|=
operator|(
literal|2
operator|<<
literal|5
operator|)
operator||
literal|4
block|,
name|PRED_UN
init|=
operator|(
literal|3
operator|<<
literal|5
operator|)
operator||
literal|12
block|,
name|PRED_NU
init|=
operator|(
literal|3
operator|<<
literal|5
operator|)
operator||
literal|4
block|}
enum|;
comment|/// Invert the specified predicate.  != -> ==,< ->>=.
name|Predicate
name|InvertPredicate
parameter_list|(
name|Predicate
name|Opcode
parameter_list|)
function_decl|;
comment|/// Assume the condition register is set by MI(a,b), return the predicate if
comment|/// we modify the instructions such that condition register is set by MI(b,a).
name|Predicate
name|getSwappedPredicate
parameter_list|(
name|Predicate
name|Opcode
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

