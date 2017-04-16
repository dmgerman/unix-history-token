begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/SymbolTableListTraits.h - Traits for iplist ---------*- C++ -*-===//
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

begin_include
include|#
directive|include
file|"llvm/ADT/simple_ilist.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Argument
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalAlias
decl_stmt|;
name|class
name|GlobalIFunc
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ValueSymbolTable
decl_stmt|;
comment|/// Template metafunction to get the parent type for a symbol table list.
comment|///
comment|/// Implementations create a typedef called \c type so that we only need a
comment|/// single template parameter for the list and traits.
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|SymbolTableListParentType
block|{}
expr_stmt|;
define|#
directive|define
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
parameter_list|(
name|NODE
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|template<> struct SymbolTableListParentType<NODE> { typedef PARENT type; };
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
argument_list|(
argument|Instruction
argument_list|,
argument|BasicBlock
argument_list|)
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
argument_list|(
argument|BasicBlock
argument_list|,
argument|Function
argument_list|)
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
argument_list|(
argument|Argument
argument_list|,
argument|Function
argument_list|)
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
argument_list|(
argument|Function
argument_list|,
argument|Module
argument_list|)
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
argument_list|(
argument|GlobalVariable
argument_list|,
argument|Module
argument_list|)
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
argument_list|(
argument|GlobalAlias
argument_list|,
argument|Module
argument_list|)
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
argument_list|(
argument|GlobalIFunc
argument_list|,
argument|Module
argument_list|)
undef|#
directive|undef
name|DEFINE_SYMBOL_TABLE_PARENT_TYPE
name|template
operator|<
name|typename
name|NodeTy
operator|>
name|class
name|SymbolTableList
expr_stmt|;
comment|// ValueSubClass   - The type of objects that I hold, e.g. Instruction.
comment|// ItemParentClass - The type of object that owns the list, e.g. BasicBlock.
comment|//
name|template
operator|<
name|typename
name|ValueSubClass
operator|>
name|class
name|SymbolTableListTraits
operator|:
name|public
name|ilist_alloc_traits
operator|<
name|ValueSubClass
operator|>
block|{
typedef|typedef
name|SymbolTableList
operator|<
name|ValueSubClass
operator|>
name|ListTy
expr_stmt|;
typedef|typedef
name|typename
name|simple_ilist
operator|<
name|ValueSubClass
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|typename
name|SymbolTableListParentType
operator|<
name|ValueSubClass
operator|>
operator|::
name|type
name|ItemParentClass
expr_stmt|;
name|public
label|:
name|SymbolTableListTraits
argument_list|()
operator|=
expr|default
expr_stmt|;
name|private
label|:
comment|/// getListOwner - Return the object that owns this list.  If this is a list
comment|/// of instructions, it returns the BasicBlock that owns them.
name|ItemParentClass
modifier|*
name|getListOwner
parameter_list|()
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
decl_stmt|;
name|ListTy
modifier|*
name|Anchor
argument_list|(
name|static_cast
operator|<
name|ListTy
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
decl_stmt|;
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
name|ListTy
modifier|&
name|getList
parameter_list|(
name|ItemParentClass
modifier|*
name|Par
parameter_list|)
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
name|public
label|:
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
parameter_list|(
name|SymbolTableListTraits
modifier|&
name|L2
parameter_list|,
name|iterator
name|first
parameter_list|,
name|iterator
name|last
parameter_list|)
function_decl|;
comment|// private:
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
comment|/// List that automatically updates parent links and symbol tables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When nodes are inserted into and removed from this list, the associated
end_comment

begin_comment
comment|/// symbol table will be automatically updated.  Similarly, parent links get
end_comment

begin_comment
comment|/// updated automatically.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|SymbolTableList
operator|:
name|public
name|iplist_impl
operator|<
name|simple_ilist
operator|<
name|T
operator|>
operator|,
name|SymbolTableListTraits
operator|<
name|T
operator|>>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_SYMBOLTABLELISTTRAITS_H
end_comment

end_unit

