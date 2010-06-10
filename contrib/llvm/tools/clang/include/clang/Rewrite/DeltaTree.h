begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DeltaTree.h - B-Tree for Rewrite Delta tracking --------*- C++ -*-===//
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
comment|// This file defines the DeltaTree class.
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
name|CLANG_REWRITE_DELTATREE_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_REWRITE_DELTATREE_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// DeltaTree - a multiway search tree (BTree) structure with some fancy
comment|/// features.  B-Trees are generally more memory and cache efficient than
comment|/// binary trees, because they store multiple keys/values in each node.  This
comment|/// implements a key/value mapping from index to delta, and allows fast lookup
comment|/// on index.  However, an added (important) bonus is that it can also
comment|/// efficiently tell us the full accumulated delta for a specific file offset
comment|/// as well, without traversing the whole tree.
name|class
name|DeltaTree
block|{
name|void
modifier|*
name|Root
decl_stmt|;
comment|// "DeltaTreeNode *"
name|void
name|operator
init|=
operator|(
specifier|const
name|DeltaTree
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|DeltaTree
argument_list|()
expr_stmt|;
comment|// Note: Currently we only support copying when the RHS is empty.
name|DeltaTree
argument_list|(
specifier|const
name|DeltaTree
operator|&
name|RHS
argument_list|)
expr_stmt|;
operator|~
name|DeltaTree
argument_list|()
expr_stmt|;
comment|/// getDeltaAt - Return the accumulated delta at the specified file offset.
comment|/// This includes all insertions or delections that occurred *before* the
comment|/// specified file index.
name|int
name|getDeltaAt
argument_list|(
name|unsigned
name|FileIndex
argument_list|)
decl|const
decl_stmt|;
comment|/// AddDelta - When a change is made that shifts around the text buffer,
comment|/// this method is used to record that info.  It inserts a delta of 'Delta'
comment|/// into the current DeltaTree at offset FileIndex.
name|void
name|AddDelta
parameter_list|(
name|unsigned
name|FileIndex
parameter_list|,
name|int
name|Delta
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

