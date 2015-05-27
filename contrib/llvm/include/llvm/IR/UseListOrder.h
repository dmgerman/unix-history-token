begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/IR/UseListOrder.h - LLVM Use List Order -------------*- C++ -*-===//
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
comment|// This file has structures and command-line options for preserving use-list
end_comment

begin_comment
comment|// order.
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
name|LLVM_IR_USELISTORDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_USELISTORDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// \brief Structure to hold a use-list order.
struct|struct
name|UseListOrder
block|{
specifier|const
name|Value
modifier|*
name|V
decl_stmt|;
specifier|const
name|Function
modifier|*
name|F
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|Shuffle
expr_stmt|;
name|UseListOrder
argument_list|(
argument|const Value *V
argument_list|,
argument|const Function *F
argument_list|,
argument|size_t ShuffleSize
argument_list|)
block|:
name|V
argument_list|(
name|V
argument_list|)
operator|,
name|F
argument_list|(
name|F
argument_list|)
operator|,
name|Shuffle
argument_list|(
argument|ShuffleSize
argument_list|)
block|{}
name|UseListOrder
argument_list|()
operator|:
name|V
argument_list|(
literal|0
argument_list|)
operator|,
name|F
argument_list|(
literal|0
argument_list|)
block|{}
name|UseListOrder
argument_list|(
name|UseListOrder
operator|&&
name|X
argument_list|)
operator|:
name|V
argument_list|(
name|X
operator|.
name|V
argument_list|)
operator|,
name|F
argument_list|(
name|X
operator|.
name|F
argument_list|)
operator|,
name|Shuffle
argument_list|(
argument|std::move(X.Shuffle)
argument_list|)
block|{}
name|UseListOrder
operator|&
name|operator
operator|=
operator|(
name|UseListOrder
operator|&&
name|X
operator|)
block|{
name|V
operator|=
name|X
operator|.
name|V
block|;
name|F
operator|=
name|X
operator|.
name|F
block|;
name|Shuffle
operator|=
name|std
operator|::
name|move
argument_list|(
name|X
operator|.
name|Shuffle
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|private
label|:
name|UseListOrder
argument_list|(
specifier|const
name|UseListOrder
operator|&
name|X
argument_list|)
operator|=
name|delete
expr_stmt|;
name|UseListOrder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|UseListOrder
operator|&
name|X
operator|)
operator|=
name|delete
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|UseListOrder
operator|>
name|UseListOrderStack
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

