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

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Cost Table Entry
struct|struct
name|CostTblEntry
block|{
name|int
name|ISD
decl_stmt|;
name|MVT
operator|::
name|SimpleValueType
name|Type
expr_stmt|;
name|unsigned
name|Cost
decl_stmt|;
block|}
struct|;
comment|/// Find in cost table, TypeTy must be comparable to CompareTy by ==
specifier|inline
specifier|const
name|CostTblEntry
modifier|*
name|CostTableLookup
argument_list|(
name|ArrayRef
operator|<
name|CostTblEntry
operator|>
name|Tbl
argument_list|,
name|int
name|ISD
argument_list|,
name|MVT
name|Ty
argument_list|)
block|{
name|auto
name|I
init|=
name|std
operator|::
name|find_if
argument_list|(
name|Tbl
operator|.
name|begin
argument_list|()
argument_list|,
name|Tbl
operator|.
name|end
argument_list|()
argument_list|,
index|[
operator|=
index|]
operator|(
specifier|const
name|CostTblEntry
operator|&
name|Entry
operator|)
block|{
return|return
name|ISD
operator|==
name|Entry
operator|.
name|ISD
operator|&&
name|Ty
operator|==
name|Entry
operator|.
name|Type
return|;
block|}
block|)
decl_stmt|;
if|if
condition|(
name|I
operator|!=
name|Tbl
operator|.
name|end
argument_list|()
condition|)
return|return
name|I
return|;
comment|// Could not find an entry.
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Type Conversion Cost Table
end_comment

begin_struct
struct|struct
name|TypeConversionCostTblEntry
block|{
name|int
name|ISD
decl_stmt|;
name|MVT
operator|::
name|SimpleValueType
name|Dst
expr_stmt|;
name|MVT
operator|::
name|SimpleValueType
name|Src
expr_stmt|;
name|unsigned
name|Cost
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Find in type conversion cost table, TypeTy must be comparable to CompareTy
end_comment

begin_comment
comment|/// by ==
end_comment

begin_decl_stmt
specifier|inline
specifier|const
name|TypeConversionCostTblEntry
modifier|*
name|ConvertCostTableLookup
argument_list|(
name|ArrayRef
operator|<
name|TypeConversionCostTblEntry
operator|>
name|Tbl
argument_list|,
name|int
name|ISD
argument_list|,
name|MVT
name|Dst
argument_list|,
name|MVT
name|Src
argument_list|)
block|{
name|auto
name|I
init|=
name|std
operator|::
name|find_if
argument_list|(
name|Tbl
operator|.
name|begin
argument_list|()
argument_list|,
name|Tbl
operator|.
name|end
argument_list|()
argument_list|,
index|[
operator|=
index|]
operator|(
specifier|const
name|TypeConversionCostTblEntry
operator|&
name|Entry
operator|)
block|{
return|return
name|ISD
operator|==
name|Entry
operator|.
name|ISD
operator|&&
name|Src
operator|==
name|Entry
operator|.
name|Src
operator|&&
name|Dst
operator|==
name|Entry
operator|.
name|Dst
return|;
block|}
block|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|I
operator|!=
name|Tbl
operator|.
name|end
argument_list|()
condition|)
return|return
name|I
return|;
end_if

begin_comment
comment|// Could not find an entry.
end_comment

begin_return
return|return
name|nullptr
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

