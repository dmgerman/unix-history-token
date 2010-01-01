begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/SDNodeOrdering.h - SDNode Ordering ---------*- C++ -*-===//
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
comment|// This file declares the SDNodeOrdering class.
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
name|LLVM_CODEGEN_SDNODEORDERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SDNODEORDERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SDNode
decl_stmt|;
comment|/// SDNodeOrdering - Maps a unique (monotonically increasing) value to each
comment|/// SDNode that roughly corresponds to the ordering of the original LLVM
comment|/// instruction. This is used for turning off scheduling, because we'll forgo
comment|/// the normal scheduling algorithms and output the instructions according to
comment|/// this ordering.
name|class
name|SDNodeOrdering
block|{
name|DenseMap
operator|<
specifier|const
name|SDNode
operator|*
operator|,
name|unsigned
operator|>
name|OrderMap
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|SDNodeOrdering
operator|&
operator|)
decl_stmt|;
comment|// Do not implement.
name|SDNodeOrdering
argument_list|(
specifier|const
name|SDNodeOrdering
operator|&
argument_list|)
expr_stmt|;
comment|// Do not implement.
name|public
label|:
name|SDNodeOrdering
argument_list|()
block|{}
name|void
name|add
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|Node
parameter_list|,
name|unsigned
name|O
parameter_list|)
block|{
name|OrderMap
index|[
name|Node
index|]
operator|=
name|O
expr_stmt|;
block|}
name|void
name|remove
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|Node
parameter_list|)
block|{
name|DenseMap
operator|<
specifier|const
name|SDNode
operator|*
operator|,
name|unsigned
operator|>
operator|::
name|iterator
name|Itr
operator|=
name|OrderMap
operator|.
name|find
argument_list|(
name|Node
argument_list|)
expr_stmt|;
if|if
condition|(
name|Itr
operator|!=
name|OrderMap
operator|.
name|end
argument_list|()
condition|)
name|OrderMap
operator|.
name|erase
argument_list|(
name|Itr
argument_list|)
expr_stmt|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|OrderMap
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|unsigned
name|getOrder
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|Node
parameter_list|)
block|{
return|return
name|OrderMap
index|[
name|Node
index|]
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

