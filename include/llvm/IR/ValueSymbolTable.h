begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ValueSymbolTable.h - Implement a Value Symtab -------*- C++ -*-===//
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
comment|// This file implements the name/Value symbol table for LLVM.
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
name|LLVM_IR_VALUESYMBOLTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_VALUESYMBOLTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
name|template
operator|<
name|unsigned
name|InternalLen
operator|>
name|class
name|SmallString
expr_stmt|;
name|template
operator|<
name|typename
name|ValueSubClass
operator|>
name|class
name|SymbolTableListTraits
expr_stmt|;
comment|/// This class provides a symbol table of name/value pairs. It is essentially
comment|/// a std::map<std::string,Value*> but has a controlled interface provided by
comment|/// LLVM as well as ensuring uniqueness of names.
comment|///
name|class
name|ValueSymbolTable
block|{
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|Argument
operator|>
expr_stmt|;
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|BasicBlock
operator|>
expr_stmt|;
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|Function
operator|>
expr_stmt|;
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|GlobalAlias
operator|>
expr_stmt|;
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|GlobalIFunc
operator|>
expr_stmt|;
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|GlobalVariable
operator|>
expr_stmt|;
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|Instruction
operator|>
expr_stmt|;
name|friend
name|class
name|Value
decl_stmt|;
comment|/// @name Types
comment|/// @{
name|public
label|:
comment|/// @brief A mapping of names to values.
name|using
name|ValueMap
init|=
name|StringMap
operator|<
name|Value
operator|*
operator|>
decl_stmt|;
comment|/// @brief An iterator over a ValueMap.
name|using
name|iterator
init|=
name|ValueMap
operator|::
name|iterator
decl_stmt|;
comment|/// @brief A const_iterator over a ValueMap.
name|using
name|const_iterator
init|=
name|ValueMap
operator|::
name|const_iterator
decl_stmt|;
comment|/// @}
comment|/// @name Constructors
comment|/// @{
name|ValueSymbolTable
argument_list|()
operator|:
name|vmap
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|ValueSymbolTable
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// @name Accessors
comment|/// @{
comment|/// This method finds the value with the given \p Name in the
comment|/// the symbol table.
comment|/// @returns the value associated with the \p Name
comment|/// @brief Lookup a named Value.
name|Value
modifier|*
name|lookup
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
block|{
return|return
name|vmap
operator|.
name|lookup
argument_list|(
name|Name
argument_list|)
return|;
block|}
comment|/// @returns true iff the symbol table is empty
comment|/// @brief Determine if the symbol table is empty
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|vmap
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @brief The number of name/type pairs is returned.
specifier|inline
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|unsigned
argument_list|(
name|vmap
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|/// This function can be used from the debugger to display the
comment|/// content of the symbol table while debugging.
comment|/// @brief Print out symbol table on stderr
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Iteration
comment|/// @{
comment|/// @brief Get an iterator that from the beginning of the symbol table.
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|vmap
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// @brief Get a const_iterator that from the beginning of the symbol table.
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|vmap
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// @brief Get an iterator to the end of the symbol table.
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|vmap
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// @brief Get a const_iterator to the end of the symbol table.
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|vmap
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Mutators
comment|/// @{
name|private
label|:
name|ValueName
modifier|*
name|makeUniqueName
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|SmallString
operator|<
literal|256
operator|>
operator|&
name|UniqueName
argument_list|)
decl_stmt|;
comment|/// This method adds the provided value \p N to the symbol table.  The Value
comment|/// must have a name which is used to place the value in the symbol table.
comment|/// If the inserted name conflicts, this renames the value.
comment|/// @brief Add a named value to the symbol table
name|void
name|reinsertValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// createValueName - This method attempts to create a value name and insert
comment|/// it into the symbol table with the specified name.  If it conflicts, it
comment|/// auto-renames the name and returns that instead.
name|ValueName
modifier|*
name|createValueName
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// This method removes a value from the symbol table.  It leaves the
comment|/// ValueName attached to the value, but it is no longer inserted in the
comment|/// symtab.
name|void
name|removeValueName
parameter_list|(
name|ValueName
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Internal Data
comment|/// @{
name|ValueMap
name|vmap
decl_stmt|;
comment|///< The map that holds the symbol table.
name|mutable
name|uint32_t
name|LastUnique
init|=
literal|0
decl_stmt|;
comment|///< Counter for tracking unique names
comment|/// @}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_VALUESYMBOLTABLE_H
end_comment

end_unit

