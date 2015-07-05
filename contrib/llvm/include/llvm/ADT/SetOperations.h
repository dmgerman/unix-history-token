begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/SetOperations.h - Generic Set Operations -------*- C++ -*-===//
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
comment|// This file defines generic set operations that may be used on set's of
end_comment

begin_comment
comment|// different types, and different element types.
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
name|LLVM_ADT_SETOPERATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SETOPERATIONS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// set_union(A, B) - Compute A := A u B, return whether A changed.
comment|///
name|template
operator|<
name|class
name|S1Ty
operator|,
name|class
name|S2Ty
operator|>
name|bool
name|set_union
argument_list|(
argument|S1Ty&S1
argument_list|,
argument|const S2Ty&S2
argument_list|)
block|{
name|bool
name|Changed
operator|=
name|false
block|;
for|for
control|(
name|typename
name|S2Ty
operator|::
name|const_iterator
name|SI
operator|=
name|S2
operator|.
name|begin
argument_list|()
operator|,
name|SE
operator|=
name|S2
operator|.
name|end
argument_list|()
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
if|if
condition|(
name|S1
operator|.
name|insert
argument_list|(
operator|*
name|SI
argument_list|)
operator|.
name|second
condition|)
name|Changed
operator|=
name|true
expr_stmt|;
return|return
name|Changed
return|;
block|}
end_decl_stmt

begin_comment
comment|/// set_intersect(A, B) - Compute A := A ^ B
end_comment

begin_comment
comment|/// Identical to set_intersection, except that it works on set<>'s and
end_comment

begin_comment
comment|/// is nicer to use.  Functionally, this iterates through S1, removing
end_comment

begin_comment
comment|/// elements that are not contained in S2.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|S1Ty
operator|,
name|class
name|S2Ty
operator|>
name|void
name|set_intersect
argument_list|(
argument|S1Ty&S1
argument_list|,
argument|const S2Ty&S2
argument_list|)
block|{
for|for
control|(
name|typename
name|S1Ty
operator|::
name|iterator
name|I
operator|=
name|S1
operator|.
name|begin
argument_list|()
init|;
name|I
operator|!=
name|S1
operator|.
name|end
argument_list|()
condition|;
control|)
block|{
specifier|const
name|typename
name|S1Ty
operator|::
name|key_type
operator|&
name|E
operator|=
operator|*
name|I
expr_stmt|;
operator|++
name|I
expr_stmt|;
if|if
condition|(
operator|!
name|S2
operator|.
name|count
argument_list|(
name|E
argument_list|)
condition|)
name|S1
operator|.
name|erase
argument_list|(
name|E
argument_list|)
expr_stmt|;
comment|// Erase element if not in S2
block|}
end_expr_stmt

begin_comment
unit|}
comment|/// set_difference(A, B) - Return A - B
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|S1Ty
operator|,
name|class
name|S2Ty
operator|>
name|S1Ty
name|set_difference
argument_list|(
argument|const S1Ty&S1
argument_list|,
argument|const S2Ty&S2
argument_list|)
block|{
name|S1Ty
name|Result
block|;
for|for
control|(
name|typename
name|S1Ty
operator|::
name|const_iterator
name|SI
operator|=
name|S1
operator|.
name|begin
argument_list|()
operator|,
name|SE
operator|=
name|S1
operator|.
name|end
argument_list|()
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
if|if
condition|(
operator|!
name|S2
operator|.
name|count
argument_list|(
operator|*
name|SI
argument_list|)
condition|)
comment|// if the element is not in set2
name|Result
operator|.
name|insert
argument_list|(
operator|*
name|SI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Result
return|;
end_return

begin_comment
unit|}
comment|/// set_subtract(A, B) - Compute A := A - B
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|S1Ty
operator|,
name|class
name|S2Ty
operator|>
name|void
name|set_subtract
argument_list|(
argument|S1Ty&S1
argument_list|,
argument|const S2Ty&S2
argument_list|)
block|{
for|for
control|(
name|typename
name|S2Ty
operator|::
name|const_iterator
name|SI
operator|=
name|S2
operator|.
name|begin
argument_list|()
operator|,
name|SE
operator|=
name|S2
operator|.
name|end
argument_list|()
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
name|S1
operator|.
name|erase
argument_list|(
operator|*
name|SI
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

