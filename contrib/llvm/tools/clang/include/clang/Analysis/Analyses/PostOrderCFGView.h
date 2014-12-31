begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PostOrderCFGView.h - Post order view of CFG blocks ---------*- C++ --*-//
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
comment|// This file implements post order view of the blocks in a CFG.
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
name|LLVM_CLANG_POSTORDER_CFGVIEW
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_POSTORDER_CFGVIEW
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|//#include<algorithm>
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/PostOrderIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/CFG.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|PostOrderCFGView
range|:
name|public
name|ManagedAnalysis
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
comment|/// \brief Implements a set of CFGBlocks using a BitVector.
comment|///
comment|/// This class contains a minimal interface, primarily dictated by the SetType
comment|/// template parameter of the llvm::po_iterator template, as used with
comment|/// external storage. We also use this set to keep track of which CFGBlocks we
comment|/// visit during the analysis.
name|class
name|CFGBlockSet
block|{
name|llvm
operator|::
name|BitVector
name|VisitedBlockIDs
block|;
name|public
operator|:
comment|// po_iterator requires this iterator, but the only interface needed is the
comment|// value_type typedef.
expr|struct
name|iterator
block|{
typedef|typedef
specifier|const
name|CFGBlock
modifier|*
name|value_type
typedef|;
block|}
block|;
name|CFGBlockSet
argument_list|()
block|{}
name|CFGBlockSet
argument_list|(
specifier|const
name|CFG
operator|*
name|G
argument_list|)
operator|:
name|VisitedBlockIDs
argument_list|(
argument|G->getNumBlockIDs()
argument_list|,
argument|false
argument_list|)
block|{}
comment|/// \brief Set the bit associated with a particular CFGBlock.
comment|/// This is the important method for the SetType template parameter.
name|bool
name|insert
argument_list|(
argument|const CFGBlock *Block
argument_list|)
block|{
comment|// Note that insert() is called by po_iterator, which doesn't check to
comment|// make sure that Block is non-null.  Moreover, the CFGBlock iterator will
comment|// occasionally hand out null pointers for pruned edges, so we catch those
comment|// here.
if|if
condition|(
operator|!
name|Block
condition|)
return|return
name|false
return|;
comment|// if an edge is trivially false.
if|if
condition|(
name|VisitedBlockIDs
operator|.
name|test
argument_list|(
name|Block
operator|->
name|getBlockID
argument_list|()
argument_list|)
condition|)
return|return
name|false
return|;
name|VisitedBlockIDs
operator|.
name|set
argument_list|(
name|Block
operator|->
name|getBlockID
argument_list|()
argument_list|)
block|;
return|return
name|true
return|;
block|}
comment|/// \brief Check if the bit for a CFGBlock has been already set.
comment|/// This method is for tracking visited blocks in the main threadsafety
comment|/// loop. Block must not be null.
name|bool
name|alreadySet
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Block
parameter_list|)
block|{
return|return
name|VisitedBlockIDs
operator|.
name|test
argument_list|(
name|Block
operator|->
name|getBlockID
argument_list|()
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|llvm
operator|::
name|po_iterator
operator|<
specifier|const
name|CFG
operator|*
operator|,
name|CFGBlockSet
operator|,
name|true
operator|>
name|po_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
specifier|const
name|CFGBlock
operator|*
operator|>
name|Blocks
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CFGBlock
operator|*
operator|,
name|unsigned
operator|>
name|BlockOrderTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|BlockOrderTy
name|BlockOrder
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|CFGBlock
operator|*
operator|>
operator|::
name|reverse_iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|CFGBlock
operator|*
operator|>
operator|::
name|const_reverse_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|PostOrderCFGView
argument_list|(
specifier|const
name|CFG
operator|*
name|cfg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Blocks
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_function

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Blocks
operator|.
name|rend
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|rend
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|begin
argument_list|()
operator|==
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|BlockOrderCompare
struct_decl|;
end_struct_decl

begin_macro
name|friend
end_macro

begin_struct_decl
struct_decl|struct
name|BlockOrderCompare
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|BlockOrderCompare
block|{
specifier|const
name|PostOrderCFGView
modifier|&
name|POV
decl_stmt|;
name|public
label|:
name|BlockOrderCompare
argument_list|(
specifier|const
name|PostOrderCFGView
operator|&
name|pov
argument_list|)
operator|:
name|POV
argument_list|(
argument|pov
argument_list|)
block|{}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|CFGBlock
operator|*
name|b1
operator|,
specifier|const
name|CFGBlock
operator|*
name|b2
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|BlockOrderCompare
name|getComparator
argument_list|()
specifier|const
block|{
return|return
name|BlockOrderCompare
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Used by AnalyisContext to construct this object.
end_comment

begin_function_decl
specifier|static
specifier|const
name|void
modifier|*
name|getTag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|PostOrderCFGView
modifier|*
name|create
parameter_list|(
name|AnalysisDeclContext
modifier|&
name|analysisContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

