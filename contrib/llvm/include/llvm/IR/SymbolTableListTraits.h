begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/SymbolTableListTraits.h - Traits for iplist --------*- C++ -*-===//
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
comment|// This file defines a generic class that is used to implement the automatic
end_comment

begin_comment
comment|// symbol table manipulation that occurs when you put (for example) a named
end_comment

begin_comment
comment|// instruction into a basic block.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The way that this is implemented is by using a special traits class with the
end_comment

begin_comment
comment|// intrusive list that makes up the list of instructions in a basic block.  When
end_comment

begin_comment
comment|// a new element is added to the list of instructions, the traits class is
end_comment

begin_comment
comment|// notified, allowing the symbol table to be updated.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This generic class implements the traits class.  It must be generic so that
end_comment

begin_comment
comment|// it can work for all uses it, which include lists of instructions, basic
end_comment

begin_comment
comment|// blocks, arguments, functions, global variables, etc...
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
name|LLVM_IR_SYMBOLTABLELISTTRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_SYMBOLTABLELISTTRAITS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ValueSymbolTable
decl_stmt|;
name|template
operator|<
name|typename
name|NodeTy
operator|>
name|class
name|ilist_iterator
expr_stmt|;
name|template
operator|<
name|typename
name|NodeTy
operator|,
name|typename
name|Traits
operator|>
name|class
name|iplist
expr_stmt|;
name|template
operator|<
name|typename
name|Ty
operator|>
expr|struct
name|ilist_traits
expr_stmt|;
comment|// ValueSubClass   - The type of objects that I hold, e.g. Instruction.
comment|// ItemParentClass - The type of object that owns the list, e.g. BasicBlock.
comment|//
name|template
operator|<
name|typename
name|ValueSubClass
operator|,
name|typename
name|ItemParentClass
operator|>
name|class
name|SymbolTableListTraits
operator|:
name|public
name|ilist_default_traits
operator|<
name|ValueSubClass
operator|>
block|{
typedef|typedef
name|ilist_traits
operator|<
name|ValueSubClass
operator|>
name|TraitsClass
expr_stmt|;
name|public
operator|:
name|SymbolTableListTraits
argument_list|()
block|{}
comment|/// getListOwner - Return the object that owns this list.  If this is a list
comment|/// of instructions, it returns the BasicBlock that owns them.
name|ItemParentClass
operator|*
name|getListOwner
argument_list|()
block|{
name|size_t
name|Offset
argument_list|(
name|size_t
argument_list|(
operator|&
operator|(
operator|(
name|ItemParentClass
operator|*
operator|)
name|nullptr
operator|->*
name|ItemParentClass
operator|::
name|getSublistAccess
argument_list|(
name|static_cast
operator|<
name|ValueSubClass
operator|*
operator|>
operator|(
name|nullptr
operator|)
argument_list|)
operator|)
argument_list|)
argument_list|)
block|;
name|iplist
operator|<
name|ValueSubClass
operator|>
operator|*
name|Anchor
argument_list|(
name|static_cast
operator|<
name|iplist
operator|<
name|ValueSubClass
operator|>
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|ItemParentClass
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|Anchor
operator|)
operator|-
name|Offset
operator|)
return|;
block|}
specifier|static
name|iplist
operator|<
name|ValueSubClass
operator|>
operator|&
name|getList
argument_list|(
argument|ItemParentClass *Par
argument_list|)
block|{
return|return
name|Par
operator|->*
operator|(
name|Par
operator|->
name|getSublistAccess
argument_list|(
operator|(
name|ValueSubClass
operator|*
operator|)
name|nullptr
argument_list|)
operator|)
return|;
block|}
specifier|static
name|ValueSymbolTable
modifier|*
name|getSymTab
parameter_list|(
name|ItemParentClass
modifier|*
name|Par
parameter_list|)
block|{
return|return
name|Par
condition|?
name|toPtr
argument_list|(
name|Par
operator|->
name|getValueSymbolTable
argument_list|()
argument_list|)
else|:
name|nullptr
return|;
block|}
name|void
name|addNodeToList
parameter_list|(
name|ValueSubClass
modifier|*
name|V
parameter_list|)
function_decl|;
name|void
name|removeNodeFromList
parameter_list|(
name|ValueSubClass
modifier|*
name|V
parameter_list|)
function_decl|;
name|void
name|transferNodesFromList
argument_list|(
name|ilist_traits
operator|<
name|ValueSubClass
operator|>
operator|&
name|L2
argument_list|,
name|ilist_iterator
operator|<
name|ValueSubClass
operator|>
name|first
argument_list|,
name|ilist_iterator
operator|<
name|ValueSubClass
operator|>
name|last
argument_list|)
decl_stmt|;
comment|//private:
name|template
operator|<
name|typename
name|TPtr
operator|>
name|void
name|setSymTabObject
argument_list|(
name|TPtr
operator|*
argument_list|,
name|TPtr
argument_list|)
expr_stmt|;
specifier|static
name|ValueSymbolTable
modifier|*
name|toPtr
parameter_list|(
name|ValueSymbolTable
modifier|*
name|P
parameter_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
name|ValueSymbolTable
modifier|*
name|toPtr
parameter_list|(
name|ValueSymbolTable
modifier|&
name|R
parameter_list|)
block|{
return|return
operator|&
name|R
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

