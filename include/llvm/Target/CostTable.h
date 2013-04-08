begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CostTable.h - Instruction Cost Table handling -----------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Cost tables and simple lookup functions
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TARGET_COSTTABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_COSTTABLE_H_
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Cost Table Entry
name|template
operator|<
name|class
name|TypeTy
operator|>
expr|struct
name|CostTblEntry
block|{
name|int
name|ISD
block|;
name|TypeTy
name|Type
block|;
name|unsigned
name|Cost
block|; }
expr_stmt|;
comment|/// Find in cost table, TypeTy must be comparable by ==
name|template
operator|<
name|class
name|TypeTy
operator|>
name|int
name|CostTableLookup
argument_list|(
argument|const CostTblEntry<TypeTy> *Tbl
argument_list|,
argument|unsigned len
argument_list|,
argument|int ISD
argument_list|,
argument|TypeTy Ty
argument_list|)
block|{
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Tbl
index|[
name|i
index|]
operator|.
name|ISD
operator|==
name|ISD
operator|&&
name|Tbl
index|[
name|i
index|]
operator|.
name|Type
operator|==
name|Ty
condition|)
return|return
name|i
return|;
comment|// Could not find an entry.
return|return
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Type Conversion Cost Table
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TypeTy
operator|>
expr|struct
name|TypeConversionCostTblEntry
block|{
name|int
name|ISD
block|;
name|TypeTy
name|Dst
block|;
name|TypeTy
name|Src
block|;
name|unsigned
name|Cost
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Find in type conversion cost table, TypeTy must be comparable by ==
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TypeTy
operator|>
name|int
name|ConvertCostTableLookup
argument_list|(
argument|const TypeConversionCostTblEntry<TypeTy> *Tbl
argument_list|,
argument|unsigned len
argument_list|,
argument|int ISD
argument_list|,
argument|TypeTy Dst
argument_list|,
argument|TypeTy Src
argument_list|)
block|{
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Tbl
index|[
name|i
index|]
operator|.
name|ISD
operator|==
name|ISD
operator|&&
name|Tbl
index|[
name|i
index|]
operator|.
name|Src
operator|==
name|Src
operator|&&
name|Tbl
index|[
name|i
index|]
operator|.
name|Dst
operator|==
name|Dst
condition|)
return|return
name|i
return|;
end_expr_stmt

begin_comment
comment|// Could not find an entry.
end_comment

begin_return
return|return
operator|-
literal|1
return|;
end_return

begin_comment
unit|}  }
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_TARGET_COSTTABLE_H_ */
end_comment

end_unit

