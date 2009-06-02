begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StableBasicBlockNumbering.h - Provide BB identifiers -----*- C++ -*-===//
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
comment|// This class provides a *stable* numbering of basic blocks that does not depend
end_comment

begin_comment
comment|// on their address in memory (which is nondeterministic).  When requested, this
end_comment

begin_comment
comment|// class simply provides a unique ID for each basic block in the function
end_comment

begin_comment
comment|// specified and the inverse mapping.
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
name|LLVM_SUPPORT_STABLEBASICBLOCKNUMBERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_STABLEBASICBLOCKNUMBERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/UniqueVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StableBasicBlockNumbering
block|{
comment|// BBNumbering - Holds the numbering.
name|UniqueVector
operator|<
name|BasicBlock
operator|*
operator|>
name|BBNumbering
expr_stmt|;
name|public
label|:
name|StableBasicBlockNumbering
argument_list|(
argument|Function *F =
literal|0
argument_list|)
block|{
if|if
condition|(
name|F
condition|)
name|compute
argument_list|(
operator|*
name|F
argument_list|)
expr_stmt|;
block|}
comment|/// compute - If we have not computed a numbering for the function yet, do
comment|/// so.
name|void
name|compute
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
block|{
if|if
condition|(
name|BBNumbering
operator|.
name|empty
argument_list|()
condition|)
block|{
for|for
control|(
name|Function
operator|::
name|iterator
name|I
operator|=
name|F
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|F
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|BBNumbering
operator|.
name|insert
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// getNumber - Return the ID number for the specified BasicBlock.
comment|///
name|unsigned
name|getNumber
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|unsigned
name|Idx
init|=
name|BBNumbering
operator|.
name|idFor
argument_list|(
name|BB
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Idx
operator|&&
literal|"Invalid basic block or numbering not computed!"
argument_list|)
expr_stmt|;
return|return
name|Idx
operator|-
literal|1
return|;
block|}
comment|/// getBlock - Return the BasicBlock corresponding to a particular ID.
comment|///
name|BasicBlock
modifier|*
name|getBlock
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|N
operator|<
name|BBNumbering
operator|.
name|size
argument_list|()
operator|&&
literal|"Block ID out of range or numbering not computed!"
argument_list|)
expr_stmt|;
return|return
name|BBNumbering
index|[
name|N
operator|+
literal|1
index|]
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

