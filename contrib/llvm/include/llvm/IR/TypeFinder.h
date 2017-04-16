begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/IR/TypeFinder.h - Class to find used struct types ---*- C++ -*-===//
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
comment|// This file contains the declaration of the TypeFinder class.
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
name|LLVM_IR_TYPEFINDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_TYPEFINDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MDNode
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// TypeFinder - Walk over a module, identifying all of the types that are
comment|/// used by the module.
name|class
name|TypeFinder
block|{
comment|// To avoid walking constant expressions multiple times and other IR
comment|// objects, we keep several helper maps.
name|DenseSet
operator|<
specifier|const
name|Value
operator|*
operator|>
name|VisitedConstants
expr_stmt|;
name|DenseSet
operator|<
specifier|const
name|MDNode
operator|*
operator|>
name|VisitedMetadata
expr_stmt|;
name|DenseSet
operator|<
name|Type
operator|*
operator|>
name|VisitedTypes
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|StructType
operator|*
operator|>
name|StructTypes
expr_stmt|;
name|bool
name|OnlyNamed
init|=
name|false
decl_stmt|;
name|public
label|:
name|TypeFinder
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|run
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|,
name|bool
name|onlyNamed
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|StructType
operator|*
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|StructType
operator|*
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|StructTypes
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|StructTypes
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|StructTypes
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|StructTypes
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|StructTypes
operator|.
name|empty
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|StructTypes
operator|.
name|size
argument_list|()
return|;
block|}
name|iterator
name|erase
parameter_list|(
name|iterator
name|I
parameter_list|,
name|iterator
name|E
parameter_list|)
block|{
return|return
name|StructTypes
operator|.
name|erase
argument_list|(
name|I
argument_list|,
name|E
argument_list|)
return|;
block|}
name|StructType
modifier|*
modifier|&
name|operator
function|[]
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
return|return
name|StructTypes
index|[
name|Idx
index|]
return|;
block|}
name|DenseSet
operator|<
specifier|const
name|MDNode
operator|*
operator|>
operator|&
name|getVisitedMetadata
argument_list|()
block|{
return|return
name|VisitedMetadata
return|;
block|}
name|private
label|:
comment|/// incorporateType - This method adds the type to the list of used
comment|/// structures if it's not in there already.
name|void
name|incorporateType
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// incorporateValue - This method is used to walk operand lists finding types
comment|/// hiding in constant expressions and other operands that won't be walked in
comment|/// other ways.  GlobalValues, basic blocks, instructions, and inst operands
comment|/// are all explicitly enumerated.
name|void
name|incorporateValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// incorporateMDNode - This method is used to walk the operands of an MDNode
comment|/// to find types hiding within.
name|void
name|incorporateMDNode
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|V
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_TYPEFINDER_H
end_comment

end_unit

