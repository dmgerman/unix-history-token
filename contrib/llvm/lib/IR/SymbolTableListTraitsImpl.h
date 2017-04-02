begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/SymbolTableListTraitsImpl.h - Implementation ------*- C++ -*--===//
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
comment|// This file implements the stickier parts of the SymbolTableListTraits class,
end_comment

begin_comment
comment|// and is explicitly instantiated where needed to avoid defining all this code
end_comment

begin_comment
comment|// in a widely used header.
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
name|LLVM_LIB_IR_SYMBOLTABLELISTTRAITSIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_IR_SYMBOLTABLELISTTRAITSIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/SymbolTableListTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueSymbolTable.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// setSymTabObject - This is called when (f.e.) the parent of a basic block
comment|/// changes.  This requires us to remove all the instruction symtab entries from
comment|/// the current function and reinsert them into the new function.
name|template
operator|<
name|typename
name|ValueSubClass
operator|>
name|template
operator|<
name|typename
name|TPtr
operator|>
name|void
name|SymbolTableListTraits
operator|<
name|ValueSubClass
operator|>
operator|::
name|setSymTabObject
argument_list|(
argument|TPtr *Dest
argument_list|,
argument|TPtr Src
argument_list|)
block|{
comment|// Get the old symtab and value list before doing the assignment.
name|ValueSymbolTable
operator|*
name|OldST
operator|=
name|getSymTab
argument_list|(
name|getListOwner
argument_list|()
argument_list|)
block|;
comment|// Do it.
operator|*
name|Dest
operator|=
name|Src
block|;
comment|// Get the new SymTab object.
name|ValueSymbolTable
operator|*
name|NewST
operator|=
name|getSymTab
argument_list|(
name|getListOwner
argument_list|()
argument_list|)
block|;
comment|// If there is nothing to do, quick exit.
if|if
condition|(
name|OldST
operator|==
name|NewST
condition|)
return|return;
comment|// Move all the elements from the old symtab to the new one.
name|ListTy
operator|&
name|ItemList
operator|=
name|getList
argument_list|(
name|getListOwner
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|ItemList
operator|.
name|empty
argument_list|()
condition|)
return|return;
if|if
condition|(
name|OldST
condition|)
block|{
comment|// Remove all entries from the previous symtab.
for|for
control|(
name|auto
name|I
init|=
name|ItemList
operator|.
name|begin
argument_list|()
init|;
name|I
operator|!=
name|ItemList
operator|.
name|end
argument_list|()
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|I
operator|->
name|hasName
argument_list|()
condition|)
name|OldST
operator|->
name|removeValueName
argument_list|(
name|I
operator|->
name|getValueName
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|NewST
condition|)
block|{
comment|// Add all of the items to the new symtab.
for|for
control|(
name|auto
name|I
init|=
name|ItemList
operator|.
name|begin
argument_list|()
init|;
name|I
operator|!=
name|ItemList
operator|.
name|end
argument_list|()
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|I
operator|->
name|hasName
argument_list|()
condition|)
name|NewST
operator|->
name|reinsertValue
argument_list|(
operator|&
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ValueSubClass
operator|>
name|void
name|SymbolTableListTraits
operator|<
name|ValueSubClass
operator|>
operator|::
name|addNodeToList
argument_list|(
argument|ValueSubClass *V
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|V
operator|->
name|getParent
argument_list|()
operator|&&
literal|"Value already in a container!!"
argument_list|)
block|;
name|ItemParentClass
operator|*
name|Owner
operator|=
name|getListOwner
argument_list|()
block|;
name|V
operator|->
name|setParent
argument_list|(
name|Owner
argument_list|)
block|;
if|if
condition|(
name|V
operator|->
name|hasName
argument_list|()
condition|)
if|if
condition|(
name|ValueSymbolTable
modifier|*
name|ST
init|=
name|getSymTab
argument_list|(
name|Owner
argument_list|)
condition|)
name|ST
operator|->
name|reinsertValue
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ValueSubClass
operator|>
name|void
name|SymbolTableListTraits
operator|<
name|ValueSubClass
operator|>
operator|::
name|removeNodeFromList
argument_list|(
argument|ValueSubClass *V
argument_list|)
block|{
name|V
operator|->
name|setParent
argument_list|(
name|nullptr
argument_list|)
block|;
if|if
condition|(
name|V
operator|->
name|hasName
argument_list|()
condition|)
if|if
condition|(
name|ValueSymbolTable
modifier|*
name|ST
init|=
name|getSymTab
argument_list|(
name|getListOwner
argument_list|()
argument_list|)
condition|)
name|ST
operator|->
name|removeValueName
argument_list|(
name|V
operator|->
name|getValueName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ValueSubClass
operator|>
name|void
name|SymbolTableListTraits
operator|<
name|ValueSubClass
operator|>
operator|::
name|transferNodesFromList
argument_list|(
argument|SymbolTableListTraits&L2
argument_list|,
argument|iterator first
argument_list|,
argument|iterator last
argument_list|)
block|{
comment|// We only have to do work here if transferring instructions between BBs
name|ItemParentClass
operator|*
name|NewIP
operator|=
name|getListOwner
argument_list|()
block|,
operator|*
name|OldIP
operator|=
name|L2
operator|.
name|getListOwner
argument_list|()
block|;
name|assert
argument_list|(
name|NewIP
operator|!=
name|OldIP
operator|&&
literal|"Expected different list owners"
argument_list|)
block|;
comment|// We only have to update symbol table entries if we are transferring the
comment|// instructions to a different symtab object...
name|ValueSymbolTable
operator|*
name|NewST
operator|=
name|getSymTab
argument_list|(
name|NewIP
argument_list|)
block|;
name|ValueSymbolTable
operator|*
name|OldST
operator|=
name|getSymTab
argument_list|(
name|OldIP
argument_list|)
block|;
if|if
condition|(
name|NewST
operator|!=
name|OldST
condition|)
block|{
for|for
control|(
init|;
name|first
operator|!=
name|last
condition|;
operator|++
name|first
control|)
block|{
name|ValueSubClass
modifier|&
name|V
init|=
operator|*
name|first
decl_stmt|;
name|bool
name|HasName
init|=
name|V
operator|.
name|hasName
argument_list|()
decl_stmt|;
if|if
condition|(
name|OldST
operator|&&
name|HasName
condition|)
name|OldST
operator|->
name|removeValueName
argument_list|(
name|V
operator|.
name|getValueName
argument_list|()
argument_list|)
expr_stmt|;
name|V
operator|.
name|setParent
argument_list|(
name|NewIP
argument_list|)
expr_stmt|;
if|if
condition|(
name|NewST
operator|&&
name|HasName
condition|)
name|NewST
operator|->
name|reinsertValue
argument_list|(
operator|&
name|V
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_block
unit|} else
block|{
comment|// Just transferring between blocks in the same function, simply update the
comment|// parent fields in the instructions...
for|for
control|(
init|;
name|first
operator|!=
name|last
condition|;
operator|++
name|first
control|)
name|first
operator|->
name|setParent
argument_list|(
name|NewIP
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
unit|}  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

