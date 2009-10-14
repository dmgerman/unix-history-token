begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/TypeSymbolTable.h - Implement a Type Symtab --------*- C++ -*-===//
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
comment|// This file implements the name/type symbol table for LLVM.
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
name|LLVM_TYPE_SYMBOL_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TYPE_SYMBOL_TABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Type.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
comment|/// This class provides a symbol table of name/type pairs with operations to
comment|/// support constructing, searching and iterating over the symbol table. The
comment|/// class derives from AbstractTypeUser so that the contents of the symbol
comment|/// table can be updated when abstract types become concrete.
name|class
name|TypeSymbolTable
range|:
name|public
name|AbstractTypeUser
block|{
comment|/// @name Types
comment|/// @{
name|public
operator|:
comment|/// @brief A mapping of names to types.
typedef|typedef
name|std
operator|::
name|map
operator|<
specifier|const
name|std
operator|::
name|string
operator|,
specifier|const
name|Type
operator|*
operator|>
name|TypeMap
expr_stmt|;
comment|/// @brief An iterator over the TypeMap.
typedef|typedef
name|TypeMap
operator|::
name|iterator
name|iterator
expr_stmt|;
comment|/// @brief A const_iterator over the TypeMap.
typedef|typedef
name|TypeMap
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|/// @}
comment|/// @name Constructors
comment|/// @{
name|public
label|:
name|TypeSymbolTable
argument_list|()
operator|:
name|LastUnique
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|TypeSymbolTable
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// @name Accessors
comment|/// @{
name|public
label|:
comment|/// Generates a unique name for a type based on the \p BaseName by
comment|/// incrementing an integer and appending it to the name, if necessary
comment|/// @returns the unique name
comment|/// @brief Get a unique name for a type
name|std
operator|::
name|string
name|getUniqueName
argument_list|(
argument|const StringRef&BaseName
argument_list|)
specifier|const
expr_stmt|;
comment|/// This method finds the type with the given \p name in the type map
comment|/// and returns it.
comment|/// @returns null if the name is not found, otherwise the Type
comment|/// associated with the \p name.
comment|/// @brief Lookup a type by name.
name|Type
modifier|*
name|lookup
argument_list|(
specifier|const
name|StringRef
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
comment|/// Lookup the type associated with name.
comment|/// @returns end() if the name is not found, or an iterator at the entry for
comment|/// Type.
name|iterator
name|find
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|name
parameter_list|)
function_decl|;
comment|/// Lookup the type associated with name.
comment|/// @returns end() if the name is not found, or an iterator at the entry for
comment|/// Type.
name|const_iterator
name|find
argument_list|(
specifier|const
name|StringRef
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
comment|/// @returns true iff the symbol table is empty.
comment|/// @brief Determine if the symbol table is empty
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|tmap
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @returns the size of the symbol table
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
name|tmap
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
name|public
label|:
comment|/// Get an iterator to the start of the symbol table
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|tmap
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// @brief Get a const_iterator to the start of the symbol table
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|tmap
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// Get an iterator to the end of the symbol table.
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|tmap
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Get a const_iterator to the end of the symbol table.
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|tmap
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Mutators
comment|/// @{
name|public
label|:
comment|/// Inserts a type into the symbol table with the specified name. There can be
comment|/// a many-to-one mapping between names and types. This method allows a type
comment|/// with an existing entry in the symbol table to get a new name.
comment|/// @brief Insert a type under a new name.
name|void
name|insert
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|Name
parameter_list|,
specifier|const
name|Type
modifier|*
name|Typ
parameter_list|)
function_decl|;
comment|/// Remove a type at the specified position in the symbol table.
comment|/// @returns the removed Type.
comment|/// @returns the Type that was erased from the symbol table.
name|Type
modifier|*
name|remove
parameter_list|(
name|iterator
name|TI
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name AbstractTypeUser Methods
comment|/// @{
name|private
label|:
comment|/// This function is called when one of the types in the type plane
comment|/// is refined.
name|virtual
name|void
name|refineAbstractType
parameter_list|(
specifier|const
name|DerivedType
modifier|*
name|OldTy
parameter_list|,
specifier|const
name|Type
modifier|*
name|NewTy
parameter_list|)
function_decl|;
comment|/// This function markes a type as being concrete (defined).
name|virtual
name|void
name|typeBecameConcrete
parameter_list|(
specifier|const
name|DerivedType
modifier|*
name|AbsTy
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Internal Data
comment|/// @{
name|private
label|:
name|TypeMap
name|tmap
decl_stmt|;
comment|///< This is the mapping of names to types.
name|mutable
name|uint32_t
name|LastUnique
decl_stmt|;
comment|///< Counter for tracking unique names
comment|/// @}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

