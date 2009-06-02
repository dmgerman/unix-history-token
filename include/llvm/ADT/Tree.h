begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/Tree.h - Generic n-way tree structure -----------*- C++ -*-===//
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
comment|// This class defines a generic N-way tree node structure.  The tree structure
end_comment

begin_comment
comment|// is immutable after creation, but the payload contained within it is not.
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
name|LLVM_ADT_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_TREE_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
name|ConcreteTreeNode
operator|,
name|class
name|Payload
operator|>
name|class
name|Tree
block|{
name|std
operator|::
name|vector
operator|<
name|ConcreteTreeNode
operator|*
operator|>
name|Children
block|;
comment|// This node's children, if any.
name|ConcreteTreeNode
operator|*
name|Parent
block|;
comment|// Parent of this node.
name|Payload
name|Data
block|;
comment|// Data held in this node.
name|protected
operator|:
name|void
name|setChildren
argument_list|(
argument|const std::vector<ConcreteTreeNode*>&children
argument_list|)
block|{
name|Children
operator|=
name|children
block|;   }
name|public
operator|:
specifier|inline
name|Tree
argument_list|(
name|ConcreteTreeNode
operator|*
name|parent
argument_list|)
operator|:
name|Parent
argument_list|(
argument|parent
argument_list|)
block|{}
specifier|inline
name|Tree
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|ConcreteTreeNode
operator|*
operator|>
operator|&
name|children
argument_list|,
name|ConcreteTreeNode
operator|*
name|par
argument_list|)
operator|:
name|Children
argument_list|(
name|children
argument_list|)
block|,
name|Parent
argument_list|(
argument|par
argument_list|)
block|{}
specifier|inline
name|Tree
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|ConcreteTreeNode
operator|*
operator|>
operator|&
name|children
argument_list|,
name|ConcreteTreeNode
operator|*
name|par
argument_list|,
specifier|const
name|Payload
operator|&
name|data
argument_list|)
operator|:
name|Children
argument_list|(
name|children
argument_list|)
block|,
name|Parent
argument_list|(
name|par
argument_list|)
block|,
name|Data
argument_list|(
argument|data
argument_list|)
block|{}
comment|// Tree dtor - Free all children
specifier|inline
operator|~
name|Tree
argument_list|()
block|{
for|for
control|(
name|unsigned
name|i
init|=
name|Children
operator|.
name|size
argument_list|()
init|;
name|i
operator|>
literal|0
condition|;
operator|--
name|i
control|)
name|delete
name|Children
index|[
name|i
operator|-
literal|1
index|]
decl_stmt|;
block|}
comment|// Tree manipulation/walking routines...
specifier|inline
name|ConcreteTreeNode
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
specifier|inline
name|unsigned
name|getNumChildren
argument_list|()
specifier|const
block|{
return|return
name|Children
operator|.
name|size
argument_list|()
return|;
block|}
specifier|inline
name|ConcreteTreeNode
operator|*
name|getChild
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|Children
operator|.
name|size
argument_list|()
operator|&&
literal|"Tree::getChild with index out of range!"
argument_list|)
block|;
return|return
name|Children
index|[
name|i
index|]
return|;
block|}
comment|// Payload access...
specifier|inline
name|Payload
operator|&
name|getTreeData
argument_list|()
block|{
return|return
name|Data
return|;
block|}
specifier|inline
specifier|const
name|Payload
operator|&
name|getTreeData
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

