begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IndirectCallSiteVisitor.h - indirect call-sites visitor -----------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
comment|// This file implements defines a visitor class and a helper function that find
end_comment

begin_comment
comment|// all indirect call-sites in a function.
end_comment

begin_include
include|#
directive|include
file|"llvm/IR/InstVisitor.h"
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
comment|// Visitor class that finds all indirect call sites.
name|struct
name|PGOIndirectCallSiteVisitor
range|:
name|public
name|InstVisitor
operator|<
name|PGOIndirectCallSiteVisitor
operator|>
block|{
name|std
operator|::
name|vector
operator|<
name|Instruction
operator|*
operator|>
name|IndirectCallInsts
block|;
name|PGOIndirectCallSiteVisitor
argument_list|()
block|{}
name|void
name|visitCallSite
argument_list|(
argument|CallSite CS
argument_list|)
block|{
if|if
condition|(
name|CS
operator|.
name|isIndirectCall
argument_list|()
condition|)
name|IndirectCallInsts
operator|.
name|push_back
argument_list|(
name|CS
operator|.
name|getInstruction
argument_list|()
argument_list|)
expr_stmt|;
block|}
expr|}
block|;
comment|// Helper function that finds all indirect call sites.
specifier|static
specifier|inline
name|std
operator|::
name|vector
operator|<
name|Instruction
operator|*
operator|>
name|findIndirectCallSites
argument_list|(
argument|Function&F
argument_list|)
block|{
name|PGOIndirectCallSiteVisitor
name|ICV
block|;
name|ICV
operator|.
name|visit
argument_list|(
name|F
argument_list|)
block|;
return|return
name|ICV
operator|.
name|IndirectCallInsts
return|;
block|}
expr|}
end_decl_stmt

end_unit

